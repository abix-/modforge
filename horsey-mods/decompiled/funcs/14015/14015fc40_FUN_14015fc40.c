// Address: 0x14015fc40
// Ghidra name: FUN_14015fc40
// ============ 0x14015fc40 FUN_14015fc40 (size=257) ============


void FUN_14015fc40(void)



{

  uint *puVar1;

  uint *puVar2;

  char cVar3;

  undefined1 uVar4;

  ulonglong local_88;

  undefined8 uStack_80;

  undefined8 local_78;

  undefined8 uStack_70;

  undefined8 local_68;

  undefined8 uStack_60;

  undefined8 local_58;

  undefined8 uStack_50;

  undefined8 local_48;

  undefined8 uStack_40;

  undefined8 local_38;

  undefined8 uStack_30;

  undefined8 local_28;

  undefined8 uStack_20;

  undefined8 local_18;

  undefined8 uStack_10;

  

  FUN_14017caa0(DAT_1403fc128);

  puVar2 = DAT_1403fc158;

  FUN_14017cae0(DAT_1403fc128);

  if (puVar2 != (uint *)0x0) {

    FUN_14017cab0(DAT_1403fc128);

    puVar2 = DAT_1403fc158;

    DAT_1403fc160 = &DAT_1403fc150;

    DAT_1403fc158 = (uint *)0x0;

    FUN_14017cae0(DAT_1403fc128);

    while (puVar2 != (uint *)0x0) {

      puVar1 = *(uint **)(puVar2 + 2);

      cVar3 = FUN_140139420(*puVar2);

      if (cVar3 != '\0') {

        uStack_80 = 0;

        local_88 = (ulonglong)*puVar2;

        uStack_70 = 0;

        local_78 = (ulonglong)puVar2[1];

        local_68 = 0;

        uStack_60 = 0;

        local_58 = 0;

        uStack_50 = 0;

        local_48 = 0;

        uStack_40 = 0;

        local_38 = 0;

        uStack_30 = 0;

        local_28 = 0;

        uStack_20 = 0;

        local_18 = 0;

        uStack_10 = 0;

        uVar4 = FUN_14015ec30();

        local_78._0_5_ = CONCAT14(uVar4,(undefined4)local_78);

        FUN_14013b140(&local_88);

      }

      FUN_1401841e0(puVar2);

      puVar2 = puVar1;

    }

  }

  return;

}




