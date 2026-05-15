// Address: 0x14000ce00
// Ghidra name: FUN_14000ce00
// ============ 0x14000ce00 FUN_14000ce00 (size=213) ============


void FUN_14000ce00(longlong param_1,undefined8 param_2,int param_3)



{

  undefined8 uVar1;

  

  if ((*(longlong *)(param_1 + 0x10) != 0) || (*(int *)(param_1 + 0x18) != 0)) {

    FID_conflict__assert

              (L"m_vertices == 0 && m_count == 0",

               L"C:\\dev\\Box2d2\\Box2D\\Collision\\Shapes\\b2ChainShape.cpp",0x22);

  }

  if (param_3 < 3) {

    FID_conflict__assert

              (L"count >= 3",L"C:\\dev\\Box2d2\\Box2D\\Collision\\Shapes\\b2ChainShape.cpp",0x23);

  }

  *(int *)(param_1 + 0x18) = param_3 + 1;

  uVar1 = _malloc_base((longlong)(param_3 * 8 + 8));

  *(undefined8 *)(param_1 + 0x10) = uVar1;

  FUN_1402f8e20(uVar1,param_2,(longlong)param_3 * 8);

  (*(undefined8 **)(param_1 + 0x10))[param_3] = **(undefined8 **)(param_1 + 0x10);

  *(undefined8 *)(param_1 + 0x1c) =

       *(undefined8 *)

        (*(longlong *)(param_1 + 0x10) + -0x10 + (longlong)*(int *)(param_1 + 0x18) * 8);

  *(undefined8 *)(param_1 + 0x24) = *(undefined8 *)(*(longlong *)(param_1 + 0x10) + 8);

  *(undefined2 *)(param_1 + 0x2c) = 0x101;

  return;

}




