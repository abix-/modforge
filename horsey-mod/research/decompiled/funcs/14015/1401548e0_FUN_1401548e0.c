// Address: 0x1401548e0
// Ghidra name: FUN_1401548e0
// ============ 0x1401548e0 FUN_1401548e0 (size=164) ============


undefined8 FUN_1401548e0(longlong param_1,undefined4 param_2,undefined4 param_3,int param_4)



{

  longlong lVar1;

  char cVar2;

  undefined4 uVar3;

  undefined4 uVar4;

  

  if ((param_1 == 0) ||

     ((DAT_1403e3d60 != '\0' && (cVar2 = FUN_1401aa7c0(param_1,2), cVar2 == '\0')))) {

    FUN_14012e850("Parameter \'%s\' is invalid","renderer");

  }

  else {

    if (*(char *)(param_1 + 0x2d8) == '\0') {

      lVar1 = *(longlong *)(param_1 + 0x138);

      uVar4 = 0;

      if (param_4 != 0) {

        uVar4 = param_3;

      }

      uVar3 = 0;

      if (param_4 != 0) {

        uVar3 = param_2;

      }

      *(undefined4 *)(lVar1 + 0x58) = uVar3;

      *(undefined4 *)(lVar1 + 0x5c) = uVar4;

      *(int *)(lVar1 + 0x54) = param_4;

      FUN_140156960(param_1);

      return 1;

    }

    FUN_14012e850("Renderer\'s window has been destroyed, can\'t use further");

  }

  return 0;

}




