// Address: 0x140061920
// Ghidra name: FUN_140061920
// ============ 0x140061920 FUN_140061920 (size=1549) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_140061920(longlong param_1,int param_2)



{

  int iVar1;

  undefined8 uVar2;

  char cVar3;

  undefined8 uVar4;

  undefined8 uVar5;

  undefined8 in_stack_ffffffffffffffc8;

  undefined4 uVar6;

  char *local_28;

  undefined8 uStack_20;

  undefined8 local_18;

  ulonglong uStack_10;

  

  uVar6 = (undefined4)((ulonglong)in_stack_ffffffffffffffc8 >> 0x20);

  cVar3 = FUN_1400d0c50();

  if (cVar3 == '\0') {

    return;

  }

  if (*(longlong *)(param_1 + 0x148) !=

      *(longlong *)(*(longlong *)(param_1 + 0x130) + (longlong)param_2 * 8)) {

    return;

  }

  if (*(int *)(param_1 + 600) < 0x3d) {

    return;

  }

  FUN_1400b87e0();

  iVar1 = *(int *)(param_1 + 0x254);

  if (iVar1 == 2) {

    if ((*(longlong *)(param_1 + 0x138) - *(longlong *)(param_1 + 0x130) & 0xfffffffffffffff8U) == 8

       ) {

      if (*(char *)(DAT_1403f4e00 + 0x262) == '\0') {

        *(undefined4 *)(param_1 + 0x1f8) = 0;

        if (DAT_1403eaa10 == 0) {

          local_28 = (char *)0x0;

          uStack_20 = 0;

          local_18 = 0;

          uStack_10 = 0;

          local_28 = (char *)FUN_1400285e0(0x30);

          uVar2 = _UNK_140307608;

          local_18 = _DAT_140303790;

          uStack_10 = _UNK_140303798;

          *(undefined8 *)local_28 = _DAT_140307600;

          *(undefined8 *)(local_28 + 8) = uVar2;

          uVar2 = s_sells_horses_at_a_fair_price_140307610._8_8_;

          *(undefined8 *)(local_28 + 0x10) = s_sells_horses_at_a_fair_price_140307610._0_8_;

          *(undefined8 *)(local_28 + 0x18) = uVar2;

          *(undefined8 *)(local_28 + 0x20) = s_sells_horses_at_a_fair_price_140307610._16_8_;

          *(undefined4 *)(local_28 + 0x28) = s_sells_horses_at_a_fair_price_140307610._24_4_;

          local_28[0x2c] = s_sells_horses_at_a_fair_price_140307610[0x1c];

          local_28[0x2d] = '\0';

          FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_28,0,

                        CONCAT44(uVar6,DAT_140303758));

          if (0xf < uStack_10) {

            if ((0xfff < uStack_10 + 1) &&

               ((char *)0x1f < local_28 + (-8 - *(longlong *)(local_28 + -8)))) {

                    /* WARNING: Subroutine does not return */

              _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

            }

            FUN_1402c7088();

          }

        }

        else {

          uVar2 = *(undefined8 *)(param_1 + 0x148);

          uVar4 = FUN_140086330();

          uVar5 = FUN_140086310(0xf);

          FUN_1400d1c40(param_1,uVar2,"If you had a %slasso%s you could catch a horse",uVar5,uVar4);

        }

        DAT_1403eaa10 = DAT_1403eaa10 + 1 & 0x80000001;

        if (-1 < (int)DAT_1403eaa10) {

          return;

        }

        DAT_1403eaa10 = (DAT_1403eaa10 - 1 | 0xfffffffe) + 1;

        return;

      }

      local_28 = (char *)0x0;

      uStack_20 = 0;

      local_18 = 0;

      uStack_10 = 0;

      local_28 = (char *)FUN_1400285e0(0x20);

      uVar2 = s_Bring_your_horses_140307660._8_8_;

      local_18 = _DAT_1403040f0;

      uStack_10 = _UNK_1403040f8;

      *(undefined8 *)local_28 = s_Bring_your_horses_140307660._0_8_;

      *(undefined8 *)(local_28 + 8) = uVar2;

      local_28[0x10] = s_Bring_your_horses_140307660[0x10];

      local_28[0x11] = '\0';

      FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_28,0,

                    CONCAT44(uVar6,DAT_140303758));

      if (uStack_10 < 0x10) {

        return;

      }

      if ((0xfff < uStack_10 + 1) && ((char *)0x1f < local_28 + (-8 - *(longlong *)(local_28 + -8)))

         ) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

    }

    else {

      local_28 = (char *)0x0;

      uStack_20 = 0;

      local_18 = 0;

      uStack_10 = 0;

      local_28 = (char *)FUN_1400285e0(0x50);

      uVar2 = s_If_you_wanna_compete_in_a_race__d_140307680._8_8_;

      local_18 = _DAT_140306050;

      uStack_10 = _UNK_140306058;

      *(undefined8 *)local_28 = s_If_you_wanna_compete_in_a_race__d_140307680._0_8_;

      *(undefined8 *)(local_28 + 8) = uVar2;

      uVar2 = s_If_you_wanna_compete_in_a_race__d_140307680._24_8_;

      *(undefined8 *)(local_28 + 0x10) = s_If_you_wanna_compete_in_a_race__d_140307680._16_8_;

      *(undefined8 *)(local_28 + 0x18) = uVar2;

      uVar2 = s_If_you_wanna_compete_in_a_race__d_140307680._40_8_;

      *(undefined8 *)(local_28 + 0x20) = s_If_you_wanna_compete_in_a_race__d_140307680._32_8_;

      *(undefined8 *)(local_28 + 0x28) = uVar2;

      uVar2 = s_If_you_wanna_compete_in_a_race__d_140307680._56_8_;

      *(undefined8 *)(local_28 + 0x30) = s_If_you_wanna_compete_in_a_race__d_140307680._48_8_;

      *(undefined8 *)(local_28 + 0x38) = uVar2;

      *(undefined2 *)(local_28 + 0x40) = s_If_you_wanna_compete_in_a_race__d_140307680._64_2_;

      local_28[0x42] = s_If_you_wanna_compete_in_a_race__d_140307680[0x42];

      local_28[0x43] = '\0';

      FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_28,0,

                    CONCAT44(uVar6,DAT_140303758));

      if (uStack_10 < 0x10) {

        return;

      }

      if ((0xfff < uStack_10 + 1) && ((char *)0x1f < local_28 + (-8 - *(longlong *)(local_28 + -8)))

         ) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

    }

  }

  else {

    if (iVar1 == 6) {

      local_28 = (char *)0x0;

      uStack_20 = 0;

      local_18 = 0;

      uStack_10 = 0;

      local_28 = (char *)FUN_1400285e0(0x30);

      uVar2 = s_I_say_it_looks_like_you_could_us_1403076c8._8_8_;

      local_18 = _DAT_1403041a0;

      uStack_10 = _UNK_1403041a8;

      *(undefined8 *)local_28 = s_I_say_it_looks_like_you_could_us_1403076c8._0_8_;

      *(undefined8 *)(local_28 + 8) = uVar2;

      uVar2 = s_I_say_it_looks_like_you_could_us_1403076c8._24_8_;

      *(undefined8 *)(local_28 + 0x10) = s_I_say_it_looks_like_you_could_us_1403076c8._16_8_;

      *(undefined8 *)(local_28 + 0x18) = uVar2;

      *(undefined8 *)(local_28 + 0x20) = s_I_say_it_looks_like_you_could_us_1403076c8._32_8_;

      *(undefined2 *)(local_28 + 0x28) = s_I_say_it_looks_like_you_could_us_1403076c8._40_2_;

      local_28[0x2a] = s_I_say_it_looks_like_you_could_us_1403076c8[0x2a];

      local_28[0x2b] = '\0';

      FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_28,0,

                    CONCAT44(uVar6,DAT_140303758));

      if (0xf < uStack_10) {

        if ((0xfff < uStack_10 + 1) &&

           ((char *)0x1f < local_28 + (-8 - *(longlong *)(local_28 + -8)))) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

        FUN_1402c7088();

      }

      FUN_1400d1c40(param_1,*(undefined8 *)(param_1 + 0x148),

                    "Scoop this dung into the cart and I\'ll pay you $%d",0x32);

      return;

    }

    if (iVar1 == 7) {

      local_28 = (char *)0x0;

      uStack_20 = 0;

      local_18 = 0;

      uStack_10 = 0;

      local_28 = (char *)FUN_1400285e0(0x20);

      uVar2 = s_Good_luck__pardner_140307730._8_8_;

      local_18 = _DAT_140303410;

      uStack_10 = _UNK_140303418;

      *(undefined8 *)local_28 = s_Good_luck__pardner_140307730._0_8_;

      *(undefined8 *)(local_28 + 8) = uVar2;

      *(undefined2 *)(local_28 + 0x10) = s_Good_luck__pardner_140307730._16_2_;

      local_28[0x12] = '\0';

      FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_28,0,

                    CONCAT44(uVar6,DAT_140303758));

      if (uStack_10 < 0x10) {

        return;

      }

      if ((0xfff < uStack_10 + 1) && ((char *)0x1f < local_28 + (-8 - *(longlong *)(local_28 + -8)))

         ) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

    }

    else {

      if (iVar1 != 8) {

        return;

      }

      local_18 = _DAT_140304090;

      uStack_10 = _UNK_140304098;

      local_28 = (char *)0x7461687720776f4e;

      uStack_20 = 0;

      FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),&local_28,0,

                    CONCAT44(uVar6,DAT_140303758));

      if (uStack_10 < 0x10) {

        return;

      }

      if ((0xfff < uStack_10 + 1) && ((char *)0x1f < local_28 + (-8 - *(longlong *)(local_28 + -8)))

         ) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

    }

  }

  FUN_1402c7088();

  return;

}




