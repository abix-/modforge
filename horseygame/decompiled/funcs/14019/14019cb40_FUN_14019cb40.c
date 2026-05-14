// Address: 0x14019cb40
// Ghidra name: FUN_14019cb40
// ============ 0x14019cb40 FUN_14019cb40 (size=466) ============


undefined8 FUN_14019cb40(longlong param_1,longlong param_2)



{

  uint uVar1;

  uint uVar2;

  undefined8 uVar3;

  byte bVar4;

  byte *pbVar5;

  ulonglong uVar6;

  ulonglong uVar7;

  int iVar8;

  ulonglong uVar9;

  undefined2 *puVar10;

  uint uVar11;

  ulonglong uVar13;

  int *piVar14;

  ushort *puVar15;

  ulonglong uVar12;

  

  uVar7 = 0;

  uVar9 = uVar7;

  uVar6 = uVar7;

  uVar13 = uVar7;

  do {

    iVar8 = (int)uVar13;

    if (0 < *(int *)(param_2 + (longlong)iVar8 * 4)) {

      uVar12 = uVar7;

      do {

        *(char *)(param_1 + 0x500 + uVar9) = (char)uVar13 + '\x01';

        uVar6 = (ulonglong)((int)uVar6 + 1);

        uVar9 = uVar9 + 1;

        if (0x100 < (longlong)uVar9) {

          uVar3 = FUN_14019f050("Corrupt JPEG");

          return uVar3;

        }

        uVar11 = (int)uVar12 + 1;

        uVar12 = (ulonglong)uVar11;

      } while ((int)uVar11 < *(int *)(param_2 + (longlong)iVar8 * 4));

    }

    uVar13 = (ulonglong)(iVar8 + 1U);

  } while ((int)(iVar8 + 1U) < 0x10);

  uVar11 = 1;

  iVar8 = 0xf;

  *(undefined1 *)((longlong)(int)uVar6 + 0x500 + param_1) = 0;

  piVar14 = (int *)(param_1 + 0x608);

  uVar9 = uVar7;

  uVar6 = uVar7;

  uVar13 = uVar7;

  do {

    uVar2 = (uint)uVar9;

    pbVar5 = (byte *)(param_1 + 0x500 + uVar13);

    piVar14[0x12] = (int)uVar6 - uVar2;

    if (*pbVar5 == uVar11) {

      puVar10 = (undefined2 *)(param_1 + 0x200 + uVar13 * 2);

      do {

        *puVar10 = (short)uVar9;

        pbVar5 = pbVar5 + 1;

        puVar10 = puVar10 + 1;

        uVar1 = (uint)uVar9;

        uVar6 = (ulonglong)((int)uVar6 + 1);

        uVar13 = uVar13 + 1;

        uVar2 = uVar1 + 1;

        uVar9 = (ulonglong)uVar2;

      } while (*pbVar5 == uVar11);

      if ((uint)(1 << ((byte)uVar11 & 0x1f)) <= uVar1) {

        uVar3 = FUN_14019f050("Corrupt JPEG");

        return uVar3;

      }

    }

    uVar9 = (ulonglong)(uVar2 * 2);

    *piVar14 = uVar2 << ((byte)iVar8 & 0x1f);

    uVar11 = uVar11 + 1;

    piVar14 = piVar14 + 1;

    iVar8 = iVar8 + -1;

    if (iVar8 < 0) {

      *(undefined4 *)(param_1 + 0x604 + (longlong)(int)uVar11 * 4) = 0xffffffff;

      FUN_1402f94c0(param_1,0xff,0x200);

      if (0 < (int)uVar6) {

        pbVar5 = (byte *)(param_1 + 0x500);

        puVar15 = (ushort *)(param_1 + 0x200);

        do {

          if (*pbVar5 < 10) {

            bVar4 = 9 - *pbVar5;

            iVar8 = 1 << (bVar4 & 0x1f);

            if (0 < iVar8) {

              FUN_1402f94c0((int)((uint)*puVar15 << (bVar4 & 0x1f)) + param_1,uVar7 & 0xff,

                            (longlong)iVar8);

            }

          }

          uVar11 = (int)uVar7 + 1;

          uVar7 = (ulonglong)uVar11;

          puVar15 = puVar15 + 1;

          pbVar5 = pbVar5 + 1;

        } while ((int)uVar11 < (int)uVar6);

      }

      return 1;

    }

  } while( true );

}




