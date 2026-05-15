// Address: 0x1400db740
// Ghidra name: FUN_1400db740
// ============ 0x1400db740 FUN_1400db740 (size=952) ============


void FUN_1400db740(longlong param_1)



{

  char *_Str;

  longlong *plVar1;

  undefined *puVar2;

  undefined4 uVar3;

  int iVar4;

  int *piVar5;

  longlong lVar6;

  undefined8 uVar7;

  ulonglong uVar8;

  longlong *plVar9;

  longlong local_res8;

  undefined8 in_stack_ffffffffffffffc8;

  longlong local_28;

  undefined8 uStack_20;

  undefined8 local_18;

  ulonglong uStack_10;

  

  uVar3 = (undefined4)((ulonglong)in_stack_ffffffffffffffc8 >> 0x20);

  if (*(int *)(param_1 + 600) == 0) {

    FUN_1400cc9d0(param_1,0,DAT_14030339c,DAT_14030fc00);

    FUN_1400cc9d0(param_1,0,DAT_14030339c,DAT_140303fb8);

    FUN_1400cc9d0(param_1,0,DAT_14030fc0c,DAT_14030fc00);

    FUN_1400cc9d0(param_1,0,DAT_14030fc0c,DAT_140303fb8);

  }

  else {

    piVar5 = (int *)&DAT_1403d9530;

    if (0xf < DAT_1403d9548) {

      piVar5 = DAT_1403d9530;

    }

    if ((DAT_1403d9540 != 4) || (*piVar5 != 0x636f7041)) {

      if (*(longlong *)(param_1 + 0x148) == 0) {

        FUN_1400d01d0(param_1,(&PTR_s_Player_1_1403da9e0)[(longlong)*(int *)(param_1 + 600) * 10]);

      }

      FUN_1400c7c60(*(undefined4 *)(*(longlong *)(param_1 + 0x148) + 0x1f8),

                    *(undefined4 *)(param_1 + 600));

      _Str = (&PTR_s_fest_horse_1403da9e8)[(longlong)*(int *)(param_1 + 600) * 10];

      local_28 = 0;

      uStack_20 = 0;

      local_18 = 0;

      uStack_10 = 0;

      strlen(_Str);

      FUN_140027e30(&local_28,_Str);

      FUN_1400a2ed0(param_1 + 0x25c,&local_28);

      if (0xf < uStack_10) {

        if ((0xfff < uStack_10 + 1) && (0x1f < (local_28 - *(longlong *)(local_28 + -8)) - 8U)) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

        FUN_1402c7088();

      }

      piVar5 = (int *)&DAT_1403d9530;

      if (0xf < DAT_1403d9548) {

        piVar5 = DAT_1403d9530;

      }

      if (((DAT_1403d9540 != 4) || (*piVar5 != 0x636f7041)) && (*(int *)(param_1 + 600) < 8)) {

        if (*(int *)(param_1 + 600) != 1) {

          local_res8 = FUN_1402c704c(0x498);

          if (local_res8 == 0) {

            lVar6 = 0;

          }

          else {

            lVar6 = FUN_1400aac60(local_res8);

          }

          local_res8 = lVar6;

          FUN_1400b35f0(lVar6,param_1 + 0x25c);

          FUN_1400b3070(lVar6);

          uVar3 = FUN_1400c7600(1,*(undefined4 *)(param_1 + 600),*(undefined4 *)(param_1 + 600),

                                0xffffffff,CONCAT44(uVar3,0xffffffff));

          *(undefined4 *)(lVar6 + 0x1f8) = uVar3;

          iVar4 = FUN_1400c6580(4);

          *(int *)(lVar6 + 0x1fc) = iVar4 + 1;

          plVar1 = *(longlong **)(param_1 + 0x138);

          if (plVar1 == *(longlong **)(param_1 + 0x140)) {

            FUN_140030680(param_1 + 0x130,plVar1,&local_res8);

          }

          else {

            *plVar1 = lVar6;

            *(longlong *)(param_1 + 0x138) = *(longlong *)(param_1 + 0x138) + 8;

          }

          FUN_1400cf620(param_1,lVar6,3);

        }

        iVar4 = (int)(*(longlong *)(param_1 + 0x138) - *(longlong *)(param_1 + 0x130) >> 3);

        if (iVar4 < 5) {

          uVar8 = (ulonglong)(5 - iVar4);

          do {

            FUN_1400dbcb0(param_1);

            uVar8 = uVar8 - 1;

          } while (uVar8 != 0);

        }

      }

      puVar2 = (&PTR_s_My_House_14030ec3f_1_1403da9d0)[(longlong)*(int *)(param_1 + 600) * 10];

      FUN_1400cf970(param_1,*(undefined8 *)(param_1 + 0x148));

      uVar7 = FUN_14008d760(&local_28,puVar2);

      FUN_1400c5580(param_1 + 0x18,uVar7);

      if (0xf < uStack_10) {

        if ((0xfff < uStack_10 + 1) && (0x1f < (local_28 - *(longlong *)(local_28 + -8)) - 8U)) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

        FUN_1402c7088();

      }

      if (*(int *)(param_1 + 600) == 4) {

        *(undefined4 *)(*(longlong *)(param_1 + 0x148) + 0x284) = 2;

        plVar1 = *(longlong **)(param_1 + 0x138);

        for (plVar9 = *(longlong **)(param_1 + 0x130); plVar9 != plVar1; plVar9 = plVar9 + 1) {

          lVar6 = *plVar9;

          *(undefined2 *)(lVar6 + 0x32c) = 0x201;

          *(undefined2 *)(lVar6 + 0x41c) = 0x201;

          FUN_1400b3070();

        }

      }

    }

  }

  return;

}




