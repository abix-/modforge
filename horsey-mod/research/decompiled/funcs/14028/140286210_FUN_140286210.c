// Address: 0x140286210
// Ghidra name: FUN_140286210
// ============ 0x140286210 FUN_140286210 (size=76) ============


undefined4 FUN_140286210(short param_1,short param_2,undefined8 param_3)



{

  undefined4 local_res8 [8];

  

  local_res8[0] = 0xffffffff;

  if ((param_1 == 0x28de) && (param_2 == 0x11ff)) {

    FUN_14012ef30(param_3,"\\\\?\\HID#VID_28DE&PID_11FF&IG_0%d",local_res8);

    return local_res8[0];

  }

  return 0xffffffff;

}




