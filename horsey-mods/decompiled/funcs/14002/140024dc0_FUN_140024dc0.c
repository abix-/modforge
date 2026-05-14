// Address: 0x140024dc0
// Ghidra name: FUN_140024dc0
// ============ 0x140024dc0 FUN_140024dc0 (size=762) ============


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */



void FUN_140024dc0(undefined8 *param_1,undefined8 *param_2)



{

  byte bVar1;

  longlong lVar2;

  undefined8 *puVar3;

  undefined8 *puVar4;

  longlong lVar5;

  int iVar6;

  char *pcVar7;

  int iVar8;

  longlong lVar9;

  ulonglong uVar10;

  undefined1 auStack_78 [32];

  ulonglong local_58;

  char local_48 [32];

  ulonglong local_28;

  

  local_28 = DAT_1403e8b00 ^ (ulonglong)auStack_78;

  iVar8 = 0;

  iVar6 = *(int *)(param_1 + 2);

  if (0 < iVar6) {

    do {

      uVar10 = param_1[3];

      puVar4 = param_1;

      if (0xf < uVar10) {

        puVar4 = (undefined8 *)*param_1;

      }

      bVar1 = *(byte *)((longlong)iVar8 + (longlong)puVar4);

      puVar4 = param_2;

      if (bVar1 == 0x26) {

        if (iVar6 + -2 <= iVar8) {

LAB_140024efb:

          uVar10 = (ulonglong)DAT_1403e9708;

          pcVar7 = PTR_DAT_1403e9700;

          goto LAB_140024f09;

        }

        puVar3 = param_1;

        if (0xf < uVar10) {

          puVar3 = (undefined8 *)*param_1;

        }

        if (*(char *)((longlong)iVar8 + 1 + (longlong)puVar3) != '#') goto LAB_140024efb;

        puVar3 = param_1;

        if (0xf < uVar10) {

          puVar3 = (undefined8 *)*param_1;

        }

        if (*(char *)((longlong)iVar8 + 2 + (longlong)puVar3) != 'x') goto LAB_140024efb;

        if (iVar8 < iVar6 + -1) {

          lVar9 = (longlong)iVar8;

          do {

            puVar4 = param_1;

            if (0xf < (ulonglong)param_1[3]) {

              puVar4 = (undefined8 *)*param_1;

            }

            uVar10 = param_2[2];

            if (param_2[3] == uVar10) {

              local_58 = 1;

              FUN_140027c80(param_2,1);

            }

            else {

              param_2[2] = uVar10 + 1;

              puVar3 = param_2;

              if (0xf < (ulonglong)param_2[3]) {

                puVar3 = (undefined8 *)*param_2;

              }

              *(undefined1 *)((longlong)puVar3 + uVar10) = *(undefined1 *)(lVar9 + (longlong)puVar4)

              ;

              *(undefined1 *)((longlong)puVar3 + uVar10 + 1) = 0;

            }

            iVar8 = iVar8 + 1;

            lVar9 = lVar9 + 1;

            puVar4 = param_1;

            if (0xf < (ulonglong)param_1[3]) {

              puVar4 = (undefined8 *)*param_1;

            }

          } while ((*(char *)(lVar9 + (longlong)puVar4) != ';') &&

                  (iVar8 < *(int *)(param_1 + 2) + -1));

        }

      }

      else {

        if (bVar1 == 0x3c) {

          uVar10 = (ulonglong)DAT_1403e9718;

          pcVar7 = PTR_DAT_1403e9710;

LAB_140024f09:

          lVar9 = param_2[2];

          if ((ulonglong)(param_2[3] - lVar9) < uVar10) {

            local_58 = uVar10;

            FUN_140027c80(param_2,uVar10);

          }

          else {

            param_2[2] = lVar9 + uVar10;

            if (0xf < (ulonglong)param_2[3]) {

              puVar4 = (undefined8 *)*param_2;

            }

LAB_140024f33:

            FUN_1402f8e20((longlong)puVar4 + lVar9,pcVar7,uVar10);

            *(undefined1 *)((longlong)puVar4 + lVar9 + uVar10) = 0;

          }

        }

        else {

          if (bVar1 == 0x3e) {

            uVar10 = (ulonglong)DAT_1403e9728;

            pcVar7 = PTR_DAT_1403e9720;

            goto LAB_140024f09;

          }

          if (bVar1 != 0x22) {

            if (bVar1 == 0x27) {

              FUN_140027810(param_2,PTR_s__apos__1403e9740,DAT_1403e9748);

              goto LAB_140025088;

            }

            if (0x1f < bVar1) {

              uVar10 = param_2[2];

              if (uVar10 < (ulonglong)param_2[3]) {

                param_2[2] = uVar10 + 1;

                if (0xf < (ulonglong)param_2[3]) {

                  puVar4 = (undefined8 *)*param_2;

                }

                *(byte *)((longlong)puVar4 + uVar10) = bVar1;

                *(undefined1 *)((longlong)puVar4 + uVar10 + 1) = 0;

              }

              else {

                FUN_1400280d0(param_2);

              }

              goto LAB_140025088;

            }

            FUN_140027670(local_48,0x20,"&#x%02X;");

            lVar9 = -1;

            do {

              lVar5 = lVar9 + 1;

              lVar2 = lVar9 + 1;

              lVar9 = lVar5;

            } while (local_48[lVar2] != '\0');

            lVar9 = param_2[2];

            uVar10 = (ulonglong)(int)lVar5;

            if ((ulonglong)(param_2[3] - lVar9) < uVar10) {

              local_58 = uVar10;

              FUN_140027c80(param_2,uVar10);

              goto LAB_140025088;

            }

            param_2[2] = lVar9 + uVar10;

            if (0xf < (ulonglong)param_2[3]) {

              puVar4 = (undefined8 *)*param_2;

            }

            pcVar7 = local_48;

            goto LAB_140024f33;

          }

          FUN_140027810(param_2,PTR_s__quot__1403e9730,DAT_1403e9738);

        }

LAB_140025088:

        iVar8 = iVar8 + 1;

      }

      iVar6 = *(int *)(param_1 + 2);

    } while (iVar8 < iVar6);

  }

  return;

}




