// Address: 0x14027d490
// Ghidra name: FUN_14027d490
// ============ 0x14027d490 FUN_14027d490 (size=223) ============


undefined8 FUN_14027d490(longlong param_1,longlong param_2)



{

  undefined8 *puVar1;

  undefined8 uVar2;

  bool bVar3;

  undefined4 uVar4;

  

  puVar1 = *(undefined8 **)(param_1 + 0x70);

  _guard_check_icall();

  *puVar1 = 0;

  puVar1[1] = 0;

  puVar1[2] = 0;

  puVar1[3] = 0;

  puVar1[4] = 0;

  puVar1[5] = 0;

  puVar1[6] = 0;

  puVar1[7] = 0;

  *(undefined4 *)(param_2 + 0x70) = 0x12;

  *(undefined4 *)(param_2 + 0x44) = 6;

  *(undefined4 *)(param_2 + 0x60) = 1;

  bVar3 = *(short *)(param_1 + 0x22) == 0x196;

  *(bool *)(puVar1 + 0xc) = bVar3;

  if (bVar3) {

    if (*(longlong *)(param_1 + 0x28) != 0) {

      uVar2 = FUN_14012f0d0();

      *(undefined8 *)(param_2 + 0x18) = uVar2;

      *(undefined1 *)((longlong)puVar1 + 0x61) = 0;

    }

  }

  else {

    FUN_14027d2e0(param_1);

  }

  uVar4 = DAT_14030c28c;

  if (*(char *)(puVar1 + 0xc) != '\0') {

    uVar4 = DAT_140303758;

  }

  FUN_14015a190(param_2,2,uVar4);

  FUN_14015a190(param_2,1,uVar4);

  uVar2 = 4000000;

  if (*(char *)(puVar1 + 0xc) != '\0') {

    uVar2 = 0x7f26c8;

  }

  puVar1[10] = uVar2;

  return CONCAT71((int7)((ulonglong)uVar2 >> 8),1);

}




