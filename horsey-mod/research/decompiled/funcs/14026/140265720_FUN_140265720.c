// Address: 0x140265720
// Ghidra name: FUN_140265720
// ============ 0x140265720 FUN_140265720 (size=119) ============


undefined1 FUN_140265720(undefined8 *param_1,undefined8 param_2,byte *param_3)



{

  undefined8 uVar1;

  longlong lVar2;

  

  uVar1 = FUN_140149300();

  if (0 < *(int *)(*(longlong *)*param_1 + 0x8c)) {

    lVar2 = FUN_1401581c0(*(undefined4 *)((longlong)param_1 + 0xc));

    if (lVar2 == 0) {

      return 0;

    }

    if (param_3[1] == 0x5b) {

      FUN_14015ad00(uVar1,lVar2,5,(*param_3 & 3) != 0);

    }

  }

  return 1;

}




