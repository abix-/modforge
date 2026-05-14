// Address: 0x140218860
// Ghidra name: FUN_140218860
// ============ 0x140218860 FUN_140218860 (size=871) ============


longlong FUN_140218860(longlong param_1,undefined8 param_2)



{

  int *piVar1;

  uint uVar2;

  int iVar3;

  int iVar4;

  char cVar5;

  int iVar6;

  undefined4 uVar7;

  ulonglong uVar8;

  int *piVar9;

  longlong lVar10;

  code *pcVar11;

  char *pcVar12;

  int *piVar13;

  ulonglong uVar14;

  uint uVar15;

  ulonglong uVar16;

  int local_res8 [2];

  int local_b8 [36];

  

  uVar2 = *(uint *)(param_1 + 0x3f0);

  iVar6 = *(int *)(param_1 + 0x3e4);

  iVar3 = *(int *)(param_1 + 1000);

  if (*(longlong *)(param_1 + 0x690) == 0) {

    pcVar12 = "EGL not initialized";

    goto LAB_140218b9f;

  }

  uVar8 = 0;

  if (*(int *)(param_1 + 0x3f4) != 0) {

    uVar8 = FUN_14016c6d0();

  }

  if (((iVar6 < 3) || ((iVar3 == 0 && (uVar2 == 4)))) && (*(int *)(param_1 + 0x3ec) == 0)) {

    uVar16 = 0;

    if (uVar2 != 0) {

      if (uVar2 != 4) goto LAB_140218907;

      local_b8[0] = 0x3098;

      uVar16 = 2;

      local_b8[1] = 1;

      if (1 < iVar6) {

        local_b8[1] = iVar6;

      }

    }

  }

  else {

LAB_140218907:

    cVar5 = FUN_1402191b0(param_1,0,"EGL_KHR_create_context");

    if (cVar5 == '\0') {

      pcVar12 = "Could not create EGL context (context attributes are not supported)";

      goto LAB_140218b9f;

    }

    local_b8[0] = 0x3098;

    uVar14 = 4;

    local_b8[2] = 0x30fb;

    if ((uVar2 & 0xfffffffb) != 0) {

      local_b8[4] = 0x30fd;

      uVar14 = 6;

      local_b8[5] = uVar2;

    }

    iVar4 = *(int *)(param_1 + 0x3ec);

    uVar16 = uVar14;

    local_b8[1] = iVar6;

    local_b8[3] = iVar3;

    if (iVar4 != 0) {

      uVar16 = (ulonglong)((int)uVar14 + 2);

      local_b8[uVar14] = 0x30fc;

      local_b8[(int)uVar14 + 1] = iVar4;

    }

  }

  uVar14 = uVar16;

  if ((*(int *)(param_1 + 0x404) != 0) &&

     (cVar5 = FUN_1402191b0(param_1,0,"EGL_KHR_create_context_no_error"), cVar5 != '\0')) {

    uVar14 = (ulonglong)((int)uVar16 + 2);

    local_b8[uVar16] = 0x31b3;

    local_b8[(int)uVar16 + 1] = *(int *)(param_1 + 0x404);

  }

  uVar15 = (uint)uVar14;

  if (*(code **)(param_1 + 0x530) != (code *)0x0) {

    piVar9 = (int *)(**(code **)(param_1 + 0x530))

                              (*(undefined8 *)(param_1 + 0x538),

                               *(undefined8 *)(*(longlong *)(param_1 + 0x690) + 0x10),

                               *(undefined8 *)(*(longlong *)(param_1 + 0x690) + 0x18));

    if (piVar9 == (int *)0x0) {

      *(undefined4 *)(param_1 + 0x410) = 0;

      pcVar12 = "EGL context attribute callback returned NULL pointer";

      *(undefined1 *)(param_1 + 0x418) = 0;

      goto LAB_140218b9f;

    }

    iVar6 = *piVar9;

    piVar13 = piVar9;

    uVar16 = uVar14;

    while (iVar6 != 0x3038) {

      if (0x1d < (int)uVar16) {

        *(undefined4 *)(param_1 + 0x410) = 0;

        pcVar12 = "EGL context attribute callback returned too many attributes";

        *(undefined1 *)(param_1 + 0x418) = 0;

        goto LAB_140218b9f;

      }

      uVar15 = (int)uVar16 + 2;

      uVar16 = (ulonglong)uVar15;

      local_b8[uVar14] = *piVar13;

      piVar1 = piVar13 + 1;

      piVar13 = piVar13 + 2;

      local_b8[uVar14 + 1] = *piVar1;

      uVar14 = uVar14 + 2;

      iVar6 = *piVar13;

    }

    FUN_1401841e0(piVar9);

  }

  local_b8[(int)uVar15] = 0x3038;

  uVar7 = 0x30a0;

  if (uVar2 != 4) {

    uVar7 = 0x30a2;

  }

  *(undefined4 *)(*(longlong *)(param_1 + 0x690) + 0x38) = uVar7;

  iVar6 = (**(code **)(*(longlong *)(param_1 + 0x690) + 200))

                    (*(undefined4 *)(*(longlong *)(param_1 + 0x690) + 0x38));

  if (iVar6 == 0) {

    pcVar12 = "Could not bind EGL API";

LAB_140218b9f:

    FUN_14012e850(pcVar12);

    return 0;

  }

  lVar10 = *(longlong *)(param_1 + 0x690);

  lVar10 = (**(code **)(lVar10 + 0x68))

                     (*(undefined8 *)(lVar10 + 0x10),*(undefined8 *)(lVar10 + 0x18),uVar8,local_b8);

  if (lVar10 == 0) {

    uVar7 = (**(code **)(*(longlong *)(param_1 + 0x690) + 0xd0))();

    FUN_14021a490("Could not create EGL context","eglCreateContext",uVar7);

    return 0;

  }

  *(undefined4 *)(*(longlong *)(param_1 + 0x690) + 0x20) = 0;

  cVar5 = FUN_140219e80(param_1,param_2,lVar10);

  if (cVar5 == '\0') {

    FUN_140218ef0(param_1,lVar10);

    return 0;

  }

  iVar6 = *(int *)(*(longlong *)(param_1 + 0x690) + 0x28);

  if ((iVar6 < 2) &&

     (((iVar6 != 1 || (*(int *)(*(longlong *)(param_1 + 0x690) + 0x2c) < 5)) &&

      (cVar5 = FUN_1402191b0(param_1,0,"EGL_KHR_surfaceless_context"), cVar5 == '\0'))))

  goto LAB_140218b89;

  if (uVar2 == 4) {

    cVar5 = FUN_14016c0c0("GL_OES_surfaceless_context");

    if (cVar5 == '\0') {

      FUN_14021a4f0(param_1,0);

      return lVar10;

    }

  }

  else {

    pcVar11 = (code *)FUN_14016c730("glGetIntegerv");

    if (pcVar11 == (code *)0x0) goto LAB_140218b89;

    local_res8[0] = 0;

    (*pcVar11)(0x821b,local_res8);

    if (local_res8[0] < 3) goto LAB_140218b89;

  }

  *(undefined1 *)(param_1 + 0x558) = 1;

LAB_140218b89:

  FUN_14021a4f0(param_1,0);

  return lVar10;

}




