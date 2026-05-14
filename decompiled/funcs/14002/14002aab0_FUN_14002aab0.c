// Address: 0x14002aab0
// Ghidra name: FUN_14002aab0
// ============ 0x14002aab0 FUN_14002aab0 (size=276) ============


void FUN_14002aab0(longlong *param_1,longlong *param_2,undefined8 *param_3)



{

  int iVar1;

  ulonglong uVar2;

  ulonglong uVar3;

  undefined *puVar4;

  uint uVar5;

  undefined8 *puVar6;

  longlong lVar7;

  longlong lVar8;

  

  iVar1 = *(int *)((longlong)*(int *)(*param_2 + 4) + 0x10 + (longlong)param_2);

  while( true ) {

    if (iVar1 != 0) {

      return;

    }

    uVar5 = FUN_14002cac0(param_2);

    if ((int)uVar5 < 1) break;

    uVar2 = param_3[2];

    uVar3 = param_3[3];

    if (uVar2 < uVar3) {

      param_3[2] = uVar2 + 1;

      puVar6 = param_3;

      if (0xf < uVar3) {

        puVar6 = (undefined8 *)*param_3;

      }

      *(char *)((longlong)puVar6 + uVar2) = (char)uVar5;

      *(undefined1 *)((longlong)puVar6 + uVar2 + 1) = 0;

    }

    else {

      FUN_1400280d0(param_3,uVar2,uVar3,uVar5 & 0xff);

    }

    if (uVar5 == 0x3e) {

      return;

    }

    iVar1 = *(int *)((longlong)*(int *)(*param_2 + 4) + 0x10 + (longlong)param_2);

  }

  while( true ) {

    if (param_1 == (longlong *)0x0) {

      return;

    }

    lVar7 = (**(code **)(*param_1 + 0x20))(param_1);

    if (lVar7 != 0) break;

    param_1 = (longlong *)param_1[3];

  }

  lVar7 = (**(code **)(*param_1 + 0x20))(param_1);

  puVar4 = PTR_s_Error_null__0__or_unexpected_EOF_14039a418;

  if (lVar7 == 0) {

    return;

  }

  if (*(char *)(lVar7 + 0x68) != '\0') {

    return;

  }

  lVar8 = -1;

  *(undefined1 *)(lVar7 + 0x68) = 1;

  *(undefined4 *)(lVar7 + 0x6c) = 0xd;

  do {

    lVar8 = lVar8 + 1;

  } while (puVar4[lVar8] != '\0');

  FUN_140027f50(lVar7 + 0x70);

  *(undefined8 *)(lVar7 + 0x94) = 0xffffffffffffffff;

  return;

}




