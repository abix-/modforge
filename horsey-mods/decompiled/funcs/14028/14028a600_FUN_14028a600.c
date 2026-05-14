// Address: 0x14028a600
// Ghidra name: FUN_14028a600
// ============ 0x14028a600 FUN_14028a600 (size=532) ============


short * FUN_14028a600(undefined8 param_1)



{

  char cVar1;

  undefined1 uVar2;

  short sVar3;

  short sVar4;

  int iVar5;

  undefined4 uVar6;

  short *psVar7;

  longlong lVar8;

  undefined8 uVar9;

  undefined8 in_stack_ffffffffffffffe8;

  undefined4 uVar10;

  

  uVar10 = (undefined4)((ulonglong)in_stack_ffffffffffffffe8 >> 0x20);

  cVar1 = FUN_14028a5a0();

  if (cVar1 == '\0') {

    FUN_14012e850("Device not supported by the lg4ff hidapi haptic driver");

    return (short *)0x0;

  }

  psVar7 = (short *)FUN_1401841f0(0xb90);

  if (psVar7 == (short *)0x0) {

    FUN_14012e770();

    return (short *)0x0;

  }

  FUN_1402f94c0(psVar7,0,0xa68);

  FUN_1402f94c0(psVar7 + 0x538,0,0x120);

  *(undefined8 *)(psVar7 + 0x534) = param_1;

  iVar5 = FUN_14028b390(psVar7);

  if (iVar5 == 0) {

    lVar8 = FUN_140179a30();

    *(longlong *)(psVar7 + 0x5c0) = lVar8;

    if (lVar8 != 0) {

      uVar6 = FUN_14027fa20("SDL_HAPTIC_LG4FF_SPRING",0,100,0x1e);

      *(undefined4 *)(psVar7 + 0x52a) = uVar6;

      uVar6 = FUN_14027fa20("SDL_HAPTIC_LG4FF_DAMPER",0,100,0x1e);

      *(undefined4 *)(psVar7 + 0x52c) = uVar6;

      uVar6 = FUN_14027fa20("SDL_HAPTIC_LG4FF_FRICTION",0,100,0x1e);

      *(undefined4 *)(psVar7 + 0x52e) = uVar6;

      uVar6 = FUN_14027fa20("SDL_HAPTIC_LG4FF_GAIN",0,0xffff);

      *(undefined4 *)(psVar7 + 0x526) = uVar6;

      psVar7[0x528] = -1;

      psVar7[0x529] = 0;

      sVar3 = FUN_140158b60(param_1);

      *psVar7 = sVar3;

      sVar4 = FUN_140158b20(param_1);

      sVar3 = *psVar7;

      psVar7[1] = sVar4;

      uVar6 = FUN_140158720(param_1);

      FUN_14012ef10(psVar7 + 0x540,0x100,"SDL_hidapihaptic_lg4ff %d %04x:%04x",uVar6,

                    CONCAT44(uVar10,0x46d),sVar3);

      *(undefined1 *)(psVar7 + 0x538) = 0;

      uVar9 = FUN_140163260(FUN_14028ae80,psVar7 + 0x540,psVar7,FUN_1402cfa08,FUN_1402cfae8);

      *(undefined8 *)(psVar7 + 0x53c) = uVar9;

      if (((*psVar7 == -0x3d6c) && ((psVar7[1] & 0xff00U) == 0x2100)) && ((char)psVar7[1] == '\0'))

      {

        uVar2 = 1;

      }

      else {

        uVar2 = 0;

      }

      *(undefined1 *)(psVar7 + 0x5c4) = uVar2;

      return psVar7;

    }

  }

  else {

    FUN_14012e850("lg4ff hidapi driver failed initializing effect slots");

  }

  FUN_1401841e0(psVar7);

  return (short *)0x0;

}




