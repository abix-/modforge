// Address: 0x140163c40
// Ghidra name: FUN_140163c40
// ============ 0x140163c40 FUN_140163c40 (size=100) ============


undefined4 FUN_140163c40(longlong param_1)



{

  char cVar1;

  int iVar2;

  undefined8 uVar3;

  

  iVar2 = FUN_140138fe0();

  while( true ) {

    if (iVar2 == 2) {

      return 0;

    }

    cVar1 = FUN_140138fc0(param_1,0,1);

    if (cVar1 != '\0') break;

    FUN_1401492f0(1);

    iVar2 = FUN_140138fe0(param_1);

  }

  uVar3 = FUN_14017ffb0();

  *(undefined8 *)(param_1 + 8) = uVar3;

  return 1;

}




