// Address: 0x1401ecce0
// Ghidra name: FUN_1401ecce0
// ============ 0x1401ecce0 FUN_1401ecce0 (size=2603) ============


ulonglong FUN_1401ecce0(longlong param_1)



{

  byte bVar1;

  longlong lVar2;

  undefined8 uVar3;

  ulonglong uVar4;

  

  bVar1 = 1;

  lVar2 = FUN_14016c730("glBegin");

  *(longlong *)(param_1 + 0x38) = lVar2;

  if (lVar2 == 0) {

    uVar3 = FUN_14012e730();

    bVar1 = FUN_14012e850("Couldn\'t load GL function %s: %s","glBegin",uVar3);

  }

  lVar2 = FUN_14016c730("glBindTexture");

  *(longlong *)(param_1 + 0x40) = lVar2;

  if (lVar2 == 0) {

    uVar3 = FUN_14012e730();

    bVar1 = FUN_14012e850("Couldn\'t load GL function %s: %s","glBindTexture",uVar3);

  }

  lVar2 = FUN_14016c730("glBlendEquation");

  *(longlong *)(param_1 + 0x48) = lVar2;

  if (lVar2 == 0) {

    uVar3 = FUN_14012e730();

    bVar1 = FUN_14012e850("Couldn\'t load GL function %s: %s","glBlendEquation",uVar3);

  }

  lVar2 = FUN_14016c730("glBlendFuncSeparate");

  *(longlong *)(param_1 + 0x50) = lVar2;

  if (lVar2 == 0) {

    uVar3 = FUN_14012e730();

    bVar1 = FUN_14012e850("Couldn\'t load GL function %s: %s","glBlendFuncSeparate",uVar3);

  }

  lVar2 = FUN_14016c730("glClear");

  *(longlong *)(param_1 + 0x58) = lVar2;

  if (lVar2 == 0) {

    uVar3 = FUN_14012e730();

    bVar1 = FUN_14012e850("Couldn\'t load GL function %s: %s","glClear",uVar3);

  }

  lVar2 = FUN_14016c730("glClearColor");

  *(longlong *)(param_1 + 0x60) = lVar2;

  if (lVar2 == 0) {

    uVar3 = FUN_14012e730();

    bVar1 = FUN_14012e850("Couldn\'t load GL function %s: %s","glClearColor",uVar3);

  }

  lVar2 = FUN_14016c730("glColor3fv");

  *(longlong *)(param_1 + 0x68) = lVar2;

  if (lVar2 == 0) {

    uVar3 = FUN_14012e730();

    bVar1 = FUN_14012e850("Couldn\'t load GL function %s: %s","glColor3fv",uVar3);

  }

  lVar2 = FUN_14016c730("glColor4f");

  *(longlong *)(param_1 + 0x70) = lVar2;

  if (lVar2 == 0) {

    uVar3 = FUN_14012e730();

    bVar1 = FUN_14012e850("Couldn\'t load GL function %s: %s","glColor4f",uVar3);

  }

  lVar2 = FUN_14016c730("glColor4ub");

  *(longlong *)(param_1 + 0x78) = lVar2;

  if (lVar2 == 0) {

    uVar3 = FUN_14012e730();

    bVar1 = FUN_14012e850("Couldn\'t load GL function %s: %s","glColor4ub",uVar3);

  }

  lVar2 = FUN_14016c730("glColorPointer");

  *(longlong *)(param_1 + 0x80) = lVar2;

  if (lVar2 == 0) {

    uVar3 = FUN_14012e730();

    bVar1 = FUN_14012e850("Couldn\'t load GL function %s: %s","glColorPointer",uVar3);

  }

  lVar2 = FUN_14016c730("glDeleteTextures");

  *(longlong *)(param_1 + 0x88) = lVar2;

  if (lVar2 == 0) {

    uVar3 = FUN_14012e730();

    bVar1 = FUN_14012e850("Couldn\'t load GL function %s: %s","glDeleteTextures",uVar3);

  }

  lVar2 = FUN_14016c730("glDepthFunc");

  *(longlong *)(param_1 + 0x90) = lVar2;

  if (lVar2 == 0) {

    uVar3 = FUN_14012e730();

    bVar1 = FUN_14012e850("Couldn\'t load GL function %s: %s","glDepthFunc",uVar3);

  }

  lVar2 = FUN_14016c730("glDisable");

  *(longlong *)(param_1 + 0x98) = lVar2;

  if (lVar2 == 0) {

    uVar3 = FUN_14012e730();

    bVar1 = FUN_14012e850("Couldn\'t load GL function %s: %s","glDisable",uVar3);

  }

  lVar2 = FUN_14016c730("glDisableClientState");

  *(longlong *)(param_1 + 0xa0) = lVar2;

  if (lVar2 == 0) {

    uVar3 = FUN_14012e730();

    bVar1 = FUN_14012e850("Couldn\'t load GL function %s: %s","glDisableClientState",uVar3);

  }

  lVar2 = FUN_14016c730("glDrawArrays");

  *(longlong *)(param_1 + 0xa8) = lVar2;

  if (lVar2 == 0) {

    uVar3 = FUN_14012e730();

    bVar1 = FUN_14012e850("Couldn\'t load GL function %s: %s","glDrawArrays",uVar3);

  }

  lVar2 = FUN_14016c730("glDrawPixels");

  *(longlong *)(param_1 + 0xb0) = lVar2;

  if (lVar2 == 0) {

    uVar3 = FUN_14012e730();

    bVar1 = FUN_14012e850("Couldn\'t load GL function %s: %s","glDrawPixels",uVar3);

  }

  lVar2 = FUN_14016c730("glEnable");

  *(longlong *)(param_1 + 0xb8) = lVar2;

  if (lVar2 == 0) {

    uVar3 = FUN_14012e730();

    bVar1 = FUN_14012e850("Couldn\'t load GL function %s: %s","glEnable",uVar3);

  }

  lVar2 = FUN_14016c730("glEnableClientState");

  *(longlong *)(param_1 + 0xc0) = lVar2;

  if (lVar2 == 0) {

    uVar3 = FUN_14012e730();

    bVar1 = FUN_14012e850("Couldn\'t load GL function %s: %s","glEnableClientState",uVar3);

  }

  lVar2 = FUN_14016c730("glEnd");

  *(longlong *)(param_1 + 200) = lVar2;

  if (lVar2 == 0) {

    uVar3 = FUN_14012e730();

    bVar1 = FUN_14012e850("Couldn\'t load GL function %s: %s","glEnd",uVar3);

  }

  lVar2 = FUN_14016c730("glGenTextures");

  *(longlong *)(param_1 + 0xd0) = lVar2;

  if (lVar2 == 0) {

    uVar3 = FUN_14012e730();

    bVar1 = FUN_14012e850("Couldn\'t load GL function %s: %s","glGenTextures",uVar3);

  }

  lVar2 = FUN_14016c730("glGetError");

  *(longlong *)(param_1 + 0xd8) = lVar2;

  if (lVar2 == 0) {

    uVar3 = FUN_14012e730();

    bVar1 = FUN_14012e850("Couldn\'t load GL function %s: %s","glGetError",uVar3);

  }

  lVar2 = FUN_14016c730("glGetFloatv");

  *(longlong *)(param_1 + 0xe0) = lVar2;

  if (lVar2 == 0) {

    uVar3 = FUN_14012e730();

    bVar1 = FUN_14012e850("Couldn\'t load GL function %s: %s","glGetFloatv",uVar3);

  }

  lVar2 = FUN_14016c730("glGetIntegerv");

  *(longlong *)(param_1 + 0xe8) = lVar2;

  if (lVar2 == 0) {

    uVar3 = FUN_14012e730();

    bVar1 = FUN_14012e850("Couldn\'t load GL function %s: %s","glGetIntegerv",uVar3);

  }

  lVar2 = FUN_14016c730("glGetPointerv");

  *(longlong *)(param_1 + 0xf0) = lVar2;

  if (lVar2 == 0) {

    uVar3 = FUN_14012e730();

    bVar1 = FUN_14012e850("Couldn\'t load GL function %s: %s","glGetPointerv",uVar3);

  }

  lVar2 = FUN_14016c730("glGetString");

  *(longlong *)(param_1 + 0xf8) = lVar2;

  if (lVar2 == 0) {

    uVar3 = FUN_14012e730();

    bVar1 = FUN_14012e850("Couldn\'t load GL function %s: %s","glGetString",uVar3);

  }

  lVar2 = FUN_14016c730("glLineWidth");

  *(longlong *)(param_1 + 0x100) = lVar2;

  if (lVar2 == 0) {

    uVar3 = FUN_14012e730();

    bVar1 = FUN_14012e850("Couldn\'t load GL function %s: %s","glLineWidth",uVar3);

  }

  lVar2 = FUN_14016c730("glLoadIdentity");

  *(longlong *)(param_1 + 0x108) = lVar2;

  if (lVar2 == 0) {

    uVar3 = FUN_14012e730();

    bVar1 = FUN_14012e850("Couldn\'t load GL function %s: %s","glLoadIdentity",uVar3);

  }

  lVar2 = FUN_14016c730("glMatrixMode");

  *(longlong *)(param_1 + 0x110) = lVar2;

  if (lVar2 == 0) {

    uVar3 = FUN_14012e730();

    bVar1 = FUN_14012e850("Couldn\'t load GL function %s: %s","glMatrixMode",uVar3);

  }

  lVar2 = FUN_14016c730("glOrtho");

  *(longlong *)(param_1 + 0x118) = lVar2;

  if (lVar2 == 0) {

    uVar3 = FUN_14012e730();

    bVar1 = FUN_14012e850("Couldn\'t load GL function %s: %s","glOrtho",uVar3);

  }

  lVar2 = FUN_14016c730("glPixelStorei");

  *(longlong *)(param_1 + 0x120) = lVar2;

  if (lVar2 == 0) {

    uVar3 = FUN_14012e730();

    bVar1 = FUN_14012e850("Couldn\'t load GL function %s: %s","glPixelStorei",uVar3);

  }

  lVar2 = FUN_14016c730("glPointSize");

  *(longlong *)(param_1 + 0x128) = lVar2;

  if (lVar2 == 0) {

    uVar3 = FUN_14012e730();

    bVar1 = FUN_14012e850("Couldn\'t load GL function %s: %s","glPointSize",uVar3);

  }

  lVar2 = FUN_14016c730("glRasterPos2i");

  *(longlong *)(param_1 + 0x130) = lVar2;

  if (lVar2 == 0) {

    uVar3 = FUN_14012e730();

    bVar1 = FUN_14012e850("Couldn\'t load GL function %s: %s","glRasterPos2i",uVar3);

  }

  lVar2 = FUN_14016c730("glReadBuffer");

  *(longlong *)(param_1 + 0x138) = lVar2;

  if (lVar2 == 0) {

    uVar3 = FUN_14012e730();

    bVar1 = FUN_14012e850("Couldn\'t load GL function %s: %s","glReadBuffer",uVar3);

  }

  lVar2 = FUN_14016c730("glReadPixels");

  *(longlong *)(param_1 + 0x140) = lVar2;

  if (lVar2 == 0) {

    uVar3 = FUN_14012e730();

    bVar1 = FUN_14012e850("Couldn\'t load GL function %s: %s","glReadPixels",uVar3);

  }

  lVar2 = FUN_14016c730("glRectf");

  *(longlong *)(param_1 + 0x148) = lVar2;

  if (lVar2 == 0) {

    uVar3 = FUN_14012e730();

    bVar1 = FUN_14012e850("Couldn\'t load GL function %s: %s","glRectf",uVar3);

  }

  lVar2 = FUN_14016c730("glRotatef");

  *(longlong *)(param_1 + 0x150) = lVar2;

  if (lVar2 == 0) {

    uVar3 = FUN_14012e730();

    bVar1 = FUN_14012e850("Couldn\'t load GL function %s: %s","glRotatef",uVar3);

  }

  lVar2 = FUN_14016c730("glScissor");

  *(longlong *)(param_1 + 0x158) = lVar2;

  if (lVar2 == 0) {

    uVar3 = FUN_14012e730();

    bVar1 = FUN_14012e850("Couldn\'t load GL function %s: %s","glScissor",uVar3);

  }

  lVar2 = FUN_14016c730("glShadeModel");

  *(longlong *)(param_1 + 0x160) = lVar2;

  if (lVar2 == 0) {

    uVar3 = FUN_14012e730();

    bVar1 = FUN_14012e850("Couldn\'t load GL function %s: %s","glShadeModel",uVar3);

  }

  lVar2 = FUN_14016c730("glTexCoord2f");

  *(longlong *)(param_1 + 0x168) = lVar2;

  if (lVar2 == 0) {

    uVar3 = FUN_14012e730();

    bVar1 = FUN_14012e850("Couldn\'t load GL function %s: %s","glTexCoord2f",uVar3);

  }

  lVar2 = FUN_14016c730("glTexCoordPointer");

  *(longlong *)(param_1 + 0x170) = lVar2;

  if (lVar2 == 0) {

    uVar3 = FUN_14012e730();

    bVar1 = FUN_14012e850("Couldn\'t load GL function %s: %s","glTexCoordPointer",uVar3);

  }

  lVar2 = FUN_14016c730("glTexEnvf");

  *(longlong *)(param_1 + 0x178) = lVar2;

  if (lVar2 == 0) {

    uVar3 = FUN_14012e730();

    bVar1 = FUN_14012e850("Couldn\'t load GL function %s: %s","glTexEnvf",uVar3);

  }

  lVar2 = FUN_14016c730("glTexImage2D");

  *(longlong *)(param_1 + 0x180) = lVar2;

  if (lVar2 == 0) {

    uVar3 = FUN_14012e730();

    bVar1 = FUN_14012e850("Couldn\'t load GL function %s: %s","glTexImage2D",uVar3);

  }

  lVar2 = FUN_14016c730("glTexParameteri");

  *(longlong *)(param_1 + 0x188) = lVar2;

  if (lVar2 == 0) {

    uVar3 = FUN_14012e730();

    bVar1 = FUN_14012e850("Couldn\'t load GL function %s: %s","glTexParameteri",uVar3);

  }

  lVar2 = FUN_14016c730("glTexSubImage2D");

  *(longlong *)(param_1 + 400) = lVar2;

  if (lVar2 == 0) {

    uVar3 = FUN_14012e730();

    bVar1 = FUN_14012e850("Couldn\'t load GL function %s: %s","glTexSubImage2D",uVar3);

  }

  lVar2 = FUN_14016c730("glVertex2f");

  *(longlong *)(param_1 + 0x198) = lVar2;

  if (lVar2 == 0) {

    uVar3 = FUN_14012e730();

    bVar1 = FUN_14012e850("Couldn\'t load GL function %s: %s","glVertex2f",uVar3);

  }

  lVar2 = FUN_14016c730("glVertex3fv");

  *(longlong *)(param_1 + 0x1a0) = lVar2;

  if (lVar2 == 0) {

    uVar3 = FUN_14012e730();

    bVar1 = FUN_14012e850("Couldn\'t load GL function %s: %s","glVertex3fv",uVar3);

  }

  lVar2 = FUN_14016c730("glVertexPointer");

  *(longlong *)(param_1 + 0x1a8) = lVar2;

  if (lVar2 == 0) {

    uVar3 = FUN_14012e730();

    bVar1 = FUN_14012e850("Couldn\'t load GL function %s: %s","glVertexPointer",uVar3);

  }

  lVar2 = FUN_14016c730("glViewport");

  *(longlong *)(param_1 + 0x1b0) = lVar2;

  if (lVar2 == 0) {

    uVar3 = FUN_14012e730();

    uVar4 = FUN_14012e850("Couldn\'t load GL function %s: %s","glViewport",uVar3);

    return uVar4;

  }

  return (ulonglong)bVar1;

}




