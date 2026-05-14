// Address: 0x1401bfac0
// Ghidra name: FUN_1401bfac0
// ============ 0x1401bfac0 FUN_1401bfac0 (size=144) ============


void FUN_1401bfac0(longlong param_1,longlong param_2,char *param_3)



{

  size_t sVar1;

  undefined8 uVar2;

  uint uVar3;

  ulonglong uVar4;

  

  sVar1 = strlen(param_3);

  if ((*(char *)(param_1 + 0x57c) != '\0') && (*(char *)(param_1 + 0x58e) != '\0')) {

    uVar2 = FUN_140184230(*(undefined8 *)(param_2 + 0x20),sVar1 + 1);

    *(undefined8 *)(param_2 + 0x20) = uVar2;

    FUN_14012f640(uVar2,param_3,sVar1 + 1);

    uVar4 = 0;

    if (*(int *)(param_2 + 0x14) != 0) {

      do {

        FUN_1401bd0d0(param_1,*(undefined8 *)(*(longlong *)(param_2 + 8) + uVar4 * 8),param_3);

        uVar3 = (int)uVar4 + 1;

        uVar4 = (ulonglong)uVar3;

      } while (uVar3 < *(uint *)(param_2 + 0x14));

    }

  }

  return;

}




