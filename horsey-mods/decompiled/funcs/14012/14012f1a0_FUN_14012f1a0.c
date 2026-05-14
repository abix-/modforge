// Address: 0x14012f1a0
// Ghidra name: FUN_14012f1a0
// ============ 0x14012f1a0 FUN_14012f1a0 (size=97) ============


size_t FUN_14012f1a0(longlong param_1,char *param_2,longlong param_3)



{

  size_t sVar1;

  ulonglong uVar2;

  

  sVar1 = strlen(param_2);

  if (param_3 != 0) {

    uVar2 = param_3 - 1U;

    if (sVar1 < param_3 - 1U) {

      uVar2 = sVar1;

    }

    FUN_1402f8e20(param_1,param_2,uVar2);

    *(undefined1 *)(uVar2 + param_1) = 0;

  }

  return sVar1;

}




