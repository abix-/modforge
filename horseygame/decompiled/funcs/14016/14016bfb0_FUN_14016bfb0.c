// Address: 0x14016bfb0
// Ghidra name: FUN_14016bfb0
// ============ 0x14016bfb0 FUN_14016bfb0 (size=156) ============


void FUN_14016bfb0(undefined4 *param_1,undefined4 *param_2)



{

  char cVar1;

  

  cVar1 = FUN_14016c0c0("GL_ARB_ES3_2_compatibility");

  if (cVar1 != '\0') {

    *param_1 = 3;

    *param_2 = 2;

    return;

  }

  cVar1 = FUN_14016c0c0("GL_ARB_ES3_1_compatibility");

  if (cVar1 != '\0') {

    *param_1 = 3;

    *param_2 = 1;

    return;

  }

  cVar1 = FUN_14016c0c0("GL_ARB_ES3_compatibility");

  if (cVar1 != '\0') {

    *param_1 = 3;

    *param_2 = 0;

    return;

  }

  *param_1 = 2;

  *param_2 = 0;

  return;

}




