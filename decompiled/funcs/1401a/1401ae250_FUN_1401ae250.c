// Address: 0x1401ae250
// Ghidra name: FUN_1401ae250
// ============ 0x1401ae250 FUN_1401ae250 (size=261) ============


void FUN_1401ae250(longlong param_1,longlong param_2,uint param_3,undefined8 *param_4,uint param_5)



{

  undefined8 uVar1;

  undefined8 *puVar2;

  longlong lVar3;

  ulonglong uVar4;

  undefined4 *puVar5;

  undefined8 *puVar6;

  

  uVar1 = *(undefined8 *)(param_1 + 0x110);

  *(uint *)(param_1 + 0x958) = param_3;

  if (param_3 != 0) {

    puVar5 = (undefined4 *)(param_2 + 8);

    puVar6 = (undefined8 *)(param_1 + 0x898);

    uVar4 = (ulonglong)param_3;

    do {

      puVar2 = (undefined8 *)

               FUN_1401bbea0(uVar1,param_1,*(undefined8 *)(puVar5 + -2),puVar5[1],*puVar5,

                             *(undefined1 *)(puVar5 + 2),6);

      puVar6[0x10] = puVar2;

      *puVar6 = puVar2[3];

      FUN_1401bdb50(param_1,*puVar2);

      puVar6 = puVar6 + 1;

      puVar5 = puVar5 + 6;

      uVar4 = uVar4 - 1;

    } while (uVar4 != 0);

  }

  if (param_5 != 0) {

    puVar6 = (undefined8 *)(param_1 + 0x8d8);

    uVar4 = (ulonglong)param_5;

    do {

      lVar3 = FUN_1401bbe40(uVar1,param_1,*param_4,*(undefined1 *)(param_4 + 1),7);

      puVar6[0x11] = lVar3;

      *puVar6 = *(undefined8 *)(lVar3 + 0x10);

      FUN_1401bd730(param_1,lVar3);

      puVar6 = puVar6 + 1;

      param_4 = param_4 + 2;

      uVar4 = uVar4 - 1;

    } while (uVar4 != 0);

  }

  return;

}




