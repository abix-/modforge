// Address: 0x140068bb0
// Ghidra name: FUN_140068bb0
// ============ 0x140068bb0 FUN_140068bb0 (size=900) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined8 FUN_140068bb0(longlong param_1,int param_2)



{

  longlong lVar1;

  longlong lVar2;

  longlong lVar3;

  longlong lVar4;

  bool bVar5;

  undefined4 uVar6;

  undefined8 uVar7;

  ulonglong uVar8;

  undefined4 uVar9;

  undefined4 uVar10;

  float *pfVar11;

  undefined8 uVar12;

  longlong lVar13;

  longlong lVar14;

  ulonglong uVar15;

  float extraout_XMM0_Da;

  float fVar16;

  undefined8 local_res8;

  undefined1 local_res20 [8];

  undefined1 local_b8 [8];

  undefined8 local_b0;

  char *local_a0;

  undefined8 uStack_98;

  undefined8 local_90;

  ulonglong uStack_88;

  

  lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x130) + (longlong)param_2 * 8);

  *(undefined4 *)(lVar1 + 0x1cc) = 0;

  *(undefined1 *)(lVar1 + 0x204) = 1;

  pfVar11 = (float *)FUN_1400b4a10(lVar1,&local_res8);

  fVar16 = (*pfVar11 - (float)DAT_1403d9178) * (*pfVar11 - (float)DAT_1403d9178) +

           (pfVar11[1] - DAT_1403d9178._4_4_) * (pfVar11[1] - DAT_1403d9178._4_4_);

  if (fVar16 < 0.0) {

    FUN_1402cdfa0(fVar16);

    fVar16 = extraout_XMM0_Da;

  }

  else {

    fVar16 = SQRT(fVar16);

  }

  if (fVar16 < DAT_14030338c) {

    FUN_1400b3dc0(lVar1,*(undefined8 *)(param_1 + 0x98));

    FUN_1400b6990(lVar1,*(int *)(param_1 + 0x120) + -1,0);

    uVar6 = DAT_140309bcc;

    bVar5 = false;

    FUN_140007610(*(undefined8 *)(param_1 + 0x98),DAT_140309bcc,10);

    FUN_140007610(*(undefined8 *)(param_1 + 0x98),uVar6,10);

    uVar9 = DAT_14039ca44;

    uVar8 = _UNK_140303428;

    uVar7 = _DAT_140303420;

    uVar6 = DAT_140303354;

    lVar14 = *(longlong *)(lVar1 + 0x40);

    lVar2 = *(longlong *)(lVar1 + 0x48);

    if (lVar14 != lVar2) {

      do {

        if ((*(longlong *)(lVar14 + 0x30) != 0) &&

           (lVar13 = *(longlong *)(*(longlong *)(lVar14 + 0x30) + 0x88), lVar13 != 0)) {

LAB_140068d20:

          lVar3 = *(longlong *)(lVar13 + 8);

          if ((lVar3 == 0) || ((*(byte *)(lVar3 + 8) & 2) == 0)) goto LAB_140068d45;

          lVar4 = *(longlong *)(lVar3 + 0x60);

          if ((lVar4 != *(longlong *)(param_1 + 0x260)) &&

             (*(longlong *)(lVar3 + 0x68) != *(longlong *)(param_1 + 0x260))) goto LAB_140068d45;

          bVar5 = true;

          uVar15 = *(longlong *)(*(longlong *)(lVar3 + 0x68) + 0x10) + 0xc;

          FUN_14000bfe0(local_b8,lVar3 + 0x78,*(longlong *)(lVar4 + 0x10) + 0xc,

                        *(undefined4 *)(*(longlong *)(lVar4 + 0x18) + 0xc),uVar15,

                        *(undefined4 *)(*(longlong *)(*(longlong *)(lVar3 + 0x68) + 0x18) + 0xc));

          local_res8 = local_b0;

          lVar13 = 10;

          do {

            uVar12 = FUN_1400c6ab0(local_res20);

            uVar15 = uVar15 & 0xffffffff00000000;

            FUN_1400c8dc0(DAT_1403f3110,0xffffffff,&local_res8,uVar12,uVar15,0,&DAT_1403d90e8,0x1e,

                          uVar6);

            lVar13 = lVar13 + -1;

          } while (lVar13 != 0);

          local_a0 = (char *)0x0;

          uStack_98 = 0;

          local_90 = 0;

          uStack_88 = 0;

          local_a0 = (char *)FUN_1400285e0(0x20);

          uVar12 = s_HorseTouchingTurbine_140309ae0._8_8_;

          local_90 = uVar7;

          uStack_88 = uVar8;

          *(undefined8 *)local_a0 = s_HorseTouchingTurbine_140309ae0._0_8_;

          *(undefined8 *)(local_a0 + 8) = uVar12;

          *(undefined4 *)(local_a0 + 0x10) = s_HorseTouchingTurbine_140309ae0._16_4_;

          local_a0[0x14] = '\0';

          uVar10 = FUN_140040fe0((undefined4)local_res8);

          FUN_140040ca0(&local_a0,100,uVar10,uVar9,uVar15 & 0xffffffffffffff00);

          if (0xf < uStack_88) {

            if ((0xfff < uStack_88 + 1) &&

               ((char *)0x1f < local_a0 + (-8 - *(longlong *)(local_a0 + -8)))) {

                    /* WARNING: Subroutine does not return */

              _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

            }

            FUN_1402c7088();

          }

        }

LAB_140068ea4:

        lVar14 = lVar14 + 0xb8;

      } while (lVar14 != lVar2);

      if (bVar5) {

        return 1;

      }

    }

    *(undefined4 *)(param_1 + 0x168) = 0xffffffff;

    *(undefined1 *)(lVar1 + 0x1c8) = 0;

    *(undefined4 *)(lVar1 + 0x1cc) = 0xffffffff;

    *(undefined1 *)(lVar1 + 0x204) = 0;

    FUN_1400b7fe0(lVar1,0);

  }

  return 1;

LAB_140068d45:

  lVar13 = *(longlong *)(lVar13 + 0x18);

  if (lVar13 == 0) goto LAB_140068ea4;

  goto LAB_140068d20;

}




