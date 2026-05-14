// Address: 0x14017e460
// Ghidra name: FUN_14017e460
// ============ 0x14017e460 FUN_14017e460 (size=853) ============


undefined1 FUN_14017e460(uint param_1)



{

  undefined1 uVar1;

  char cVar2;

  longlong lVar3;

  undefined8 uVar4;

  uint uVar5;

  

  uVar5 = 0;

  if (DAT_1403e28e8 == '\0') {

    uVar1 = FUN_14012e850(

                         "Application didn\'t initialize properly, did you include SDL_main.h in the file containing your main() function?"

                         );

    return uVar1;

  }

  FUN_14017e340();

  if ((param_1 & 0x1200) != 0) {

    cVar2 = FUN_1401a90f0();

    if (cVar2 == '\0') goto LAB_14017e75c;

  }

  if ((param_1 >> 0xe & 1) != 0) {

    cVar2 = FUN_14017eb50(0x4000);

    if (cVar2 == '\0') {

      FUN_14017e320(0x4000);

    }

    else {

      FUN_14017e320(0x4000);

      DAT_1403fc630 = FUN_14017ffb0();

      cVar2 = FUN_14013ac00();

      if (cVar2 == '\0') {

        FUN_14017e170(0x4000);

        uVar5 = 0;

        goto LAB_14017e75c;

      }

    }

    uVar5 = 0x4000;

  }

  if ((param_1 & 0x20) == 0) {

LAB_14017e550:

    if ((param_1 & 0x10) != 0) {

      cVar2 = FUN_14017eb50(0x10);

      if (cVar2 == '\0') {

        FUN_14017e320(0x10);

      }

      else {

        cVar2 = FUN_14017e430(0x4000);

        if (cVar2 == '\0') goto LAB_14017e75c;

        FUN_14017e320(0x10);

        cVar2 = FUN_14015e770(0);

        if (cVar2 == '\0') {

          uVar4 = 0x10;

          goto LAB_14017e721;

        }

      }

      uVar5 = uVar5 | 0x10;

    }

    if ((param_1 >> 9 & 1) != 0) {

      cVar2 = FUN_14017eb50(0x200);

      if (cVar2 == '\0') {

        FUN_14017e320(0x200);

      }

      else {

        cVar2 = FUN_14017e430(0x4000);

        if (cVar2 == '\0') goto LAB_14017e75c;

        FUN_14017e320(0x200);

        cVar2 = FUN_140159250();

        if (cVar2 == '\0') {

          uVar4 = 0x200;

          goto LAB_14017e721;

        }

      }

      uVar5 = uVar5 | 0x200;

    }

    if ((param_1 >> 0xd & 1) == 0) {

LAB_14017e65b:

      if ((param_1 >> 0xc & 1) != 0) {

        cVar2 = FUN_14017eb50(0x1000);

        if (cVar2 == '\0') {

          FUN_14017e320(0x1000);

        }

        else {

          FUN_14017e320(0x1000);

          cVar2 = FUN_140176150();

          if (cVar2 == '\0') {

            FUN_14017e170(0x1000);

            goto LAB_14017e75c;

          }

        }

        uVar5 = uVar5 | 0x1000;

      }

      if ((param_1 >> 0xf & 1) != 0) {

        cVar2 = FUN_14017eb50(0x8000);

        if (cVar2 == '\0') {

          FUN_14017e320(0x8000);

        }

        else {

          FUN_14017e320(0x8000);

          cVar2 = FUN_140177360();

          if (cVar2 == '\0') {

            FUN_14017e170(0x8000);

            goto LAB_14017e75c;

          }

        }

        uVar5 = uVar5 | 0x8000;

      }

      if ((param_1 >> 0x10 & 1) == 0) {

LAB_14017e7a6:

        uVar1 = FUN_14012e710();

        return uVar1;

      }

      cVar2 = FUN_14017eb50(0x10000);

      if (cVar2 == '\0') {

        FUN_14017e320(0x10000);

        goto LAB_14017e7a6;

      }

      cVar2 = FUN_14017e430(0x4000);

      if (cVar2 == '\0') goto LAB_14017e75c;

      FUN_14017e320(0x10000);

      cVar2 = FUN_1401310c0(0);

      if (cVar2 != '\0') goto LAB_14017e7a6;

      uVar4 = 0x10000;

      goto LAB_14017e721;

    }

    cVar2 = FUN_14017eb50(0x2000);

    if (cVar2 == '\0') {

      FUN_14017e320(0x2000);

LAB_14017e657:

      uVar5 = uVar5 | 0x2000;

      goto LAB_14017e65b;

    }

    cVar2 = FUN_14017e430(0x200);

    if (cVar2 == '\0') goto LAB_14017e75c;

    FUN_14017e320(0x2000);

    cVar2 = FUN_14013f520();

    if (cVar2 != '\0') goto LAB_14017e657;

    FUN_14017e170(0x2000);

    uVar4 = FUN_14012e730();

    lVar3 = FUN_14012f0d0(uVar4);

    uVar4 = 0x200;

  }

  else {

    cVar2 = FUN_14017eb50(0x20);

    if (cVar2 == '\0') {

      FUN_14017e320(0x20);

LAB_14017e54d:

      uVar5 = uVar5 | 0x20;

      goto LAB_14017e550;

    }

    cVar2 = FUN_14017e430(0x4000);

    if (cVar2 == '\0') goto LAB_14017e75c;

    FUN_14017e320(0x20);

    DAT_1403fc638 = FUN_14017ffb0();

    cVar2 = FUN_140173a40(0);

    if (cVar2 != '\0') goto LAB_14017e54d;

    uVar4 = 0x20;

LAB_14017e721:

    FUN_14017e170(uVar4);

    uVar4 = FUN_14012e730();

    lVar3 = FUN_14012f0d0(uVar4);

    uVar4 = 0x4000;

  }

  FUN_14017e880(uVar4);

  if (lVar3 != 0) {

    FUN_14012e850(&DAT_14039bf30,lVar3);

    FUN_1401841e0(lVar3);

  }

LAB_14017e75c:

  uVar4 = FUN_14012e730();

  lVar3 = FUN_14012f0d0(uVar4);

  FUN_14017e880(uVar5);

  if (lVar3 != 0) {

    FUN_14012e850(&DAT_14039bf30,lVar3);

    FUN_1401841e0(lVar3);

  }

  return 0;

}




