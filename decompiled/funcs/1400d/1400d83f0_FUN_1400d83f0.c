// Address: 0x1400d83f0
// Ghidra name: FUN_1400d83f0
// ============ 0x1400d83f0 FUN_1400d83f0 (size=680) ============


void FUN_1400d83f0(int *param_1,int *param_2,longlong param_3,longlong param_4)



{

  int iVar1;

  int iVar2;

  bool bVar3;

  longlong lVar4;

  ulonglong uVar5;

  longlong lVar6;

  int *piVar7;

  int *piVar8;

  int *piVar9;

  float fVar10;

  float fVar11;

  int local_res8 [2];

  longlong local_res10;

  int *local_58;

  int *local_50;

  

  uVar5 = (longlong)param_2 - (longlong)param_1;

  while( true ) {

    if ((longlong)(uVar5 & 0xfffffffffffffffc) < 0x81) {

      if ((param_1 != param_2) && (piVar7 = param_1 + 1, piVar7 != param_2)) {

        local_res10 = 4;

        do {

          lVar4 = local_res10;

          iVar1 = *piVar7;

          lVar6 = (longlong)iVar1;

          iVar2 = *param_1;

          fVar10 = (float)FUN_1400b6150(*(undefined8 *)(*(longlong *)(param_4 + 0x130) + lVar6 * 8))

          ;

          fVar11 = (float)FUN_1400b6150(*(undefined8 *)

                                         (*(longlong *)(param_4 + 0x130) + (longlong)iVar2 * 8));

          if (fVar10 == fVar11) {

            bVar3 = *(int *)(*(longlong *)(*(longlong *)(param_4 + 0x130) + lVar6 * 8) + 0x1d0) <

                    *(int *)(*(longlong *)(*(longlong *)(param_4 + 0x130) + (longlong)iVar2 * 8) +

                            0x1d0);

          }

          else {

            bVar3 = fVar10 < fVar11;

          }

          piVar8 = piVar7;

          if (bVar3) {

            FUN_1402f8e20((longlong)piVar7 + (4 - lVar4),param_1,lVar4);

            *param_1 = iVar1;

            local_res10 = lVar4;

          }

          else {

            while( true ) {

              piVar9 = piVar8 + -1;

              iVar2 = *piVar9;

              fVar10 = (float)FUN_1400b6150(*(undefined8 *)

                                             (*(longlong *)(param_4 + 0x130) + lVar6 * 8));

              fVar11 = (float)FUN_1400b6150(*(undefined8 *)

                                             (*(longlong *)(param_4 + 0x130) + (longlong)iVar2 * 8))

              ;

              if (fVar10 == fVar11) {

                bVar3 = *(int *)(*(longlong *)(*(longlong *)(param_4 + 0x130) + lVar6 * 8) + 0x1d0)

                        < *(int *)(*(longlong *)

                                    (*(longlong *)(param_4 + 0x130) + (longlong)iVar2 * 8) + 0x1d0);

              }

              else {

                bVar3 = fVar10 < fVar11;

              }

              if (!bVar3) break;

              *piVar8 = *piVar9;

              piVar8 = piVar9;

            }

            *piVar8 = iVar1;

          }

          local_res10 = local_res10 + 4;

          piVar7 = piVar7 + 1;

        } while (piVar7 != param_2);

      }

      return;

    }

    if (param_3 < 1) break;

    FUN_1400d72f0(&local_58,param_1,param_2,param_4);

    piVar8 = local_50;

    piVar7 = local_58;

    param_3 = (param_3 >> 1) + (param_3 >> 2);

    if ((longlong)((longlong)local_58 - (longlong)param_1 & 0xfffffffffffffffcU) <

        (longlong)((longlong)param_2 - (longlong)local_50 & 0xfffffffffffffffcU)) {

      FUN_1400d83f0(param_1,local_58,param_3,param_4);

      piVar7 = param_2;

      param_1 = piVar8;

    }

    else {

      FUN_1400d83f0(local_50,param_2,param_3,param_4);

    }

    uVar5 = (longlong)piVar7 - (longlong)param_1;

    param_2 = piVar7;

  }

  FUN_1400d6d50(param_1,param_2,param_4);

  if ((longlong)((longlong)param_2 - (longlong)param_1 & 0xfffffffffffffffcU) < 8) {

    return;

  }

  param_2 = param_2 + -1;

  do {

    local_res8[0] = *param_2;

    *param_2 = *param_1;

    FUN_1400d7cd0(param_1,0,(longlong)param_2 - (longlong)param_1 >> 2,local_res8,param_4);

    param_2 = param_2 + -1;

  } while (7 < (longlong)((4 - (longlong)param_1) + (longlong)param_2 & 0xfffffffffffffffcU));

  return;

}




