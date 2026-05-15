// Address: 0x140272200
// Ghidra name: FUN_140272200
// ============ 0x140272200 FUN_140272200 (size=1042) ============


undefined8 FUN_140272200(longlong param_1)



{

  undefined2 *puVar1;

  short sVar2;

  longlong lVar3;

  undefined1 uVar4;

  char cVar5;

  int iVar6;

  longlong *plVar7;

  size_t sVar8;

  undefined8 uVar9;

  longlong lVar10;

  longlong lVar11;

  char *pcVar12;

  undefined4 uVar13;

  undefined1 local_c8;

  undefined2 uStack_c7;

  undefined1 auStack_c5 [14];

  undefined1 local_b7;

  char local_a8;

  undefined1 local_a7;

  char local_a6;

  undefined1 local_a5;

  byte local_a4;

  undefined1 local_a3;

  undefined1 local_a2;

  char local_94;

  byte local_90;

  undefined2 local_7c;

  

  uVar13 = 1;

  plVar7 = (longlong *)FUN_1401841a0(1,200);

  if (plVar7 == (longlong *)0x0) {

    return 0;

  }

  *plVar7 = param_1;

  *(longlong **)(param_1 + 0x70) = plVar7;

  if ((*(char **)(param_1 + 0x28) == (char *)0x0) ||

     (sVar8 = strlen(*(char **)(param_1 + 0x28)), sVar8 != 0xc)) {

    local_c8 = 0;

  }

  else {

    lVar3 = *(longlong *)(param_1 + 0x28);

    lVar10 = 0;

    lVar11 = -1;

    do {

      puVar1 = (undefined2 *)(lVar3 + lVar10);

      lVar10 = lVar10 + 2;

      *(undefined2 *)((longlong)&uStack_c7 + lVar11) = *puVar1;

      auStack_c5[lVar11] = 0x2d;

      lVar11 = lVar11 + 3;

    } while (lVar10 < 0xc);

    local_b7 = 0;

  }

  iVar6 = FUN_140193800(*(undefined8 *)(param_1 + 0x80),&local_a8,0x80,0x10);

  if ((iVar6 == 0x40) || ((0 < iVar6 && (local_a8 == '1')))) {

    *(undefined1 *)(plVar7 + 4) = 1;

  }

  if (*(short *)(param_1 + 0x20) == 0x54c) {

    if ((char)plVar7[4] != '\0') {

      iVar6 = FUN_14026ffd0(*(undefined8 *)(param_1 + 0x80),9,&local_a8,0x80);

      if (6 < iVar6) {

        FUN_14012ef10(&local_c8,0x12,"%.2x-%.2x-%.2x-%.2x-%.2x-%.2x",local_a2,local_a3,local_a4,

                      local_a5,local_a6,local_a7);

      }

      iVar6 = FUN_14026ffd0(*(undefined8 *)(param_1 + 0x80),0x20,&local_a8,0x40);

      if (0x2d < iVar6) {

        *(undefined2 *)(plVar7 + 0xb) = local_7c;

      }

    }

    if ((*(short *)(param_1 + 0x20) == 0x54c) &&

       (((*(short *)(param_1 + 0x22) == 0xdf2 || (*(ushort *)(plVar7 + 0xb) == 0)) ||

        (0x223 < *(ushort *)(plVar7 + 0xb))))) {

      *(undefined1 *)((longlong)plVar7 + 0x6d) = 1;

    }

  }

  if (*(short *)(param_1 + 0x20) == 0x54c) {

    *(undefined4 *)((longlong)plVar7 + 0x12) = 0x1010101;

    *(undefined1 *)((longlong)plVar7 + 0x16) = 1;

  }

  else {

    iVar6 = FUN_14026ffd0(*(undefined8 *)(param_1 + 0x80),3,&local_a8,0x80);

    if ((iVar6 == 0x30) && (local_a6 == '(')) {

      if ((local_a4 & 2) != 0) {

        *(undefined1 *)((longlong)plVar7 + 0x12) = 1;

      }

      if ((local_a4 & 4) != 0) {

        *(undefined1 *)((longlong)plVar7 + 0x13) = 1;

      }

      if ((local_a4 & 8) != 0) {

        *(undefined1 *)((longlong)plVar7 + 0x14) = 1;

      }

      if ((local_a4 & 0x40) != 0) {

        *(undefined1 *)((longlong)plVar7 + 0x16) = 1;

      }

      if (local_94 < '\0') {

        *(undefined1 *)((longlong)plVar7 + 0x15) = 1;

      }

      switch(local_a3) {

      case 0:

        break;

      case 1:

        uVar13 = 6;

        if ((local_90 & 1) != 0) {

          *(undefined1 *)((longlong)plVar7 + 0x1a) = 1;

        }

        if ((local_90 & 2) != 0) {

          *(undefined1 *)((longlong)plVar7 + 0x19) = 1;

        }

        if ((local_90 & 4) != 0) {

          *(undefined1 *)(plVar7 + 3) = 1;

        }

        break;

      case 2:

        uVar13 = 7;

        break;

      default:

        uVar13 = 0;

        break;

      case 6:

        uVar13 = 2;

        break;

      case 7:

        uVar13 = 3;

        break;

      case 8:

        uVar13 = 4;

      }

      *(undefined1 *)((longlong)plVar7 + 0x11) = 1;

      *(undefined1 *)((longlong)plVar7 + 0x25) = 1;

      if ((*(short *)(param_1 + 0x20) == 0x3285) &&

         ((*(short *)(param_1 + 0x22) == 0xd19 || (*(short *)(param_1 + 0x22) == 0xd18)))) {

        *(undefined1 *)((longlong)plVar7 + 0x14) = 1;

      }

    }

    else if (*(short *)(param_1 + 0x20) == 0x1532) {

      sVar2 = *(short *)(param_1 + 0x22);

      if ((sVar2 == 0x100b) || (sVar2 == 0x100c)) {

        *(undefined2 *)((longlong)plVar7 + 0x11) = 0x101;

        *(undefined1 *)((longlong)plVar7 + 0x16) = 1;

      }

      else if ((sVar2 == 0x1012) || ((sVar2 + 0xefdcU & 0xfffd) == 0)) {

        uVar13 = 3;

        *(undefined1 *)((longlong)plVar7 + 0x16) = 1;

        *(undefined1 *)((longlong)plVar7 + 0x11) = 1;

      }

    }

  }

  if (((*(char *)((longlong)plVar7 + 0x13) == '\0') && (*(char *)((longlong)plVar7 + 0x14) == '\0'))

     && (*(char *)((longlong)plVar7 + 0x15) == '\0')) {

    uVar4 = 0;

  }

  else {

    uVar4 = 1;

  }

  *(undefined1 *)((longlong)plVar7 + 0x17) = uVar4;

  if (*(short *)(param_1 + 0x20) == 0x3285) {

    if (*(short *)(param_1 + 0x22) != 0xd18) goto LAB_140272575;

  }

  else if ((*(short *)(param_1 + 0x20) != 0x1532) ||

          (((sVar2 = *(short *)(param_1 + 0x22), sVar2 != 0xd18 && (sVar2 != 0x100c)) &&

           (sVar2 != 0x1026)))) goto LAB_140272575;

  *(undefined1 *)(plVar7 + 2) = 1;

LAB_140272575:

  *(undefined4 *)(param_1 + 0x58) = uVar13;

  *(undefined4 *)(param_1 + 0x5c) = 6;

  if (*(short *)(param_1 + 0x20) == 0x54c) {

    cVar5 = FUN_140159400(0x54c,*(undefined2 *)(param_1 + 0x22));

    pcVar12 = "DualSense Edge Wireless Controller";

    if (cVar5 == '\0') {

      pcVar12 = "DualSense Wireless Controller";

    }

    FUN_1402083c0(param_1,pcVar12);

  }

  FUN_140208490(param_1,&local_c8);

  if ((char)plVar7[2] != '\0') {

    return 1;

  }

  if (*(char *)(param_1 + 0x54) == '\0') {

    FUN_140207920(*(undefined8 *)(param_1 + 0x28));

  }

  else {

    cVar5 = FUN_140207f20();

    if (cVar5 != '\0') {

      return 1;

    }

  }

  uVar9 = FUN_140208110(param_1,0);

  return uVar9;

}




