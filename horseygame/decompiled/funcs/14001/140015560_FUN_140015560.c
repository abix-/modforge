// Address: 0x140015560
// Ghidra name: FUN_140015560
// ============ 0x140015560 FUN_140015560 (size=133) ============


void FUN_140015560(longlong param_1,int param_2)



{

  if ((param_2 < 0) || (*(int *)(param_1 + 0x14) <= param_2)) {

    FID_conflict__assert

              (L"0 <= nodeId && nodeId < m_nodeCapacity",

               L"C:\\dev\\Box2d2\\Box2D\\Collision\\b2DynamicTree.cpp",0x61);

  }

  if (*(int *)(param_1 + 0x10) < 1) {

    FID_conflict__assert

              (L"0 < m_nodeCount",L"C:\\dev\\Box2d2\\Box2D\\Collision\\b2DynamicTree.cpp",0x62);

  }

  *(undefined4 *)((longlong)param_2 * 0x28 + 0x18 + *(longlong *)(param_1 + 8)) =

       *(undefined4 *)(param_1 + 0x18);

  *(undefined4 *)((longlong)param_2 * 0x28 + 0x24 + *(longlong *)(param_1 + 8)) = 0xffffffff;

  *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + -1;

  *(int *)(param_1 + 0x18) = param_2;

  return;

}




