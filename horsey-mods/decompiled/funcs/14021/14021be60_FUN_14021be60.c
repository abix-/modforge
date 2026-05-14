// Address: 0x14021be60
// Ghidra name: FUN_14021be60
// ============ 0x14021be60 FUN_14021be60 (size=172) ============


undefined8 FUN_14021be60(longlong *param_1)



{

  int iVar1;

  longlong lVar2;

  

  FUN_140177410();

  iVar1 = 0;

  lVar2 = DAT_1403fdb98;

  if (0 < DAT_1403fdb90) {

    do {

      if (param_1 == *(longlong **)(lVar2 + 8)) {

        (**(code **)(*param_1 + 0x10))(param_1);

        FUN_1401841e0(*(undefined8 *)(lVar2 + 0x20));

        DAT_1403fdb90 = DAT_1403fdb90 + -1;

        if (iVar1 < DAT_1403fdb90) {

          FUN_1402f8e20((longlong)iVar1 * 0x38 + DAT_1403fdb98,

                        (longlong)(iVar1 + 1) * 0x38 + DAT_1403fdb98,

                        (longlong)(DAT_1403fdb90 - iVar1) * 0x38);

        }

        break;

      }

      iVar1 = iVar1 + 1;

      lVar2 = lVar2 + 0x38;

    } while (iVar1 < DAT_1403fdb90);

  }

  FUN_140177750();

  return 1;

}




