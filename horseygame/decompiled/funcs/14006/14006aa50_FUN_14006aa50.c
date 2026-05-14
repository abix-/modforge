// Address: 0x14006aa50
// Ghidra name: FUN_14006aa50
// ============ 0x14006aa50 FUN_14006aa50 (size=345) ============


void FUN_14006aa50(longlong param_1,int param_2)



{

  int iVar1;

  int iVar2;

  longlong lVar3;

  undefined8 uVar4;

  undefined *puVar5;

  longlong lVar6;

  float fVar7;

  undefined8 in_stack_ffffffffffffffc8;

  undefined4 uVar8;

  longlong local_28 [3];

  ulonglong local_10;

  

  uVar8 = (undefined4)((ulonglong)in_stack_ffffffffffffffc8 >> 0x20);

  lVar6 = (longlong)param_2;

  lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x130) + lVar6 * 8);

  if (((*(char *)(lVar3 + 0x204) == '\0') && (lVar3 != *(longlong *)(param_1 + 0x2d0))) &&

     (lVar3 != *(longlong *)(param_1 + 0x2d8))) {

    iVar1 = *(int *)(*(longlong *)(param_1 + 0x298) + lVar6 * 4);

    iVar2 = *(int *)(*(longlong *)(param_1 + 0x268) + lVar6 * 4);

    if (iVar1 == 2) {

      puVar5 = (&PTR_s_Let_me_ride_that_horse_1403d9230)[iVar2];

    }

    else if (iVar1 == 1) {

      puVar5 = (&PTR_s_That__s_is_a_sure_fire_winner_1403d91c0)[iVar2];

    }

    else {

      puVar5 = (&PTR_s_Fancy_a_flutter_on_the_gee_gees__1403d9180)[iVar2];

    }

    uVar4 = FUN_14008d760(local_28,puVar5,

                          *(undefined8 *)

                           (param_1 + 600 +

                           (longlong)*(int *)(*(longlong *)(param_1 + 0x280) + lVar6 * 4) * 8));

    FUN_1400d0c80(param_1,lVar3,uVar4,0,CONCAT44(uVar8,DAT_140303758));

    if (0xf < local_10) {

      if (0xfff < local_10 + 1) {

        if (0x1f < (local_28[0] - *(longlong *)(local_28[0] + -8)) - 8U) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

      }

      FUN_1402c7088();

    }

    fVar7 = ((float)(DAT_14030b680 + DAT_1403eda00) - *(float *)(param_1 + 0x1d0)) * DAT_140303354;

    if (*(float *)(param_1 + 0x1c8) <= fVar7) {

      fVar7 = *(float *)(param_1 + 0x1c8);

    }

    *(float *)(param_1 + 0x1c8) = fVar7;

  }

  return;

}




