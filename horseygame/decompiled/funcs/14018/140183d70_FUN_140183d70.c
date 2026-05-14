// Address: 0x140183d70
// Ghidra name: FUN_140183d70
// ============ 0x140183d70 FUN_140183d70 (size=409) ============


undefined8 FUN_140183d70(longlong param_1)



{

  char cVar1;

  longlong lVar2;

  longlong lVar3;

  undefined8 uVar4;

  

  lVar2 = FUN_14016dcf0();

  lVar3 = FUN_1401611a0();

  if ((param_1 != 0) &&

     (((DAT_1403e3d60 != '\0' && (cVar1 = FUN_1401aa7c0(param_1,1), cVar1 == '\0')) ||

      (*(char *)(param_1 + 0x10f) != '\0')))) {

    uVar4 = FUN_14012e850("Invalid window");

    return uVar4;

  }

  if (DAT_1403fc6e0 != 0) {

    if (param_1 == 0) {

      FUN_1401837c0();

    }

    if (DAT_1403fc6e0 != 0) {

      if (DAT_1403fc6e0 != param_1) {

        FUN_1401cda90(DAT_1403fc6e0,0x20f,0,0);

        cVar1 = FUN_140172fc0(DAT_1403fc6e0);

        if (((cVar1 != '\0') && (lVar2 != 0)) && (*(code **)(lVar2 + 0x268) != (code *)0x0)) {

          (**(code **)(lVar2 + 0x268))(lVar2,DAT_1403fc6e0);

        }

      }

      if (((DAT_1403fc6e0 != 0) && (param_1 == 0)) &&

         ((*(char *)(lVar3 + 0xc1) != '\0' &&

          (FUN_140162d10(0), (*(byte *)(DAT_1403fc6e0 + 0x48) & 0x40) != 0)))) {

        FUN_140163140((float)*(int *)(DAT_1403fc6e0 + 0x18) + *(float *)(lVar3 + 0x90),

                      (float)*(int *)(DAT_1403fc6e0 + 0x1c) + *(float *)(lVar3 + 0x94));

        DAT_1403fc6e0 = param_1;

        goto LAB_140183ef2;

      }

    }

  }

  DAT_1403fc6e0 = param_1;

  if (param_1 != 0) {

    FUN_1401cda90(param_1,0x20e,0,0);

    cVar1 = FUN_140172fc0(DAT_1403fc6e0);

    if (((cVar1 != '\0') && (lVar2 != 0)) && (*(code **)(lVar2 + 0x260) != (code *)0x0)) {

      (**(code **)(lVar2 + 0x260))(lVar2,DAT_1403fc6e0,*(undefined4 *)(DAT_1403fc6e0 + 0x134));

    }

  }

LAB_140183ef2:

  FUN_1401630f0();

  return 1;

}




