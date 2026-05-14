// Address: 0x140281f80
// Ghidra name: FUN_140281f80
// ============ 0x140281f80 FUN_140281f80 (size=737) ============


void FUN_140281f80(undefined8 *param_1)



{

  longlong lVar1;

  longlong lVar2;

  undefined8 uVar3;

  char *pcVar4;

  undefined1 uVar5;

  

  lVar1 = param_1[0xe];

  switch(*(undefined1 *)(lVar1 + 8)) {

  case 0x13:

switchD_140281fc4_caseD_13:

    uVar5 = 1;

    break;

  case 0x14:

  case 0x15:

  case 0x17:

    uVar5 = 0x10;

    break;

  case 0x16:

    uVar5 = 0x11;

    break;

  case 0x18:

  case 0x1a:

  case 0x1d:

switchD_140281fc4_caseD_18:

    uVar5 = 2;

    break;

  default:

    lVar2 = FUN_14012f030(*param_1,"VADER");

    uVar5 = 0;

    if (lVar2 == 0) {

      lVar2 = thunk_FUN_1402c9340(*param_1,&DAT_14037ff20);

      if (lVar2 != 0) {

        lVar2 = thunk_FUN_1402c9340(*param_1,"APEX2");

        if (lVar2 != 0) goto switchD_140281fc4_caseD_13;

        lVar2 = thunk_FUN_1402c9340(*param_1,"APEX3");

        if (lVar2 != 0) goto switchD_140281fc4_caseD_18;

        lVar2 = thunk_FUN_1402c9340(*param_1,"APEX4");

        if (lVar2 != 0) goto switchD_140281fc4_caseD_54;

        lVar2 = thunk_FUN_1402c9340(*param_1,"APEX5");

        uVar5 = 0;

        if (lVar2 != 0) {

          uVar5 = 4;

        }

      }

    }

    else {

      lVar2 = thunk_FUN_1402c9340(*param_1,"VADER2");

      if (lVar2 == 0) {

        lVar2 = thunk_FUN_1402c9340(*param_1,"VADER3");

        if (lVar2 != 0) goto switchD_140281fc4_caseD_1c;

        lVar2 = thunk_FUN_1402c9340(*param_1,"VADER4");

        if (lVar2 != 0) goto switchD_140281fc4_caseD_55;

        lVar2 = thunk_FUN_1402c9340(*param_1,"Vader 5");

        if (lVar2 != 0) goto switchD_140281fc4_caseD_82;

      }

      else {

        uVar5 = 0x10;

      }

    }

    break;

  case 0x1c:

switchD_140281fc4_caseD_1c:

    uVar5 = 0x12;

    break;

  case 0x50:

  case 0x51:

    uVar5 = 0x13;

    break;

  case 0x54:

switchD_140281fc4_caseD_54:

    uVar5 = 3;

    break;

  case 0x55:

  case 0x5b:

  case 0x69:

switchD_140281fc4_caseD_55:

    uVar5 = 0x14;

    break;

  case 0x80:

  case 0x81:

  case 0x85:

  case 0x86:

    uVar5 = 4;

    break;

  case 0x82:

switchD_140281fc4_caseD_82:

    uVar5 = 0x15;

  }

  *(undefined1 *)((longlong)param_1 + 0x3f) = uVar5;

  *(undefined8 *)(lVar1 + 0x20) = 8000000;

  switch(uVar5) {

  case 1:

    FUN_1402083c0(param_1,"Flydigi Apex 2");

    break;

  case 2:

    FUN_1402083c0(param_1,"Flydigi Apex 3");

    break;

  case 3:

    FUN_1402083c0(param_1,"Flydigi Apex 4");

    break;

  case 4:

    FUN_1402083c0(param_1,"Flydigi Apex 5");

    *(undefined1 *)(lVar1 + 0xb) = 1;

    uVar3 = 0xfbb0f;

    if (*(char *)(lVar1 + 0xd) != '\0') {

      uVar3 = 0x33b986;

    }

    *(undefined1 *)(lVar1 + 0xe) = 1;

    *(undefined8 *)(lVar1 + 0x20) = uVar3;

    *(undefined4 *)(lVar1 + 0x28) = 0x3b1ce80a;

    *(undefined4 *)(lVar1 + 0x2c) = 0x420ba058;

    break;

  default:

    FUN_14012e080(7,"Unknown FlyDigi controller with ID %d, name \'%s\'",*(undefined1 *)(lVar1 + 8),

                  *param_1);

    break;

  case 0x10:

    FUN_1402083c0(param_1,"Flydigi Vader 2");

    *(undefined1 *)(lVar1 + 10) = 1;

    break;

  case 0x11:

    FUN_1402083c0(param_1,"Flydigi Vader 2 Pro");

    *(undefined1 *)(lVar1 + 10) = 1;

    break;

  case 0x12:

    FUN_1402083c0(param_1,"Flydigi Vader 3");

    *(undefined1 *)(lVar1 + 10) = 1;

    break;

  case 0x13:

    pcVar4 = "Flydigi Vader 3 Pro";

    goto LAB_1402821c6;

  case 0x14:

    pcVar4 = "Flydigi Vader 4 Pro";

LAB_1402821c6:

    FUN_1402083c0(param_1,pcVar4);

    *(undefined1 *)(lVar1 + 10) = 1;

    uVar3 = 2000000;

    if (*(char *)(lVar1 + 0xd) != '\0') {

      uVar3 = 1000000;

    }

    *(undefined4 *)(lVar1 + 0x28) = 0x3d1ce80a;

    *(undefined8 *)(lVar1 + 0x20) = uVar3;

    *(undefined1 *)(lVar1 + 0xe) = 1;

    break;

  case 0x15:

    FUN_1402083c0(param_1,"Flydigi Vader 5 Pro");

    *(undefined2 *)(lVar1 + 10) = 0x101;

    *(undefined8 *)(lVar1 + 0x20) = 2000000;

    *(undefined1 *)(lVar1 + 0xc) = 1;

    *(undefined4 *)(lVar1 + 0x28) = 0x3b1ce80a;

    *(undefined4 *)(lVar1 + 0x2c) = 0x420ba058;

    *(undefined1 *)(lVar1 + 0xe) = 1;

  }

  return;

}




