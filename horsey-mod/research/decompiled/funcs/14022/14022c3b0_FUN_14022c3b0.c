// Address: 0x14022c3b0
// Ghidra name: FUN_14022c3b0
// ============ 0x14022c3b0 FUN_14022c3b0 (size=98) ============


undefined8 FUN_14022c3b0(undefined8 param_1,longlong param_2)



{

  ulonglong uVar1;

  undefined8 uVar2;

  

  uVar1 = *(ulonglong *)(param_2 + 0x48);

  if ((uVar1 & 1) != 0) {

    uVar2 = FUN_140173190(param_2,1,1);

    return uVar2;

  }

  if ((uVar1 & 0xc0) == 0) {

    FUN_14022ade0(param_2,1);

    uVar2 = FUN_14022c420(param_2,*(uint *)(*(longlong *)(param_2 + 0x188) + 0xd0) | 0x215,3);

    return uVar2;

  }

  return CONCAT71((int7)(uVar1 >> 8),1);

}




