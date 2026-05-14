// Address: 0x14017f520
// Ghidra name: FUN_14017f520
// ============ 0x14017f520 FUN_14017f520 (size=58) ============


/* WARNING: Removing unreachable block (ram,0x00014017f542) */



uint FUN_14017f520(void)



{

  longlong lVar1;

  

  if ((DAT_1403fc6a4 != '\0') && (6 < DAT_1403fc6a0)) {

    lVar1 = cpuid_Extended_Feature_Enumeration_info(7);

    return *(uint *)(lVar1 + 4) & 0x20;

  }

  return 0;

}




