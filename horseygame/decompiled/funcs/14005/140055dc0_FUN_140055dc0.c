// Address: 0x140055dc0
// Ghidra name: FUN_140055dc0
// ============ 0x140055dc0 FUN_140055dc0 (size=2115) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_140055dc0(longlong param_1)



{

  longlong lVar1;

  bool bVar2;

  undefined8 ****ppppuVar3;

  ulonglong uVar4;

  char cVar5;

  int iVar6;

  uint uVar7;

  undefined8 *puVar8;

  char *pcVar9;

  size_t sVar10;

  undefined8 *****pppppuVar11;

  ulonglong uVar12;

  longlong *plVar13;

  longlong lVar14;

  longlong lVar15;

  longlong *plVar16;

  ulonglong uVar17;

  bool bVar18;

  ulonglong in_stack_ffffffffffffff38;

  undefined4 uVar19;

  undefined8 ****local_b8;

  undefined8 uStack_b0;

  ulonglong local_a8;

  ulonglong local_a0;

  undefined8 ****local_98;

  undefined8 ***pppuStack_90;

  ulonglong local_88;

  ulonglong uStack_80;

  undefined8 ****local_78;

  undefined8 uStack_70;

  ulonglong local_68;

  ulonglong uStack_60;

  undefined8 ***local_58;

  undefined8 ***pppuStack_50;

  undefined8 ***local_48;

  undefined8 ***pppuStack_40;

  

  *(int *)(param_1 + 0x26c) = *(int *)(param_1 + 0x26c) + 1;

  puVar8 = (undefined8 *)FUN_1400c7520(*(undefined4 *)(*(longlong *)(param_1 + 0x270) + 0x1f8));

  if (0xf < (ulonglong)puVar8[3]) {

    puVar8 = (undefined8 *)*puVar8;

  }

  iVar6 = FUN_140086450(DAT_1403ede48,puVar8);

  *(float *)(*(longlong *)(param_1 + 0x60) + 0x37c) = (float)iVar6;

  FUN_1400ca260(param_1);

  if (*(int *)(param_1 + 0xe0) == 7) {

    *(int *)(param_1 + 0x27c) = (*(int *)(param_1 + 0x27c) + 1) % 0x14;

    local_88 = _DAT_1403040a0;

    uStack_80 = _UNK_1403040a8;

    local_98 = (undefined8 ****)s_SelectInv_140305578._0_8_;

    pppuStack_90 = (undefined8 ***)(ulonglong)(byte)s_SelectInv_140305578[8];

    in_stack_ffffffffffffff38 = in_stack_ffffffffffffff38 & 0xffffffffffffff00;

    FUN_140040ca0(&local_98,100,0,DAT_14039ca44,in_stack_ffffffffffffff38);

    if (0xf < uStack_80) {

      if ((0xfff < uStack_80 + 1) &&

         (0x1f < (ulonglong)((longlong)local_98 + (-8 - (longlong)local_98[-1])))) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

      FUN_1402c7088();

    }

  }

  cVar5 = FUN_14008d2c0();

  if (cVar5 == '\0') {

    if (*(char *)(*(longlong *)(param_1 + 0x270) + 0x204) != '\0') {

      *(undefined1 *)(*(longlong *)(param_1 + 0x60) + 0x39d) = 1;

      if ((DAT_1403f3554 != '\0') && (cVar5 = FUN_14008d2c0(), cVar5 == '\0')) {

        DAT_1403f3554 = cVar5;

        pcVar9 = (char *)FUN_1400cf970(param_1,*(undefined8 *)(param_1 + 0x270));

        local_98 = (undefined8 *****)0x0;

        pppuStack_90 = (undefined8 ****)0x0;

        local_88 = 0;

        uStack_80 = 0;

        strlen(pcVar9);

        FUN_140027e30(&local_98,pcVar9);

        uVar4 = uStack_80;

        ppppuVar3 = local_98;

        pppppuVar11 = &local_98;

        if (0xf < uStack_80) {

          pppppuVar11 = (undefined8 *****)local_98;

        }

        if (local_88 == 0xd) {

          iVar6 = memcmp(pppppuVar11,"High Achiever",0xd);

          bVar18 = iVar6 == 0;

        }

        else {

          bVar18 = false;

        }

        if (0xf < uVar4) {

          pppppuVar11 = (undefined8 *****)ppppuVar3;

          if ((0xfff < uVar4 + 1) &&

             (pppppuVar11 = (undefined8 *****)ppppuVar3[-1],

             0x1f < (ulonglong)((longlong)ppppuVar3 + (-8 - (longlong)pppppuVar11))))

          goto LAB_1400565df;

          FUN_1402c7088(pppppuVar11);

        }

        if (bVar18) {

          pppuStack_90 = (undefined8 ****)0x0;

          local_88 = _DAT_140305680;

          uStack_80 = _UNK_140305688;

          local_98 = (undefined8 *****)0x656d616e;

          FUN_140037710(&local_98);

          if (0xf < uStack_80) {

            if ((0xfff < uStack_80 + 1) &&

               (0x1f < (ulonglong)((longlong)local_98 + (-8 - (longlong)local_98[-1])))) {

                    /* WARNING: Subroutine does not return */

              _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

            }

            FUN_1402c7088();

          }

        }

      }

      if (*(int *)(param_1 + 0xe0) == 8) {

        lVar1 = *(longlong *)(param_1 + 0x60);

        pcVar9 = (char *)FUN_1400cf970(param_1,*(undefined8 *)(param_1 + 0x270));

        uVar19 = (undefined4)(in_stack_ffffffffffffff38 >> 0x20);

        local_b8 = (undefined8 *****)0x0;

        uStack_b0 = 0;

        local_a8 = 0;

        local_a0 = 0;

        sVar10 = strlen(pcVar9);

        FUN_140027e30(&local_b8,pcVar9,sVar10);

        uVar4 = local_a8;

        ppppuVar3 = local_b8;

        pppppuVar11 = &local_b8;

        if (0xf < local_a0) {

          pppppuVar11 = (undefined8 *****)local_b8;

        }

        if (local_a8 == 5) {

          lVar14 = 0;

          do {

            lVar15 = lVar14 + 1;

            if (*(byte *)((longlong)pppppuVar11 + lVar14) != "Horse"[lVar14]) {

              uVar7 = -(uint)(*(byte *)((longlong)pppppuVar11 + lVar14) < (byte)"Horse"[lVar14]) | 1

              ;

              goto LAB_14005615f;

            }

            lVar14 = lVar15;

          } while (lVar15 != 5);

          uVar7 = 0;

LAB_14005615f:

          if (uVar7 != 0) goto LAB_140056188;

          uStack_70 = 0;

          local_68 = _DAT_14039caa0;

          uStack_60 = _UNK_14039caa8;

          local_78 = (undefined8 *****)0x0;

          pppppuVar11 = &local_78;

          bVar2 = true;

          bVar18 = false;

        }

        else {

LAB_140056188:

          local_98 = (undefined8 ****)0x0;

          pppuStack_90 = (undefined8 ****)0x0;

          local_88 = 0;

          uStack_80 = 0;

          pppppuVar11 = &local_b8;

          if (0xf < local_a0) {

            pppppuVar11 = (undefined8 *****)local_b8;

          }

          if (0x7fffffffffffffff < local_a8) {

                    /* WARNING: Subroutine does not return */

            FUN_140024130();

          }

          if (local_a8 < 0x10) {

            local_88 = local_a8;

            uStack_80 = 0xf;

            local_98 = *pppppuVar11;

            pppuStack_90 = pppppuVar11[1];

          }

          else {

            uVar17 = local_a8 | 0xf;

            if (uVar17 < 0x8000000000000000) {

              if (uVar17 < 0x16) {

                uVar17 = 0x16;

              }

            }

            else {

              uVar17 = 0x7fffffffffffffff;

            }

            local_98 = (undefined8 ****)FUN_1400285e0(uVar17 + 1);

            local_88 = uVar4;

            uStack_80 = uVar17;

            FUN_1402f8e20(local_98,pppppuVar11,uVar4 + 1);

          }

          pppppuVar11 = &local_98;

          bVar2 = false;

          bVar18 = true;

        }

        uVar4 = local_a0;

        local_58 = *pppppuVar11;

        pppuStack_50 = pppppuVar11[1];

        local_48 = pppppuVar11[2];

        pppuStack_40 = pppppuVar11[3];

        pppppuVar11[2] = (undefined8 ****)0x0;

        pppppuVar11[3] = (undefined8 ****)0xf;

        *(undefined1 *)pppppuVar11 = 0;

        in_stack_ffffffffffffff38 = CONCAT44(uVar19,(int)*(float *)(lVar1 + 0x380));

        FUN_14008d200(&local_58,(int)*(float *)(lVar1 + 0x374),(int)*(float *)(lVar1 + 0x378),

                      (int)*(float *)(lVar1 + 0x37c),in_stack_ffffffffffffff38);

        if ((bVar18) && (0xf < uStack_80)) {

          if ((0xfff < uStack_80 + 1) &&

             (0x1f < (ulonglong)((longlong)local_98 + (-8 - (longlong)local_98[-1])))) {

                    /* WARNING: Subroutine does not return */

            _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

          }

          FUN_1402c7088();

        }

        if ((bVar2) && (0xf < uStack_60)) {

          if ((0xfff < uStack_60 + 1) &&

             (0x1f < (ulonglong)((longlong)local_78 + (-8 - (longlong)local_78[-1])))) {

                    /* WARNING: Subroutine does not return */

            _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

          }

          FUN_1402c7088();

        }

        DAT_1403f3554 = '\x01';

        if (0xf < uVar4) {

          pppppuVar11 = (undefined8 *****)ppppuVar3;

          if ((0xfff < uVar4 + 1) &&

             (pppppuVar11 = (undefined8 *****)ppppuVar3[-1],

             0x1f < (ulonglong)((longlong)ppppuVar3 + (-8 - (longlong)pppppuVar11)))) {

LAB_1400565df:

                    /* WARNING: Subroutine does not return */

            _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

          }

          FUN_1402c7088(pppppuVar11);

        }

      }

    }

  }

  else {

    *(undefined1 *)(*(longlong *)(param_1 + 0x60) + 0x39d) = 0;

    FUN_14008d2d0(&local_58);

    FUN_1400cf950(param_1,*(undefined8 *)(param_1 + 0x270));

    if ((undefined8 ****)0xf < pppuStack_40) {

      if ((0xfff < (longlong)pppuStack_40 + 1U) &&

         (0x1f < (ulonglong)((longlong)local_58 + (-8 - (longlong)local_58[-1])))) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

      FUN_1402c7088();

    }

    if (DAT_1403ed960 != 0) {

      FUN_14008d290();

    }

  }

  *(undefined4 *)(param_1 + 0x124) = 0;

  if (DAT_1403ed5c7 != '\0') {

    FUN_1400c4fa0(&local_78);

    uVar4 = local_68;

    if (local_68 != 0) {

      local_98 = (undefined8 ****)0x0;

      pppuStack_90 = (undefined8 ****)0x0;

      local_88 = 0;

      uStack_80 = 0;

      pppppuVar11 = &local_78;

      if (0xf < uStack_60) {

        pppppuVar11 = (undefined8 *****)local_78;

      }

      if (0x7fffffffffffffff < local_68) {

                    /* WARNING: Subroutine does not return */

        FUN_140024130();

      }

      if (local_68 < 0x10) {

        local_88 = local_68;

        uStack_80 = 0xf;

        local_98 = *pppppuVar11;

        pppuStack_90 = pppppuVar11[1];

      }

      else {

        uVar12 = local_68 | 0xf;

        uVar17 = 0x7fffffffffffffff;

        if ((uVar12 < 0x8000000000000000) && (uVar17 = uVar12, uVar12 < 0x16)) {

          uVar17 = 0x16;

        }

        local_98 = (undefined8 ****)FUN_1400285e0(uVar17 + 1);

        local_88 = uVar4;

        uStack_80 = uVar17;

        FUN_1402f8e20(local_98,pppppuVar11);

      }

      plVar13 = (longlong *)FUN_140040550(&local_58,&local_98);

      lVar1 = *(longlong *)(param_1 + 0x270);

      plVar16 = (longlong *)(lVar1 + 0x168);

      if (plVar16 != plVar13) {

        if (0xf < *(ulonglong *)(lVar1 + 0x180)) {

          lVar14 = *plVar16;

          lVar15 = lVar14;

          if ((0xfff < *(ulonglong *)(lVar1 + 0x180) + 1) &&

             (lVar15 = *(longlong *)(lVar14 + -8), 0x1f < (lVar14 - lVar15) - 8U))

          goto LAB_1400565f4;

          FUN_1402c7088(lVar15);

        }

        *(undefined8 *)(lVar1 + 0x178) = 0;

        *(undefined8 *)(lVar1 + 0x180) = 0xf;

        *(undefined1 *)plVar16 = 0;

        lVar14 = plVar13[1];

        *plVar16 = *plVar13;

        *(longlong *)(lVar1 + 0x170) = lVar14;

        lVar14 = plVar13[3];

        *(longlong *)(lVar1 + 0x178) = plVar13[2];

        *(longlong *)(lVar1 + 0x180) = lVar14;

        plVar13[2] = 0;

        plVar13[3] = 0xf;

        *(undefined1 *)plVar13 = 0;

      }

      if ((undefined8 ****)0xf < pppuStack_40) {

        if ((0xfff < (longlong)pppuStack_40 + 1U) &&

           (0x1f < (ulonglong)((longlong)local_58 + (-8 - (longlong)local_58[-1])))) {

LAB_1400565f4:

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

        FUN_1402c7088();

      }

      FUN_140040ca0(*(longlong *)(param_1 + 0x270) + 0x168,100,0,DAT_14039ca44,

                    in_stack_ffffffffffffff38 & 0xffffffffffffff00);

    }

    if (0xf < uStack_60) {

      if ((0xfff < uStack_60 + 1) &&

         (0x1f < (ulonglong)((longlong)local_78 + (-8 - (longlong)local_78[-1])))) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

      FUN_1402c7088();

    }

  }

  if ((((*(int *)(param_1 + 0xe0) == 3) || (DAT_1403ed570 != '\0')) || (DAT_1403ed558 != '\0')) ||

     (DAT_1403ed5b9 != '\0')) {

    *(undefined8 *)(param_1 + 0x270) = 0;

  }

  return;

}




