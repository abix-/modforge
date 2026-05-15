// Address: 0x14021b910
// Ghidra name: FUN_14021b910
// ============ 0x14021b910 FUN_14021b910 (size=135) ============


undefined8 FUN_14021b910(undefined8 param_1,undefined8 param_2)



{

  int iVar1;

  int iVar2;

  longlong lVar3;

  

  FUN_140177410();

  iVar2 = 0;

  if (0 < DAT_1403fdb90) {

    lVar3 = 0;

    do {

      iVar1 = FUN_1401a98e0(param_2,DAT_1403fdb98 + 0x10 + (longlong)iVar2 * 0x38);

      if (iVar1 != 0) {

        FUN_14021be60(*(undefined8 *)(lVar3 + 8 + DAT_1403fdb98));

      }

      iVar2 = iVar2 + 1;

      lVar3 = lVar3 + 0x38;

    } while (iVar2 < DAT_1403fdb90);

  }

  FUN_140177750();

  return 0;

}




