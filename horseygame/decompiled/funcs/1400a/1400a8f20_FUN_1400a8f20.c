// Address: 0x1400a8f20
// Ghidra name: FUN_1400a8f20
// ============ 0x1400a8f20 FUN_1400a8f20 (size=124) ============


void FUN_1400a8f20(longlong param_1,char param_2,char param_3)



{

  int iVar1;

  

  iVar1 = *(int *)(param_1 + 0x3c);

  if (param_2 == '\0') {

    if (*(int *)(param_1 + 0x40) != -1) {

      if (DAT_1403f30b4 % 0x3c < 0x1e) {

        iVar1 = *(int *)(param_1 + 0x40);

      }

    }

  }

  else if (param_3 != '\0') {

    iVar1 = *(int *)(param_1 + 0x40);

  }

  FUN_140071d20(iVar1,*(float *)(param_1 + 0x28) - *(float *)(param_1 + 0x30) * DAT_14039ca34,

                *(float *)(param_1 + 0x2c) - *(float *)(param_1 + 0x34) * DAT_14039ca34);

  return;

}




