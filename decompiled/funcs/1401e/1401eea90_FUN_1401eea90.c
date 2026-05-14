// Address: 0x1401eea90
// Ghidra name: FUN_1401eea90
// ============ 0x1401eea90 FUN_1401eea90 (size=151) ============


char * FUN_1401eea90(uint param_1)



{

  char *pcVar1;

  

  if (param_1 < 0x501) {

    if (param_1 != 0x500) {

      pcVar1 = "UNKNOWN";

      if (param_1 == 0) {

        pcVar1 = "GL_NO_ERROR";

      }

      return pcVar1;

    }

    return "GL_INVALID_ENUM";

  }

  if (0x504 < param_1) {

    if (param_1 != 0x505) {

      pcVar1 = "GL_TABLE_TOO_LARGE";

      if (param_1 != 0x8031) {

        pcVar1 = "UNKNOWN";

      }

      return pcVar1;

    }

    return "GL_OUT_OF_MEMORY";

  }

  if (param_1 != 0x504) {

    if (param_1 == 0x501) {

      return "GL_INVALID_VALUE";

    }

    if (param_1 != 0x502) {

      if (param_1 != 0x503) {

        return "UNKNOWN";

      }

      return "GL_STACK_OVERFLOW";

    }

    return "GL_INVALID_OPERATION";

  }

  return "GL_STACK_UNDERFLOW";

}




