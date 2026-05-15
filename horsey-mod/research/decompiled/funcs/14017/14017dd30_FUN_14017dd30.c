// Address: 0x14017dd30
// Ghidra name: FUN_14017dd30
// ============ 0x14017dd30 FUN_14017dd30 (size=674) ============


undefined8 FUN_14017dd30(byte *param_1,int *param_2,uint param_3,uint param_4)



{

  int iVar1;

  longlong lVar2;

  char cVar3;

  undefined8 uVar4;

  uint uVar5;

  code *pcVar6;

  code *pcVar7;

  ulonglong uVar8;

  int local_28;

  int local_24;

  undefined4 local_20;

  undefined4 local_1c;

  

  uVar8 = (ulonglong)param_3;

  cVar3 = FUN_1401489c0();

  if (cVar3 == '\0') {

    uVar4 = FUN_14012e850("Parameter \'%s\' is invalid","SDL_FillSurfaceRects(): dst");

    return uVar4;

  }

  if (param_2 == (int *)0x0) {

    uVar4 = FUN_14012e850("Parameter \'%s\' is invalid","SDL_FillSurfaceRects(): rects");

    return uVar4;

  }

  lVar2 = *(longlong *)(param_1 + 0x18);

  if ((lVar2 == 0) && ((*param_1 & 2) != 0)) {

    uVar4 = FUN_14012e850("SDL_FillSurfaceRects(): You must lock the surface");

    return uVar4;

  }

  if (*(int *)(param_1 + 8) == 0) {

    return 1;

  }

  iVar1 = *(int *)(param_1 + 0xc);

  if (iVar1 == 0) {

    return 1;

  }

  if (lVar2 == 0) {

    return 1;

  }

  uVar5 = *(uint *)(param_1 + 4);

  if (((uVar5 == 0) || ((uVar5 & 0xf0000000) != 0x10000000)) || ((uVar5 & 0xff00) < 0x800)) {

    if ((((param_3 == 1) && (*param_2 == 0)) &&

        ((param_2[1] == 0 && ((param_2[2] == *(int *)(param_1 + 8) && (param_2[3] == iVar1)))))) &&

       ((uVar5 != 0 && (((uVar5 & 0xf0000000) == 0x10000000 && ((uVar5 & 0xff00) == 0x400)))))) {

      FUN_1402f94c0(lVar2,(uint)(byte)((char)param_4 << 4) | param_4 & 0xff,

                    (longlong)*(int *)(param_1 + 0x10) * (longlong)iVar1);

      return 1;

    }

    uVar4 = FUN_14012e850("SDL_FillSurfaceRects(): Unsupported surface format");

    return uVar4;

  }

  uVar5 = uVar5 & 0xff;

  if (uVar5 == 1) {

    param_4 = param_4 << 8 | param_4;

    param_4 = param_4 << 0x10 | param_4;

    cVar3 = FUN_14017fed0();

    pcVar6 = FUN_14017d7a0;

    pcVar7 = FUN_14017d6b0;

  }

  else if (uVar5 == 2) {

    param_4 = param_4 | param_4 << 0x10;

    cVar3 = FUN_14017fed0();

    pcVar6 = FUN_14017d9a0;

    pcVar7 = FUN_14017d8a0;

  }

  else {

    if (uVar5 == 3) {

      pcVar7 = FUN_14017daa0;

      goto LAB_14017dea0;

    }

    if (uVar5 != 4) {

      uVar4 = FUN_14012e850("Unsupported pixel format");

      return uVar4;

    }

    cVar3 = FUN_14017fed0();

    pcVar6 = FUN_14017db80;

    pcVar7 = FUN_14017db10;

  }

  if (cVar3 != '\0') {

    pcVar7 = pcVar6;

  }

LAB_14017dea0:

  if (0 < (int)param_3) {

    do {

      cVar3 = FUN_140185790(param_2,param_1 + 100,&local_28);

      if (cVar3 != '\0') {

        uVar5 = *(uint *)(param_1 + 4);

        if ((uVar5 == 0) || ((uVar5 & 0xf0000000) == 0x10000000)) {

          uVar5 = uVar5 & 0xff;

        }

        else if ((((uVar5 == 0x32595559) || (uVar5 == 0x59565955)) || (uVar5 == 0x55595659)) ||

                (uVar5 == 0x30313050)) {

          uVar5 = 2;

        }

        else {

          uVar5 = 1;

        }

        (*pcVar7)((longlong)(*(int *)(param_1 + 0x10) * local_24) +

                  (longlong)(int)(uVar5 * local_28) + *(longlong *)(param_1 + 0x18),

                  *(int *)(param_1 + 0x10),param_4,local_20,local_1c);

      }

      param_2 = param_2 + 4;

      uVar8 = uVar8 - 1;

    } while (uVar8 != 0);

  }

  return 1;

}




