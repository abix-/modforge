// Address: 0x14022b3a0
// Ghidra name: FUN_14022b3a0
// ============ 0x14022b3a0 FUN_14022b3a0 (size=132) ============


undefined8 FUN_14022b3a0(undefined8 param_1,longlong param_2,int param_3)



{

  BOOL BVar1;

  undefined8 uVar2;

  undefined4 extraout_var;

  undefined4 extraout_var_00;

  FLASHWINFO local_28;

  

  local_28.cbSize = 0x20;

  local_28._4_4_ = 0;

  local_28.dwFlags = 0;

  local_28.uCount = 0;

  local_28.dwTimeout = 0;

  local_28._28_4_ = 0;

  local_28.hwnd = *(HWND *)(*(longlong *)(param_2 + 0x188) + 8);

  if (param_3 != 0) {

    if (param_3 != 1) {

      if (param_3 != 2) {

        uVar2 = FUN_14012e850("That operation is not supported");

        return uVar2;

      }

      local_28.dwFlags = 0xe;

      local_28.uCount = 0;

      BVar1 = FlashWindowEx(&local_28);

      return CONCAT71((int7)(CONCAT44(extraout_var,BVar1) >> 8),1);

    }

    local_28.dwFlags = 2;

    local_28.uCount = 1;

  }

  BVar1 = FlashWindowEx(&local_28);

  return CONCAT71((int7)(CONCAT44(extraout_var_00,BVar1) >> 8),1);

}




