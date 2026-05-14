// Address: 0x140040550
// Ghidra name: FUN_140040550
// ============ 0x140040550 FUN_140040550 (size=1011) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined8 * FUN_140040550(undefined8 *param_1,longlong ****param_2)



{

  longlong *plVar1;

  longlong ***ppplVar2;

  int iVar3;

  FILE *_File;

  void *_DstBuf;

  longlong lVar4;

  longlong lVar5;

  longlong ****pppplVar6;

  longlong ****pppplVar7;

  ulonglong uVar8;

  size_t _ElementSize;

  ulonglong uVar9;

  ulonglong uVar10;

  undefined4 uVar11;

  ulonglong local_res18;

  undefined1 local_b0;

  undefined7 uStack_af;

  undefined8 uStack_a8;

  undefined8 local_a0;

  undefined8 uStack_98;

  longlong local_88;

  longlong ***local_80;

  undefined8 uStack_78;

  ulonglong local_70;

  ulonglong local_68;

  undefined4 local_60;

  undefined4 local_5c;

  undefined4 local_58;

  undefined4 local_54;

  undefined1 local_50;

  

  FUN_14008d760(&local_b0,"Custom%d");

  uVar11 = DAT_14039ca44;

  DAT_1403ea6f4 = DAT_1403ea6f4 + 1;

  uStack_78 = 0;

  local_70 = 0;

  local_68 = 0xf;

  local_80 = (longlong ***)0x0;

  local_88 = 0;

  local_60 = DAT_14039ca44;

  local_5c = 100;

  local_58 = 100;

  local_54 = 0xffffffff;

  local_50 = 0;

  pppplVar6 = param_2;

  if ((longlong ***)0xf < param_2[3]) {

    pppplVar6 = (longlong ****)*param_2;

  }

  _File = (FILE *)FUN_1402ce0f8(pppplVar6,&DAT_14039be7c);

  if (_File == (FILE *)0x0) {

LAB_14004066f:

    lVar4 = 0;

  }

  else {

    FUN_1402cea4c(_File,0,2);

    iVar3 = FUN_1402cf00c(_File);

    _ElementSize = (size_t)iVar3;

    FUN_1402cea4c(_File,0,0);

    _DstBuf = (void *)_malloc_base(_ElementSize);

    fread(_DstBuf,_ElementSize,1,_File);

    FUN_1402ce288(_File);

    if (_DstBuf == (void *)0x0) goto LAB_14004066f;

    lVar4 = FUN_140044140(_DstBuf,_ElementSize);

    thunk_FUN_1402e9a80(_DstBuf);

  }

  uVar9 = 0;

  uVar10 = 0xf;

  local_88 = lVar4;

  if (&local_80 != param_2) {

    pppplVar6 = param_2;

    if ((longlong ***)0xf < param_2[3]) {

      pppplVar6 = (longlong ****)*param_2;

    }

    FUN_140027f50(&local_80,pppplVar6);

    uVar9 = local_70;

    uVar10 = local_68;

    uVar11 = local_60;

  }

  lVar4 = local_88;

  if (local_88 == 0) {

    *param_1 = 0;

    param_1[1] = 0;

    param_1[2] = 0;

    param_1[3] = 0xf;

    *(undefined1 *)param_1 = 0;

    if (0xf < uVar10) {

      if ((0xfff < uVar10 + 1) &&

         (0x1f < (ulonglong)((longlong)local_80 + (-8 - (longlong)local_80[-1]))))

      goto LAB_140040916;

      FUN_1402c7088();

    }

    if (uStack_98 < 0x10) goto LAB_140040856;

    if (0xfff < uStack_98 + 1) {

      lVar4 = CONCAT71(uStack_af,local_b0) - *(longlong *)(CONCAT71(uStack_af,local_b0) + -8);

      goto joined_r0x00014004090f;

    }

  }

  else {

    lVar5 = FUN_140047560(&DAT_1403ea2c0,&local_b0);

    pppplVar6 = (longlong ****)local_80;

    plVar1 = *(longlong **)(lVar5 + 8);

    if (plVar1 == *(longlong **)(lVar5 + 0x10)) {

      FUN_140046e50(lVar5,plVar1);

      uVar10 = local_68;

      pppplVar6 = (longlong ****)local_80;

    }

    else {

      *plVar1 = lVar4;

      plVar1[1] = 0;

      plVar1[2] = 0;

      plVar1[3] = 0;

      plVar1[4] = 0;

      pppplVar7 = &local_80;

      if (0xf < uVar10) {

        pppplVar7 = (longlong ****)local_80;

      }

      local_res18 = 0x7fffffffffffffff;

      if (0x7fffffffffffffff < uVar9) {

                    /* WARNING: Subroutine does not return */

        FUN_140024130();

      }

      if (uVar9 < 0x10) {

        plVar1[3] = uVar9;

        plVar1[4] = 0xf;

        ppplVar2 = pppplVar7[1];

        plVar1[1] = (longlong)*pppplVar7;

        plVar1[2] = (longlong)ppplVar2;

      }

      else {

        uVar8 = uVar9 | 0xf;

        if ((uVar8 < 0x8000000000000000) && (local_res18 = uVar8, uVar8 < 0x16)) {

          local_res18 = 0x16;

        }

        lVar4 = FUN_1400285e0(local_res18 + 1);

        plVar1[1] = lVar4;

        plVar1[3] = uVar9;

        plVar1[4] = local_res18;

        FUN_1402f8e20(lVar4,pppplVar7);

      }

      *(undefined4 *)(plVar1 + 5) = uVar11;

      *(undefined4 *)((longlong)plVar1 + 0x2c) = local_5c;

      *(undefined4 *)(plVar1 + 6) = local_58;

      *(undefined4 *)((longlong)plVar1 + 0x34) = local_54;

      *(undefined1 *)(plVar1 + 7) = local_50;

      *(longlong *)(lVar5 + 8) = *(longlong *)(lVar5 + 8) + 0x40;

    }

    *param_1 = CONCAT71(uStack_af,local_b0);

    param_1[1] = uStack_a8;

    *(undefined4 *)(param_1 + 2) = (undefined4)local_a0;

    *(undefined4 *)((longlong)param_1 + 0x14) = local_a0._4_4_;

    *(undefined4 *)(param_1 + 3) = (undefined4)uStack_98;

    *(undefined4 *)((longlong)param_1 + 0x1c) = uStack_98._4_4_;

    local_a0 = _DAT_14039caa0;

    uStack_98 = _UNK_14039caa8;

    local_b0 = 0;

    if (0xf < uVar10) {

      pppplVar7 = pppplVar6;

      if ((0xfff < uVar10 + 1) &&

         (pppplVar7 = (longlong ****)pppplVar6[-1],

         0x1f < (ulonglong)((longlong)pppplVar6 + (-8 - (longlong)pppplVar7)))) {

LAB_140040916:

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

      FUN_1402c7088(pppplVar7);

    }

    if (uStack_98 < 0x10) goto LAB_140040856;

    if (0xfff < uStack_98 + 1) {

      lVar4 = CONCAT71(uStack_af,local_b0) - *(longlong *)(CONCAT71(uStack_af,local_b0) + -8);

joined_r0x00014004090f:

      if (0x1f < lVar4 - 8U) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

    }

  }

  FUN_1402c7088();

LAB_140040856:

  local_b0 = 0;

  local_a0 = _DAT_14039caa0;

  uStack_98 = _UNK_14039caa8;

  FUN_140027900(param_2);

  return param_1;

}




