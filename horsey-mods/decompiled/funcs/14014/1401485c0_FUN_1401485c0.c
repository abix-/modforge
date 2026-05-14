// Address: 0x1401485c0
// Ghidra name: FUN_1401485c0
// ============ 0x1401485c0 FUN_1401485c0 (size=112) ============


undefined8 FUN_1401485c0(longlong param_1,longlong param_2)



{

  undefined8 uVar1;

  undefined8 local_18;

  undefined4 uStack_10;

  undefined4 uStack_c;

  

  uVar1 = FUN_1401489c0();

  if ((char)uVar1 == '\0') {

    return uVar1;

  }

  local_18 = 0;

  uStack_10 = *(undefined4 *)(param_1 + 8);

  uStack_c = *(undefined4 *)(param_1 + 0xc);

  if (param_2 == 0) {

    *(undefined8 *)(param_1 + 100) = 0;

    *(undefined8 *)(param_1 + 0x6c) = *(undefined8 *)(param_1 + 8);

    return CONCAT71((uint7)(uint3)((uint)uStack_c >> 8),1);

  }

  uVar1 = FUN_140185790(param_2,&local_18);

  return uVar1;

}




