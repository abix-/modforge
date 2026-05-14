// Address: 0x140263db0
// Ghidra name: FUN_140263db0
// ============ 0x140263db0 FUN_140263db0 (size=78) ============


undefined4 FUN_140263db0(longlong param_1)



{

  int iVar1;

  undefined1 local_res8 [32];

  

  local_res8[0] = 0x13;

  iVar1 = FUN_140195730(*(undefined8 *)(param_1 + 0x80),local_res8,1);

  if (iVar1 != 1) {

    FUN_14012e080(7,"HIDAPI_DriverGameCube_InitDevice(): Couldn\'t initialize WUP-028");

    return 0;

  }

  FUN_1401492f0(10);

  return 1;

}




