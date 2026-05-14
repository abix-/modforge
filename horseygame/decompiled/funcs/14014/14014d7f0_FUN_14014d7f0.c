// Address: 0x14014d7f0
// Ghidra name: FUN_14014d7f0
// ============ 0x14014d7f0 FUN_14014d7f0 (size=171) ============


undefined8 FUN_14014d7f0(undefined8 param_1,int param_2,int param_3,int param_4,int param_5)



{

  undefined4 uVar1;

  undefined8 uVar2;

  

  uVar1 = FUN_1401746e0();

  FUN_140175360(uVar1,"SDL.texture.create.format",(longlong)param_2);

  FUN_140175360(uVar1,"SDL.texture.create.access",(longlong)param_3);

  FUN_140175360(uVar1,"SDL.texture.create.width",(longlong)param_4);

  FUN_140175360(uVar1,"SDL.texture.create.height",(longlong)param_5);

  uVar2 = FUN_14014cfa0(param_1,uVar1);

  FUN_1401747e0(uVar1);

  return uVar2;

}




