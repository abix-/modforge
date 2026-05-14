// Address: 0x14018c450
// Ghidra name: FUN_14018c450
// ============ 0x14018c450 FUN_14018c450 (size=276) ============


void FUN_14018c450(undefined8 param_1,ulonglong param_2,longlong param_3,undefined4 param_4)



{

  undefined4 uVar1;

  byte bVar2;

  

  if (param_2 != *(ulonglong *)(param_3 + 0x50)) {

    uVar1 = FUN_1401612e0(0,0);

    bVar2 = (byte)param_2;

    FUN_14018c3a0(param_1,param_2 & 1,uVar1,0,param_3,1,param_4);

    FUN_14018c3a0(param_1,bVar2 >> 4 & 1,uVar1,0,param_3,2,param_4);

    FUN_14018c3a0(param_1,bVar2 >> 1 & 1,uVar1,0,param_3,3,param_4);

    FUN_14018c3a0(param_1,bVar2 >> 5 & 1,uVar1,0,param_3,4,param_4);

    FUN_14018c3a0(param_1,bVar2 >> 6 & 1,uVar1,0,param_3,5,param_4);

    *(ulonglong *)(param_3 + 0x50) = param_2;

  }

  return;

}




