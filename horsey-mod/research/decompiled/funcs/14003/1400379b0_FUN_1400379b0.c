// Address: 0x1400379b0
// Ghidra name: FUN_1400379b0
// ============ 0x1400379b0 FUN_1400379b0 (size=39) ============


void FUN_1400379b0(undefined8 *param_1)



{

  undefined8 uVar1;

  undefined4 uVar2;

  

  uVar2 = SteamAPI_GetHSteamUser();

  uVar1 = SteamInternal_FindOrCreateUserInterface(uVar2,"STEAMUSERSTATS_INTERFACE_VERSION013");

  *param_1 = uVar1;

  return;

}




