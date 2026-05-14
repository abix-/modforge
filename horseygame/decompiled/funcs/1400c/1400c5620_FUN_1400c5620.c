// Address: 0x1400c5620
// Ghidra name: FUN_1400c5620
// ============ 0x1400c5620 FUN_1400c5620 (size=39) ============


void FUN_1400c5620(undefined8 *param_1)



{

  undefined8 uVar1;

  undefined4 uVar2;

  

  uVar2 = SteamAPI_GetHSteamUser();

  uVar1 = SteamInternal_FindOrCreateUserInterface(uVar2,"STEAMAPPS_INTERFACE_VERSION008");

  *param_1 = uVar1;

  return;

}




