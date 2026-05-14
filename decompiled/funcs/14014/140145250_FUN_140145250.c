// Address: 0x140145250
// Ghidra name: FUN_140145250
// ============ 0x140145250 FUN_140145250 (size=131) ============


undefined8 FUN_140145250(longlong param_1,undefined8 param_2,undefined4 param_3)



{

  undefined4 uVar1;

  char cVar2;

  undefined4 uVar3;

  undefined8 uVar4;

  

  cVar2 = FUN_1401489c0();

  if (cVar2 == '\0') {

    FUN_14012e850("Parameter \'%s\' is invalid","surface");

    return 0;

  }

  uVar1 = *(undefined4 *)(param_1 + 0x34);

  uVar3 = FUN_14017a4b0(param_3);

  uVar4 = FUN_1401452e0(param_1,param_2,param_3,0,uVar3,uVar1);

  return uVar4;

}




