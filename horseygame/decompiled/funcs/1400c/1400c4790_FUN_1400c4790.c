// Address: 0x1400c4790
// Ghidra name: FUN_1400c4790
// ============ 0x1400c4790 FUN_1400c4790 (size=626) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void * FUN_1400c4790(undefined8 *param_1,int *param_2)



{

  int iVar1;

  undefined8 uVar2;

  longlong *plVar3;

  FILE *_File;

  void *_DstBuf;

  undefined8 *puVar4;

  undefined8 local_88;

  undefined8 uStack_80;

  undefined8 local_78;

  ulonglong uStack_70;

  longlong local_68;

  longlong lStack_60;

  longlong local_58;

  ulonglong uStack_50;

  undefined1 local_48;

  undefined7 uStack_47;

  undefined8 local_38;

  ulonglong uStack_30;

  

  uStack_80 = 0;

  local_78 = _DAT_1403033e0;

  uStack_70 = _UNK_1403033e8;

  local_88 = (ulonglong)

             CONCAT16(s_source__14030e088[6],

                      CONCAT24(s_source__14030e088._4_2_,s_source__14030e088._0_4_));

  uVar2 = FUN_14006f590(&local_48,&DAT_1403da658,&local_88);

  puVar4 = param_1;

  if (0xf < (ulonglong)param_1[3]) {

    puVar4 = (undefined8 *)*param_1;

  }

  plVar3 = (longlong *)FUN_140027810(uVar2,puVar4);

  local_68 = *plVar3;

  lStack_60 = plVar3[1];

  local_58 = plVar3[2];

  uStack_50 = plVar3[3];

  plVar3[2] = 0;

  plVar3[3] = 0xf;

  *(undefined1 *)plVar3 = 0;

  FUN_1400c5580(param_1,&local_68);

  if (0xf < uStack_50) {

    if (0xfff < uStack_50 + 1) {

      if (0x1f < (local_68 - *(longlong *)(local_68 + -8)) - 8U) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

    }

    FUN_1402c7088();

  }

  if (0xf < uStack_30) {

    if (0xfff < uStack_30 + 1) {

      if (0x1f < (CONCAT71(uStack_47,local_48) - *(longlong *)(CONCAT71(uStack_47,local_48) + -8)) -

                 8U) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

    }

    FUN_1402c7088();

  }

  local_38 = _DAT_14039caa0;

  uStack_30 = _UNK_14039caa8;

  local_48 = 0;

  if (0xf < uStack_70) {

    if (0xfff < uStack_70 + 1) {

      if (0x1f < (local_88 - *(longlong *)(local_88 - 8)) - 8) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

    }

    FUN_1402c7088();

  }

  puVar4 = param_1;

  if (0xf < (ulonglong)param_1[3]) {

    puVar4 = (undefined8 *)*param_1;

  }

  _File = (FILE *)FUN_1402ce0f8(puVar4,&DAT_14039be7c);

  if (_File == (FILE *)0x0) {

    FUN_140027900(param_1);

    _DstBuf = (void *)0x0;

  }

  else {

    FUN_1402cea4c(_File,0,2);

    iVar1 = FUN_1402cf00c(_File);

    FUN_1402cea4c(_File,0,0);

    _DstBuf = (void *)thunk_FUN_1402c704c((longlong)iVar1);

    if (0 < iVar1) {

      fread(_DstBuf,(longlong)iVar1,1,_File);

    }

    if (param_2 != (int *)0x0) {

      *param_2 = iVar1;

    }

    FUN_1402ce288(_File);

    FUN_140027900(param_1);

  }

  return _DstBuf;

}




