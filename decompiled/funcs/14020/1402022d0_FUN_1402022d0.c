// Address: 0x1402022d0
// Ghidra name: FUN_1402022d0
// ============ 0x1402022d0 FUN_1402022d0 (size=533) ============


void FUN_1402022d0(undefined8 param_1,uint param_2)



{

  undefined8 uVar1;

  

  FUN_14014b7f0();

  if ((int)param_2 < 0x16161805) {

    if (param_2 == 0x16161804) {

      uVar1 = 0x16362004;

    }

    else if ((int)param_2 < 0x15520c03) {

      if (param_2 == 0x15520c02) {

        uVar1 = 0x15721002;

      }

      else if (param_2 == 0x15120c02) {

        uVar1 = 0x15321002;

      }

      else if (param_2 == 0x15130f02) {

        uVar1 = 0x15331002;

      }

      else if (param_2 == 0x15321002) {

        uVar1 = 0x15120c02;

      }

      else {

        if (param_2 != 0x15331002) {

          if (param_2 != 0) goto LAB_140202332;

          goto LAB_140202344;

        }

        uVar1 = 0x15130f02;

      }

    }

    else if (param_2 == 0x15530f02) {

      uVar1 = 0x15731002;

    }

    else if (param_2 == 0x15721002) {

      uVar1 = 0x15520c02;

    }

    else {

      if (param_2 != 0x15731002) goto LAB_140202332;

      uVar1 = 0x15530f02;

    }

LAB_14020242b:

    FUN_14014b7f0(param_1,uVar1);

LAB_14020243a:

    if (((param_2 & 0xf000000) + 0xfb000000 & 0xfeffffff) != 0) goto switchD_140202476_caseD_1;

LAB_140202446:

    if ((param_2 & 0xf0000) == 0x60000) goto LAB_1402024ce;

    switch((int)param_2 >> 0x14 & 0xf) {

    default:

      goto switchD_140202476_caseD_1;

    case 2:

    case 4:

      FUN_14014b7f0(param_1,0x16261804);

      uVar1 = 0x16462004;

      break;

    case 5:

    case 7:

      FUN_14014b7f0(param_1,0x16561804);

      uVar1 = 0x16762004;

      break;

    case 6:

    case 8:

      FUN_14014b7f0(param_1,0x16661804);

      uVar1 = 0x16862004;

    }

  }

  else {

    if ((int)param_2 < 0x16561805) {

      if (param_2 == 0x16561804) {

        uVar1 = 0x16762004;

      }

      else if (param_2 == 0x16261804) {

        uVar1 = 0x16462004;

      }

      else if (param_2 == 0x16362004) {

        uVar1 = 0x16161804;

      }

      else {

        if (param_2 != 0x16462004) goto LAB_140202332;

        uVar1 = 0x16261804;

      }

      goto LAB_14020242b;

    }

    if (param_2 == 0x16661804) {

      uVar1 = 0x16862004;

      goto LAB_14020242b;

    }

    if (param_2 == 0x16762004) {

      uVar1 = 0x16561804;

      goto LAB_14020242b;

    }

    if (param_2 == 0x16862004) {

      uVar1 = 0x16661804;

      goto LAB_14020242b;

    }

LAB_140202332:

    if ((param_2 & 0xf0000000) == 0x10000000) {

LAB_140202344:

      if ((param_2 & 0xf000000) != 0x4000000) goto LAB_14020243a;

      goto LAB_140202446;

    }

switchD_140202476_caseD_1:

    FUN_14014b7f0(param_1,0x16161804);

    uVar1 = 0x16362004;

  }

  FUN_14014b7f0(param_1,uVar1);

LAB_1402024ce:

  FUN_14014b7f0(param_1,0x13000801);

  return;

}




