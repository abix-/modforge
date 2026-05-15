// Address: 0x1400b3070
// Ghidra name: FUN_1400b3070
// ============ 0x1400b3070 FUN_1400b3070 (size=1367) ============


void FUN_1400b3070(longlong param_1)



{

  undefined4 uVar1;

  undefined4 uVar2;

  undefined8 uVar3;

  undefined1 uVar4;

  longlong lVar5;

  int iVar6;

  longlong lVar7;

  int *piVar8;

  ulonglong uVar9;

  ulonglong uVar10;

  ulonglong uVar11;

  undefined1 *puVar12;

  uint uVar13;

  longlong lVar14;

  ulonglong uVar15;

  int *piVar16;

  ulonglong uVar17;

  undefined1 local_7b8 [1332];

  undefined8 local_284;

  undefined8 uStack_27c;

  undefined8 local_274;

  undefined8 uStack_26c;

  undefined8 local_264;

  undefined8 uStack_25c;

  undefined4 local_254;

  undefined1 local_250;

  undefined8 local_24c;

  undefined8 uStack_244;

  undefined8 local_23c;

  undefined1 local_228 [512];

  

  uVar10 = 0;

  if (-1 < *(int *)(param_1 + 0x234)) {

    puVar12 = local_228;

    lVar14 = 2;

    uVar9 = uVar10;

    do {

      do {

        uVar4 = FUN_1400c6580(4);

        puVar12[uVar9] = uVar4;

        uVar9 = uVar9 + 1;

      } while ((longlong)uVar9 < 0xf0);

      puVar12 = puVar12 + 0xf0;

      lVar14 = lVar14 + -1;

      uVar9 = uVar10;

    } while (lVar14 != 0);

    FUN_1400b39b0(param_1,local_228);

  }

  lVar5 = DAT_1403f3148;

  lVar14 = *(longlong *)(param_1 + 0x48) - *(longlong *)(param_1 + 0x40);

  lVar14 = lVar14 + SUB168(SEXT816(-0x4de9bd37a6f4de9b) * SEXT816(lVar14),8);

  uVar9 = (lVar14 >> 7) - (lVar14 >> 0x3f);

  uVar17 = DAT_1403f3148 - DAT_1403f3140 >> 2;

  if (uVar9 < uVar17) {

    DAT_1403f3148 = DAT_1403f3140 + uVar9 * 4;

  }

  else if (uVar17 < uVar9) {

    uVar11 = DAT_1403f3150 - DAT_1403f3140 >> 2;

    if (uVar11 < uVar9) {

      if (0x3fffffffffffffff < uVar9) {

LAB_1400b35c3:

                    /* WARNING: Subroutine does not return */

        FUN_14002f0d0();

      }

      if (0x3fffffffffffffff - (uVar11 >> 1) < uVar11) {

        uVar15 = 0x3fffffffffffffff;

      }

      else {

        uVar11 = (uVar11 >> 1) + uVar11;

        uVar15 = uVar9;

        if ((uVar9 <= uVar11) && (uVar15 = uVar11, 0x3fffffffffffffff < uVar11)) {

LAB_1400b35bd:

                    /* WARNING: Subroutine does not return */

          FUN_140024090();

        }

      }

      lVar14 = FUN_1400285e0(uVar15 * 4);

      FUN_1402f94c0(lVar14 + uVar17 * 4,0,(uVar9 - uVar17) * 4);

      FUN_1402f8e20(lVar14,DAT_1403f3140,DAT_1403f3148 - DAT_1403f3140);

      FUN_1400642e0(&DAT_1403f3140,lVar14,uVar9,uVar15);

    }

    else {

      lVar14 = (uVar9 - uVar17) * 4;

      FUN_1402f94c0(DAT_1403f3148,0,lVar14);

      DAT_1403f3148 = lVar14 + lVar5;

    }

  }

  lVar14 = *(longlong *)(param_1 + 0x48);

  lVar5 = *(longlong *)(param_1 + 0x40);

  lVar7 = SUB168(SEXT816(-0x4de9bd37a6f4de9b) * SEXT816(lVar14 - lVar5),8) + (lVar14 - lVar5);

  uVar9 = uVar10;

  uVar17 = uVar10;

  uVar11 = uVar10;

  if (lVar7 >> 7 != lVar7 >> 0x3f) {

    do {

      uVar13 = (int)uVar11 + 1;

      *(undefined4 *)(uVar9 + DAT_1403f3140) = *(undefined4 *)(uVar17 + 0x10 + lVar5);

      lVar14 = *(longlong *)(param_1 + 0x48);

      lVar5 = *(longlong *)(param_1 + 0x40);

      lVar7 = SUB168(SEXT816(-0x4de9bd37a6f4de9b) * SEXT816(lVar14 - lVar5),8) + (lVar14 - lVar5);

      uVar9 = uVar9 + 4;

      uVar17 = uVar17 + 0xb8;

      uVar11 = (ulonglong)uVar13;

    } while ((ulonglong)(longlong)(int)uVar13 < (ulonglong)((lVar7 >> 7) - (lVar7 >> 0x3f)));

  }

  if (lVar5 != lVar14) {

    if (*(longlong *)(lVar5 + 0x30) != 0) {

      uVar3 = *(undefined8 *)(*(longlong *)(lVar5 + 0x30) + 0x58);

      FUN_1400b47e0(param_1);

      lVar14 = *(longlong *)(param_1 + 0x40);

      lVar5 = *(longlong *)(param_1 + 0x48);

      uVar1 = *(undefined4 *)(lVar14 + 0x40);

      uVar2 = *(undefined4 *)(lVar14 + 0x44);

      if (lVar14 != lVar5) {

        do {

          FUN_1400bf700(lVar14 + 0x18);

          lVar14 = lVar14 + 0xb8;

        } while (lVar14 != lVar5);

        *(undefined8 *)(param_1 + 0x48) = *(undefined8 *)(param_1 + 0x40);

      }

      FUN_1402f94c0(local_7b8,0,0x4e4);

      local_284 = 0;

      uStack_27c = 0;

      local_254 = 0;

      local_274 = 0;

      uStack_26c = 0;

      local_250 = 0;

      local_264 = 0;

      uStack_25c = 0;

      local_23c = 0;

      local_24c = 0;

      uStack_244 = 0;

      FUN_14009f680(local_7b8,param_1 + 0x2b8);

      FUN_1400ab3d0(param_1,local_7b8);

      lVar14 = *(longlong *)(param_1 + 0x40);

      *(undefined4 *)(lVar14 + 0x40) = uVar1;

      *(undefined4 *)(lVar14 + 0x44) = uVar2;

      FUN_1400b3dc0(param_1,uVar3);

      goto LAB_1400b3418;

    }

    if (lVar5 != lVar14) {

      do {

        FUN_1400bf700(lVar5 + 0x18);

        lVar5 = lVar5 + 0xb8;

      } while (lVar5 != lVar14);

      *(undefined8 *)(param_1 + 0x48) = *(undefined8 *)(param_1 + 0x40);

    }

  }

  FUN_1402f94c0(local_7b8,0,0x4e4);

  local_284 = 0;

  uStack_27c = 0;

  local_254 = 0;

  local_274 = 0;

  uStack_26c = 0;

  local_250 = 0;

  local_264 = 0;

  uStack_25c = 0;

  local_23c = 0;

  local_24c = 0;

  uStack_244 = 0;

  FUN_14009f680(local_7b8,param_1 + 0x2b8);

  FUN_1400ab3d0(param_1,local_7b8);

LAB_1400b3418:

  if (-1 < *(int *)(param_1 + 0x234)) {

    FUN_1400b3650(param_1,local_228);

  }

  iVar6 = *(int *)(param_1 + 0x1c);

  if (((iVar6 == 3) && (*(char *)(param_1 + 0x390) == '\x03')) &&

     (iVar6 = 3, *(char *)(param_1 + 0x480) == '\x03')) {

    iVar6 = 0;

  }

  *(undefined4 *)(param_1 + 0x1c) = 0;

  *(undefined1 *)(param_1 + 0x21) = 0;

  FUN_1400b8f90(param_1,iVar6);

  piVar16 = (int *)(param_1 + 0xcc);

  do {

    piVar8 = DAT_1403f3128;

    if ((*piVar16 != -1) &&

       ((*(uint *)(DAT_1403f3190 + ((ulonglong)(longlong)(int)uVar10 >> 5) * 4) >>

         ((byte)uVar10 & 0x1f) & 1) == 0)) {

      if (DAT_1403f3128 == DAT_1403f3130) {

        lVar14 = (longlong)DAT_1403f3128 - (longlong)DAT_1403f3120 >> 2;

        if (lVar14 == 0x3fffffffffffffff) goto LAB_1400b35c3;

        uVar9 = lVar14 + 1;

        uVar17 = (longlong)DAT_1403f3130 - (longlong)DAT_1403f3120 >> 2;

        if (0x3fffffffffffffff - (uVar17 >> 1) < uVar17) {

          uVar11 = 0x3fffffffffffffff;

        }

        else {

          uVar17 = (uVar17 >> 1) + uVar17;

          uVar11 = uVar9;

          if (uVar9 <= uVar17) {

            uVar11 = uVar17;

          }

          if (0x3fffffffffffffff < uVar11) goto LAB_1400b35bd;

        }

        lVar5 = FUN_1400285e0(uVar11 * 4);

        *(int *)(lVar5 + lVar14 * 4) = *piVar16;

        if (piVar8 == DAT_1403f3128) {

          lVar7 = (longlong)DAT_1403f3128 - (longlong)DAT_1403f3120;

          lVar14 = lVar5;

          piVar8 = DAT_1403f3120;

        }

        else {

          FUN_1402f8e20(lVar5,DAT_1403f3120,(longlong)piVar8 - (longlong)DAT_1403f3120);

          lVar7 = (longlong)DAT_1403f3128 - (longlong)piVar8;

          lVar14 = lVar5 + (lVar14 + 1) * 4;

        }

        FUN_1402f8e20(lVar14,piVar8,lVar7);

        FUN_1400642e0(&DAT_1403f3120,lVar5,uVar9,uVar11);

      }

      else {

        *DAT_1403f3128 = *piVar16;

        DAT_1403f3128 = DAT_1403f3128 + 1;

      }

      *piVar16 = -1;

    }

    uVar13 = (int)uVar10 + 1;

    uVar10 = (ulonglong)uVar13;

    piVar16 = piVar16 + 1;

    if (0x14 < (int)uVar13) {

      if (DAT_1403f3140 != DAT_1403f3148) {

        DAT_1403f3148 = DAT_1403f3140;

      }

      return;

    }

  } while( true );

}




