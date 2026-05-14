// Address: 0x140010c10
// Ghidra name: FUN_140010c10
// ============ 0x140010c10 FUN_140010c10 (size=156) ============


undefined8 * FUN_140010c10(undefined8 *param_1,undefined4 *param_2)



{

  *param_1 = b2Joint::vftable;

  if (*(longlong *)(param_2 + 4) == *(longlong *)(param_2 + 6)) {

    FID_conflict__assert

              (L"def->bodyA != def->bodyB",L"C:\\dev\\Box2d2\\Box2D\\Dynamics\\Joints\\b2Joint.cpp",

               0xad);

  }

  *(undefined4 *)(param_1 + 1) = *param_2;

  param_1[2] = 0;

  param_1[3] = 0;

  param_1[0xc] = *(undefined8 *)(param_2 + 4);

  param_1[0xd] = *(undefined8 *)(param_2 + 6);

  *(undefined1 *)((longlong)param_1 + 0x71) = *(undefined1 *)(param_2 + 8);

  *(undefined1 *)(param_1 + 0xe) = 0;

  param_1[0xf] = *(undefined8 *)(param_2 + 2);

  param_1[5] = 0;

  param_1[4] = 0;

  param_1[6] = 0;

  param_1[7] = 0;

  param_1[9] = 0;

  param_1[8] = 0;

  param_1[10] = 0;

  param_1[0xb] = 0;

  return param_1;

}




