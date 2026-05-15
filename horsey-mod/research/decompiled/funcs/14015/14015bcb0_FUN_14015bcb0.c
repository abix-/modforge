// Address: 0x14015bcb0
// Ghidra name: FUN_14015bcb0
// ============ 0x14015bcb0 FUN_14015bcb0 (size=545) ============


void FUN_14015bcb0(void)



{

  undefined4 *puVar1;

  longlong lVar2;

  char cVar3;

  ulonglong uVar4;

  undefined **ppuVar5;

  uint uVar6;

  undefined4 local_88 [2];

  longlong local_80;

  undefined4 local_78;

  

  if (DAT_1403fc068 != '\0') {

    FUN_140159d30();

    cVar3 = FUN_140210c60();

    if (cVar3 != '\0') {

      FUN_14015bfc0();

    }

    FUN_140208a20();

    uVar6 = 0;

    for (puVar1 = DAT_1403fc070; puVar1 != (undefined4 *)0x0;

        puVar1 = *(undefined4 **)(puVar1 + 0x56)) {

      if (*(char *)(puVar1 + 0x38) != '\0') {

        (**(code **)(*(longlong *)(puVar1 + 0x50) + 0x88))(puVar1);

        if (*(char *)(puVar1 + 0x3c) != '\0') {

          FUN_14013d970(puVar1);

        }

        uVar4 = FUN_140149350();

        if ((*(ulonglong *)(puVar1 + 0x2a) != 0) && (*(ulonglong *)(puVar1 + 0x2a) <= uVar4)) {

          FUN_14015a960(puVar1,0,0,0);

          *(undefined8 *)(puVar1 + 0x2c) = 0;

        }

        if ((*(ulonglong *)(puVar1 + 0x2c) != 0) && (*(ulonglong *)(puVar1 + 0x2c) <= uVar4)) {

          (**(code **)(*(longlong *)(puVar1 + 0x50) + 0x60))(puVar1,*(undefined2 *)(puVar1 + 0x28));

          *(ulonglong *)(puVar1 + 0x2c) = uVar4 + 2000;

          if (uVar4 + 2000 == 0) {

            *(undefined8 *)(puVar1 + 0x2c) = 1;

          }

        }

        if ((*(ulonglong *)(puVar1 + 0x30) != 0) && (*(ulonglong *)(puVar1 + 0x30) <= uVar4)) {

          FUN_14015a810(puVar1,0);

          *(undefined8 *)(puVar1 + 0x32) = 0;

        }

        if ((*(ulonglong *)(puVar1 + 0x32) != 0) && (*(ulonglong *)(puVar1 + 0x32) <= uVar4)) {

          (**(code **)(*(longlong *)(puVar1 + 0x50) + 0x68))(puVar1,*(undefined2 *)(puVar1 + 0x2e));

          *(ulonglong *)(puVar1 + 0x32) = uVar4 + 2000;

          if (uVar4 + 2000 == 0) {

            *(undefined8 *)(puVar1 + 0x32) = 1;

          }

        }

      }

    }

    cVar3 = FUN_140139420(0x608);

    puVar1 = DAT_1403fc070;

    lVar2 = local_80;

    if (cVar3 != '\0') {

      for (; local_80 = lVar2, puVar1 != (undefined4 *)0x0; puVar1 = *(undefined4 **)(puVar1 + 0x56)

          ) {

        local_80 = *(longlong *)(puVar1 + 0x4e);

        if (local_80 != 0) {

          local_78 = *puVar1;

          local_88[0] = 0x608;

          FUN_14013b140(local_88);

          *(undefined8 *)(puVar1 + 0x4e) = 0;

          lVar2 = local_80;

        }

        local_80 = lVar2;

        lVar2 = local_80;

      }

    }

    ppuVar5 = &PTR_PTR_1403e2380;

    do {

      (**(code **)(*ppuVar5 + 0x10))();

      uVar6 = uVar6 + 1;

      ppuVar5 = ppuVar5 + 1;

    } while (uVar6 < 6);

    FUN_14015bb10();

  }

  return;

}




