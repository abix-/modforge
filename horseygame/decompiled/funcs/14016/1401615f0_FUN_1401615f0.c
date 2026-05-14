// Address: 0x1401615f0
// Ghidra name: FUN_1401615f0
// ============ 0x1401615f0 FUN_1401615f0 (size=85) ============


void FUN_1401615f0(longlong param_1,undefined8 param_2,undefined8 param_3,char *param_4)



{

  double dVar1;

  undefined4 uVar2;

  

  uVar2 = DAT_14039ca44;

  if ((param_4 != (char *)0x0) && (*param_4 != '\0')) {

    *(undefined1 *)(param_1 + 0xd0) = 1;

    dVar1 = (double)thunk_FUN_1402de5ec(param_4);

    *(float *)(param_1 + 0xd4) = (float)dVar1;

    return;

  }

  *(undefined1 *)(param_1 + 0xd0) = 0;

  *(undefined4 *)(param_1 + 0xd4) = uVar2;

  return;

}




