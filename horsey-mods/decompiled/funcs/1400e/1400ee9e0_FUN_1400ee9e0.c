// Address: 0x1400ee9e0
// Ghidra name: FUN_1400ee9e0
// ============ 0x1400ee9e0 FUN_1400ee9e0 (size=1836) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



longlong FUN_1400ee9e0(int *param_1,int *param_2,int *param_3,uint *param_4,uint param_5)



{

  ulonglong *puVar1;

  ulonglong *puVar2;

  float fVar3;

  uint uVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  int *piVar8;

  int iVar9;

  int iVar10;

  int iVar11;

  char *pcVar12;

  longlong lVar13;

  longlong lVar14;

  ulonglong uVar15;

  undefined8 uVar16;

  char cVar17;

  ulonglong uVar18;

  float *pfVar19;

  uint uVar20;

  double dVar22;

  float fVar23;

  undefined8 in_stack_ffffffffffffff38;

  undefined4 uVar25;

  undefined8 uVar24;

  int *local_98;

  undefined8 local_90;

  undefined8 local_88;

  longlong local_80;

  ulonglong uVar21;

  

  puVar1 = (ulonglong *)(param_1 + 0x2e);

  pcVar12 = (char *)*puVar1;

  if (pcVar12 < *(char **)(param_1 + 0x30)) {

LAB_1400eea2a:

    cVar17 = *pcVar12;

    pcVar12 = pcVar12 + 1;

    *puVar1 = (ulonglong)pcVar12;

    if (cVar17 == -1) {

      do {

        if (*(char **)(param_1 + 0x30) <= pcVar12) {

          if (param_1[0xc] == 0) {

            cVar17 = '\0';

            break;

          }

          FUN_1400ed820(param_1);

          pcVar12 = (char *)*puVar1;

        }

        cVar17 = *pcVar12;

        pcVar12 = pcVar12 + 1;

        *puVar1 = (ulonglong)pcVar12;

      } while (cVar17 == -1);

      if (cVar17 == -0x28) {

        *puVar1 = *(ulonglong *)(param_1 + 0x32);

        lVar13 = FUN_1400ee9b0(param_1,param_2,param_3,param_4,param_5);

        return lVar13;

      }

    }

  }

  else if (param_1[0xc] != 0) {

    FUN_1400ed820();

    pcVar12 = (char *)*puVar1;

    goto LAB_1400eea2a;

  }

  _DAT_1403f4c40 = "no SOI";

  puVar2 = (ulonglong *)(param_1 + 0x32);

  *puVar1 = *puVar2;

  iVar9 = FUN_1400e6900(param_1);

  uVar25 = (undefined4)((ulonglong)in_stack_ffffffffffffff38 >> 0x20);

  pcVar12 = (char *)*puVar2;

  *puVar1 = (ulonglong)pcVar12;

  if (iVar9 != 0) {

    lVar13 = 0;

    if (4 < param_5) {

      _DAT_1403f4c40 = "bad req_comp";

      return 0;

    }

    local_98 = param_1;

    iVar9 = FUN_1400eaf60(&local_98,0,param_5);

    piVar8 = local_98;

    lVar14 = lVar13;

    if (iVar9 != 0) {

      lVar14 = local_80;

      if ((param_5 != 0) && (param_5 != local_98[3])) {

        lVar14 = FUN_1400e6f80(local_80,local_98[3],param_5,*local_98,CONCAT44(uVar25,local_98[1]));

        piVar8[3] = param_5;

        if (lVar14 == 0) {

          return 0;

        }

      }

      *param_2 = *piVar8;

      *param_3 = piVar8[1];

      local_80 = lVar13;

      if (param_4 != (uint *)0x0) {

        *param_4 = piVar8[2];

      }

    }

    thunk_FUN_1402e9a80(local_80);

    thunk_FUN_1402e9a80(local_88);

    thunk_FUN_1402e9a80(local_90);

    return lVar14;

  }

  if (pcVar12 < *(char **)(param_1 + 0x30)) {

    cVar17 = *pcVar12;

LAB_1400eebaf:

    pcVar12 = pcVar12 + 1;

    *puVar1 = (ulonglong)pcVar12;

    if (cVar17 == 'B') {

      if (*(char **)(param_1 + 0x30) <= pcVar12) {

        if (param_1[0xc] == 0) goto LAB_1400eec63;

        FUN_1400ed820(param_1);

        pcVar12 = (char *)*puVar1;

      }

      cVar17 = *pcVar12;

      *puVar1 = (ulonglong)(pcVar12 + 1);

      if (cVar17 == 'M') {

        FUN_1400e8b80(param_1);

        FUN_1400e8b80(param_1);

        FUN_1400e8b80(param_1);

        FUN_1400e8b80(param_1);

        FUN_1400e8b80(param_1);

        FUN_1400e8b80(param_1);

        iVar9 = FUN_1400e8b80(param_1);

        iVar10 = FUN_1400e8b80(param_1);

        iVar9 = iVar10 * 0x10000 + iVar9;

        if ((((iVar9 == 0xc) || (iVar9 == 0x28)) || (iVar9 == 0x38)) || (iVar9 == 0x6c)) {

          *puVar1 = *puVar2;

          lVar13 = FUN_1400e5690(param_1,param_2,param_3,param_4,param_5);

          return lVar13;

        }

      }

    }

  }

  else if (param_1[0xc] != 0) {

    FUN_1400ed820(param_1);

    pcVar12 = (char *)*puVar1;

    cVar17 = *pcVar12;

    goto LAB_1400eebaf;

  }

LAB_1400eec63:

  *puVar1 = *puVar2;

  iVar9 = FUN_1400e8e30(param_1);

  *puVar1 = *puVar2;

  if (iVar9 != 0) {

    lVar13 = FUN_1400edde0(param_1,param_2,param_3,param_4,param_5);

    return lVar13;

  }

  iVar9 = FUN_1400e8ad0(param_1);

  iVar10 = FUN_1400e8ad0(param_1);

  *puVar1 = *puVar2;

  if (iVar10 + iVar9 * 0x10000 == 0x38425053) {

    lVar13 = FUN_1400ed370(param_1,param_2,param_3,param_4,param_5);

    return lVar13;

  }

  iVar9 = FUN_1400ec010(param_1,&DAT_1403100cc);

  uVar25 = (undefined4)((ulonglong)in_stack_ffffffffffffff38 >> 0x20);

  if (iVar9 == 0) {

LAB_1400eed42:

    *(undefined8 *)(param_1 + 0x2e) = *(undefined8 *)(param_1 + 0x32);

    iVar9 = FUN_1400ee550(param_1);

    if (iVar9 == 0) {

      iVar9 = FUN_1400f0250(param_1);

      *(undefined8 *)(param_1 + 0x2e) = *(undefined8 *)(param_1 + 0x32);

      if (iVar9 == 0) {

        _DAT_1403f4c40 = "unknown image type";

        lVar14 = 0;

      }

      else {

        lVar14 = FUN_1400efab0(param_1,param_2,param_3,param_4,CONCAT44(uVar25,param_5));

      }

    }

    else {

      lVar13 = FUN_1400e9380(param_1,param_2,param_3,param_4,CONCAT44(uVar25,param_5));

      if (param_5 == 0) {

        param_5 = *param_4;

      }

      iVar9 = *param_2 * *param_3;

      lVar14 = _malloc_base((longlong)(int)(param_5 * iVar9));

      fVar7 = DAT_1403dadfc;

      fVar6 = DAT_14039ca34;

      fVar5 = DAT_14030a2d0;

      if (lVar14 == 0) {

        thunk_FUN_1402e9a80(lVar13);

        lVar14 = 0;

        _DAT_1403f4c40 = "outofmem";

      }

      else {

        uVar4 = param_5;

        if ((param_5 & 1) == 0) {

          uVar4 = param_5 - 1;

        }

        uVar15 = 0;

        if (0 < iVar9) {

          uVar21 = uVar15;

          uVar18 = uVar15;

          do {

            iVar10 = (int)uVar18;

            uVar20 = 0;

            if (0 < (longlong)(int)uVar4) {

              pfVar19 = (float *)(lVar13 + (longlong)iVar10 * 4);

              uVar18 = uVar15;

              do {

                dVar22 = (double)FUN_1402d0770((double)(fVar7 * *pfVar19));

                pfVar19 = pfVar19 + 1;

                fVar23 = (float)dVar22 * fVar5 + fVar6;

                fVar3 = 0.0;

                if (0.0 <= fVar23) {

                  fVar3 = fVar23;

                }

                fVar23 = fVar5;

                if (fVar3 <= fVar5) {

                  fVar23 = fVar3;

                }

                *(char *)(uVar18 + lVar14 + iVar10) = (char)(int)fVar23;

                uVar18 = uVar18 + 1;

                uVar20 = uVar4;

              } while ((longlong)uVar18 < (longlong)(int)uVar4);

            }

            if ((int)uVar20 < (int)param_5) {

              fVar23 = *(float *)(lVar13 + (longlong)(int)(iVar10 + uVar20) * 4) * fVar5 + fVar6;

              fVar3 = 0.0;

              if (0.0 <= fVar23) {

                fVar3 = fVar23;

              }

              fVar23 = fVar5;

              if (fVar3 <= fVar5) {

                fVar23 = fVar3;

              }

              *(char *)((int)(iVar10 + uVar20) + lVar14) = (char)(int)fVar23;

            }

            uVar20 = (int)uVar21 + 1;

            uVar21 = (ulonglong)uVar20;

            uVar18 = (ulonglong)(iVar10 + param_5);

          } while ((int)uVar20 < iVar9);

        }

        thunk_FUN_1402e9a80(lVar13);

      }

    }

    return lVar14;

  }

  lVar13 = 0x54;

  do {

    if (*puVar1 < *(ulonglong *)(param_1 + 0x30)) {

      *puVar1 = *puVar1 + 1;

    }

    else if (param_1[0xc] != 0) {

      FUN_1400ed820(param_1);

      *puVar1 = *puVar1 + 1;

    }

    uVar25 = (undefined4)((ulonglong)in_stack_ffffffffffffff38 >> 0x20);

    lVar13 = lVar13 + -1;

  } while (lVar13 != 0);

  iVar9 = FUN_1400ec010(param_1,&DAT_1403100d4);

  if (iVar9 == 0) goto LAB_1400eed42;

  uVar15 = *(ulonglong *)(param_1 + 0x32);

  lVar13 = 0x5c;

  *(ulonglong *)(param_1 + 0x2e) = uVar15;

  do {

    if (uVar15 < *(ulonglong *)(param_1 + 0x30)) {

      uVar15 = uVar15 + 1;

      *(ulonglong *)(param_1 + 0x2e) = uVar15;

    }

    else if (param_1[0xc] != 0) {

      FUN_1400ed820(param_1);

      *(longlong *)(param_1 + 0x2e) = *(longlong *)(param_1 + 0x2e) + 1;

      uVar15 = *(ulonglong *)(param_1 + 0x2e);

    }

    lVar13 = lVar13 + -1;

  } while (lVar13 != 0);

  iVar9 = FUN_1400e8ad0(param_1);

  iVar10 = FUN_1400e8ad0(param_1);

  if (*(longlong *)(param_1 + 4) != 0) {

    iVar11 = (**(code **)(param_1 + 8))(*(undefined8 *)(param_1 + 10));

    if (iVar11 == 0) goto LAB_1400ef02d;

    if (param_1[0xc] == 0) goto LAB_1400ef018;

  }

  if (*(ulonglong *)(param_1 + 0x30) <= *(ulonglong *)(param_1 + 0x2e)) {

LAB_1400ef018:

    _DAT_1403f4c40 = "bad file";

    return 0;

  }

LAB_1400ef02d:

  if ((int)(0x10000000 / (longlong)iVar9) < iVar10) {

    _DAT_1403f4c40 = "too large";

    return 0;

  }

  FUN_1400e8ad0(param_1,0x10000000 % (longlong)iVar9 & 0xffffffff);

  FUN_1400e8ad0(param_1);

  FUN_1400e8ad0(param_1);

  FUN_1400e8ad0(param_1);

  lVar13 = (longlong)(iVar10 * iVar9 * 4);

  uVar16 = _malloc_base(lVar13);

  FUN_1402f94c0(uVar16,0xff,lVar13);

  uVar24 = uVar16;

  lVar13 = FUN_1400ec0b0(param_1,iVar9,iVar10,param_4,uVar16);

  uVar25 = (undefined4)((ulonglong)uVar24 >> 0x20);

  if (lVar13 == 0) {

    thunk_FUN_1402e9a80(uVar16);

    uVar16 = 0;

  }

  *param_2 = iVar9;

  *param_3 = iVar10;

  if (param_5 == 0) {

    param_5 = *param_4;

  }

  lVar13 = FUN_1400e6f80(uVar16,4,param_5,iVar9,CONCAT44(uVar25,iVar10));

  return lVar13;

}




