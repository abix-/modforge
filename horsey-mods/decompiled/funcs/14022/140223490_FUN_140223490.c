// Address: 0x140223490
// Ghidra name: FUN_140223490
// ============ 0x140223490 FUN_140223490 (size=230) ============


void FUN_140223490(longlong param_1,undefined4 *param_2)



{

  char cVar1;

  char cVar2;

  char cVar3;

  char cVar4;

  uint uVar5;

  

  *(undefined8 *)(param_2 + 2) = 0;

  *(undefined8 *)(param_2 + 4) = 0;

  *(undefined8 *)(param_2 + 6) = 0;

  *(undefined8 *)(param_2 + 8) = 0;

  uVar5 = 0x24;

  param_2[1] = 0x24;

  *param_2 = 0x10028;

  if (*(int *)(param_1 + 0x3bc) != 0) {

    uVar5 = 0x25;

    param_2[1] = 0x25;

  }

  if (*(int *)(param_1 + 0x3d0) != 0) {

    param_2[1] = uVar5 | 2;

  }

  cVar4 = *(char *)(param_1 + 0x3a0);

  *(char *)((longlong)param_2 + 10) = cVar4;

  cVar1 = *(char *)(param_1 + 0x3a4);

  *(char *)(param_2 + 3) = cVar1;

  cVar2 = *(char *)(param_1 + 0x3a8);

  *(char *)((longlong)param_2 + 0xe) = cVar2;

  *(undefined1 *)(param_2 + 4) = *(undefined1 *)(param_1 + 0x3ac);

  if (*(int *)(param_1 + 0x3b4) == 0) {

    cVar4 = cVar1 + cVar2 + cVar4;

  }

  else {

    cVar4 = (char)*(int *)(param_1 + 0x3b4) - *(char *)(param_1 + 0x3ac);

  }

  *(char *)((longlong)param_2 + 9) = cVar4;

  cVar4 = *(char *)(param_1 + 0x3c0);

  *(char *)((longlong)param_2 + 0x13) = cVar4;

  cVar1 = *(char *)(param_1 + 0x3c4);

  *(char *)(param_2 + 5) = cVar1;

  cVar2 = *(char *)(param_1 + 0x3c8);

  *(char *)((longlong)param_2 + 0x15) = cVar2;

  cVar3 = *(char *)(param_1 + 0x3cc);

  *(char *)((longlong)param_2 + 0x16) = cVar3;

  *(char *)((longlong)param_2 + 0x12) = cVar3 + cVar2 + cVar1 + cVar4;

  *(undefined1 *)((longlong)param_2 + 0x17) = *(undefined1 *)(param_1 + 0x3b0);

  *(undefined1 *)(param_2 + 6) = *(undefined1 *)(param_1 + 0x3b8);

  return;

}




