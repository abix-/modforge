// Address: 0x1402e90b0
// Ghidra name: FUN_1402e90b0
// ============ 0x1402e90b0 FUN_1402e90b0 (size=178) ============


/* WARNING: Removing unreachable block (ram,0x0001402e9130) */

/* WARNING: Removing unreachable block (ram,0x0001402e9122) */

/* WARNING: Removing unreachable block (ram,0x0001402e90c7) */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined8 FUN_1402e90b0(void)



{

  longlong lVar1;

  int *piVar2;

  byte in_XCR0;

  

  DAT_1403ff158 = 0;

  _DAT_1403ff15c = 0;

  lVar1 = cpuid_Version_info(1);

  if ((*(uint *)(lVar1 + 0xc) & 0x18001000) == 0x18001000) {

    if ((in_XCR0 & 6) == 6) {

      DAT_1403ff158 = 1;

      _DAT_1403ff15c = 1;

    }

    else {

      DAT_1403ff158 = 0;

    }

  }

  if ((DAT_1403ff158 != 0) && (piVar2 = (int *)cpuid_basic_info(0), 6 < *piVar2)) {

    lVar1 = cpuid_Extended_Feature_Enumeration_info(7);

    if ((*(uint *)(lVar1 + 4) & 0x20) != 0) {

      _DAT_1403ff15c = 3;

      DAT_1403ff158 = 3;

      return 0;

    }

  }

  return 0;

}




