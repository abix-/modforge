// Address: 0x1400c4340
// Ghidra name: FUN_1400c4340
// ============ 0x1400c4340 FUN_1400c4340 (size=82) ============


void FUN_1400c4340(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)



{

  code *pcVar1;

  undefined8 local_res10;

  undefined8 local_res18;

  undefined8 local_res20;

  

  local_res10 = param_2;

  local_res18 = param_3;

  local_res20 = param_4;

  FUN_1400c5680(&DAT_1403f33a0,0xff,param_1,&local_res10);

  MessageBoxA((HWND)0x0,&DAT_1403f33a0,"Error",0);

  FUN_1402da254(0);

  pcVar1 = (code *)swi(3);

  (*pcVar1)();

  return;

}




