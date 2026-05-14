// Address: 0x14008fce0
// Ghidra name: FUN_14008fce0
// ============ 0x14008fce0 FUN_14008fce0 (size=477) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined8 FUN_14008fce0(longlong param_1)



{

  bool bVar1;

  int iVar2;

  undefined4 uVar3;

  longlong lVar4;

  char *_Str;

  ulonglong in_stack_ffffffffffffffc8;

  longlong local_28;

  ulonglong uStack_20;

  undefined8 local_18;

  ulonglong uStack_10;

  

  lVar4 = *(longlong *)

           (*(longlong *)(DAT_1403fb0d8 + 0x438) + 8 + (longlong)*(int *)(param_1 + 8) * 8);

  *(longlong *)(param_1 + 0x278) = lVar4;

  _Str = "  Exit";

  if (lVar4 != 0) {

    _Str = "Paddock";

  }

  strlen(_Str);

  FUN_140027f50(*(longlong *)(param_1 + 0x60) + 0xa30,_Str);

  if (DAT_1403f3110 != 0) {

    FUN_1400c8d90();

  }

  if (*(longlong *)(param_1 + 0x3a8) == 0) {

    iVar2 = FUN_1400c5f50(*(int *)(param_1 + 0x268) + -1,0);

    lVar4 = *(longlong *)(param_1 + 0x390 + (longlong)iVar2 * 8);

    if (lVar4 == 0) {

      lVar4 = FUN_140106bc0(DAT_1403fb0d8,*(undefined4 *)(param_1 + 8));

      *(longlong *)(param_1 + 0x390 + (longlong)iVar2 * 8) = lVar4;

    }

    *(longlong *)(param_1 + 0x3a8) = lVar4;

  }

  uVar3 = 0xffffffff;

  *(undefined4 *)(param_1 + 0x2a8) = 0xffffffff;

  *(undefined1 *)(param_1 + 0x2b0) = 0;

  *(undefined1 *)(param_1 + 600) = 0;

  *(undefined1 *)(param_1 + 0x259) = DAT_1403d959a;

  *(undefined4 *)(param_1 + 0x3d0) = 0;

  *(undefined1 *)(param_1 + 0x264) = 0;

  *(undefined4 *)(param_1 + 0x230) = 0xffffffff;

  bVar1 = 0 < DAT_1403eded8;

  if (bVar1) {

    local_18 = _DAT_1403033f0;

    uStack_10 = _UNK_1403033f8;

    local_28._0_1_ = s_OnYourMark_14030bc10[0];

    local_28._1_1_ = s_OnYourMark_14030bc10[1];

    local_28._2_1_ = s_OnYourMark_14030bc10[2];

    local_28._3_1_ = s_OnYourMark_14030bc10[3];

    local_28._4_1_ = s_OnYourMark_14030bc10[4];

    local_28._5_1_ = s_OnYourMark_14030bc10[5];

    local_28._6_1_ = s_OnYourMark_14030bc10[6];

    local_28._7_1_ = s_OnYourMark_14030bc10[7];

    uStack_20 = (ulonglong)(ushort)s_OnYourMark_14030bc10._8_2_;

    uVar3 = FUN_140040ca0(&local_28,100,0,DAT_14039ca44,

                          in_stack_ffffffffffffffc8 & 0xffffffffffffff00);

  }

  *(undefined4 *)(param_1 + 0x2f4) = uVar3;

  if ((bVar1) && (0xf < uStack_10)) {

    if (0xfff < uStack_10 + 1) {

      if (0x1f < (local_28 - *(longlong *)(local_28 + -8)) - 8U) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

    }

    FUN_1402c7088();

  }

  FUN_14008ffc0(param_1);

  return 1;

}




