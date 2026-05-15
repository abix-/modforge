// Address: 0x140157b80
// Ghidra name: FUN_140157b80
// ============ 0x140157b80 FUN_140157b80 (size=477) ============


undefined4 FUN_140157b80(short param_1,short param_2,char *param_3,char param_4)



{

  char cVar1;

  int iVar2;

  undefined4 uVar3;

  undefined4 uVar4;

  longlong lVar5;

  

  uVar4 = 1;

  if (param_1 == 0) {

    if (param_2 != 0) goto LAB_140157c12;

    if (param_3 == (char *)0x0) {

      return 1;

    }

    iVar2 = strcmp(param_3,"Lic Pro Controller");

    if (((iVar2 != 0) && (iVar2 = strcmp(param_3,"Nintendo Wireless Gamepad"), iVar2 != 0)) &&

       (iVar2 = strcmp(param_3,"Wireless Gamepad"), iVar2 != 0)) {

      return 1;

    }

switchD_140157cfd_caseD_26:

    uVar4 = 7;

  }

  else {

    if (param_1 == 1) {

      if (param_2 == 1) {

        return 1;

      }

    }

    else if (param_1 == 0x57e) {

      if ((param_2 == 0x2006) || (param_2 == 0x2067)) {

        return 8;

      }

      if ((param_2 == 0x2007) || (param_2 == 0x2066)) {

        if ((param_3 != (char *)0x0) &&

           (lVar5 = thunk_FUN_1402c9340(param_3,"NES Controller"), lVar5 != 0)) {

          return 1;

        }

        return 9;

      }

      if (param_2 == 0x200e) {

        if (param_3 == (char *)0x0) {

          return 9;

        }

        lVar5 = thunk_FUN_1402c9340(param_3,&DAT_140333508);

        if (lVar5 == 0) {

          return 9;

        }

        return 8;

      }

      if ((param_2 == 0x2008) || (param_2 == 0x2068)) {

        return 10;

      }

    }

LAB_140157c12:

    if ((param_4 != '\0') && (cVar1 = FUN_140159470(param_1,param_2), cVar1 != '\0')) {

      return 0xb;

    }

    uVar3 = FUN_140211000(param_1,param_2);

    switch(uVar3) {

    case 0x1f:

      uVar4 = 2;

      break;

    case 0x20:

      uVar4 = 3;

      break;

    case 0x21:

      uVar4 = 4;

      break;

    case 0x22:

      uVar4 = 5;

      break;

    case 0x26:

    case 0x2a:

      goto switchD_140157cfd_caseD_26;

    case 0x2c:

      uVar4 = 1;

      if (param_4 != '\0') {

        uVar4 = 7;

      }

      break;

    case 0x2d:

      uVar4 = 6;

      break;

    case 0x2e:

      uVar4 = 5;

      if (param_4 == '\0') {

        uVar4 = 1;

      }

    }

  }

  return uVar4;

}




