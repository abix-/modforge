// Address: 0x140218c30
// Ghidra name: FUN_140218c30
// ============ 0x140218c30 FUN_140218c30 (size=690) ============


longlong FUN_140218c30(longlong param_1,longlong param_2,undefined8 param_3)



{

  int *piVar1;

  char cVar2;

  int iVar3;

  undefined4 uVar4;

  char *_Str1;

  int *piVar5;

  longlong lVar6;

  longlong lVar7;

  int *piVar8;

  ulonglong uVar9;

  uint uVar10;

  uint uVar11;

  uint uVar12;

  bool bVar13;

  int local_a8 [36];

  

  uVar10 = 0;

  cVar2 = FUN_1402187e0();

  if (cVar2 == '\0') {

    return 0;

  }

  cVar2 = FUN_1402191b0(param_1,0,"EGL_KHR_gl_colorspace");

  if (cVar2 != '\0') {

    _Str1 = (char *)FUN_140142960("SDL_OPENGL_FORCE_SRGB_FRAMEBUFFER");

    if ((_Str1 == (char *)0x0) || (*_Str1 == '\0')) {

      if (*(int *)(param_1 + 0x400) < 0) goto LAB_140218cfc;

      bVar13 = *(int *)(param_1 + 0x400) != 0;

      local_a8[0] = 0x309d;

    }

    else {

      iVar3 = strcmp(_Str1,"skip");

      if (iVar3 == 0) goto LAB_140218cfc;

      local_a8[0] = 0x309d;

      cVar2 = FUN_1401429e0(_Str1,0);

      bVar13 = cVar2 != '\0';

    }

    local_a8[1] = 0x308a - (uint)bVar13;

    uVar10 = 2;

  }

LAB_140218cfc:

  cVar2 = FUN_1402191b0(param_1,0,"EGL_EXT_present_opaque");

  uVar11 = uVar10;

  uVar12 = 0xffffffff;

  if (cVar2 != '\0') {

    iVar3 = 1;

    if ((param_2 != 0) && (iVar3 = 1, (*(uint *)(param_2 + 0x48) >> 0x1e & 1) != 0)) {

      iVar3 = 0;

    }

    uVar11 = uVar10 + 2;

    local_a8[uVar10] = 0x31df;

    local_a8[uVar10 + 1] = iVar3;

    uVar12 = uVar10;

  }

  if (*(code **)(param_1 + 0x528) != (code *)0x0) {

    piVar5 = (int *)(**(code **)(param_1 + 0x528))

                              (*(undefined8 *)(param_1 + 0x538),

                               *(undefined8 *)(*(longlong *)(param_1 + 0x690) + 0x10),

                               *(undefined8 *)(*(longlong *)(param_1 + 0x690) + 0x18));

    if (piVar5 == (int *)0x0) {

      *(undefined4 *)(param_1 + 0x410) = 0;

      *(undefined1 *)(param_1 + 0x418) = 0;

      FUN_14012e850("EGL surface attribute callback returned NULL pointer");

      return 0;

    }

    if (*piVar5 != 0x3038) {

      uVar9 = (ulonglong)uVar11;

      piVar8 = piVar5;

      do {

        if (0x1d < (int)uVar11) {

          *(undefined4 *)(param_1 + 0x410) = 0;

          *(undefined1 *)(param_1 + 0x418) = 0;

          FUN_14012e850("EGL surface attribute callback returned too many attributes");

          return 0;

        }

        uVar11 = uVar11 + 2;

        local_a8[uVar9] = *piVar8;

        piVar1 = piVar8 + 1;

        piVar8 = piVar8 + 2;

        local_a8[uVar9 + 1] = *piVar1;

        uVar9 = uVar9 + 2;

      } while (*piVar8 != 0x3038);

    }

    FUN_1401841e0(piVar5);

  }

  lVar6 = *(longlong *)(param_1 + 0x690);

  local_a8[(int)uVar11] = 0x3038;

  lVar6 = (**(code **)(lVar6 + 0x80))

                    (*(undefined8 *)(lVar6 + 0x10),*(undefined8 *)(lVar6 + 0x18),param_3,local_a8);

  if (lVar6 == 0) {

    iVar3 = (**(code **)(*(longlong *)(param_1 + 0x690) + 0xd0))();

    if ((iVar3 == 0x3004) && (-1 < (int)uVar12)) {

      FUN_1402f8e20(local_a8 + (int)uVar12,local_a8 + (int)(uVar12 + 2),

                    (longlong)(int)((uVar11 - uVar12) + -1) << 2);

      lVar6 = *(longlong *)(param_1 + 0x690);

      lVar7 = (**(code **)(lVar6 + 0x80))

                        (*(undefined8 *)(lVar6 + 0x10),*(undefined8 *)(lVar6 + 0x18),param_3,

                         local_a8);

      lVar6 = 0;

      if (lVar7 != 0) {

        return lVar7;

      }

    }

    uVar4 = (**(code **)(*(longlong *)(param_1 + 0x690) + 0xd0))();

    FUN_14021a490("unable to create an EGL window surface","eglCreateWindowSurface",uVar4);

  }

  return lVar6;

}




