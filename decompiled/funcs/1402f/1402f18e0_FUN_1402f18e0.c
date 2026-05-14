// Address: 0x1402f18e0
// Ghidra name: FUN_1402f18e0
// ============ 0x1402f18e0 FUN_1402f18e0 (size=92) ============


ulonglong FUN_1402f18e0(ulonglong param_1)



{

  uint uVar1;

  

  uVar1 = (uint)(param_1 >> 0x34) & 0x7ff;

  if (uVar1 == 0x7ff) {

    return (ulonglong)(ushort)(((param_1 & 0xfffffffffffff) != 0) + 1);

  }

  if (uVar1 == 0) {

    return CONCAT62((int6)(-(param_1 & 0x7fffffffffffffff) >> 0x10),

                    -(ushort)((param_1 & 0x7fffffffffffffff) != 0)) & 0xfffffffffffffffe;

  }

  return 0xffffffff;

}




