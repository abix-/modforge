// Address: 0x14022bad0
// Ghidra name: FUN_14022bad0
// ============ 0x14022bad0 FUN_14022bad0 (size=70) ============


longlong FUN_14022bad0(longlong param_1,char param_2)



{

  uint uVar1;

  char cVar2;

  longlong lVar3;

  longlong lVar4;

  

  uVar1 = *(uint *)(param_1 + 0x48);

  lVar3 = param_1;

  while ((uVar1 & 0xc0000) != 0) {

    lVar3 = *(longlong *)(lVar3 + 0x1a8);

    uVar1 = *(uint *)(lVar3 + 0x48);

  }

  *(longlong *)(lVar3 + 400) = param_1;

  if (((param_2 == '\0') || (*(char *)(param_1 + 0x109) != '\0')) ||

     (*(char *)(param_1 + 0x10f) != '\0')) {

    return lVar3;

  }

  lVar3 = FUN_14016dcf0();

  lVar4 = FUN_1401611a0();

  if ((param_1 != 0) &&

     (((DAT_1403e3d60 != '\0' && (cVar2 = FUN_1401aa7c0(param_1,1), cVar2 == '\0')) ||

      (*(char *)(param_1 + 0x10f) != '\0')))) {

    lVar3 = FUN_14012e850("Invalid window");

    return lVar3;

  }

  if (DAT_1403fc6e0 != 0) {

    if (param_1 == 0) {

      FUN_1401837c0();

    }

    if (DAT_1403fc6e0 != 0) {

      if (DAT_1403fc6e0 != param_1) {

        FUN_1401cda90(DAT_1403fc6e0,0x20f,0,0);

        cVar2 = FUN_140172fc0(DAT_1403fc6e0);

        if (((cVar2 != '\0') && (lVar3 != 0)) && (*(code **)(lVar3 + 0x268) != (code *)0x0)) {

          (**(code **)(lVar3 + 0x268))(lVar3,DAT_1403fc6e0);

        }

      }

      if ((((DAT_1403fc6e0 != 0) && (param_1 == 0)) && (*(char *)(lVar4 + 0xc1) != '\0')) &&

         (FUN_140162d10(0), (*(byte *)(DAT_1403fc6e0 + 0x48) & 0x40) != 0)) {

        FUN_140163140((float)*(int *)(DAT_1403fc6e0 + 0x18) + *(float *)(lVar4 + 0x90),

                      (float)*(int *)(DAT_1403fc6e0 + 0x1c) + *(float *)(lVar4 + 0x94));

        DAT_1403fc6e0 = param_1;

        goto LAB_140183ef2;

      }

    }

  }

  DAT_1403fc6e0 = param_1;

  if (param_1 != 0) {

    FUN_1401cda90(param_1,0x20e,0,0);

    cVar2 = FUN_140172fc0(DAT_1403fc6e0);

    if (((cVar2 != '\0') && (lVar3 != 0)) && (*(code **)(lVar3 + 0x260) != (code *)0x0)) {

      (**(code **)(lVar3 + 0x260))(lVar3,DAT_1403fc6e0,*(undefined4 *)(DAT_1403fc6e0 + 0x134));

    }

  }

LAB_140183ef2:

  FUN_1401630f0();

  return 1;

}




