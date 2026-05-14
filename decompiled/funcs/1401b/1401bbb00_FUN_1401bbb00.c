// Address: 0x1401bbb00
// Ghidra name: FUN_1401bbb00
// ============ 0x1401bbb00 FUN_1401bbb00 (size=83) ============


undefined4 FUN_1401bbb00(undefined8 param_1,int *param_2)



{

  int iVar1;

  int iVar2;

  longlong lVar3;

  

  if (*param_2 == 0x207) {

    iVar1 = param_2[4];

    iVar2 = FUN_14016e2d0();

    if (iVar1 == iVar2) {

      lVar3 = FUN_1401baca0(param_1);

      *(undefined1 *)(lVar3 + 0x1c) = 1;

      *(int *)(lVar3 + 0x20) = param_2[5];

      *(int *)(lVar3 + 0x24) = param_2[6];

    }

  }

  return 1;

}




