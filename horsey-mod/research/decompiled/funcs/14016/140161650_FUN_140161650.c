// Address: 0x140161650
// Ghidra name: FUN_140161650
// ============ 0x140161650 FUN_140161650 (size=62) ============


ulonglong FUN_140161650(longlong param_1,float param_2,float param_3)



{

  uint uVar1;

  uint3 uVar2;

  ulonglong in_RAX;

  

  if (param_1 != 0) {

    uVar1 = *(uint *)(param_1 + 0x48);

    in_RAX = (ulonglong)uVar1;

    uVar2 = (uint3)(uVar1 >> 8);

    if ((uVar1 >> 0xe & 1) != 0) {

      return CONCAT71((uint7)uVar2,1);

    }

    if (((0.0 <= param_2) && (0.0 <= param_3)) && (param_2 < (float)*(int *)(param_1 + 0x20))) {

      return (ulonglong)CONCAT31(uVar2,param_3 < (float)*(int *)(param_1 + 0x24));

    }

  }

  return in_RAX & 0xffffffffffffff00;

}




