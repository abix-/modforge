// Address: 0x1401916e0
// Ghidra name: FUN_1401916e0
// ============ 0x1401916e0 FUN_1401916e0 (size=208) ============


ushort FUN_1401916e0(byte param_1)



{

  ushort uVar1;

  ushort uVar2;

  ushort uVar3;

  ushort uVar4;

  ushort uVar5;

  ushort uVar6;

  

  uVar4 = -(ushort)((param_1 & 1) != 0) & 0xa001;

  uVar1 = -(ushort)(((param_1 >> 1 ^ (byte)uVar4) & 1) != 0) & 0xa001;

  uVar5 = -(ushort)(((param_1 >> 2 ^ (byte)uVar1) & 1) != 0) & 0xa001;

  uVar2 = -(ushort)(((param_1 >> 3 ^ (byte)uVar5) & 1) != 0) & 0xa001;

  uVar6 = -(ushort)(((param_1 >> 4 ^ (byte)uVar2) & 1) != 0) & 0xa001;

  uVar3 = -(ushort)(((param_1 >> 5 ^ (byte)uVar6) & 1) != 0) & 0xa001;

  uVar1 = -(ushort)(((param_1 >> 6 ^ (byte)uVar3) & 1) != 0) & 0xa001 ^

          (ushort)(uVar3 ^ (ushort)(uVar6 ^ (ushort)(uVar2 ^ (ushort)(uVar5 ^ (ushort)(uVar1 ^ uVar4

                                                                                               >> 1)

                                                                              >> 1) >> 1) >> 1) >> 1

                  ) >> 1;

  return -(ushort)(((param_1 >> 7 ^ (byte)uVar1) & 1) != 0) & 0xa001 ^ uVar1 >> 1;

}




