// Address: 0x14024af20
// Ghidra name: FUN_14024af20
// ============ 0x14024af20 FUN_14024af20 (size=514) ============


ulonglong FUN_14024af20(longlong param_1,longlong param_2,uint param_3,int param_4,byte param_5,

                       byte param_6,byte param_7,byte param_8)



{

  byte bVar1;

  longlong lVar2;

  char cVar3;

  byte bVar4;

  ulonglong uVar5;

  code *pcVar6;

  code *pcVar7;

  uint uVar8;

  bool bVar9;

  byte local_48;

  byte local_44;

  undefined1 local_40 [24];

  

  uVar5 = (ulonglong)param_3;

  bVar4 = 1;

  cVar3 = FUN_1401489c0();

  if (cVar3 == '\0') {

    uVar5 = FUN_14012e850("Parameter \'%s\' is invalid","SDL_BlendFillRects(): dst");

    return uVar5;

  }

  lVar2 = *(longlong *)(param_1 + 0x38);

  bVar1 = *(byte *)(lVar2 + 4);

  if (bVar1 < 8) {

    uVar5 = FUN_14012e850("SDL_BlendFillRects(): Unsupported surface format");

    return uVar5;

  }

  if (param_4 - 1U < 2) {

    uVar8 = ((uint)param_5 * (uint)param_8) / 0xff;

    local_44 = (byte)(((uint)param_6 * (uint)param_8) / 0xff);

    local_48 = (byte)(((uint)param_7 * (uint)param_8) / 0xff);

  }

  else {

    uVar8 = (uint)param_5;

    local_48 = param_7;

    local_44 = param_6;

  }

  if (bVar1 == 0xf) {

    if (*(int *)(lVar2 + 8) == 0x7c00) {

      pcVar7 = FUN_140245b20;

      goto LAB_14024b083;

    }

  }

  else {

    if (bVar1 == 0x10) {

      pcVar6 = (code *)0x0;

      pcVar7 = FUN_140246d40;

      bVar9 = *(int *)(lVar2 + 8) == 0xf800;

    }

    else {

      if ((bVar1 != 0x20) || (*(int *)(lVar2 + 8) != 0xff0000)) goto LAB_14024b06c;

      bVar9 = *(int *)(lVar2 + 0x14) == 0;

      pcVar7 = FUN_14024a1b0;

      pcVar6 = FUN_140241550;

    }

    if (!bVar9) {

      pcVar7 = pcVar6;

    }

    if (pcVar7 != (code *)0x0) goto LAB_14024b083;

  }

LAB_14024b06c:

  pcVar7 = FUN_140247f90;

  if (*(int *)(lVar2 + 0x14) == 0) {

    pcVar7 = FUN_140242480;

  }

LAB_14024b083:

  if (0 < (int)param_3) {

    do {

      cVar3 = FUN_140185790(param_2,param_1 + 100,local_40);

      if (cVar3 != '\0') {

        bVar4 = (*pcVar7)(param_1,local_40,param_4,uVar8 & 0xff,local_44,local_48,param_8);

      }

      param_2 = param_2 + 0x10;

      uVar5 = uVar5 - 1;

    } while (uVar5 != 0);

  }

  return (ulonglong)bVar4;

}




