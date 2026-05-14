// Address: 0x1401db980
// Ghidra name: FUN_1401db980
// ============ 0x1401db980 FUN_1401db980 (size=155) ============


undefined8

FUN_1401db980(int param_1,int param_2,undefined1 *param_3,int param_4,undefined1 *param_5,

             int param_6)



{

  undefined1 *puVar1;

  undefined1 uVar2;

  undefined1 uVar3;

  undefined1 uVar4;

  int iVar5;

  uint uVar6;

  int iVar8;

  ulonglong uVar7;

  

  iVar5 = (param_1 + 1) / 2;

  uVar6 = param_6 + iVar5 * -4;

  uVar7 = (ulonglong)uVar6;

  if (param_2 != 0) {

    do {

      param_2 = param_2 + -1;

      for (iVar8 = iVar5; iVar8 != 0; iVar8 = iVar8 + -1) {

        uVar2 = *param_3;

        uVar3 = param_3[1];

        uVar4 = param_3[2];

        puVar1 = param_3 + 3;

        uVar7 = 0;

        param_3 = param_3 + 4;

        *param_5 = *puVar1;

        param_5[1] = uVar2;

        param_5[2] = uVar3;

        param_5[3] = uVar4;

        param_5 = param_5 + 4;

      }

      param_3 = param_3 + (param_4 + iVar5 * -4);

      param_5 = param_5 + (int)uVar6;

    } while (param_2 != 0);

  }

  return CONCAT71((int7)(uVar7 >> 8),1);

}




