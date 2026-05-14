// Address: 0x1400327b0
// Ghidra name: FUN_1400327b0
// ============ 0x1400327b0 FUN_1400327b0 (size=766) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_1400327b0(longlong param_1)



{

  longlong *plVar1;

  int iVar2;

  undefined8 *puVar3;

  undefined8 uVar4;

  char *pcVar5;

  longlong lVar6;

  undefined8 uVar7;

  longlong lVar8;

  longlong lVar9;

  int iVar10;

  int iVar11;

  undefined1 *puVar12;

  longlong lVar13;

  undefined8 in_stack_fffffffffffffdb8;

  undefined4 uVar14;

  char *local_238;

  undefined8 uStack_230;

  undefined8 local_228;

  ulonglong uStack_220;

  undefined1 local_218 [496];

  

  iVar11 = 0;

  plVar1 = (longlong *)(param_1 + 0x260);

  lVar13 = *(longlong *)(param_1 + 0x268);

  lVar6 = *plVar1;

  if (lVar13 - lVar6 >> 3 != 0) {

    lVar9 = 0;

    do {

      puVar3 = *(undefined8 **)(lVar9 + lVar6);

      if (puVar3 != (undefined8 *)0x0) {

        (**(code **)*puVar3)(puVar3,1);

      }

      iVar11 = iVar11 + 1;

      lVar9 = lVar9 + 8;

      lVar13 = *(longlong *)(param_1 + 0x268);

      lVar6 = *plVar1;

    } while ((ulonglong)(longlong)iVar11 < (ulonglong)(lVar13 - lVar6 >> 3));

  }

  if (lVar6 != lVar13) {

    *(longlong *)(param_1 + 0x268) = lVar6;

  }

  *(undefined4 *)(param_1 + 0x28c) = 0;

  FUN_140037550(plVar1,(longlong)*(int *)(param_1 + 0x6ac));

  uVar4 = _UNK_1403041e8;

  pcVar5 = _DAT_1403041e0;

  uVar14 = (undefined4)((ulonglong)in_stack_fffffffffffffdb8 >> 0x20);

  iVar11 = 0;

  if (*(longlong *)(param_1 + 0x268) - *plVar1 >> 3 != 0) {

    lVar13 = 0;

    do {

      lVar6 = FUN_1402c704c();

      if (lVar6 == 0) {

        uVar7 = 0;

      }

      else {

        uVar7 = FUN_1400aac60(lVar6);

      }

      *(undefined8 *)(lVar13 + *plVar1) = uVar7;

      *(undefined4 *)(*(longlong *)(*plVar1 + lVar13) + 0x1fc) = 1;

      puVar12 = local_218;

      lVar6 = 2;

      do {

        iVar10 = 0;

        lVar9 = 0x2b8;

        do {

          local_238 = pcVar5;

          uStack_230 = uVar4;

          FUN_1400c5c80(&local_238,4);

          *puVar12 = 0;

          lVar8 = 0;

          do {

            iVar2 = *(int *)((longlong)&local_238 + lVar8 * 4);

            if (*(char *)(lVar9 + iVar2 + param_1) != '\0') {

              *puVar12 = (char)iVar2;

              break;

            }

            if (lVar8 == 3) {

              FUN_1400c4320("vat missing gene %d",iVar10);

              break;

            }

            lVar8 = lVar8 + 1;

          } while (lVar8 < 4);

          iVar10 = iVar10 + 1;

          lVar9 = lVar9 + 4;

          puVar12 = puVar12 + 1;

        } while (iVar10 < 0xf0);

        lVar6 = lVar6 + -1;

      } while (lVar6 != 0);

      FUN_1400b35f0(*(undefined8 *)(*plVar1 + lVar13),local_218);

      FUN_1400b3070(*(undefined8 *)(*plVar1 + lVar13));

      uVar14 = (undefined4)((ulonglong)in_stack_fffffffffffffdb8 >> 0x20);

      *(undefined4 *)(*(longlong *)(*plVar1 + lVar13) + 0x224) = *(undefined4 *)(param_1 + 0x28c);

      *(int *)(param_1 + 0x28c) = *(int *)(param_1 + 0x28c) + 1;

      *(undefined4 *)(*(longlong *)(*plVar1 + lVar13) + 0x228) = 0;

      *(undefined4 *)(*(longlong *)(*plVar1 + lVar13) + 0x21c) = 0;

      iVar11 = iVar11 + 1;

      lVar13 = lVar13 + 8;

    } while ((ulonglong)(longlong)iVar11 <

             (ulonglong)(*(longlong *)(param_1 + 0x268) - *plVar1 >> 3));

  }

  *(undefined4 *)(param_1 + 0x288) = 0;

  *(undefined4 *)(param_1 + 0x278) = 0;

  *(undefined4 *)(param_1 + 0x298) = 0;

  FUN_140032ac0(param_1);

  *(int *)(param_1 + 0x6a0) = *(int *)(param_1 + 0x6a0) + 1;

  local_238 = (char *)0x0;

  uStack_230 = 0;

  local_228 = 0;

  uStack_220 = 0;

  local_238 = (char *)FUN_1400285e0(0x20);

  uVar4 = s_And_they_re_off__140303b88._8_8_;

  local_228 = _DAT_1403040e0;

  uStack_220 = _UNK_1403040e8;

  *(undefined8 *)local_238 = s_And_they_re_off__140303b88._0_8_;

  *(undefined8 *)(local_238 + 8) = uVar4;

  local_238[0x10] = '\0';

  FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_238,0,CONCAT44(uVar14,DAT_140303758)

               );

  if (0xf < uStack_220) {

    if ((0xfff < uStack_220 + 1) &&

       ((char *)0x1f < local_238 + (-8 - *(longlong *)(local_238 + -8)))) {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

    FUN_1402c7088();

  }

  return;

}




