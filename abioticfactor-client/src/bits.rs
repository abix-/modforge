use std::io::{self, ErrorKind};

pub(crate) fn invalid(message: &str) -> io::Error {
    io::Error::new(ErrorKind::InvalidData, message)
}

#[derive(Clone, Default)]
pub(crate) struct Writer {
    data: Vec<u8>,
    len: usize,
}

impl Writer {
    pub fn put(&mut self, value: u64, count: usize) {
        for bit in 0..count {
            if self.len.is_multiple_of(8) {
                self.data.push(0);
            }
            self.data[self.len / 8] |= (((value >> bit) & 1) as u8) << (self.len % 8);
            self.len += 1;
        }
    }

    pub fn bytes(&mut self, bytes: &[u8]) {
        for byte in bytes {
            self.put(u64::from(*byte), 8);
        }
    }

    pub fn len(&self) -> usize {
        self.len
    }

    pub fn append(&mut self, other: &Self) {
        for bit in 0..other.len {
            self.put(u64::from((other.data[bit / 8] >> (bit % 8)) & 1), 1);
        }
    }

    pub fn packed(&mut self, mut value: u32) {
        loop {
            let byte = (value & 127) << 1;
            value >>= 7;
            self.put(u64::from(byte | u32::from(value != 0)), 8);
            if value == 0 {
                break;
            }
        }
    }

    pub fn bounded(&mut self, value: u32, max: u32) {
        assert!(value < max);
        let mut encoded = 0;
        let mut mask = 1;
        while encoded + mask < max {
            let set = value & mask != 0;
            self.put(u64::from(set), 1);
            if set { encoded |= mask; }
            mask <<= 1;
        }
    }

    pub fn string(&mut self, value: &str) {
        if value.is_empty() {
            self.put(0, 32);
            return;
        }
        // Client-authored fields are restricted to ASCII at the public boundary.
        self.put((value.len() + 1) as u64, 32);
        self.bytes(value.as_bytes());
        self.put(0, 8);
    }

    pub fn finish(mut self) -> Vec<u8> {
        self.put(1, 1);
        self.data
    }
}

#[derive(Clone)]
pub(crate) struct Reader<'a> {
    data: &'a [u8],
    cursor: usize,
    end: usize,
}

impl<'a> Reader<'a> {
    pub fn packet(data: &'a [u8]) -> io::Result<Self> {
        let last = data
            .last()
            .copied()
            .filter(|byte| *byte != 0)
            .ok_or_else(|| invalid("missing packet termination bit"))?;
        let end = data.len() * 8 - last.leading_zeros() as usize - 1;
        Ok(Self {
            data,
            cursor: 0,
            end,
        })
    }

    pub fn get(&mut self, count: usize) -> io::Result<u64> {
        if count > 64 || count > self.remaining() {
            return Err(invalid("truncated packet"));
        }
        let mut value = 0;
        for bit in 0..count {
            value |= u64::from((self.data[self.cursor / 8] >> (self.cursor % 8)) & 1) << bit;
            self.cursor += 1;
        }
        Ok(value)
    }

    pub fn remaining(&self) -> usize {
        self.end - self.cursor
    }

    pub fn take(&mut self, count: usize) -> io::Result<Self> {
        if count > self.remaining() {
            return Err(invalid("truncated bunch payload"));
        }
        let part = Self {
            data: self.data,
            cursor: self.cursor,
            end: self.cursor + count,
        };
        self.cursor += count;
        Ok(part)
    }

    pub fn remove_inner_stop(&mut self) -> io::Result<()> {
        if self.remaining() == 0 {
            return Err(invalid("missing inner termination bit"));
        }
        let bit = self.end - 1;
        if (self.data[bit / 8] >> (bit % 8)) & 1 != 1 {
            return Err(invalid("invalid inner termination bit"));
        }
        self.end -= 1;
        Ok(())
    }

    pub fn packed(&mut self) -> io::Result<u32> {
        let mut value = 0;
        for shift in (0..35).step_by(7) {
            let byte = self.get(8)? as u32;
            if shift == 28 && byte > 31 {
                return Err(invalid("packed integer overflow"));
            }
            value |= (byte >> 1) << shift;
            if byte & 1 == 0 {
                return Ok(value);
            }
        }
        Err(invalid("unterminated packed integer"))
    }

    pub fn bounded(&mut self, max: u32) -> io::Result<u32> {
        let mut value = 0;
        let mut mask = 1;
        while value + mask < max {
            if self.get(1)? != 0 {
                value |= mask;
            }
            mask <<= 1;
        }
        Ok(value)
    }

    pub fn string(&mut self) -> io::Result<String> {
        let length = self.get(32)? as u32 as i32;
        let units = length.unsigned_abs() as usize;
        if units > 4096 {
            return Err(invalid("oversized network string"));
        }
        if units == 0 {
            return Ok(String::new());
        }
        if length < 0 {
            let mut chars = Vec::with_capacity(units);
            for _ in 0..units {
                chars.push(self.get(16)? as u16);
            }
            if chars.pop() != Some(0) {
                return Err(invalid("unterminated wide string"));
            }
            String::from_utf16(&chars).map_err(|_| invalid("invalid UTF-16"))
        } else {
            let mut chars = Vec::with_capacity(units);
            for _ in 0..units {
                chars.push(self.get(8)? as u8);
            }
            if chars.pop() != Some(0) {
                return Err(invalid("unterminated string"));
            }
            String::from_utf8(chars).map_err(|_| invalid("invalid UTF-8"))
        }
    }
}
