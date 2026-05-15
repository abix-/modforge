// Address: 0x1401a5120
// Ghidra name: FUN_1401a5120
// ============ 0x1401a5120 FUN_1401a5120 (size=220) ============


ulonglong FUN_1401a5120(longlong param_1,longlong param_2)



{

  uint uVar1;

  int *piVar2;

  int iVar3;

  uint uVar4;

  uint uVar5;

  

  uVar1 = *(uint *)(param_1 + 0x18);

  uVar4 = (int)uVar1 >> 1 & 0x5555U | (uVar1 & 0x5555) * 2;

  uVar4 = uVar4 >> 2 & 0x3333 | (uVar4 & 0x3333) << 2;

  uVar4 = uVar4 >> 4 & 0xf0f | (uVar4 & 0xf0f) << 4;

  piVar2 = (int *)(param_2 + 0x448);

  uVar5 = (uVar4 & 0xff) << 8 | uVar4 >> 8;

  uVar4 = 10;

  if (*piVar2 <= (int)uVar5) {

    do {

      uVar4 = uVar4 + 1;

      piVar2 = piVar2 + 1;

    } while (*piVar2 <= (int)uVar5);

    if (0xf < (int)uVar4) {

      return 0xffffffff;

    }

  }

  iVar3 = (uint)*(ushort *)(param_2 + 0x464 + (longlong)(int)uVar4 * 2) +

          (((int)uVar5 >> (0x10 - (byte)uVar4 & 0x1f)) -

          (uint)*(ushort *)(param_2 + 0x400 + (longlong)(int)uVar4 * 2));

  if ((iVar3 < 0x120) && (*(byte *)((longlong)iVar3 + 0x484 + param_2) == uVar4)) {

    *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) - uVar4;

    *(uint *)(param_1 + 0x18) = uVar1 >> ((byte)uVar4 & 0x1f);

    return (ulonglong)*(ushort *)(param_2 + 0x5a4 + (longlong)iVar3 * 2);

  }

  return 0xffffffff;

}




