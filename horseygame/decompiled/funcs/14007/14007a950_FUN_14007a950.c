// Address: 0x14007a950
// Ghidra name: FUN_14007a950
// ============ 0x14007a950 FUN_14007a950 (size=698) ============


void FUN_14007a950(undefined8 *param_1,int param_2,int param_3,uint param_4,int param_5,int param_6,

                  longlong param_7,int param_8,undefined4 param_9,int param_10)



{

  byte bVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  undefined8 uVar7;

  byte *pbVar8;

  longlong lVar9;

  byte *pbVar10;

  undefined8 uVar11;

  longlong lVar12;

  ulonglong uVar13;

  byte local_58;

  undefined1 local_57;

  undefined1 local_56;

  byte local_54;

  byte local_53;

  byte local_52;

  byte local_50;

  byte local_4f;

  byte local_4e;

  int local_4c;

  int local_48;

  undefined4 local_44;

  int local_40;

  int local_3c;

  

  iVar4 = param_8;

  iVar3 = param_6;

  local_44 = 0;

  if (0 < param_5) {

    local_4c = param_5 + -1;

    if (-1 < param_3) {

      local_4c = 0;

    }

    local_3c = -1;

    if (-1 < param_3) {

      local_3c = param_5;

    }

    if (local_4c != local_3c) {

      lVar9 = (longlong)param_6;

      local_48 = local_4c * param_4 * param_6;

      lVar12 = (longlong)param_2;

      local_40 = param_3 * param_4 * param_6;

      do {

        if (0 < (int)param_4) {

          pbVar10 = (byte *)(local_48 + param_7);

          uVar13 = (ulonglong)param_4;

          do {

            if (iVar4 < 0) {

              (*(code *)*param_1)(param_1[1],pbVar10 + (iVar3 + -1),1);

            }

            iVar2 = param_5;

            pbVar8 = pbVar10;

            if (iVar3 == 1) {

              uVar11 = 1;

LAB_14007ab6c:

              uVar7 = param_1[1];

LAB_14007ab70:

              (*(code *)*param_1)(uVar7,pbVar8,uVar11);

LAB_14007ab75:

              if (0 < iVar4) {

                uVar11 = 1;

                pbVar8 = pbVar10 + (iVar3 + -1);

                goto LAB_14007ab85;

              }

            }

            else {

              if (iVar3 == 2) {

                uVar7 = param_1[1];

                if (param_10 == 0) {

                  uVar11 = 1;

                }

                else {

                  local_50 = *pbVar10;

                  uVar11 = 3;

                  pbVar8 = &local_50;

                  local_4f = local_50;

                  local_4e = local_50;

                }

                goto LAB_14007ab70;

              }

              if (iVar3 == 3) {

LAB_14007ab01:

                uVar11 = 3;

                local_54 = pbVar10[1 - lVar12];

                local_53 = pbVar10[1];

                local_52 = pbVar10[lVar12 + 1];

                pbVar8 = &local_54;

                goto LAB_14007ab6c;

              }

              if (iVar3 != 4) goto LAB_14007ab75;

              if (iVar4 != 0) goto LAB_14007ab01;

              bVar1 = pbVar10[3];

              iVar5 = (*pbVar10 - 0xff) * (uint)bVar1;

              iVar6 = (pbVar10[2] - 0xff) * (uint)bVar1;

              local_57 = (undefined1)(((uint)pbVar10[1] * (uint)bVar1) / 0xff);

              uVar11 = 3;

              param_5._3_1_ = SUB41(iVar2,3);

              param_5._0_3_ =

                   CONCAT12((((char)(iVar6 / 0xff) + (char)(iVar6 >> 0x1f)) -

                            (char)((longlong)iVar6 * 0x80808081 >> 0x3f)) + -1,

                            CONCAT11(local_57,(((char)(iVar5 / 0xff) + (char)(iVar5 >> 0x1f)) -

                                              (char)((longlong)iVar5 * 0x80808081 >> 0x3f)) + -1));

              pbVar8 = &local_58;

              local_58 = *(byte *)((longlong)&param_5 + (1 - lVar12));

              local_56 = *(undefined1 *)((longlong)&param_5 + lVar12 + 1);

LAB_14007ab85:

              (*(code *)*param_1)(param_1[1],pbVar8,uVar11);

            }

            pbVar10 = pbVar10 + lVar9;

            uVar13 = uVar13 - 1;

          } while (uVar13 != 0);

        }

        (*(code *)*param_1)(param_1[1],&local_44,param_9);

        local_4c = local_4c + param_3;

        local_48 = local_48 + local_40;

      } while (local_4c != local_3c);

    }

  }

  return;

}




