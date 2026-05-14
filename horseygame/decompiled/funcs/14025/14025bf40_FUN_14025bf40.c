// Address: 0x14025bf40
// Ghidra name: FUN_14025bf40
// ============ 0x14025bf40 FUN_14025bf40 (size=540) ============


undefined8

FUN_14025bf40(longlong param_1,int param_2,int param_3,int param_4,byte param_5,byte param_6,

             byte param_7,byte param_8)



{

  uint uVar1;

  longlong lVar2;

  char cVar3;

  undefined8 uVar4;

  

  cVar3 = FUN_1401489c0();

  if (cVar3 == '\0') {

    uVar4 = FUN_14012e850("Parameter \'%s\' is invalid","SDL_BlendPoint(): dst");

  }

  else {

    uVar1 = *(uint *)(param_1 + 4);

    if (((uVar1 == 0) || ((uVar1 & 0xf0000000) != 0x10000000)) || ((uVar1 & 0xff00) < 0x800)) {

      uVar4 = FUN_14012e850("SDL_BlendPoint(): Unsupported surface format");

    }

    else if (((param_2 < *(int *)(param_1 + 100)) || (param_3 < *(int *)(param_1 + 0x68))) ||

            ((*(int *)(param_1 + 100) + *(int *)(param_1 + 0x6c) <= param_2 ||

             (*(int *)(param_1 + 0x70) + *(int *)(param_1 + 0x68) <= param_3)))) {

      uVar4 = 0x10000001;

    }

    else {

      if (param_4 - 1U < 2) {

        param_5 = (byte)(((uint)param_5 * (uint)param_8) / 0xff);

        param_6 = (byte)(((uint)param_6 * (uint)param_8) / 0xff);

        param_7 = (byte)(((uint)param_7 * (uint)param_8) / 0xff);

      }

      lVar2 = *(longlong *)(param_1 + 0x38);

      cVar3 = *(char *)(lVar2 + 4);

      if (cVar3 == '\x0f') {

        if (*(int *)(lVar2 + 8) == 0x7c00) {

          uVar4 = FUN_14025d330(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);

          return uVar4;

        }

      }

      else if (cVar3 == '\x10') {

        if (*(int *)(lVar2 + 8) == 0xf800) {

          uVar4 = FUN_14025d820(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);

          return uVar4;

        }

      }

      else if ((cVar3 == ' ') && (*(int *)(lVar2 + 8) == 0xff0000)) {

        if (*(int *)(lVar2 + 0x14) == 0) {

          uVar4 = FUN_14025e610();

          return uVar4;

        }

        uVar4 = FUN_14025c160(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);

        return uVar4;

      }

      if (*(int *)(lVar2 + 0x14) == 0) {

        uVar4 = FUN_14025c580();

      }

      else {

        uVar4 = FUN_14025dd40(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);

      }

    }

  }

  return uVar4;

}




