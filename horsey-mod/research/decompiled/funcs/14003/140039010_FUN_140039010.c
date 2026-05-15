// Address: 0x140039010
// Ghidra name: FUN_140039010
// ============ 0x140039010 FUN_140039010 (size=372) ============


void FUN_140039010(longlong param_1)



{

  ulonglong uVar1;

  longlong *plVar2;

  longlong lVar3;

  longlong lVar4;

  ulonglong uVar5;

  ulonglong uVar6;

  ulonglong uVar7;

  

  if (((*(int *)(param_1 + 0x254) == 1) || ((*(int *)(param_1 + 0x254) - 3U & 0xfffffffd) == 0)) &&

     (plVar2 = (longlong *)(param_1 + 0x130), *plVar2 != *(longlong *)(param_1 + 0x138))) {

    *(undefined1 *)(*(longlong *)(*(longlong *)(param_1 + 0x138) + -8) + 0x1e0) = 0;

    FUN_1400b47e0(*(undefined8 *)(*(longlong *)(param_1 + 0x138) + -8));

    lVar4 = *(longlong *)(param_1 + 0x138);

    lVar3 = *plVar2;

    uVar7 = lVar4 - lVar3 >> 3;

    uVar1 = uVar7 - 1;

    if (uVar1 < uVar7) {

      *(ulonglong *)(param_1 + 0x138) = lVar3 + uVar1 * 8;

    }

    else if (uVar7 < uVar1) {

      uVar5 = *(longlong *)(param_1 + 0x140) - lVar3 >> 3;

      if (uVar5 < uVar1) {

        if (0x1fffffffffffffff < uVar1) {

                    /* WARNING: Subroutine does not return */

          FUN_14002f0d0();

        }

        if (0x1fffffffffffffff - (uVar5 >> 1) < uVar5) {

          uVar6 = 0x1fffffffffffffff;

        }

        else {

          uVar5 = uVar5 + (uVar5 >> 1);

          uVar6 = uVar1;

          if ((uVar1 <= uVar5) && (uVar6 = uVar5, 0x1fffffffffffffff < uVar5)) {

                    /* WARNING: Subroutine does not return */

            FUN_140024090();

          }

        }

        lVar4 = FUN_1400285e0(uVar6 * 8);

        FUN_1402f94c0(lVar4 + uVar7 * 8,0,0xfffffffffffffff8);

        FUN_1402f8e20(lVar4,*plVar2,*(longlong *)(param_1 + 0x138) - *plVar2);

        FUN_140037380(plVar2,lVar4,uVar1,uVar6);

      }

      else {

        FUN_1402f94c0(lVar4,0,0xfffffffffffffff8);

        *(longlong *)(param_1 + 0x138) = lVar4 + -8;

      }

    }

  }

  return;

}




