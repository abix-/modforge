// Address: 0x14020a920
// Ghidra name: FUN_14020a920
// ============ 0x14020a920 FUN_14020a920 (size=44) ============


ulonglong FUN_14020a920(void)



{

  char *pcVar1;

  uint uVar2;

  

  uVar2 = 0;

  pcVar1 = &DAT_1403fd1e3;

  while ((pcVar1[-1] == '\0' || (*pcVar1 != '\0'))) {

    uVar2 = uVar2 + 1;

    pcVar1 = pcVar1 + 0x18;

    if (3 < uVar2) {

      return (ulonglong)pcVar1 & 0xffffffffffffff00;

    }

  }

  return CONCAT71((int7)((ulonglong)pcVar1 >> 8),1);

}




