// Address: 0x14002b4d0
// Ghidra name: FUN_14002b4d0
// ============ 0x14002b4d0 FUN_14002b4d0 (size=377) ============


void FUN_14002b4d0(longlong *param_1,longlong *param_2,undefined8 *param_3)



{

  ulonglong uVar1;

  undefined *puVar2;

  int iVar3;

  undefined8 *puVar4;

  longlong lVar5;

  longlong lVar6;

  

  iVar3 = *(int *)((longlong)*(int *)(*param_2 + 4) + 0x10 + (longlong)param_2);

  while( true ) {

    if (iVar3 != 0) {

      return;

    }

    iVar3 = FUN_14002c950(param_2);

    if (((char)param_1[0xd] == '\0') && (iVar3 == 0x3c)) {

      return;

    }

    if (iVar3 < 1) break;

    uVar1 = param_3[2];

    if (uVar1 < (ulonglong)param_3[3]) {

      param_3[2] = uVar1 + 1;

      puVar4 = param_3;

      if (0xf < (ulonglong)param_3[3]) {

        puVar4 = (undefined8 *)*param_3;

      }

      *(char *)((longlong)puVar4 + uVar1) = (char)iVar3;

      *(undefined1 *)((longlong)puVar4 + uVar1 + 1) = 0;

    }

    else {

      FUN_1400280d0(param_3);

    }

    FUN_14002cac0(param_2);

    if ((((char)param_1[0xd] != '\0') && (iVar3 == 0x3e)) && (uVar1 = param_3[2], 2 < uVar1)) {

      puVar4 = param_3;

      if (0xf < (ulonglong)param_3[3]) {

        puVar4 = (undefined8 *)*param_3;

      }

      if (*(char *)((uVar1 - 2) + (longlong)puVar4) == ']') {

        puVar4 = param_3;

        if (0xf < (ulonglong)param_3[3]) {

          puVar4 = (undefined8 *)*param_3;

        }

        if (*(char *)((uVar1 - 3) + (longlong)puVar4) == ']') {

          return;

        }

      }

    }

    iVar3 = *(int *)((longlong)*(int *)(*param_2 + 4) + 0x10 + (longlong)param_2);

  }

  while (lVar5 = (**(code **)(*param_1 + 0x20))(param_1), lVar5 == 0) {

    param_1 = (longlong *)param_1[3];

    if (param_1 == (longlong *)0x0) {

      return;

    }

  }

  lVar5 = (**(code **)(*param_1 + 0x20))(param_1);

  puVar2 = PTR_s_Error_null__0__or_unexpected_EOF_14039a418;

  if (lVar5 == 0) {

    return;

  }

  if (*(char *)(lVar5 + 0x68) != '\0') {

    return;

  }

  lVar6 = -1;

  *(undefined1 *)(lVar5 + 0x68) = 1;

  *(undefined4 *)(lVar5 + 0x6c) = 0xd;

  do {

    lVar6 = lVar6 + 1;

  } while (puVar2[lVar6] != '\0');

  FUN_140027f50(lVar5 + 0x70);

  *(undefined8 *)(lVar5 + 0x94) = 0xffffffffffffffff;

  return;

}




