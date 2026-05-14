// Address: 0x1402dff58
// Ghidra name: FUN_1402dff58
// ============ 0x1402dff58 FUN_1402dff58 (size=455) ============


undefined8 FUN_1402dff58(longlong param_1)



{

  byte *pbVar1;

  byte *pbVar2;

  char cVar3;

  int iVar4;

  ushort *puVar5;

  

  if (*(int *)(param_1 + 0x10) != 0) {

    return 0;

  }

  *(undefined4 *)(param_1 + 0x14) = 0;

  *(undefined2 *)(param_1 + 0x18) = 0;

  *(undefined1 *)(param_1 + 0x1a) = 0;

  *(undefined8 *)(param_1 + 0x20) = 0;

  *(undefined4 *)(param_1 + 0x28) = 0;

  *(undefined1 *)(param_1 + 0x2c) = 0;

  *(undefined4 *)(param_1 + 0x30) = 0;

  if (**(byte **)(param_1 + 8) == 0) {

    *(undefined4 *)(param_1 + 0x14) = 1;

    return 0;

  }

  iVar4 = isspace((uint)**(byte **)(param_1 + 8));

  pbVar2 = *(byte **)(param_1 + 8);

  if (iVar4 != 0) {

    *(undefined4 *)(param_1 + 0x14) = 2;

    iVar4 = isspace((uint)*pbVar2);

    while (iVar4 != 0) {

      *(longlong *)(param_1 + 8) = *(longlong *)(param_1 + 8) + 1;

      iVar4 = isspace((uint)**(byte **)(param_1 + 8));

    }

    return 1;

  }

  if ((*pbVar2 != 0x25) || (pbVar1 = pbVar2 + 1, *pbVar1 == 0x25)) {

    *(undefined4 *)(param_1 + 0x14) = 3;

    *(byte *)(param_1 + 0x18) = *pbVar2;

    *(byte **)(param_1 + 8) = pbVar2 + (ulonglong)(*pbVar2 == 0x25) + 1;

    puVar5 = __pctype_func();

    if (-1 < (short)puVar5[*(byte *)(param_1 + 0x18)]) {

      return 1;

    }

    cVar3 = **(char **)(param_1 + 8);

    if (cVar3 != '\0') {

      *(char *)(param_1 + 0x19) = cVar3;

      *(char **)(param_1 + 8) = *(char **)(param_1 + 8) + 1;

      return 1;

    }

    *(undefined8 *)(param_1 + 0x10) = 0x2a;

    *(undefined2 *)(param_1 + 0x18) = 0;

    *(undefined1 *)(param_1 + 0x1a) = 0;

    *(undefined8 *)(param_1 + 0x20) = 0;

    *(undefined4 *)(param_1 + 0x28) = 0;

    *(undefined1 *)(param_1 + 0x2c) = 0;

    *(undefined4 *)(param_1 + 0x30) = 0;

    return 0;

  }

  *(undefined4 *)(param_1 + 0x14) = 4;

  *(byte **)(param_1 + 8) = pbVar1;

  if (*pbVar1 == 0x2a) {

    *(undefined1 *)(param_1 + 0x1a) = 1;

    *(byte **)(param_1 + 8) = pbVar2 + 2;

  }

  cVar3 = FUN_1402e08a8(param_1);

  if (cVar3 == '\0') {

    return 0;

  }

  FUN_1402e0948(param_1);

  cVar3 = **(char **)(param_1 + 8);

  if (cVar3 == 'w') {

    *(char **)(param_1 + 8) = *(char **)(param_1 + 8) + 1;

  }

  else if ((cVar3 + 0xbdU & 0xef) != 0) goto LAB_1402e0056;

  *(undefined1 *)(param_1 + 0x2c) = 1;

LAB_1402e0056:

  cVar3 = FUN_1402e06dc(param_1);

  if (cVar3 != '\0') {

    if ((&DAT_14038ab00)

        [(longlong)*(int *)(param_1 + 0x28) + (longlong)*(int *)(param_1 + 0x30) * 0xc] != '\0') {

      return 1;

    }

    *(undefined8 *)(param_1 + 0x10) = 0x16;

    *(undefined2 *)(param_1 + 0x18) = 0;

    *(undefined1 *)(param_1 + 0x1a) = 0;

    *(undefined8 *)(param_1 + 0x20) = 0;

    *(undefined4 *)(param_1 + 0x28) = 0;

    *(undefined1 *)(param_1 + 0x2c) = 0;

    *(undefined4 *)(param_1 + 0x30) = 0;

  }

  return 0;

}




