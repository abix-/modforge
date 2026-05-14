// Address: 0x1401c68a0
// Ghidra name: FUN_1401c68a0
// ============ 0x1401c68a0 FUN_1401c68a0 (size=74) ============


void FUN_1401c68a0(undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined8 *param_4)



{

  undefined4 uVar1;

  

  uVar1 = 0;

  if (*(char *)((longlong)param_4 + 0x8c) != '\0') {

    uVar1 = param_2;

  }

  FUN_1401cb0d0(param_1,uVar1,param_3,param_4[2],0,(byte)(*(uint *)*param_4 >> 5) & 1);

  *(undefined1 *)((longlong)param_4 + 0x8c) = 1;

  return;

}




