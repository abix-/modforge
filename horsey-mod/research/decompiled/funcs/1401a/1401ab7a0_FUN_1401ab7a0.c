// Address: 0x1401ab7a0
// Ghidra name: FUN_1401ab7a0
// ============ 0x1401ab7a0 FUN_1401ab7a0 (size=162) ============


undefined8 FUN_1401ab7a0(longlong param_1,int param_2)



{

  int iVar1;

  longlong lVar2;

  uint uVar3;

  longlong lVar4;

  longlong lVar5;

  ulonglong uVar6;

  

  lVar4 = FUN_1401841a0(param_2,0x18);

  if (lVar4 != 0) {

    iVar1 = *(int *)(param_1 + 0x30);

    lVar2 = *(longlong *)(param_1 + 8);

    *(undefined4 *)(param_1 + 0x34) = 0;

    *(longlong *)(param_1 + 8) = lVar4;

    *(int *)(param_1 + 0x30) = param_2 + -1;

    uVar3 = iVar1 + 1;

    if (uVar3 != 0) {

      uVar6 = (ulonglong)uVar3;

      lVar5 = lVar2;

      do {

        if (*(int *)(lVar5 + 0x14) < 0) {

          FUN_1401ab630(lVar5,lVar4,param_2 + -1,(undefined4 *)(param_1 + 0x34));

        }

        lVar5 = lVar5 + 0x18;

        uVar6 = uVar6 - 1;

      } while (uVar6 != 0);

    }

    FUN_1401841e0(lVar2);

    return 1;

  }

  return 0;

}




