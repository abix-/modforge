// Address: 0x14015bfc0
// Ghidra name: FUN_14015bfc0
// ============ 0x14015bfc0 FUN_14015bfc0 (size=224) ============


void FUN_14015bfc0(void)



{

  undefined4 *puVar1;

  char cVar2;

  undefined1 uVar3;

  longlong *plVar4;

  undefined8 local_88;

  undefined8 local_80;

  undefined4 local_78;

  undefined8 local_74;

  undefined8 uStack_6c;

  undefined8 local_64;

  undefined8 uStack_5c;

  undefined8 local_54;

  undefined8 uStack_4c;

  undefined8 local_44;

  undefined8 uStack_3c;

  undefined8 local_34;

  undefined8 uStack_2c;

  undefined8 local_24;

  undefined8 uStack_1c;

  undefined8 local_14;

  undefined4 local_c;

  

  puVar1 = DAT_1403fc070;

  do {

    if (puVar1 == (undefined4 *)0x0) {

      return;

    }

    cVar2 = FUN_14013f5e0(*puVar1);

    if (cVar2 != '\0') {

      plVar4 = (longlong *)FUN_140158f10(*puVar1);

      if (plVar4 == (longlong *)0x0) {

        if (*(longlong *)(puVar1 + 0xe) != 0) {

          *(undefined8 *)(puVar1 + 0xe) = 0;

          uVar3 = 0;

          goto LAB_14015c021;

        }

      }

      else if (*(longlong *)(puVar1 + 0xe) != *plVar4) {

        *(longlong *)(puVar1 + 0xe) = *plVar4;

        uVar3 = FUN_14015c220(plVar4);

LAB_14015c021:

        *(undefined1 *)(puVar1 + 0x10) = uVar3;

        local_14 = 0;

        local_c = 0;

        local_78 = *puVar1;

        local_88 = 0x65b;

        local_74 = 0;

        uStack_6c = 0;

        local_80 = 0;

        local_64 = 0;

        uStack_5c = 0;

        local_54 = 0;

        uStack_4c = 0;

        local_44 = 0;

        uStack_3c = 0;

        local_34 = 0;

        uStack_2c = 0;

        local_24 = 0;

        uStack_1c = 0;

        FUN_14013b140(&local_88);

      }

    }

    puVar1 = *(undefined4 **)(puVar1 + 0x56);

  } while( true );

}




