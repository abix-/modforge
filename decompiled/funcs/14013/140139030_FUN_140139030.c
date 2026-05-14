// Address: 0x140139030
// Ghidra name: FUN_140139030
// ============ 0x140139030 FUN_140139030 (size=356) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined8 FUN_140139030(int *param_1)



{

  int iVar1;

  int iVar2;

  undefined8 uVar3;

  int iVar4;

  undefined8 *puVar5;

  

  iVar4 = FUN_140138fe0(&DAT_1403fbeac);

  if (0xfffe < iVar4) {

    FUN_14012e850("Event queue is full (%d events)",iVar4);

    return 0;

  }

  if (DAT_1403fbec8 == (undefined8 *)0x0) {

    puVar5 = (undefined8 *)FUN_1401841f0(0x98);

    if (puVar5 == (undefined8 *)0x0) {

      return 0;

    }

  }

  else {

    puVar5 = DAT_1403fbec8;

    DAT_1403fbec8 = (undefined8 *)DAT_1403fbec8[0x12];

  }

  if (0 < DAT_1403fbed0) {

    FUN_14013ad50(param_1);

  }

  uVar3 = *(undefined8 *)(param_1 + 2);

  *puVar5 = *(undefined8 *)param_1;

  puVar5[1] = uVar3;

  uVar3 = *(undefined8 *)(param_1 + 6);

  puVar5[2] = *(undefined8 *)(param_1 + 4);

  puVar5[3] = uVar3;

  uVar3 = *(undefined8 *)(param_1 + 10);

  puVar5[4] = *(undefined8 *)(param_1 + 8);

  puVar5[5] = uVar3;

  uVar3 = *(undefined8 *)(param_1 + 0xe);

  puVar5[6] = *(undefined8 *)(param_1 + 0xc);

  puVar5[7] = uVar3;

  uVar3 = *(undefined8 *)(param_1 + 0x12);

  puVar5[8] = *(undefined8 *)(param_1 + 0x10);

  puVar5[9] = uVar3;

  uVar3 = *(undefined8 *)(param_1 + 0x16);

  puVar5[10] = *(undefined8 *)(param_1 + 0x14);

  puVar5[0xb] = uVar3;

  iVar4 = param_1[0x19];

  iVar1 = param_1[0x1a];

  iVar2 = param_1[0x1b];

  *(int *)(puVar5 + 0xc) = param_1[0x18];

  *(int *)((longlong)puVar5 + 100) = iVar4;

  *(int *)(puVar5 + 0xd) = iVar1;

  *(int *)((longlong)puVar5 + 0x6c) = iVar2;

  iVar4 = param_1[0x1d];

  iVar1 = param_1[0x1e];

  iVar2 = param_1[0x1f];

  *(int *)(puVar5 + 0xe) = param_1[0x1c];

  *(int *)((longlong)puVar5 + 0x74) = iVar4;

  *(int *)(puVar5 + 0xf) = iVar1;

  *(int *)((longlong)puVar5 + 0x7c) = iVar2;

  if (*param_1 == 0x7f00) {

    FUN_140138fb0(&DAT_1403fb690,1);

  }

  puVar5[0x10] = 0;

  FUN_14013ba80(puVar5);

  if (DAT_1403fbec0 == (undefined8 *)0x0) {

    DAT_1403fbeb8 = puVar5;

    DAT_1403fbec0 = puVar5;

    puVar5[0x11] = 0;

  }

  else {

    *(undefined8 **)((longlong)DAT_1403fbec0 + 0x90) = puVar5;

    puVar5[0x11] = DAT_1403fbec0;

    DAT_1403fbec0 = puVar5;

  }

  puVar5[0x12] = 0;

  iVar4 = FUN_140138fb0(&DAT_1403fbeac,1);

  if (DAT_1403fbeb0 < iVar4 + 1) {

    DAT_1403fbeb0 = iVar4 + 1;

  }

  _DAT_1403fb694 = _DAT_1403fb694 + 1;

  return 1;

}




