// Address: 0x14016c230
// Ghidra name: FUN_14016c230
// ============ 0x14016c230 FUN_14016c230 (size=1062) ============


undefined8 FUN_14016c230(int param_1,uint *param_2)



{

  char cVar1;

  int iVar2;

  int iVar3;

  undefined8 uVar4;

  code *pcVar5;

  longlong lVar6;

  code *pcVar7;

  char *pcVar8;

  int iVar9;

  int local_res10 [2];

  int local_res18 [2];

  int local_res20 [2];

  int local_48 [4];

  

  iVar9 = 0x402;

  iVar3 = 0;

  if (param_2 == (uint *)0x0) {

    uVar4 = FUN_14012e850("Parameter \'%s\' is invalid","value");

    return uVar4;

  }

  *param_2 = 0;

  if (DAT_1403fc410 == 0) {

    uVar4 = FUN_1401730c0();

    return uVar4;

  }

  switch(param_1) {

  case 0:

    iVar3 = 0x8212;

    uVar4 = 0xd52;

    break;

  case 1:

    iVar3 = 0x8213;

    uVar4 = 0xd53;

    break;

  case 2:

    iVar3 = 0x8214;

    uVar4 = 0xd54;

    break;

  case 3:

    iVar3 = 0x8215;

    uVar4 = 0xd55;

    break;

  case 4:

    local_48[0] = 0;

    local_res20[0] = 0;

    local_res18[0] = 0;

    local_res10[0] = 0;

    cVar1 = FUN_14016c230(0,local_48);

    if (cVar1 == '\0') {

      return 0;

    }

    cVar1 = FUN_14016c230(1,local_res20);

    if (cVar1 == '\0') {

      return 0;

    }

    cVar1 = FUN_14016c230(2,local_res18);

    if (cVar1 == '\0') {

      return 0;

    }

    cVar1 = FUN_14016c230(3,local_res10);

    if (cVar1 == '\0') {

      return 0;

    }

    *param_2 = local_res10[0] + local_res18[0] + local_res20[0] + local_48[0];

    return 1;

  case 5:

    uVar4 = 0xc32;

    break;

  case 6:

    iVar3 = 0x8216;

    uVar4 = 0xd56;

    iVar9 = 0x1801;

    break;

  case 7:

    iVar3 = 0x8217;

    uVar4 = 0xd57;

    iVar9 = 0x1802;

    break;

  case 8:

    uVar4 = 0xd58;

    break;

  case 9:

    uVar4 = 0xd59;

    break;

  case 10:

    uVar4 = 0xd5a;

    break;

  case 0xb:

    uVar4 = 0xd5b;

    break;

  case 0xc:

    uVar4 = 0xc33;

    break;

  case 0xd:

    uVar4 = 0x80a8;

    break;

  case 0xe:

    uVar4 = 0x80a9;

    break;

  case 0xf:

    *param_2 = (uint)(*(int *)(DAT_1403fc410 + 0x3e0) != 0);

    return 1;

  case 0x10:

    *param_2 = *(uint *)(DAT_1403fc410 + 0x408);

    return 1;

  case 0x11:

    *param_2 = *(uint *)(DAT_1403fc410 + 0x3e4);

    return 1;

  case 0x12:

    *param_2 = *(uint *)(DAT_1403fc410 + 1000);

    return 1;

  case 0x13:

    *param_2 = *(uint *)(DAT_1403fc410 + 0x3ec);

    return 1;

  case 0x14:

    *param_2 = *(uint *)(DAT_1403fc410 + 0x3f0);

    return 1;

  case 0x15:

    *param_2 = *(uint *)(DAT_1403fc410 + 0x3f4);

    return 1;

  case 0x16:

    *param_2 = *(uint *)(DAT_1403fc410 + 0x400);

    return 1;

  case 0x17:

    uVar4 = 0x82fb;

    break;

  default:

    pcVar8 = "Unknown OpenGL attribute";

    goto LAB_14016c63b;

  case 0x19:

    *param_2 = *(uint *)(DAT_1403fc410 + 0x404);

    return 1;

  case 0x1a:

    if (*(int *)(DAT_1403fc410 + 0x414) == 0) {

      return 0;

    }

    uVar4 = 0x8820;

    break;

  case 0x1b:

    *param_2 = *(uint *)(DAT_1403fc410 + 0x40c);

    return 1;

  }

  pcVar5 = (code *)FUN_14016c730("glGetString");

  if (pcVar5 != (code *)0x0) {

    if (((iVar3 == 0) || (lVar6 = (*pcVar5)(0x1f02), lVar6 == 0)) ||

       (iVar2 = thunk_FUN_1402d89dc(lVar6), iVar2 < 3)) {

      pcVar5 = (code *)FUN_14016c730("glGetIntegerv");

      if (pcVar5 == (code *)0x0) {

        return 0;

      }

      (*pcVar5)(uVar4,param_2);

    }

    else {

      local_res10[0] = 0;

      pcVar5 = (code *)FUN_14016c730("glGetIntegerv");

      pcVar7 = (code *)FUN_14016c730("glBindFramebuffer");

      if ((pcVar5 != (code *)0x0) && (pcVar7 != (code *)0x0)) {

        (*pcVar5)(0x8ca6,local_res10);

      }

      pcVar5 = (code *)FUN_14016c730("glGetFramebufferAttachmentParameteriv");

      if (pcVar5 == (code *)0x0) {

        return 0;

      }

      if ((pcVar7 != (code *)0x0) && (local_res10[0] != 0)) {

        (*pcVar7)(0x8ca9,0);

      }

      local_res18[0] = 0x8218;

      if ((iVar9 - 0x1801U < 2) && ((*pcVar5)(0x8d40,iVar9,0x8cd0,local_res18), local_res18[0] == 0)

         ) {

        *param_2 = 0;

      }

      else {

        (*pcVar5)(0x8d40,iVar9,iVar3,param_2);

      }

      if ((pcVar7 != (code *)0x0) && (local_res10[0] != 0)) {

        (*pcVar7)(0x8ca9);

      }

    }

    pcVar5 = (code *)FUN_14016c730("glGetError");

    if (pcVar5 != (code *)0x0) {

      iVar3 = (*pcVar5)();

      if (iVar3 == 0) {

        if (param_1 == 0x17) {

          *param_2 = (uint)(*param_2 == 0x82fc);

        }

        return 1;

      }

      if (iVar3 == 0x500) {

        pcVar8 = "OpenGL error: GL_INVALID_ENUM";

      }

      else {

        if (iVar3 != 0x501) {

          uVar4 = FUN_14012e850("OpenGL error: %08X",iVar3);

          return uVar4;

        }

        pcVar8 = "OpenGL error: GL_INVALID_VALUE";

      }

LAB_14016c63b:

      uVar4 = FUN_14012e850(pcVar8);

      return uVar4;

    }

  }

  return 0;

}




