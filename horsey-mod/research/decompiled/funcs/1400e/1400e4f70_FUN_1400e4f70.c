// Address: 0x1400e4f70
// Ghidra name: FUN_1400e4f70
// ============ 0x1400e4f70 FUN_1400e4f70 (size=607) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



float * FUN_1400e4f70(undefined8 param_1,int *param_2,int *param_3,uint *param_4,uint param_5)



{

  int iVar1;

  uint uVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  int iVar6;

  float *pfVar7;

  longlong lVar8;

  ulonglong uVar9;

  uint uVar10;

  ulonglong uVar11;

  longlong lVar12;

  float *pfVar13;

  ulonglong uVar14;

  float *pfVar15;

  uint uVar16;

  double dVar17;

  uint local_88;

  

  iVar6 = FUN_1400ee550();

  if (iVar6 == 0) {

    lVar8 = FUN_1400ee9e0(param_1,param_2,param_3,param_4,param_5);

    if (lVar8 == 0) {

      _DAT_1403f4c40 = "unknown image type";

      pfVar7 = (float *)0x0;

    }

    else {

      if (param_5 == 0) {

        param_5 = *param_4;

      }

      iVar6 = *param_2;

      iVar1 = *param_3;

      pfVar7 = (float *)_malloc_base((longlong)(int)(iVar6 * iVar1 * param_5) << 2);

      fVar5 = DAT_1403dae04;

      fVar4 = DAT_1403dae00;

      fVar3 = DAT_14030a2d0;

      if (pfVar7 == (float *)0x0) {

        thunk_FUN_1402e9a80(lVar8);

        pfVar7 = (float *)0x0;

        _DAT_1403f4c40 = "outofmem";

      }

      else {

        uVar2 = param_5;

        if ((param_5 & 1) == 0) {

          uVar2 = param_5 - 1;

        }

        uVar10 = iVar6 * iVar1;

        if (0 < (int)uVar10) {

          uVar14 = (ulonglong)uVar10;

          local_88 = 0;

          uVar9 = 0;

          lVar12 = lVar8;

          pfVar15 = pfVar7;

          do {

            uVar11 = 0;

            pfVar13 = pfVar15;

            uVar10 = (uint)uVar9;

            uVar16 = 0;

            if (0 < (longlong)(int)uVar2) {

              do {

                dVar17 = (double)FUN_1402d0770((double)((float)*(byte *)(uVar11 + lVar12) / fVar3),

                                               (double)fVar4);

                uVar11 = uVar11 + 1;

                *pfVar13 = (float)dVar17 * fVar5;

                pfVar13 = pfVar13 + 1;

                uVar10 = local_88;

                uVar16 = uVar2;

              } while ((longlong)uVar11 < (longlong)(int)uVar2);

            }

            if ((int)uVar16 < (int)param_5) {

              pfVar7[(int)(uVar10 + uVar16)] =

                   (float)*(byte *)((int)(uVar10 + uVar16) + lVar8) / fVar3;

            }

            local_88 = uVar10 + param_5;

            uVar9 = (ulonglong)local_88;

            pfVar15 = pfVar15 + (int)param_5;

            lVar12 = lVar12 + (int)param_5;

            uVar14 = uVar14 - 1;

          } while (uVar14 != 0);

        }

        thunk_FUN_1402e9a80(lVar8);

      }

    }

    return pfVar7;

  }

  pfVar7 = (float *)FUN_1400e9380();

  return pfVar7;

}




