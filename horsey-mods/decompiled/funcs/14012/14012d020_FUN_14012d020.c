// Address: 0x14012d020
// Ghidra name: FUN_14012d020
// ============ 0x14012d020 FUN_14012d020 (size=53) ============


undefined1 FUN_14012d020(undefined8 *param_1)



{

  code *pcVar1;

  

  pcVar1 = (code *)FUN_140174d30(*(undefined4 *)(param_1 + 3),"SDL.iostream.memory.free",0);

  if (pcVar1 != (code *)0x0) {

    (*pcVar1)(*param_1);

  }

  FUN_1401841e0(param_1);

  return 1;

}




