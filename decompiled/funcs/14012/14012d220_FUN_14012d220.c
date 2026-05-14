// Address: 0x14012d220
// Ghidra name: FUN_14012d220
// ============ 0x14012d220 FUN_14012d220 (size=40) ============


undefined4 FUN_14012d220(undefined8 *param_1)



{

  BOOL BVar1;

  undefined4 uVar2;

  

  BVar1 = FlushFileBuffers((HANDLE)*param_1);

  if (BVar1 == 0) {

    uVar2 = FUN_1401a9ed0("Error flushing datastream");

    return uVar2;

  }

  return 1;

}




