// Address: 0x140270120
// Ghidra name: FUN_140270120
// ============ 0x140270120 FUN_140270120 (size=874) ============


undefined8 FUN_140270120(longlong param_1)



{

  undefined2 *puVar1;

  longlong lVar2;

  undefined1 uVar3;

  char cVar4;

  int iVar5;

  longlong *plVar6;

  size_t sVar7;

  undefined8 uVar8;

  longlong lVar9;

  longlong lVar10;

  undefined4 uVar11;

  char local_68;

  undefined2 uStack_67;

  undefined1 auStack_65 [14];

  undefined1 local_57;

  char local_48 [2];

  char local_46;

  byte local_44;

  undefined1 local_43;

  short local_3e;

  short local_3c;

  short local_3a;

  short local_38;

  byte local_30;

  

  uVar11 = 1;

  plVar6 = (longlong *)FUN_1401841a0(1,0xc0);

  if (plVar6 == (longlong *)0x0) {

    return 0;

  }

  *plVar6 = param_1;

  *(undefined4 *)((longlong)plVar6 + 0x6a) = 0x100001;

  *(undefined4 *)((longlong)plVar6 + 0x6e) = 0x20000001;

  *(longlong **)(param_1 + 0x70) = plVar6;

  if ((*(char **)(param_1 + 0x28) == (char *)0x0) ||

     (sVar7 = strlen(*(char **)(param_1 + 0x28)), sVar7 != 0xc)) {

    local_68 = '\0';

  }

  else {

    lVar2 = *(longlong *)(param_1 + 0x28);

    lVar9 = 0;

    lVar10 = -1;

    do {

      puVar1 = (undefined2 *)(lVar2 + lVar9);

      lVar9 = lVar9 + 2;

      *(undefined2 *)((longlong)&uStack_67 + lVar10) = *puVar1;

      auStack_65[lVar10] = 0x2d;

      lVar10 = lVar10 + 3;

    } while (lVar9 < 0xc);

    local_57 = 0;

  }

  if ((*(short *)(param_1 + 0x20) == 0x54c) && (*(short *)(param_1 + 0x22) == 0xba0)) {

    *(undefined1 *)(plVar6 + 2) = 1;

LAB_1402701e3:

    FUN_140271e50(param_1,&local_68,0x12);

  }

  else {

    *(undefined1 *)(plVar6 + 2) = 0;

    if ((*(short *)(param_1 + 0x20) == 0x54c) && (*(short *)(param_1 + 0x22) != 0x5c5)) {

      if (*(char *)(param_1 + 0x54) == '\0') goto LAB_1402701e3;

      iVar5 = FUN_140193800(*(undefined8 *)(param_1 + 0x80),local_48,0x40,0x10);

      if ((iVar5 < 1) || (8 < (byte)(local_48[0] - 0x11U))) goto LAB_1402701fa;

    }

  }

  *(undefined1 *)(plVar6 + 4) = 1;

LAB_1402701fa:

  if (*(short *)(param_1 + 0x20) == 0x54c) {

    *(undefined4 *)((longlong)plVar6 + 0x12) = 0x1010101;

    *(undefined1 *)((longlong)plVar6 + 0x16) = 1;

  }

  else {

    iVar5 = FUN_14026ffd0(*(undefined8 *)(param_1 + 0x80),3,local_48,0x40);

    if ((iVar5 == 0x30) && (local_46 == '\'')) {

      if ((local_44 & 2) != 0) {

        *(undefined1 *)((longlong)plVar6 + 0x13) = 1;

      }

      if ((local_44 & 4) != 0) {

        *(undefined1 *)((longlong)plVar6 + 0x14) = 1;

      }

      if ((local_44 & 8) != 0) {

        *(undefined1 *)((longlong)plVar6 + 0x15) = 1;

      }

      if ((local_44 & 0x40) != 0) {

        *(undefined1 *)((longlong)plVar6 + 0x16) = 1;

      }

      switch(local_43) {

      case 0:

        break;

      case 1:

        uVar11 = 6;

        if ((local_30 & 1) != 0) {

          *(undefined1 *)((longlong)plVar6 + 0x1a) = 1;

        }

        if ((local_30 & 2) != 0) {

          *(undefined1 *)((longlong)plVar6 + 0x19) = 1;

        }

        if ((local_30 & 4) != 0) {

          *(undefined1 *)(plVar6 + 3) = 1;

        }

        break;

      case 2:

        uVar11 = 7;

        break;

      default:

        uVar11 = 0;

        break;

      case 4:

        uVar11 = 5;

        break;

      case 6:

        uVar11 = 2;

        break;

      case 7:

        uVar11 = 3;

        break;

      case 8:

        uVar11 = 4;

      }

      if ((local_3e != 0) && (local_3c != 0)) {

        *(short *)((longlong)plVar6 + 0x6a) = local_3e;

        *(short *)((longlong)plVar6 + 0x6c) = local_3c;

      }

      if ((local_3a != 0) && (local_38 != 0)) {

        *(short *)((longlong)plVar6 + 0x6e) = local_3a;

        *(short *)(plVar6 + 0xe) = local_38;

      }

    }

    else if (*(short *)(param_1 + 0x20) == 0x1532) {

      *(undefined2 *)((longlong)plVar6 + 0x15) = 0x101;

    }

  }

  if ((*(char *)((longlong)plVar6 + 0x14) == '\0') && (*(char *)((longlong)plVar6 + 0x15) == '\0'))

  {

    uVar3 = 0;

  }

  else {

    uVar3 = 1;

  }

  *(undefined1 *)((longlong)plVar6 + 0x17) = uVar3;

  if ((*(short *)(param_1 + 0x20) == 0x3285) && (*(short *)(param_1 + 0x22) == 0xd16)) {

    *(undefined1 *)((longlong)plVar6 + 0x11) = 1;

  }

  if ((*(short *)(param_1 + 0x20) == 0xe6f) &&

     ((*(short *)(param_1 + 0x22) == 0x203 || (*(short *)(param_1 + 0x22) == 0x207)))) {

    *(undefined1 *)((longlong)plVar6 + 0x17) = 0;

  }

  *(undefined4 *)(param_1 + 0x58) = uVar11;

  *(undefined4 *)(param_1 + 0x5c) = 5;

  if (*(char *)((longlong)plVar6 + 0x12) != '\0') {

    FUN_1402083c0(param_1,"PS4 Controller");

  }

  FUN_140208490(param_1,&local_68);

  if (*(char *)(param_1 + 0x54) == '\0') {

    FUN_140207920(*(undefined8 *)(param_1 + 0x28));

  }

  else {

    cVar4 = FUN_140207f20();

    if (cVar4 != '\0') {

      return 1;

    }

  }

  if ((((char)plVar6[2] != '\0') || (*(char *)((longlong)plVar6 + 0x11) != '\0')) &&

     (local_68 == '\0')) {

    return 1;

  }

  uVar8 = FUN_140208110(param_1,0);

  return uVar8;

}




