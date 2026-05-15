// Address: 0x14014bad0
// Ghidra name: FUN_14014bad0
// ============ 0x14014bad0 FUN_14014bad0 (size=624) ============


undefined8 FUN_14014bad0(longlong param_1,int *param_2)



{

  int iVar1;

  char cVar2;

  longlong lVar3;

  int local_res8 [2];

  int local_res18 [4];

  

  if ((param_1 == 0) ||

     ((DAT_1403e3d60 != '\0' && (cVar2 = FUN_1401aa7c0(param_1,2), cVar2 == '\0')))) {

    FUN_14012e850("Parameter \'%s\' is invalid","renderer");

    return 0;

  }

  if (*(char *)(param_1 + 0x2d8) != '\0') {

    FUN_14012e850("Renderer\'s window has been destroyed, can\'t use further");

    return 0;

  }

  iVar1 = *param_2;

  if (iVar1 == 0x400) {

    lVar3 = FUN_14016e190(param_2[4]);

    if (lVar3 != *(longlong *)(param_1 + 0x118)) {

      return 1;

    }

    FUN_14014fc50(param_1);

    FUN_1401536e0(param_1);

    return 1;

  }

  if (1 < iVar1 - 0x401U) {

    if (iVar1 == 0x403) {

      lVar3 = FUN_14016e190(param_2[4]);

      if (lVar3 != *(longlong *)(param_1 + 0x118)) {

        return 1;

      }

      goto LAB_14014bd02;

    }

    if (iVar1 - 0x700U < 4) {

      if (*(longlong *)(param_1 + 0x118) == 0) {

        return 1;

      }

      cVar2 = FUN_14016ed40(*(longlong *)(param_1 + 0x118),local_res18,local_res8);

      if (cVar2 == '\0') {

        return 0;

      }

      FUN_14014fc50(param_1,(float)local_res18[0] * (float)param_2[8],

                    (float)local_res8[0] * (float)param_2[9],param_2 + 8,param_2 + 9);

      FUN_1401536e0(param_1,(float)local_res18[0] * (float)param_2[10],

                    (float)local_res8[0] * (float)param_2[0xb],param_2 + 10,param_2 + 0xb);

      return 1;

    }

    if ((((iVar1 != 0x1306) && (1 < iVar1 - 0x1302U)) && (1 < iVar1 - 0x1304U)) && (iVar1 != 0x1307)

       ) {

      if ((1 < iVar1 - 0x1003U) && (1 < iVar1 - 0x1000U)) {

        return 1;

      }

      lVar3 = FUN_14016e190(param_2[4]);

      if (lVar3 != *(longlong *)(param_1 + 0x118)) {

        return 1;

      }

      goto LAB_14014bd02;

    }

  }

  lVar3 = FUN_14016e190(param_2[4]);

  if (lVar3 != *(longlong *)(param_1 + 0x118)) {

    return 1;

  }

LAB_14014bd02:

  FUN_14014fc50(param_1);

  return 1;

}




