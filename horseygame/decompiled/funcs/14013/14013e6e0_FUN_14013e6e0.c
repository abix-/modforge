// Address: 0x14013e6e0
// Ghidra name: FUN_14013e6e0
// ============ 0x14013e6e0 FUN_14013e6e0 (size=82) ============


bool FUN_14013e6e0(undefined8 param_1,ulonglong param_2)



{

  ulonglong uVar1;

  char *pcVar2;

  

  pcVar2 = (char *)FUN_140142960("SDL_GAMECONTROLLERCONFIG_FILE");

  if ((pcVar2 != (char *)0x0) && (*pcVar2 != '\0')) {

    uVar1 = FUN_14012f1a0(param_1,pcVar2,param_2);

    return uVar1 < param_2;

  }

  return false;

}




