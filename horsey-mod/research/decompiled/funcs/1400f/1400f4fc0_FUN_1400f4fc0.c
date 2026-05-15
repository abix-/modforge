// Address: 0x1400f4fc0
// Ghidra name: FUN_1400f4fc0
// ============ 0x1400f4fc0 FUN_1400f4fc0 (size=682) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_1400f4fc0(longlong param_1)



{

  longlong *plVar1;

  longlong *plVar2;

  int iVar3;

  undefined4 uVar4;

  longlong lVar5;

  undefined8 in_stack_ffffffffffffffc8;

  undefined8 local_28;

  undefined8 uStack_20;

  undefined8 local_18;

  ulonglong uStack_10;

  

  uVar4 = (undefined4)((ulonglong)in_stack_ffffffffffffffc8 >> 0x20);

  FUN_1400d01d0(param_1,"Doctor Horse PhD");

  *(undefined4 *)(*(longlong *)(param_1 + 0x148) + 0x284) = 3;

  *(undefined4 *)(*(longlong *)(param_1 + 0x148) + 0xc0) = DAT_1403dc074;

  iVar3 = FUN_14005e250(0x1f);

  *(undefined4 *)(*(longlong *)(param_1 + 0x148) + 0xcc + (longlong)iVar3 * 4) = 0x1f;

  FUN_1400b3070(*(undefined8 *)(param_1 + 0x148));

  lVar5 = FUN_1402c704c();

  if (lVar5 == 0) {

    lVar5 = 0;

  }

  else {

    lVar5 = FUN_1400aac60(lVar5);

  }

  plVar1 = (longlong *)(param_1 + 600);

  *plVar1 = lVar5;

  *(undefined4 *)(lVar5 + 0xc0) = DAT_1403dc064;

  uStack_20 = 0;

  local_18 = _DAT_140304080;

  uStack_10 = _UNK_140304088;

  local_28 = (ulonglong)CONCAT14(s_human_140303b0c[4],s_human_140303b0c._0_4_);

  FUN_1400a2ed0(*plVar1 + 0x2b8,&local_28);

  if (0xf < uStack_10) {

    if (0xfff < uStack_10 + 1) {

      if (0x1f < (local_28 - *(longlong *)(local_28 - 8)) - 8) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

    }

    FUN_1402c7088();

  }

  *(undefined4 *)(*plVar1 + 0x1fc) = 2;

  lVar5 = *plVar1;

  uVar4 = FUN_1400c7600(0,6,0xffffffff,0xffffffff,CONCAT44(uVar4,0xffffffff));

  *(undefined4 *)(lVar5 + 0x1f8) = uVar4;

  uStack_20 = 0;

  local_18 = _DAT_1403033e0;

  uStack_10 = _UNK_1403033e8;

  local_28 = (ulonglong)

             CONCAT16(s_Sweetie_140307ec8[6],

                      CONCAT24(s_Sweetie_140307ec8._4_2_,s_Sweetie_140307ec8._0_4_));

  FUN_1400cf950(param_1,*plVar1);

  if (0xf < uStack_10) {

    if (0xfff < uStack_10 + 1) {

      if (0x1f < (local_28 - *(longlong *)(local_28 - 8)) - 8) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

    }

    FUN_1402c7088();

  }

  FUN_1400b3070(*plVar1);

  FUN_1400b8f90(*plVar1,3);

  *(undefined4 *)(*plVar1 + 0x284) = 10;

  FUN_1400278e0(*plVar1 + 0x168,"SweetieVoice");

  plVar2 = *(longlong **)(param_1 + 0x138);

  if (plVar2 == *(longlong **)(param_1 + 0x140)) {

    FUN_140030680(param_1 + 0x130,plVar2,plVar1);

  }

  else {

    *plVar2 = *plVar1;

    *(longlong *)(param_1 + 0x138) = *(longlong *)(param_1 + 0x138) + 8;

  }

  FUN_1400cc9d0(param_1,0x11,DAT_140312f18,DAT_1403065b8);

  return;

}




