// Address: 0x140004280
// Ghidra name: FUN_140004280
// ============ 0x140004280 FUN_140004280 (size=193) ============


void FUN_140004280(void)



{

  undefined8 *puVar1;

  int iVar2;

  undefined8 *puVar3;

  longlong lVar4;

  undefined8 *puVar5;

  undefined8 local_res8;

  undefined8 local_res10;

  

  local_res10 = 0;

  puVar3 = (undefined8 *)FUN_1402c704c(800);

  local_res8 = 0;

  DAT_1403edf28 = puVar3;

  DAT_1403edf38 = puVar3 + 100;

  iVar2 = memcmp(&local_res10,&local_res8,8);

  if (iVar2 == 0) {

    FUN_1402f94c0(puVar3,0,800);

  }

  else {

    lVar4 = 6;

    puVar1 = puVar3;

    do {

      puVar5 = puVar1;

      *puVar5 = 0;

      puVar5[1] = 0;

      puVar5[2] = 0;

      puVar5[3] = 0;

      puVar5[4] = 0;

      puVar5[5] = 0;

      puVar5[6] = 0;

      puVar5[7] = 0;

      puVar5[8] = 0;

      puVar5[9] = 0;

      puVar5[10] = 0;

      puVar5[0xb] = 0;

      puVar5[0xc] = 0;

      puVar5[0xd] = 0;

      puVar5[0xe] = 0;

      puVar5[0xf] = 0;

      lVar4 = lVar4 + -1;

      puVar1 = puVar5 + 0x10;

    } while (lVar4 != 0);

    puVar5[0x10] = 0;

    puVar5[0x11] = 0;

    puVar5[0x12] = 0;

    puVar5[0x13] = 0;

  }

  DAT_1403edf30 = puVar3 + 100;

  atexit(FUN_140300830);

  return;

}




