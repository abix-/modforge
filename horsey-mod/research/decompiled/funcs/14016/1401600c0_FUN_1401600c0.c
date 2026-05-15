// Address: 0x1401600c0
// Ghidra name: FUN_1401600c0
// ============ 0x1401600c0 FUN_1401600c0 (size=75) ============


undefined8 FUN_1401600c0(longlong param_1)



{

  longlong lVar1;

  int iVar2;

  

  iVar2 = FUN_140138fe0(param_1 + 0x8c);

  if (iVar2 == 0) {

    lVar1 = (longlong)

            (int)((*(uint *)(param_1 + 0x6c) /

                  ((*(uint *)(param_1 + 0x60) >> 3 & 0x1f) * *(int *)(param_1 + 100))) * 1000);

    FUN_1401492f0(lVar1 / (longlong)*(int *)(param_1 + 0x68) & 0xffffffff,

                  lVar1 % (longlong)*(int *)(param_1 + 0x68) & 0xffffffff);

  }

  return 1;

}




