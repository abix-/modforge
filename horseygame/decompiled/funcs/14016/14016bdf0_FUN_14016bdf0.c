// Address: 0x14016bdf0
// Ghidra name: FUN_14016bdf0
// ============ 0x14016bdf0 FUN_14016bdf0 (size=438) ============


longlong FUN_14016bdf0(longlong param_1)



{

  char cVar1;

  char cVar2;

  int iVar3;

  char *pcVar4;

  longlong lVar5;

  code *pcVar6;

  code *pcVar7;

  longlong lVar8;

  uint uVar9;

  

  if (DAT_1403fc410 == 0) {

    FUN_1401730c0();

    return 0;

  }

  if ((param_1 == 0) ||

     ((DAT_1403e3d60 != '\0' && (cVar1 = FUN_1401aa7c0(param_1,1), cVar1 == '\0')))) {

    FUN_14012e850("Invalid window");

    return 0;

  }

  if ((*(byte *)(param_1 + 0x48) & 2) == 0) {

    FUN_14012e850("The specified window isn\'t an OpenGL window");

    return 0;

  }

  uVar9 = 0xffffffff;

  pcVar4 = (char *)FUN_140142960("SDL_OPENGL_FORCE_SRGB_FRAMEBUFFER");

  if ((pcVar4 != (char *)0x0) && (*pcVar4 != '\0')) {

    cVar1 = FUN_1401429e0(pcVar4,0);

    uVar9 = (uint)(cVar1 != '\0');

  }

  lVar5 = (**(code **)(DAT_1403fc410 + 0x1b8))(DAT_1403fc410,param_1);

  lVar8 = DAT_1403fc410;

  if (lVar5 != 0) {

    *(longlong *)(DAT_1403fc410 + 0x540) = param_1;

    *(longlong *)(lVar8 + 0x548) = lVar5;

    FUN_140163ac0(lVar8 + 0x550,param_1,0);

    FUN_140163ac0(DAT_1403fc410 + 0x554,lVar5,0);

  }

  if (uVar9 == 0xffffffff) {

    return lVar5;

  }

  pcVar4 = "glDisable";

  if (uVar9 != 0) {

    pcVar4 = "glEnable";

  }

  pcVar6 = (code *)FUN_14016c730(pcVar4);

  pcVar7 = (code *)FUN_14016c730("glGetString");

  if (pcVar6 == (code *)0x0) {

    return lVar5;

  }

  if (pcVar7 == (code *)0x0) {

    return lVar5;

  }

  if ((*(byte *)(DAT_1403fc410 + 0x3f0) & 4) == 0) {

    lVar8 = (*pcVar7)(0x1f02);

    if (((lVar8 == 0) || (iVar3 = thunk_FUN_1402d89dc(lVar8), iVar3 < 3)) &&

       (cVar1 = FUN_14016c0c0("GL_EXT_framebuffer_sRGB"), cVar1 == '\0')) {

      cVar2 = FUN_14016c0c0("GL_ARB_framebuffer_sRGB");

      cVar1 = '\0';

      if (cVar2 == '\0') goto LAB_14016bf74;

    }

    cVar1 = '\x01';

  }

  else {

    cVar1 = FUN_14016c0c0("GL_EXT_sRGB_write_control");

  }

LAB_14016bf74:

  if (cVar1 != '\0') {

    (*pcVar6)(0x8db9);

  }

  return lVar5;

}




