// Address: 0x14018c820
// Ghidra name: FUN_14018c820
// ============ 0x14018c820 FUN_14018c820 (size=1387) ============


void FUN_14018c820(undefined8 param_1,longlong param_2,ulonglong param_3,ushort *param_4)



{

  byte bVar1;

  ushort uVar2;

  longlong lVar3;

  bool bVar4;

  ushort uVar5;

  char cVar6;

  int iVar7;

  int iVar8;

  int iVar9;

  int iVar10;

  longlong lVar11;

  longlong lVar12;

  undefined8 uVar13;

  byte bVar14;

  int iVar15;

  int iVar16;

  uint uVar17;

  int iVar18;

  byte *pbVar19;

  float fVar20;

  undefined8 in_stack_ffffffffffffff88;

  undefined4 uVar21;

  

  uVar21 = (undefined4)((ulonglong)in_stack_ffffffffffffff88 >> 0x20);

  iVar16 = *(int *)(param_4 + 6);

  iVar15 = *(int *)(param_4 + 8);

  if ((iVar16 != 0) || (bVar4 = false, iVar15 != 0)) {

    bVar4 = true;

  }

  uVar5 = *param_4;

  uVar2 = param_4[2];

  if (*(char *)(param_2 + 0x128) == '\0') {

    return;

  }

  lVar11 = FUN_140183290();

  if (lVar11 == 0) {

    return;

  }

  lVar12 = FUN_1401611a0();

  if (lVar12 == 0) {

    return;

  }

  iVar7 = FUN_14018b9b0(*(undefined4 *)(param_4 + 10));

  if (iVar7 != 1) {

    return;

  }

  cVar6 = FUN_140186c20();

  if ((cVar6 != '\0') && ((param_4[10] & 0x80) != 0)) {

    return;

  }

  lVar3 = *(longlong *)(lVar11 + 0x188);

  if ((bVar4) && (*(int *)(lVar3 + 0x70) == 0)) {

    if ((uVar5 & 1) == 0) {

      FUN_1401628f0(param_1,lVar11,param_3 & 0xffffffff,1,CONCAT44(uVar21,(float)iVar16),

                    (float)iVar15);

    }

    else {

      iVar7 = GetSystemMetrics(0x1000);

      uVar5 = *param_4;

      iVar8 = GetSystemMetrics(-(uint)((uVar5 & 2) != 0) & 0x4e);

      iVar9 = 1;

      if ((uVar5 & 2) != 0) {

        iVar9 = 0x4f;

      }

      iVar9 = GetSystemMetrics(iVar9);

      if ((uVar5 & 0x40) == 0) {

        iVar15 = (int)(((float)iVar15 / DAT_14030ec38) * (float)iVar9);

        iVar16 = (int)(((float)iVar16 / DAT_14030ec38) * (float)iVar8);

      }

      iVar10 = *(int *)(param_2 + 0x120);

      if ((iVar10 == 0) && (*(int *)(param_2 + 0x124) == 0)) {

        *(int *)(param_2 + 0x120) = iVar16;

        *(int *)(param_2 + 0x124) = iVar15;

        iVar10 = iVar16;

      }

      iVar18 = iVar15 - *(int *)(param_2 + 0x124);

      if (iVar7 == 1) {

        if ((*(char *)(lVar3 + 0x65) == '\0') && (*(char *)(lVar3 + 0x66) == '\0')) {

          fVar20 = (float)iVar16 / (float)iVar8;

          if ((((fVar20 <= DAT_14039ca0c) || (DAT_14030d98c <= fVar20)) ||

              (fVar20 = (float)iVar15 / (float)iVar9, fVar20 <= DAT_14039ca0c)) ||

             ((DAT_14030d98c <= fVar20 || (iVar15 < 0x20)))) {

            iVar8 = (int)*(undefined8 *)(lVar3 + 0x8c);

            iVar7 = (int)((ulonglong)*(undefined8 *)(lVar3 + 0x8c) >> 0x20);

            FUN_140228460(((int)*(undefined8 *)(lVar3 + 0x94) - iVar8) / 2 + DAT_1403fcbb8 + iVar8,

                          iVar7 + ((int)((ulonglong)*(undefined8 *)(lVar3 + 0x94) >> 0x20) - iVar7)

                                  / 2);

            DAT_1403fcbb8 = DAT_1403fcbb8 + 1;

            if (1 < DAT_1403fcbb8) {

              DAT_1403fcbb8 = -1;

            }

          }

          else {

            iVar8 = iVar9 / 6 + (iVar9 >> 0x1f) +

                    (int)(((longlong)iVar9 / 6 + ((longlong)iVar9 >> 0x3f) & 0xffffffffU) >> 0x1f);

            iVar7 = FUN_140190050();

            if ((iVar7 < iVar8) && (iVar7 = FUN_140190050(iVar18), iVar7 < iVar8))

            goto LAB_14018cb41;

          }

        }

      }

      else if (*(char *)(lVar12 + 0xee) == '\0') {

        if ((uVar5 & 2) != 0) {

          GetSystemMetrics(0x4c);

          GetSystemMetrics(0x4d);

        }

        iVar7 = *(int *)(param_2 + 0x134);

        if (iVar7 == 0) {

          iVar7 = FUN_1401a8170(param_1,"raw mouse input",lVar11,0,0xffffffffffffffff,1);

          *(int *)(param_2 + 0x134) = iVar7;

        }

        FUN_1401a8920(param_1,iVar7,lVar11);

      }

      else {

        iVar7 = FUN_140190050();

        if ((iVar7 < 0x21) && (iVar7 = FUN_140190050(iVar18), iVar7 < 0x21)) {

LAB_14018cb41:

          FUN_1401628f0(param_1,lVar11,param_3 & 0xffffffff,1,

                        CONCAT44(uVar21,(float)(iVar16 - iVar10)),(float)iVar18);

        }

      }

      *(int *)(param_2 + 0x120) = iVar16;

      *(int *)(param_2 + 0x124) = iVar15;

    }

  }

  if (uVar2 == 0) {

    return;

  }

  uVar17 = 0;

  pbVar19 = &DAT_1403e3a22;

  do {

    if ((param_4[2] & *(ushort *)(pbVar19 + -2)) != 0) {

      bVar14 = *pbVar19;

      bVar1 = pbVar19[1];

      if (bVar14 == 1) {

        cVar6 = FUN_14018d700(param_3);

        if (cVar6 != '\0') {

          bVar14 = 3;

        }

      }

      else if ((bVar14 == 3) && (cVar6 = FUN_14018d700(param_3), cVar6 != '\0')) {

        bVar14 = 1;

      }

      if ((*(byte *)(lVar3 + 0x66) >> (bVar14 - 1 & 0x1f) & 1) == 0) {

        FUN_1401628d0(param_1,lVar11,param_3 & 0xffffffff,bVar14,bVar1);

      }

      else if (bVar1 == 0) {

        *(byte *)(lVar3 + 0x66) = *(byte *)(lVar3 + 0x66) & ~(byte)(1 << (bVar14 - 1 & 0x1f));

        FUN_14022c8c0(lVar11);

      }

    }

    uVar17 = uVar17 + 1;

    pbVar19 = pbVar19 + 4;

  } while (uVar17 < 10);

  if ((param_4[2] >> 10 & 1) == 0) {

    if ((param_4[2] >> 0xb & 1) == 0) goto LAB_14018cd66;

    uVar13 = FUN_14018c5c0();

  }

  else {

    uVar13 = FUN_14018c5c0();

  }

  FUN_1401629c0(uVar13,lVar11,param_3 & 0xffffffff);

LAB_14018cd66:

  *(undefined8 *)(lVar3 + 0x50) = 0xffffffffffffffff;

  return;

}




