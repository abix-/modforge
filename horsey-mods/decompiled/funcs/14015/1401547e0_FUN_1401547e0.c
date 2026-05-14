// Address: 0x1401547e0
// Ghidra name: FUN_1401547e0
// ============ 0x1401547e0 FUN_1401547e0 (size=175) ============


undefined1

FUN_1401547e0(longlong param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,

             undefined4 param_5)



{

  char cVar1;

  

  if ((param_1 == 0) ||

     ((DAT_1403e3d60 != '\0' && (cVar1 = FUN_1401aa7c0(param_1,2), cVar1 == '\0')))) {

    FUN_14012e850("Parameter \'%s\' is invalid","renderer");

  }

  else {

    if (*(char *)(param_1 + 0x2d8) == '\0') {

      *(undefined4 *)(param_1 + 0x228) = param_5;

      *(undefined4 *)(param_1 + 0x21c) = param_2;

      *(undefined4 *)(param_1 + 0x220) = param_3;

      *(undefined4 *)(param_1 + 0x224) = param_4;

      return 1;

    }

    FUN_14012e850("Renderer\'s window has been destroyed, can\'t use further");

  }

  return 0;

}




