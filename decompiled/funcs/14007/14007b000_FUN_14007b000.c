// Address: 0x14007b000
// Ghidra name: FUN_14007b000
// ============ 0x14007b000 FUN_14007b000 (size=593) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



bool FUN_14007b000(longlong param_1,int param_2,int param_3)



{

  char cVar1;

  undefined4 uVar2;

  longlong lVar3;

  undefined8 uVar4;

  bool bVar5;

  ulonglong in_stack_ffffffffffffffc8;

  longlong local_28;

  undefined8 uStack_20;

  undefined8 local_18;

  ulonglong uStack_10;

  

  lVar3 = (longlong)param_2;

  if (*(char *)(param_1 + 0x2a8) == '\0') {

    if (((param_3 == 3) && (*(int *)(param_1 + 0x250) == 2)) &&

       (cVar1 = FUN_1400b7660(*(undefined8 *)(*(longlong *)(param_1 + 0x130) + lVar3 * 8),1,0),

       cVar1 != '\0')) {

      lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x130) + lVar3 * 8);

      *(longlong *)(param_1 + 0x260) = lVar3;

      *(undefined1 *)(lVar3 + 0x1a) = 0;

      *(int *)(param_1 + 0x270) = param_2;

      uVar2 = FUN_1400b76e0(*(undefined8 *)(param_1 + 0x260));

      *(undefined4 *)(param_1 + 0x280) = uVar2;

      *(undefined8 *)(param_1 + 0x288) = 0;

      *(undefined8 *)(param_1 + 0x250) = 3;

      *(undefined4 *)(param_1 + 600) = 0xe10;

      *(undefined4 *)(param_1 + 0x1b0) = 0;

      local_18 = _DAT_1403040c0;

      uStack_10 = _UNK_1403040c8;

      local_28._0_1_ = s_NewChallenger_14030a750[0];

      local_28._1_1_ = s_NewChallenger_14030a750[1];

      local_28._2_1_ = s_NewChallenger_14030a750[2];

      local_28._3_1_ = s_NewChallenger_14030a750[3];

      local_28._4_1_ = s_NewChallenger_14030a750[4];

      local_28._5_1_ = s_NewChallenger_14030a750[5];

      local_28._6_1_ = s_NewChallenger_14030a750[6];

      local_28._7_1_ = s_NewChallenger_14030a750[7];

      uStack_20 = (ulonglong)

                  CONCAT14(s_NewChallenger_14030a750[0xc],s_NewChallenger_14030a750._8_4_);

      FUN_140040ca0(&local_28,100,0xffffffce,DAT_14039ca44,

                    in_stack_ffffffffffffffc8 & 0xffffffffffffff00);

      if (0xf < uStack_10) {

        if ((0xfff < uStack_10 + 1) && (0x1f < (local_28 - *(longlong *)(local_28 + -8)) - 8U)) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

        FUN_1402c7088();

      }

      cVar1 = FUN_1400b7730(*(undefined8 *)(param_1 + 0x260));

      uVar4 = 0x13;

      if (cVar1 == '\0') {

        uVar4 = 0x1e;

      }

      FUN_1400d1e10(param_1,param_2,uVar4);

      return true;

    }

    bVar5 = param_3 == 0;

  }

  else {

    if ((param_3 == 3) &&

       (cVar1 = FUN_1400b7660(*(undefined8 *)(*(longlong *)(param_1 + 0x130) + lVar3 * 8),1,0),

       cVar1 != '\0')) {

      *(undefined1 *)(param_1 + 0x2a8) = 0;

      lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x130) + lVar3 * 8);

      *(longlong *)(param_1 + 0x268) = lVar3;

      *(undefined1 *)(lVar3 + 0x204) = 0;

      *(undefined1 *)(*(longlong *)(param_1 + 0x268) + 0x1a) = 1;

      FUN_1400b6820(*(undefined8 *)(param_1 + 0x268));

      FUN_1400cead0(param_1,*(undefined8 *)(param_1 + 0x268));

      *(undefined1 *)(*(longlong *)(param_1 + 0x268) + 0x1e1) = 1;

      *(undefined8 *)(*(longlong *)(param_1 + 0x268) + 0x1e4) = 0x40c00000;

      *(undefined8 *)(param_1 + 0x250) = 2;

    }

    bVar5 = true;

  }

  return bVar5;

}




