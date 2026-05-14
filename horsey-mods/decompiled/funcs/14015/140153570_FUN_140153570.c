// Address: 0x140153570
// Ghidra name: FUN_140153570
// ============ 0x140153570 FUN_140153570 (size=361) ============


undefined8 FUN_140153570(longlong param_1,longlong param_2,longlong param_3,undefined1 *param_4)



{

  char cVar1;

  undefined8 uVar2;

  char *pcVar3;

  undefined8 local_28;

  float local_20;

  float local_1c;

  undefined1 local_18 [16];

  

  if ((param_1 == 0) ||

     ((DAT_1403e3d60 != '\0' && (cVar1 = FUN_1401aa7c0(param_1,2), cVar1 == '\0')))) {

    pcVar3 = "renderer";

  }

  else {

    if (*(char *)(param_1 + 0x2d8) != '\0') {

      FUN_14012e850("Renderer\'s window has been destroyed, can\'t use further");

      return 0;

    }

    if ((param_2 != 0) &&

       ((DAT_1403e3d60 == '\0' || (cVar1 = FUN_1401aa7c0(param_2,3), cVar1 != '\0')))) {

      if (param_1 != *(longlong *)(param_2 + 0x10)) {

        uVar2 = FUN_14012e850("Texture was not created with this renderer");

        return uVar2;

      }

      local_28 = 0;

      local_20 = (float)*(int *)(param_2 + 4);

      local_1c = (float)*(int *)(param_2 + 8);

      if ((param_3 != 0) && (cVar1 = FUN_140185680(param_3,&local_28,&local_28), cVar1 == '\0')) {

        return 1;

      }

      if (param_4 == (undefined1 *)0x0) {

        FUN_14014a2f0(param_1,local_18);

        param_4 = local_18;

      }

      cVar1 = FUN_140156f30(param_2);

      if (cVar1 == '\0') {

        return 0;

      }

      if (*(longlong *)(param_2 + 0xf8) != 0) {

        param_2 = *(longlong *)(param_2 + 0xf8);

      }

      *(undefined4 *)(param_2 + 0x130) = *(undefined4 *)(param_1 + 600);

      uVar2 = FUN_1401527c0(param_1,param_2,&local_28,param_4);

      return uVar2;

    }

    pcVar3 = "texture";

  }

  FUN_14012e850("Parameter \'%s\' is invalid",pcVar3);

  return 0;

}




