// Address: 0x1401a6b30
// Ghidra name: FUN_1401a6b30
// ============ 0x1401a6b30 FUN_1401a6b30 (size=176) ============


undefined8 FUN_1401a6b30(longlong param_1)



{

  ulonglong uVar1;

  

  if (*(longlong **)(param_1 + 0x98) != (longlong *)0x0) {

    **(longlong **)(param_1 + 0x98) = *(longlong *)(param_1 + 0xb0) - *(longlong *)(param_1 + 0x88);

  }

  if (*(longlong **)(param_1 + 0xa0) != (longlong *)0x0) {

    uVar1 = **(longlong **)(param_1 + 0xa0) - *(longlong *)(param_1 + 0xc0);

    if (*(uint *)(param_1 + 0x74) <= uVar1) {

      uVar1 = (ulonglong)*(uint *)(param_1 + 0x74);

    }

    FUN_1402f8e20(*(longlong *)(param_1 + 0xc0) + *(longlong *)(param_1 + 0x90),

                  (ulonglong)*(uint *)(param_1 + 0x70) + 0x392aa + param_1,uVar1);

    *(int *)(param_1 + 0x70) = *(int *)(param_1 + 0x70) + (int)uVar1;

    *(int *)(param_1 + 0x74) = *(int *)(param_1 + 0x74) - (int)uVar1;

    *(longlong *)(param_1 + 0xc0) = *(longlong *)(param_1 + 0xc0) + uVar1;

    **(undefined8 **)(param_1 + 0xa0) = *(undefined8 *)(param_1 + 0xc0);

  }

  if ((*(int *)(param_1 + 0x78) != 0) && (*(int *)(param_1 + 0x74) == 0)) {

    return 1;

  }

  return 0;

}




