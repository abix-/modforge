// Address: 0x1401871e0
// Ghidra name: FUN_1401871e0
// ============ 0x1401871e0 FUN_1401871e0 (size=489) ============


undefined8 FUN_1401871e0(longlong *param_1,longlong param_2)



{

  int iVar1;

  char cVar2;

  undefined1 uVar3;

  uint uVar4;

  undefined8 uVar5;

  longlong lVar6;

  uint uVar7;

  char *pcVar8;

  bool bVar9;

  

  *param_1 = param_2;

  param_1[1] = 0;

  *(undefined2 *)(param_1 + 2) = 0;

  cVar2 = FUN_1401489c0(param_2);

  if (cVar2 == '\0') {

    uVar5 = FUN_14012e850("Parameter \'%s\' is invalid","surface");

    return uVar5;

  }

  uVar7 = *(uint *)(param_2 + 4);

  if ((((uVar7 != 0) && ((uVar7 & 0xf0000000) == 0x10000000)) && (0x7ff < (uVar7 & 0xff00))) &&

     (((((uVar7 & 0xf000000) == 0x4000000 || (((uVar7 & 0xf000000) + 0xfb000000 & 0xfeffffff) == 0))

       && (((uVar4 = uVar7 & 0xf00000, uVar4 == 0x300000 ||

            ((uVar4 == 0x400000 || (uVar4 == 0x700000)))) || (uVar4 == 0x800000)))) ||

      (((((uVar7 & 0xf000000) == 0x7000000 || (((uVar7 & 0xf000000) + 0xf8000000 & 0xfcffffff) == 0)

         ) && ((uVar7 = uVar7 & 0xf00000, uVar7 == 0x300000 ||

               (((uVar7 == 0x200000 || (uVar7 == 0x600000)) || (uVar7 == 0x500000)))))) ||

       ((*(uint *)(param_2 + 0x108) & 0x400) != 0)))))) {

    *(undefined1 *)(param_1 + 2) = 1;

  }

  if ((*(longlong *)(param_2 + 0x48) != 0) && ((char)param_1[2] == '\0')) {

    iVar1 = *(int *)(param_2 + 4);

    if ((iVar1 == 0) || ((iVar1 >> 0x1c & 0xfU) != 1)) {

      uVar7 = 0;

      pcVar8 = "%u bpp BMP files not supported";

      goto LAB_140187371;

    }

    if ((char)((uint)iVar1 >> 8) != '\b') {

      uVar7 = iVar1 >> 8 & 0xff;

      pcVar8 = "%u bpp BMP files not supported";

      goto LAB_140187371;

    }

LAB_14018739c:

    param_1[1] = param_2;

    goto LAB_1401873a0;

  }

  if (*(int *)(param_2 + 4) == 0x17401803) {

    if ((char)param_1[2] == '\0') goto LAB_14018739c;

LAB_140187349:

    bVar9 = (char)param_1[2] == '\0';

  }

  else {

    if (*(int *)(param_2 + 4) != 0x16362004) goto LAB_140187349;

    bVar9 = (char)param_1[2] == '\0';

    if (!bVar9) goto LAB_14018739c;

  }

  uVar7 = 0x16362004;

  if (bVar9) {

    uVar7 = 0x17401803;

  }

  lVar6 = FUN_140145bb0(param_2,uVar7);

  param_1[1] = lVar6;

  if (lVar6 == 0) {

    pcVar8 = "Couldn\'t convert image to %d bpp";

    uVar7 = uVar7 >> 8 & 0xff;

LAB_140187371:

    FUN_14012e850(pcVar8,uVar7);

    FUN_1401871c0(param_1);

    return 0;

  }

LAB_1401873a0:

  if ((char)param_1[2] != '\0') {

    uVar3 = FUN_140142940("SDL_BMP_SAVE_LEGACY_FORMAT",0);

    *(undefined1 *)((longlong)param_1 + 0x11) = uVar3;

  }

  return 1;

}




