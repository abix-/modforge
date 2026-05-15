// Address: 0x140163cb0
// Ghidra name: FUN_140163cb0
// ============ 0x140163cb0 FUN_140163cb0 (size=88) ============


undefined4 FUN_140163cb0(longlong param_1)



{

  char cVar1;

  int iVar2;

  undefined8 uVar3;

  

  iVar2 = FUN_140138fe0();

  while( true ) {

    if (iVar2 == 0) {

      return 0;

    }

    cVar1 = FUN_140138fc0(param_1,2,3);

    if (cVar1 != '\0') break;

    FUN_1401492f0(1);

    iVar2 = FUN_140138fe0(param_1);

  }

  uVar3 = FUN_14017ffb0();

  *(undefined8 *)(param_1 + 8) = uVar3;

  return 1;

}




