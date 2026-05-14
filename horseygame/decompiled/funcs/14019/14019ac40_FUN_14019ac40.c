// Address: 0x14019ac40
// Ghidra name: FUN_14019ac40
// ============ 0x14019ac40 FUN_14019ac40 (size=231) ============


/* WARNING: Type propagation algorithm not settling */



undefined8

FUN_14019ac40(longlong param_1,int param_2,int param_3,int param_4,undefined1 *param_5,int param_6,

             uint param_7,int param_8)



{

  longlong lVar1;

  ulonglong uVar2;

  undefined1 *puVar3;

  undefined1 *puVar4;

  ulonglong uVar5;

  ulonglong uVar6;

  ulonglong uVar7;

  longlong lVar8;

  int iVar9;

  

  uVar6 = (ulonglong)param_7;

  uVar2 = (ulonglong)((longlong)param_3 << 0x10) / (ulonglong)(longlong)(int)param_7;

  puVar3 = (undefined1 *)((ulonglong)((longlong)param_2 << 0x10) / (ulonglong)(longlong)param_6);

  uVar5 = uVar2 >> 1;

  puVar4 = puVar3;

  if (0 < (int)param_7) {

    do {

      uVar7 = uVar5 >> 0x10;

      uVar5 = uVar5 + uVar2;

      lVar8 = uVar7 * (longlong)param_4 + param_1;

      puVar4 = (undefined1 *)((ulonglong)puVar3 >> 1);

      for (iVar9 = param_6; iVar9 != 0; iVar9 = iVar9 + -1) {

        lVar1 = ((ulonglong)puVar4 >> 0x10) * 3;

        *param_5 = *(undefined1 *)(lVar1 + lVar8);

        param_5[1] = *(undefined1 *)(lVar1 + 1 + lVar8);

        param_5[2] = *(undefined1 *)(lVar1 + 2 + lVar8);

        param_5 = param_5 + 3;

        puVar4 = puVar4 + (longlong)puVar3;

      }

      param_5 = param_5 + (param_8 + param_6 * -3);

      uVar6 = uVar6 - 1;

      puVar4 = param_5;

    } while (uVar6 != 0);

  }

  return CONCAT71((int7)((ulonglong)puVar4 >> 8),1);

}




