// Address: 0x1401bd050
// Ghidra name: FUN_1401bd050
// ============ 0x1401bd050 FUN_1401bd050 (size=113) ============


void FUN_1401bd050(longlong param_1,longlong param_2)



{

  uint uVar1;

  undefined8 uVar2;

  

  if (*(uint *)(param_1 + 0x834) <= *(uint *)(param_1 + 0x830)) {

    uVar1 = *(uint *)(param_1 + 0x834) * 2;

    *(uint *)(param_1 + 0x834) = uVar1;

    uVar2 = FUN_140184230(*(undefined8 *)(param_1 + 0x828),(ulonglong)uVar1 << 3);

    *(undefined8 *)(param_1 + 0x828) = uVar2;

  }

  *(longlong *)(*(longlong *)(param_1 + 0x828) + (ulonglong)*(uint *)(param_1 + 0x830) * 8) =

       param_2;

  *(int *)(param_1 + 0x830) = *(int *)(param_1 + 0x830) + 1;

  *(undefined8 *)(param_2 + 8) = 0;

  return;

}




