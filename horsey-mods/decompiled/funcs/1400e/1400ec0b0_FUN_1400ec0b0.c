// Address: 0x1400ec0b0
// Ghidra name: FUN_1400ec0b0
// ============ 0x1400ec0b0 FUN_1400ec0b0 (size=1558) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



longlong FUN_1400ec0b0(longlong param_1,uint param_2,int param_3,int *param_4,longlong param_5)



{

  uint uVar1;

  int iVar2;

  uint uVar3;

  longlong lVar4;

  byte bVar5;

  ulonglong uVar6;

  byte *pbVar7;

  byte bVar8;

  undefined1 *puVar9;

  byte bVar10;

  byte bVar11;

  byte *pbVar12;

  longlong lVar13;

  undefined4 local_78;

  undefined4 local_74;

  int local_70;

  int local_6c;

  longlong local_68;

  undefined1 *local_60;

  byte local_58 [2];

  byte local_56 [30];

  

  bVar11 = 0;

  local_68 = 0;

  pbVar12 = local_58;

  do {

    if (local_68 == 10) {

LAB_1400ec68d:

      _DAT_1403f4c40 = "bad format";

      return 0;

    }

    pbVar7 = *(byte **)(param_1 + 0xb8);

    local_68 = local_68 + 1;

    if (pbVar7 < *(byte **)(param_1 + 0xc0)) {

      bVar10 = *pbVar7;

      pbVar7 = pbVar7 + 1;

      *(byte **)(param_1 + 0xb8) = pbVar7;

    }

    else if (*(int *)(param_1 + 0x30) == 0) {

      bVar10 = 0;

    }

    else {

      FUN_1400ed820(param_1);

      bVar10 = **(byte **)(param_1 + 0xb8);

      pbVar7 = *(byte **)(param_1 + 0xb8) + 1;

      *(byte **)(param_1 + 0xb8) = pbVar7;

    }

    if (pbVar7 < *(byte **)(param_1 + 0xc0)) {

      bVar8 = *pbVar7;

      pbVar7 = pbVar7 + 1;

      *(byte **)(param_1 + 0xb8) = pbVar7;

    }

    else if (*(int *)(param_1 + 0x30) == 0) {

      bVar8 = 0;

    }

    else {

      FUN_1400ed820();

      bVar8 = **(byte **)(param_1 + 0xb8);

      pbVar7 = *(byte **)(param_1 + 0xb8) + 1;

      *(byte **)(param_1 + 0xb8) = pbVar7;

    }

    *pbVar12 = bVar8;

    if (pbVar7 < *(byte **)(param_1 + 0xc0)) {

      bVar5 = *pbVar7;

      pbVar7 = pbVar7 + 1;

      *(byte **)(param_1 + 0xb8) = pbVar7;

    }

    else if (*(int *)(param_1 + 0x30) == 0) {

      bVar5 = 0;

    }

    else {

      FUN_1400ed820(param_1);

      bVar5 = **(byte **)(param_1 + 0xb8);

      pbVar7 = *(byte **)(param_1 + 0xb8) + 1;

      *(byte **)(param_1 + 0xb8) = pbVar7;

    }

    pbVar12[1] = bVar5;

    if (pbVar7 < *(byte **)(param_1 + 0xc0)) {

      bVar5 = *pbVar7;

      *(byte **)(param_1 + 0xb8) = pbVar7 + 1;

    }

    else if (*(int *)(param_1 + 0x30) == 0) {

      bVar5 = 0;

    }

    else {

      FUN_1400ed820(param_1);

      bVar5 = **(byte **)(param_1 + 0xb8);

      *(byte **)(param_1 + 0xb8) = *(byte **)(param_1 + 0xb8) + 1;

    }

    pbVar12[2] = bVar5;

    bVar11 = bVar11 | bVar5;

    if (*(longlong *)(param_1 + 0x10) == 0) {

LAB_1400ec255:

      if (*(ulonglong *)(param_1 + 0xc0) <= *(ulonglong *)(param_1 + 0xb8)) goto LAB_1400ec684;

    }

    else {

      iVar2 = (**(code **)(param_1 + 0x20))(*(undefined8 *)(param_1 + 0x28));

      if (iVar2 != 0) {

        if (*(int *)(param_1 + 0x30) != 0) goto LAB_1400ec255;

LAB_1400ec684:

        _DAT_1403f4c40 = "bad file";

        return 0;

      }

    }

    if (bVar8 != 8) goto LAB_1400ec68d;

    pbVar12 = pbVar12 + 3;

    if (bVar10 == 0) {

      *param_4 = ((bVar11 & 0x10) != 0) + 3;

      local_70 = 0;

      if (param_3 < 1) {

        return param_5;

      }

      local_6c = 0;

      lVar4 = local_68;

      do {

        lVar13 = 0;

        if (0 < lVar4) {

          pbVar12 = local_56;

          local_60 = (undefined1 *)(local_6c + param_5);

          do {

            bVar11 = pbVar12[-1];

            if (bVar11 == 0) {

              iVar2 = 0;

              if (0 < (int)param_2) {

                bVar11 = *pbVar12;

                puVar9 = local_60;

                do {

                  lVar4 = FUN_1400ec6d0(param_1,bVar11,puVar9);

                  if (lVar4 == 0) {

                    return 0;

                  }

                  iVar2 = iVar2 + 1;

                  puVar9 = puVar9 + 4;

                } while (iVar2 < (int)param_2);

              }

            }

            else {

              uVar1 = param_2;

              puVar9 = local_60;

              if (bVar11 == 1) {

                for (; 0 < (int)uVar1; uVar1 = uVar1 - bVar11) {

                  pbVar7 = *(byte **)(param_1 + 0xb8);

                  if (pbVar7 < *(byte **)(param_1 + 0xc0)) {

                    bVar11 = *pbVar7;

                    *(byte **)(param_1 + 0xb8) = pbVar7 + 1;

                  }

                  else if (*(int *)(param_1 + 0x30) == 0) {

                    bVar11 = 0;

                  }

                  else {

                    FUN_1400ed820(param_1);

                    bVar11 = **(byte **)(param_1 + 0xb8);

                    *(byte **)(param_1 + 0xb8) = *(byte **)(param_1 + 0xb8) + 1;

                  }

                  if (*(longlong *)(param_1 + 0x10) == 0) {

LAB_1400ec541:

                    if (*(ulonglong *)(param_1 + 0xc0) <= *(ulonglong *)(param_1 + 0xb8))

                    goto LAB_1400ec684;

                  }

                  else {

                    iVar2 = (**(code **)(param_1 + 0x20))(*(undefined8 *)(param_1 + 0x28));

                    if (iVar2 != 0) {

                      if (*(int *)(param_1 + 0x30) != 0) goto LAB_1400ec541;

                      goto LAB_1400ec684;

                    }

                  }

                  bVar10 = *pbVar12;

                  if (uVar1 < bVar11) {

                    bVar11 = (byte)uVar1;

                  }

                  lVar4 = FUN_1400ec6d0(param_1,bVar10,&local_74);

                  if (lVar4 == 0) {

                    return 0;

                  }

                  if (bVar11 != 0) {

                    uVar6 = (ulonglong)bVar11;

                    do {

                      if ((bVar10 & 0x80) != 0) {

                        *puVar9 = (char)local_74;

                      }

                      if ((bVar10 & 0x40) != 0) {

                        puVar9[1] = local_74._1_1_;

                      }

                      if ((bVar10 & 0x20) != 0) {

                        puVar9[2] = local_74._2_1_;

                      }

                      if ((bVar10 & 0x10) != 0) {

                        puVar9[3] = local_74._3_1_;

                      }

                      puVar9 = puVar9 + 4;

                      uVar6 = uVar6 - 1;

                    } while (uVar6 != 0);

                  }

                }

              }

              else {

                if (bVar11 != 2) goto LAB_1400ec68d;

                for (; 0 < (int)uVar1; uVar1 = uVar1 - uVar3) {

                  pbVar7 = *(byte **)(param_1 + 0xb8);

                  if (pbVar7 < *(byte **)(param_1 + 0xc0)) {

                    uVar3 = (uint)*pbVar7;

                    *(byte **)(param_1 + 0xb8) = pbVar7 + 1;

                  }

                  else if (*(int *)(param_1 + 0x30) == 0) {

                    uVar3 = 0;

                  }

                  else {

                    FUN_1400ed820(param_1);

                    uVar3 = (uint)**(byte **)(param_1 + 0xb8);

                    *(byte **)(param_1 + 0xb8) = *(byte **)(param_1 + 0xb8) + 1;

                  }

                  if (*(longlong *)(param_1 + 0x10) == 0) {

LAB_1400ec3a0:

                    if (*(ulonglong *)(param_1 + 0xc0) <= *(ulonglong *)(param_1 + 0xb8))

                    goto LAB_1400ec684;

                  }

                  else {

                    iVar2 = (**(code **)(param_1 + 0x20))(*(undefined8 *)(param_1 + 0x28));

                    if (iVar2 != 0) {

                      if (*(int *)(param_1 + 0x30) != 0) goto LAB_1400ec3a0;

                      goto LAB_1400ec684;

                    }

                  }

                  if (uVar3 < 0x80) {

                    uVar3 = uVar3 + 1;

                    if (uVar1 < uVar3) goto LAB_1400ec684;

                    iVar2 = 0;

                    if (uVar3 != 0) {

                      bVar11 = *pbVar12;

                      do {

                        lVar4 = FUN_1400ec6d0(param_1,bVar11,puVar9);

                        if (lVar4 == 0) {

                          return 0;

                        }

                        iVar2 = iVar2 + 1;

                        puVar9 = puVar9 + 4;

                      } while (iVar2 < (int)uVar3);

                    }

                  }

                  else {

                    if (uVar3 == 0x80) {

                      uVar3 = FUN_1400e8ad0(param_1);

                    }

                    else {

                      uVar3 = uVar3 - 0x7f;

                    }

                    uVar6 = (ulonglong)uVar3;

                    if ((int)uVar1 < (int)uVar3) goto LAB_1400ec684;

                    bVar11 = *pbVar12;

                    lVar4 = FUN_1400ec6d0(param_1,bVar11,&local_78);

                    if (lVar4 == 0) {

                      return 0;

                    }

                    if (0 < (int)uVar3) {

                      do {

                        if ((bVar11 & 0x80) != 0) {

                          *puVar9 = (char)local_78;

                        }

                        if ((bVar11 & 0x40) != 0) {

                          puVar9[1] = local_78._1_1_;

                        }

                        if ((bVar11 & 0x20) != 0) {

                          puVar9[2] = local_78._2_1_;

                        }

                        if ((bVar11 & 0x10) != 0) {

                          puVar9[3] = local_78._3_1_;

                        }

                        puVar9 = puVar9 + 4;

                        uVar6 = uVar6 - 1;

                      } while (uVar6 != 0);

                    }

                  }

                }

              }

            }

            lVar13 = lVar13 + 1;

            pbVar12 = pbVar12 + 3;

            lVar4 = local_68;

          } while (lVar13 < local_68);

        }

        local_70 = local_70 + 1;

        local_6c = local_6c + param_2 * 4;

        if (param_3 <= local_70) {

          return param_5;

        }

      } while( true );

    }

  } while( true );

}




