// Address: 0x140054a60
// Ghidra name: FUN_140054a60
// ============ 0x140054a60 FUN_140054a60 (size=1525) ============


undefined8 FUN_140054a60(longlong param_1,int *param_2,uint *param_3)



{

  char *pcVar1;

  byte *pbVar2;

  uint uVar3;

  uint uVar4;

  uint uVar5;

  byte bVar6;

  byte bVar7;

  byte bVar8;

  byte bVar9;

  int iVar10;

  uint uVar11;

  char cVar12;

  uint uVar13;

  ulonglong uVar14;

  int iVar15;

  uint uVar16;

  ulonglong uVar17;

  longlong lVar18;

  char *pcVar19;

  ulonglong uVar20;

  int iVar21;

  char local_54 [4];

  byte local_50;

  byte local_4f;

  byte local_4e;

  byte local_4d;

  byte local_4c;

  byte local_4b;

  byte local_4a;

  byte local_49;

  byte local_48;

  byte local_47;

  byte local_46;

  byte local_45;

  byte local_44;

  byte local_43;

  byte local_42;

  byte local_41;

  byte local_40;

  byte local_3f;

  byte local_3e;

  

  iVar15 = *(int *)(param_1 + 0x98);

  do {

    if (iVar15 != 0) {

      return 0;

    }

    pcVar19 = *(char **)(param_1 + 0x40);

    if (pcVar19 == (char *)0x0) {

      iVar15 = FUN_1402ce36c(*(undefined8 *)(param_1 + 0x30));

      cVar12 = (char)iVar15;

      if (iVar15 == -1) goto LAB_140054add;

LAB_140054ab9:

      if (cVar12 == 'O') {

        if (*(char *)(param_1 + 0x5c) == '\0') {

          if (*(longlong *)(param_1 + 0x40) == 0) {

            iVar15 = *(int *)(param_1 + 0x38);

            iVar21 = FUN_1402cf00c();

            iVar21 = iVar21 - iVar15;

          }

          else {

            iVar21 = (int)*(longlong *)(param_1 + 0x40) - *(int *)(param_1 + 0x48);

          }

        }

        else {

          iVar21 = 0;

        }

        if (*(uint *)(param_1 + 0x58) < iVar21 - 0x19U) {

          return 0;

        }

        iVar15 = 1;

        lVar18 = 1;

        do {

          pcVar19 = *(char **)(param_1 + 0x40);

          if (pcVar19 == (char *)0x0) {

            iVar10 = FUN_1402ce36c(*(undefined8 *)(param_1 + 0x30));

            cVar12 = (char)iVar10;

            if (iVar10 == -1) goto LAB_140054b4b;

          }

          else if (pcVar19 < *(char **)(param_1 + 0x50)) {

            cVar12 = *pcVar19;

            *(char **)(param_1 + 0x40) = pcVar19 + 1;

          }

          else {

LAB_140054b4b:

            cVar12 = '\0';

            *(undefined4 *)(param_1 + 0x98) = 1;

          }

          bVar9 = DAT_1403d45db;

          bVar8 = DAT_1403d45da;

          bVar7 = DAT_1403d45d9;

          bVar6 = DAT_1403d45d8;

          if (cVar12 != (&DAT_1403d45d8)[lVar18]) break;

          iVar15 = iVar15 + 1;

          lVar18 = lVar18 + 1;

        } while (lVar18 < 4);

        if (*(int *)(param_1 + 0x98) != 0) {

          return 0;

        }

        if (iVar15 == 4) {

          pcVar19 = local_54;

          lVar18 = 0x17;

          do {

            pcVar1 = *(char **)(param_1 + 0x40);

            if (pcVar1 == (char *)0x0) {

              iVar15 = FUN_1402ce36c(*(undefined8 *)(param_1 + 0x30));

              cVar12 = (char)iVar15;

              if (iVar15 == -1) goto LAB_140054bde;

            }

            else if (pcVar1 < *(char **)(param_1 + 0x50)) {

              cVar12 = *pcVar1;

              *(char **)(param_1 + 0x40) = pcVar1 + 1;

            }

            else {

LAB_140054bde:

              cVar12 = '\0';

              *(undefined4 *)(param_1 + 0x98) = 1;

            }

            *pcVar19 = cVar12;

            pcVar19 = pcVar19 + 1;

            lVar18 = lVar18 + -1;

          } while (lVar18 != 0);

          if (*(int *)(param_1 + 0x98) != 0) {

            return 0;

          }

          if (local_54[0] == '\0') {

            uVar20 = (ulonglong)(byte)local_54[1];

            uVar3 = (uint)local_40;

            uVar4 = (uint)local_41;

            uVar5 = (uint)local_3f;

            uVar11 = (uint)local_42;

            uVar13 = (&DAT_1403ea2f0)[bVar6] << 8 ^

                     (&DAT_1403ea2f0)

                     [(ulonglong)((uint)(&DAT_1403ea2f0)[bVar6] >> 0x18) ^ (ulonglong)bVar7];

            uVar13 = uVar13 << 8 ^ (&DAT_1403ea2f0)[(ulonglong)(uVar13 >> 0x18) ^ (ulonglong)bVar8];

            uVar13 = uVar13 << 8 ^ (&DAT_1403ea2f0)[(ulonglong)(uVar13 >> 0x18) ^ (ulonglong)bVar9];

            uVar13 = uVar13 << 8 ^ (&DAT_1403ea2f0)[uVar13 >> 0x18];

            uVar13 = uVar13 << 8 ^ (&DAT_1403ea2f0)[uVar13 >> 0x18 ^ uVar20];

            uVar13 = uVar13 << 8 ^

                     (&DAT_1403ea2f0)[(ulonglong)(uVar13 >> 0x18) ^ (ulonglong)(byte)local_54[2]];

            uVar13 = uVar13 << 8 ^

                     (&DAT_1403ea2f0)[(ulonglong)(uVar13 >> 0x18) ^ (ulonglong)(byte)local_54[3]];

            uVar13 = uVar13 << 8 ^

                     (&DAT_1403ea2f0)[(ulonglong)(uVar13 >> 0x18) ^ (ulonglong)local_50];

            uVar13 = uVar13 << 8 ^

                     (&DAT_1403ea2f0)[(ulonglong)(uVar13 >> 0x18) ^ (ulonglong)local_4f];

            uVar13 = uVar13 << 8 ^

                     (&DAT_1403ea2f0)[(ulonglong)(uVar13 >> 0x18) ^ (ulonglong)local_4e];

            uVar13 = uVar13 << 8 ^

                     (&DAT_1403ea2f0)[(ulonglong)(uVar13 >> 0x18) ^ (ulonglong)local_4d];

            uVar13 = uVar13 << 8 ^

                     (&DAT_1403ea2f0)[(ulonglong)(uVar13 >> 0x18) ^ (ulonglong)local_4c];

            uVar13 = uVar13 << 8 ^

                     (&DAT_1403ea2f0)[(ulonglong)(uVar13 >> 0x18) ^ (ulonglong)local_4b];

            uVar13 = uVar13 << 8 ^

                     (&DAT_1403ea2f0)[(ulonglong)(uVar13 >> 0x18) ^ (ulonglong)local_4a];

            uVar13 = uVar13 << 8 ^

                     (&DAT_1403ea2f0)[(ulonglong)(uVar13 >> 0x18) ^ (ulonglong)local_49];

            uVar13 = uVar13 << 8 ^

                     (&DAT_1403ea2f0)[(ulonglong)(uVar13 >> 0x18) ^ (ulonglong)local_48];

            uVar13 = uVar13 << 8 ^

                     (&DAT_1403ea2f0)[(ulonglong)(uVar13 >> 0x18) ^ (ulonglong)local_47];

            uVar13 = uVar13 << 8 ^

                     (&DAT_1403ea2f0)[(ulonglong)(uVar13 >> 0x18) ^ (ulonglong)local_46];

            uVar13 = uVar13 << 8 ^

                     (&DAT_1403ea2f0)[(ulonglong)(uVar13 >> 0x18) ^ (ulonglong)local_45];

            uVar13 = uVar13 << 8 ^

                     (&DAT_1403ea2f0)[(ulonglong)(uVar13 >> 0x18) ^ (ulonglong)local_44];

            uVar13 = uVar13 << 8 ^

                     (&DAT_1403ea2f0)[(ulonglong)(uVar13 >> 0x18) ^ (ulonglong)local_43];

            uVar13 = uVar13 << 8 ^ (&DAT_1403ea2f0)[uVar13 >> 0x18];

            uVar13 = uVar13 << 8 ^ (&DAT_1403ea2f0)[uVar13 >> 0x18];

            uVar13 = uVar13 << 8 ^ (&DAT_1403ea2f0)[uVar13 >> 0x18];

            uVar13 = uVar13 << 8 ^ (&DAT_1403ea2f0)[uVar13 >> 0x18];

            uVar13 = uVar13 << 8 ^

                     (&DAT_1403ea2f0)[(ulonglong)(uVar13 >> 0x18) ^ (ulonglong)local_3e];

            uVar17 = 0;

            if (local_3e != 0) {

              uVar20 = (ulonglong)local_3e;

              do {

                pbVar2 = *(byte **)(param_1 + 0x40);

                if (pbVar2 == (byte *)0x0) {

                  uVar16 = FUN_1402ce36c(*(undefined8 *)(param_1 + 0x30));

                  uVar14 = (ulonglong)uVar16;

                  if (uVar16 == 0xffffffff) goto LAB_140054f10;

                }

                else if (pbVar2 < *(byte **)(param_1 + 0x50)) {

                  uVar14 = (ulonglong)*pbVar2;

                  *(byte **)(param_1 + 0x40) = pbVar2 + 1;

                }

                else {

LAB_140054f10:

                  uVar14 = 0;

                  *(undefined4 *)(param_1 + 0x98) = 1;

                }

                uVar16 = (int)uVar17 + ((uint)uVar14 & 0xff);

                uVar17 = (ulonglong)uVar16;

                uVar13 = uVar13 << 8 ^ (&DAT_1403ea2f0)[(ulonglong)(uVar13 >> 0x18) ^ uVar14 & 0xff]

                ;

                uVar20 = uVar20 - 1;

              } while (uVar20 != 0);

              if (uVar16 != 0) {

                if (*(int *)(param_1 + 0x98) != 0) {

                  return 0;

                }

                if (uVar16 != 0) {

                  do {

                    pbVar2 = *(byte **)(param_1 + 0x40);

                    if (pbVar2 == (byte *)0x0) {

                      uVar16 = FUN_1402ce36c(*(undefined8 *)(param_1 + 0x30));

                      uVar20 = (ulonglong)uVar16;

                      if (uVar16 == 0xffffffff) goto LAB_140054f8b;

                    }

                    else if (pbVar2 < *(byte **)(param_1 + 0x50)) {

                      uVar20 = (ulonglong)*pbVar2;

                      *(byte **)(param_1 + 0x40) = pbVar2 + 1;

                    }

                    else {

LAB_140054f8b:

                      uVar20 = 0;

                      *(undefined4 *)(param_1 + 0x98) = 1;

                    }

                    uVar13 = uVar13 << 8 ^

                             (&DAT_1403ea2f0)[(ulonglong)(uVar13 >> 0x18) ^ uVar20 & 0xff];

                    uVar17 = uVar17 - 1;

                  } while (uVar17 != 0);

                }

              }

              uVar20 = (ulonglong)(byte)local_54[1];

            }

            iVar15 = 0;

            if (uVar13 == uVar4 * 0x100 + uVar3 * 0x10000 + uVar5 * 0x1000000 + uVar11) {

              if (param_2 != (int *)0x0) {

                if (*(char *)(param_1 + 0x5c) == '\0') {

                  if (*(longlong *)(param_1 + 0x40) == 0) {

                    iVar10 = *(int *)(param_1 + 0x38);

                    iVar15 = FUN_1402cf00c(*(undefined8 *)(param_1 + 0x30));

                    iVar15 = iVar15 - iVar10;

                  }

                  else {

                    iVar15 = (int)*(longlong *)(param_1 + 0x40) - *(int *)(param_1 + 0x48);

                  }

                }

                *param_2 = iVar15;

              }

              if (param_3 != (uint *)0x0) {

                *param_3 = (uint)(uVar20 >> 2) & 1;

              }

              FUN_140050920(param_1,iVar21 + -1);

              return 1;

            }

          }

        }

        FUN_140050920(param_1,iVar21);

      }

    }

    else {

      if (pcVar19 < *(char **)(param_1 + 0x50)) {

        cVar12 = *pcVar19;

        *(char **)(param_1 + 0x40) = pcVar19 + 1;

        goto LAB_140054ab9;

      }

LAB_140054add:

      *(undefined4 *)(param_1 + 0x98) = 1;

    }

    iVar15 = *(int *)(param_1 + 0x98);

  } while( true );

}




