// Address: 0x1400985e0
// Ghidra name: FUN_1400985e0
// ============ 0x1400985e0 FUN_1400985e0 (size=107) ============


void FUN_1400985e0(longlong param_1,int param_2,uint param_3)



{

  uint *puVar1;

  longlong lVar2;

  

  if (*(char *)(param_1 + 600) == '\0') {

    lVar2 = (longlong)param_2;

    if (((int)param_3 < 1) ||

       ((*(uint *)(*(longlong *)(param_1 + 0x280) + 0x1c + lVar2 * 0x70) & param_3) == 0)) {

      puVar1 = (uint *)(*(longlong *)(param_1 + 0x280) + 0x1c + lVar2 * 0x70);

      *puVar1 = *puVar1 | param_3;

      FUN_1400b87e0(*(undefined8 *)(*(longlong *)(param_1 + 0x130) + lVar2 * 8));

      FUN_1400d4f50(param_1,*(undefined8 *)(*(longlong *)(param_1 + 0x130) + lVar2 * 8));

    }

  }

  return;

}




