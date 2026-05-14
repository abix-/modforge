// Address: 0x140130230
// Ghidra name: FUN_140130230
// ============ 0x140130230 FUN_140130230 (size=433) ============


ulonglong FUN_140130230(uint *param_1,uint *param_2)



{

  uint uVar1;

  uint uVar2;

  uint uVar3;

  uint uVar4;

  uint uVar5;

  uint uVar6;

  float fVar7;

  

  uVar1 = *param_1;

  uVar2 = *param_2;

  uVar4 = 0;

  uVar6 = uVar4;

  if ((uVar1 == 0) || ((uVar1 & 0xf0000000) == 0x10000000)) {

    if ((uVar2 != 0) && ((uVar2 & 0xf0000000) != 0x10000000)) {

      return 1;

    }

    if ((uVar1 == 0) || ((uVar1 & 0xf0000000) == 0x10000000)) {

      uVar6 = (int)uVar1 >> 8 & 0xff;

    }

  }

  else {

    if (uVar2 == 0) {

      return 0xffffffff;

    }

    if ((uVar2 & 0xf0000000) == 0x10000000) {

      return 0xffffffff;

    }

  }

  uVar5 = 0;

  if ((uVar2 == 0) || (uVar3 = uVar5, (uVar2 & 0xf0000000) == 0x10000000)) {

    uVar3 = (int)uVar2 >> 8 & 0xff;

  }

  if (uVar6 <= uVar3) {

    if ((uVar2 == 0) || ((uVar2 & 0xf0000000) == 0x10000000)) {

      uVar5 = (int)uVar2 >> 8 & 0xff;

    }

    if ((uVar1 == 0) || ((uVar1 & 0xf0000000) == 0x10000000)) {

      uVar4 = (int)uVar1 >> 8 & 0xff;

    }

    if (uVar4 < uVar5) {

      return 1;

    }

    if ((int)param_1[2] <= (int)param_2[2]) {

      if ((int)param_1[2] < (int)param_2[2]) {

        return 1;

      }

      if ((int)param_1[3] <= (int)param_2[3]) {

        if ((int)param_1[3] < (int)param_2[3]) {

          return 1;

        }

        uVar1 = param_2[4];

        if (param_1[4] == 0) {

          if (uVar1 != 0) {

            return 1;

          }

        }

        else if (uVar1 == 0) {

          return 0xffffffff;

        }

        fVar7 = (float)(int)param_1[4] / (float)(int)param_1[5];

        if (fVar7 <= (float)(int)uVar1 / (float)(int)param_2[5]) {

          if (fVar7 < (float)(int)uVar1 / (float)(int)param_2[5]) {

            return 1;

          }

          if ((param_1[1] & 0xf000000) != 0x2000000) {

            return (ulonglong)((param_2[1] & 0xf000000) == 0x2000000);

          }

          if ((param_2[1] & 0xf000000) == 0x2000000) {

            return 0;

          }

        }

      }

    }

  }

  return 0xffffffff;

}




