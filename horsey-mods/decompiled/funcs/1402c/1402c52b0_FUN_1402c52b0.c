// Address: 0x1402c52b0
// Ghidra name: FUN_1402c52b0
// ============ 0x1402c52b0 FUN_1402c52b0 (size=241) ============


void FUN_1402c52b0(longlong *param_1)



{

  longlong lVar1;

  undefined8 *puVar2;

  undefined8 uVar3;

  char cVar4;

  char cVar5;

  int iVar6;

  longlong lVar7;

  longlong lVar8;

  uint uVar9;

  

  lVar8 = param_1[8];

  lVar1 = param_1[5];

  puVar2 = *(undefined8 **)(*param_1 + 0x28);

  uVar3 = puVar2[1];

  FUN_140179b40(*puVar2);

  if ((int)param_1[1] == 2) {

    cVar4 = '\x01';

    if ((char)param_1[4] != '\0') {

      cVar4 = FUN_14012bda0(puVar2[1]);

    }

    cVar5 = FUN_14012bd50();

    if ((cVar5 != '\0') && (cVar4 != '\0')) {

      uVar9 = 0;

      goto LAB_1402c537b;

    }

  }

  else {

    lVar7 = FUN_14012cb40(uVar3,param_1[3],0);

    if (-1 < lVar7) {

      lVar7 = param_1[1];

      if ((int)lVar7 == 1) {

        lVar8 = FUN_14012cbb0();

      }

      else {

        lVar8 = FUN_14012c730(uVar3,lVar1,lVar8);

      }

      param_1[9] = lVar8;

      if (lVar8 == param_1[8]) {

        uVar9 = 0;

      }

      else if ((int)lVar7 == 1) {

        uVar9 = 1;

      }

      else {

        iVar6 = FUN_14012bf10(uVar3);

        uVar9 = (uint)(iVar6 != 2);

      }

      goto LAB_1402c537b;

    }

  }

  uVar9 = 1;

LAB_1402c537b:

  *(uint *)(param_1 + 7) = uVar9;

  FUN_140179b60(*puVar2);

  FUN_1402c4c90(param_1);

  return;

}




