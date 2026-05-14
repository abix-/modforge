// Address: 0x14012e730
// Ghidra name: FUN_14012e730
// ============ 0x14012e730 FUN_14012e730 (size=61) ============


char * FUN_14012e730(void)



{

  int *piVar1;

  

  piVar1 = (int *)FUN_1401637d0(0);

  if (piVar1 != (int *)0x0) {

    if (*piVar1 == 1) {

      return *(char **)(piVar1 + 2);

    }

    if (*piVar1 == 2) {

      return "Out of memory";

    }

  }

  return "";

}




