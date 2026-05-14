// Address: 0x140225ac0
// Ghidra name: FUN_140225ac0
// ============ 0x140225ac0 FUN_140225ac0 (size=105) ============


undefined8 FUN_140225ac0(longlong param_1,longlong param_2)



{

  undefined8 uVar1;

  undefined8 uVar2;

  

  FUN_140225a20();

  uVar1 = *(undefined8 *)(param_1 + 0x680);

  uVar2 = *(undefined8 *)(*(longlong *)(param_2 + 0x188) + 8);

  FUN_140224900(uVar1,param_2);

  FUN_140223f50(uVar1,uVar2);

  FUN_140225c30(param_1,param_2);

  return 1;

}




