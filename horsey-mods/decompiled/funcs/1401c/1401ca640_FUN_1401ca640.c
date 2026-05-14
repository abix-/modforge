// Address: 0x1401ca640
// Ghidra name: FUN_1401ca640
// ============ 0x1401ca640 FUN_1401ca640 (size=62) ============


undefined4 FUN_1401ca640(undefined8 param_1,int *param_2)



{

  int iVar1;

  longlong lVar2;

  int iVar3;

  

  if (*param_2 == 0x207) {

    iVar1 = param_2[4];

    iVar3 = FUN_14016e2d0();

    if (iVar1 == iVar3) {

      lVar2 = FUN_1401c9f40(param_1);

      *(undefined1 *)(lVar2 + 0x148) = 1;

    }

  }

  return 1;

}




