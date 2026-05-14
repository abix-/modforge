// Address: 0x14018bd90
// Ghidra name: FUN_14018bd90
// ============ 0x14018bd90 FUN_14018bd90 (size=338) ============


void FUN_14018bd90(undefined8 param_1,longlong param_2)



{

  SHORT SVar1;

  undefined4 uVar2;

  int iVar3;

  bool bVar4;

  

  uVar2 = FUN_1401612e0(0,0);

  iVar3 = GetSystemMetrics(0x17);

  bVar4 = iVar3 != 0;

  SVar1 = GetAsyncKeyState(1);

  if (-1 < SVar1) {

    FUN_14018c3a0(param_1,0,uVar2,bVar4,param_2,1,0);

  }

  SVar1 = GetAsyncKeyState(2);

  if (-1 < SVar1) {

    FUN_14018c3a0(param_1,0,uVar2,bVar4,param_2,3,0);

  }

  SVar1 = GetAsyncKeyState(4);

  if (-1 < SVar1) {

    FUN_14018c3a0(param_1,0,uVar2,bVar4,param_2,2,0);

  }

  SVar1 = GetAsyncKeyState(5);

  if (-1 < SVar1) {

    FUN_14018c3a0(param_1,0,uVar2,bVar4,param_2,4,0);

  }

  SVar1 = GetAsyncKeyState(6);

  if (-1 < SVar1) {

    FUN_14018c3a0(param_1,0,uVar2,bVar4,param_2,5,0);

  }

  *(undefined8 *)(param_2 + 0x50) = 0xffffffffffffffff;

  return;

}




