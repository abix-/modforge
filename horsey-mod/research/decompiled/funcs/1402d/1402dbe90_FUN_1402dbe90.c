// Address: 0x1402dbe90
// Ghidra name: FUN_1402dbe90
// ============ 0x1402dbe90 FUN_1402dbe90 (size=950) ============


undefined8

FUN_1402dbe90(ulonglong param_1,int param_2,longlong param_3,char param_4,undefined8 *param_5)



{

  ulonglong *puVar1;

  longlong lVar2;

  int iVar3;

  bool bVar4;

  byte bVar5;

  byte bVar6;

  int iVar7;

  uint uVar8;

  ulonglong uVar9;

  char cVar10;

  int iVar11;

  int iVar12;

  int iVar13;

  ulonglong uVar14;

  

  lVar2 = 0x3f;

  if (param_1 != 0) {

    for (; param_1 >> lVar2 == 0; lVar2 = lVar2 + -1) {

    }

  }

  iVar3 = (int)param_3;

  if (param_1 == 0) {

    iVar7 = 0;

  }

  else {

    iVar7 = (int)lVar2 + 1;

  }

  cVar10 = *(char *)(param_5 + 1);

  iVar7 = ((-(uint)(cVar10 != '\0') & 0x1d) + 0x18) - iVar7;

  iVar11 = param_2 - iVar7;

  iVar12 = (-(uint)(cVar10 != '\0') & 0x380) + 0x7f;

  if (iVar12 < iVar11) goto LAB_1402dc16a;

  bVar5 = (byte)param_3;

  if (iVar11 < (int)((-(uint)(cVar10 != '\0') & 0xfffffc80) - 0x7e)) {

    iVar13 = param_2 + -1 + iVar12;

    iVar11 = -iVar12;

    if (iVar13 < 0) {

      if ((uint)-iVar13 < 0x40) {

        bVar6 = (byte)-iVar13;

        uVar9 = 1L << (bVar6 - 1 & 0x3f);

        uVar14 = uVar9 & param_1;

        if ((param_4 == '\0') || ((param_1 & uVar9 - 1) != 0)) {

          bVar4 = true;

        }

        else {

          bVar4 = false;

        }

        if ((uVar14 != 0) || (bVar4)) {

          iVar12 = fegetround();

          if (iVar12 == 0) {

            if ((uVar14 == 0) || ((bVar5 = 1, !bVar4 && ((1L << (bVar6 & 0x3f) & param_1) == 0))))

            goto LAB_1402dbff6;

          }

          else if (iVar12 != 0x100) {

            if (iVar12 != 0x200) goto LAB_1402dbff6;

            bVar5 = bVar5 ^ 1;

          }

        }

        else {

LAB_1402dbff6:

          bVar5 = 0;

        }

        param_1 = (param_1 >> (bVar6 & 0x3f)) + (ulonglong)bVar5;

      }

      else {

        param_1 = 0;

      }

      cVar10 = *(char *)(param_5 + 1);

      if (param_1 == 0) {

        if (cVar10 == '\0') {

          *(int *)*param_5 = iVar3 << 0x1f;

        }

        else {

          *(longlong *)*param_5 = param_3 << 0x3f;

        }

        return 2;

      }

      if ((-(ulonglong)(cVar10 != '\0') & 0xfffffff800000) + 0x7fffff < param_1) {

        iVar11 = ((param_2 - iVar13) - iVar7) + -1;

      }

      goto LAB_1402dc1a8;

    }

  }

  else {

    if (iVar7 < 0) {

      if ((uint)-iVar7 < 0x40) {

        bVar6 = (byte)-iVar7;

        uVar9 = 1L << (bVar6 - 1 & 0x3f);

        uVar14 = uVar9 & param_1;

        if ((param_4 == '\0') || ((param_1 & uVar9 - 1) != 0)) {

          bVar4 = true;

        }

        else {

          bVar4 = false;

        }

        if ((uVar14 != 0) || (bVar4)) {

          iVar7 = fegetround();

          if (iVar7 == 0) {

            if ((uVar14 == 0) || ((!bVar4 && ((1L << (bVar6 & 0x3f) & param_1) == 0))))

            goto LAB_1402dc117;

            bVar5 = 1;

          }

          else if (iVar7 != 0x100) {

            if (iVar7 != 0x200) goto LAB_1402dc117;

            bVar5 = bVar5 ^ 1;

          }

        }

        else {

LAB_1402dc117:

          bVar5 = 0;

        }

        param_1 = (param_1 >> (bVar6 & 0x3f)) + (ulonglong)bVar5;

      }

      else {

        param_1 = 0;

      }

      cVar10 = *(char *)(param_5 + 1);

      if ((-(ulonglong)(cVar10 != '\0') & 0x1fffffff000000) + 0xffffff < param_1) {

        param_1 = param_1 >> 1;

        iVar11 = iVar11 + 1;

        if ((int)((-(uint)(cVar10 != '\0') & 0x380) + 0x7f) < iVar11) {

LAB_1402dc16a:

          if (cVar10 == '\0') {

            *(uint *)*param_5 = iVar3 << 0x1f | 0x7f800000;

          }

          else {

            *(ulonglong *)*param_5 = param_3 << 0x3f | 0x7ff0000000000000;

          }

          return 3;

        }

      }

      goto LAB_1402dc1a8;

    }

    iVar13 = iVar7;

    if (iVar7 < 1) goto LAB_1402dc1a8;

  }

  param_1 = param_1 << ((byte)iVar13 & 0x3f);

LAB_1402dc1a8:

  puVar1 = (ulonglong *)*param_5;

  param_1 = (-(ulonglong)(cVar10 != '\0') & 0xfffffff800000) + 0x7fffff & param_1;

  if (cVar10 == '\0') {

    uVar8 = iVar3 << 0x1f | (uint)*puVar1 & 0x7fffffff;

    uVar8 = ((iVar11 + 0x7f) * 0x800000 ^ uVar8) & 0x7f800000 ^ uVar8;

    *(uint *)puVar1 = (uVar8 ^ (uint)param_1) & 0x7fffff ^ uVar8;

  }

  else {

    uVar9 = (longlong)(iVar11 + 0x3ff) << 0x34;

    *puVar1 = (param_3 << 0x3f ^ uVar9) & 0x8000000000000000 ^ uVar9 | param_1;

  }

  return 0;

}




