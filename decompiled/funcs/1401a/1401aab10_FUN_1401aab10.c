// Address: 0x1401aab10
// Ghidra name: FUN_1401aab10
// ============ 0x1401aab10 FUN_1401aab10 (size=407) ============


int FUN_1401aab10(char *param_1,longlong param_2,int param_3)



{

  char *pcVar1;

  char cVar2;

  char cVar3;

  size_t sVar4;

  longlong lVar5;

  longlong lVar6;

  byte bVar7;

  longlong lVar8;

  int iVar9;

  int iVar10;

  int iVar11;

  

  bVar7 = 0;

  if (((param_1 == (char *)0x0) || (param_2 == 0)) || (param_3 < 0)) {

    return -1;

  }

  if (param_3 == 0) {

    sVar4 = strlen(param_1);

    param_3 = (int)sVar4;

  }

  iVar11 = 0;

  iVar10 = 0;

  iVar9 = 0;

  if (0 < param_3) {

    lVar8 = 0;

    lVar6 = 0;

    do {

      if (param_3 <= lVar6) break;

      if (iVar9 == 0) {

        if (param_1[lVar8] == '%') {

          bVar7 = 0;

          iVar9 = 1;

        }

        else {

          iVar10 = iVar10 + 1;

          *(char *)(lVar6 + param_2) = param_1[lVar8];

          lVar6 = lVar6 + 1;

        }

      }

      else if (iVar9 - 1U < 2) {

        cVar2 = param_1[lVar8];

        if (((byte)(cVar2 + 0x9fU) < 6) || ((byte)(cVar2 + 0xbfU) < 6)) {

          if ((byte)(cVar2 - 0x30U) < 10) goto LAB_1401aac1b;

          if ((byte)(cVar2 + 0x9fU) < 6) {

            cVar3 = -0x57;

          }

          else {

            cVar3 = '\0';

            if ((byte)(cVar2 + 0xbfU) < 6) {

              cVar3 = -0x37;

            }

          }

        }

        else {

          if (9 < (byte)(cVar2 - 0x30U)) {

            lVar5 = (longlong)(iVar11 - iVar9);

            if (lVar5 <= lVar8) {

              iVar10 = iVar10 + 1 + ((int)lVar8 - (iVar11 - iVar9));

              do {

                pcVar1 = param_1 + lVar5;

                lVar5 = lVar5 + 1;

                *(char *)(param_2 + lVar6) = *pcVar1;

                lVar6 = lVar6 + 1;

              } while (lVar5 <= lVar8);

            }

            iVar9 = 0;

            goto LAB_1401aac60;

          }

LAB_1401aac1b:

          cVar3 = -0x30;

        }

        bVar7 = bVar7 | cVar2 + cVar3 << (('\x02' - (char)iVar9) * '\x04' & 0x1fU);

        if (iVar9 == 2) {

          *(byte *)(lVar6 + param_2) = bVar7;

          iVar10 = iVar10 + 1;

          lVar6 = lVar6 + 1;

          iVar9 = 0;

        }

        else {

          iVar9 = iVar9 + 1;

        }

      }

LAB_1401aac60:

      iVar11 = iVar11 + 1;

      lVar8 = lVar8 + 1;

    } while (lVar8 < param_3);

  }

  *(undefined1 *)(iVar10 + param_2) = 0;

  return iVar10;

}




