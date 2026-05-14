// Address: 0x140154990
// Ghidra name: FUN_140154990
// ============ 0x140154990 FUN_140154990 (size=285) ============


byte FUN_140154990(longlong param_1,float param_2,float param_3)



{

  longlong lVar1;

  char cVar2;

  byte bVar3;

  byte bVar4;

  

  if ((param_1 != 0) &&

     ((DAT_1403e3d60 == '\0' || (cVar2 = FUN_1401aa7c0(param_1,2), cVar2 != '\0')))) {

    if (*(char *)(param_1 + 0x2d8) == '\0') {

      lVar1 = *(longlong *)(param_1 + 0x138);

      if ((*(float *)(lVar1 + 0x4c) == param_2) && (*(float *)(lVar1 + 0x50) == param_3)) {

        bVar3 = 1;

      }

      else {

        *(float *)(lVar1 + 0x4c) = param_2;

        *(float *)(lVar1 + 0x50) = param_3;

        *(float *)(lVar1 + 0x90) = param_2 * *(float *)(lVar1 + 0x80);

        *(float *)(lVar1 + 0x94) = param_3 * *(float *)(lVar1 + 0x84);

        FUN_140156e80(param_1,lVar1);

        FUN_140156de0(param_1,lVar1);

        bVar3 = FUN_14014af50(param_1);

        bVar4 = FUN_14014adb0(param_1);

        bVar3 = bVar4 & bVar3 & 1;

      }

      return bVar3;

    }

    FUN_14012e850("Renderer\'s window has been destroyed, can\'t use further");

    return 0;

  }

  FUN_14012e850("Parameter \'%s\' is invalid","renderer");

  return 0;

}




