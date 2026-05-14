// Address: 0x14014f910
// Ghidra name: FUN_14014f910
// ============ 0x14014f910 FUN_14014f910 (size=312) ============


ulonglong FUN_14014f910(longlong param_1,undefined8 *param_2,undefined8 param_3,undefined8 param_4)



{

  longlong lVar1;

  char cVar2;

  ulonglong uVar3;

  undefined8 local_18;

  undefined4 local_10;

  undefined4 local_c;

  

  if ((param_1 == 0) ||

     ((DAT_1403e3d60 != '\0' && (cVar2 = FUN_1401aa7c0(param_1,3), cVar2 == '\0')))) {

    uVar3 = FUN_14012e850("Parameter \'%s\' is invalid","texture");

    uVar3 = uVar3 & 0xffffffffffffff00;

  }

  else if (*(int *)(param_1 + 0x24) == 1) {

    if (param_2 == (undefined8 *)0x0) {

      param_2 = &local_18;

      local_18 = 0;

      local_10 = *(undefined4 *)(param_1 + 4);

      local_c = *(undefined4 *)(param_1 + 8);

    }

    if (*(longlong *)(param_1 + 0x100) == 0) {

      if (*(longlong *)(param_1 + 0xf0) != 0) {

        uVar3 = FUN_14014f740(param_1,param_2,param_3,param_4);

        return uVar3;

      }

      if (*(longlong *)(param_1 + 0xf8) != 0) {

        uVar3 = FUN_14014f6a0(param_1,param_2,param_3,param_4);

        return uVar3;

      }

      lVar1 = *(longlong *)(param_1 + 0x10);

      uVar3 = FUN_140149dc0(param_1);

      if ((char)uVar3 != '\0') {

        uVar3 = (**(code **)(lVar1 + 0xa8))(lVar1,param_1,param_2,param_3,param_4);

        return uVar3;

      }

    }

    else {

      uVar3 = FUN_140149dc0(param_1);

      if ((char)uVar3 != '\0') {

        uVar3 = FUN_14014f900(param_1,param_2,param_3,param_4);

        return uVar3;

      }

    }

    uVar3 = uVar3 & 0xffffffffffffff00;

  }

  else {

    uVar3 = FUN_14012e850("SDL_LockTexture(): texture must be streaming");

  }

  return uVar3;

}




