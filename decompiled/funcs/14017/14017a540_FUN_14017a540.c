// Address: 0x14017a540
// Ghidra name: FUN_14017a540
// ============ 0x14017a540 FUN_14017a540 (size=969) ============


undefined8

FUN_14017a540(uint param_1,uint *param_2,undefined4 *param_3,undefined4 *param_4,undefined4 *param_5

             ,undefined4 *param_6)



{

  uint uVar1;

  undefined8 uVar2;

  uint uVar3;

  undefined4 uVar4;

  uint uVar5;

  undefined4 uVar6;

  uint uVar7;

  undefined4 uVar8;

  undefined4 uVar9;

  

  uVar1 = (int)param_1 >> 0x1c & 0xf;

  if ((param_1 != 0) && (uVar1 != 1)) {

    uVar1 = 0;

    *param_6 = 0;

    *param_5 = 0;

    *param_4 = 0;

    *param_3 = 0;

    if ((param_1 == 0x32595559) || ((param_1 == 0x55595659 || (param_1 == 0x59565955)))) {

      uVar1 = 0x20;

    }

    *param_2 = uVar1;

    return 1;

  }

  uVar3 = 2;

  uVar5 = param_1 & 0xff;

  uVar6 = 0;

  uVar9 = 1;

  uVar7 = 0;

  if (uVar5 < 3) {

    if ((param_1 == 0) || (uVar1 == 1)) {

      uVar7 = (int)param_1 >> 8 & 0xff;

    }

  }

  else {

    uVar7 = uVar5;

    if ((param_1 != 0) && (uVar1 != 1)) {

      if ((param_1 == 0x32595559) ||

         (((param_1 == 0x59565955 || (param_1 == 0x55595659)) || (param_1 == 0x30313050)))) {

        uVar7 = 2;

      }

      else {

        uVar7 = 1;

      }

    }

    uVar7 = uVar7 * 8;

  }

  *param_2 = uVar7;

  uVar7 = param_1 & 0xf000000;

  *param_6 = 0;

  *param_5 = 0;

  *param_4 = 0;

  *param_3 = 0;

  uVar1 = (int)param_1 >> 0x14;

  if (uVar7 == 0x7000000) {

    if (((param_1 == 0) || ((param_1 & 0xf0000000) == 0x10000000)) ||

       ((uVar5 = uVar3, param_1 == 0x32595559 ||

        (((param_1 == 0x59565955 || (param_1 == 0x55595659)) || (param_1 == 0x30313050)))))) {

      if (uVar5 == 3) {

        if ((uVar1 & 0xf) == 1) {

          *param_3 = 0xff;

          *param_4 = 0xff00;

          *param_5 = 0xff0000;

          return 1;

        }

        if ((uVar1 & 0xf) == 4) {

          *param_3 = 0xff0000;

          *param_4 = 0xff00;

          *param_5 = 0xff;

          return 1;

        }

      }

      else if (uVar5 == 4) {

        uVar1 = uVar1 & 0xf;

        if (uVar1 == 2) {

          *param_3 = 0xff;

          *param_4 = 0xff00;

          *param_5 = 0xff0000;

          *param_6 = 0xff000000;

          return 1;

        }

        if (uVar1 == 3) {

          *param_3 = 0xff00;

          *param_4 = 0xff0000;

          *param_5 = 0xff000000;

LAB_14017a6ca:

          *param_6 = 0xff;

          return 1;

        }

        if (uVar1 == 5) {

          *param_3 = 0xff0000;

          *param_4 = 0xff00;

          *param_5 = 0xff;

          *param_6 = 0xff000000;

          return 1;

        }

        if (uVar1 == 6) {

          *param_3 = 0xff000000;

          *param_4 = 0xff0000;

          *param_5 = 0xff00;

          goto LAB_14017a6ca;

        }

      }

    }

    goto switchD_14017a7bd_default;

  }

  if ((uVar7 + 0xfc000000 & 0xfcffffff) != 0) {

    return 1;

  }

  if (uVar7 == 0x7000000) {

    return 1;

  }

  switch((int)param_1 >> 0x10 & 0xf) {

  case 1:

    uVar4 = 0xe0;

    uVar8 = 0x1c;

    uVar6 = 0;

    goto LAB_14017a86d;

  case 2:

    uVar4 = 0xf00;

    uVar6 = 0xf000;

    uVar8 = 0xf0;

    uVar9 = 0xf;

    break;

  case 3:

    uVar4 = 0x7c00;

    uVar6 = 0x8000;

    uVar8 = 0x3e0;

    uVar9 = 0x1f;

    break;

  case 4:

    uVar4 = 0x7c0;

    uVar6 = 0xf800;

    uVar8 = 0x3e;

    break;

  case 5:

    uVar4 = 0xf800;

    uVar8 = 0x7e0;

    uVar9 = 0x1f;

    break;

  case 6:

    uVar4 = 0xff0000;

    uVar6 = 0xff000000;

    uVar8 = 0xff00;

    uVar9 = 0xff;

    break;

  case 7:

    uVar4 = 0x3ff00000;

    uVar6 = 0xc0000000;

    uVar8 = 0xffc00;

    uVar9 = 0x3ff;

    break;

  case 8:

    uVar4 = 0x3ff000;

    uVar8 = 0xffc;

    uVar6 = 0xffc00000;

LAB_14017a86d:

    uVar9 = 3;

    break;

  default:

    goto switchD_14017a7bd_default;

  }

  switch(uVar1 & 0xf) {

  case 1:

    *param_3 = uVar4;

    uVar2 = 1;

    *param_4 = uVar8;

    *param_5 = uVar9;

    break;

  case 2:

    *param_3 = uVar6;

    uVar2 = 1;

    *param_4 = uVar4;

    *param_5 = uVar8;

    break;

  case 3:

    *param_6 = uVar6;

    uVar2 = 1;

    *param_3 = uVar4;

    *param_4 = uVar8;

    *param_5 = uVar9;

    break;

  case 4:

    *param_3 = uVar6;

    uVar2 = 1;

    *param_4 = uVar4;

    *param_5 = uVar8;

    *param_6 = uVar9;

    break;

  case 6:

    *param_5 = uVar6;

    uVar2 = 1;

    *param_4 = uVar4;

    *param_3 = uVar8;

    break;

  case 7:

    *param_6 = uVar6;

  case 5:

    *param_5 = uVar4;

    uVar2 = 1;

    *param_4 = uVar8;

    *param_3 = uVar9;

    break;

  case 8:

    *param_5 = uVar6;

    uVar2 = 1;

    *param_4 = uVar4;

    *param_3 = uVar8;

    *param_6 = uVar9;

    break;

  default:

switchD_14017a7bd_default:

    uVar2 = FUN_14012e850("Unknown pixel format");

  }

  return uVar2;

}




