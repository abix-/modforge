// Address: 0x14020a8f0
// Ghidra name: FUN_14020a8f0
// ============ 0x14020a8f0 FUN_14020a8f0 (size=47) ============


ulonglong FUN_14020a8f0(void)



{

  ulonglong in_RAX;

  int iVar1;

  ulonglong *puVar2;

  

  iVar1 = 0;

  puVar2 = DAT_1403fd230;

  if (0 < DAT_1403fd238) {

    do {

      in_RAX = *puVar2;

      if (*(char *)(in_RAX + 0x50) == '\0') {

        return CONCAT71((int7)(in_RAX >> 8),1);

      }

      iVar1 = iVar1 + 1;

      puVar2 = puVar2 + 1;

    } while (iVar1 < DAT_1403fd238);

  }

  return in_RAX & 0xffffffffffffff00;

}




