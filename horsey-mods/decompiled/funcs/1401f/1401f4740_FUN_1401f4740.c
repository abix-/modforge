// Address: 0x1401f4740
// Ghidra name: FUN_1401f4740
// ============ 0x1401f4740 FUN_1401f4740 (size=75) ============


char * FUN_1401f4740(int param_1)



{

  if (param_1 == 0) {

    return "GL_NO_ERROR";

  }

  if (param_1 == 0x500) {

    return "GL_INVALID_ENUM";

  }

  if (param_1 == 0x501) {

    return "GL_INVALID_VALUE";

  }

  if (param_1 != 0x502) {

    if (param_1 != 0x505) {

      return "UNKNOWN";

    }

    return "GL_OUT_OF_MEMORY";

  }

  return "GL_INVALID_OPERATION";

}




