// Address: 0x140186c70
// Ghidra name: FUN_140186c70
// ============ 0x140186c70 FUN_140186c70 (size=831) ============


undefined8 FUN_140186c70(uint param_1)



{

  if (param_1 - 0x8000 < 0x8000) {

    return 0x1c;

  }

  if (param_1 - 0x151 < 8) {

    return 2;

  }

  if (param_1 - 0x202 < 0x19) {

    return 3;

  }

  if (param_1 < 0x301) {

    if (param_1 != 0x300) {

      switch(param_1) {

      case 0x100:

        return 0x1b;

      case 0x101:

      case 0x102:

      case 0x103:

      case 0x104:

      case 0x105:

      case 0x106:

      case 0x107:

      case 0x108:

        goto switchD_140186cdf_caseD_101;

      default:

        goto switchD_140186cdf_default;

      }

    }

switchD_140186d15_caseD_301:

    return 5;

  }

  if (param_1 < 0x401) {

    if (param_1 == 0x400) {

      return 10;

    }

    switch(param_1) {

    case 0x301:

      goto switchD_140186d15_caseD_301;

    case 0x302:

      return 6;

    case 0x303:

      return 8;

    case 0x304:

      goto switchD_140186cdf_caseD_101;

    case 0x305:

    case 0x306:

      return 4;

    case 0x307:

      return 7;

    }

  }

  else if (param_1 < 0x701) {

    if (param_1 == 0x700) {

      return 0x1d;

    }

    if (param_1 < 0x601) {

      if (param_1 == 0x600) {

        return 0xe;

      }

      if ((param_1 == 0x401) || (param_1 == 0x402)) {

        return 0xb;

      }

      if (param_1 == 0x403) {

        return 0xc;

      }

      if ((param_1 == 0x404) || (param_1 == 0x405)) {

        return 9;

      }

    }

    else {

      switch(param_1) {

      case 0x601:

        return 0xf;

      case 0x602:

        return 0x10;

      case 0x603:

      case 0x604:

        return 0x11;

      case 0x605:

      case 0x606:

      case 0x608:

        return 0xd;

      case 0x607:

        return 0x12;

      case 0x650:

        return 0x14;

      case 0x651:

      case 0x652:

        return 0x15;

      case 0x653:

      case 0x654:

      case 0x655:

      case 0x65a:

      case 0x65b:

        return 0x13;

      case 0x656:

      case 0x657:

      case 0x658:

        return 0x16;

      case 0x659:

        return 0x17;

      }

    }

  }

  else if (param_1 < 0x1301) {

    if (param_1 == 0x1300) {

switchD_140186f2b_caseD_1301:

      return 0x1e;

    }

    if (0x1002 < param_1) {

      if (param_1 < 0x1102) {

        if (param_1 != 0x1101) {

          if (param_1 == 0x1003) {

            return 0x23;

          }

          if (param_1 == 0x1004) {

            return 0x23;

          }

          if (param_1 != 0x1100) goto switchD_140186cdf_default;

        }

      }

      else if (param_1 != 0x1102) {

        if (param_1 == 0x1200) {

          return 0x1a;

        }

        goto switchD_140186cdf_default;

      }

      return 0x18;

    }

    if (param_1 == 0x1002) {

      return 0x23;

    }

    if (param_1 < 0x901) {

      if (param_1 == 0x900) {

        return 0x24;

      }

      if (param_1 == 0x701) {

        return 0x1d;

      }

      if (param_1 == 0x702) {

        return 0x1d;

      }

      if (param_1 == 0x703) {

        return 0x1d;

      }

    }

    else {

      if (param_1 == 0x1000) {

        return 0x23;

      }

      if (param_1 == 0x1001) {

        return 0x23;

      }

    }

  }

  else if (param_1 < 0x1401) {

    if (param_1 == 0x1400) {

      return 0x19;

    }

    switch(param_1) {

    case 0x1301:

      goto switchD_140186f2b_caseD_1301;

    case 0x1302:

    case 0x1303:

      return 0x1f;

    case 0x1304:

    case 0x1305:

      return 0x21;

    case 0x1306:

      return 0x20;

    case 0x1307:

      return 0x22;

    }

  }

  else if (param_1 < 0x2001) {

    if (param_1 == 0x2000) {

      return 0x25;

    }

    if (param_1 == 0x1401) {

      return 0x19;

    }

    if (param_1 == 0x1402) {

      return 0x19;

    }

    if (param_1 == 0x1403) {

      return 0x19;

    }

  }

  else {

    if (param_1 == 0x2001) {

      return 0x25;

    }

    if (param_1 == 0x2002) {

      return 0x25;

    }

  }

switchD_140186cdf_default:

  FUN_14012e850("Unknown event type");

  return 0;

switchD_140186cdf_caseD_101:

  return 1;

}




