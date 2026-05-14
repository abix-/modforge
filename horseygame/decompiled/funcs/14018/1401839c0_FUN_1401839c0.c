// Address: 0x1401839c0
// Ghidra name: FUN_1401839c0
// ============ 0x1401839c0 FUN_1401839c0 (size=704) ============


uint FUN_1401839c0(undefined8 param_1,byte param_2,undefined4 param_3,int param_4,int param_5,

                  char param_6)



{

  char cVar1;

  byte bVar2;

  char cVar3;

  uint uVar4;

  int iVar5;

  byte *pbVar6;

  byte bVar7;

  ushort uVar8;

  int iVar9;

  longlong lVar10;

  int local_b8 [2];

  undefined8 local_b0;

  undefined4 local_a8;

  undefined4 local_a4;

  int local_a0;

  int local_9c;

  ushort local_98;

  undefined2 local_96;

  char local_94;

  char local_93;

  

  lVar10 = (longlong)param_5;

  iVar5 = 0;

  bVar2 = 0;

  cVar1 = '\0';

  cVar3 = '\0';

  bVar7 = param_2 & 5;

  uVar4 = param_5 - 1;

  iVar9 = 0x301 - (uint)(param_6 != '\0');

  if (uVar4 < 0x1ff) {

    if (param_6 == '\0') {

      if ((&DAT_1403fc8ea)[lVar10] == '\0') goto LAB_140183a54;

      (&DAT_1403fc6ea)[lVar10] = 0;

      cVar3 = cVar1;

    }

    else {

      pbVar6 = &DAT_1403fc6ea + lVar10;

      if ((&DAT_1403fc8ea)[lVar10] != '\0') {

        if ((bVar7 & *pbVar6) == 0) {

          uVar4 = 0;

          *pbVar6 = *pbVar6 | bVar7;

          goto LAB_140183a54;

        }

        cVar1 = '\x01';

      }

      *pbVar6 = *pbVar6 | bVar7;

      cVar3 = cVar1;

    }

    (&DAT_1403fc8ea)[lVar10] = param_6;

    iVar5 = FUN_140183200(param_5,DAT_1403fc6e8,&DAT_1403fc801);

  }

  else if (param_4 == 0) {

LAB_140183a54:

    return uVar4 & 0xffffff00;

  }

  if (bVar7 == 1) {

    DAT_1403fcb00 = FUN_140149350();

  }

  else if (bVar7 == 4) {

    DAT_1403fcafc = 1;

  }

  if (((param_2 & 8) == 0) && (cVar3 == '\0')) {

    switch(iVar5) {

    case 0x400000e0:

      uVar8 = 0x40;

      break;

    case 0x400000e1:

      uVar8 = 1;

      break;

    case 0x400000e2:

      uVar8 = 0x100;

      break;

    case 0x400000e3:

      uVar8 = 0x400;

      break;

    case 0x400000e4:

      uVar8 = 0x80;

      break;

    case 0x400000e5:

      uVar8 = 2;

      break;

    case 0x400000e6:

      uVar8 = 0x200;

      break;

    case 0x400000e7:

      uVar8 = 0x800;

      break;

    default:

      uVar8 = 0;

      break;

    case 0x40000101:

      uVar8 = 0x4000;

    }

    if (param_6 == '\0') {

      DAT_1403fc6e8 = DAT_1403fc6e8 & ~uVar8;

    }

    else if (iVar5 == 0x40000039) {

      DAT_1403fc6e8 = DAT_1403fc6e8 ^ 0x2000;

    }

    else if (iVar5 == 0x40000047) {

      DAT_1403fc6e8 = DAT_1403fc6e8 ^ 0x8000;

    }

    else if (iVar5 == 0x40000053) {

      DAT_1403fc6e8 = DAT_1403fc6e8 ^ 0x1000;

    }

    else {

      DAT_1403fc6e8 = DAT_1403fc6e8 | uVar8;

    }

  }

  cVar1 = FUN_140139420(iVar9);

  if (cVar1 != '\0') {

    local_98 = DAT_1403fc6e8;

    local_96 = (undefined2)param_4;

    local_a0 = param_5;

    local_94 = param_6;

    if (DAT_1403fc6e0 == (undefined4 *)0x0) {

      local_a8 = 0;

    }

    else {

      local_a8 = *DAT_1403fc6e0;

    }

    local_b8[0] = iVar9;

    local_b0 = param_1;

    local_a4 = param_3;

    local_9c = iVar5;

    local_93 = cVar3;

    bVar2 = FUN_14013b140(local_b8);

  }

  if ((((iVar5 == 9) && (param_6 != '\0')) && ((DAT_1403fc6e8 & 0x300) != 0)) &&

     (((DAT_1403fc6e0 != (undefined4 *)0x0 && ((DAT_1403fc6e0[0x12] & 0x100001) == 0x100001)) &&

      (cVar3 = FUN_140142940("SDL_ALLOW_ALT_TAB_WHILE_GRABBED",1), cVar3 != '\0')))) {

    FUN_14016f4f0(DAT_1403fc6e0);

  }

  return (uint)bVar2;

}




