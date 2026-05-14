// Address: 0x140241030
// Ghidra name: FUN_140241030
// ============ 0x140241030 FUN_140241030 (size=60) ============


char * FUN_140241030(int param_1)



{

  if (param_1 == 1) {

    return 

    "#ifdef GL_FRAGMENT_PRECISION_HIGH\n#define SDL_TEXCOORD_PRECISION highp\n#else\n#define SDL_TEXCOORD_PRECISION mediump\n#endif\n\nprecision mediump float;\n\n"

    ;

  }

  if (param_1 == 2) {

    return "#define SDL_TEXCOORD_PRECISION mediump\nprecision mediump float;\n\n";

  }

  if (param_1 == 3) {

    return "#define SDL_TEXCOORD_PRECISION highp\nprecision mediump float;\n\n";

  }

  if (param_1 != 4) {

    return "";

  }

  return "#define mediump\n#define highp\n#define lowp\n#define SDL_TEXCOORD_PRECISION\n\n";

}




