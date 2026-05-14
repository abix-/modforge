// Address: 0x1401c26f0
// Ghidra name: FUN_1401c26f0
// ============ 0x1401c26f0 FUN_1401c26f0 (size=256) ============


void FUN_1401c26f0(longlong param_1,longlong param_2,uint param_3,undefined8 *param_4,uint param_5)



{

  undefined8 *puVar1;

  longlong lVar2;

  ulonglong uVar3;

  ulonglong uVar4;

  undefined4 *puVar5;

  undefined8 *puVar6;

  

  uVar4 = (ulonglong)param_5;

  *(uint *)(param_1 + 0x938) = param_5;

  *(uint *)(param_1 + 0x8f0) = param_3;

  if (param_3 != 0) {

    puVar5 = (undefined4 *)(param_2 + 8);

    puVar6 = (undefined8 *)(param_1 + 0x830);

    uVar3 = (ulonglong)param_3;

    do {

      puVar1 = (undefined8 *)

               FUN_1401ca910(param_1,*(undefined8 *)(puVar5 + -2),puVar5[1],*puVar5,

                             *(undefined1 *)(puVar5 + 2),8);

      puVar6[0x10] = puVar1;

      *puVar6 = puVar1[6];

      FUN_1401cb900(param_1,*puVar1);

      puVar6 = puVar6 + 1;

      puVar5 = puVar5 + 6;

      uVar3 = uVar3 - 1;

    } while (uVar3 != 0);

  }

  if (param_5 != 0) {

    puVar6 = (undefined8 *)(param_1 + 0x870);

    do {

      lVar2 = FUN_1401ca8a0(param_1,*param_4,*(undefined1 *)(param_4 + 1),8);

      puVar6[0x11] = lVar2;

      *puVar6 = *(undefined8 *)(lVar2 + 0x28);

      FUN_1401cb5f0(param_1,lVar2);

      puVar6 = puVar6 + 1;

      param_4 = param_4 + 2;

      uVar4 = uVar4 - 1;

    } while (uVar4 != 0);

  }

  return;

}




