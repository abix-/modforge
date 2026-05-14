// Address: 0x14003e780
// Ghidra name: FUN_14003e780
// ============ 0x14003e780 FUN_14003e780 (size=564) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_14003e780(longlong param_1)



{

  char *_Str;

  longlong *plVar1;

  undefined8 uVar2;

  ulonglong uVar3;

  undefined4 uVar4;

  int iVar5;

  longlong lVar6;

  size_t sVar7;

  int iVar8;

  float local_res10 [2];

  longlong local_res18;

  longlong local_res20;

  undefined8 in_stack_ffffffffffffff98;

  undefined8 local_58;

  undefined8 uStack_50;

  undefined8 local_48;

  ulonglong uStack_40;

  

  uVar3 = _UNK_1403033d8;

  uVar2 = _DAT_1403033d0;

  iVar8 = 3;

  do {

    uVar4 = (undefined4)((ulonglong)in_stack_ffffffffffffff98 >> 0x20);

    local_res20 = FUN_1402c704c(0x498);

    if (local_res20 == 0) {

      lVar6 = 0;

    }

    else {

      lVar6 = FUN_1400aac60(local_res20);

    }

    uStack_50 = 0;

    local_48 = uVar2;

    uStack_40 = uVar3;

    local_58 = (ulonglong)CONCAT24(s_jockey_140304ee0._4_2_,s_jockey_140304ee0._0_4_);

    local_res18 = lVar6;

    FUN_1400c6580(5);

    FUN_1400b2ee0(lVar6,&local_58);

    if (0xf < uStack_40) {

      if (0xfff < uStack_40 + 1) {

        if (0x1f < (local_58 - *(longlong *)(local_58 - 8)) - 8) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

      }

      FUN_1402c7088();

    }

    local_res10[0] = (float)iVar8;

    local_res10[1] = 5.0;

    FUN_1400b6610(lVar6,local_res10);

    in_stack_ffffffffffffff98 = CONCAT44(uVar4,0xffffffff);

    uVar4 = FUN_1400c7600(0,7,0xffffffff,0xffffffff,in_stack_ffffffffffffff98);

    *(undefined4 *)(lVar6 + 0x1f8) = uVar4;

    iVar5 = FUN_1400c6580(0x1a);

    _Str = (&PTR_DAT_1403d4460)[iVar5];

    local_58 = 0;

    uStack_50 = 0;

    local_48 = 0;

    uStack_40 = 0;

    sVar7 = strlen(_Str);

    FUN_140027e30(&local_58,_Str,sVar7);

    FUN_1400cf950(param_1,lVar6);

    if (0xf < uStack_40) {

      if (0xfff < uStack_40 + 1) {

        if (0x1f < (local_58 - *(longlong *)(local_58 + -8)) - 8) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

      }

      FUN_1402c7088();

    }

    *(undefined1 *)(lVar6 + 0x160) = 1;

    plVar1 = *(longlong **)(param_1 + 0x138);

    if (plVar1 == *(longlong **)(param_1 + 0x140)) {

      FUN_140030680(param_1 + 0x130,plVar1,&local_res18);

    }

    else {

      *plVar1 = lVar6;

      *(longlong *)(param_1 + 0x138) = *(longlong *)(param_1 + 0x138) + 8;

    }

    iVar8 = iVar8 + 2;

  } while (iVar8 < 0xd);

  return;

}




