// Address: 0x140241230
// Ghidra name: FUN_140241230
// ============ 0x140241230 FUN_140241230 (size=71) ============


void FUN_140241230(code *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)



{

  code *pcVar1;

  

  pcVar1 = (code *)(*param_1)(param_2,"vkDestroySurfaceKHR");

  if (pcVar1 != (code *)0x0) {

    (*pcVar1)(param_2,param_3,param_4);

  }

  return;

}




