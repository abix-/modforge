// Address: 0x14017c670
// Ghidra name: FUN_14017c670
// ============ 0x14017c670 FUN_14017c670 (size=44) ============


uint FUN_14017c670(longlong param_1)



{

  byte bVar1;

  

  if (param_1 == 0) {

    bVar1 = FUN_14012e850("Parameter \'%s\' is invalid","process");

    return (uint)bVar1;

  }

  return *(uint *)(param_1 + 8);

}




