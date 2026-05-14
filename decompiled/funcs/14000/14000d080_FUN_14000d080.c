// Address: 0x14000d080
// Ghidra name: FUN_14000d080
// ============ 0x14000d080 FUN_14000d080 (size=219) ============


void FUN_14000d080(longlong param_1,longlong param_2,int param_3)



{

  undefined1 uVar1;

  longlong lVar2;

  

  lVar2 = (longlong)param_3;

  if ((param_3 < 0) || (*(int *)(param_1 + 0x18) + -1 <= param_3)) {

    FID_conflict__assert

              (L"0 <= index && index < m_count - 1",

               L"C:\\dev\\Box2d2\\Box2D\\Collision\\Shapes\\b2ChainShape.cpp",0x59);

  }

  *(undefined4 *)(param_2 + 8) = 1;

  *(undefined4 *)(param_2 + 0xc) = *(undefined4 *)(param_1 + 0xc);

  *(undefined8 *)(param_2 + 0x10) = *(undefined8 *)(*(longlong *)(param_1 + 0x10) + lVar2 * 8);

  *(undefined8 *)(param_2 + 0x18) = *(undefined8 *)(*(longlong *)(param_1 + 0x10) + 8 + lVar2 * 8);

  if (param_3 < 1) {

    *(undefined8 *)(param_2 + 0x20) = *(undefined8 *)(param_1 + 0x1c);

    uVar1 = *(undefined1 *)(param_1 + 0x2c);

  }

  else {

    uVar1 = 1;

    *(undefined8 *)(param_2 + 0x20) =

         *(undefined8 *)(*(longlong *)(param_1 + 0x10) + -8 + lVar2 * 8);

  }

  *(undefined1 *)(param_2 + 0x30) = uVar1;

  if (param_3 < *(int *)(param_1 + 0x18) + -2) {

    *(undefined8 *)(param_2 + 0x28) =

         *(undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x10 + lVar2 * 8);

    *(undefined1 *)(param_2 + 0x31) = 1;

  }

  else {

    *(undefined8 *)(param_2 + 0x28) = *(undefined8 *)(param_1 + 0x24);

    *(undefined1 *)(param_2 + 0x31) = *(undefined1 *)(param_1 + 0x2d);

  }

  return;

}




