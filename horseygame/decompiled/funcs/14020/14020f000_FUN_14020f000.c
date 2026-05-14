// Address: 0x14020f000
// Ghidra name: FUN_14020f000
// ============ 0x14020f000 FUN_14020f000 (size=131) ============


void FUN_14020f000(longlong param_1,int param_2)



{

  undefined4 *puVar1;

  undefined4 uVar2;

  undefined4 uVar3;

  undefined4 uVar4;

  undefined4 *puVar5;

  

  puVar1 = DAT_1403ffc48;

  for (; 0 < param_2; param_2 = param_2 + -1) {

    puVar1 = *(undefined4 **)(puVar1 + 0x15e);

  }

  puVar5 = (undefined4 *)FUN_1401841a0(1,0xc70);

  *(undefined4 **)(param_1 + 0x148) = puVar5;

  if (puVar5 == (undefined4 *)0x0) {

    return;

  }

  uVar2 = puVar1[1];

  uVar3 = puVar1[2];

  uVar4 = puVar1[3];

  *puVar5 = *puVar1;

  puVar5[1] = uVar2;

  puVar5[2] = uVar3;

  puVar5[3] = uVar4;

  if (*(char *)(puVar1 + 8) != '\0') {

    FUN_1402854d0();

    return;

  }

  FUN_140286870(param_1,puVar1);

  return;

}




