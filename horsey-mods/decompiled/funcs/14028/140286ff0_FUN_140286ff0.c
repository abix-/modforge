// Address: 0x140286ff0
// Ghidra name: FUN_140286ff0
// ============ 0x140286ff0 FUN_140286ff0 (size=82) ============


uint FUN_140286ff0(int param_1)



{

  uint uVar1;

  uint uVar2;

  byte local_res10 [24];

  

  uVar1 = 0xffff;

  local_res10[0] = 1;

  local_res10[1] = 3;

  local_res10[2] = 2;

  local_res10[3] = 6;

  local_res10[4] = 4;

  local_res10[5] = 0xc;

  local_res10[6] = 8;

  local_res10[7] = 9;

  if ((short)param_1 != -1) {

    uVar1 = (param_1 + 0x8caU) * -0x16fbad2b;

    uVar2 = (param_1 + 0x8caU) % 36000;

    if (uVar2 < 36000) {

      return (uint)local_res10[(ulonglong)uVar2 / 0x1194];

    }

  }

  return uVar1 & 0xffffff00;

}




