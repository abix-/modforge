# HumanitZ engine and platform

> **Authoritative on:** HumanitZ's modding surface at the platform
> level. Engine version, exe names, pak layout, third-party SDKs.
> Anything true of the game rather than of UE4 in general or of
> our mod.
>
> Generic UE4 / UE4SS material lives in
> [`../../ueforge/docs/ue-engine.md`](../../ueforge/docs/ue-engine.md).

## Game baseline

| Property | Value |
| -------- | ----- |
| Engine | UE 4.27 (PhysX3/APEX, pak version 11, VS2015 toolchain, "NoEditor" pak suffix) |
| Project name | `HumanitZ` |
| Steam app id | `1766060` |
| Steam exe | `HumanitZ-Win64-Shipping.exe` (81 MB, Shipping config, fully stripped) |
| Launcher | `HumanitZ.exe` at install root |
| Steam install path | `<Steam>/steamapps/common/HumanitZ/` |
| Beta branch | `experimental` (as installed) |

## Pak layout

Single monolithic pak: `HumanitZ/Content/Paks/pakchunk0-WindowsNoEditor.pak` (22.6 GB).
Compressed with Zlib. No IoStore containers (UE4, not UE5).

## Third-party SDKs

| SDK | DLL | Purpose |
| --- | --- | ------- |
| Epic Online Services | `EOSSDK-Win64-Shipping.dll` | Crossplay, accounts |
| Stove PC SDK | `StovePCSDK.dll` + `StoveSDKPlugin` | Korean Stove platform |
| Intel OIDN | `OpenImageDenoise.dll` + `tbb12.dll` | Ray tracing denoiser |
| Steamworks | `steam_api64.dll` (v151) | Steam integration |
| PhysX3 | 9 DLLs (APEX Clothing/Destructible/Legacy, NvCloth, PhysX3, Px*) | Physics |
| GeForce NOW | `GfnRuntimeSdk.dll` | Cloud gaming |
| NV Aftermath | `GFSDK_Aftermath_Lib.x64.dll` | GPU crash diagnostics |

## Anti-cheat

None detected. No EasyAntiCheat, no BattlEye, no other anti-cheat
DLLs. Straightforward process attachment expected.

## Intro movies

5 splash videos in `HumanitZ/Content/Movies/`:
`HZ_EA_VideoV2.mp4`, `HZ_FreedomIntro.mp4`, `Indieio.mp4`,
`UE_moving_logo 3.mp4`, `YoDubzz_Introv2.mp4`.
