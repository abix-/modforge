// Address: 0x14005e3c0
// Ghidra name: FUN_14005e3c0
// ============ 0x14005e3c0 FUN_14005e3c0 (size=1110) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_14005e3c0(longlong param_1)



{

  ulonglong uVar1;

  longlong *plVar2;

  char *pcVar3;

  longlong lVar4;

  undefined4 uVar5;

  int iVar6;

  undefined4 uVar7;

  longlong lVar8;

  undefined8 *puVar9;

  undefined8 *****pppppuVar10;

  longlong *plVar11;

  longlong lVar12;

  ulonglong uVar13;

  longlong local_res8;

  longlong local_res10;

  undefined8 in_stack_fffffffffffffd98;

  undefined8 ****local_258;

  undefined8 uStack_250;

  ulonglong local_248;

  ulonglong uStack_240;

  longlong local_238 [3];

  ulonglong local_220;

  undefined1 local_218 [480];

  

  uVar7 = (undefined4)((ulonglong)in_stack_fffffffffffffd98 >> 0x20);

  lVar8 = 0;

  FUN_1400d01d0(param_1,&DAT_140307128,0);

  FUN_1400c7c60(*(undefined4 *)(*(longlong *)(param_1 + 0x148) + 0x1f8),7);

  *(undefined4 *)(*(longlong *)(param_1 + 0x148) + 0x284) = 0xd;

  iVar6 = FUN_14005e250(0x1f);

  *(undefined4 *)(*(longlong *)(param_1 + 0x148) + 0xcc + (longlong)iVar6 * 4) = 0x1f;

  FUN_1400b3070(*(undefined8 *)(param_1 + 0x148));

  local_258 = (undefined8 ****)0x0;

  uStack_250 = 0;

  local_248 = 0;

  uStack_240 = 0;

  strlen(PTR_s_00_CGAACTCTTA_00_CGAACTCTTA_01_T_1403d6120);

  FUN_140027e30(&local_258,PTR_s_00_CGAACTCTTA_00_CGAACTCTTA_01_T_1403d6120);

  FUN_1400a5950(&local_258,local_218);

  if (0xf < uStack_240) {

    if ((0xfff < uStack_240 + 1) &&

       (0x1f < (ulonglong)((longlong)local_258 + (-8 - (longlong)local_258[-1])))) {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

    FUN_1402c7088();

  }

  local_res8 = FUN_1402c704c(0x498);

  if (local_res8 != 0) {

    lVar8 = FUN_1400aac60(local_res8);

  }

  local_res10 = lVar8;

  FUN_1400b35f0(lVar8,local_218);

  FUN_1400b3070(lVar8);

  local_res8 = 0x40a0000041500000;

  FUN_1400b6610(lVar8,&local_res8);

  *(undefined4 *)(lVar8 + 0x1fc) = *(undefined4 *)(lVar8 + 0x200);

  *(undefined1 *)(lVar8 + 0x1a) = 1;

  uVar7 = FUN_1400c7600(0,1,0xffffffff,0xffffffff,CONCAT44(uVar7,0xffffffff));

  *(undefined4 *)(lVar8 + 0x1f8) = uVar7;

  *(undefined1 *)(lVar8 + 0x205) = 1;

  local_248 = _DAT_140304090;

  uStack_240 = _UNK_140304098;

  local_258 = (undefined8 ****)0x65636e6572616c43;

  uStack_250 = 0;

  FUN_1400c7910(uVar7,&local_258);

  if (0xf < uStack_240) {

    if ((0xfff < uStack_240 + 1) &&

       (0x1f < (ulonglong)((longlong)local_258 + (-8 - (longlong)local_258[-1])))) {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

    FUN_1402c7088();

  }

  puVar9 = (undefined8 *)FUN_1400c4e10();

  lVar4 = puVar9[2];

  if (0x7fffffffffffffffU - lVar4 < 0x15) {

                    /* WARNING: Subroutine does not return */

    FUN_140024130();

  }

  if (0xf < (ulonglong)puVar9[3]) {

    puVar9 = (undefined8 *)*puVar9;

  }

  local_258 = (undefined8 *****)0x0;

  uStack_250 = 0;

  local_248 = 0;

  uStack_240 = 0;

  uVar1 = lVar4 + 0x15;

  uVar13 = 0xf;

  pppppuVar10 = &local_258;

  if (0xf < uVar1) {

    uVar13 = uVar1 | 0xf;

    if (uVar13 < 0x8000000000000000) {

      if (uVar13 < 0x16) {

        uVar13 = 0x16;

      }

    }

    else {

      uVar13 = 0x7fffffffffffffff;

    }

    pppppuVar10 = (undefined8 *****)FUN_1400285e0(uVar13 + 1);

    local_258 = pppppuVar10;

  }

  local_248 = uVar1;

  uStack_240 = uVar13;

  FUN_1402f8e20(pppppuVar10,puVar9);

  pcVar3 = (char *)((longlong)pppppuVar10 + lVar4);

  *(undefined4 *)pcVar3 = s_Animal_HorseMike1_wav_140307130._0_4_;

  *(undefined4 *)(pcVar3 + 4) = s_Animal_HorseMike1_wav_140307130._4_4_;

  *(undefined4 *)(pcVar3 + 8) = s_Animal_HorseMike1_wav_140307130._8_4_;

  *(undefined4 *)(pcVar3 + 0xc) = s_Animal_HorseMike1_wav_140307130._12_4_;

  *(undefined4 *)((longlong)pppppuVar10 + lVar4 + 0x10) = s_Animal_HorseMike1_wav_140307130._16_4_;

  *(char *)((longlong)pppppuVar10 + lVar4 + 0x14) = s_Animal_HorseMike1_wav_140307130[0x14];

  *(undefined1 *)((longlong)pppppuVar10 + uVar1) = 0;

  plVar11 = (longlong *)FUN_140040550(local_238,&local_258);

  plVar2 = (longlong *)(lVar8 + 0x168);

  if (plVar2 != plVar11) {

    if (0xf < *(ulonglong *)(lVar8 + 0x180)) {

      lVar4 = *plVar2;

      lVar12 = lVar4;

      if ((0xfff < *(ulonglong *)(lVar8 + 0x180) + 1) &&

         (lVar12 = *(longlong *)(lVar4 + -8), 0x1f < (lVar4 - lVar12) - 8U)) goto LAB_14005e7d1;

      FUN_1402c7088(lVar12);

    }

    *(undefined8 *)(lVar8 + 0x178) = 0;

    *(undefined8 *)(lVar8 + 0x180) = 0xf;

    *(undefined1 *)plVar2 = 0;

    uVar7 = *(undefined4 *)((longlong)plVar11 + 4);

    lVar4 = plVar11[1];

    uVar5 = *(undefined4 *)((longlong)plVar11 + 0xc);

    *(int *)plVar2 = (int)*plVar11;

    *(undefined4 *)(lVar8 + 0x16c) = uVar7;

    *(int *)(lVar8 + 0x170) = (int)lVar4;

    *(undefined4 *)(lVar8 + 0x174) = uVar5;

    lVar4 = plVar11[3];

    *(longlong *)(lVar8 + 0x178) = plVar11[2];

    *(longlong *)(lVar8 + 0x180) = lVar4;

    plVar11[2] = 0;

    plVar11[3] = 0xf;

    *(undefined1 *)plVar11 = 0;

  }

  if (0xf < local_220) {

    if ((0xfff < local_220 + 1) && (0x1f < (local_238[0] - *(longlong *)(local_238[0] + -8)) - 8U))

    {

LAB_14005e7d1:

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

    FUN_1402c7088();

  }

  *(undefined4 *)(lVar8 + 0x284) = 0xc;

  plVar2 = *(longlong **)(param_1 + 0x138);

  if (plVar2 == *(longlong **)(param_1 + 0x140)) {

    FUN_140030680(param_1 + 0x130,plVar2,&local_res10);

  }

  else {

    *plVar2 = lVar8;

    *(longlong *)(param_1 + 0x138) = *(longlong *)(param_1 + 0x138) + 8;

  }

  FUN_1400cc9d0(param_1,8,DAT_140303fd4,DAT_140304be8);

  return;

}




