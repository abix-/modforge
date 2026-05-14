// Address: 0x14015d7a0
// Ghidra name: FUN_14015d7a0
// ============ 0x14015d7a0 FUN_14015d7a0 (size=511) ============


undefined8 FUN_14015d7a0(longlong param_1,undefined8 *param_2,int param_3)



{

  int iVar1;

  char cVar2;

  undefined8 uVar3;

  longlong lVar4;

  undefined4 *puVar5;

  undefined4 *puVar6;

  undefined4 *puVar7;

  bool bVar8;

  undefined4 local_28 [2];

  undefined4 *local_20;

  

  iVar1 = *(int *)(param_1 + 0xb0);

  cVar2 = FUN_14015da30((undefined8 *)(param_1 + 0x60),param_2,0,0);

  if ((cVar2 == '\0') || (param_3 != *(int *)(param_1 + 0x84))) {

    *(undefined8 *)(param_1 + 0x60) = *param_2;

    *(undefined4 *)(param_1 + 0x68) = *(undefined4 *)(param_2 + 1);

    FUN_14015fec0(param_1);

    *(int *)(param_1 + 0x84) = param_3;

    FUN_14015fd50(param_1);

    if ((*(longlong *)(param_1 + 0x98) != 0) && (iVar1 < *(int *)(param_1 + 0xb0))) {

      FUN_140190140();

      iVar1 = *(int *)(param_1 + 0xb0);

      uVar3 = FUN_14017fc90();

      lVar4 = FUN_140190080(uVar3,(longlong)iVar1);

      bVar8 = lVar4 == 0;

      *(longlong *)(param_1 + 0x98) = lVar4;

      if (*(longlong *)(param_1 + 0xa8) != 0) {

        FUN_140190140();

        iVar1 = *(int *)(param_1 + 0xb0);

        uVar3 = FUN_14017fc90();

        lVar4 = FUN_140190080(uVar3,(longlong)iVar1);

        *(longlong *)(param_1 + 0xa8) = lVar4;

        if (lVar4 == 0) {

          bVar8 = true;

        }

      }

      FUN_140190140(*(undefined8 *)(param_1 + 0xa0));

      *(undefined8 *)(param_1 + 0xa0) = 0;

      if (*(int *)(param_1 + 0x60) != 0x8120) {

        iVar1 = *(int *)(param_1 + 0xb0);

        uVar3 = FUN_14017fc90();

        lVar4 = FUN_140190080(uVar3,(longlong)iVar1);

        *(longlong *)(param_1 + 0xa0) = lVar4;

        if (lVar4 == 0) {

          return 0;

        }

      }

      if (bVar8) {

        return 0;

      }

    }

    local_20 = (undefined4 *)0x0;

    puVar5 = (undefined4 *)FUN_1401841f0(0x10);

    puVar7 = local_28;

    if (puVar5 != (undefined4 *)0x0) {

      *puVar5 = 0x1102;

      puVar5[1] = *(undefined4 *)(param_1 + 0x50);

      *(undefined8 *)(puVar5 + 2) = 0;

      puVar7 = puVar5;

      local_20 = puVar5;

    }

    for (puVar5 = *(undefined4 **)(param_1 + 0xd0); puVar5 != (undefined4 *)0x0;

        puVar5 = *(undefined4 **)(puVar5 + 0xe)) {

      puVar6 = (undefined4 *)FUN_1401841f0(0x10);

      if (puVar6 != (undefined4 *)0x0) {

        *puVar6 = 0x1102;

        puVar6[1] = *puVar5;

        *(undefined8 *)(puVar6 + 2) = 0;

        *(undefined4 **)(puVar7 + 2) = puVar6;

        puVar7 = puVar6;

      }

    }

    if (local_20 != (undefined4 *)0x0) {

      FUN_14017cab0(DAT_1403fc128);

      *(undefined4 **)(DAT_1403fc160 + 2) = local_20;

      DAT_1403fc160 = puVar7;

      FUN_14017cae0(DAT_1403fc128);

    }

  }

  return 1;

}




