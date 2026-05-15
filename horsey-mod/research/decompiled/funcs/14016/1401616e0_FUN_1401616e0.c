// Address: 0x1401616e0
// Ghidra name: FUN_1401616e0
// ============ 0x1401616e0 FUN_1401616e0 (size=85) ============


void FUN_1401616e0(longlong param_1,undefined8 param_2,undefined8 param_3,char *param_4)



{

  double dVar1;

  undefined4 uVar2;

  

  uVar2 = DAT_14039ca44;

  if ((param_4 != (char *)0x0) && (*param_4 != '\0')) {

    *(undefined1 *)(param_1 + 0xd8) = 1;

    dVar1 = (double)thunk_FUN_1402de5ec(param_4);

    *(float *)(param_1 + 0xdc) = (float)dVar1;

    return;

  }

  *(undefined1 *)(param_1 + 0xd8) = 0;

  *(undefined4 *)(param_1 + 0xdc) = uVar2;

  return;

}




