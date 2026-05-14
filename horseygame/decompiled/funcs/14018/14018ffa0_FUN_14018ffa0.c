// Address: 0x14018ffa0
// Ghidra name: FUN_14018ffa0
// ============ 0x14018ffa0 FUN_14018ffa0 (size=174) ============


void FUN_14018ffa0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,

                  int param_5,undefined8 param_6)



{

  undefined4 uVar1;

  

  uVar1 = FUN_1401746e0();

  FUN_140175480(uVar1,"SDL.filedialog.filters",param_4);

  FUN_140175360(uVar1,"SDL.filedialog.nfilters",(longlong)param_5);

  FUN_140175480(uVar1,"SDL.filedialog.window",param_3);

  FUN_140175500(uVar1,"SDL.filedialog.location",param_6);

  FUN_14018fd40(1,param_1,param_2,uVar1);

  FUN_1401747e0(uVar1);

  return;

}




