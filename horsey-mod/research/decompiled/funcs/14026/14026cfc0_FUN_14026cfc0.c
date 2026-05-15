// Address: 0x14026cfc0
// Ghidra name: FUN_14026cfc0
// ============ 0x14026cfc0 FUN_14026cfc0 (size=676) ============


void FUN_14026cfc0(longlong param_1)



{

  short sVar1;

  longlong lVar2;

  char cVar3;

  char *pcVar4;

  undefined1 local_28 [32];

  

  lVar2 = *(longlong *)(param_1 + 0x70);

  if (*(char *)(lVar2 + 0x10) != '\0') {

    cVar3 = FUN_140159470(*(undefined2 *)(param_1 + 0x20),*(undefined2 *)(param_1 + 0x22));

    if (cVar3 == '\0') {

      return;

    }

    *(undefined4 *)(param_1 + 0x5c) = 0xb;

    return;

  }

  switch(*(undefined4 *)(lVar2 + 0x20)) {

  case 0:

    if (*(short *)(param_1 + 0x20) != 0x57e) {

      return;

    }

    sVar1 = *(short *)(param_1 + 0x22);

    if (sVar1 == 0x2006) {

      *(undefined4 *)(lVar2 + 0x20) = 1;

      FUN_1402083c0(param_1,"Nintendo Switch Joy-Con (L)");

      *(undefined4 *)(param_1 + 0x5c) = 8;

      return;

    }

    if (sVar1 == 0x2007) {

      *(undefined4 *)(lVar2 + 0x20) = 2;

      FUN_1402083c0(param_1,"Nintendo Switch Joy-Con (R)");

      *(undefined4 *)(param_1 + 0x5c) = 9;

      return;

    }

    if (sVar1 != 0x2009) {

      return;

    }

    *(undefined4 *)(lVar2 + 0x20) = 3;

    FUN_1402083c0(param_1,"Nintendo Switch Pro Controller");

    *(undefined4 *)(param_1 + 0x5c) = 7;

    return;

  case 1:

    FUN_1402083c0(param_1,"Nintendo Switch Joy-Con (L)");

    FUN_140208430(param_1,0x57e,0x2006);

    *(undefined4 *)(param_1 + 0x5c) = 8;

    goto LAB_14026d0b8;

  case 2:

    FUN_1402083c0(param_1,"Nintendo Switch Joy-Con (R)");

    FUN_140208430(param_1,0x57e,0x2007);

    *(undefined4 *)(param_1 + 0x5c) = 9;

    goto LAB_14026d0b8;

  case 3:

  case 6:

    FUN_1402083c0(param_1,"Nintendo Switch Pro Controller");

    FUN_140208430(param_1,0x57e,0x2009);

    *(undefined4 *)(param_1 + 0x5c) = 7;

    goto LAB_14026d0b8;

  case 7:

    pcVar4 = "Nintendo HVC Controller (1)";

    goto LAB_14026d0a9;

  case 8:

    pcVar4 = "Nintendo HVC Controller (2)";

    goto LAB_14026d0a9;

  case 9:

    pcVar4 = "Nintendo NES Controller (L)";

    goto LAB_14026d0a9;

  case 10:

    pcVar4 = "Nintendo NES Controller (R)";

LAB_14026d0a9:

    FUN_1402083c0(param_1,pcVar4);

    break;

  case 0xb:

    FUN_1402083c0(param_1,"Nintendo SNES Controller");

    FUN_140208430(param_1,0x57e,0x2017);

    break;

  case 0xc:

    FUN_1402083c0(param_1,"Nintendo N64 Controller");

    FUN_140208430(param_1,0x57e,0x2019);

    break;

  case 0xd:

    FUN_1402083c0(param_1,"Nintendo SEGA Genesis Controller");

    FUN_140208430(param_1,0x57e,0x201e);

  }

  *(undefined4 *)(param_1 + 0x5c) = 1;

LAB_14026d0b8:

  *(undefined1 *)(param_1 + 0x3f) = *(undefined1 *)(lVar2 + 0x20);

  FUN_14012ef10(local_28,0x12,"%.2x-%.2x-%.2x-%.2x-%.2x-%.2x",*(undefined1 *)(lVar2 + 0x26),

                *(undefined1 *)(lVar2 + 0x27),*(undefined1 *)(lVar2 + 0x28),

                *(undefined1 *)(lVar2 + 0x29),*(undefined1 *)(lVar2 + 0x2a),

                *(undefined1 *)(lVar2 + 0x2b));

  FUN_140208490(param_1,local_28);

  return;

}




