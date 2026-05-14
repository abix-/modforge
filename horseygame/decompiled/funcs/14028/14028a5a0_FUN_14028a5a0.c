// Address: 0x14028a5a0
// Ghidra name: FUN_14028a5a0
// ============ 0x14028a5a0 FUN_14028a5a0 (size=92) ============


ulonglong FUN_14028a5a0(undefined8 param_1)



{

  uint uVar1;

  short sVar2;

  uint *puVar3;

  uint uVar4;

  

  sVar2 = FUN_140158e60();

  puVar3 = (uint *)FUN_140158b60(param_1);

  if (sVar2 == 0x46d) {

    uVar1 = (uint)puVar3;

    uVar4 = 0;

    puVar3 = &DAT_1403e7a50;

    do {

      if (*puVar3 == (uVar1 & 0xffff)) {

        return CONCAT71((int7)((ulonglong)puVar3 >> 8),1);

      }

      uVar4 = uVar4 + 1;

      puVar3 = puVar3 + 1;

    } while (uVar4 < 6);

  }

  return (ulonglong)puVar3 & 0xffffffffffffff00;

}




