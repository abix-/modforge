// Address: 0x140222a60
// Ghidra name: FUN_140222a60
// ============ 0x140222a60 FUN_140222a60 (size=885) ============


longlong FUN_140222a60(longlong param_1,longlong param_2)



{

  int iVar1;

  undefined8 uVar2;

  char cVar3;

  byte bVar4;

  longlong lVar5;

  longlong lVar6;

  longlong lVar7;

  code *pcVar8;

  ulonglong uVar9;

  int local_58 [4];

  int local_48 [12];

  

  uVar2 = *(undefined8 *)(*(longlong *)(param_2 + 0x188) + 0x18);

  if ((*(int *)(param_1 + 0x3f0) == 4) && (cVar3 = FUN_140223940(), cVar3 != '\0')) {

    FUN_140223900(param_1);

    *(code **)(param_1 + 0x1a0) = FUN_140228c50;

    *(code **)(param_1 + 0x1a8) = FUN_140219030;

    *(code **)(param_1 + 0x1b0) = FUN_14021a5f0;

    *(code **)(param_1 + 0x1b8) = FUN_140228b00;

    *(code **)(param_1 + 0x1c0) = FUN_140228d60;

    *(code **)(param_1 + 0x1d0) = FUN_14021a4f0;

    *(undefined1 **)(param_1 + 0x1d8) = &LAB_1402190e0;

    *(undefined1 **)(param_1 + 0x1e0) = &LAB_140228e50;

    *(undefined1 **)(param_1 + 0x1e8) = &LAB_140228c30;

    *(undefined1 **)(param_1 + 0x1c8) = &LAB_140228c40;

    cVar3 = FUN_140228c50(param_1,0);

    if (cVar3 != '\0') {

      lVar5 = FUN_140228b00(param_1,param_2);

      return lVar5;

    }

    return 0;

  }

  if (*(int *)(param_1 + 0x3f4) == 0) {

    lVar5 = 0;

  }

  else {

    lVar5 = FUN_14016c6d0();

  }

  if (((*(int *)(param_1 + 0x3e4) < 3) && (*(int *)(param_1 + 0x3f0) == 0)) &&

     (*(int *)(param_1 + 0x3ec) == 0)) {

    lVar6 = (**(code **)(*(longlong *)(param_1 + 0x688) + 0x18))(uVar2);

    if (lVar5 != 0) {

      (**(code **)(*(longlong *)(param_1 + 0x688) + 0x30))(lVar5,lVar6);

    }

  }

  else {

    lVar7 = (**(code **)(*(longlong *)(param_1 + 0x688) + 0x18))(uVar2);

    if (lVar7 == 0) {

      FUN_14012e850("Could not create GL context");

      return 0;

    }

    cVar3 = FUN_140223390(param_1,param_2,lVar7);

    if (cVar3 == '\0') {

      FUN_140222de0(param_1,lVar7);

      return 0;

    }

    pcVar8 = (code *)(**(code **)(*(longlong *)(param_1 + 0x688) + 0x10))

                               ("wglCreateContextAttribsARB");

    if (pcVar8 == (code *)0x0) {

      FUN_14012e850("GL 3.x is not supported");

      goto LAB_140222c4b;

    }

    local_58[1] = *(undefined4 *)(param_1 + 0x3e4);

    local_58[3] = *(undefined4 *)(param_1 + 1000);

    iVar1 = *(int *)(param_1 + 0x3f0);

    local_58[0] = 0x2091;

    local_58[2] = 0x2092;

    if (iVar1 != 0) {

      local_48[0] = 0x9126;

      local_48[1] = iVar1;

    }

    uVar9 = 6;

    if (iVar1 == 0) {

      uVar9 = 4;

    }

    iVar1 = *(int *)(param_1 + 0x3ec);

    if (iVar1 != 0) {

      local_58[uVar9] = 0x2094;

      local_58[(int)uVar9 + 1] = iVar1;

      uVar9 = (ulonglong)((int)uVar9 + 2);

    }

    lVar6 = *(longlong *)(param_1 + 0x688);

    if ((*(char *)(lVar6 + 2) != '\0') && (*(int *)(param_1 + 0x3f8) == 0)) {

      local_58[uVar9] = 0x2097;

      local_58[(int)uVar9 + 1] = 0;

      uVar9 = (ulonglong)((int)uVar9 + 2);

    }

    if ((*(char *)(lVar6 + 3) != '\0') && (*(int *)(param_1 + 0x3fc) != 0)) {

      local_58[uVar9] = 0x8256;

      local_58[(int)uVar9 + 1] = 0x8252;

      uVar9 = (ulonglong)((int)uVar9 + 2);

    }

    if ((*(char *)(lVar6 + 4) != '\0') && (iVar1 = *(int *)(param_1 + 0x404), iVar1 != 0)) {

      local_58[uVar9] = 0x31b3;

      local_58[(int)uVar9 + 1] = iVar1;

      uVar9 = (ulonglong)((int)uVar9 + 2);

    }

    local_58[uVar9] = 0;

    lVar6 = (*pcVar8)(uVar2,lVar5,local_58);

    (**(code **)(*(longlong *)(param_1 + 0x688) + 0x20))(lVar7);

  }

  lVar7 = lVar6;

  if (lVar6 == 0) {

    FUN_1401a9ed0("Could not create GL context");

    return 0;

  }

LAB_140222c4b:

  cVar3 = FUN_140223390(param_1,param_2,lVar7);

  if (cVar3 == '\0') {

    FUN_140222de0(param_1,lVar7);

    lVar7 = 0;

  }

  else {

    bVar4 = FUN_14016c0c0("GL_ARB_color_buffer_float");

    *(uint *)(param_1 + 0x414) = (uint)bVar4;

  }

  return lVar7;

}




