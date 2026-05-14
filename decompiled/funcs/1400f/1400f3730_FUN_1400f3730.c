// Address: 0x1400f3730
// Ghidra name: FUN_1400f3730
// ============ 0x1400f3730 FUN_1400f3730 (size=689) ============


ulonglong FUN_1400f3730(longlong param_1,int param_2,float param_3,longlong *param_4,int *param_5)



{

  char cVar1;

  ulonglong uVar2;

  longlong lVar3;

  longlong lVar4;

  char *pcVar5;

  int iVar6;

  longlong lVar7;

  ulonglong uVar8;

  ulonglong uVar9;

  short *psVar10;

  longlong lVar11;

  float fVar12;

  float fVar13;

  int local_res10 [2];

  

  uVar2 = 0;

  local_res10[0] = 0;

  lVar11 = (longlong)param_2;

  uVar8 = uVar2;

  if (0 < param_2) {

    pcVar5 = (char *)(param_1 + 8);

    lVar3 = lVar11;

    uVar9 = uVar2;

    do {

      cVar1 = *pcVar5;

      pcVar5 = pcVar5 + 10;

      uVar8 = (ulonglong)((int)uVar9 + 1);

      if (cVar1 != '\x01') {

        uVar8 = uVar9;

      }

      lVar3 = lVar3 + -1;

      uVar9 = uVar8;

    } while (lVar3 != 0);

  }

  iVar6 = (int)uVar8;

  *param_5 = iVar6;

  if (iVar6 != 0) {

    lVar3 = _malloc_base((longlong)iVar6 << 2);

    *param_4 = lVar3;

    if (lVar3 != 0) {

      iVar6 = 0;

      uVar8 = uVar2;

      do {

        fVar12 = 0.0;

        fVar13 = 0.0;

        if ((iVar6 == 1) && (uVar2 = _malloc_base((longlong)local_res10[0] << 3), uVar2 == 0)) {

          thunk_FUN_1402e9a80(0);

          thunk_FUN_1402e9a80(*param_4);

          *param_4 = 0;

          *param_5 = 0;

          return 0;

        }

        local_res10[0] = 0;

        lVar3 = -1;

        if (0 < lVar11) {

          psVar10 = (short *)(param_1 + 2);

          lVar7 = lVar11;

          do {

            cVar1 = (char)psVar10[3];

            if (cVar1 == '\x01') {

              if (-1 < lVar3) {

                *(int *)(*param_4 + lVar3 * 4) = local_res10[0] - (int)uVar8;

              }

              lVar3 = lVar3 + 1;

              uVar8 = (ulonglong)local_res10[0];

              fVar12 = (float)(int)psVar10[-1];

              local_res10[0] = local_res10[0] + 1;

              fVar13 = (float)(int)*psVar10;

              if (uVar2 != 0) {

                *(float *)(uVar2 + uVar8 * 8) = fVar12;

                *(float *)(uVar2 + 4 + uVar8 * 8) = fVar13;

              }

            }

            else if (cVar1 == '\x02') {

              lVar4 = (longlong)local_res10[0];

              fVar12 = (float)(int)psVar10[-1];

              local_res10[0] = local_res10[0] + 1;

              fVar13 = (float)(int)*psVar10;

              if (uVar2 != 0) {

                *(float *)(uVar2 + lVar4 * 8) = fVar12;

                *(float *)(uVar2 + 4 + lVar4 * 8) = fVar13;

              }

            }

            else if (cVar1 == '\x03') {

              FUN_1400f4cb0(uVar2,local_res10,fVar12,fVar13,(float)(int)psVar10[1],

                            (float)(int)psVar10[2],(float)(int)psVar10[-1],(float)(int)*psVar10,

                            param_3 * param_3,0);

              fVar13 = (float)(int)*psVar10;

              fVar12 = (float)(int)psVar10[-1];

            }

            psVar10 = psVar10 + 5;

            lVar7 = lVar7 + -1;

          } while (lVar7 != 0);

        }

        iVar6 = iVar6 + 1;

        *(int *)(*param_4 + lVar3 * 4) = local_res10[0] - (int)uVar8;

      } while (iVar6 < 2);

      return uVar2;

    }

    *param_5 = 0;

  }

  return 0;

}




