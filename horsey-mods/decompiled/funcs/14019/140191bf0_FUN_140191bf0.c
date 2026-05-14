// Address: 0x140191bf0
// Ghidra name: FUN_140191bf0
// ============ 0x140191bf0 FUN_140191bf0 (size=219) ============


ulonglong FUN_140191bf0(undefined8 *param_1,longlong param_2,ulonglong param_3)



{

  char cVar1;

  longlong lVar2;

  ulonglong uVar3;

  

  if ((param_2 == 0) || (param_3 == 0)) {

    FUN_140196b60(param_1,L"Zero buffer/length");

  }

  else {

    FUN_140196b60(param_1,0);

    uVar3 = param_3;

    if (param_3 < *(ushort *)(param_1 + 4)) {

      lVar2 = param_1[5];

      if (lVar2 == 0) {

        lVar2 = FUN_1401841f0();

        param_1[5] = lVar2;

      }

      FUN_1402f8e20(lVar2,param_2,param_3);

      FUN_1402f94c0(lVar2 + param_3,0,*(ushort *)(param_1 + 4) - param_3);

      param_2 = lVar2;

      uVar3 = (ulonglong)*(ushort *)(param_1 + 4);

    }

    cVar1 = (*DAT_1403fcc70)(*param_1,param_2,uVar3);

    if (cVar1 != '\0') {

      return param_3 & 0xffffffff;

    }

    FUN_140196c00(param_1,L"HidD_SetFeature");

  }

  return 0xffffffff;

}




