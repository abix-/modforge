// Address: 0x1401e47b0
// Ghidra name: FUN_1401e47b0
// ============ 0x1401e47b0 FUN_1401e47b0 (size=490) ============


undefined1

FUN_1401e47b0(longlong param_1,uint *param_2,undefined4 *param_3,longlong param_4,int param_5)



{

  undefined1 uVar1;

  char cVar2;

  int iVar3;

  longlong lVar4;

  longlong lVar5;

  uint uVar6;

  longlong lVar7;

  

  lVar7 = *(longlong *)(param_2 + 0x4e);

  if (lVar7 == 0) {

    uVar1 = FUN_14012e850("Texture is not currently available");

    return uVar1;

  }

  if (*(char *)(lVar7 + 0x60) == '\0') {

    if (*(char *)(lVar7 + 0x38) == '\0') {

      uVar6 = *param_2;

      if ((uVar6 == 0) || ((uVar6 & 0xf0000000) == 0x10000000)) {

        uVar6 = uVar6 & 0xff;

      }

      else if (((uVar6 == 0x32595559) || (uVar6 == 0x59565955)) ||

              ((uVar6 == 0x55595659 || (uVar6 == 0x30313050)))) {

        uVar6 = 2;

      }

      else {

        uVar6 = 1;

      }

      cVar2 = FUN_1401e49a0(*(undefined8 *)(param_1 + 0x2e0),*(undefined8 *)(lVar7 + 8),uVar6,

                            *param_3,param_3[1],param_3[2],param_3[3],param_4,param_5);

      return cVar2 != '\0';

    }

    iVar3 = (param_5 + 1) / 2;

    lVar5 = param_3[3] * param_5 + param_4;

    lVar4 = ((param_3[3] + 1) / 2) * iVar3 + lVar5;

    lVar7 = lVar5;

    if (*param_2 == 0x32315659) {

      lVar7 = lVar4;

      lVar4 = lVar5;

    }

    uVar1 = FUN_1401e4f80(param_1,param_2,param_3,param_4,param_5,lVar7,iVar3,lVar4,iVar3);

    return uVar1;

  }

  uVar6 = *param_2;

  if ((uVar6 == 0) || ((uVar6 & 0xf0000000) == 0x10000000)) {

    uVar6 = uVar6 & 0xff;

  }

  else if ((((uVar6 == 0x32595559) || (uVar6 == 0x59565955)) || (uVar6 == 0x55595659)) ||

          (uVar6 == 0x30313050)) {

    uVar6 = 2;

  }

  else {

    uVar6 = 1;

  }

  uVar1 = FUN_1401e4c50(param_1,param_2,param_3,param_4,param_5,param_5 * param_3[3] + param_4,

                        param_5 + -1 + uVar6 * 2 & uVar6 * -2);

  return uVar1;

}




