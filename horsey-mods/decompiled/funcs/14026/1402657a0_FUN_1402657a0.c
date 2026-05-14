// Address: 0x1402657a0
// Ghidra name: FUN_1402657a0
// ============ 0x1402657a0 FUN_1402657a0 (size=644) ============


undefined8 FUN_1402657a0(longlong *param_1,longlong param_2,undefined8 *param_3,int param_4)



{

  char cVar1;

  char cVar2;

  char cVar3;

  char cVar4;

  char cVar5;

  char cVar6;

  undefined2 uVar7;

  undefined2 uVar8;

  undefined2 uVar9;

  undefined2 uVar10;

  undefined8 uVar11;

  

  if (param_4 != 0x1c) {

    return 0;

  }

  uVar10 = *(undefined2 *)(param_3 + 2);

  uVar9 = *(undefined2 *)((longlong)param_3 + 0x12);

  cVar1 = *(char *)((longlong)param_3 + 0x1a);

  uVar7 = *(undefined2 *)((longlong)param_3 + 0xc);

  cVar2 = *(char *)((longlong)param_3 + 0x1b);

  uVar8 = *(undefined2 *)((longlong)param_3 + 0xe);

  cVar3 = *(char *)((longlong)param_3 + 0x17);

  cVar4 = *(char *)((longlong)param_3 + 0x16);

  cVar5 = *(char *)(param_3 + 3);

  cVar6 = *(char *)((longlong)param_3 + 0x19);

  FUN_14012e0e0(7,"GIP: Device hello from %I64x (%04x:%04x)",*param_3,*(undefined2 *)(param_3 + 1),

                *(undefined2 *)((longlong)param_3 + 10));

  FUN_14012e0e0(7,"GIP: Firmware version %d.%d.%d rev %d",uVar7,uVar8,uVar10,uVar9);

  if ((cVar4 != '\x01') && (cVar3 != '\0')) {

    FUN_14012e2e0(7,"GIP: Invalid RF protocol version %d.%d, expected 1.0",cVar4,cVar3);

  }

  if ((cVar5 != '\x01') && (cVar6 != '\0')) {

    FUN_14012e2e0(7,"GIP: Invalid security protocol version %d.%d, expected 1.0",cVar5,cVar6);

  }

  if ((cVar1 != '\x01') && (cVar2 != '\0')) {

    FUN_14012e2e0(7,"GIP: Invalid GIP version %d.%d, expected 1.0",cVar1,cVar2);

  }

  if ((*(byte *)(param_2 + 1) & 7) != 0) {

    uVar11 = FUN_140267e80(param_1,4,0,0,0);

    return uVar11;

  }

  *(undefined2 *)((longlong)param_1 + 0x34) = uVar7;

  *(undefined2 *)((longlong)param_1 + 0x36) = uVar8;

  if ((char)param_1[1] == '\0') {

    *(undefined8 *)(*param_1 + 8) = 0;

    *(undefined1 *)(*param_1 + 0x10) = 1;

  }

  if ((int)param_1[7] == 2) {

    *(undefined4 *)(param_1 + 7) = 0;

  }

  FUN_140265350(param_1);

  return 1;

}




