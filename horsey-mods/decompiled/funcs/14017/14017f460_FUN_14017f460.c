// Address: 0x14017f460
// Ghidra name: FUN_14017f460
// ============ 0x14017f460 FUN_14017f460 (size=190) ============


/* WARNING: Removing unreachable block (ram,0x00014017f4ae) */

/* WARNING: Removing unreachable block (ram,0x00014017f48e) */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_14017f460(void)



{

  int *piVar1;

  undefined8 *puVar2;

  int iVar3;

  uint in_XCR0;

  

  if (DAT_1403fc6a6 == '\0') {

    DAT_1403fc6a6 = '\x01';

    iVar3 = FUN_14000c580();

    if (iVar3 != 0) {

      piVar1 = (int *)cpuid_basic_info(0);

      DAT_1403fc6a0 = *piVar1;

      if (0 < DAT_1403fc6a0) {

        puVar2 = (undefined8 *)cpuid_Version_info(1);

        _DAT_1403fc690 = *puVar2;

        _DAT_1403fc698 = CONCAT44(*(undefined4 *)(puVar2 + 1),*(uint *)((longlong)puVar2 + 0xc));

        if ((*(uint *)((longlong)puVar2 + 0xc) >> 0x1b & 1) != 0) {

          DAT_1403fc6a4 = (in_XCR0 & 6) == 6;

          if (((bool)DAT_1403fc6a4) && (((byte)in_XCR0 & 0xe0) == 0xe0)) {

            DAT_1403fc6a5 = 1;

            return;

          }

          DAT_1403fc6a5 = 0;

        }

      }

    }

  }

  return;

}




