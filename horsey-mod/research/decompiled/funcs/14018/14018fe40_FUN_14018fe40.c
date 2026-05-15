// Address: 0x14018fe40
// Ghidra name: FUN_14018fe40
// ============ 0x14018fe40 FUN_14018fe40 (size=192) ============


void FUN_14018fe40(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,

                  int param_5,undefined8 param_6,undefined1 param_7)



{

  undefined4 uVar1;

  

  uVar1 = FUN_1401746e0();

  FUN_140175480(uVar1,"SDL.filedialog.filters",param_4);

  FUN_140175360(uVar1,"SDL.filedialog.nfilters",(longlong)param_5);

  FUN_140175480(uVar1,"SDL.filedialog.window",param_3);

  FUN_140175500(uVar1,"SDL.filedialog.location",param_6);

  FUN_140175280(uVar1,"SDL.filedialog.many",param_7);

  FUN_14018fd40(0,param_1,param_2,uVar1);

  FUN_1401747e0(uVar1);

  return;

}




