// Address: 0x14002d750
// Ghidra name: FUN_14002d750
// ============ 0x14002d750 FUN_14002d750 (size=100) ============


void FUN_14002d750(longlong param_1,int param_2,uint param_3)



{

  uint *puVar1;

  longlong lVar2;

  

  lVar2 = (longlong)param_2;

  if (((int)param_3 < 1) ||

     ((*(uint *)(*(longlong *)(param_1 + 0x268) + 0x10 + lVar2 * 0x20) & param_3) == 0)) {

    puVar1 = (uint *)(*(longlong *)(param_1 + 0x268) + 0x10 + lVar2 * 0x20);

    *puVar1 = *puVar1 | param_3;

    FUN_1400b87e0(*(undefined8 *)(*(longlong *)(param_1 + 0x130) + lVar2 * 8));

    FUN_1400d4f50(param_1,*(undefined8 *)(*(longlong *)(param_1 + 0x130) + lVar2 * 8));

  }

  return;

}




