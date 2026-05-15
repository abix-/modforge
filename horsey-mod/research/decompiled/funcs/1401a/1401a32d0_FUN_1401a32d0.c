// Address: 0x1401a32d0
// Ghidra name: FUN_1401a32d0
// ============ 0x1401a32d0 FUN_1401a32d0 (size=1369) ============


undefined8 FUN_1401a32d0(undefined8 *param_1,int param_2)



{

  char cVar1;

  uint *puVar2;

  byte *pbVar3;

  uint uVar4;

  int iVar5;

  uint uVar6;

  int iVar7;

  undefined4 uVar8;

  undefined8 uVar9;

  undefined8 *puVar10;

  longlong lVar11;

  byte bVar12;

  uint uVar13;

  int iVar14;

  ulonglong uVar15;

  char *pcVar16;

  uint *puVar17;

  uint *puVar18;

  uint uVar19;

  ulonglong uVar20;

  undefined4 *puVar21;

  int iVar22;

  byte *pbVar23;

  int local_res8;

  

  puVar2 = (uint *)*param_1;

  uVar20 = 1;

  uVar19 = 1;

  iVar5 = FUN_14019f260(puVar2);

  if (10 < iVar5) {

    pcVar16 = *(char **)(puVar2 + 0x30);

    if (*(char **)(puVar2 + 0x32) <= pcVar16) {

      if (puVar2[0xc] == 0) goto LAB_1401a3812;

      FUN_1401a4400(puVar2);

      pcVar16 = *(char **)(puVar2 + 0x30);

    }

    cVar1 = *pcVar16;

    *(char **)(puVar2 + 0x30) = pcVar16 + 1;

    if (cVar1 != '\b') {

LAB_1401a3812:

      uVar9 = FUN_14019f050("JPEG format not supported: 8-bit only");

      return uVar9;

    }

    uVar6 = FUN_14019f260(puVar2);

    puVar2[1] = uVar6;

    if (uVar6 == 0) {

      uVar9 = FUN_14019f050("JPEG format not supported: delayed height");

      return uVar9;

    }

    uVar6 = FUN_14019f260();

    *puVar2 = uVar6;

    if (uVar6 != 0) {

      if ((0x1000000 < puVar2[1]) || (0x1000000 < uVar6)) {

        uVar9 = FUN_14019f050("Very large image (corrupt?)");

        return uVar9;

      }

      pbVar23 = *(byte **)(puVar2 + 0x30);

      if (pbVar23 < *(byte **)(puVar2 + 0x32)) {

        bVar12 = *pbVar23;

        *(byte **)(puVar2 + 0x30) = pbVar23 + 1;

      }

      else if (puVar2[0xc] == 0) {

        bVar12 = 0;

      }

      else {

        FUN_1401a4400(puVar2);

        bVar12 = **(byte **)(puVar2 + 0x30);

        *(byte **)(puVar2 + 0x30) = *(byte **)(puVar2 + 0x30) + 1;

      }

      uVar15 = (ulonglong)bVar12;

      if (((bVar12 == 3) || (bVar12 == 1)) || (bVar12 == 4)) {

        puVar2[2] = (uint)bVar12;

        if (bVar12 != 0) {

          puVar10 = param_1 + 0x8dd;

          do {

            puVar10[-3] = 0;

            *puVar10 = 0;

            puVar10 = puVar10 + 0xc;

            uVar15 = uVar15 - 1;

          } while (uVar15 != 0);

        }

        if (iVar5 != puVar2[2] * 3 + 8) {

          uVar9 = FUN_14019f050("Corrupt JPEG");

          return uVar9;

        }

        *(undefined4 *)(param_1 + 0x90a) = 0;

        uVar6 = puVar2[2];

        local_res8 = 0;

        if (0 < (int)uVar6) {

          pbVar23 = &DAT_14033b354;

          puVar17 = (uint *)((longlong)param_1 + 0x46a4);

          do {

            puVar18 = puVar2 + 0xc;

            pbVar3 = *(byte **)(puVar2 + 0x30);

            if (pbVar3 < *(byte **)(puVar2 + 0x32)) {

              bVar12 = *pbVar3;

              *(byte **)(puVar2 + 0x30) = pbVar3 + 1;

            }

            else if (*puVar18 == 0) {

              bVar12 = 0;

            }

            else {

              FUN_1401a4400(puVar2);

              bVar12 = **(byte **)(puVar2 + 0x30);

              *(byte **)(puVar2 + 0x30) = *(byte **)(puVar2 + 0x30) + 1;

            }

            puVar17[-1] = (uint)bVar12;

            if ((puVar2[2] == 3) && ((uint)bVar12 == (uint)*pbVar23)) {

              *(int *)(param_1 + 0x90a) = *(int *)(param_1 + 0x90a) + 1;

            }

            pbVar3 = *(byte **)(puVar2 + 0x30);

            if (pbVar3 < *(byte **)(puVar2 + 0x32)) {

              bVar12 = *pbVar3;

              *(byte **)(puVar2 + 0x30) = pbVar3 + 1;

            }

            else if (*puVar18 == 0) {

              bVar12 = 0;

            }

            else {

              FUN_1401a4400(puVar2);

              bVar12 = **(byte **)(puVar2 + 0x30);

              *(byte **)(puVar2 + 0x30) = *(byte **)(puVar2 + 0x30) + 1;

            }

            *puVar17 = (uint)(bVar12 >> 4);

            if ((3 < (bVar12 >> 4) - 1) || (puVar17[1] = bVar12 & 0xf, 3 < (bVar12 & 0xf) - 1))

            goto LAB_1401a37e7;

            pbVar3 = *(byte **)(puVar2 + 0x30);

            if (pbVar3 < *(byte **)(puVar2 + 0x32)) {

              bVar12 = *pbVar3;

              *(byte **)(puVar2 + 0x30) = pbVar3 + 1;

            }

            else if (*puVar18 == 0) {

              bVar12 = 0;

            }

            else {

              FUN_1401a4400(puVar2);

              bVar12 = **(byte **)(puVar2 + 0x30);

              *(byte **)(puVar2 + 0x30) = *(byte **)(puVar2 + 0x30) + 1;

            }

            puVar17[2] = (uint)bVar12;

            if (3 < bVar12) goto LAB_1401a37e7;

            pbVar23 = pbVar23 + 1;

            uVar6 = puVar2[2];

            local_res8 = local_res8 + 1;

            puVar17 = puVar17 + 0x18;

          } while (local_res8 < (int)uVar6);

        }

        iVar5 = 0;

        if (param_2 == 0) {

          iVar7 = FUN_1401a19f0(*puVar2,puVar2[1],uVar6,0);

          if (iVar7 == 0) {

            pcVar16 = "Image too large to decode";

            goto LAB_1401a360b;

          }

          if (0 < (int)uVar6) {

            puVar17 = (uint *)(param_1 + 0x8d5);

            uVar15 = (ulonglong)uVar6;

            puVar18 = puVar17;

            do {

              uVar13 = puVar18[-1];

              if ((int)puVar18[-1] <= (int)(uint)uVar20) {

                uVar13 = (uint)uVar20;

              }

              uVar20 = (ulonglong)uVar13;

              uVar4 = *puVar18;

              if ((int)*puVar18 <= (int)uVar19) {

                uVar4 = uVar19;

              }

              uVar19 = uVar4;

              uVar15 = uVar15 - 1;

              puVar18 = puVar18 + 0x18;

              iVar7 = iVar5;

            } while (uVar15 != 0);

            do {

              if (((int)uVar13 % (int)puVar17[-1] != 0) || ((int)uVar19 % (int)*puVar17 != 0))

              goto LAB_1401a37e7;

              iVar7 = iVar7 + 1;

              puVar17 = puVar17 + 0x18;

            } while (iVar7 < (int)uVar6);

          }

          iVar7 = (int)uVar20;

          *(int *)(param_1 + 0x8d1) = iVar7;

          uVar13 = iVar7 * 8;

          *(uint *)((longlong)param_1 + 0x468c) = uVar19;

          uVar6 = uVar19 * 8;

          *(uint *)(param_1 + 0x8d3) = uVar13;

          *(uint *)((longlong)param_1 + 0x469c) = uVar6;

          *(uint *)(param_1 + 0x8d2) = ((*puVar2 - 1) + uVar13) / uVar13;

          *(uint *)((longlong)param_1 + 0x4694) = ((puVar2[1] - 1) + uVar6) / uVar6;

          if (0 < (int)puVar2[2]) {

            puVar21 = (undefined4 *)((longlong)param_1 + 0x46bc);

            do {

              *puVar21 = (int)((puVar21[-6] * *puVar2 + -1 + iVar7) / uVar20);

              puVar21[1] = (puVar21[-5] * puVar2[1] + -1 + uVar19) / uVar19;

              iVar14 = puVar21[-6] * *(int *)(param_1 + 0x8d2) * 8;

              puVar21[2] = iVar14;

              iVar22 = *(int *)((longlong)param_1 + 0x4694);

              *(undefined8 *)(puVar21 + 0xd) = 0;

              *(undefined8 *)(puVar21 + 9) = 0;

              *(undefined8 *)(puVar21 + 0xb) = 0;

              iVar22 = puVar21[-5] * iVar22 * 8;

              puVar21[3] = iVar22;

              lVar11 = FUN_1401a1ae0(iVar14,iVar22,0xf);

              *(longlong *)(puVar21 + 7) = lVar11;

              if (lVar11 == 0) {

LAB_1401a37f3:

                uVar8 = FUN_14019f050("Out of memory");

                uVar9 = FUN_14019f1d0(param_1,iVar5 + 1,uVar8);

                return uVar9;

              }

              *(ulonglong *)(puVar21 + 5) = lVar11 + 0xfU & 0xfffffffffffffff0;

              if (*(int *)(param_1 + 0x906) != 0) {

                iVar22 = puVar21[2];

                puVar21[0xf] = (int)(iVar22 + (iVar22 >> 0x1f & 7U)) >> 3;

                puVar21[0x10] = (int)(puVar21[3] + ((int)puVar21[3] >> 0x1f & 7U)) >> 3;

                lVar11 = FUN_1401a1b30(iVar22,puVar21[3],2,0xf);

                *(longlong *)(puVar21 + 9) = lVar11;

                if (lVar11 == 0) goto LAB_1401a37f3;

                *(ulonglong *)(puVar21 + 0xd) = lVar11 + 0xfU & 0xfffffffffffffff0;

              }

              iVar5 = iVar5 + 1;

              puVar21 = puVar21 + 0x18;

            } while (iVar5 < (int)puVar2[2]);

          }

        }

        return 1;

      }

    }

  }

  uVar9 = FUN_14019f050("Corrupt JPEG");

  return uVar9;

LAB_1401a37e7:

  pcVar16 = "Corrupt JPEG";

LAB_1401a360b:

  uVar9 = FUN_14019f050(pcVar16);

  return uVar9;

}




