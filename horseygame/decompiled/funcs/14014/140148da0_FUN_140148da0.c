// Address: 0x140148da0
// Ghidra name: FUN_140148da0
// ============ 0x140148da0 FUN_140148da0 (size=599) ============


ulonglong FUN_140148da0(byte *param_1,int param_2,int param_3,undefined1 param_4,undefined1 param_5,

                       undefined1 param_6,undefined1 param_7)



{

  char cVar1;

  byte bVar2;

  uint uVar3;

  ulonglong uVar4;

  ulonglong uVar5;

  longlong lVar6;

  undefined4 local_18 [4];

  

  cVar1 = FUN_1401489c0();

  if (((cVar1 == '\0') || (uVar3 = *(uint *)(param_1 + 4), uVar3 == 0)) ||

     (*(longlong *)(param_1 + 0x18) == 0)) {

    uVar4 = FUN_14012e850("Parameter \'%s\' is invalid","surface");

  }

  else if ((param_2 < 0) || (*(int *)(param_1 + 8) <= param_2)) {

    uVar4 = FUN_14012e850("Parameter \'%s\' is invalid",&DAT_14030a29c);

  }

  else if ((param_3 < 0) || (*(int *)(param_1 + 0xc) <= param_3)) {

    uVar4 = FUN_14012e850("Parameter \'%s\' is invalid",&DAT_14030a2a0);

  }

  else {

    if ((uVar3 & 0xf0000000) == 0x10000000) {

      uVar3 = uVar3 & 0xff;

    }

    else if ((((uVar3 == 0x32595559) || (uVar3 == 0x59565955)) || (uVar3 == 0x55595659)) ||

            (uVar3 == 0x30313050)) {

      uVar3 = 2;

    }

    else {

      uVar3 = 1;

    }

    uVar5 = (ulonglong)uVar3;

    if (((*param_1 & 2) == 0) || (uVar4 = FUN_140146f20(param_1), (char)uVar4 != '\0')) {

      lVar6 = (longlong)param_2 * uVar5 + (longlong)(*(int *)(param_1 + 0x10) * param_3) +

              *(longlong *)(param_1 + 0x18);

      if ((uVar5 < 5) &&

         ((*(uint *)(param_1 + 4) == 0 || ((*(uint *)(param_1 + 4) & 0xf0000000) == 0x10000000)))) {

        local_18[0] = FUN_14017bba0(*(undefined8 *)(param_1 + 0x38),*(undefined8 *)(param_1 + 0x48),

                                    param_4,param_5,param_6,param_7);

        FUN_1402f8e20(lVar6,local_18,uVar5);

        bVar2 = 1;

      }

      else {

        uVar3 = *(uint *)(param_1 + 4);

        if ((uVar3 == 0) || ((uVar3 & 0xf0000000) == 0x10000000)) {

          local_18[0] = CONCAT31(CONCAT12(param_7,CONCAT11(param_6,param_5)),param_4);

          bVar2 = FUN_140144d60(1,1,0x16762004,0x120005a0,0,local_18,4,uVar3,

                                *(undefined4 *)(param_1 + 0x40),*(undefined4 *)(param_1 + 0x34),

                                lVar6,*(int *)(param_1 + 0x10));

        }

        else {

          bVar2 = FUN_14012e850("That operation is not supported");

        }

      }

      if ((*param_1 & 2) != 0) {

        FUN_1401489e0(param_1);

      }

      uVar4 = (ulonglong)bVar2;

    }

  }

  return uVar4;

}




