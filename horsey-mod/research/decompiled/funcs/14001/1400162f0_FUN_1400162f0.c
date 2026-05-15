// Address: 0x1400162f0
// Ghidra name: FUN_1400162f0
// ============ 0x1400162f0 FUN_1400162f0 (size=69) ============


longlong FUN_1400162f0(longlong param_1,int param_2)



{

  if ((param_2 < 0) || (*(int *)(param_1 + 0x18) <= param_2)) {

    FID_conflict__assert

              (L"0 <= index && index < m_count",

               L"C:\\dev\\Box2d2\\Box2D\\Collision\\Shapes\\b2ChainShape.h",0x58);

  }

  return *(longlong *)(param_1 + 0x10) + (longlong)param_2 * 8;

}




