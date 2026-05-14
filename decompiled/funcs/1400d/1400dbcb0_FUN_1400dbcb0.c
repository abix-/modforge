// Address: 0x1400dbcb0
// Ghidra name: FUN_1400dbcb0
// ============ 0x1400dbcb0 FUN_1400dbcb0 (size=345) ============


void FUN_1400dbcb0(longlong param_1)



{

  char *_Str;

  longlong *plVar1;

  undefined4 uVar2;

  longlong lVar3;

  size_t sVar4;

  longlong local_res8;

  undefined8 in_stack_ffffffffffffffc8;

  longlong local_28 [4];

  

  uVar2 = (undefined4)((ulonglong)in_stack_ffffffffffffffc8 >> 0x20);

  local_res8 = FUN_1402c704c(0x498);

  if (local_res8 == 0) {

    lVar3 = 0;

  }

  else {

    lVar3 = FUN_1400aac60(local_res8);

  }

  _Str = (&PTR_s_fest_horse_1403da9e8)[(longlong)*(int *)(param_1 + 600) * 10];

  local_28[0] = 0;

  local_28[1] = 0;

  local_28[2] = 0;

  local_28[3] = 0;

  local_res8 = lVar3;

  sVar4 = strlen(_Str);

  FUN_140027e30(local_28,_Str,sVar4);

  FUN_1400c6580(5);

  FUN_1400b2ee0(lVar3,local_28);

  if (0xf < (ulonglong)local_28[3]) {

    if (0xfff < local_28[3] + 1U) {

      if (0x1f < (local_28[0] - *(longlong *)(local_28[0] + -8)) - 8U) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

    }

    FUN_1402c7088();

  }

  uVar2 = FUN_1400c7600(1,*(undefined4 *)(param_1 + 600),*(undefined4 *)(param_1 + 600),0xffffffff,

                        CONCAT44(uVar2,0xffffffff));

  *(undefined4 *)(lVar3 + 0x1f8) = uVar2;

  plVar1 = *(longlong **)(param_1 + 0x138);

  if (plVar1 == *(longlong **)(param_1 + 0x140)) {

    FUN_140030680(param_1 + 0x130,plVar1,&local_res8);

  }

  else {

    *plVar1 = lVar3;

    *(longlong *)(param_1 + 0x138) = *(longlong *)(param_1 + 0x138) + 8;

  }

  FUN_1400cf620(param_1,lVar3,3);

  return;

}




