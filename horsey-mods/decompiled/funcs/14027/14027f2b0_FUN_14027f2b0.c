// Address: 0x14027f2b0
// Ghidra name: FUN_14027f2b0
// ============ 0x14027f2b0 FUN_14027f2b0 (size=492) ============


undefined8 FUN_14027f2b0(undefined2 param_1,ushort param_2)



{

  undefined8 uVar1;

  ushort uVar2;

  

  switch(param_1) {

  case 0xc24f:

    if ((param_2 & 0xfff8) != 0x1350) {

      uVar1 = 0;

      if ((param_2 & 0xff00) == 0x8900) {

        uVar1 = 0xc24f;

      }

      return uVar1;

    }

    break;

  default:

    return 0;

  case 0xc294:

  case 0xc298:

    if (((param_2 & 0xfff8) != 0x1350) && (uVar2 = param_2 & 0xff00, uVar2 != 0x8900)) {

      if ((param_2 & 0xfff0) == 0x1230) {

        return 0xc29b;

      }

      if (uVar2 != 0x1200) {

        if (uVar2 == 0x1300) {

          return 0xc29a;

        }

        uVar1 = 0;

        if ((param_2 & 0xf000) == 0x1000) {

          uVar1 = 0xc298;

        }

        return uVar1;

      }

      return 0xc299;

    }

    break;

  case 0xc299:

    if (((param_2 & 0xfff8) != 0x1350) && ((param_2 & 0xff00) != 0x8900)) {

      if ((param_2 & 0xfff0) == 0x1230) {

        return 0xc29b;

      }

      uVar1 = 0;

      if ((param_2 & 0xff00) == 0x1200) {

        uVar1 = 0xc299;

      }

      return uVar1;

    }

    break;

  case 0xc29a:

    if (((param_2 & 0xfff8) != 0x1350) && ((param_2 & 0xff00) != 0x8900)) {

      uVar1 = 0;

      if ((param_2 & 0xff00) == 0x1300) {

        uVar1 = 0xc29a;

      }

      return uVar1;

    }

    break;

  case 0xc29b:

    if (((param_2 & 0xfff8) != 0x1350) && ((param_2 & 0xff00) != 0x8900)) {

      uVar1 = 0;

      if ((param_2 & 0xfff0) == 0x1230) {

        uVar1 = 0xc29b;

      }

      return uVar1;

    }

  }

  return 0xc24f;

}




