// Address: 0x1400ed370
// Ghidra name: FUN_1400ed370
// ============ 0x1400ed370 FUN_1400ed370 (size=1192) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



byte * FUN_1400ed370(longlong param_1,int *param_2,int *param_3,uint *param_4,uint param_5)



{

  int iVar1;

  int iVar2;

  uint uVar3;

  int iVar4;

  undefined4 uVar5;

  byte *pbVar6;

  ulonglong uVar7;

  byte *pbVar8;

  byte *pbVar9;

  byte bVar10;

  int iVar11;

  uint uVar12;

  uint uVar13;

  int iVar14;

  byte *pbVar15;

  byte *pbVar16;

  uint uVar17;

  

  iVar1 = FUN_1400e8ad0();

  iVar2 = FUN_1400e8ad0(param_1);

  if (iVar2 + iVar1 * 0x10000 != 0x38425053) {

    _DAT_1403f4c40 = "not PSD";

    return (byte *)0x0;

  }

  iVar1 = FUN_1400e8ad0(param_1);

  if (iVar1 != 1) {

    _DAT_1403f4c40 = "wrong version";

    return (byte *)0x0;

  }

  if ((*(longlong *)(param_1 + 0x10) == 0) ||

     (iVar1 = *(int *)(param_1 + 0xc0) - *(int *)(param_1 + 0xb8), 5 < iVar1)) {

    *(longlong *)(param_1 + 0xb8) = *(longlong *)(param_1 + 0xb8) + 6;

  }

  else {

    *(undefined8 *)(param_1 + 0xb8) = *(undefined8 *)(param_1 + 0xc0);

    (**(code **)(param_1 + 0x18))(*(undefined8 *)(param_1 + 0x28),6 - iVar1);

  }

  uVar3 = FUN_1400e8ad0(param_1);

  if (0x10 < uVar3) {

    _DAT_1403f4c40 = "wrong channel count";

    return (byte *)0x0;

  }

  iVar1 = FUN_1400e8c30(param_1);

  iVar2 = FUN_1400e8c30(param_1);

  iVar4 = FUN_1400e8ad0(param_1);

  if (iVar4 == 8) {

    iVar4 = FUN_1400e8ad0(param_1);

    if (iVar4 == 3) {

      uVar5 = FUN_1400e8c30(param_1);

      FUN_1400ed890(param_1,uVar5);

      uVar5 = FUN_1400e8c30(param_1);

      FUN_1400ed890(param_1,uVar5);

      uVar5 = FUN_1400e8c30(param_1);

      FUN_1400ed890(param_1,uVar5);

      iVar4 = FUN_1400e8ad0(param_1);

      if (iVar4 < 2) {

        uVar17 = iVar2 * iVar1;

        pbVar6 = (byte *)_malloc_base();

        if (pbVar6 == (byte *)0x0) {

          _DAT_1403f4c40 = "outofmem";

        }

        else {

          if (iVar4 == 0) {

            iVar4 = 0;

            pbVar16 = pbVar6;

            do {

              if ((int)uVar3 < iVar4) {

                if (0 < (int)uVar17) {

                  bVar10 = 0;

                  uVar7 = (ulonglong)uVar17;

                  pbVar15 = pbVar16;

                  if (iVar4 == 3) {

                    bVar10 = 0xff;

                  }

                  do {

                    *pbVar15 = bVar10;

                    pbVar15 = pbVar15 + 4;

                    uVar7 = uVar7 - 1;

                  } while (uVar7 != 0);

                }

              }

              else if (0 < (int)uVar17) {

                uVar7 = (ulonglong)uVar17;

                pbVar15 = pbVar16;

                do {

                  pbVar8 = *(byte **)(param_1 + 0xb8);

                  if (pbVar8 < *(byte **)(param_1 + 0xc0)) {

                    bVar10 = *pbVar8;

                    *(byte **)(param_1 + 0xb8) = pbVar8 + 1;

                  }

                  else if (*(int *)(param_1 + 0x30) == 0) {

                    bVar10 = 0;

                  }

                  else {

                    FUN_1400ed820(param_1);

                    bVar10 = **(byte **)(param_1 + 0xb8);

                    *(byte **)(param_1 + 0xb8) = *(byte **)(param_1 + 0xb8) + 1;

                  }

                  *pbVar15 = bVar10;

                  pbVar15 = pbVar15 + 4;

                  uVar7 = uVar7 - 1;

                } while (uVar7 != 0);

              }

              iVar4 = iVar4 + 1;

              pbVar16 = pbVar16 + 1;

            } while (iVar4 < 4);

          }

          else {

            FUN_1400ed890(param_1,iVar1 * uVar3 * 2);

            iVar4 = 0;

            pbVar16 = pbVar6;

            do {

              if (iVar4 < (int)uVar3) {

                iVar11 = 0;

                pbVar15 = pbVar16;

                if (0 < (int)uVar17) {

                  do {

                    pbVar8 = *(byte **)(param_1 + 0xb8);

                    if (pbVar8 < *(byte **)(param_1 + 0xc0)) {

LAB_1400ed5e9:

                      bVar10 = *pbVar8;

                      pbVar9 = pbVar8 + 1;

                      uVar12 = (uint)bVar10;

                      *(byte **)(param_1 + 0xb8) = pbVar9;

                      uVar13 = (uint)bVar10;

                      if (uVar13 != 0x80) {

                        if (uVar13 < 0x80) goto LAB_1400ed662;

                        if (0x80 < uVar13) {

                          iVar14 = (uVar13 ^ 0xff) + 2;

                          if (pbVar9 < *(byte **)(param_1 + 0xc0)) {

                            bVar10 = *pbVar9;

                            *(byte **)(param_1 + 0xb8) = pbVar8 + 2;

                          }

                          else if (*(int *)(param_1 + 0x30) == 0) {

                            bVar10 = 0;

                          }

                          else {

                            FUN_1400ed820(param_1);

                            bVar10 = **(byte **)(param_1 + 0xb8);

                            *(byte **)(param_1 + 0xb8) = *(byte **)(param_1 + 0xb8) + 1;

                          }

                          iVar11 = iVar11 + iVar14;

                          do {

                            *pbVar15 = bVar10;

                            pbVar15 = pbVar15 + 4;

                            iVar14 = iVar14 + -1;

                          } while (iVar14 != 0);

                        }

                      }

                    }

                    else {

                      if (*(int *)(param_1 + 0x30) != 0) {

                        FUN_1400ed820(param_1);

                        pbVar8 = *(byte **)(param_1 + 0xb8);

                        goto LAB_1400ed5e9;

                      }

                      uVar12 = 0;

LAB_1400ed662:

                      iVar14 = uVar12 + 1;

                      iVar11 = iVar11 + iVar14;

                      do {

                        pbVar8 = *(byte **)(param_1 + 0xb8);

                        if (pbVar8 < *(byte **)(param_1 + 0xc0)) {

                          bVar10 = *pbVar8;

                          *(byte **)(param_1 + 0xb8) = pbVar8 + 1;

                        }

                        else if (*(int *)(param_1 + 0x30) == 0) {

                          bVar10 = 0;

                        }

                        else {

                          FUN_1400ed820(param_1);

                          bVar10 = **(byte **)(param_1 + 0xb8);

                          *(byte **)(param_1 + 0xb8) = *(byte **)(param_1 + 0xb8) + 1;

                        }

                        *pbVar15 = bVar10;

                        pbVar15 = pbVar15 + 4;

                        iVar14 = iVar14 + -1;

                      } while (iVar14 != 0);

                    }

                  } while (iVar11 < (int)uVar17);

                }

              }

              else if (0 < (int)uVar17) {

                bVar10 = 0;

                uVar7 = (ulonglong)uVar17;

                pbVar15 = pbVar16;

                if (iVar4 == 3) {

                  bVar10 = 0xff;

                }

                do {

                  *pbVar15 = bVar10;

                  pbVar15 = pbVar15 + 4;

                  uVar7 = uVar7 - 1;

                } while (uVar7 != 0);

              }

              iVar4 = iVar4 + 1;

              pbVar16 = pbVar16 + 1;

            } while (iVar4 < 4);

          }

          if (((param_5 & 0xfffffffb) == 0) ||

             (pbVar6 = (byte *)FUN_1400e6f80(pbVar6,4,param_5,iVar2,iVar1), pbVar6 != (byte *)0x0))

          {

            if (param_4 != (uint *)0x0) {

              *param_4 = uVar3;

            }

            *param_3 = iVar1;

            *param_2 = iVar2;

            return pbVar6;

          }

        }

      }

      else {

        _DAT_1403f4c40 = "bad compression";

      }

    }

    else {

      _DAT_1403f4c40 = "wrong color format";

    }

  }

  else {

    _DAT_1403f4c40 = "unsupported bit depth";

  }

  return (byte *)0x0;

}




