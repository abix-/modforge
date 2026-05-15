// Address: 0x14005d480
// Ghidra name: FUN_14005d480
// ============ 0x14005d480 FUN_14005d480 (size=641) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_14005d480(longlong param_1,char param_2)



{

  int iVar1;

  undefined4 uVar2;

  int iVar3;

  undefined8 in_stack_ffffffffffffffc8;

  uint7 uVar4;

  longlong local_28;

  undefined8 uStack_20;

  undefined8 local_18;

  ulonglong uStack_10;

  

  iVar3 = *(int *)(param_1 + 0x18) + 1;

  *(int *)(param_1 + 0x18) = iVar3;

  iVar1 = *(int *)(param_1 + 0xc);

  uVar4 = (uint7)((ulonglong)in_stack_ffffffffffffffc8 >> 8);

  if (iVar1 == 0xe) {

    if (iVar3 == 0x3c) {

      local_18 = _DAT_1403040c0;

      uStack_10 = _UNK_1403040c8;

      local_28._0_1_ = s_BriefcaseOpen_140306998[0];

      local_28._1_1_ = s_BriefcaseOpen_140306998[1];

      local_28._2_1_ = s_BriefcaseOpen_140306998[2];

      local_28._3_1_ = s_BriefcaseOpen_140306998[3];

      local_28._4_1_ = s_BriefcaseOpen_140306998[4];

      local_28._5_1_ = s_BriefcaseOpen_140306998[5];

      local_28._6_1_ = s_BriefcaseOpen_140306998[6];

      local_28._7_1_ = s_BriefcaseOpen_140306998[7];

      uStack_20._0_5_ = CONCAT14(s_BriefcaseOpen_140306998[0xc],s_BriefcaseOpen_140306998._8_4_);

      uStack_20 = (ulonglong)(uint5)uStack_20;

      FUN_140040ca0(&local_28,100,0,DAT_14039ca44,(ulonglong)uVar4 << 8);

      if (0xf < uStack_10) {

        if (0xfff < uStack_10 + 1) {

          if (0x1f < (local_28 - *(longlong *)(local_28 + -8)) - 8U) {

                    /* WARNING: Subroutine does not return */

            _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

          }

        }

        FUN_1402c7088();

      }

      local_18 = 0xd;

      uStack_10 = 0xf;

      local_28._0_1_ = s_BriefcaseOpen_140306998[0];

      local_28._1_1_ = s_BriefcaseOpen_140306998[1];

      local_28._2_1_ = s_BriefcaseOpen_140306998[2];

      local_28._3_1_ = s_BriefcaseOpen_140306998[3];

      local_28._4_1_ = s_BriefcaseOpen_140306998[4];

      local_28._5_1_ = s_BriefcaseOpen_140306998[5];

      local_28._6_1_ = s_BriefcaseOpen_140306998[6];

      local_28._7_1_ = s_BriefcaseOpen_140306998[7];

      uStack_20._0_5_ = CONCAT14(s_BriefcaseOpen_140306998[0xc],s_BriefcaseOpen_140306998._8_4_);

      uStack_20 = (ulonglong)(uint5)uStack_20;

      uVar2 = FUN_14006fe60(&local_28);

      *(undefined4 *)(param_1 + 0x3c) = uVar2;

      FUN_1400a8a00(param_1);

      return;

    }

  }

  else if (iVar1 == 0xf) {

    if (iVar3 == 0x3c) {

      local_18 = _DAT_1403040c0;

      uStack_10 = _UNK_1403040c8;

      local_28._0_1_ = s_BriefcaseOpen_140306998[0];

      local_28._1_1_ = s_BriefcaseOpen_140306998[1];

      local_28._2_1_ = s_BriefcaseOpen_140306998[2];

      local_28._3_1_ = s_BriefcaseOpen_140306998[3];

      local_28._4_1_ = s_BriefcaseOpen_140306998[4];

      local_28._5_1_ = s_BriefcaseOpen_140306998[5];

      local_28._6_1_ = s_BriefcaseOpen_140306998[6];

      local_28._7_1_ = s_BriefcaseOpen_140306998[7];

      uStack_20._0_5_ = CONCAT14(s_BriefcaseOpen_140306998[0xc],s_BriefcaseOpen_140306998._8_4_);

      uStack_20 = (ulonglong)(uint5)uStack_20;

      FUN_140040ca0(&local_28,100,0,DAT_14039ca44,(ulonglong)uVar4 << 8);

      if (0xf < uStack_10) {

        if (0xfff < uStack_10 + 1) {

          if (0x1f < (local_28 - *(longlong *)(local_28 + -8)) - 8U) {

                    /* WARNING: Subroutine does not return */

            _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

          }

        }

        FUN_1402c7088();

      }

      local_18 = 9;

      uStack_10 = 0xf;

      local_28._0_1_ = s_ChestOpen_1403069a8[0];

      local_28._1_1_ = s_ChestOpen_1403069a8[1];

      local_28._2_1_ = s_ChestOpen_1403069a8[2];

      local_28._3_1_ = s_ChestOpen_1403069a8[3];

      local_28._4_1_ = s_ChestOpen_1403069a8[4];

      local_28._5_1_ = s_ChestOpen_1403069a8[5];

      local_28._6_1_ = s_ChestOpen_1403069a8[6];

      local_28._7_1_ = s_ChestOpen_1403069a8[7];

      uStack_20 = (ulonglong)(byte)s_ChestOpen_1403069a8[8];

      uVar2 = FUN_14006fe60(&local_28);

      *(undefined4 *)(param_1 + 0x3c) = uVar2;

      FUN_1400a8a00(param_1);

      return;

    }

  }

  else if ((((iVar1 == 7) && (param_2 != '\0')) && (599 < iVar3)) &&

          ((iVar3 == (iVar3 / 0x1e) * 0x1e &&

           (*(int *)(param_1 + 0x44) = *(int *)(param_1 + 0x44) + -1, *(int *)(param_1 + 0x44) < 1))

          )) {

    *(undefined1 *)(param_1 + 0x11) = 1;

  }

  FUN_1400a8a00(param_1);

  return;

}




