// Address: 0x1402ccf80
// Ghidra name: _CallSettingFrame
// ============ 0x1402ccf80 _CallSettingFrame (size=64) ============


/* Library Function - Single Match

    _CallSettingFrame

   

   Library: Visual Studio */



void _CallSettingFrame(undefined8 param_1,undefined8 *param_2)



{

  code *pcVar1;

  undefined8 uVar2;

  

  pcVar1 = (code *)FUN_1402ccbe0(param_1,*param_2);

  (*pcVar1)();

  uVar2 = FUN_1402ccc10();

  FUN_1402ccbe0(uVar2,*param_2,2);

  return;

}




