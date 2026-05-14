// Address: 0x1401fa4f0
// Ghidra name: FUN_1401fa4f0
// ============ 0x1401fa4f0 FUN_1401fa4f0 (size=112) ============


char FUN_1401fa4f0(int param_1,int param_2)



{

  char cVar1;

  

  if (0x3b9d2b62 < param_1) {

    if (param_1 == 0x3b9d2b63) {

      return (param_2 != 0) + '\x01';

    }

    if (param_1 == 0x3b9d2b6d) {

      cVar1 = '\x04';

      if (param_2 == 0) {

        cVar1 = '\x02';

      }

      return cVar1;

    }

switchD_1401fa51e_caseD_a:

    return '\x04';

  }

  if (param_1 != 0x3b9d2b62) {

    switch(param_1) {

    case 9:

      break;

    default:

      goto switchD_1401fa51e_caseD_a;

    case 0x10:

      return '\x02';

    case 0x61:

      return '\b';

    }

  }

  return '\x01';

}




