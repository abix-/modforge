// Address: 0x1401ca8a0
// Ghidra name: FUN_1401ca8a0
// ============ 0x1401ca8a0 FUN_1401ca8a0 (size=98) ============


undefined8 FUN_1401ca8a0(longlong param_1,longlong param_2,char param_3,undefined4 param_4)



{

  int iVar1;

  

  if (param_3 != '\0') {

    iVar1 = FUN_140138fe0(*(longlong *)(param_2 + 0x10) + 0x88);

    if (0 < iVar1) {

      FUN_1401c92f0(*(undefined8 *)(param_1 + 0x110),param_2);

    }

  }

  FUN_1401c68f0(param_1,param_4,*(undefined8 *)(param_2 + 0x10));

  return *(undefined8 *)(param_2 + 0x10);

}




