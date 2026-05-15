// Address: 0x140155130
// Ghidra name: FUN_140155130
// ============ 0x140155130 FUN_140155130 (size=631) ============


undefined8 FUN_140155130(uint *param_1,int *param_2)



{

  uint uVar1;

  longlong lVar2;

  char cVar3;

  uint uVar4;

  undefined8 uVar5;

  undefined4 *puVar6;

  byte bVar7;

  uint uVar8;

  

  if ((param_1 == (uint *)0x0) ||

     ((DAT_1403e3d60 != '\0' && (cVar3 = FUN_1401aa7c0(param_1,3), cVar3 == '\0')))) {

    FUN_14012e850("Parameter \'%s\' is invalid","texture");

    return 0;

  }

  uVar1 = *param_1;

  uVar8 = (int)uVar1 >> 0x1c & 0xf;

  if (uVar1 == 0) {

    uVar4 = 0;

LAB_14015519e:

    if (((uVar4 != 0xc000000) && (uVar4 != 0x2000000)) && (uVar4 != 0x3000000)) {

LAB_1401551b3:

      uVar5 = FUN_14012e850("Texture isn\'t palettized format");

      return uVar5;

    }

  }

  else {

    if (uVar8 != 1) goto LAB_1401551b3;

    uVar4 = uVar1 & 0xf000000;

    if (uVar4 != 0x1000000) goto LAB_14015519e;

  }

  if (param_2 != (int *)0x0) {

    if ((uVar1 == 0) || (uVar8 == 1)) {

      bVar7 = (byte)(uVar1 >> 8);

    }

    else {

      bVar7 = 0;

    }

    if (1 << (bVar7 & 0x1f) < *param_2) {

      uVar5 = FUN_14012e850("Palette doesn\'t match surface format");

      return uVar5;

    }

  }

  if (param_2 != *(int **)(param_1 + 0x36)) {

    lVar2 = *(longlong *)(param_1 + 4);

    if ((*(int **)(param_1 + 0x36) != (int *)0x0) &&

       (FUN_14017a0f0(), *(longlong *)(param_1 + 0x3e) == 0)) {

      **(int **)(param_1 + 0x38) = **(int **)(param_1 + 0x38) + -1;

      if (**(int **)(param_1 + 0x38) == 0) {

        FUN_140149da0(lVar2);

        (**(code **)(lVar2 + 0x80))(lVar2,*(undefined8 *)(param_1 + 0x38));

        FUN_1401ab340(*(undefined8 *)(lVar2 + 0x200),*(undefined8 *)(param_1 + 0x36));

      }

      param_1[0x38] = 0;

      param_1[0x39] = 0;

    }

    *(int **)(param_1 + 0x36) = param_2;

    param_1[0x3a] = 0;

    if ((param_2 != (int *)0x0) && (param_2[5] = param_2[5] + 1, *(longlong *)(param_1 + 0x3e) == 0)

       ) {

      cVar3 = FUN_1401aaff0(*(undefined8 *)(lVar2 + 0x200),param_2,param_1 + 0x38);

      if (cVar3 == '\0') {

        puVar6 = (undefined4 *)FUN_1401841a0(1,0x18);

        if (puVar6 == (undefined4 *)0x0) {

LAB_140155300:

          FUN_140155130(param_1,0);

          return 0;

        }

        cVar3 = (**(code **)(lVar2 + 0x70))(lVar2,puVar6);

        if (cVar3 == '\0') {

          (**(code **)(lVar2 + 0x80))(lVar2,puVar6);

          goto LAB_140155300;

        }

        *(undefined4 **)(param_1 + 0x38) = puVar6;

        *puVar6 = 1;

        cVar3 = FUN_1401ab100(*(undefined8 *)(lVar2 + 0x200),param_2,*(undefined8 *)(param_1 + 0x38)

                              ,0);

        if (cVar3 == '\0') goto LAB_140155300;

      }

      else {

        **(int **)(param_1 + 0x38) = **(int **)(param_1 + 0x38) + 1;

      }

      if (*(longlong *)(param_1 + 0x3e) == 0) {

        if (*(code **)(lVar2 + 0x88) != (code *)0x0) {

          (**(code **)(lVar2 + 0x88))(lVar2,param_1);

        }

      }

    }

    if (*(longlong *)(param_1 + 0x3c) != 0) {

      FUN_1401487f0(*(longlong *)(param_1 + 0x3c),param_2);

    }

  }

  return 1;

}




