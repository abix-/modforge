// Address: 0x1401cda90
// Ghidra name: FUN_1401cda90
// ============ 0x1401cda90 FUN_1401cda90 (size=1155) ============


ulonglong FUN_1401cda90(undefined4 *param_1,int param_2,int param_3,int param_4)



{

  longlong lVar1;

  bool bVar2;

  char cVar3;

  byte bVar4;

  ulonglong in_RAX;

  longlong lVar5;

  longlong lVar6;

  uint uVar7;

  int local_a8 [2];

  undefined8 local_a0;

  undefined4 local_98;

  int local_94;

  int local_90;

  

  bVar2 = true;

  if (param_1 == (undefined4 *)0x0) goto LAB_1401cdbbe;

  uVar7 = param_2 - 0x202;

  if (0x16 < uVar7) goto switchD_1401cdae8_caseD_6;

  in_RAX = (ulonglong)(int)uVar7;

  switch(uVar7) {

  case 0:

    in_RAX = *(ulonglong *)(param_1 + 0x12);

    if ((in_RAX & 8) == 0) goto LAB_1401cdbbe;

    in_RAX = in_RAX & 0xffffffffffffffb7;

    break;

  case 1:

    in_RAX = *(ulonglong *)(param_1 + 0x12);

    if ((in_RAX & 8) != 0) goto LAB_1401cdbbe;

    in_RAX = in_RAX | 8;

    break;

  case 2:

    *(ulonglong *)(param_1 + 0x12) = *(ulonglong *)(param_1 + 0x12) & 0xfffffffffffffffb;

    goto switchD_1401cdae8_caseD_6;

  case 3:

    *(undefined2 *)((longlong)param_1 + 0x9d) = 0;

    if ((*(char *)((longlong)param_1 + 0x10b) == '\0') && ((*(byte *)(param_1 + 0x14) & 1) == 0)) {

      param_1[0x1a] = 0;

    }

    in_RAX = *(ulonglong *)(param_1 + 0x12);

    *(undefined1 *)((longlong)param_1 + 0x10b) = 0;

    if ((in_RAX & 1) == 0) {

      param_1[0x1b] = param_3;

      param_1[0x1c] = param_4;

      if ((-1 < (char)in_RAX) && (*(char *)(param_1 + 0x27) == '\0')) {

        param_1[0x1f] = param_3;

        param_1[0x20] = param_4;

      }

    }

    if ((param_3 == param_1[6]) && (param_4 == param_1[7])) goto LAB_1401cdbbe;

    param_1[6] = param_3;

    param_1[7] = param_4;

    goto switchD_1401cdae8_caseD_6;

  case 4:

    in_RAX = *(ulonglong *)(param_1 + 0x12);

    *(undefined1 *)(param_1 + 0x43) = 0;

    if ((in_RAX & 1) == 0) {

      param_1[0x1d] = param_3;

      param_1[0x1e] = param_4;

      if ((-1 < (char)in_RAX) && (*(char *)(param_1 + 0x27) == '\0')) {

        param_1[0x21] = param_3;

        param_1[0x22] = param_4;

      }

    }

    if ((param_3 == param_1[8]) && (param_4 == param_1[9])) {

      in_RAX = FUN_14016a520(param_1);

      goto LAB_1401cdbbe;

    }

    param_1[8] = param_3;

    param_1[9] = param_4;

    goto switchD_1401cdae8_caseD_6;

  case 5:

    if ((param_3 == param_1[0x10]) && (param_4 == param_1[0x11])) goto LAB_1401cdbbe;

    param_1[0x10] = param_3;

    param_1[0x11] = param_4;

  default:

    goto switchD_1401cdae8_caseD_6;

  case 7:

    in_RAX = *(ulonglong *)(param_1 + 0x12);

    if ((in_RAX & 0x40) != 0) goto LAB_1401cdbbe;

    in_RAX = in_RAX & 0xffffffffffffff7f | 0x40;

    break;

  case 8:

    in_RAX = *(ulonglong *)(param_1 + 0x12);

    if ((char)in_RAX < '\0') goto LAB_1401cdbbe;

    in_RAX = in_RAX & 0xffffffffffffffbf | 0x80;

    break;

  case 9:

    in_RAX = *(ulonglong *)(param_1 + 0x12);

    if ((in_RAX & 0xc0) == 0) goto LAB_1401cdbbe;

    in_RAX = in_RAX & 0xffffffffffffff3f;

    break;

  case 10:

    in_RAX = *(ulonglong *)(param_1 + 0x12);

    if ((in_RAX >> 10 & 1) != 0) goto LAB_1401cdbbe;

    in_RAX = in_RAX | 0x400;

    break;

  case 0xb:

    in_RAX = *(ulonglong *)(param_1 + 0x12);

    if ((in_RAX >> 10 & 1) == 0) goto LAB_1401cdbbe;

    in_RAX = in_RAX & 0xfffffffffffffbff;

    break;

  case 0xc:

    in_RAX = *(ulonglong *)(param_1 + 0x12);

    if ((in_RAX >> 9 & 1) != 0) goto LAB_1401cdbbe;

    in_RAX = in_RAX | 0x200;

    break;

  case 0xd:

    in_RAX = *(ulonglong *)(param_1 + 0x12);

    if ((in_RAX >> 9 & 1) == 0) goto LAB_1401cdbbe;

    in_RAX = in_RAX & 0xfffffffffffffdff;

    break;

  case 0x11:

    if ((param_3 == 0) || (param_3 == param_1[0x19])) goto LAB_1401cdbbe;

    *(undefined1 *)((longlong)param_1 + 0x10d) = 1;

    param_1[0x19] = param_3;

    goto switchD_1401cdae8_caseD_6;

  case 0x14:

    in_RAX = *(ulonglong *)(param_1 + 0x12);

    if ((in_RAX & 4) != 0) goto LAB_1401cdbbe;

    in_RAX = in_RAX | 4;

    break;

  case 0x15:

    in_RAX = *(ulonglong *)(param_1 + 0x12);

    if ((in_RAX & 1) != 0) goto LAB_1401cdbbe;

    in_RAX = in_RAX | 1;

    break;

  case 0x16:

    in_RAX = *(ulonglong *)(param_1 + 0x12);

    if ((in_RAX & 1) == 0) goto LAB_1401cdbbe;

    in_RAX = in_RAX & 0xfffffffffffffffe;

  }

  *(ulonglong *)(param_1 + 0x12) = in_RAX;

switchD_1401cdae8_caseD_6:

  if ((*(char *)((longlong)param_1 + 0x10f) != '\0') && (param_2 != 0x219)) {

LAB_1401cdbbe:

    return in_RAX & 0xffffffffffffff00;

  }

  lVar5 = FUN_14016dcf0();

  if ((lVar5 == 0) || (*(char *)(lVar5 + 0x39d) != '\0')) {

    bVar2 = false;

  }

  local_98 = *param_1;

  lVar1 = *(longlong *)(param_1 + 0x6a);

  local_a0 = 0;

  local_a8[0] = param_2;

  local_94 = param_3;

  local_90 = param_4;

  FUN_1401ce190(&DAT_1403fce30,local_a8);

  FUN_1401ce190(&DAT_1403fce60,local_a8);

  if ((bVar2) && (cVar3 = FUN_140139420(param_2), cVar3 != '\0')) {

    if ((param_2 - 0x204U < 4) || (param_2 - 0x215U < 2)) {

      FUN_1401394c0(&LAB_1401cd990,local_a8);

    }

    bVar4 = FUN_14013b140(local_a8);

  }

  else {

    bVar4 = 0;

  }

  lVar6 = FUN_14016e190(local_98);

  if (lVar6 == 0) {

switchD_1401cddf4_caseD_2:

    if (((param_2 == 0x210) && (lVar1 == 0)) && (cVar3 = FUN_14021efa0(), cVar3 == '\0')) {

      uVar7 = (uint)(lVar6 == 0);

      for (lVar5 = *(longlong *)(lVar5 + 0x348); lVar5 != 0; lVar5 = *(longlong *)(lVar5 + 0x1a0)) {

        if ((*(longlong *)(lVar5 + 0x1a8) == 0) && ((*(byte *)(lVar5 + 0x48) & 8) == 0)) {

          uVar7 = uVar7 + 1;

        }

      }

      if (((int)uVar7 < 2) &&

         (cVar3 = FUN_140142940("SDL_QUIT_ON_LAST_WINDOW_CLOSE",1), cVar3 != '\0')) {

        FUN_1401ce0e0();

      }

    }

  }

  else {

    switch(uVar7) {

    case 0:

      FUN_14016fa60(lVar6);

      break;

    case 1:

      FUN_14016f910(lVar6);

      break;

    default:

      goto switchD_1401cddf4_caseD_2;

    case 3:

      thunk_FUN_14016a310(lVar6);

      break;

    case 4:

      FUN_14016f9c0(lVar6);

      break;

    case 5:

      FUN_14016f9b0(lVar6);

      break;

    case 7:

      FUN_14016f980(lVar6);

      break;

    case 8:

      _guard_check_icall(lVar6);

      break;

    case 9:

      FUN_14016fa40(lVar6);

      break;

    case 10:

      FUN_14016f880(lVar6);

      break;

    case 0xb:

      _guard_check_icall(lVar6);

      break;

    case 0xc:

      FUN_14016f8a0(lVar6);

      break;

    case 0xd:

      FUN_14016f8e0(lVar6);

      break;

    case 0x11:

      FUN_14016f760(lVar6);

    }

  }

  return (ulonglong)bVar4;

}




