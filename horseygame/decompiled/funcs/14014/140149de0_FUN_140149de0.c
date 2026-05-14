// Address: 0x140149de0
// Ghidra name: FUN_140149de0
// ============ 0x140149de0 FUN_140149de0 (size=1290) ============


int FUN_140149de0(longlong param_1,uint param_2)



{

  int *piVar1;

  int iVar2;

  ulonglong uVar3;

  int *piVar4;

  uint *puVar5;

  uint uVar6;

  ulonglong uVar7;

  ulonglong uVar8;

  int iVar9;

  int iVar10;

  uint uVar11;

  ulonglong uVar12;

  uint uVar13;

  int iVar14;

  

  if (param_2 == 0x47504a4d) {

    iVar9 = *(int *)(param_1 + 0x110);

    uVar7 = 0;

    if (0 < iVar9) {

      piVar1 = *(int **)(param_1 + 0x108);

      uVar3 = uVar7;

      uVar8 = uVar7;

      do {

        if (piVar1[uVar3] == 0x3231564e) {

          return piVar1[(int)uVar8];

        }

        uVar8 = (ulonglong)((int)uVar8 + 1);

        uVar3 = uVar3 + 1;

        piVar4 = piVar1;

        uVar12 = uVar7;

      } while ((longlong)uVar3 < (longlong)iVar9);

      do {

        if (*piVar4 == 0x16762004) {

          return piVar1[(int)uVar12];

        }

        uVar7 = uVar7 + 1;

        piVar4 = piVar4 + 1;

        uVar12 = (ulonglong)((int)uVar12 + 1);

      } while ((longlong)uVar7 < (longlong)iVar9);

    }

    goto LAB_140149e57;

  }

  uVar6 = (int)param_2 >> 0x1c & 0xf;

  if ((param_2 != 0) && (uVar6 != 1)) {

    uVar7 = 0;

    if (0 < *(int *)(param_1 + 0x110)) {

      puVar5 = *(uint **)(param_1 + 0x108);

      uVar3 = uVar7;

      do {

        if (*puVar5 == param_2) {

          return *(int *)(*(longlong *)(param_1 + 0x108) + (longlong)(int)uVar3 * 4);

        }

        uVar3 = (ulonglong)((int)uVar3 + 1);

        uVar7 = uVar7 + 1;

        puVar5 = puVar5 + 1;

      } while ((longlong)uVar7 < (longlong)*(int *)(param_1 + 0x110));

    }

    goto LAB_140149e57;

  }

  uVar13 = (int)param_2 >> 0x18;

  if (((uVar13 & 0xf) == 6) && ((param_2 & 0xf0000) == 0x70000)) {

LAB_14014a1e5:

    uVar11 = 0;

    if (((param_2 == 0) || (uVar6 == 1)) &&

       ((((uVar13 & 0xf) == 6 && ((param_2 & 0xf0000) == 0x70000)) &&

        (0 < *(int *)(param_1 + 0x110))))) {

      puVar5 = *(uint **)(param_1 + 0x108);

      uVar6 = uVar11;

      do {

        uVar13 = *puVar5;

        if (((uVar13 != 0) && ((uVar13 & 0xf0000000) == 0x10000000)) &&

           (((uVar13 & 0xf000000) == 0x6000000 && ((uVar13 & 0xf0000) == 0x70000)))) {

          return *(int *)(*(longlong *)(param_1 + 0x108) + (longlong)(int)uVar6 * 4);

        }

        uVar6 = uVar6 + 1;

        puVar5 = puVar5 + 1;

      } while ((int)uVar6 < *(int *)(param_1 + 0x110));

    }

    if (0 < *(int *)(param_1 + 0x110)) {

      puVar5 = *(uint **)(param_1 + 0x108);

      do {

        uVar6 = *puVar5;

        if (((uVar6 == 0) || ((uVar6 & 0xf0000000) == 0x10000000)) &&

           (((uVar6 & 0xf000000) == 0xa000000 || ((uVar6 & 0xf000000) == 0xb000000)))) {

          return *(int *)(*(longlong *)(param_1 + 0x108) + (ulonglong)uVar11 * 4);

        }

        uVar11 = uVar11 + 1;

        puVar5 = puVar5 + 1;

      } while ((int)uVar11 < *(int *)(param_1 + 0x110));

    }

    goto LAB_140149e57;

  }

  if ((param_2 == 0) || (uVar6 == 1)) {

    if (((uVar13 & 0xf) == 10) || ((uVar13 & 0xf) == 0xb)) goto LAB_14014a1e5;

    if ((param_2 != 0) && (uVar6 != 1)) goto LAB_140149f9d;

    if ((((uVar13 & 0xf) != 4) && (1 < (uVar13 & 0xf) - 5)) ||

       ((((uVar6 = param_2 & 0xf00000, uVar6 != 0x300000 && (uVar6 != 0x400000)) &&

         (uVar6 != 0x700000)) && (uVar6 != 0x800000)))) {

      if (param_2 != 0) goto LAB_140149f9d;

      goto LAB_140149fab;

    }

LAB_140149fed:

    iVar9 = 1;

  }

  else {

LAB_140149f9d:

    if ((param_2 & 0xf0000000) == 0x10000000) {

LAB_140149fab:

      if ((((param_2 & 0xf000000) == 0x7000000) ||

          (((param_2 & 0xf000000) + 0xf8000000 & 0xfcffffff) == 0)) &&

         (((uVar6 = param_2 & 0xf00000, uVar6 == 0x300000 ||

           ((uVar6 == 0x200000 || (uVar6 == 0x600000)))) || (uVar6 == 0x500000))))

      goto LAB_140149fed;

    }

    iVar9 = 0;

  }

  if (param_2 == 0) {

LAB_14014a055:

    uVar6 = param_2 & 0xf000000;

    if (((uVar6 == 0xc000000) || (uVar6 == 0x2000000)) || (uVar6 == 0x3000000)) goto LAB_14014a012;

LAB_14014a06a:

    iVar10 = 0;

  }

  else {

    if ((param_2 & 0xf0000000) != 0x10000000) goto LAB_14014a06a;

    if ((param_2 & 0xf000000) != 0x1000000) goto LAB_14014a055;

LAB_14014a012:

    iVar10 = 1;

  }

  if ((param_2 == 0) || ((param_2 & 0xf0000000) == 0x10000000)) {

    param_2 = param_2 & 0xff;

  }

  else if (((param_2 == 0x32595559) || (param_2 == 0x59565955)) ||

          ((param_2 == 0x55595659 || (param_2 == 0x30313050)))) {

    param_2 = 2;

  }

  else {

    param_2 = 1;

  }

  iVar14 = 0;

  if (0 < *(int *)(param_1 + 0x110)) {

    puVar5 = *(uint **)(param_1 + 0x108);

    do {

      uVar6 = *puVar5;

      if (((uVar6 == 0) || ((uVar6 & 0xf0000000) == 0x10000000)) && ((uVar6 & 0xff) == param_2)) {

        if ((uVar6 == 0) || ((uVar6 & 0xf0000000) == 0x10000000)) {

          if ((((uVar6 & 0xf000000) != 0x4000000) &&

              (((uVar6 & 0xf000000) + 0xfb000000 & 0xfeffffff) != 0)) ||

             ((((uVar13 = uVar6 & 0xf00000, uVar13 != 0x300000 && (uVar13 != 0x400000)) &&

               (uVar13 != 0x700000)) && (uVar13 != 0x800000)))) {

            if (uVar6 != 0) goto LAB_14014a113;

            goto LAB_14014a121;

          }

LAB_14014a163:

          iVar2 = 1;

        }

        else {

LAB_14014a113:

          if ((uVar6 & 0xf0000000) == 0x10000000) {

LAB_14014a121:

            if ((((uVar6 & 0xf000000) == 0x7000000) ||

                (((uVar6 & 0xf000000) + 0xf8000000 & 0xfcffffff) == 0)) &&

               ((uVar13 = uVar6 & 0xf00000, uVar13 == 0x300000 ||

                (((uVar13 == 0x200000 || (uVar13 == 0x600000)) || (uVar13 == 0x500000))))))

            goto LAB_14014a163;

          }

          iVar2 = 0;

        }

        if (iVar2 == iVar9) {

          if (((uVar6 == 0) || ((uVar6 & 0xf0000000) == 0x10000000)) &&

             (((uVar6 = uVar6 & 0xf000000, uVar6 == 0x1000000 ||

               ((uVar6 == 0xc000000 || (uVar6 == 0x2000000)))) || (uVar6 == 0x3000000)))) {

            iVar2 = 1;

          }

          else {

            iVar2 = 0;

          }

          if (iVar2 == iVar10) {

            return *(int *)(*(longlong *)(param_1 + 0x108) + (longlong)iVar14 * 4);

          }

        }

      }

      iVar14 = iVar14 + 1;

      puVar5 = puVar5 + 1;

    } while (iVar14 < *(int *)(param_1 + 0x110));

  }

LAB_140149e57:

  return **(int **)(param_1 + 0x108);

}




