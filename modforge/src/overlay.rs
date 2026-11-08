//! A click-through window drawn over another program's window, like
//! GameHelper2's overlay (ClickableTransparentOverlay over the game).
//!
//! The window is its own top-most, layered, transparent popup on a
//! thread of its own. Pure black is its colour key, so whatever is not
//! drawn shows the program below, and WS_EX_TRANSPARENT sends every
//! click through to it. Callers hand it a [`Frame`]: where to sit on
//! the screen and the shapes to draw there, in pixels from the frame's
//! top left. It never touches the program below.

use parking_lot::Mutex;
use std::sync::Arc;
use std::sync::atomic::{AtomicIsize, Ordering};
use std::thread::JoinHandle;
use windows_sys::Win32::Foundation::{COLORREF, HWND, LPARAM, LRESULT, POINT, RECT, WPARAM};
use windows_sys::Win32::Graphics::Gdi::{
    BI_RGB, BITMAPINFO, BITMAPINFOHEADER, BeginPaint, BitBlt, CreateCompatibleBitmap,
    CreateCompatibleDC, CreateDIBSection, CreatePen, CreateSolidBrush, DIB_RGB_COLORS, DeleteDC,
    DeleteObject, Ellipse, EndPaint, FillRect, GetStockObject, HBITMAP, HDC, InvalidateRect,
    LineTo, MoveToEx, NULL_BRUSH, PAINTSTRUCT, PS_SOLID, PlgBlt, Polyline, Rectangle, SRCCOPY,
    SelectObject, SetBkMode, SetStretchBltMode, SetTextColor, TRANSPARENT, TextOutW, WHITEONBLACK,
};
use windows_sys::Win32::System::LibraryLoader::GetModuleHandleW;
use windows_sys::Win32::UI::WindowsAndMessaging::{
    CreateWindowExW, DefWindowProcW, DestroyWindow, DispatchMessageW, GetMessageW, HWND_TOPMOST,
    LWA_COLORKEY, MSG, PostMessageW, PostQuitMessage, RegisterClassW, SW_SHOWNOACTIVATE,
    SWP_NOACTIVATE, SetLayeredWindowAttributes, SetTimer, SetWindowPos, ShowWindow,
    TranslateMessage, WM_CLOSE, WM_DESTROY, WM_PAINT, WM_TIMER, WNDCLASSW, WS_EX_LAYERED,
    WS_EX_NOACTIVATE, WS_EX_TOOLWINDOW, WS_EX_TOPMOST, WS_EX_TRANSPARENT, WS_POPUP,
};

/// The colour key: drawn black is not drawn.
const KEY: COLORREF = 0;
const TIMER_ID: usize = 1;

/// A colour as 0xRRGGBB. Pure black would vanish under the colour
/// key, so it is drawn as the nearest other black.
pub type Rgb = u32;

#[derive(Clone, Debug, PartialEq)]
pub enum Shape {
    Line {
        from: [f32; 2],
        to: [f32; 2],
        color: Rgb,
        width: i32,
    },
    /// Points joined in order, the last back to the first when closed.
    Path {
        points: Vec<[f32; 2]>,
        color: Rgb,
        width: i32,
        closed: bool,
    },
    Rect {
        at: [f32; 2],
        size: [f32; 2],
        color: Rgb,
        filled: bool,
    },
    Circle {
        centre: [f32; 2],
        radius: f32,
        color: Rgb,
        width: i32,
    },
    Text {
        at: [f32; 2],
        text: String,
        color: Rgb,
    },
    /// A picture drawn into the parallelogram whose top left, top right
    /// and bottom left corners are `corners` (GDI PlgBlt, what ImGui's
    /// AddImageQuad does for a flat map). Black pixels are not drawn;
    /// when the picture shrinks, lit pixels win over black ones.
    Image {
        corners: [[f32; 2]; 3],
        image: Arc<Image>,
    },
}

/// A picture as 0xRRGGBB pixels, row by row from the top.
#[derive(Clone, PartialEq, Eq)]
pub struct Image {
    pub width: u32,
    pub height: u32,
    pub pixels: Vec<Rgb>,
}

impl std::fmt::Debug for Image {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(f, "Image({}x{})", self.width, self.height)
    }
}

/// Where the window sits (left, top, width, height in screen pixels)
/// and what it draws.
#[derive(Clone, Debug, Default, PartialEq)]
pub struct Frame {
    pub area: (i32, i32, i32, i32),
    pub shapes: Vec<Shape>,
}

/// GDI's COLORREF is 0x00BBGGRR.
pub fn colorref(rgb: Rgb) -> COLORREF {
    let c = ((rgb & 0xFF) << 16) | (rgb & 0xFF00) | ((rgb >> 16) & 0xFF);
    if c == KEY { 0x0001_0101 } else { c }
}

/// The running overlay window.
pub struct Overlay {
    hwnd: Arc<AtomicIsize>,
    frame: Arc<Mutex<Frame>>,
    thread: Option<JoinHandle<()>>,
}

thread_local! {
    /// The frame the window on this thread draws.
    static FRAME: std::cell::RefCell<Option<Arc<Mutex<Frame>>>> =
        const { std::cell::RefCell::new(None) };
    static AREA: std::cell::Cell<(i32, i32, i32, i32)> = const { std::cell::Cell::new((0, 0, 0, 0)) };
    /// The last picture turned into a GDI bitmap, kept while frames
    /// keep handing the same one.
    static PICTURE: std::cell::RefCell<Option<(Arc<Image>, HBITMAP)>> =
        const { std::cell::RefCell::new(None) };
}

/// The GDI bitmap for `image`, made once and kept until another picture
/// comes. None when the picture is empty or GDI fails.
fn bitmap_for(image: &Arc<Image>) -> Option<HBITMAP> {
    PICTURE.with(|p| {
        let mut p = p.borrow_mut();
        if let Some((kept, bitmap)) = p.as_ref()
            && Arc::ptr_eq(kept, image)
        {
            return Some(*bitmap);
        }
        if let Some((_, old)) = p.take() {
            // SAFETY: a bitmap this thread made and no DC holds.
            unsafe { DeleteObject(old) };
        }
        let (w, h) = (image.width as usize, image.height as usize);
        if w == 0 || h == 0 || image.pixels.len() != w * h {
            return None;
        }
        // SAFETY: BITMAPINFO is plain data; the header says 32-bit top
        // down rows of `w` by `h`, which CreateDIBSection allocates and
        // the copy fills exactly.
        unsafe {
            let mut info: BITMAPINFO = std::mem::zeroed();
            info.bmiHeader = BITMAPINFOHEADER {
                biSize: std::mem::size_of::<BITMAPINFOHEADER>() as u32,
                biWidth: w as i32,
                biHeight: -(h as i32),
                biPlanes: 1,
                biBitCount: 32,
                biCompression: BI_RGB,
                ..std::mem::zeroed()
            };
            let mut bits: *mut std::ffi::c_void = std::ptr::null_mut();
            let bitmap = CreateDIBSection(
                std::ptr::null_mut(),
                &info,
                DIB_RGB_COLORS,
                &mut bits,
                std::ptr::null_mut(),
                0,
            );
            if bitmap.is_null() || bits.is_null() {
                return None;
            }
            // 0x00RRGGBB in memory is blue, green, red, 0: the DIB's order.
            std::ptr::copy_nonoverlapping(image.pixels.as_ptr(), bits.cast::<u32>(), w * h);
            *p = Some((image.clone(), bitmap));
            Some(bitmap)
        }
    })
}

fn wide(s: &str) -> Vec<u16> {
    s.encode_utf16().chain(std::iter::once(0)).collect()
}

impl Overlay {
    /// Open the window, redrawn `fps` times a second. Fails when the
    /// window cannot be made.
    pub fn start(title: &str, fps: u32) -> Result<Self, String> {
        let hwnd = Arc::new(AtomicIsize::new(0));
        let frame = Arc::new(Mutex::new(Frame::default()));
        let (ready_tx, ready_rx) = std::sync::mpsc::channel::<Result<(), String>>();
        let (h, f, title) = (hwnd.clone(), frame.clone(), title.to_string());
        let period = 1000 / fps.clamp(1, 120);
        let thread = std::thread::Builder::new()
            .name("overlay".into())
            .spawn(move || run(&title, period, &h, f, &ready_tx))
            .map_err(|e| format!("overlay thread: {e}"))?;
        ready_rx
            .recv()
            .map_err(|_| "overlay thread ended".to_string())??;
        Ok(Self {
            hwnd,
            frame,
            thread: Some(thread),
        })
    }

    /// Draw `frame` from the next redraw on.
    pub fn show(&self, frame: Frame) {
        *self.frame.lock() = frame;
    }

    /// The window's handle, as an integer.
    pub fn hwnd(&self) -> isize {
        self.hwnd.load(Ordering::Acquire)
    }

    /// Close the window and wait for its thread.
    pub fn stop(mut self) {
        self.close();
    }

    fn close(&mut self) {
        let h = self.hwnd.swap(0, Ordering::AcqRel);
        if h != 0 {
            // SAFETY: posting to a window handle is safe even if the
            // window is gone; Windows then fails the call.
            unsafe { PostMessageW(h as HWND, WM_CLOSE, 0, 0) };
        }
        if let Some(t) = self.thread.take() {
            let _ = t.join();
        }
    }
}

impl Drop for Overlay {
    fn drop(&mut self) {
        self.close();
    }
}

fn run(
    title: &str,
    period_ms: u32,
    hwnd_out: &AtomicIsize,
    frame: Arc<Mutex<Frame>>,
    ready: &std::sync::mpsc::Sender<Result<(), String>>,
) {
    FRAME.with(|f| *f.borrow_mut() = Some(frame));
    let class = wide("modforge_overlay");
    let name = wide(title);
    // SAFETY: plain Win32 window set up on this thread; every pointer
    // passed lives until the calls return (`class` and `name` until the
    // window is gone, as this function outlives it).
    let hwnd = unsafe {
        let instance = GetModuleHandleW(std::ptr::null());
        let wc = WNDCLASSW {
            style: 0,
            lpfnWndProc: Some(wndproc),
            cbClsExtra: 0,
            cbWndExtra: 0,
            hInstance: instance,
            hIcon: std::ptr::null_mut(),
            hCursor: std::ptr::null_mut(),
            hbrBackground: std::ptr::null_mut(),
            lpszMenuName: std::ptr::null(),
            lpszClassName: class.as_ptr(),
        };
        // A second overlay finds the class already there; that is fine.
        RegisterClassW(&wc);
        CreateWindowExW(
            WS_EX_LAYERED | WS_EX_TRANSPARENT | WS_EX_TOPMOST | WS_EX_TOOLWINDOW | WS_EX_NOACTIVATE,
            class.as_ptr(),
            name.as_ptr(),
            WS_POPUP,
            0,
            0,
            1,
            1,
            std::ptr::null_mut(),
            std::ptr::null_mut(),
            instance,
            std::ptr::null(),
        )
    };
    if hwnd.is_null() {
        let _ = ready.send(Err(format!(
            "CreateWindowExW failed: {}",
            std::io::Error::last_os_error()
        )));
        return;
    }
    // SAFETY: `hwnd` is the live window made above, on this thread.
    unsafe {
        SetLayeredWindowAttributes(hwnd, KEY, 255, LWA_COLORKEY);
        ShowWindow(hwnd, SW_SHOWNOACTIVATE);
        SetTimer(hwnd, TIMER_ID, period_ms, None);
    }
    hwnd_out.store(hwnd as isize, Ordering::Release);
    let _ = ready.send(Ok(()));
    // SAFETY: MSG is plain data, written by GetMessageW.
    let mut msg: MSG = unsafe { std::mem::zeroed() };
    // SAFETY: the standard message loop for windows on this thread.
    while unsafe { GetMessageW(&mut msg, std::ptr::null_mut(), 0, 0) } > 0 {
        // SAFETY: `msg` was filled by GetMessageW just above.
        unsafe {
            TranslateMessage(&msg);
            DispatchMessageW(&msg);
        }
    }
}

extern "system" fn wndproc(hwnd: HWND, msg: u32, wparam: WPARAM, lparam: LPARAM) -> LRESULT {
    match msg {
        WM_TIMER => {
            let area = FRAME.with(|f| f.borrow().as_ref().map(|f| f.lock().area));
            if let Some(area) = area {
                if area != AREA.with(std::cell::Cell::get) {
                    AREA.with(|a| a.set(area));
                    let (x, y, w, h) = area;
                    // SAFETY: `hwnd` is this thread's live window.
                    unsafe {
                        SetWindowPos(hwnd, HWND_TOPMOST, x, y, w.max(1), h.max(1), SWP_NOACTIVATE)
                    };
                }
                // SAFETY: as above; a null rect means the whole window.
                unsafe { InvalidateRect(hwnd, std::ptr::null(), 0) };
            }
            0
        }
        WM_PAINT => {
            paint(hwnd);
            0
        }
        WM_CLOSE => {
            // SAFETY: closing this thread's own window.
            unsafe { DestroyWindow(hwnd) };
            0
        }
        WM_DESTROY => {
            // SAFETY: ends this thread's message loop.
            unsafe { PostQuitMessage(0) };
            0
        }
        // SAFETY: every other message goes to the default handler.
        _ => unsafe { DefWindowProcW(hwnd, msg, wparam, lparam) },
    }
}

fn paint(hwnd: HWND) {
    let shapes = FRAME.with(|f| {
        f.borrow()
            .as_ref()
            .map(|f| f.lock().shapes.clone())
            .unwrap_or_default()
    });
    let (_, _, w, h) = AREA.with(std::cell::Cell::get);
    let (w, h) = (w.max(1), h.max(1));
    // SAFETY: PAINTSTRUCT is plain data, written by BeginPaint.
    let mut ps: PAINTSTRUCT = unsafe { std::mem::zeroed() };
    // SAFETY: painting this thread's window between BeginPaint and
    // EndPaint into a memory bitmap made, used and freed here.
    unsafe {
        let screen = BeginPaint(hwnd, &mut ps);
        let dc = CreateCompatibleDC(screen);
        let bitmap = CreateCompatibleBitmap(screen, w, h);
        let old_bitmap = SelectObject(dc, bitmap);
        let key = CreateSolidBrush(KEY);
        let all = RECT {
            left: 0,
            top: 0,
            right: w,
            bottom: h,
        };
        FillRect(dc, &all, key);
        DeleteObject(key);
        SetBkMode(dc, TRANSPARENT as _);
        for s in &shapes {
            draw(dc, s);
        }
        BitBlt(screen, 0, 0, w, h, dc, 0, 0, SRCCOPY);
        SelectObject(dc, old_bitmap);
        DeleteObject(bitmap);
        DeleteDC(dc);
        EndPaint(hwnd, &ps);
    }
}

/// Draw one shape on `dc` with a pen of its colour and no fill unless
/// asked.
///
/// # Safety
/// `dc` is a live device context on this thread.
unsafe fn draw(dc: HDC, shape: &Shape) {
    let p = |v: [f32; 2]| (v[0].round() as i32, v[1].round() as i32);
    let (color, width) = match shape {
        Shape::Line { color, width, .. }
        | Shape::Path { color, width, .. }
        | Shape::Circle { color, width, .. } => (*color, *width),
        Shape::Rect { color, .. } | Shape::Text { color, .. } => (*color, 1),
        Shape::Image { corners, image } => {
            // SAFETY: the caller's live `dc`.
            unsafe { draw_image(dc, corners, image) };
            return;
        }
    };
    // SAFETY: the caller's live `dc`; every object made here is selected
    // out and freed before return.
    unsafe {
        let pen = CreatePen(PS_SOLID, width.max(1), colorref(color));
        let old_pen = SelectObject(dc, pen);
        let old_brush = SelectObject(dc, GetStockObject(NULL_BRUSH));
        match shape {
            Shape::Line { from, to, .. } => {
                let (a, b) = (p(*from), p(*to));
                MoveToEx(dc, a.0, a.1, std::ptr::null_mut());
                LineTo(dc, b.0, b.1);
            }
            Shape::Path { points, closed, .. } => {
                let mut pts: Vec<POINT> = points
                    .iter()
                    .map(|v| {
                        let (x, y) = p(*v);
                        POINT { x, y }
                    })
                    .collect();
                if *closed && let Some(first) = pts.first().copied() {
                    pts.push(first);
                }
                if pts.len() >= 2 {
                    Polyline(dc, pts.as_ptr(), pts.len() as i32);
                }
            }
            Shape::Rect {
                at, size, filled, ..
            } => {
                let (x, y) = p(*at);
                let (r, b) = p([at[0] + size[0], at[1] + size[1]]);
                if *filled {
                    let brush = CreateSolidBrush(colorref(color));
                    let rect = RECT {
                        left: x,
                        top: y,
                        right: r,
                        bottom: b,
                    };
                    FillRect(dc, &rect, brush);
                    DeleteObject(brush);
                } else {
                    Rectangle(dc, x, y, r, b);
                }
            }
            Shape::Circle { centre, radius, .. } => {
                let (l, t) = p([centre[0] - radius, centre[1] - radius]);
                let (r, b) = p([centre[0] + radius, centre[1] + radius]);
                Ellipse(dc, l, t, r, b);
            }
            Shape::Text { at, text, .. } => {
                let (x, y) = p(*at);
                let t: Vec<u16> = text.encode_utf16().collect();
                SetTextColor(dc, colorref(color));
                TextOutW(dc, x, y, t.as_ptr(), t.len() as i32);
            }
            Shape::Image { .. } => {}
        }
        SelectObject(dc, old_brush);
        SelectObject(dc, old_pen);
        DeleteObject(pen);
    }
}

/// Draw a picture into its parallelogram.
///
/// # Safety
/// `dc` is a live device context on this thread.
unsafe fn draw_image(dc: HDC, corners: &[[f32; 2]; 3], image: &Arc<Image>) {
    let Some(bitmap) = bitmap_for(image) else {
        return;
    };
    let pts = corners.map(|[x, y]| POINT {
        x: x.round() as i32,
        y: y.round() as i32,
    });
    // SAFETY: the caller's live `dc`; the source DC is made, used and
    // freed here, and the kept bitmap is selected out before it goes.
    unsafe {
        let src = CreateCompatibleDC(dc);
        let old = SelectObject(src, bitmap);
        SetStretchBltMode(dc, WHITEONBLACK);
        PlgBlt(
            dc,
            pts.as_ptr(),
            src,
            0,
            0,
            image.width as i32,
            image.height as i32,
            std::ptr::null_mut(),
            0,
            0,
        );
        SelectObject(src, old);
        DeleteDC(src);
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use windows_sys::Win32::UI::WindowsAndMessaging::{
        GWL_EXSTYLE, GetWindowLongPtrW, IsWindow, IsWindowVisible, WindowFromPoint,
    };

    /// A 2 by 2 picture with one grey pixel, drawn twice its size into a
    /// memory bitmap: the grey covers its quarter, black stays black.
    #[test]
    fn a_picture_lands_in_its_parallelogram() {
        let target = Arc::new(Image {
            width: 4,
            height: 4,
            pixels: vec![0; 16],
        });
        let picture = Arc::new(Image {
            width: 2,
            height: 2,
            pixels: vec![0x969696, 0, 0, 0],
        });
        let dest = bitmap_for(&target).expect("target bitmap");
        // Keep the target out of the one-picture cache.
        PICTURE.with(|p| p.borrow_mut().take());
        // SAFETY: a memory DC made, used and freed here; the target
        // bitmap is selected out before it is read and freed.
        let pixels = unsafe {
            let dc = CreateCompatibleDC(std::ptr::null_mut());
            let old = SelectObject(dc, dest);
            draw(
                dc,
                &Shape::Image {
                    corners: [[0.0, 0.0], [4.0, 0.0], [0.0, 4.0]],
                    image: picture,
                },
            );
            SelectObject(dc, old);
            DeleteDC(dc);
            let mut out = [0u32; 16];
            use windows_sys::Win32::Graphics::Gdi::{BITMAP, GetObjectW};
            let mut b: BITMAP = std::mem::zeroed();
            GetObjectW(
                dest,
                std::mem::size_of::<BITMAP>() as i32,
                (&raw mut b).cast(),
            );
            std::ptr::copy_nonoverlapping(b.bmBits.cast::<u32>(), out.as_mut_ptr(), 16);
            DeleteObject(dest);
            out
        };
        assert_eq!(pixels[0] & 0xFFFFFF, 0x969696);
        assert_eq!(pixels[5] & 0xFFFFFF, 0x969696);
        assert_eq!(pixels[2] & 0xFFFFFF, 0);
        assert_eq!(pixels[15] & 0xFFFFFF, 0);
    }

    #[test]
    fn colours_swap_to_gdi_order_and_avoid_the_key() {
        assert_eq!(colorref(0x112233), 0x332211);
        assert_eq!(colorref(0x000000), 0x010101);
    }

    /// Opens a window on the desktop for a moment; nothing is drawn, so
    /// all of it is the colour key and shows what is below.
    #[test]
    fn the_window_is_top_most_and_lets_clicks_through() {
        let o = Overlay::start("modforge overlay test", 30).expect("overlay");
        o.show(Frame {
            area: (100, 100, 200, 200),
            shapes: Vec::new(),
        });
        std::thread::sleep(std::time::Duration::from_millis(200));
        let h = o.hwnd() as HWND;
        // SAFETY: reading the styles of our own live window.
        let ex = unsafe { GetWindowLongPtrW(h, GWL_EXSTYLE) } as u32;
        for flag in [WS_EX_LAYERED, WS_EX_TRANSPARENT, WS_EX_TOPMOST] {
            assert_ne!(ex & flag, 0, "style {flag:#x} missing");
        }
        // SAFETY: plain queries on a window handle and a point.
        unsafe {
            assert_ne!(IsWindowVisible(h), 0);
            assert_ne!(
                WindowFromPoint(POINT { x: 200, y: 200 }),
                h,
                "a click on the overlay must reach the window below"
            );
        }
        o.stop();
        // SAFETY: as above.
        assert_eq!(unsafe { IsWindow(h) }, 0, "closed");
    }
}
