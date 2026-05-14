// Address: 0x14017f560
// Ghidra name: FUN_14017f560
// ============ 0x14017f560 FUN_14017f560 (size=61) ============


/* WARNING: Removing unreachable block (ram,0x00014017f582) */



uint FUN_14017f560(void)



{

  longlong lVar1;

  

  if ((DAT_1403fc6a5 != '\0') && (6 < DAT_1403fc6a0)) {

    lVar1 = cpuid_Extended_Feature_Enumeration_info(7);

    return *(uint *)(lVar1 + 4) & 0x10000;

  }

  return 0;

}




