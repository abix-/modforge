// Address: 0x140186240
// Ghidra name: FUN_140186240
// ============ 0x140186240 FUN_140186240 (size=125) ============


undefined8 FUN_140186240(ulonglong param_1)



{

  code *pcVar1;

  int iVar2;

  longlong lVar3;

  undefined8 uVar4;

  

  iVar2 = FUN_1401864e0();

  if ((-1 < iVar2) && (iVar2 < DAT_1403fcb5c)) {

    return *(undefined8 *)(DAT_1403fcb60 + (longlong)iVar2 * 8);

  }

  if (param_1 < 0xfffffffffffffffe) {

    lVar3 = FUN_14016dcf0();

    if (*(longlong *)(lVar3 + 0x18) != 0) {

      FUN_14012e850("Unknown touch id %d, resetting",param_1 & 0xffffffff);

      lVar3 = FUN_14016dcf0();

      pcVar1 = *(code **)(lVar3 + 0x18);

      uVar4 = FUN_14016dcf0();

      (*pcVar1)(uVar4);

      return 0;

    }

    FUN_14012e850("Unknown touch device id %d, cannot reset",param_1 & 0xffffffff);

  }

  return 0;

}




