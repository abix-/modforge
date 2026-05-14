// Address: 0x14009b650
// Ghidra name: FUN_14009b650
// ============ 0x14009b650 FUN_14009b650 (size=225) ============


void FUN_14009b650(longlong param_1)



{

  undefined8 uVar1;

  undefined8 *puVar2;

  longlong lVar3;

  char local_res8 [8];

  longlong local_res10;

  

  FUN_140075b80(&DAT_1403eded8);

  FUN_140075b80(param_1 + 0x268);

  FUN_140075b80(param_1 + 0x26c);

  FUN_140075b80(param_1 + 0x3d4);

  FUN_140075e80(param_1 + 0x3d8);

  FUN_140075b80(param_1 + 0x3dc);

  FUN_140075b80(param_1 + 0x3e0);

  puVar2 = (undefined8 *)(param_1 + 0x390);

  lVar3 = 3;

  do {

    local_res8[0] = '\0';

    FUN_140075e80(local_res8);

    if (local_res8[0] == '\0') {

      *puVar2 = 0;

    }

    else {

      local_res10 = FUN_1402c704c(0x498);

      uVar1 = 0;

      if (local_res10 != 0) {

        uVar1 = FUN_1400aac60(local_res10);

      }

      *puVar2 = uVar1;

      FUN_14006f150(uVar1);

    }

    puVar2 = puVar2 + 1;

    lVar3 = lVar3 + -1;

  } while (lVar3 != 0);

  return;

}




