// Address: 0x1401607e0
// Ghidra name: FUN_1401607e0
// ============ 0x1401607e0 FUN_1401607e0 (size=701) ============


/* WARNING: Function: __chkstk replaced with injection: alloca_probe */



longlong * FUN_1401607e0(longlong *param_1,uint param_2,int param_3,int param_4)



{

  int iVar1;

  code *pcVar2;

  undefined4 uVar3;

  longlong *plVar4;

  ulonglong uVar5;

  ulonglong uVar6;

  longlong lVar7;

  longlong lVar8;

  longlong lVar9;

  char *pcVar10;

  int iVar11;

  undefined4 *puVar12;

  ulonglong uVar13;

  undefined1 *puVar14;

  uint uVar15;

  ulonglong uVar17;

  undefined1 auStack_78 [32];

  int local_58 [2];

  longlong local_50;

  ulonglong local_48;

  ulonglong local_40;

  longlong local_38;

  longlong *plVar16;

  

  puVar14 = auStack_78;

  uVar13 = (ulonglong)param_2;

  local_38 = FUN_1401611a0();

  plVar4 = (longlong *)0x0;

  if (param_1 == (longlong *)0x0) {

    FUN_14012e850("Parameter \'%s\' is invalid","frames");

  }

  else {

    if (*param_1 == 0) {

      pcVar10 = "NULL surface in frame 0";

    }

    else {

      if ((int)param_2 < 1) {

        FUN_14012e850("Parameter \'%s\' is invalid","frame_count");

        return (longlong *)0x0;

      }

      if (param_2 == 1) {

        plVar4 = (longlong *)FUN_140160aa0(*param_1,param_3,param_4);

        return plVar4;

      }

      uVar3 = FUN_140146bc0();

      uVar5 = FUN_140174c40(uVar3,"SDL.surface.hotspot.x",(longlong)param_3);

      local_40 = uVar5;

      local_48 = FUN_140174c40(uVar3,"SDL.surface.hotspot.y",(longlong)param_4);

      if ((((-1 < (int)uVar5) && (-1 < (int)local_48)) && ((int)uVar5 < *(int *)(*param_1 + 8))) &&

         ((int)local_48 < *(int *)(*param_1 + 0xc))) {

        uVar5 = (longlong)(int)param_2 * 0x10;

        if (uVar5 < 0x80) {

          uVar6 = uVar5 + 0xf;

          if (uVar6 <= uVar5) {

            uVar6 = 0xffffffffffffff0;

          }

          puVar14 = auStack_78 + -(uVar6 & 0xfffffffffffffff0);

          lVar7 = (longlong)local_58 + -(uVar6 & 0xfffffffffffffff0);

        }

        else {

          lVar7 = FUN_1401841f0(uVar5);

        }

        if (lVar7 == 0) {

          return (longlong *)0x0;

        }

        *(undefined8 *)(puVar14 + -8) = 0x14016092e;

        FUN_1402f94c0(lVar7,0,uVar5);

        puVar12 = (undefined4 *)(lVar7 + 8);

        iVar1 = *(int *)(*param_1 + 8);

        iVar11 = *(int *)(*param_1 + 0xc);

        local_50 = (longlong)param_1 - lVar7;

        local_58[0] = iVar11;

        plVar16 = plVar4;

        do {

          lVar8 = *(longlong *)((longlong)puVar12 + local_50 + -8);

          if (lVar8 == 0) {

            *(undefined8 *)(puVar14 + -8) = 0x140160a39;

            FUN_14012e850("Null surface in frame %i",plVar16);

            plVar4 = (longlong *)0x0;

            goto LAB_140160a39;

          }

          if ((*(int *)(lVar8 + 8) != iVar1) || (*(int *)(lVar8 + 0xc) != iVar11)) {

            *(undefined8 *)(puVar14 + -8) = 0x140160a29;

            FUN_14012e850("All frames in an animated sequence must have the same dimensions");

            plVar4 = (longlong *)0x0;

            goto LAB_140160a39;

          }

          if (*(int *)(lVar8 + 4) != 0x16362004) {

            *(undefined8 *)(puVar14 + -8) = 0x140160986;

            lVar8 = FUN_140145bb0(lVar8,0x16362004);

            iVar11 = local_58[0];

            if (lVar8 == 0) goto LAB_140160a39;

          }

          *(longlong *)(puVar12 + -2) = lVar8;

          uVar15 = (int)plVar16 + 1;

          plVar16 = (longlong *)(ulonglong)uVar15;

          *puVar12 = *(undefined4 *)((longlong)puVar12 + local_50);

          lVar8 = local_38;

          puVar12 = puVar12 + 4;

        } while ((int)uVar15 < (int)param_2);

        uVar17 = local_48 & 0xffffffff;

        uVar6 = local_40 & 0xffffffff;

        pcVar2 = *(code **)(local_38 + 8);

        if (pcVar2 == (code *)0x0) {

          *(undefined8 *)(puVar14 + -8) = 0x1401609dd;

          lVar9 = FUN_140160bc0(lVar7,param_2,uVar6,uVar17);

          if (lVar9 == 0) goto LAB_140160a39;

          *(undefined8 *)(puVar14 + -8) = 0x1401609f4;

          plVar4 = (longlong *)FUN_1401841a0(1,0x18);

          if (plVar4 == (longlong *)0x0) {

            *(undefined8 *)(puVar14 + -8) = 0x140160a04;

            FUN_140160e30(lVar9);

            goto LAB_140160a39;

          }

          *plVar4 = lVar9;

        }

        else {

          *(undefined8 *)(puVar14 + -8) = 0x1401609ce;

          plVar4 = (longlong *)(*pcVar2)();

          if (plVar4 == (longlong *)0x0) goto LAB_140160a39;

        }

        plVar4[2] = *(longlong *)(lVar8 + 0x110);

        *(longlong **)(lVar8 + 0x110) = plVar4;

LAB_140160a39:

        lVar8 = lVar7 - (longlong)param_1;

        do {

          lVar9 = *(longlong *)(lVar8 + (longlong)param_1);

          if ((lVar9 != 0) && (*param_1 != lVar9)) {

            *(undefined8 *)(puVar14 + -8) = 0x140160a55;

            FUN_140146010();

          }

          param_1 = param_1 + 2;

          uVar13 = uVar13 - 1;

        } while (uVar13 != 0);

        if (0x7f < uVar5) {

          *(undefined8 *)(puVar14 + -8) = 0x140160a70;

          FUN_1401841e0(lVar7);

          return plVar4;

        }

        return plVar4;

      }

      pcVar10 = "Cursor hot spot doesn\'t lie within cursor";

    }

    FUN_14012e850(pcVar10);

  }

  return (longlong *)0x0;

}




