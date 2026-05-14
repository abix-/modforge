// Address: 0x1402183a0
// Ghidra name: FUN_1402183a0
// ============ 0x1402183a0 FUN_1402183a0 (size=91) ============


ulonglong FUN_1402183a0(longlong param_1,undefined8 param_2,ulonglong param_3)



{

  ulonglong uVar1;

  ulonglong uVar2;

  

  if (*(char *)(param_1 + 0x18) == '\0') {

    uVar1 = *(ulonglong *)(param_1 + 0x48);

    if (uVar1 < *(ulonglong *)(param_1 + 0x50)) {

      uVar2 = *(ulonglong *)(param_1 + 0x50) - uVar1;

      if (uVar2 <= param_3) {

        param_3 = uVar2;

      }

      FUN_1402f8e20(*(longlong *)(param_1 + 0x38) + uVar1,param_2,param_3);

      *(longlong *)(param_1 + 0x48) = *(longlong *)(param_1 + 0x48) + param_3;

      return param_3;

    }

  }

  return 0;

}




