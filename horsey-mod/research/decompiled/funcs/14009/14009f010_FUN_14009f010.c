// Address: 0x14009f010
// Ghidra name: FUN_14009f010
// ============ 0x14009f010 FUN_14009f010 (size=631) ============


ulonglong FUN_14009f010(longlong param_1,longlong param_2,int param_3,float param_4,float *param_5)



{

  char cVar1;

  char cVar2;

  longlong *plVar3;

  float *pfVar4;

  uint uVar5;

  longlong *plVar6;

  uint uVar7;

  longlong *plVar8;

  longlong *plVar9;

  longlong *plVar10;

  int iVar11;

  int iVar12;

  uint uVar13;

  ulonglong uVar14;

  float fVar15;

  float fVar16;

  float fVar17;

  longlong *local_88;

  undefined8 uStack_80;

  

  uVar14 = (ulonglong)param_3;

  fVar17 = 0.0;

  fVar15 = (float)FUN_1402d0350(*(float *)(param_1 + 0x34) * *(float *)(param_1 + 0x20) *

                                *(float *)(param_1 + 0x24));

  fVar16 = (float)FUN_1402d0350(*param_5 / fVar15);

  iVar12 = 0;

  cVar1 = *(char *)(uVar14 + param_2);

  uVar5 = 0xffffffff;

  do {

    if (cVar1 == '\0') {

      *param_5 = (float)(iVar12 + 1) * fVar15;

      return uVar14 & 0xffffffff;

    }

    uVar13 = (uint)uVar14;

    iVar11 = (int)*(char *)((int)uVar13 + param_2);

    uVar7 = uVar13;

    if (iVar11 != 0x20) {

      uVar7 = uVar5;

    }

    if (iVar11 == 10) {

      if ((int)fVar16 <= iVar12 + 1) {

        return (ulonglong)(uVar13 + 1);

      }

LAB_14009f21c:

      iVar12 = iVar12 + 1;

      uVar7 = 0xffffffff;

      fVar17 = 0.0;

    }

    else {

      plVar3 = *(longlong **)(param_1 + 0x10);

      plVar8 = (longlong *)plVar3[1];

      cVar2 = *(char *)((longlong)plVar8 + 0x19);

      plVar6 = plVar3;

      plVar9 = plVar8;

      cVar1 = cVar2;

      while (cVar1 == '\0') {

        plVar10 = plVar9;

        if ((int)plVar9[4] < iVar11) {

          plVar9 = plVar9 + 2;

          plVar10 = plVar6;

        }

        plVar9 = (longlong *)*plVar9;

        plVar6 = plVar10;

        cVar1 = *(char *)((longlong)plVar9 + 0x19);

      }

      if ((*(char *)((longlong)plVar6 + 0x19) != '\0') || (iVar11 < (int)plVar6[4])) {

        iVar11 = 0x3f;

      }

      uStack_80 = uStack_80 & 0xffffffff00000000;

      plVar9 = plVar3;

      local_88 = plVar8;

      while (plVar6 = plVar8, cVar2 == '\0') {

        uStack_80._4_4_ = (uint)(uStack_80 >> 0x20);

        if ((int)plVar6[4] < iVar11) {

          uStack_80 = (ulonglong)uStack_80._4_4_ << 0x20;

          plVar8 = plVar6 + 2;

        }

        else {

          uStack_80 = CONCAT44(uStack_80._4_4_,1);

          plVar8 = plVar6;

          plVar9 = plVar6;

        }

        cVar2 = *(char *)(*plVar8 + 0x19);

        plVar8 = (longlong *)*plVar8;

        local_88 = plVar6;

      }

      if ((*(char *)((longlong)plVar9 + 0x19) != '\0') || (iVar11 < (int)plVar9[4])) {

        if (*(longlong *)(param_1 + 0x18) == 0x555555555555555) {

                    /* WARNING: Subroutine does not return */

          FUN_1400478f0();

        }

        plVar8 = (longlong *)FUN_1402c704c();

        *(int *)(plVar8 + 4) = iVar11;

        plVar8[5] = 0;

        *plVar8 = (longlong)plVar3;

        plVar8[1] = (longlong)plVar3;

        plVar8[2] = (longlong)plVar3;

        *(undefined2 *)(plVar8 + 3) = 0;

        plVar9 = (longlong *)FUN_140047690((longlong *)(param_1 + 0x10),&local_88,plVar8);

      }

      pfVar4 = (float *)plVar9[5];

      fVar17 = fVar17 + pfVar4[8] + *pfVar4 + pfVar4[9] + *(float *)(param_1 + 0x30);

      if ((param_4 < fVar17) && (uVar7 != 0xffffffff)) {

        uVar13 = uVar7;

        if ((int)fVar16 <= iVar12 + 1) {

          return (ulonglong)uVar7;

        }

        goto LAB_14009f21c;

      }

    }

    uVar14 = (ulonglong)(uVar13 + 1);

    cVar1 = *(char *)((longlong)(int)uVar13 + 1 + param_2);

    uVar5 = uVar7;

  } while( true );

}




