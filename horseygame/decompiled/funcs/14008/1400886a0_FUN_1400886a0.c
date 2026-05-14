// Address: 0x1400886a0
// Ghidra name: FUN_1400886a0
// ============ 0x1400886a0 FUN_1400886a0 (size=739) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_1400886a0(longlong param_1)



{

  longlong *plVar1;

  longlong lVar2;

  longlong lVar3;

  longlong lVar4;

  int *piVar5;

  float fVar6;

  int iVar7;

  char cVar8;

  undefined8 uVar9;

  ulonglong uVar10;

  longlong lVar11;

  int local_res8 [2];

  float local_res10;

  float local_res14;

  ulonglong in_stack_ffffffffffffff98;

  char *local_58;

  undefined8 uStack_50;

  undefined8 local_48;

  ulonglong uStack_40;

  

  plVar1 = (longlong *)(param_1 + 0x4a0);

  lVar2 = *plVar1;

  lVar3 = *(longlong *)(param_1 + 0x4a8);

  if (lVar2 != *(longlong *)(param_1 + 0x4a8)) {

    *(longlong *)(param_1 + 0x4a8) = lVar2;

  }

  lVar11 = *(longlong *)(param_1 + 0x4b8);

  if (lVar11 != *(longlong *)(param_1 + 0x4c0)) {

    *(longlong *)(param_1 + 0x4c0) = lVar11;

  }

  if (*(int *)(param_1 + 0x250) != 0) {

    local_res8[0] = 0;

    lVar11 = *(longlong *)(param_1 + 0x130);

    if (*(longlong *)(param_1 + 0x138) - lVar11 >> 3 != 0) {

      uVar10 = 0;

      do {

        iVar7 = local_res8[0];

        if ((int)uVar10 != *(int *)(param_1 + 0x168)) {

          lVar4 = *(longlong *)(param_1 + 0x78);

          uVar9 = FUN_1400b4a10(*(undefined8 *)(lVar11 + (longlong)local_res8[0] * 8),&local_res10);

          cVar8 = FUN_1400c5740(uVar9,lVar4 + 0x20,0);

          if (cVar8 != '\0') {

            piVar5 = *(int **)(param_1 + 0x4a8);

            if (piVar5 == *(int **)(param_1 + 0x4b0)) {

              FUN_140057a60(plVar1,piVar5,local_res8);

            }

            else {

              *piVar5 = iVar7;

              *(longlong *)(param_1 + 0x4a8) = *(longlong *)(param_1 + 0x4a8) + 4;

            }

          }

        }

        local_res8[0] = iVar7 + 1;

        uVar10 = (ulonglong)local_res8[0];

        lVar11 = *(longlong *)(param_1 + 0x130);

      } while (uVar10 < (ulonglong)(*(longlong *)(param_1 + 0x138) - lVar11 >> 3));

    }

    fVar6 = DAT_14039ca34;

    local_res8[0] = 0;

    lVar11 = *(longlong *)(param_1 + 0xb8);

    if (*(longlong *)(param_1 + 0xc0) - lVar11 >> 3 != 0) {

      uVar10 = 0;

      do {

        iVar7 = local_res8[0];

        if (((int)uVar10 != *(int *)(param_1 + 0xd4)) &&

           (lVar11 = *(longlong *)(lVar11 + (longlong)local_res8[0] * 8), *(int *)(lVar11 + 8) == 3)

           ) {

          local_res14 = *(float *)(lVar11 + 0x34) * fVar6 + *(float *)(lVar11 + 0x2c);

          local_res10 = *(float *)(lVar11 + 0x30) * fVar6 + *(float *)(lVar11 + 0x28);

          cVar8 = FUN_1400c5740(&local_res10,*(longlong *)(param_1 + 0x78) + 0x20,0);

          if (cVar8 != '\0') {

            piVar5 = *(int **)(param_1 + 0x4c0);

            if (piVar5 == *(int **)(param_1 + 0x4c8)) {

              FUN_140057a60((longlong *)(param_1 + 0x4b8),piVar5,local_res8);

            }

            else {

              *piVar5 = iVar7;

              *(longlong *)(param_1 + 0x4c0) = *(longlong *)(param_1 + 0x4c0) + 4;

            }

          }

        }

        local_res8[0] = iVar7 + 1;

        uVar10 = (ulonglong)local_res8[0];

        lVar11 = *(longlong *)(param_1 + 0xb8);

      } while (uVar10 < (ulonglong)(*(longlong *)(param_1 + 0xc0) - lVar11 >> 3));

    }

    if ((ulonglong)(longlong)(int)(lVar3 - lVar2 >> 2) <

        (ulonglong)(*(longlong *)(param_1 + 0x4a8) - *plVar1 >> 2)) {

      local_58 = (char *)0x0;

      uStack_50 = 0;

      local_48 = 0;

      uStack_40 = 0;

      local_58 = (char *)FUN_1400285e0(0x20);

      uVar9 = s_ChamberContentsUpdated_14030b258._8_8_;

      local_48 = _DAT_140305fd0;

      uStack_40 = _UNK_140305fd8;

      *(undefined8 *)local_58 = s_ChamberContentsUpdated_14030b258._0_8_;

      *(undefined8 *)(local_58 + 8) = uVar9;

      *(undefined4 *)(local_58 + 0x10) = s_ChamberContentsUpdated_14030b258._16_4_;

      *(undefined2 *)(local_58 + 0x14) = s_ChamberContentsUpdated_14030b258._20_2_;

      local_58[0x16] = '\0';

      FUN_140040ca0(&local_58,100,0xffffffce,DAT_14039ca44,

                    in_stack_ffffffffffffff98 & 0xffffffffffffff00);

      if (0xf < uStack_40) {

        if (0xfff < uStack_40 + 1) {

          if ((char *)0x1f < local_58 + (-8 - *(longlong *)(local_58 + -8))) {

                    /* WARNING: Subroutine does not return */

            _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

          }

        }

        FUN_1402c7088();

      }

    }

  }

  return;

}




