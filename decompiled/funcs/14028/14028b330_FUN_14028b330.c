// Address: 0x14028b330
// Ghidra name: FUN_14028b330
// ============ 0x14028b330 FUN_14028b330 (size=59) ============


void FUN_14028b330(longlong param_1,longlong param_2)



{

  *(uint *)(param_2 + 4) =

       (int)*(short *)(param_1 + 0x3c) - (uint)(*(ushort *)(param_1 + 0x36) >> 1);

  *(uint *)(param_2 + 8) =

       (uint)(*(ushort *)(param_1 + 0x36) >> 1) + (int)*(short *)(param_1 + 0x3c);

  *(int *)(param_2 + 0xc) = (int)*(short *)(param_1 + 0x30);

  *(int *)(param_2 + 0x10) = (int)*(short *)(param_1 + 0x2a);

  *(uint *)(param_2 + 0x14) = (uint)*(ushort *)(param_1 + 0x1e);

  return;

}




