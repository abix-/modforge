// Address: 0x14017aa70
// Ghidra name: FUN_14017aa70
// ============ 0x14017aa70 FUN_14017aa70 (size=1227) ============


undefined8 FUN_14017aa70(undefined4 param_1,int param_2,int param_3,int param_4,int param_5)



{

  undefined8 uVar1;

  

  switch(param_1) {

  case 1:

    return 0x11200100;

  case 2:

    return 0x1c200200;

  case 4:

    return 0x12200400;

  case 8:

    if (((param_2 == 0xe0) && (param_3 == 0x1c)) && (param_4 == 3)) {

      uVar1 = 0x13000801;

      if (param_5 == 0) {

        uVar1 = 0x14110801;

      }

      return uVar1;

    }

    return 0x13000801;

  case 0xc:

    if (param_2 == 0) {

      return 0x15120c02;

    }

    if (param_2 == 0xf00) {

      if ((param_3 == 0xf0) && (param_4 == 0xf)) {

        uVar1 = 0;

        if (param_5 == 0) {

          uVar1 = 0x15120c02;

        }

        return uVar1;

      }

    }

    else if (((param_2 == 0xf) && (param_3 == 0xf0)) && (param_4 == 0xf00)) {

      uVar1 = 0;

      if (param_5 == 0) {

        uVar1 = 0x15520c02;

      }

      return uVar1;

    }

    break;

  case 0xf:

    if (param_2 == 0) {

      return 0x15130f02;

    }

    goto LAB_14017ab53;

  case 0x10:

    if (param_2 == 0) {

      return 0x15151002;

    }

LAB_14017ab53:

    if (param_2 == 0x7c00) {

      if ((param_3 == 0x3e0) && (param_4 == 0x1f)) {

        if (param_5 == 0) {

          return 0x15130f02;

        }

        uVar1 = 0;

        if (param_5 == 0x8000) {

          uVar1 = 0x15331002;

        }

        return uVar1;

      }

    }

    else if (param_2 == 0x1f) {

      if (param_3 == 0x3e0) {

        if (param_4 == 0x7c00) {

          if (param_5 != 0) {

            uVar1 = 0;

            if (param_5 == 0x8000) {

              uVar1 = 0x15731002;

            }

            return uVar1;

          }

          return 0x15530f02;

        }

      }

      else if ((param_3 == 0x7e0) && (param_4 == 0xf800)) {

        uVar1 = 0;

        if (param_5 == 0) {

          uVar1 = 0x15551002;

        }

        return uVar1;

      }

    }

    else if (param_2 == 0xf00) {

      if ((param_3 == 0xf0) && (param_4 == 0xf)) {

        uVar1 = 0;

        if (param_5 == 0xf000) {

          uVar1 = 0x15321002;

        }

        return uVar1;

      }

    }

    else if (param_2 == 0xf000) {

      if ((param_3 == 0xf00) && (param_4 == 0xf0)) {

        uVar1 = 0;

        if (param_5 == 0xf) {

          uVar1 = 0x15421002;

        }

        return uVar1;

      }

    }

    else if (param_2 == 0xf) {

      if ((param_3 == 0xf0) && (param_4 == 0xf00)) {

        uVar1 = 0;

        if (param_5 == 0xf000) {

          uVar1 = 0x15721002;

        }

        return uVar1;

      }

    }

    else if (param_2 == 0xf0) {

      if ((param_3 == 0xf00) && (param_4 == 0xf000)) {

        uVar1 = 0;

        if (param_5 == 0xf) {

          uVar1 = 0x15821002;

        }

        return uVar1;

      }

    }

    else if (param_2 == 0xf800) {

      if (param_3 == 0x7c0) {

        if (param_4 == 0x3e) {

          uVar1 = 0;

          if (param_5 == 1) {

            uVar1 = 0x15441002;

          }

          return uVar1;

        }

      }

      else if (((param_3 == 0x7e0) && (param_4 == 0x1f)) && (param_5 == 0)) {

        return 0x15151002;

      }

    }

    else if (param_2 == 0x3e) {

      if ((param_3 == 0x7c0) && (param_4 == 0xf800)) {

        uVar1 = 0;

        if (param_5 == 1) {

          uVar1 = 0x15841002;

        }

        return uVar1;

      }

    }

    else if (((param_2 == 0x3f) && (param_3 == 0x7c0)) && (param_4 == 0xf800)) {

      uVar1 = 0;

      if (param_5 == 0) {

        uVar1 = 0x15151002;

      }

      return uVar1;

    }

    break;

  case 0x18:

    if (param_2 != 0) {

      if (param_2 == 0xff) {

        return 0x17101803;

      }

      if (param_2 != 0xff0000) {

        return 0;

      }

    }

    return 0x17401803;

  case 0x1e:

    if (param_2 == 0x3ff00000) {

      if ((param_3 == 0xffc00) && (param_4 == 0x3ff)) {

        if (param_5 == 0) {

          return 0x16172004;

        }

        return 0;

      }

    }

    else if (((param_2 == 0x3ff) && (param_3 == 0xffc00)) && (param_4 == 0x3ff00000)) {

      if (param_5 == 0) {

        return 0x16572004;

      }

      return 0;

    }

    break;

  case 0x20:

    if (param_2 == 0) {

      return 0x16161804;

    }

    if (param_2 == 0xff0000) {

      if ((param_3 == 0xff00) && (param_4 == 0xff)) {

        if (param_5 == 0) {

          return 0x16161804;

        }

        uVar1 = 0;

        if (param_5 == -0x1000000) {

          uVar1 = 0x16362004;

        }

        return uVar1;

      }

    }

    else if (param_2 == -0x1000000) {

      if ((param_3 == 0xff0000) && (param_4 == 0xff00)) {

        if (param_5 != 0) {

          uVar1 = 0;

          if (param_5 == 0xff) {

            uVar1 = 0x16462004;

          }

          return uVar1;

        }

        return 0x16261804;

      }

    }

    else if (param_2 == 0xff) {

      if ((param_3 == 0xff00) && (param_4 == 0xff0000)) {

        if (param_5 != 0) {

          uVar1 = 0;

          if (param_5 == -0x1000000) {

            uVar1 = 0x16762004;

          }

          return uVar1;

        }

        return 0x16561804;

      }

    }

    else if (param_2 == 0xff00) {

      if ((param_3 == 0xff0000) && (param_4 == -0x1000000)) {

        if (param_5 != 0) {

          uVar1 = 0;

          if (param_5 == 0xff) {

            uVar1 = 0x16862004;

          }

          return uVar1;

        }

        return 0x16661804;

      }

    }

    else if (param_2 == 0x3ff00000) {

      if ((param_3 == 0xffc00) && (param_4 == 0x3ff)) {

        if (param_5 == 0) {

          return 0x16172004;

        }

        uVar1 = 0;

        if (param_5 == -0x40000000) {

          uVar1 = 0x16372004;

        }

        return uVar1;

      }

    }

    else if (((param_2 == 0x3ff) && (param_3 == 0xffc00)) && (param_4 == 0x3ff00000)) {

      if (param_5 == 0) {

        return 0x16572004;

      }

      uVar1 = 0;

      if (param_5 == -0x40000000) {

        uVar1 = 0x16772004;

      }

      return uVar1;

    }

  }

  return 0;

}




