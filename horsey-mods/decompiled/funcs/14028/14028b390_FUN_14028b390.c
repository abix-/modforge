// Address: 0x14028b390
// Ghidra name: FUN_14028b390
// ============ 0x14028b390 FUN_14028b390 (size=287) ============


undefined8 FUN_14028b390(longlong param_1)



{

  char cVar1;

  uint uVar2;

  ulonglong uVar3;

  undefined1 *puVar4;

  undefined2 local_res8;

  undefined4 local_resa;

  undefined1 local_rese;

  undefined8 local_28;

  undefined8 uStack_20;

  undefined8 local_18;

  

  local_res8 = 0xd;

  uVar3 = 0;

  local_resa = 0;

  local_rese = 0;

  cVar1 = FUN_14015adf0(*(undefined8 *)(param_1 + 0xa68),&local_res8,7);

  if (cVar1 != '\0') {

    FUN_1402f94c0(param_1 + 8,0,0x980);

    FUN_1402f94c0(param_1 + 0x988,0,0xc0);

    *(undefined4 *)(param_1 + 0x9b4) = 1;

    *(undefined4 *)(param_1 + 0x9e4) = 0x80;

    local_28 = 0;

    uStack_20 = 0;

    local_18 = 0;

    puVar4 = (undefined1 *)(param_1 + 0x9b0);

    *(undefined4 *)(param_1 + 0xa14) = 0x100;

    *(undefined4 *)(param_1 + 0xa44) = 0x400;

    while( true ) {

      *(int *)(puVar4 + -0x28) = (int)uVar3;

      FUN_14028b9c0(uVar3 * 0x30 + 0x988 + param_1,&local_28);

      cVar1 = FUN_14015adf0(*(undefined8 *)(param_1 + 0xa68),&local_res8,7);

      if (cVar1 == '\0') break;

      *puVar4 = 0;

      uVar2 = (int)uVar3 + 1;

      uVar3 = (ulonglong)uVar2;

      puVar4 = puVar4 + 0x30;

      if (3 < (int)uVar2) {

        return 0;

      }

    }

  }

  return 0xffffffff;

}




