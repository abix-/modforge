// Address: 0x140207680
// Ghidra name: FUN_140207680
// ============ 0x140207680 FUN_140207680 (size=517) ============


void FUN_140207680(undefined8 *param_1)



{

  undefined8 *puVar1;

  undefined8 *puVar2;

  undefined8 *puVar3;

  int iVar4;

  undefined8 *puVar5;

  undefined *puVar6;

  undefined *puVar7;

  char *pcVar8;

  uint uVar9;

  undefined8 *puVar10;

  bool bVar11;

  

  _guard_check_icall();

  puVar10 = (undefined8 *)param_1[0xd];

  if ((puVar10 == (undefined8 *)0x0) || (*(char *)(puVar10 + 1) == '\0')) {

    pcVar8 = "DISABLED";

    if (puVar10 == (undefined8 *)0x0) {

      puVar6 = &DAT_14034fbc0;

    }

    else {

      puVar6 = (undefined *)*puVar10;

    }

  }

  else {

    puVar6 = (undefined *)*puVar10;

    pcVar8 = "ENABLED";

  }

  puVar7 = &DAT_14034fbc0;

  if ((undefined *)param_1[5] != (undefined *)0x0) {

    puVar7 = (undefined *)param_1[5];

  }

  FUN_14012e080(7,

                "Removing HIDAPI device \'%s\' VID 0x%.4x, PID 0x%.4x, bluetooth %d, version %d, serial %s, interface %d, interface_class %d, interface_subclass %d, interface_protocol %d, usage page 0x%.4x, usage 0x%.4x, path = %s, driver = %s (%s)"

                ,*param_1,*(undefined2 *)(param_1 + 4),*(undefined2 *)((longlong)param_1 + 0x22),

                *(undefined1 *)((longlong)param_1 + 0x54),*(undefined2 *)((longlong)param_1 + 0x24),

                puVar7,*(undefined4 *)(param_1 + 8),*(undefined4 *)((longlong)param_1 + 0x44),

                *(undefined4 *)(param_1 + 9),*(undefined4 *)((longlong)param_1 + 0x4c),

                *(undefined2 *)(param_1 + 10),*(undefined2 *)((longlong)param_1 + 0x52),param_1[3],

                puVar6,pcVar8);

  puVar5 = (undefined8 *)0x0;

  puVar3 = puVar5;

  puVar10 = DAT_1403fd198;

  do {

    puVar2 = puVar3;

    if (puVar10 == (undefined8 *)0x0) {

      return;

    }

    puVar1 = (undefined8 *)puVar10[0x17];

    bVar11 = puVar10 != param_1;

    puVar3 = puVar10;

    puVar10 = puVar1;

  } while (bVar11);

  if (puVar2 != (undefined8 *)0x0) {

    puVar2[0x17] = puVar1;

    puVar1 = DAT_1403fd198;

  }

  DAT_1403fd198 = puVar1;

  FUN_140207340(param_1);

  iVar4 = FUN_140138fe0(param_1 + 0x11);

  while (0 < iVar4) {

    FUN_1401492f0(10);

    iVar4 = FUN_140138fe0(param_1 + 0x11);

  }

  puVar10 = puVar5;

  if (0 < *(int *)(param_1 + 0x15)) {

    do {

      uVar9 = (int)puVar10 + 1;

      *(undefined8 *)(*(longlong *)((longlong)puVar5 + param_1[0x16]) + 0xa0) = 0;

      puVar5 = puVar5 + 1;

      puVar10 = (undefined8 *)(ulonglong)uVar9;

    } while ((int)uVar9 < *(int *)(param_1 + 0x15));

  }

  FUN_1401aa9d0(param_1,9,0);

  FUN_140179b30(param_1[0xf]);

  FUN_1401841e0(param_1[1]);

  FUN_1401841e0(param_1[2]);

  FUN_1401841e0(param_1[5]);

  FUN_1401841e0(*param_1);

  FUN_1401841e0(param_1[3]);

  FUN_1401841e0(param_1[0x16]);

  FUN_1401841e0(param_1);

  return;

}




