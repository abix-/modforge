// Address: 0x14016b430
// Ghidra name: FUN_14016b430
// ============ 0x14016b430 FUN_14016b430 (size=170) ============


undefined8 FUN_14016b430(char *param_1,int param_2,int param_3,undefined8 param_4)



{

  undefined4 uVar1;

  undefined8 uVar2;

  

  uVar1 = FUN_1401746e0();

  if ((param_1 != (char *)0x0) && (*param_1 != '\0')) {

    FUN_140175500(uVar1,"SDL.window.create.title",param_1);

  }

  FUN_140175360(uVar1,"SDL.window.create.width",(longlong)param_2);

  FUN_140175360(uVar1,"SDL.window.create.height",(longlong)param_3);

  FUN_140175360(uVar1,"SDL.window.create.flags",param_4);

  uVar2 = FUN_14016ae20(uVar1);

  FUN_1401747e0(uVar1);

  return uVar2;

}




