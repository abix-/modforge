// Address: 0x1402170f0
// Ghidra name: FUN_1402170f0
// ============ 0x1402170f0 FUN_1402170f0 (size=65) ============


char * FUN_1402170f0(char param_1)



{

  char *pcVar1;

  

  pcVar1 = "SDL_AUDIO_DISK_OUTPUT_FILE";

  if (param_1 != '\0') {

    pcVar1 = "SDL_AUDIO_DISK_INPUT_FILE";

  }

  pcVar1 = (char *)FUN_140142960(pcVar1);

  if ((pcVar1 == (char *)0x0) && (pcVar1 = "sdlaudio.raw", param_1 != '\0')) {

    pcVar1 = "sdlaudio-in.raw";

  }

  return pcVar1;

}




