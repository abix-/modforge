// Address: 0x140029110
// Ghidra name: FUN_140029110
// ============ 0x140029110 FUN_140029110 (size=700) ============


void FUN_140029110(longlong param_1,longlong *param_2,undefined8 *param_3)



{

  ulonglong uVar1;

  ulonglong uVar2;

  undefined *puVar3;

  int iVar4;

  int iVar5;

  uint uVar6;

  undefined8 *puVar7;

  longlong *plVar8;

  longlong lVar9;

  

  iVar4 = *(int *)((longlong)*(int *)(*param_2 + 4) + 0x10 + (longlong)param_2);

  while (iVar4 == 0) {

    iVar4 = FUN_14002c950(param_2);

    if (iVar4 == 0x3c) {

      lVar9 = *param_2;

      iVar4 = *(int *)((longlong)*(int *)(lVar9 + 4) + 0x10 + (longlong)param_2);

      puVar3 = PTR_s_Error_14039a3b8;

      goto joined_r0x000140029204;

    }

    if (iVar4 < 1) break;

    FUN_14002cac0(param_2);

    uVar1 = param_3[2];

    if (uVar1 < (ulonglong)param_3[3]) {

      param_3[2] = uVar1 + 1;

      puVar7 = param_3;

      if (0xf < (ulonglong)param_3[3]) {

        puVar7 = (undefined8 *)*param_3;

      }

      *(char *)(uVar1 + (longlong)puVar7) = (char)iVar4;

      *(undefined1 *)(uVar1 + 1 + (longlong)puVar7) = 0;

    }

    else {

      FUN_1400280d0(param_3);

    }

    iVar4 = *(int *)((longlong)*(int *)(*param_2 + 4) + 0x10 + (longlong)param_2);

  }

  puVar3 = PTR_s_Error__empty_tag__14039a3e8;

  if (*(char *)(param_1 + 0x68) != '\0') {

    return;

  }

  lVar9 = -1;

  *(undefined1 *)(param_1 + 0x68) = 1;

  *(undefined4 *)(param_1 + 0x6c) = 7;

  do {

    lVar9 = lVar9 + 1;

  } while (puVar3[lVar9] != '\0');

  FUN_140027f50(param_1 + 0x70);

  *(undefined8 *)(param_1 + 0x94) = 0xffffffffffffffff;

  return;

joined_r0x000140029204:

  PTR_s_Error_14039a3b8 = puVar3;

  if (iVar4 != 0) {

    if (*(char *)(param_1 + 0x68) == '\0') {

      lVar9 = -1;

      *(undefined1 *)(param_1 + 0x68) = 1;

      *(undefined4 *)(param_1 + 0x6c) = 1;

      do {

        lVar9 = lVar9 + 1;

      } while (puVar3[lVar9] != '\0');

LAB_140029370:

      FUN_140027f50(param_1 + 0x70);

      *(undefined8 *)(param_1 + 0x94) = 0xffffffffffffffff;

    }

    return;

  }

  iVar4 = *(int *)(param_3 + 2);

  iVar5 = *(int *)((longlong)*(int *)(lVar9 + 4) + 0x10 + (longlong)param_2);

  while( true ) {

    if ((iVar5 != 0) || (iVar5 = FUN_14002c950(param_2), iVar5 == 0x3e)) goto LAB_1400292c4;

    uVar6 = FUN_14002cac0(param_2);

    puVar3 = PTR_s_Error_null__0__or_unexpected_EOF_14039a418;

    if ((int)uVar6 < 1) break;

    uVar1 = param_3[2];

    uVar2 = param_3[3];

    if (uVar1 < uVar2) {

      param_3[2] = uVar1 + 1;

      puVar7 = param_3;

      if (0xf < uVar2) {

        puVar7 = (undefined8 *)*param_3;

      }

      *(char *)(uVar1 + (longlong)puVar7) = (char)uVar6;

      *(undefined1 *)(uVar1 + 1 + (longlong)puVar7) = 0;

    }

    else {

      FUN_1400280d0(param_3,uVar1,uVar2,uVar6 & 0xff);

    }

    iVar5 = *(int *)((longlong)*(int *)(*param_2 + 4) + 0x10 + (longlong)param_2);

  }

  if (*(char *)(param_1 + 0x68) == '\0') {

    lVar9 = -1;

    *(undefined1 *)(param_1 + 0x68) = 1;

    *(undefined4 *)(param_1 + 0x6c) = 0xd;

    do {

      lVar9 = lVar9 + 1;

    } while (puVar3[lVar9] != '\0');

    FUN_140027f50(param_1 + 0x70);

    *(undefined8 *)(param_1 + 0x94) = 0xffffffffffffffff;

  }

LAB_1400292c4:

  if (*(int *)((longlong)*(int *)(*param_2 + 4) + 0x10 + (longlong)param_2) == 0) {

    puVar7 = param_3;

    if (0xf < (ulonglong)param_3[3]) {

      puVar7 = (undefined8 *)*param_3;

    }

    plVar8 = (longlong *)FUN_1400297b0(param_1,(longlong)puVar7 + (longlong)iVar4,0);

    puVar3 = PTR_s_Error_14039a3b8;

    if (plVar8 != (longlong *)0x0) {

      (**(code **)(*plVar8 + 0x88))(plVar8,param_2,param_3);

      lVar9 = (**(code **)(*plVar8 + 0x28))(plVar8);

      (**(code **)*plVar8)(plVar8,1);

      if (lVar9 != 0) {

        return;

      }

      goto LAB_140029335;

    }

    if (*(char *)(param_1 + 0x68) != '\0') {

      return;

    }

    lVar9 = -1;

    *(undefined1 *)(param_1 + 0x68) = 1;

    *(undefined4 *)(param_1 + 0x6c) = 1;

    do {

      lVar9 = lVar9 + 1;

    } while (puVar3[lVar9] != '\0');

    goto LAB_140029370;

  }

LAB_140029335:

  lVar9 = *param_2;

  iVar4 = *(int *)((longlong)*(int *)(lVar9 + 4) + 0x10 + (longlong)param_2);

  puVar3 = PTR_s_Error_14039a3b8;

  goto joined_r0x000140029204;

}




