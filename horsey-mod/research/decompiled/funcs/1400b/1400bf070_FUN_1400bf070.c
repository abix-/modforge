// Address: 0x1400bf070
// Ghidra name: FUN_1400bf070
// ============ 0x1400bf070 FUN_1400bf070 (size=165) ============


undefined8 * FUN_1400bf070(undefined8 *param_1,longlong param_2)



{

  for (; param_2 != 0; param_2 = param_2 + -1) {

    *param_1 = b2PolygonShape::vftable;

    *(undefined4 *)((longlong)param_1 + 0x14) = 0;

    *(undefined4 *)(param_1 + 1) = 2;

    *(undefined8 *)((longlong)param_1 + 0xc) = 0x3c23d70a;

    *(undefined4 *)(param_1 + 0x13) = 0;

    param_1[0x14] = b2PolygonShape::vftable;

    *(undefined4 *)((longlong)param_1 + 0xb4) = 0;

    *(undefined4 *)(param_1 + 0x15) = 2;

    *(undefined8 *)((longlong)param_1 + 0xac) = 0x3c23d70a;

    *(undefined4 *)(param_1 + 0x27) = 0;

    *(undefined4 *)(param_1 + 0x2a) = 0;

    *(undefined4 *)(param_1 + 0x29) = 0;

    *(undefined4 *)((longlong)param_1 + 0x154) = 0x3f800000;

    *(undefined4 *)(param_1 + 0x2b) = 0x3f800000;

    *(undefined4 *)((longlong)param_1 + 0x15c) = 5;

    *(undefined4 *)((longlong)param_1 + 0x14c) = 0xffffffff;

    *(undefined1 *)(param_1 + 0x2c) = 1;

    param_1 = param_1 + 0x2d;

  }

  return param_1;

}




