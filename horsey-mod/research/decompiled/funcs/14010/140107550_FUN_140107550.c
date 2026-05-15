// Address: 0x140107550
// Ghidra name: FUN_140107550
// ============ 0x140107550 FUN_140107550 (size=214) ============


longlong * FUN_140107550(longlong param_1,longlong *param_2)



{

  longlong lVar1;

  longlong lVar2;

  ulonglong uVar3;

  longlong lVar4;

  

  lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x438) + 0x120);

  *param_2 = 0;

  param_2[1] = 0;

  param_2[2] = 0;

  if (lVar1 == 0) {

    return param_2;

  }

  uVar3 = *(longlong *)(lVar1 + 0x138) - *(longlong *)(lVar1 + 0x130) >> 3;

  if (uVar3 != 0) {

    if (0x1fffffffffffffff < uVar3) {

                    /* WARNING: Subroutine does not return */

      FUN_14002f0d0();

    }

    lVar2 = FUN_1400285e0(uVar3 * 8);

    *param_2 = lVar2;

    param_2[1] = lVar2;

    param_2[2] = uVar3 * 8 + lVar2;

    lVar4 = *(longlong *)(lVar1 + 0x138) - *(longlong *)(lVar1 + 0x130);

    FUN_1402f8e20(lVar2,*(longlong *)(lVar1 + 0x130),lVar4);

    param_2[1] = lVar2 + (lVar4 >> 3) * 8;

  }

  return param_2;

}




