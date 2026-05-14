// Address: 0x14019f070
// Ghidra name: FUN_14019f070
// ============ 0x14019f070 FUN_14019f070 (size=251) ============


undefined8 FUN_14019f070(undefined8 *param_1,longlong param_2,undefined8 param_3,int param_4)



{

  longlong lVar1;

  undefined8 uVar2;

  undefined1 *puVar3;

  ulonglong uVar4;

  byte *pbVar5;

  uint uVar6;

  ulonglong uVar7;

  

  pbVar5 = (byte *)param_1[3];

  uVar6 = ((int *)*param_1)[1] * *(int *)*param_1;

  lVar1 = FUN_1401a1ae0(uVar6,param_4,0);

  if (lVar1 == 0) {

    uVar2 = FUN_14019f050("Out of memory");

  }

  else {

    if (uVar6 != 0) {

      uVar7 = (ulonglong)uVar6;

      if (param_4 == 3) {

        puVar3 = (undefined1 *)(lVar1 + 2);

        do {

          uVar4 = (ulonglong)*pbVar5;

          pbVar5 = pbVar5 + 1;

          puVar3[-2] = *(undefined1 *)(param_2 + uVar4 * 4);

          puVar3[-1] = *(undefined1 *)(param_2 + 1 + uVar4 * 4);

          *puVar3 = *(undefined1 *)(param_2 + 2 + uVar4 * 4);

          uVar7 = uVar7 - 1;

          puVar3 = puVar3 + 3;

        } while (uVar7 != 0);

      }

      else {

        puVar3 = (undefined1 *)(lVar1 + 2);

        do {

          uVar4 = (ulonglong)*pbVar5;

          pbVar5 = pbVar5 + 1;

          puVar3[-2] = *(undefined1 *)(param_2 + uVar4 * 4);

          puVar3[-1] = *(undefined1 *)(param_2 + 1 + uVar4 * 4);

          *puVar3 = *(undefined1 *)(param_2 + 2 + uVar4 * 4);

          puVar3[1] = *(undefined1 *)(param_2 + 3 + uVar4 * 4);

          uVar7 = uVar7 - 1;

          puVar3 = puVar3 + 4;

        } while (uVar7 != 0);

      }

    }

    FUN_1401841e0(param_1[3]);

    uVar2 = 1;

    param_1[3] = lVar1;

  }

  return uVar2;

}




