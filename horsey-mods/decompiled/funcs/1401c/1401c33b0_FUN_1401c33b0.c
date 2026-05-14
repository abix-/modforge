// Address: 0x1401c33b0
// Ghidra name: FUN_1401c33b0
// ============ 0x1401c33b0 FUN_1401c33b0 (size=217) ============


void FUN_1401c33b0(longlong param_1,int param_2,longlong param_3,uint param_4)



{

  uint uVar1;

  longlong lVar2;

  longlong lVar3;

  int *piVar4;

  uint uVar5;

  

  uVar5 = 0;

  if (param_4 != 0) {

    piVar4 = (int *)(param_3 + 8);

    do {

      lVar3 = *(longlong *)(*(longlong *)(piVar4 + -2) + 0x10);

      uVar1 = uVar5 + param_2;

      lVar2 = param_1 + (ulonglong)uVar1 * 8;

      if ((*(longlong *)(lVar2 + 0x228) != lVar3) ||

         (*(int *)(param_1 + 0x2a8 + (ulonglong)uVar1 * 4) != *piVar4)) {

        FUN_1401cb5f0(param_1,lVar3);

        *(longlong *)(lVar2 + 0x228) = lVar3;

        *(int *)(param_1 + ((ulonglong)uVar1 + 0xaa) * 4) = *piVar4;

        *(undefined1 *)(param_1 + 0x210) = 1;

      }

      uVar5 = uVar5 + 1;

      piVar4 = piVar4 + 4;

    } while (uVar5 < param_4);

  }

  uVar5 = *(uint *)(param_1 + 0x2e8);

  if (*(uint *)(param_1 + 0x2e8) <= param_2 + param_4) {

    uVar5 = param_2 + param_4;

  }

  *(uint *)(param_1 + 0x2e8) = uVar5;

  return;

}




