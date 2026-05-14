// Address: 0x1401de770
// Ghidra name: FUN_1401de770
// ============ 0x1401de770 FUN_1401de770 (size=856) ============


undefined8 FUN_1401de770(longlong param_1)



{

  longlong lVar1;

  longlong lVar2;

  int iVar3;

  undefined8 uVar4;

  undefined4 local_d8;

  undefined4 uStack_d4;

  undefined4 uStack_d0;

  undefined4 uStack_cc;

  undefined4 uStack_c8;

  undefined4 uStack_c4;

  undefined8 uStack_c0;

  undefined8 uStack_b8;

  undefined4 local_b0;

  undefined4 local_ac;

  undefined4 uStack_a8;

  undefined4 uStack_a4;

  undefined4 uStack_a0;

  undefined4 local_9c;

  undefined8 local_98;

  undefined8 uStack_90;

  undefined8 local_88;

  undefined8 uStack_80;

  undefined8 local_78;

  undefined8 uStack_70;

  undefined8 local_68;

  undefined8 uStack_60;

  undefined8 local_58;

  undefined8 uStack_50;

  undefined8 local_48;

  undefined8 uStack_40;

  undefined4 local_38;

  undefined4 uStack_34;

  undefined4 uStack_30;

  undefined4 uStack_2c;

  undefined4 local_28;

  undefined4 uStack_24;

  undefined4 uStack_20;

  undefined4 uStack_1c;

  

  lVar1 = *(longlong *)(param_1 + 0x2e0);

  local_d8 = 0x3f800000;

  uStack_d4 = 0;

  uStack_d0 = 0;

  uStack_cc = 0;

  uStack_c8 = 0;

  uStack_c4 = 0x3f800000;

  uStack_c0 = 0;

  uStack_b8 = 0;

  local_b0 = 0x3f800000;

  local_48 = 0x3f80000000000000;

  local_9c = 0x3f800000;

  local_ac = 0;

  uStack_a8 = 0;

  uStack_a4 = 0;

  uStack_a0 = 0;

  local_58 = 0x3f800000;

  uStack_50 = 0;

  uStack_40 = 0;

  local_28 = 0;

  uStack_24 = 0;

  uStack_20 = 0;

  uStack_1c = 0x3f800000;

  local_38 = 0;

  uStack_34 = 0;

  uStack_30 = 0x3f800000;

  uStack_2c = 0;

  if (*(char *)(lVar1 + 0x61) == '\0') {

    (**(code **)(**(longlong **)(lVar1 + 0x10) + 0x150))();

    *(undefined1 *)(lVar1 + 0x61) = 1;

  }

  if (*(longlong **)(lVar1 + 0x88) != (longlong *)0x0) {

    (**(code **)(**(longlong **)(lVar1 + 0x88) + 0x10))();

    *(undefined8 *)(lVar1 + 0x88) = 0;

  }

  if (*(longlong **)(lVar1 + 0x90) != (longlong *)0x0) {

    (**(code **)(**(longlong **)(lVar1 + 0x90) + 0x10))();

    *(undefined8 *)(lVar1 + 0x90) = 0;

  }

  for (lVar2 = *(longlong *)(param_1 + 0x1e8); lVar2 != 0; lVar2 = *(longlong *)(lVar2 + 0x148)) {

    if (*(int *)(lVar2 + 0x24) == 2) {

      FUN_1401dd550();

    }

    else {

      FUN_1401de410(param_1,lVar2);

    }

  }

  for (lVar2 = *(longlong *)(lVar1 + 0x198); lVar2 != 0; lVar2 = *(longlong *)(lVar2 + 0x30)) {

    FUN_1401de490(*(undefined8 *)(lVar1 + 0x10),lVar2);

  }

  if (*(longlong **)(lVar1 + 0xc0) != (longlong *)0x0) {

    (**(code **)(**(longlong **)(lVar1 + 0xc0) + 0x10))();

  }

  *(undefined8 *)(lVar1 + 0xc0) = 0;

  *(undefined8 *)(lVar1 + 0x100) = 0;

  if (*(longlong **)(lVar1 + 200) != (longlong *)0x0) {

    (**(code **)(**(longlong **)(lVar1 + 200) + 0x10))();

  }

  *(undefined8 *)(lVar1 + 200) = 0;

  *(undefined8 *)(lVar1 + 0x108) = 0;

  if (*(longlong **)(lVar1 + 0xd0) != (longlong *)0x0) {

    (**(code **)(**(longlong **)(lVar1 + 0xd0) + 0x10))();

  }

  *(undefined8 *)(lVar1 + 0xd0) = 0;

  *(undefined8 *)(lVar1 + 0x110) = 0;

  if (*(longlong **)(lVar1 + 0xd8) != (longlong *)0x0) {

    (**(code **)(**(longlong **)(lVar1 + 0xd8) + 0x10))();

  }

  *(undefined8 *)(lVar1 + 0xd8) = 0;

  *(undefined8 *)(lVar1 + 0x118) = 0;

  if (*(longlong **)(lVar1 + 0xe0) != (longlong *)0x0) {

    (**(code **)(**(longlong **)(lVar1 + 0xe0) + 0x10))();

  }

  *(undefined8 *)(lVar1 + 0xe0) = 0;

  *(undefined8 *)(lVar1 + 0x120) = 0;

  if (*(longlong **)(lVar1 + 0xe8) != (longlong *)0x0) {

    (**(code **)(**(longlong **)(lVar1 + 0xe8) + 0x10))();

  }

  *(undefined8 *)(lVar1 + 0xe8) = 0;

  *(undefined8 *)(lVar1 + 0x128) = 0;

  if (*(longlong **)(lVar1 + 0xf0) != (longlong *)0x0) {

    (**(code **)(**(longlong **)(lVar1 + 0xf0) + 0x10))();

  }

  *(undefined8 *)(lVar1 + 0xf0) = 0;

  *(undefined8 *)(lVar1 + 0x130) = 0;

  if (*(longlong **)(lVar1 + 0xf8) != (longlong *)0x0) {

    (**(code **)(**(longlong **)(lVar1 + 0xf8) + 0x10))();

  }

  *(undefined8 *)(lVar1 + 0xf8) = 0;

  *(undefined8 *)(lVar1 + 0x138) = 0;

  iVar3 = (**(code **)(**(longlong **)(lVar1 + 0x10) + 0x80))

                    (*(longlong **)(lVar1 + 0x10),lVar1 + 0x20);

  if (iVar3 < 0) {

    if (iVar3 != -0x7789f798) {

      uVar4 = FUN_1401df290("Reset()",iVar3);

      return uVar4;

    }

  }

  else {

    for (lVar2 = *(longlong *)(param_1 + 0x1e8); lVar2 != 0; lVar2 = *(longlong *)(lVar2 + 0x148)) {

      if (*(int *)(lVar2 + 0x24) == 2) {

        FUN_1401dd050(param_1,lVar2,0);

      }

    }

    (**(code **)(**(longlong **)(lVar1 + 0x10) + 0x130))

              (*(longlong **)(lVar1 + 0x10),0,lVar1 + 0x88);

    FUN_1401dd6d0(lVar1);

    FUN_1401df5c0(param_1,*(undefined8 *)(param_1 + 0x1f0));

    FUN_1401dd960(param_1);

    (**(code **)(**(longlong **)(lVar1 + 0x10) + 0x160))(*(longlong **)(lVar1 + 0x10),2,&local_58);

    uStack_d4 = 0;

    uStack_d0 = 0;

    uStack_cc = 0;

    local_d8 = 0x2000;

    uStack_c8 = 0;

    uStack_c4 = 0;

    uStack_c0 = 0;

    uStack_b8 = 0;

    local_b0 = 0;

    local_ac = 0;

    uStack_a8 = 0;

    uStack_a4 = 0;

    uStack_a0 = 0;

    local_9c = 0;

    local_98 = 0;

    uStack_90 = 0;

    local_88 = 0;

    uStack_80 = 0;

    local_78 = 0;

    uStack_70 = 0;

    local_68 = 0;

    uStack_60 = 0;

    uVar4 = FUN_14014ef60(param_1);

    uStack_c8 = FUN_14016e2d0(uVar4);

    FUN_14013b140(&local_d8);

  }

  return 1;

}




