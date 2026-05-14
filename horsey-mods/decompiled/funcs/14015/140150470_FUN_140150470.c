// Address: 0x140150470
// Ghidra name: FUN_140150470
// ============ 0x140150470 FUN_140150470 (size=1497) ============


ulonglong FUN_140150470(longlong param_1,longlong param_2,longlong param_3,undefined4 param_4,

                       longlong param_5,undefined4 param_6,longlong param_7,int param_8,int param_9,

                       longlong param_10,int param_11,int param_12)



{

  float fVar1;

  float fVar2;

  char cVar3;

  char cVar4;

  int iVar5;

  ulonglong uVar6;

  ulonglong uVar7;

  int iVar8;

  longlong lVar9;

  uint uVar10;

  char *pcVar11;

  int iVar12;

  int iVar13;

  int iVar14;

  int iVar15;

  int iVar16;

  int iVar17;

  

  iVar17 = param_9;

  if (param_10 != 0) {

    iVar17 = param_11;

  }

  iVar5 = 1;

  iVar15 = 1;

  if ((param_1 == 0) ||

     ((DAT_1403e3d60 != '\0' && (cVar3 = FUN_1401aa7c0(param_1,2), cVar3 == '\0')))) {

    uVar6 = FUN_14012e850("Parameter \'%s\' is invalid","renderer");

    return uVar6 & 0xffffffffffffff00;

  }

  if (*(char *)(param_1 + 0x2d8) != '\0') {

    uVar6 = FUN_14012e850("Renderer\'s window has been destroyed, can\'t use further");

    return uVar6 & 0xffffffffffffff00;

  }

  if (param_2 != 0) {

    if ((DAT_1403e3d60 != '\0') && (cVar3 = FUN_1401aa7c0(param_2,3), cVar3 == '\0')) {

      uVar6 = FUN_14012e850("Parameter \'%s\' is invalid","texture");

      return uVar6 & 0xffffffffffffff00;

    }

    if (param_1 != *(longlong *)(param_2 + 0x10)) {

      uVar6 = FUN_14012e850("Texture was not created with this renderer");

      return uVar6;

    }

  }

  if (param_3 == 0) {

    uVar6 = FUN_14012e850("Parameter \'%s\' is invalid",&DAT_140332f44);

    return uVar6;

  }

  if (param_5 == 0) {

    uVar6 = FUN_14012e850("Parameter \'%s\' is invalid","color");

    return uVar6;

  }

  if ((param_2 != 0) && (param_7 == 0)) {

    uVar6 = FUN_14012e850("Parameter \'%s\' is invalid",&DAT_140332f48);

    return uVar6;

  }

  if (iVar17 != (iVar17 / 3 + (iVar17 >> 0x1f) +

                (int)(((longlong)iVar17 / 3 + ((longlong)iVar17 >> 0x3f) & 0xffffffffU) >> 0x1f)) *

                3) {

    pcVar11 = "num_vertices";

    if (param_10 != 0) {

      pcVar11 = "num_indices";

    }

    uVar6 = FUN_14012e850("Parameter \'%s\' is invalid",pcVar11);

    return uVar6;

  }

  if ((param_10 != 0) && (((param_12 - 1U & 0xfffffffc) != 0 || (param_12 == 3)))) {

    uVar6 = FUN_14012e850("Parameter \'%s\' is invalid","size_indices");

    return uVar6;

  }

  uVar6 = 0;

  iVar17 = 0;

  if (param_10 != 0) {

    iVar17 = param_12;

  }

  if (*(longlong *)(param_1 + 0x58) == 0) {

    pcVar11 = "That operation is not supported";

LAB_14015065a:

    uVar6 = FUN_14012e850(pcVar11);

    return uVar6;

  }

  if (param_9 < 3) {

    return 1;

  }

  lVar9 = param_1;

  iVar14 = iVar5;

  if (param_2 == 0) goto LAB_1401508e8;

  uVar7 = FUN_140156f30(param_2);

  if ((char)uVar7 == '\0') {

    return uVar7;

  }

  if (*(longlong *)(param_2 + 0xf8) != 0) {

    param_2 = *(longlong *)(param_2 + 0xf8);

  }

  cVar3 = *(char *)(param_1 + 0x115);

  if ((((cVar3 == '\0') || (cVar4 = FUN_14014a360(*(undefined4 *)(param_2 + 4)), cVar4 == '\0')) &&

      (iVar15 = *(int *)(lVar9 + 0x230), cVar3 == '\0')) ||

     (cVar3 = FUN_14014a360(*(undefined4 *)(param_2 + 8)), iVar5 = iVar15, iVar14 = 1, cVar3 == '\0'

     )) {

    iVar14 = *(int *)(lVar9 + 0x234);

    iVar5 = iVar15;

  }

  if ((iVar5 != 0) && (iVar14 != 0)) goto LAB_1401508e8;

  uVar7 = uVar6;

  iVar15 = iVar5;

  iVar12 = iVar14;

  if (param_9 < 4) {

LAB_140150869:

    iVar8 = (int)uVar7 * param_8;

    do {

      fVar1 = *(float *)(iVar8 + param_7);

      fVar2 = *(float *)((longlong)iVar8 + 4 + param_7);

      if (((fVar1 < 0.0) || (DAT_14039ca44 < fVar1)) && (iVar5 == 0)) {

        iVar15 = 2;

        iVar5 = 2;

        if (iVar14 != 0) goto LAB_1401508e8;

      }

      iVar13 = iVar14;

      if (((fVar2 < 0.0) || (DAT_14039ca44 < fVar2)) && (iVar14 == 0)) {

        iVar12 = 2;

        iVar14 = 2;

        iVar13 = iVar14;

        if (iVar5 != 0) goto LAB_1401508e8;

      }

      uVar10 = (int)uVar7 + 1;

      uVar7 = (ulonglong)uVar10;

      iVar8 = iVar8 + param_8;

      iVar16 = iVar5;

      iVar14 = iVar13;

    } while ((int)uVar10 < param_9);

  }

  else {

    iVar16 = param_8 * 2;

    do {

      lVar9 = (longlong)(param_8 * -2 + iVar16);

      fVar1 = *(float *)(lVar9 + param_7);

      fVar2 = *(float *)(lVar9 + 4 + param_7);

      if (((fVar1 < 0.0) || (DAT_14039ca44 < fVar1)) && (iVar5 == 0)) {

        iVar15 = 2;

        iVar5 = 2;

        lVar9 = param_1;

        if (iVar14 != 0) goto LAB_1401508e8;

      }

      if (((fVar2 < 0.0) || (DAT_14039ca44 < fVar2)) && (iVar14 == 0)) {

        iVar12 = 2;

        iVar14 = 2;

        lVar9 = param_1;

        if (iVar5 != 0) goto LAB_1401508e8;

      }

      fVar1 = *(float *)((iVar16 - param_8) + param_7);

      fVar2 = *(float *)((longlong)(iVar16 - param_8) + 4 + param_7);

      if (((fVar1 < 0.0) || (DAT_14039ca44 < fVar1)) && (iVar5 == 0)) {

        iVar15 = 2;

        iVar5 = 2;

        lVar9 = param_1;

        if (iVar14 != 0) goto LAB_1401508e8;

      }

      if (((fVar2 < 0.0) || (DAT_14039ca44 < fVar2)) && (iVar14 == 0)) {

        iVar12 = 2;

        iVar14 = 2;

        lVar9 = param_1;

        if (iVar5 != 0) goto LAB_1401508e8;

      }

      fVar1 = *(float *)(iVar16 + param_7);

      fVar2 = *(float *)((longlong)iVar16 + 4 + param_7);

      if (((fVar1 < 0.0) || (DAT_14039ca44 < fVar1)) && (iVar5 == 0)) {

        iVar15 = 2;

        iVar5 = 2;

        lVar9 = param_1;

        if (iVar14 != 0) goto LAB_1401508e8;

      }

      if (((fVar2 < 0.0) || (DAT_14039ca44 < fVar2)) && (iVar14 == 0)) {

        iVar12 = 2;

        iVar14 = 2;

        lVar9 = param_1;

        if (iVar5 != 0) goto LAB_1401508e8;

      }

      fVar1 = *(float *)((iVar16 + param_8) + param_7);

      fVar2 = *(float *)((longlong)(iVar16 + param_8) + 4 + param_7);

      if (((fVar1 < 0.0) || (DAT_14039ca44 < fVar1)) && (iVar5 == 0)) {

        iVar15 = 2;

        iVar5 = 2;

        lVar9 = param_1;

        if (iVar14 != 0) goto LAB_1401508e8;

      }

      if (((fVar2 < 0.0) || (DAT_14039ca44 < fVar2)) && (iVar14 == 0)) {

        iVar12 = 2;

        iVar14 = 2;

        lVar9 = param_1;

        if (iVar5 != 0) goto LAB_1401508e8;

      }

      uVar10 = (int)uVar7 + 4;

      uVar7 = (ulonglong)uVar10;

      iVar16 = iVar16 + param_8 * 4;

    } while ((int)uVar10 < param_9 + -3);

    lVar9 = param_1;

    iVar16 = iVar5;

    iVar13 = iVar14;

    if ((int)uVar10 < param_9) goto LAB_140150869;

  }

  iVar14 = iVar12;

  iVar5 = iVar15;

  if (iVar16 == 0) {

    iVar5 = 1;

  }

  lVar9 = param_1;

  if (iVar13 == 0) {

    iVar14 = 1;

  }

LAB_1401508e8:

  if ((param_10 != 0) && (0 < param_11)) {

    do {

      if (iVar17 == 4) {

        uVar10 = *(uint *)(param_10 + uVar6 * 4);

      }

      else if (iVar17 == 2) {

        uVar10 = (uint)*(ushort *)(param_10 + uVar6 * 2);

      }

      else {

        uVar10 = (uint)*(byte *)(uVar6 + param_10);

      }

      if (((int)uVar10 < 0) || (param_9 <= (int)uVar10)) {

        pcVar11 = "Values of \'indices\' out of bounds";

        goto LAB_14015065a;

      }

      uVar6 = uVar6 + 1;

    } while ((longlong)uVar6 < (longlong)param_11);

  }

  if (param_2 != 0) {

    *(undefined4 *)(param_2 + 0x130) = *(undefined4 *)(lVar9 + 600);

  }

  if (((*(char *)(lVar9 + 0x114) == '\0') || (iVar5 != 1)) || (iVar14 != 1)) {

    uVar6 = FUN_14014ac90(lVar9,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,

                          param_10,param_11,iVar17,

                          *(undefined4 *)(*(longlong *)(lVar9 + 0x138) + 0x90),

                          *(undefined4 *)(*(longlong *)(lVar9 + 0x138) + 0x94),iVar5,iVar14);

  }

  else {

    uVar6 = FUN_1401538f0(lVar9,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,

                          param_10,param_11,iVar17);

  }

  return uVar6;

}




