// Address: 0x14017d7a0
// Ghidra name: FUN_14017d7a0
// ============ 0x14017d7a0 FUN_14017d7a0 (size=251) ============


void FUN_14017d7a0(undefined8 *param_1,int param_2,undefined4 param_3,uint param_4,int param_5)



{

  undefined8 uVar1;

  undefined8 uVar2;

  undefined8 *puVar3;

  int iVar4;

  ulonglong uVar5;

  uint uVar6;

  

  if (param_5 != 0) {

    uVar1 = CONCAT44(param_3,param_3);

    uVar2 = CONCAT44(param_3,param_3);

    do {

      param_5 = param_5 + -1;

      puVar3 = param_1;

      uVar6 = param_4;

      if (0x3f < (int)param_4) {

        iVar4 = 0x10 - ((uint)param_1 & 0xf);

        if (iVar4 != 0) {

          uVar6 = param_4 - iVar4;

          uVar5 = (ulonglong)((uint)param_1 & 0xf);

          FUN_1402f94c0(param_1,param_3,0x10 - uVar5);

          puVar3 = (undefined8 *)((longlong)param_1 + (0x10 - uVar5));

        }

        for (iVar4 = (int)(uVar6 + ((int)uVar6 >> 0x1f & 0x3fU)) >> 6; iVar4 != 0;

            iVar4 = iVar4 + -1) {

          *puVar3 = uVar1;

          puVar3[1] = uVar2;

          puVar3[2] = uVar1;

          puVar3[3] = uVar2;

          puVar3[4] = uVar1;

          puVar3[5] = uVar2;

          puVar3[6] = uVar1;

          puVar3[7] = uVar2;

          puVar3 = puVar3 + 8;

        }

      }

      if ((uVar6 & 0x3f) != 0) {

        FUN_1402f94c0(puVar3,param_3,uVar6 & 0x3f);

      }

      param_1 = (undefined8 *)((longlong)param_1 + (longlong)param_2);

    } while (param_5 != 0);

  }

  return;

}




