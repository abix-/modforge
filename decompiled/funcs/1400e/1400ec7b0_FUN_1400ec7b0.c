// Address: 0x1400ec7b0
// Ghidra name: FUN_1400ec7b0
// ============ 0x1400ec7b0 FUN_1400ec7b0 (size=1170) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined8 FUN_1400ec7b0(undefined8 *param_1,int param_2)



{

  char cVar1;

  byte bVar2;

  uint *puVar3;

  int iVar4;

  uint uVar5;

  uint uVar6;

  char *pcVar7;

  undefined8 *puVar8;

  byte *pbVar9;

  longlong lVar10;

  ulonglong uVar11;

  uint *puVar12;

  uint uVar13;

  uint uVar14;

  uint uVar15;

  

  puVar3 = (uint *)*param_1;

  uVar15 = 1;

  uVar6 = 1;

  iVar4 = FUN_1400e8ad0(puVar3);

  if (iVar4 < 0xb) {

LAB_1400ecc2d:

    _DAT_1403f4c40 = "bad SOF len";

  }

  else {

    pcVar7 = *(char **)(puVar3 + 0x2e);

    if (pcVar7 < *(char **)(puVar3 + 0x30)) {

LAB_1400ec816:

      cVar1 = *pcVar7;

      *(char **)(puVar3 + 0x2e) = pcVar7 + 1;

      if (cVar1 == '\b') {

        uVar5 = FUN_1400e8ad0(puVar3);

        puVar3[1] = uVar5;

        if (uVar5 == 0) {

          _DAT_1403f4c40 = "no header height";

          return 0;

        }

        uVar5 = FUN_1400e8ad0(puVar3);

        *puVar3 = uVar5;

        if (uVar5 == 0) {

          _DAT_1403f4c40 = "0 width";

          return 0;

        }

        pbVar9 = *(byte **)(puVar3 + 0x2e);

        if (*(byte **)(puVar3 + 0x30) <= pbVar9) {

          if (puVar3[0xc] == 0) goto LAB_1400ecc03;

          FUN_1400ed820(puVar3);

          pbVar9 = *(byte **)(puVar3 + 0x2e);

        }

        bVar2 = *pbVar9;

        *(byte **)(puVar3 + 0x2e) = pbVar9 + 1;

        uVar11 = (ulonglong)bVar2;

        if ((bVar2 != 3) && (bVar2 != 1)) {

LAB_1400ecc03:

          _DAT_1403f4c40 = "bad component count";

          return 0;

        }

        puVar3[2] = (uint)bVar2;

        if (bVar2 != 0) {

          puVar8 = param_1 + 0x6bc;

          do {

            puVar8[-2] = 0;

            *puVar8 = 0;

            puVar8 = puVar8 + 9;

            uVar11 = uVar11 - 1;

          } while (uVar11 != 0);

        }

        uVar5 = puVar3[2];

        if (iVar4 == uVar5 * 3 + 8) {

          if (0 < (int)uVar5) {

            puVar12 = (uint *)((longlong)param_1 + 0x35a4);

            uVar13 = 0;

            do {

              pbVar9 = *(byte **)(puVar3 + 0x2e);

              if (pbVar9 < *(byte **)(puVar3 + 0x30)) {

                bVar2 = *pbVar9;

                *(byte **)(puVar3 + 0x2e) = pbVar9 + 1;

                uVar5 = (uint)bVar2;

              }

              else if (puVar3[0xc] == 0) {

                uVar5 = 0;

              }

              else {

                FUN_1400ed820(puVar3);

                bVar2 = **(byte **)(puVar3 + 0x2e);

                *(byte **)(puVar3 + 0x2e) = *(byte **)(puVar3 + 0x2e) + 1;

                uVar5 = (uint)bVar2;

              }

              uVar14 = uVar13 + 1;

              puVar12[-1] = uVar5;

              if ((uVar5 != uVar14) && (uVar5 != uVar13)) {

                _DAT_1403f4c40 = "bad component ID";

                return 0;

              }

              pbVar9 = *(byte **)(puVar3 + 0x2e);

              if (*(byte **)(puVar3 + 0x30) <= pbVar9) {

                if (puVar3[0xc] == 0) {

                  *puVar12 = 0;

                  goto LAB_1400eca94;

                }

                FUN_1400ed820(puVar3);

                pbVar9 = *(byte **)(puVar3 + 0x2e);

              }

              bVar2 = *pbVar9;

              *(byte **)(puVar3 + 0x2e) = pbVar9 + 1;

              uVar5 = (uint)(bVar2 >> 4);

              *puVar12 = uVar5;

              if (3 < uVar5 - 1) {

LAB_1400eca94:

                _DAT_1403f4c40 = "bad H";

                return 0;

              }

              uVar5 = bVar2 & 0xf;

              puVar12[1] = uVar5;

              if (3 < uVar5 - 1) {

                _DAT_1403f4c40 = "bad V";

                return 0;

              }

              pbVar9 = *(byte **)(puVar3 + 0x2e);

              if (pbVar9 < *(byte **)(puVar3 + 0x30)) {

LAB_1400ec9f0:

                bVar2 = *pbVar9;

                *(byte **)(puVar3 + 0x2e) = pbVar9 + 1;

                puVar12[2] = (uint)bVar2;

                if (3 < bVar2) {

                  _DAT_1403f4c40 = "bad TQ";

                  return 0;

                }

              }

              else {

                if (puVar3[0xc] != 0) {

                  FUN_1400ed820(puVar3);

                  pbVar9 = *(byte **)(puVar3 + 0x2e);

                  goto LAB_1400ec9f0;

                }

                puVar12[2] = 0;

              }

              uVar5 = puVar3[2];

              puVar12 = puVar12 + 0x12;

              uVar13 = uVar14;

            } while ((int)uVar14 < (int)uVar5);

          }

          iVar4 = 0;

          if (param_2 == 0) {

            if ((uint)((0x40000000 / (ulonglong)*puVar3) / (ulonglong)uVar5) < puVar3[1]) {

              _DAT_1403f4c40 = "too large";

              return 0;

            }

            if (0 < (int)uVar5) {

              uVar11 = (ulonglong)uVar5;

              puVar12 = (uint *)(param_1 + 0x6b5);

              uVar5 = 1;

              do {

                uVar6 = puVar12[-1];

                if ((int)puVar12[-1] <= (int)uVar15) {

                  uVar6 = uVar15;

                }

                uVar15 = uVar6;

                uVar6 = *puVar12;

                if ((int)*puVar12 <= (int)uVar5) {

                  uVar6 = uVar5;

                }

                uVar11 = uVar11 - 1;

                puVar12 = puVar12 + 0x12;

                uVar5 = uVar6;

              } while (uVar11 != 0);

            }

            *(uint *)(param_1 + 0x6b1) = uVar15;

            uVar5 = uVar15 * 8;

            *(uint *)((longlong)param_1 + 0x358c) = uVar6;

            uVar13 = uVar6 * 8;

            *(uint *)(param_1 + 0x6b3) = uVar5;

            *(uint *)((longlong)param_1 + 0x359c) = uVar13;

            *(uint *)(param_1 + 0x6b2) = ((*puVar3 - 1) + uVar5) / uVar5;

            *(uint *)((longlong)param_1 + 0x3594) = ((puVar3[1] - 1) + uVar13) / uVar13;

            if (0 < (int)puVar3[2]) {

              puVar12 = (uint *)((longlong)param_1 + 0x35bc);

              do {

                *puVar12 = (puVar12[-6] * *puVar3 + -1 + uVar15) / uVar15;

                puVar12[1] = (puVar12[-5] * puVar3[1] + -1 + uVar6) / uVar6;

                uVar13 = puVar12[-6] * *(int *)(param_1 + 0x6b2) * 8;

                puVar12[2] = uVar13;

                uVar5 = puVar12[-5] * *(int *)((longlong)param_1 + 0x3594) * 8;

                puVar12[3] = uVar5;

                lVar10 = _malloc_base((longlong)(int)(uVar5 * uVar13) + 0xf);

                *(longlong *)(puVar12 + 7) = lVar10;

                if (lVar10 == 0) {

                  lVar10 = (longlong)(iVar4 + -1);

                  if (-1 < iVar4 + -1) {

                    param_1 = param_1 + lVar10 * 9 + 0x6ba;

                    do {

                      thunk_FUN_1402e9a80(param_1[1]);

                      lVar10 = lVar10 + -1;

                      *param_1 = 0;

                      param_1 = param_1 + -9;

                    } while (-1 < lVar10);

                  }

                  _DAT_1403f4c40 = "outofmem";

                  return 0;

                }

                puVar12[9] = 0;

                puVar12[10] = 0;

                iVar4 = iVar4 + 1;

                *(ulonglong *)(puVar12 + 5) = lVar10 + 0xfU & 0xfffffffffffffff0;

                puVar12 = puVar12 + 0x12;

              } while (iVar4 < (int)puVar3[2]);

            }

          }

          return 1;

        }

        goto LAB_1400ecc2d;

      }

    }

    else if (puVar3[0xc] != 0) {

      FUN_1400ed820(puVar3);

      pcVar7 = *(char **)(puVar3 + 0x2e);

      goto LAB_1400ec816;

    }

    _DAT_1403f4c40 = "only 8-bit";

  }

  return 0;

}




