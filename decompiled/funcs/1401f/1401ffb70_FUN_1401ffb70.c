// Address: 0x1401ffb70
// Ghidra name: FUN_1401ffb70
// ============ 0x1401ffb70 FUN_1401ffb70 (size=244) ============


undefined8 FUN_1401ffb70(longlong param_1,undefined8 param_2,ulonglong param_3,undefined8 *param_4)



{

  int iVar1;

  longlong lVar2;

  int iVar3;

  undefined8 uVar4;

  longlong lVar5;

  

  lVar2 = *(longlong *)(param_1 + 0x2e0);

  iVar1 = *(int *)(lVar2 + 0x297c);

  if (param_3 != 0) {

    if ((*(char *)(lVar2 + 0x2980) != '\0') && (iVar3 = FUN_1401fabf0(lVar2), iVar3 != 0)) {

      uVar4 = FUN_14012e850("Failed to issue intermediate batch");

      return uVar4;

    }

    lVar5 = (longlong)iVar1 * 0x20;

    if (*(ulonglong *)(lVar5 + 0x768 + lVar2) < param_3) {

      FUN_1401fabf0(lVar2);

      FUN_1402000b0(lVar2);

      FUN_1401f8f40(lVar2,(longlong)iVar1,param_3);

    }

    FUN_1402f8e20(*(undefined8 *)(lVar5 + 0x770 + lVar2),param_2,param_3);

    *param_4 = *(undefined8 *)(lVar5 + 0x760 + lVar2);

    *(int *)(lVar2 + 0x297c) = iVar1 + 1;

    if (0xff < iVar1 + 1) {

      *(undefined4 *)(lVar2 + 0x297c) = 0;

      *(undefined1 *)(lVar2 + 0x2980) = 1;

    }

  }

  return 1;

}




