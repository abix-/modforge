// Address: 0x14019aa90
// Ghidra name: FUN_14019aa90
// ============ 0x14019aa90 FUN_14019aa90 (size=207) ============


/* WARNING: Type propagation algorithm not settling */



undefined8

FUN_14019aa90(longlong param_1,int param_2,int param_3,int param_4,undefined1 *param_5,int param_6,

             uint param_7,int param_8)



{

  ulonglong uVar1;

  undefined1 *puVar2;

  undefined1 *puVar3;

  ulonglong uVar4;

  int iVar5;

  ulonglong uVar6;

  ulonglong uVar7;

  

  uVar4 = (ulonglong)param_7;

  uVar1 = (ulonglong)((longlong)param_3 << 0x10) / (ulonglong)(longlong)(int)param_7;

  puVar2 = (undefined1 *)((ulonglong)((longlong)param_2 << 0x10) / (ulonglong)(longlong)param_6);

  uVar7 = uVar1 >> 1;

  puVar3 = puVar2;

  if (0 < (int)param_7) {

    do {

      uVar6 = uVar7 >> 0x10;

      uVar7 = uVar7 + uVar1;

      puVar3 = (undefined1 *)((ulonglong)puVar2 >> 1);

      for (iVar5 = param_6; iVar5 != 0; iVar5 = iVar5 + -1) {

        *param_5 = *(undefined1 *)

                    (((ulonglong)puVar3 >> 0x10) + uVar6 * (longlong)param_4 + param_1);

        param_5 = param_5 + 1;

        puVar3 = puVar3 + (longlong)puVar2;

      }

      param_5 = param_5 + (param_8 - param_6);

      uVar4 = uVar4 - 1;

      puVar3 = param_5;

    } while (uVar4 != 0);

  }

  return CONCAT71((int7)((ulonglong)puVar3 >> 8),1);

}




