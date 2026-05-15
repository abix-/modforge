// Address: 0x1401323e0
// Ghidra name: FUN_1401323e0
// ============ 0x1401323e0 FUN_1401323e0 (size=248) ============


void FUN_1401323e0(void)



{

  uint *puVar1;

  uint *puVar2;

  char cVar3;

  ulonglong local_88;

  undefined8 uStack_80;

  ulonglong local_78;

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

  

  FUN_14017caa0(DAT_1403fb628);

  puVar2 = DAT_1403fb640;

  FUN_14017cae0(DAT_1403fb628);

  if (puVar2 != (uint *)0x0) {

    FUN_14017cab0(DAT_1403fb628);

    puVar2 = DAT_1403fb640;

    DAT_1403fb648 = &DAT_1403fb638;

    DAT_1403fb640 = (uint *)0x0;

    FUN_14017cae0(DAT_1403fb628);

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

        FUN_14013b140(&local_88);

      }

      FUN_1401841e0(puVar2);

      puVar2 = puVar1;

    }

  }

  return;

}




