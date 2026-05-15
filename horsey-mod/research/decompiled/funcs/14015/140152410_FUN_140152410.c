// Address: 0x140152410
// Ghidra name: FUN_140152410
// ============ 0x140152410 FUN_140152410 (size=944) ============


undefined8

FUN_140152410(longlong param_1,longlong param_2,longlong param_3,float *param_4,float *param_5,

             float *param_6)



{

  char cVar1;

  undefined8 uVar2;

  char *pcVar3;

  undefined8 local_c8;

  float local_c0;

  float local_bc;

  float local_b8;

  float local_b4;

  float local_b0;

  float local_ac;

  float local_a8;

  float local_a4;

  float local_a0;

  float local_9c;

  float local_98;

  float local_94;

  float local_90;

  float local_8c;

  float local_88;

  float local_84;

  float local_80;

  float local_7c;

  float local_78;

  float local_74;

  float local_70;

  float local_6c;

  

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

      if ((*(longlong *)(param_1 + 0x50) == 0) && (*(longlong *)(param_1 + 0x58) == 0)) {

        uVar2 = FUN_14012e850("Renderer does not support RenderCopyEx");

        return uVar2;

      }

      local_c8 = 0;

      local_c0 = (float)*(int *)(param_2 + 4);

      local_bc = (float)*(int *)(param_2 + 8);

      if ((param_3 != 0) && (cVar1 = FUN_140185680(param_3,&local_c8,&local_c8), cVar1 == '\0')) {

        return 1;

      }

      FUN_14014a2f0(param_1,&local_b8);

      cVar1 = FUN_140156f30(param_2);

      if (cVar1 == '\0') {

        return 0;

      }

      if (*(longlong *)(param_2 + 0xf8) != 0) {

        param_2 = *(longlong *)(param_2 + 0xf8);

      }

      *(undefined4 *)(param_2 + 0x130) = *(undefined4 *)(param_1 + 600);

      local_88 = (float)local_c8 / (float)*(int *)(param_2 + 4);

      local_74 = (local_bc + local_c8._4_4_) / (float)*(int *)(param_2 + 8);

      local_84 = local_c8._4_4_ / (float)*(int *)(param_2 + 8);

      local_80 = (local_c0 + (float)local_c8) / (float)*(int *)(param_2 + 4);

      local_a4 = local_b4;

      local_a8 = local_b8;

      if (param_4 != (float *)0x0) {

        local_a4 = param_4[1];

        local_a8 = *param_4;

      }

      if (param_5 == (float *)0x0) {

        local_a0 = local_b0 + local_b8;

        local_9c = local_b4;

      }

      else {

        local_a0 = *param_5;

        local_9c = param_5[1];

      }

      if (param_6 == (float *)0x0) {

        local_8c = local_ac + local_b4;

        local_90 = local_b8;

      }

      else {

        local_8c = param_6[1];

        local_90 = *param_6;

      }

      if (((param_4 == (float *)0x0) && (param_5 == (float *)0x0)) && (param_6 == (float *)0x0)) {

        local_98 = local_b0 + local_b8;

        local_94 = local_ac + local_b4;

      }

      else {

        local_98 = (local_90 + local_a0) - local_a8;

        local_94 = (local_8c + local_9c) - local_a4;

      }

      local_7c = local_84;

      local_78 = local_80;

      local_70 = local_88;

      local_6c = local_74;

      uVar2 = FUN_14014ac90(param_1,param_2,&local_a8,8,param_2 + 0x30,0,&local_88,8,4,

                            &DAT_1403325d0,6,4,

                            *(undefined4 *)(*(longlong *)(param_1 + 0x138) + 0x90),

                            *(undefined4 *)(*(longlong *)(param_1 + 0x138) + 0x94),1,1);

      return uVar2;

    }

    pcVar3 = "texture";

  }

  FUN_14012e850("Parameter \'%s\' is invalid",pcVar3);

  return 0;

}




