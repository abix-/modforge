// Address: 0x140140ec0
// Ghidra name: FUN_140140ec0
// ============ 0x140140ec0 FUN_140140ec0 (size=678) ============


ulonglong FUN_140140ec0(longlong param_1,char *param_2,char *param_3)



{

  undefined8 *puVar1;

  char cVar2;

  int iVar3;

  undefined4 uVar4;

  undefined4 uVar5;

  longlong lVar6;

  longlong lVar7;

  ulonglong uVar8;

  undefined4 extraout_var;

  int iVar9;

  char cVar10;

  undefined4 local_48;

  undefined4 uStack_44;

  undefined8 uStack_40;

  undefined4 local_38;

  int iStack_34;

  undefined8 uStack_30;

  

  _guard_check_icall();

  uStack_40 = 0;

  uStack_30 = 0;

  cVar2 = *param_2;

  if ((cVar2 == '+') || (cVar10 = '\0', cVar2 == '-')) {

    param_2 = param_2 + 1;

    cVar10 = cVar2;

  }

  lVar6 = thunk_FUN_1402c9340(*(undefined8 *)(*(longlong *)(param_1 + 0x20) + 0x18),

                              ",hint:SDL_GAMECONTROLLER_USE_GAMECUBE_LABELS:=1");

  lVar7 = thunk_FUN_1402c9340(*(undefined8 *)(*(longlong *)(param_1 + 0x20) + 0x18),

                              ",hint:SDL_GAMECONTROLLER_USE_BUTTON_LABELS:=1");

  iVar3 = FUN_14013ddb0(param_2);

  iStack_34 = FUN_140140570(param_2,lVar6 != 0,lVar7 != 0);

  uVar5 = 0x7fff;

  if (iVar3 == -1) {

    uVar8 = 0xffffffff;

    if (iStack_34 == -1) goto LAB_140141124;

    local_38 = 1;

  }

  else {

    local_38 = 2;

    iStack_34 = iVar3;

    if ((1 < iVar3 - 4U) && (cVar10 != '+')) {

      if (cVar10 == '-') {

        uStack_30 = CONCAT44(0xffff8000,(undefined4)uStack_30);

        goto LAB_140140fb3;

      }

      uStack_30 = 0xffff8000;

    }

    uStack_30 = CONCAT44(0x7fff,(undefined4)uStack_30);

  }

LAB_140140fb3:

  cVar2 = *param_3;

  if ((cVar2 == '+') || (cVar10 = '\0', cVar2 == '-')) {

    param_3 = param_3 + 1;

    cVar10 = cVar2;

  }

  uVar8 = strlen(param_3);

  cVar2 = param_3[uVar8 - 1];

  if ((*param_3 == 'a') && (uVar8 = FUN_140190340(param_3[1]), (int)uVar8 != 0)) {

    local_48 = 2;

    uStack_44 = thunk_FUN_1402d89dc(param_3 + 1);

    if (cVar10 == '+') {

      uVar4 = 0;

    }

    else if (cVar10 == '-') {

      uVar4 = 0;

      uVar5 = 0xffff8000;

    }

    else {

      uVar4 = 0xffff8000;

    }

    uStack_40 = CONCAT44(uVar5,uVar4);

    if (cVar2 == '~') {

      uStack_40 = CONCAT44(uVar4,uVar5);

    }

  }

  else if ((*param_3 == 'b') && (uVar8 = FUN_140190340(param_3[1]), (int)uVar8 != 0)) {

    local_48 = 1;

    uStack_44 = thunk_FUN_1402d89dc(param_3 + 1);

  }

  else {

    if ((((*param_3 != 'h') || (uVar8 = FUN_140190340(param_3[1]), (int)uVar8 == 0)) ||

        (param_3[2] != '.')) || (uVar8 = FUN_140190340(param_3[3]), (int)uVar8 == 0))

    goto LAB_140141124;

    uVar5 = thunk_FUN_1402d89dc(param_3 + 1);

    uVar4 = thunk_FUN_1402d89dc(param_3 + 3);

    uStack_40 = CONCAT44(uStack_40._4_4_,uVar4);

    local_48 = 3;

    uStack_44 = uVar5;

  }

  iVar3 = *(int *)(param_1 + 0x28);

  iVar9 = 0;

  if (0 < iVar3) {

    do {

      iVar3 = memcmp((void *)((longlong)iVar9 * 0x20 + *(longlong *)(param_1 + 0x30)),&local_48,0x20

                    );

      lVar6 = CONCAT44(extraout_var,iVar3);

      if (iVar3 == 0) goto LAB_140141162;

      iVar3 = *(int *)(param_1 + 0x28);

      iVar9 = iVar9 + 1;

    } while (iVar9 < iVar3);

  }

  *(int *)(param_1 + 0x28) = iVar3 + 1;

  lVar7 = FUN_140184230(*(undefined8 *)(param_1 + 0x30),((longlong)iVar3 + 1) * 0x20);

  if (lVar7 != 0) {

    lVar6 = (longlong)*(int *)(param_1 + 0x28) * 0x20;

    *(longlong *)(param_1 + 0x30) = lVar7;

    puVar1 = (undefined8 *)(lVar6 + -0x20 + lVar7);

    *puVar1 = CONCAT44(uStack_44,local_48);

    puVar1[1] = uStack_40;

    puVar1 = (undefined8 *)(lVar6 + -0x10 + lVar7);

    *puVar1 = CONCAT44(iStack_34,local_38);

    puVar1[1] = uStack_30;

LAB_140141162:

    return CONCAT71((int7)((ulonglong)lVar6 >> 8),1);

  }

  uVar8 = FUN_1401841e0(*(undefined8 *)(param_1 + 0x30));

  *(undefined4 *)(param_1 + 0x28) = 0;

  *(undefined8 *)(param_1 + 0x30) = 0;

LAB_140141124:

  return uVar8 & 0xffffffffffffff00;

}




