// Address: 0x140282720
// Ghidra name: FUN_140282720
// ============ 0x140282720 FUN_140282720 (size=137) ============


undefined8 FUN_140282720(longlong param_1,undefined8 param_2,undefined8 param_3,ushort param_4)



{

  undefined8 uVar1;

  undefined2 local_40;

  undefined8 local_3e;

  undefined8 uStack_36;

  undefined8 local_2e;

  undefined8 uStack_26;

  undefined8 local_1e;

  undefined4 local_16;

  undefined2 local_12;

  

  if (*(char *)(*(longlong *)(param_1 + 0x70) + 0x10) != '\0') {

    local_1e = 0;

    uStack_36 = 0;

    local_16 = 0;

    local_12 = 0;

    local_40 = 0x103;

    local_2e = 0;

    uStack_26 = 0;

    local_3e = CONCAT71((uint7)((ulonglong)param_3 >> 8) & 0xff,2);

    local_3e = (ulonglong)CONCAT13((char)(param_4 >> 8),(undefined3)local_3e);

    FUN_140284590(0,&local_40,0x30,param_4 >> 8,0,0);

    return 1;

  }

  uVar1 = FUN_14012e850("That operation is not supported");

  return uVar1;

}




