// Address: 0x14020ec00
// Ghidra name: FUN_14020ec00
// ============ 0x14020ec00 FUN_14020ec00 (size=308) ============


void FUN_14020ec00(void)



{

  longlong lVar1;

  char cVar2;

  longlong local_res8 [4];

  

  cVar2 = FUN_14020f6a0();

  if (cVar2 != '\0') {

    if (DAT_1403fd320 != 0) {

      FUN_140179b40();

    }

    DAT_1403fd398 = FUN_1402205b0();

    local_res8[0] = DAT_1403ffc48;

    DAT_1403ffc48 = 0;

    FUN_140286510(local_res8);

    FUN_140285420(local_res8);

    if (DAT_1403fd320 != 0) {

      FUN_140179b60();

    }

    while (lVar1 = DAT_1403ffc48, local_res8[0] != 0) {

      if (*(char *)(local_res8[0] + 0x20) == '\0') {

        FUN_140287da0(local_res8[0] + 0x24);

      }

      FUN_14015a550(*(undefined4 *)(local_res8[0] + 0x1c));

      lVar1 = *(longlong *)(local_res8[0] + 0x578);

      FUN_1401841e0(*(undefined8 *)(local_res8[0] + 0x10));

      FUN_1401841e0(local_res8[0]);

      local_res8[0] = lVar1;

    }

    while (local_res8[0] = lVar1, local_res8[0] != 0) {

      if (*(char *)(local_res8[0] + 0x18) != '\0') {

        if (*(char *)(local_res8[0] + 0x20) == '\0') {

          FUN_140287b80(local_res8[0] + 0x24);

        }

        FUN_14015a2b0(*(undefined4 *)(local_res8[0] + 0x1c));

        *(undefined1 *)(local_res8[0] + 0x18) = 0;

      }

      lVar1 = *(longlong *)(local_res8[0] + 0x578);

    }

  }

  return;

}




