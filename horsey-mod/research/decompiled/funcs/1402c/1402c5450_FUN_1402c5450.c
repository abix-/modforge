// Address: 0x1402c5450
// Ghidra name: FUN_1402c5450
// ============ 0x1402c5450 FUN_1402c5450 (size=191) ============


undefined8 FUN_1402c5450(longlong param_1)



{

  char cVar1;

  int iVar2;

  ulonglong uVar3;

  uint uVar4;

  ulonglong uVar5;

  ulonglong uVar6;

  ulonglong uVar7;

  

  uVar3 = 0;

  if ((*(int *)(param_1 + 0xc) != 0) && (*(int *)(param_1 + 8) != 0)) {

    uVar5 = uVar3;

    if ((*(int *)(param_1 + 0x24) == 0) &&

       ((uVar4 = *(uint *)(param_1 + 0x18), uVar5 = 0, uVar4 != 0 &&

        (uVar4 <= *(uint *)(param_1 + 0x1c))))) {

      uVar5 = (ulonglong)uVar4;

      do {

        cVar1 = FUN_1402c5510(param_1,uVar5);

        if (cVar1 == '\0') {

          return 0;

        }

        uVar4 = (int)uVar5 + 1;

        uVar5 = (ulonglong)uVar4;

      } while (uVar4 <= *(uint *)(param_1 + 0x1c));

    }

    uVar6 = uVar3;

    uVar7 = uVar3;

    if (*(int *)(param_1 + 0xc) != 0) {

      do {

        iVar2 = (int)uVar3;

        if ((iVar2 < *(int *)(param_1 + 0x24)) &&

           (uVar5 = (ulonglong)*(uint *)(uVar6 + *(longlong *)(param_1 + 0x28)),

           iVar2 < *(int *)(param_1 + 0x24) + -1)) {

          uVar3 = (ulonglong)(iVar2 + 1);

          uVar6 = uVar6 + 4;

        }

        iVar2 = *(int *)(param_1 + 8);

        if (((int)uVar5 != 0) && (cVar1 = FUN_1402c53b0(param_1,uVar5,iVar2), cVar1 == '\0')) {

          return 0;

        }

        *(int *)(param_1 + 0x38) = *(int *)(param_1 + 0x38) + iVar2;

        uVar4 = (int)uVar7 + 1;

        uVar7 = (ulonglong)uVar4;

      } while (uVar4 < *(uint *)(param_1 + 0xc));

    }

  }

  return 1;

}




