// Address: 0x1401a25a0
// Ghidra name: FUN_1401a25a0
// ============ 0x1401a25a0 FUN_1401a25a0 (size=2555) ============


/* WARNING: Type propagation algorithm not settling */



undefined8

FUN_1401a25a0(undefined8 *param_1,int param_2,uint param_3,undefined1 *param_4,int param_5)



{

  byte bVar1;

  uint *puVar2;

  undefined1 *puVar3;

  bool bVar4;

  bool bVar5;

  char cVar6;

  undefined2 uVar7;

  int iVar8;

  uint uVar9;

  uint uVar10;

  undefined8 uVar11;

  ulonglong uVar12;

  longlong lVar13;

  byte *pbVar14;

  undefined1 uVar15;

  ulonglong uVar16;

  byte bVar17;

  uint uVar18;

  undefined1 *puVar19;

  byte bVar20;

  ulonglong uVar21;

  uint uVar22;

  ulonglong uVar23;

  uint local_res8 [2];

  int local_res10;

  uint local_res18;

  undefined1 *local_res20;

  uint local_470;

  char local_46c [4];

  uint local_468;

  int local_464;

  undefined4 local_460;

  undefined2 local_45c;

  ulonglong local_458;

  undefined1 local_448 [1032];

  

  local_res10 = param_2;

  local_res18 = param_3;

  local_res20 = param_4;

  FUN_1402f94c0(local_448,0,0x400);

  puVar2 = (uint *)*param_1;

  uVar16 = 0;

  bVar4 = true;

  local_470 = 0;

  local_46c[0] = '\0';

  local_46c[1] = '\0';

  bVar20 = 0;

  local_46c[2] = 0;

  local_460 = 0;

  local_45c = 0;

  bVar5 = false;

  local_res8[0] = local_res8[0] & 0xffffff00;

  local_468 = 0;

  local_464 = 0;

  puVar19 = local_448;

  if (local_res20 != (undefined1 *)0x0) {

    if (param_5 < 0x100) {

      uVar11 = FUN_14019f050("palette buffer len must be 256");

      return uVar11;

    }

    puVar19 = local_res20;

    if (local_res18 != 1) {

      uVar11 = FUN_14019f050("req_comp must be 1 when loading paletted");

      return uVar11;

    }

  }

  param_1[2] = 0;

  param_1[1] = 0;

  param_1[3] = 0;

  iVar8 = FUN_14019cd20(puVar2);

  if (iVar8 == 0) {

LAB_1401a2e7c:

    uVar11 = 0;

  }

  else {

    uVar21 = uVar16;

    uVar23 = uVar16;

    if (param_2 != 1) {

LAB_1401a2694:

      while( true ) {

        uVar10 = (uint)uVar23;

        uVar12 = FUN_14019f340();

        uVar9 = (uint)(uVar12 >> 0x20);

        uVar22 = (uint)uVar21;

        uVar18 = (uint)uVar12;

        local_458 = uVar12;

        if (uVar9 < 0x49484453) break;

        if (uVar9 == 0x504c5445) {

          if ((bVar4) || (0x300 < uVar18)) goto LAB_1401a29bf;

          uVar21 = (uVar12 & 0xffffffff) / 3;

          uVar10 = (uint)uVar21;

          if (uVar10 * 3 != uVar18) goto LAB_1401a29bf;

          uVar9 = 0;

          if (uVar10 == 0) goto LAB_1401a2bd5;

          do {

            puVar3 = *(undefined1 **)(puVar2 + 0x30);

            if (puVar3 < *(undefined1 **)(puVar2 + 0x32)) {

              uVar15 = *puVar3;

              *(undefined1 **)(puVar2 + 0x30) = puVar3 + 1;

            }

            else if (puVar2[0xc] == 0) {

              uVar15 = 0;

            }

            else {

              FUN_1401a4400(puVar2);

              uVar15 = **(undefined1 **)(puVar2 + 0x30);

              *(undefined1 **)(puVar2 + 0x30) = *(undefined1 **)(puVar2 + 0x30) + 1;

            }

            uVar18 = uVar9 * 4;

            puVar19[uVar18] = uVar15;

            puVar3 = *(undefined1 **)(puVar2 + 0x30);

            if (puVar3 < *(undefined1 **)(puVar2 + 0x32)) {

              uVar15 = *puVar3;

              *(undefined1 **)(puVar2 + 0x30) = puVar3 + 1;

            }

            else if (puVar2[0xc] == 0) {

              uVar15 = 0;

            }

            else {

              FUN_1401a4400();

              uVar15 = **(undefined1 **)(puVar2 + 0x30);

              *(undefined1 **)(puVar2 + 0x30) = *(undefined1 **)(puVar2 + 0x30) + 1;

            }

            puVar19[uVar18 + 1] = uVar15;

            puVar3 = *(undefined1 **)(puVar2 + 0x30);

            if (puVar3 < *(undefined1 **)(puVar2 + 0x32)) {

              uVar15 = *puVar3;

              *(undefined1 **)(puVar2 + 0x30) = puVar3 + 1;

            }

            else if (puVar2[0xc] == 0) {

              uVar15 = 0;

            }

            else {

              FUN_1401a4400();

              uVar15 = **(undefined1 **)(puVar2 + 0x30);

              *(undefined1 **)(puVar2 + 0x30) = *(undefined1 **)(puVar2 + 0x30) + 1;

            }

            uVar9 = uVar9 + 1;

            puVar19[uVar18 + 2] = uVar15;

            puVar19[uVar18 + 3] = 0xff;

          } while (uVar9 < uVar10);

          bVar20 = (byte)local_res8[0];

          FUN_14019f310(puVar2);

        }

        else {

          if (uVar9 != 0x74524e53) goto LAB_1401a2af8;

          if ((bVar4) || (param_1[1] != 0)) goto LAB_1401a29bf;

          if (bVar20 == 0) {

            uVar10 = puVar2[2];

            if (((uVar10 & 1) == 0) || (uVar18 != uVar10 * 2)) goto LAB_1401a29bf;

            bVar5 = true;

            if (local_res10 == 2) {

              puVar2[2] = uVar10 + 1;

              return 1;

            }

            iVar8 = 0;

            lVar13 = 0;

            if (*(int *)(param_1 + 4) == 0x10) {

              if ((int)uVar10 < 1) {

LAB_1401a2bd5:

                bVar20 = (byte)local_res8[0];

                goto LAB_1401a2bdd;

              }

              do {

                if (2 < lVar13) goto LAB_1401a2bd5;

                uVar7 = FUN_14019f260(puVar2);

                *(undefined2 *)((longlong)&local_460 + lVar13 * 2) = uVar7;

                iVar8 = iVar8 + 1;

                lVar13 = lVar13 + 1;

              } while (iVar8 < (int)puVar2[2]);

              bVar20 = (byte)local_res8[0];

              FUN_14019f310(puVar2);

            }

            else {

              if ((int)uVar10 < 1) goto LAB_1401a2bd5;

              do {

                if (2 < lVar13) goto LAB_1401a2bd5;

                cVar6 = FUN_14019f260(puVar2);

                iVar8 = iVar8 + 1;

                local_46c[lVar13] = (&DAT_14033b610)[*(int *)(param_1 + 4)] * cVar6;

                lVar13 = lVar13 + 1;

              } while (iVar8 < (int)puVar2[2]);

              bVar20 = (byte)local_res8[0];

              FUN_14019f310(puVar2);

            }

          }

          else {

            if (local_res10 == 2) {

              puVar2[2] = 4;

              goto LAB_1401a2f81;

            }

            if ((uVar22 == 0) || (uVar22 < uVar18)) goto LAB_1401a29bf;

            uVar10 = 0;

            local_res8[0] = CONCAT31(local_res8[0]._1_3_,4);

            if (uVar18 != 0) {

              do {

                puVar3 = *(undefined1 **)(puVar2 + 0x30);

                if (puVar3 < *(undefined1 **)(puVar2 + 0x32)) {

                  uVar15 = *puVar3;

                  *(undefined1 **)(puVar2 + 0x30) = puVar3 + 1;

                }

                else if (puVar2[0xc] == 0) {

                  uVar15 = 0;

                }

                else {

                  FUN_1401a4400(puVar2);

                  uVar15 = **(undefined1 **)(puVar2 + 0x30);

                  *(undefined1 **)(puVar2 + 0x30) = *(undefined1 **)(puVar2 + 0x30) + 1;

                }

                iVar8 = uVar10 * 4;

                uVar10 = uVar10 + 1;

                puVar19[iVar8 + 3] = uVar15;

              } while (uVar10 < uVar18);

              goto LAB_1401a2bd5;

            }

            bVar20 = 4;

            FUN_14019f310(puVar2);

          }

        }

      }

      if (uVar9 == 0x49484452) {

        if (!bVar4) goto LAB_1401a29bf;

        uVar16 = 0;

        bVar4 = false;

        if (uVar18 != 0xd) goto LAB_1401a29bf;

        uVar10 = FUN_14019f310(puVar2);

        *puVar2 = uVar10;

        uVar10 = FUN_14019f310(puVar2);

        puVar2[1] = uVar10;

        if ((0x1000000 < uVar10) || (0x1000000 < *puVar2)) {

          uVar11 = FUN_14019f050("Very large image (corrupt?)");

          return uVar11;

        }

        pbVar14 = *(byte **)(puVar2 + 0x30);

        if (*(byte **)(puVar2 + 0x32) <= pbVar14) {

          if (puVar2[0xc] == 0) {

            *(undefined4 *)(param_1 + 4) = 0;

            goto LAB_1401a2f20;

          }

          FUN_1401a4400(puVar2);

          pbVar14 = *(byte **)(puVar2 + 0x30);

        }

        bVar17 = *pbVar14;

        *(byte **)(puVar2 + 0x30) = pbVar14 + 1;

        *(uint *)(param_1 + 4) = (uint)bVar17;

        if ((((bVar17 != 1) && (bVar17 != 2)) && (bVar17 != 4)) &&

           ((bVar17 != 8 && (bVar17 != 0x10)))) {

LAB_1401a2f20:

          uVar11 = FUN_14019f050("PNG not supported: 1/2/4/8/16-bit only");

          return uVar11;

        }

        pbVar14 = *(byte **)(puVar2 + 0x30);

        if (pbVar14 < *(byte **)(puVar2 + 0x32)) {

LAB_1401a2985:

          bVar17 = *pbVar14;

          pbVar14 = pbVar14 + 1;

          local_468 = (uint)bVar17;

          *(byte **)(puVar2 + 0x30) = pbVar14;

          if (6 < bVar17) goto LAB_1401a29bf;

          if (bVar17 == 3) {

            if (*(int *)(param_1 + 4) == 0x10) goto LAB_1401a29bf;

            bVar20 = 3;

            local_res8[0] = CONCAT31(local_res8[0]._1_3_,3);

          }

          else if ((bVar17 & 1) != 0) goto LAB_1401a29bf;

        }

        else {

          if (puVar2[0xc] != 0) {

            FUN_1401a4400(puVar2);

            pbVar14 = *(byte **)(puVar2 + 0x30);

            goto LAB_1401a2985;

          }

          bVar17 = 0;

          local_468 = 0;

        }

        if (pbVar14 < *(byte **)(puVar2 + 0x32)) {

LAB_1401a29f5:

          bVar1 = *pbVar14;

          pbVar14 = pbVar14 + 1;

          *(byte **)(puVar2 + 0x30) = pbVar14;

          if (bVar1 != 0) goto LAB_1401a29bf;

        }

        else if (puVar2[0xc] != 0) {

          FUN_1401a4400(puVar2);

          pbVar14 = *(byte **)(puVar2 + 0x30);

          goto LAB_1401a29f5;

        }

        if (pbVar14 < *(byte **)(puVar2 + 0x32)) {

LAB_1401a2a24:

          bVar1 = *pbVar14;

          pbVar14 = pbVar14 + 1;

          *(byte **)(puVar2 + 0x30) = pbVar14;

          if (bVar1 != 0) goto LAB_1401a29bf;

        }

        else if (puVar2[0xc] != 0) {

          FUN_1401a4400(puVar2);

          pbVar14 = *(byte **)(puVar2 + 0x30);

          goto LAB_1401a2a24;

        }

        if (pbVar14 < *(byte **)(puVar2 + 0x32)) {

LAB_1401a2a53:

          bVar1 = *pbVar14;

          *(byte **)(puVar2 + 0x30) = pbVar14 + 1;

          uVar16 = (ulonglong)bVar1;

          if (1 < bVar1) goto LAB_1401a29bf;

        }

        else if (puVar2[0xc] != 0) {

          FUN_1401a4400(puVar2);

          pbVar14 = *(byte **)(puVar2 + 0x30);

          goto LAB_1401a2a53;

        }

        if ((*puVar2 != 0) && (uVar10 = puVar2[1], uVar10 != 0)) {

          uVar12 = 0x40000000 / (ulonglong)*puVar2;

          if (bVar20 == 0) {

            uVar9 = (bVar17 >> 2 & 1) + (bVar17 & 2 | 1);

            puVar2[2] = uVar9;

            if ((uint)(uVar12 / uVar9) < uVar10) {

              uVar11 = FUN_14019f050("Image too large to decode");

              return uVar11;

            }

LAB_1401a2bdd:

            FUN_14019f310(puVar2);

          }

          else {

            puVar2[2] = 1;

            if ((uint)(uVar12 >> 2) < uVar10) goto LAB_1401a29bf;

            FUN_14019f310(puVar2);

          }

          goto LAB_1401a2694;

        }

      }

      else {

        if (uVar9 == 0x43674249) {

          local_464 = 1;

          FUN_1401a4ad0(puVar2);

          FUN_14019f310(puVar2);

          goto LAB_1401a2694;

        }

        if (uVar9 == 0x49444154) {

          if ((!bVar4) && ((bVar20 == 0 || (uVar22 != 0)))) {

            if (local_res10 == 2) {

              if (bVar20 != 0) {

                puVar2[2] = (uint)bVar20;

                return 1;

              }

              goto LAB_1401a2f81;

            }

            if (0x40000000 < uVar18) {

              uVar11 = FUN_14019f050("IDAT section larger than 2^30 bytes");

              return uVar11;

            }

            uVar9 = uVar18 + local_470;

            if ((int)uVar9 < (int)local_470) goto LAB_1401a2e7c;

            if (uVar10 < uVar9) {

              if (uVar10 != 0) goto LAB_1401a2850;

              uVar23 = 0x1000;

              if (0x1000 < uVar18) {

                uVar23 = uVar12 & 0xffffffff;

              }

              uVar22 = (uint)uVar23;

              while (uVar10 = (uint)uVar23, uVar22 < uVar9) {

LAB_1401a2850:

                uVar22 = uVar10 * 2;

                uVar23 = (ulonglong)uVar22;

              }

              lVar13 = FUN_140184230(param_1[1],uVar23);

              if (lVar13 == 0) {

                uVar11 = FUN_14019f050("Out of memory");

                return uVar11;

              }

              param_1[1] = lVar13;

            }

            iVar8 = FUN_14019f440(puVar2,(ulonglong)local_470 + param_1[1],uVar12 & 0xffffffff);

            if (iVar8 == 0) goto LAB_1401a29bf;

            local_470 = local_470 + uVar18;

            FUN_14019f310(puVar2);

            goto LAB_1401a2694;

          }

        }

        else {

          if (uVar9 != 0x49454e44) {

LAB_1401a2af8:

            if (bVar4) goto LAB_1401a29bf;

            if ((uVar9 >> 0x1d & 1) == 0) {

              s_XXXX_PNG_chunk_not_known_1403e3d10[3] = (char)(uVar12 >> 0x20);

              s_XXXX_PNG_chunk_not_known_1403e3d10[0] = (char)(uVar12 >> 0x38);

              s_XXXX_PNG_chunk_not_known_1403e3d10[1] = (char)(uVar12 >> 0x30);

              s_XXXX_PNG_chunk_not_known_1403e3d10[2] = (char)(uVar12 >> 0x28);

              uVar11 = FUN_14019f050("PNG not supported: unknown PNG chunk type");

              return uVar11;

            }

            FUN_1401a4ad0(puVar2);

            FUN_14019f310(puVar2);

            goto LAB_1401a2694;

          }

          if (bVar4) goto LAB_1401a29bf;

          if (local_res10 != 0) goto LAB_1401a2f81;

          if (param_1[1] != 0) {

            local_res8[0] = ((*puVar2 * *(int *)(param_1 + 4) + 7 >> 3) * puVar2[2] + 1) * puVar2[1]

            ;

            lVar13 = FUN_1401a5310(param_1[1],local_470,local_res8[0],local_res8,local_464 == 0);

            param_1[2] = lVar13;

            if (lVar13 == 0) goto LAB_1401a2e7c;

            FUN_1401841e0(param_1[1]);

            uVar9 = local_res18;

            param_1[1] = 0;

            uVar10 = puVar2[2] + 1;

            if ((((local_res18 != uVar10) || (local_res18 == 3)) || (bVar20 != 0)) && (!bVar5)) {

              uVar10 = puVar2[2];

            }

            puVar2[3] = uVar10;

            iVar8 = FUN_14019dd10(param_1,param_1[2],local_res8[0],uVar10,

                                  *(undefined4 *)(param_1 + 4),local_468,(int)uVar16);

            if (iVar8 == 0) goto LAB_1401a2e7c;

            if (bVar5) {

              if (*(int *)(param_1 + 4) == 0x10) {

                iVar8 = FUN_14019d140(param_1,&local_460);

              }

              else {

                iVar8 = FUN_14019d0c0(param_1,local_46c,puVar2[3]);

              }

              if (iVar8 == 0) goto LAB_1401a2e7c;

            }

            if (((local_464 != 0) && (DAT_1403fcd3c != 0)) && (2 < (int)puVar2[3])) {

              FUN_14019eb10(param_1);

            }

            if (bVar20 == 0) {

              if (bVar5) {

                puVar2[2] = puVar2[2] + 1;

              }

            }

            else {

              puVar2[2] = (uint)bVar20;

              puVar2[3] = (uint)bVar20;

              uVar10 = (uint)bVar20;

              if (2 < (int)uVar9) {

                puVar2[3] = uVar9;

                uVar10 = uVar9;

              }

              if ((local_res20 == (undefined1 *)0x0) &&

                 (iVar8 = FUN_14019f070(param_1,puVar19,uVar21,uVar10), iVar8 == 0))

              goto LAB_1401a2e7c;

            }

            FUN_1401841e0(param_1[2]);

            param_1[2] = 0;

            FUN_14019f310(puVar2);

            if (*(code **)(puVar2 + 6) != (code *)0x0) {

              if (*(ulonglong *)(puVar2 + 0x30) < *(ulonglong *)(puVar2 + 0x32)) {

                (**(code **)(puVar2 + 6))

                          (*(undefined8 *)(puVar2 + 10),

                           (int)*(ulonglong *)(puVar2 + 0x30) - (int)*(ulonglong *)(puVar2 + 0x32));

                return 1;

              }

            }

            goto LAB_1401a2f81;

          }

        }

      }

LAB_1401a29bf:

      uVar11 = FUN_14019f050("Corrupt PNG");

      return uVar11;

    }

LAB_1401a2f81:

    uVar11 = 1;

  }

  return uVar11;

}




