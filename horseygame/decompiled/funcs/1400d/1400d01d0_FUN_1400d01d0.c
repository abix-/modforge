// Address: 0x1400d01d0
// Ghidra name: FUN_1400d01d0
// ============ 0x1400d01d0 FUN_1400d01d0 (size=525) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



longlong FUN_1400d01d0(longlong param_1,char *param_2,undefined4 param_3,undefined4 param_4)



{

  longlong *plVar1;

  longlong *plVar2;

  undefined4 uVar3;

  longlong lVar4;

  longlong lVar5;

  undefined8 in_stack_ffffffffffffffb8;

  undefined8 local_38;

  undefined8 uStack_30;

  undefined8 local_28;

  ulonglong uStack_20;

  

  uVar3 = (undefined4)((ulonglong)in_stack_ffffffffffffffb8 >> 0x20);

  lVar4 = FUN_1402c704c(0x498);

  lVar5 = 0;

  if (lVar4 != 0) {

    lVar5 = FUN_1400aac60(lVar4);

  }

  plVar1 = (longlong *)(param_1 + 0x148);

  *plVar1 = lVar5;

  *(undefined4 *)(lVar5 + 0xc0) = param_4;

  uStack_30 = 0;

  local_28 = _DAT_140304080;

  uStack_20 = _UNK_140304088;

  local_38 = (ulonglong)CONCAT14(s_human_140303b0c[4],s_human_140303b0c._0_4_);

  FUN_1400c6580(5);

  FUN_1400b2ee0(*plVar1,&local_38);

  if (0xf < uStack_20) {

    if (0xfff < uStack_20 + 1) {

      if (0x1f < (local_38 - *(longlong *)(local_38 - 8)) - 8) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

    }

    FUN_1402c7088();

  }

  lVar5 = *plVar1;

  uVar3 = FUN_1400c7600(0,param_3,param_3,0xffffffff,CONCAT44(uVar3,0xffffffff));

  *(undefined4 *)(lVar5 + 0x1f8) = uVar3;

  *(undefined4 *)(*plVar1 + 0x284) = 0;

  local_38 = 0;

  uStack_30 = 0;

  local_28 = 0;

  uStack_20 = 0;

  strlen(param_2);

  FUN_140027e30(&local_38,param_2);

  if (*plVar1 != 0) {

    FUN_1400c7910(*(undefined4 *)(*plVar1 + 0x1f8),&local_38);

  }

  if (0xf < uStack_20) {

    if (0xfff < uStack_20 + 1) {

      if (0x1f < (local_38 - *(longlong *)(local_38 + -8)) - 8) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

    }

    FUN_1402c7088();

  }

  plVar2 = *(longlong **)(param_1 + 0x138);

  if (plVar2 == *(longlong **)(param_1 + 0x140)) {

    FUN_140030680((longlong *)(param_1 + 0x130),plVar2,plVar1);

  }

  else {

    *plVar2 = *plVar1;

    *(longlong *)(param_1 + 0x138) = *(longlong *)(param_1 + 0x138) + 8;

  }

  FUN_1400d03f0(param_1,(int)(*(longlong *)(param_1 + 0x138) - *(longlong *)(param_1 + 0x130) >> 3)

                        + -1);

  return *plVar1;

}




