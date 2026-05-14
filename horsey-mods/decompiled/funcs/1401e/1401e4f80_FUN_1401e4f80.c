// Address: 0x1401e4f80
// Ghidra name: FUN_1401e4f80
// ============ 0x1401e4f80 FUN_1401e4f80 (size=594) ============


undefined1

FUN_1401e4f80(longlong param_1,uint *param_2,int *param_3,undefined8 param_4,undefined4 param_5,

             undefined8 param_6,undefined4 param_7,undefined8 param_8,undefined4 param_9)



{

  longlong lVar1;

  undefined8 uVar2;

  undefined1 uVar3;

  char cVar4;

  uint uVar5;

  uint uVar6;

  

  lVar1 = *(longlong *)(param_2 + 0x4e);

  uVar2 = *(undefined8 *)(param_1 + 0x2e0);

  if (lVar1 == 0) {

    uVar3 = FUN_14012e850("Texture is not currently available");

    return uVar3;

  }

  uVar6 = *param_2;

  uVar5 = 1;

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

  cVar4 = FUN_1401e49a0(uVar2,*(undefined8 *)(lVar1 + 8),uVar6,*param_3,param_3[1],param_3[2],

                        param_3[3],param_4,param_5);

  if (cVar4 != '\0') {

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

    cVar4 = FUN_1401e49a0(uVar2,*(undefined8 *)(lVar1 + 0x40),uVar6,*param_3 / 2,param_3[1] / 2,

                          (param_3[2] + 1) / 2,(param_3[3] + 1) / 2,param_6,param_7);

    if (cVar4 != '\0') {

      uVar6 = *param_2;

      if ((uVar6 == 0) || ((uVar6 & 0xf0000000) == 0x10000000)) {

        uVar5 = uVar6 & 0xff;

      }

      else if ((((uVar6 == 0x32595559) || (uVar6 == 0x59565955)) || (uVar6 == 0x55595659)) ||

              (uVar6 == 0x30313050)) {

        uVar5 = 2;

      }

      cVar4 = FUN_1401e49a0(uVar2,*(undefined8 *)(lVar1 + 0x50),uVar5,*param_3 / 2,param_3[1] / 2,

                            (param_3[2] + 1) / 2,(param_3[3] + 1) / 2,param_8,param_9);

      return cVar4 != '\0';

    }

  }

  return false;

}




