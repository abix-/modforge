// Address: 0x1402172b0
// Ghidra name: FUN_1402172b0
// ============ 0x1402172b0 FUN_1402172b0 (size=155) ============


void FUN_1402172b0(undefined8 *param_1)



{

  int iVar1;

  uint uVar2;

  ulonglong uVar3;

  ulonglong uVar4;

  

  if (param_1 != (undefined8 *)0x0) {

    FUN_140163d70(param_1[2]);

    iVar1 = *(int *)(param_1 + 3);

    if (iVar1 <= *(int *)((longlong)param_1 + 0x1c)) {

      FUN_14017cea0(param_1[2]);

      return;

    }

    uVar2 = iVar1 - *(int *)((longlong)param_1 + 0x1c);

    *(int *)((longlong)param_1 + 0x1c) = iVar1;

    uVar4 = (ulonglong)uVar2;

    uVar3 = uVar4;

    if ((int)uVar2 < 1) {

      FUN_14017cea0(param_1[2]);

      return;

    }

    do {

      FUN_14017cea0(*param_1);

      uVar3 = uVar3 - 1;

    } while (uVar3 != 0);

    FUN_14017cea0(param_1[2]);

    do {

      FUN_140163d70(param_1[1]);

      uVar4 = uVar4 - 1;

    } while (uVar4 != 0);

  }

  return;

}




