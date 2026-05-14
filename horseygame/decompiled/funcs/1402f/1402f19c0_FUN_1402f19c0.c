// Address: 0x1402f19c0
// Ghidra name: FUN_1402f19c0
// ============ 0x1402f19c0 FUN_1402f19c0 (size=61) ============


uint FUN_1402f19c0(uint param_1)



{

  if ((param_1 & 0x7f800000) == 0x7f800000) {

    return (uint)(ushort)(((param_1 & 0x7fffff) != 0) + 1);

  }

  if ((param_1 & 0x7f800000) == 0) {

    return CONCAT22((short)(-(param_1 & 0x7fffffff) >> 0x10),-(ushort)((param_1 & 0x7fffffff) != 0))

           & 0xfffffffe;

  }

  return 0xffffffff;

}




