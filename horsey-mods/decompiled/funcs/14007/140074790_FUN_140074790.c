// Address: 0x140074790
// Ghidra name: FUN_140074790
// ============ 0x140074790 FUN_140074790 (size=281) ============


void FUN_140074790(longlong *param_1)



{

  longlong lVar1;

  longlong lVar2;

  ulonglong uVar3;

  

  uVar3 = param_1[1] - *param_1 >> 5;

  if (uVar3 != 0) {

    if (0x7ffffffffffffff < uVar3) {

                    /* WARNING: Subroutine does not return */

      FUN_14002f0d0();

    }

    uVar3 = uVar3 * 0x20;

    lVar1 = FUN_1400285e0(uVar3);

    FUN_1402f8e20(lVar1,*param_1,param_1[1] - *param_1);

    FUN_140073510();

    if (lVar1 != 0) {

      lVar2 = lVar1;

      if (0xfff < uVar3) {

        uVar3 = uVar3 + 0x27;

        lVar2 = *(longlong *)(lVar1 + -8);

        if (0x1f < (lVar1 - lVar2) - 8U) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

      }

      FUN_1402c7088(lVar2,uVar3);

    }

  }

  return;

}




