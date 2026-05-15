// Address: 0x140225b30
// Ghidra name: FUN_140225b30
// ============ 0x140225b30 FUN_140225b30 (size=84) ============


undefined8 FUN_140225b30(longlong param_1,longlong param_2)



{

  undefined8 uVar1;

  undefined8 uVar2;

  

  FUN_140225a20();

  uVar1 = *(undefined8 *)(param_1 + 0x680);

  uVar2 = *(undefined8 *)(*(longlong *)(param_2 + 0x188) + 8);

  FUN_140224900(uVar1,param_2);

  FUN_140223f00(uVar1,uVar2);

  return 1;

}




