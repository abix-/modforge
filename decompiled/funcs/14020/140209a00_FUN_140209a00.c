// Address: 0x140209a00
// Ghidra name: FUN_140209a00
// ============ 0x140209a00 FUN_140209a00 (size=76) ============


undefined4 FUN_140209a00(short param_1,short param_2,undefined8 param_3)



{

  undefined4 local_res8 [8];

  

  local_res8[0] = 0xffffffff;

  if ((param_1 == 0x28de) && (param_2 == 0x11ff)) {

    FUN_14012ef30(param_3,"\\\\.\\pipe\\HID#VID_045E&PID_028E&IG_00#%*X&%*X&%*X#%d#%*u",local_res8);

    return local_res8[0];

  }

  return 0xffffffff;

}




