// Address: 0x140092820
// Ghidra name: FUN_140092820
// ============ 0x140092820 FUN_140092820 (size=5156) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined8 FUN_140092820(longlong param_1)



{

  longlong lVar1;

  longlong *plVar2;

  longlong lVar3;

  char *_Str;

  bool bVar4;

  ulonglong *puVar5;

  char cVar6;

  int iVar7;

  undefined4 uVar8;

  int iVar9;

  ulonglong **ppuVar10;

  ulonglong uVar11;

  size_t sVar12;

  ulonglong *puVar13;

  longlong *plVar14;

  int *piVar15;

  int *piVar16;

  ulonglong uVar17;

  ulonglong *puVar18;

  undefined8 uVar19;

  ulonglong uVar20;

  int *piVar21;

  ulonglong *puVar22;

  undefined8 *puVar23;

  int *piVar24;

  longlong lVar25;

  longlong lVar26;

  uint uVar27;

  ulonglong uVar28;

  ulonglong local_res8;

  longlong local_res10;

  longlong local_res18;

  ulonglong in_stack_ffffffffffffff08;

  ulonglong *local_e8;

  ulonglong *puStack_e0;

  ulonglong *local_d8;

  ulonglong *local_d0;

  ulonglong *puStack_c8;

  longlong local_c0;

  ulonglong uStack_b8;

  int *local_b0;

  int *piStack_a8;

  int *local_a0;

  char *local_98 [4];

  char *local_78;

  char *local_70;

  char *local_68;

  char *local_60;

  char *local_58;

  

  uVar11 = 0;

  uVar28 = 0;

  local_res8 = local_res8 & 0xffffffff00000000;

  local_e8 = (ulonglong *)0x0;

  puStack_e0 = (ulonglong *)0x0;

  local_d8 = (ulonglong *)0x0;

  local_res10 = 0;

  *(int *)(param_1 + 0x2a8) = *(int *)(param_1 + 0x2a8) + 1;

  cVar6 = '\0';

  *(undefined4 *)(param_1 + 0x29c) = 0;

  *(undefined1 *)(param_1 + 0x2a4) = 0;

  if (1 < (int)DAT_1403eded8) {

    FUN_140105730(DAT_1403fb0d8);

  }

  lVar26 = *(longlong *)(param_1 + 0x278);

  uVar20 = uVar11;

  if (lVar26 == 0) {

LAB_1400929b5:

    uVar27 = DAT_1403eded8 & 0x80000001;

    if ((int)uVar27 < 0) {

      uVar27 = (uVar27 - 1 | 0xfffffffe) + 1;

    }

    if (((uVar27 != 0) ||

        (cVar6 = FUN_140092620(param_1,0), puVar5 = _UNK_14030c2d8, puVar18 = _DAT_14030c2d0,

        cVar6 == '\0')) &&

       (puVar5 = _UNK_14030c2d8, puVar18 = _DAT_14030c2d0, 4 < (int)DAT_1403eded8)) {

      uVar27 = DAT_1403eded8 & 0x80000003;

      if ((int)uVar27 < 0) {

        uVar27 = (uVar27 - 1 | 0xfffffffc) + 1;

      }

      if ((uVar27 == 3) &&

         (iVar7 = FUN_1400c6580(5), puVar5 = _UNK_14030c2d8, puVar18 = _DAT_14030c2d0, iVar7 == 0))

      {

        in_stack_ffffffffffffff08 = CONCAT44((int)(in_stack_ffffffffffffff08 >> 0x20),1000);

        ppuVar10 = (ulonglong **)

                   FUN_140105da0(DAT_1403fb0d8,&local_d0,4,*(undefined8 *)(param_1 + 0xc),

                                 in_stack_ffffffffffffff08,0);

        if (&local_e8 != ppuVar10) {

          if (local_e8 != (ulonglong *)0x0) {

            if ((0xfff < ((longlong)local_d8 - (longlong)local_e8 & 0xfffffffffffffff8U)) &&

               (0x1f < (longlong)local_e8 + (-8 - local_e8[-1]))) {

                    /* WARNING: Subroutine does not return */

              _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

            }

            FUN_1402c7088();

          }

          local_e8 = *ppuVar10;

          puStack_e0 = ppuVar10[1];

          local_d8 = ppuVar10[2];

          *ppuVar10 = (ulonglong *)0x0;

          ppuVar10[1] = (ulonglong *)0x0;

          ppuVar10[2] = (ulonglong *)0x0;

        }

        FUN_140030810(&local_d0);

        puVar5 = _UNK_14030c2d8;

        puVar18 = _DAT_14030c2d0;

        if (3 < (ulonglong)((longlong)puStack_e0 - (longlong)local_e8 >> 3)) {

          cVar6 = '\x01';

          *(undefined4 *)(param_1 + 0x2a0) = 9;

          *(undefined1 *)(param_1 + 0x2a4) = 1;

          puVar5 = _UNK_14030c2d8;

          puVar18 = _DAT_14030c2d0;

        }

      }

    }

  }

  else {

    lVar3 = *(longlong *)(lVar26 + 0x298);

    uVar17 = (ulonglong)*(int *)(param_1 + 0x2a8);

    if ((ulonglong)(*(longlong *)(lVar26 + 0x2a0) - lVar3 >> 4) <= uVar17) goto LAB_1400929b5;

    lVar26 = *(longlong *)(lVar3 + uVar17 * 0x10);

    local_res10 = lVar26;

    if (*(char *)(lVar3 + 9 + uVar17 * 0x10) == '\0') {

      cVar6 = FUN_140092710(param_1,7);

      if ((((cVar6 == '\0') && (cVar6 = FUN_140092710(param_1,8), cVar6 == '\0')) &&

          (cVar6 = FUN_140092710(param_1,4), cVar6 == '\0')) &&

         ((lVar26 = FUN_1400c7520(*(undefined4 *)(lVar26 + 0x1f8)), *(int *)(lVar26 + 0x54) != 0 ||

          (cVar6 = FUN_140092710(param_1,1), cVar6 == '\0')))) {

        cVar6 = FUN_140092710(param_1,0);

      }

    }

    else {

      cVar6 = FUN_140092620(param_1,1);

    }

    if (cVar6 == '\0') {

      *(int *)(param_1 + 0x2a8) = *(int *)(param_1 + 0x2a8) + -1;

      goto LAB_1400929b5;

    }

    *(undefined1 *)(param_1 + 0x2a5) = 1;

    *(undefined1 *)

     (*(longlong *)(*(longlong *)(param_1 + 0x278) + 0x298) + 8 +

     (longlong)*(int *)(param_1 + 0x2a8) * 0x10) = 1;

    puVar5 = _UNK_14030c2d8;

    puVar18 = _DAT_14030c2d0;

  }

  do {

    if ((cVar6 == '\0') && (7 < (int)DAT_1403eded8)) {

      local_d0 = puVar18;

      puStack_c8 = puVar5;

      local_c0 = CONCAT44(local_c0._4_4_,8);

      iVar7 = -1;

      if (DAT_1403da0b8 == -1) {

        do {

          iVar7 = FUN_1400c6580(5);

        } while (iVar7 == DAT_1403da0b8);

      }

      uVar8 = *(undefined4 *)((longlong)&local_d0 + (longlong)iVar7 * 4);

      in_stack_ffffffffffffff08 = in_stack_ffffffffffffff08 & 0xffffffffffffff00;

      ppuVar10 = (ulonglong **)

                 FUN_140105b00(DAT_1403fb0d8,&local_d0,uVar8,4,in_stack_ffffffffffffff08);

      if (&local_e8 != ppuVar10) {

        if (local_e8 != (ulonglong *)0x0) {

          if ((0xfff < ((longlong)local_d8 - (longlong)local_e8 & 0xfffffffffffffff8U)) &&

             (0x1f < (longlong)local_e8 + (-8 - local_e8[-1]))) goto LAB_140093b95;

          FUN_1402c7088();

        }

        local_e8 = *ppuVar10;

        puStack_e0 = ppuVar10[1];

        local_d8 = ppuVar10[2];

        *ppuVar10 = (ulonglong *)0x0;

        ppuVar10[1] = (ulonglong *)0x0;

        ppuVar10[2] = (ulonglong *)0x0;

      }

      if (local_d0 != (ulonglong *)0x0) {

        if ((0xfff < (local_c0 - (longlong)local_d0 & 0xfffffffffffffff8U)) &&

           (0x1f < (longlong)local_d0 + (-8 - local_d0[-1]))) {

LAB_140093b95:

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

        FUN_1402c7088();

      }

      if ((ulonglong)((longlong)puStack_e0 - (longlong)local_e8 >> 3) < 4) {

        if (local_e8 != puStack_e0) {

          puStack_e0 = local_e8;

        }

        cVar6 = '\0';

      }

      else {

        *(undefined4 *)(param_1 + 0x2a0) = uVar8;

        cVar6 = '\x01';

      }

    }

    uVar27 = (int)uVar20 + 1;

    uVar20 = (ulonglong)uVar27;

  } while ((int)uVar27 < 2);

  if (cVar6 == '\0') {

    in_stack_ffffffffffffff08 = in_stack_ffffffffffffff08 & 0xffffffffffffff00;

    ppuVar10 = (ulonglong **)FUN_140105b00(DAT_1403fb0d8,&local_d0,0,4,in_stack_ffffffffffffff08);

    if (&local_e8 != ppuVar10) {

      if (local_e8 != (ulonglong *)0x0) {

        if ((0xfff < ((longlong)local_d8 - (longlong)local_e8 & 0xfffffffffffffff8U)) &&

           (0x1f < (longlong)local_e8 + (-8 - local_e8[-1]))) goto LAB_140093b80;

        FUN_1402c7088();

      }

      local_e8 = *ppuVar10;

      puStack_e0 = ppuVar10[1];

      local_d8 = ppuVar10[2];

      *ppuVar10 = (ulonglong *)0x0;

      ppuVar10[1] = (ulonglong *)0x0;

      ppuVar10[2] = (ulonglong *)0x0;

    }

    if (local_d0 != (ulonglong *)0x0) {

      if ((0xfff < (local_c0 - (longlong)local_d0 & 0xfffffffffffffff8U)) &&

         (0x1f < (longlong)local_d0 + (-8 - local_d0[-1]))) {

LAB_140093b80:

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

      FUN_1402c7088();

    }

    if ((ulonglong)((longlong)puStack_e0 - (longlong)local_e8 >> 3) < 4) {

      if (local_e8 != puStack_e0) {

        puStack_e0 = local_e8;

      }

      FUN_140105730(DAT_1403fb0d8);

      in_stack_ffffffffffffff08 = in_stack_ffffffffffffff08 & 0xffffffffffffff00;

      ppuVar10 = (ulonglong **)FUN_140105b00(DAT_1403fb0d8,&local_d0,0,4,in_stack_ffffffffffffff08);

      if (&local_e8 != ppuVar10) {

        if (local_e8 != (ulonglong *)0x0) {

          if ((0xfff < ((longlong)local_d8 - (longlong)local_e8 & 0xfffffffffffffff8U)) &&

             (0x1f < (longlong)local_e8 + (-8 - local_e8[-1]))) goto LAB_140093baa;

          FUN_1402c7088();

        }

        local_e8 = *ppuVar10;

        puStack_e0 = ppuVar10[1];

        local_d8 = ppuVar10[2];

        *ppuVar10 = (ulonglong *)0x0;

        ppuVar10[1] = (ulonglong *)0x0;

        ppuVar10[2] = (ulonglong *)0x0;

      }

      if (local_d0 != (ulonglong *)0x0) {

        if ((0xfff < (local_c0 - (longlong)local_d0 & 0xfffffffffffffff8U)) &&

           (0x1f < (longlong)local_d0 + (-8 - local_d0[-1]))) {

LAB_140093baa:

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

        FUN_1402c7088();

      }

      if ((ulonglong)((longlong)puStack_e0 - (longlong)local_e8 >> 3) < 4) {

        if (local_e8 != puStack_e0) {

          puStack_e0 = local_e8;

        }

        cVar6 = '\0';

      }

      else {

        *(undefined4 *)(param_1 + 0x2a0) = 0;

        cVar6 = '\x01';

      }

    }

    else {

      *(undefined4 *)(param_1 + 0x2a0) = 0;

      cVar6 = '\x01';

    }

  }

  uVar8 = (undefined4)(in_stack_ffffffffffffff08 >> 0x20);

  if ((*(char *)(param_1 + 0x259) != '\0') && (4 < (int)DAT_1403eded8)) {

    local_98[0] = "crazy horse";

    local_98[1] = "giraffe";

    local_98[2] = "human";

    local_98[3] = "impala";

    local_78 = "alligator";

    local_70 = "fest horse";

    local_68 = "freak";

    local_60 = "dachshund";

    local_58 = "moose";

    local_res18 = FUN_1402c704c(0x498);

    if (local_res18 != 0) {

      uVar11 = FUN_1400aac60(local_res18);

    }

    iVar7 = FUN_1400c6580(9);

    _Str = local_98[iVar7];

    local_d0 = (ulonglong *)0x0;

    puStack_c8 = (ulonglong *)0x0;

    local_c0 = 0;

    uStack_b8 = 0;

    sVar12 = strlen(_Str);

    FUN_140027e30(&local_d0,_Str,sVar12);

    FUN_1400c6580(5);

    FUN_1400b2ee0(uVar11,&local_d0);

    if (0xf < uStack_b8) {

      if ((0xfff < uStack_b8 + 1) && (0x1f < (longlong)local_d0 + (-8 - local_d0[-1]))) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

      FUN_1402c7088();

    }

    iVar7 = FUN_1400c6580(8);

    uVar8 = FUN_1400c7600(1,iVar7 + 8,iVar7 + 8,0xffffffff,CONCAT44(uVar8,0xffffffff));

    puVar5 = puStack_e0;

    *(undefined4 *)(uVar11 + 0x1f8) = uVar8;

    *(undefined4 *)(uVar11 + 0x218) = 999;

    if (puStack_e0 == local_d8) {

      lVar26 = (longlong)puStack_e0 - (longlong)local_e8 >> 3;

      if (lVar26 == 0x1fffffffffffffff) {

                    /* WARNING: Subroutine does not return */

        FUN_14002f0d0();

      }

      uVar28 = lVar26 + 1;

      uVar20 = (longlong)local_d8 - (longlong)local_e8 >> 3;

      if (0x1fffffffffffffff - (uVar20 >> 1) < uVar20) {

        uVar17 = 0x1fffffffffffffff;

      }

      else {

        uVar20 = (uVar20 >> 1) + uVar20;

        uVar17 = uVar28;

        if (uVar28 <= uVar20) {

          uVar17 = uVar20;

        }

        if (0x1fffffffffffffff < uVar17) {

                    /* WARNING: Subroutine does not return */

          FUN_140024090();

        }

      }

      local_res18 = uVar17 * 8;

      puVar13 = (ulonglong *)FUN_1400285e0(local_res18);

      puVar13[lVar26] = uVar11;

      puVar18 = puVar13;

      puVar22 = local_e8;

      if (puVar5 != puStack_e0) {

        FUN_1402f8e20(puVar13,local_e8,(longlong)puVar5 - (longlong)local_e8);

        puVar18 = puVar13 + lVar26 + 1;

        puVar22 = puVar5;

      }

      FUN_1402f8e20(puVar18,puVar22);

      if (local_e8 != (ulonglong *)0x0) {

        if ((0xfff < ((longlong)local_d8 - (longlong)local_e8 & 0xfffffffffffffff8U)) &&

           (0x1f < (longlong)local_e8 + (-8 - local_e8[-1]))) goto LAB_140093b50;

        FUN_1402c7088();

      }

      puStack_e0 = puVar13 + uVar28;

      local_d8 = (ulonglong *)(local_res18 + (longlong)puVar13);

      local_e8 = puVar13;

    }

    else {

      *puStack_e0 = uVar11;

      puStack_e0 = puStack_e0 + 1;

    }

    uVar20 = local_res8 & 0xffffffff;

    goto LAB_140093159;

  }

  if (cVar6 == '\0') {

LAB_140093165:

    if ((local_res10 != 0) && (*(char *)(param_1 + 0x2a5) == '\0')) {

      *(undefined1 *)(param_1 + 0x2a5) = 1;

      *(int *)(param_1 + 0x2a8) = *(int *)(param_1 + 0x2a8) + 1;

    }

    ppuVar10 = (ulonglong **)FUN_140106140(DAT_1403fb0d8,&local_d0);

    if (&local_e8 != ppuVar10) {

      if (local_e8 != (ulonglong *)0x0) {

        if ((0xfff < ((longlong)local_d8 - (longlong)local_e8 & 0xfffffffffffffff8U)) &&

           (0x1f < (longlong)local_e8 + (-8 - local_e8[-1]))) goto LAB_140093bda;

        FUN_1402c7088();

      }

      local_e8 = *ppuVar10;

      puStack_e0 = ppuVar10[1];

      local_d8 = ppuVar10[2];

      *ppuVar10 = (ulonglong *)0x0;

      ppuVar10[1] = (ulonglong *)0x0;

      ppuVar10[2] = (ulonglong *)0x0;

    }

    if (local_d0 != (ulonglong *)0x0) {

      if ((0xfff < (local_c0 - (longlong)local_d0 & 0xfffffffffffffff8U)) &&

         (0x1f < (longlong)local_d0 + (-8 - local_d0[-1]))) {

LAB_140093bda:

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

      FUN_1402c7088();

    }

    if (((longlong)puStack_e0 - (longlong)local_e8 >> 3 == 0) &&

       (*(char *)(param_1 + 0x2a5) == '\0')) {

      *(undefined4 *)(param_1 + 0x2a0) = 10;

      if (*(longlong *)(param_1 + 0x3a8) == 0) {

        uVar19 = 0;

        goto LAB_140093ae8;

      }

      FUN_14009bea0(&local_e8,1);

    }

    else {

      *(undefined4 *)(param_1 + 0x2a0) = 10;

    }

  }

  else {

    uVar20 = uVar11;

    if ((*(int *)(param_1 + 0x2a0) == 0) && (uVar20 = uVar28, 4 < (int)DAT_1403eded8)) {

      uVar19 = 0x14;

      if ((ulonglong)((longlong)puStack_e0 - (longlong)local_e8 >> 3) < 5) {

        uVar19 = 6;

      }

      iVar7 = FUN_1400c6580(uVar19);

      if (iVar7 != 0) goto LAB_140093159;

      FUN_140105da0(DAT_1403fb0d8,&local_d0,1,*(undefined8 *)(param_1 + 0xc),CONCAT44(uVar8,1000),0)

      ;

      if (local_d0 != puStack_c8) {

        if (puStack_e0 == local_d8) {

          FUN_140030680(&local_e8);

        }

        else {

          *puStack_e0 = *local_d0;

          puStack_e0 = puStack_e0 + 1;

        }

        *(undefined1 *)(param_1 + 0x2a4) = 1;

      }

      if (local_d0 == (ulonglong *)0x0) goto LAB_140093159;

      if ((0xfff < (local_c0 - (longlong)local_d0 & 0xfffffffffffffff8U)) &&

         (0x1f < (longlong)local_d0 + (-8 - local_d0[-1]))) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

      FUN_1402c7088();

    }

    else {

LAB_140093159:

      uVar11 = uVar20;

      if (cVar6 == '\0') goto LAB_140093165;

    }

  }

  if ((int)DAT_1403eded8 < 3) {

    *(undefined4 *)(param_1 + 0x29c) = 4;

  }

  else {

    iVar7 = *(int *)(param_1 + 0x2a0);

    if ((iVar7 == 2) || (iVar7 - 5U < 2)) {

      *(undefined4 *)(param_1 + 0x29c) = 1;

    }

    else if (iVar7 == 8) {

      *(undefined4 *)(param_1 + 0x29c) = 3;

    }

    else if (5 < (int)DAT_1403eded8) {

      uVar27 = DAT_1403eded8 & 0x80000001;

      if ((int)uVar27 < 0) {

        uVar27 = (uVar27 - 1 | 0xfffffffe) + 1;

      }

      if ((uVar27 == 0) && (iVar7 == 0)) {

        iVar7 = FUN_1400c69c0(&DAT_14030ba60,0x16);

        *(int *)(param_1 + 0x29c) = iVar7;

        if (iVar7 == 6) {

          plVar14 = (longlong *)FUN_140107550(DAT_1403fb0d8,&local_d0);

          uVar11 = 1;

          if ((1 < (ulonglong)(plVar14[1] - *plVar14 >> 3)) && (8 < *(int *)(param_1 + 0x3d4)))

          goto LAB_14009347b;

          bVar4 = true;

        }

        else {

LAB_14009347b:

          bVar4 = false;

        }

        if ((uVar11 & 1) != 0) {

          FUN_140030810(&local_d0);

        }

        if (bVar4) {

          *(undefined4 *)(param_1 + 0x29c) = 0;

        }

      }

    }

  }

  if (*(char *)(param_1 + 0x2a5) == '\0') {

    piVar16 = (int *)&DAT_1403d9530;

    if (0xf < DAT_1403d9548) {

      piVar16 = DAT_1403d9530;

    }

    if (DAT_1403d9540 == 7) {

      iVar7 = *piVar16 + -0x6b636f4a;

      if ((iVar7 == 0) && (iVar7 = *(ushort *)(piVar16 + 1) - 0x7965, iVar7 == 0)) {

        iVar7 = *(byte *)((longlong)piVar16 + 6) - 0x73;

      }

      if (iVar7 != 0) goto LAB_14009357d;

      *(undefined4 *)(param_1 + 0x29c) = 6;

    }

LAB_140093507:

    if (*(int *)(param_1 + 0x29c) == 6) {

      plVar14 = (longlong *)FUN_140107550(DAT_1403fb0d8,&local_d0);

      iVar9 = (int)(plVar14[1] - *plVar14 >> 3);

      iVar7 = 4;

      if (iVar9 < 4) {

        iVar7 = iVar9;

      }

      if (local_d0 != (ulonglong *)0x0) {

        if ((0xfff < (local_c0 - (longlong)local_d0 & 0xfffffffffffffff8U)) &&

           (0x1f < (longlong)local_d0 + (-8 - local_d0[-1]))) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

        FUN_1402c7088();

      }

    }

    else if ((((*(char *)(param_1 + 0x259) == '\0') && (iVar7 = FUN_1400c6580(4), iVar7 != 0)) &&

             (DAT_1403eded8 != 1)) && (*(int *)(param_1 + 0x268) != 0)) {

      iVar9 = FUN_1400c6580(5);

      iVar7 = 5;

      if ((iVar9 == 0) && (7 < (int)DAT_1403eded8)) {

        iVar7 = 6;

      }

    }

    else {

      iVar7 = 4;

    }

  }

  else {

LAB_14009357d:

    if (*(char *)(param_1 + 0x2a5) == '\0') goto LAB_140093507;

    iVar7 = (1 < *(int *)(param_1 + 0x3e0)) + 4;

  }

  iVar7 = FUN_1400c5c20((int)((longlong)puStack_e0 - (longlong)local_e8 >> 3) +

                        (uint)(*(char *)(param_1 + 0x2a5) != '\0'),iVar7);

  *(int *)(param_1 + 0x298) = iVar7;

  local_res8 = 0;

  FUN_14009bea0(param_1 + 0x130,(longlong)iVar7,&local_res8);

  uVar28 = (ulonglong)*(int *)(param_1 + 0x298);

  plVar2 = (longlong *)(param_1 + 0x280);

  plVar14 = (longlong *)(param_1 + 0x288);

  lVar26 = *plVar2;

  lVar3 = *plVar14;

  uVar11 = (lVar3 - lVar26) / 0x70;

  if (uVar28 < uVar11) {

    lVar26 = uVar28 * 0x70 + lVar26;

    if (lVar26 != lVar3) {

      lVar25 = lVar26 + 0x30;

      do {

        FUN_140027900(lVar25 + 0x20);

        FUN_140027900(lVar25);

        lVar1 = lVar25 + 0x40;

        lVar25 = lVar25 + 0x70;

      } while (lVar1 != lVar3);

    }

    *plVar14 = lVar26;

  }

  else if (uVar11 < uVar28) {

    if ((ulonglong)((*(longlong *)(param_1 + 0x290) - lVar26) / 0x70) < uVar28) {

      FUN_14009b7b0(plVar2,uVar28,&local_res8);

    }

    else {

      lVar26 = FUN_14009bab0(lVar3,uVar28 - uVar11,plVar2);

      *plVar14 = lVar26;

    }

  }

  plVar14 = (longlong *)(param_1 + 0x280);

  uVar20 = 0;

  uVar11 = uVar20;

  uVar28 = uVar20;

  if (0 < *(int *)(param_1 + 0x298)) {

    do {

      *(undefined4 *)(*plVar14 + 8 + uVar11) = 0xffffffff;

      *(undefined4 *)(*plVar14 + 0xc + uVar11) = 0xffffffff;

      *(undefined4 *)(*plVar14 + 0x10 + uVar11) = 0;

      *(undefined4 *)(*plVar14 + 0x14 + uVar11) = 0;

      *(undefined4 *)(*plVar14 + 0x20 + uVar11) = 0;

      *(undefined4 *)(*plVar14 + 0x18 + uVar11) = 0;

      *(undefined1 *)(*plVar14 + 0x29 + uVar11) = 0;

      *(undefined1 *)(*plVar14 + 0x28 + uVar11) = 0;

      *(undefined4 *)(*plVar14 + 0x1c + uVar11) = 0;

      puVar23 = (undefined8 *)(uVar11 + 0x30 + *plVar14);

      puVar23[2] = 0;

      if (0xf < (ulonglong)puVar23[3]) {

        puVar23 = (undefined8 *)*puVar23;

      }

      *(undefined1 *)puVar23 = 0;

      puVar23 = (undefined8 *)(*plVar14 + 0x50 + uVar11);

      puVar23[2] = 0;

      if (0xf < (ulonglong)puVar23[3]) {

        puVar23 = (undefined8 *)*puVar23;

      }

      *(undefined1 *)puVar23 = 0;

      uVar27 = (int)uVar28 + 1;

      uVar11 = uVar11 + 0x70;

      uVar28 = (ulonglong)uVar27;

    } while ((int)uVar27 < *(int *)(param_1 + 0x298));

  }

  local_b0 = (int *)0x0;

  piStack_a8 = (int *)0x0;

  local_a0 = (int *)0x0;

  if ((longlong)puStack_e0 - (longlong)local_e8 >> 3 != 0) {

    do {

      piVar16 = piStack_a8;

      iVar7 = (int)uVar20;

      if (piStack_a8 == local_a0) {

        lVar26 = (longlong)piStack_a8 - (longlong)local_b0 >> 2;

        if (lVar26 == 0x3fffffffffffffff) {

                    /* WARNING: Subroutine does not return */

          FUN_14002f0d0();

        }

        uVar11 = lVar26 + 1;

        uVar28 = (longlong)local_a0 - (longlong)local_b0 >> 2;

        if (0x3fffffffffffffff - (uVar28 >> 1) < uVar28) {

          uVar20 = 0x3fffffffffffffff;

        }

        else {

          uVar28 = uVar28 + (uVar28 >> 1);

          uVar20 = uVar11;

          if (uVar11 <= uVar28) {

            uVar20 = uVar28;

          }

          if (0x3fffffffffffffff < uVar20) {

                    /* WARNING: Subroutine does not return */

            FUN_140024090();

          }

        }

        piVar15 = (int *)FUN_1400285e0(uVar20 * 4);

        piVar15[lVar26] = iVar7;

        piVar21 = piVar15;

        piVar24 = local_b0;

        if (piVar16 != piStack_a8) {

          FUN_1402f8e20(piVar15,local_b0,(longlong)piVar16 - (longlong)local_b0);

          piVar21 = piVar15 + lVar26 + 1;

          piVar24 = piVar16;

        }

        FUN_1402f8e20(piVar21,piVar24);

        if (local_b0 != (int *)0x0) {

          if ((0xfff < ((longlong)local_a0 - (longlong)local_b0 & 0xfffffffffffffffcU)) &&

             (0x1f < (ulonglong)((longlong)local_b0 + (-8 - *(longlong *)(local_b0 + -2))))) {

                    /* WARNING: Subroutine does not return */

            _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

          }

          FUN_1402c7088();

        }

        piStack_a8 = piVar15 + uVar11;

        local_a0 = piVar15 + uVar20;

        local_b0 = piVar15;

      }

      else {

        *piStack_a8 = iVar7;

        piStack_a8 = piStack_a8 + 1;

      }

      uVar20 = (ulonglong)(iVar7 + 1U);

    } while ((ulonglong)(longlong)(int)(iVar7 + 1U) <

             (ulonglong)((longlong)puStack_e0 - (longlong)local_e8 >> 3));

  }

  piVar16 = (int *)(param_1 + 0x298);

  uVar11 = 0;

  if (local_b0 != piStack_a8) {

    FUN_1400c5c80(local_b0,(longlong)piStack_a8 - (longlong)local_b0 >> 2 & 0xffffffff);

  }

  *(undefined4 *)(param_1 + 0x2ac) = 0xffffffff;

  if (*(char *)(param_1 + 0x2a5) != '\0') {

    *(int *)(param_1 + 0x2ac) = *piVar16 / 2;

    *(undefined1 *)((longlong)(*piVar16 / 2) * 0x70 + 0x28 + *(longlong *)(param_1 + 0x280)) = 1;

    *(undefined4 *)((longlong)*(int *)(param_1 + 0x2ac) * 0x70 + 8 + *(longlong *)(param_1 + 0x280))

         = 0;

    *(longlong *)(*(longlong *)(param_1 + 0x130) + (longlong)*(int *)(param_1 + 0x2ac) * 8) =

         local_res10;

  }

  iVar7 = *piVar16;

  uVar28 = uVar11;

  uVar20 = uVar11;

  uVar17 = uVar11;

  if (0 < iVar7) {

    do {

      if ((int)uVar20 != *(int *)(param_1 + 0x2ac)) {

        *(ulonglong *)(uVar28 + *(longlong *)(param_1 + 0x130)) =

             local_e8[*(int *)((longlong)local_b0 + uVar17)];

        uVar17 = uVar17 + 4;

      }

      if ((((*(int *)(*(longlong *)(*(longlong *)(param_1 + 0x130) + uVar28) + 0x1f8) != -1) &&

           (lVar26 = FUN_1400c7520(), *(int *)(lVar26 + 100) == 6)) &&

          (*(int *)(*(longlong *)(*(longlong *)(param_1 + 0x130) + uVar28) + 0x1c) == 0)) &&

         (6 < (int)DAT_1403eded8)) {

        uVar27 = DAT_1403eded8 & 0x80000001;

        if ((int)uVar27 < 0) {

          uVar27 = (uVar27 - 1 | 0xfffffffe) + 1;

        }

        if ((uVar27 == 1) && (iVar7 = FUN_1400c6580(3), iVar7 == 0)) {

          FUN_1400b8f90(*(undefined8 *)(*(longlong *)(param_1 + 0x130) + uVar28),1);

        }

      }

      uVar27 = (int)uVar20 + 1;

      iVar7 = *piVar16;

      uVar28 = uVar28 + 8;

      uVar20 = (ulonglong)uVar27;

    } while ((int)uVar27 < iVar7);

  }

  if ((*(int *)(param_1 + 0x2a0) == 6) && (uVar28 = uVar11, 0 < iVar7)) {

    do {

      *(undefined4 *)(*(longlong *)(uVar28 + *(longlong *)(param_1 + 0x130)) + 0x214) = 0;

      uVar27 = (int)uVar11 + 1;

      uVar11 = (ulonglong)uVar27;

      uVar28 = uVar28 + 8;

    } while ((int)uVar27 < *(int *)(param_1 + 0x298));

  }

  uVar19 = 1;

  if (local_b0 != (int *)0x0) {

    piVar16 = local_b0;

    if ((0xfff < ((longlong)local_a0 - (longlong)local_b0 & 0xfffffffffffffffcU)) &&

       (piVar16 = *(int **)(local_b0 + -2),

       0x1f < (ulonglong)((longlong)local_b0 + (-8 - (longlong)piVar16)))) {

LAB_140093b50:

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

    FUN_1402c7088(piVar16);

    local_b0 = (int *)0x0;

    piStack_a8 = (int *)0x0;

    local_a0 = (int *)0x0;

  }

LAB_140093ae8:

  if (local_e8 != (ulonglong *)0x0) {

    if ((0xfff < ((longlong)local_d8 - (longlong)local_e8 & 0xfffffffffffffff8U)) &&

       (0x1f < (longlong)local_e8 + (-8 - local_e8[-1]))) {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

    FUN_1402c7088();

  }

  return uVar19;

}




