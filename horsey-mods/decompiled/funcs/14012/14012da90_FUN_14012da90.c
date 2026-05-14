// Address: 0x14012da90
// Ghidra name: FUN_14012da90
// ============ 0x14012da90 FUN_14012da90 (size=66) ============


char * FUN_14012da90(int param_1)



{

  if (param_1 - 1U < 7) {

    if ((char *)(&DAT_1403fb580)[param_1] != (char *)0x0) {

      return (char *)(&DAT_1403fb580)[param_1];

    }

    if (param_1 == 5) {

      return "WARNING: ";

    }

    if ((param_1 == 6) || (param_1 == 7)) {

      return "ERROR: ";

    }

  }

  return "";

}




