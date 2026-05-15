// Address: 0x140226360
// Ghidra name: FUN_140226360
// ============ 0x140226360 FUN_140226360 (size=414) ============


undefined8

FUN_140226360(undefined8 param_1,undefined8 param_2,undefined8 param_3,LPCWSTR param_4,DWORD param_5

             ,undefined4 *param_6,undefined4 *param_7,undefined4 *param_8)



{

  BOOL BVar1;

  undefined4 uVar2;

  WCHAR *pWVar3;

  DEVMODEW local_f8;

  

  local_f8.dmSize = 0xdc;

  local_f8.dmDriverExtra = 0;

  BVar1 = EnumDisplaySettingsW(param_4,param_5,&local_f8);

  if (BVar1 != 0) {

    pWVar3 = (WCHAR *)FUN_1401841f0(0xdc);

    if (pWVar3 != (WCHAR *)0x0) {

      *param_6 = 0;

      *(undefined8 *)(param_6 + 2) = 0;

      *(undefined8 *)(param_6 + 4) = 0;

      *(undefined8 *)(param_6 + 6) = 0;

      *(WCHAR **)(param_6 + 8) = pWVar3;

      *(undefined8 *)pWVar3 = local_f8.dmDeviceName._0_8_;

      *(undefined8 *)(pWVar3 + 4) = local_f8.dmDeviceName._8_8_;

      *(undefined8 *)(pWVar3 + 8) = local_f8.dmDeviceName._16_8_;

      *(undefined8 *)(pWVar3 + 0xc) = local_f8.dmDeviceName._24_8_;

      *(undefined8 *)(pWVar3 + 0x10) = local_f8.dmDeviceName._32_8_;

      *(undefined8 *)(pWVar3 + 0x14) = local_f8.dmDeviceName._40_8_;

      *(undefined8 *)(pWVar3 + 0x18) = local_f8.dmDeviceName._48_8_;

      *(undefined8 *)(pWVar3 + 0x1c) = local_f8.dmDeviceName._56_8_;

      *(ulonglong *)(pWVar3 + 0x20) = CONCAT44(local_f8._68_4_,local_f8._64_4_);

      *(undefined8 *)(pWVar3 + 0x24) = local_f8._72_8_;

      *(undefined8 *)(pWVar3 + 0x28) = local_f8.field6_0x4c._4_8_;

      *(undefined8 *)(pWVar3 + 0x2c) = local_f8._88_8_;

      pWVar3[0x30] = local_f8.dmYResolution;

      pWVar3[0x31] = local_f8.dmTTOption;

      pWVar3[0x32] = local_f8.dmCollate;

      pWVar3[0x33] = local_f8.dmFormName[0];

      *(undefined8 *)(pWVar3 + 0x34) = local_f8.dmFormName._2_8_;

      *(undefined8 *)(pWVar3 + 0x38) = local_f8.dmFormName._10_8_;

      *(undefined8 *)(pWVar3 + 0x3c) = local_f8.dmFormName._18_8_;

      *(undefined8 *)(pWVar3 + 0x40) = local_f8.dmFormName._26_8_;

      *(undefined8 *)(pWVar3 + 0x44) = local_f8.dmFormName._34_8_;

      *(undefined8 *)(pWVar3 + 0x48) = local_f8.dmFormName._42_8_;

      *(undefined8 *)(pWVar3 + 0x4c) = local_f8.dmFormName._50_8_;

      pWVar3[0x50] = local_f8.dmFormName[0x1d];

      pWVar3[0x51] = local_f8.dmFormName[0x1e];

      pWVar3[0x52] = local_f8.dmFormName[0x1f];

      pWVar3[0x53] = local_f8.dmLogPixels;

      *(undefined8 *)(pWVar3 + 0x54) = local_f8._168_8_;

      *(DWORD *)(pWVar3 + 0x58) = local_f8.dmPelsHeight;

      *(_union_685 *)(pWVar3 + 0x5a) = local_f8.field17_0xb4;

      *(DWORD *)(pWVar3 + 0x5c) = local_f8.dmDisplayFrequency;

      *(DWORD *)(pWVar3 + 0x5e) = local_f8.dmICMMethod;

      *(DWORD *)(pWVar3 + 0x60) = local_f8.dmICMIntent;

      *(DWORD *)(pWVar3 + 0x62) = local_f8.dmMediaType;

      *(DWORD *)(pWVar3 + 100) = local_f8.dmDitherType;

      *(DWORD *)(pWVar3 + 0x66) = local_f8.dmReserved1;

      *(undefined8 *)(pWVar3 + 0x68) = local_f8._208_8_;

      *(DWORD *)(pWVar3 + 0x6c) = local_f8.dmPanningHeight;

      param_6[1] = 0;

      param_6[2] = *(undefined4 *)(pWVar3 + 0x56);

      param_6[3] = *(undefined4 *)(pWVar3 + 0x58);

      FUN_140226db0(param_2,pWVar3,param_6 + 6,param_6 + 7);

      FUN_140227160(param_1,param_4,param_5,param_6);

      if (param_7 != (undefined4 *)0x0) {

        uVar2 = FUN_140226d70(&local_f8);

        *param_7 = uVar2;

      }

      if (param_8 != (undefined4 *)0x0) {

        uVar2 = FUN_140226860(&local_f8);

        *param_8 = uVar2;

      }

      return 1;

    }

  }

  return 0;

}




