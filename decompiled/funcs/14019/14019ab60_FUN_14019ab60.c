// Address: 0x14019ab60
// Ghidra name: FUN_14019ab60
// ============ 0x14019ab60 FUN_14019ab60 (size=209) ============


undefined8

FUN_14019ab60(longlong param_1,int param_2,int param_3,int param_4,undefined2 *param_5,int param_6,

             uint param_7,int param_8)



{

  ulonglong uVar1;

  ulonglong uVar2;

  undefined2 *puVar3;

  undefined2 *puVar4;

  ulonglong uVar5;

  int iVar6;

  ulonglong uVar7;

  ulonglong uVar8;

  

  uVar5 = (ulonglong)param_7;

  uVar2 = (ulonglong)((longlong)param_3 << 0x10) / (ulonglong)(longlong)(int)param_7;

  puVar3 = (undefined2 *)((ulonglong)((longlong)param_2 << 0x10) / (ulonglong)(longlong)param_6);

  uVar8 = uVar2 >> 1;

  puVar4 = puVar3;

  if (0 < (int)param_7) {

    do {

      uVar7 = uVar8 >> 0x10;

      uVar8 = uVar8 + uVar2;

      uVar1 = (ulonglong)puVar3 >> 1;

      for (iVar6 = param_6; iVar6 != 0; iVar6 = iVar6 + -1) {

        *param_5 = *(undefined2 *)(uVar7 * (longlong)param_4 + param_1 + (uVar1 >> 0x10) * 2);

        param_5 = param_5 + 1;

        uVar1 = uVar1 + (longlong)puVar3;

      }

      param_5 = (undefined2 *)((longlong)param_5 + (longlong)(param_8 + param_6 * -2));

      uVar5 = uVar5 - 1;

      puVar4 = param_5;

    } while (uVar5 != 0);

  }

  return CONCAT71((int7)((ulonglong)puVar4 >> 8),1);

}




