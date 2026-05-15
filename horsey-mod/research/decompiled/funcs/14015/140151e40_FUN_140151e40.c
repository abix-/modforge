// Address: 0x140151e40
// Ghidra name: FUN_140151e40
// ============ 0x140151e40 FUN_140151e40 (size=1478) ============


undefined1

FUN_140151e40(longlong param_1,longlong param_2,float *param_3,float param_4,float param_5,

             float param_6,float param_7,undefined8 param_8,float *param_9)



{

  char cVar1;

  undefined1 uVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float local_c8;

  float local_c4;

  float local_c0;

  float local_bc;

  float local_b8;

  float local_b4;

  float local_b0;

  float local_ac;

  undefined8 local_a8;

  float local_a0;

  float local_9c;

  float local_98 [36];

  

  if ((param_1 == 0) ||

     ((DAT_1403e3d60 != '\0' && (cVar1 = FUN_1401aa7c0(param_1,2), cVar1 == '\0')))) {

    FUN_14012e850("Parameter \'%s\' is invalid","renderer");

    uVar2 = 0;

  }

  else if (*(char *)(param_1 + 0x2d8) == '\0') {

    if ((param_2 == 0) ||

       ((DAT_1403e3d60 != '\0' && (cVar1 = FUN_1401aa7c0(param_2,3), cVar1 == '\0')))) {

      FUN_14012e850("Parameter \'%s\' is invalid","texture");

      uVar2 = 0;

    }

    else if (param_1 == *(longlong *)(param_2 + 0x10)) {

      if (param_3 == (float *)0x0) {

        local_a0 = (float)*(int *)(param_2 + 4);

        param_3 = (float *)&local_a8;

        local_9c = (float)*(int *)(param_2 + 8);

        local_a8 = 0;

      }

      if (param_9 == (float *)0x0) {

        FUN_14014a2f0(param_1,local_98);

        param_9 = local_98;

      }

      fVar3 = (float)thunk_FUN_1402e33f0();

      fVar4 = (float)thunk_FUN_1402e33f0();

      fVar5 = (float)thunk_FUN_1402e33f0();

      fVar6 = (float)thunk_FUN_1402e33f0();

      local_b8 = param_4 + *param_3;

      local_ac = (param_3[3] - param_6) - param_7;

      local_b4 = param_6 + param_3[1];

      local_c8 = fVar3 + *param_9;

      local_c4 = fVar5 + param_9[1];

      local_b0 = (param_3[2] - param_4) - param_5;

      local_c0 = (param_9[2] - fVar3) - fVar4;

      local_bc = (param_9[3] - fVar5) - fVar6;

      cVar1 = FUN_140153570(param_1,param_2,&local_b8,&local_c8);

      if (cVar1 != '\0') {

        local_b8 = *param_3;

        local_b4 = param_3[1];

        local_c8 = *param_9;

        local_c4 = param_9[1];

        local_ac = param_6;

        local_c0 = fVar3;

        local_bc = fVar5;

        local_b0 = param_4;

        cVar1 = FUN_140153570(param_1,param_2,&local_b8,&local_c8);

        if (cVar1 != '\0') {

          local_b0 = param_5;

          local_b8 = (*param_3 + param_3[2]) - param_5;

          local_c8 = (param_9[2] + *param_9) - fVar4;

          local_c0 = fVar4;

          cVar1 = FUN_140153570(param_1,param_2,&local_b8,&local_c8);

          if (cVar1 != '\0') {

            local_ac = param_7;

            local_b4 = (param_3[3] + param_3[1]) - param_7;

            local_c4 = (param_9[3] + param_9[1]) - fVar6;

            local_bc = fVar6;

            cVar1 = FUN_140153570(param_1,param_2,&local_b8,&local_c8);

            if (cVar1 != '\0') {

              local_b8 = *param_3;

              local_c8 = *param_9;

              local_c0 = fVar3;

              local_b0 = param_4;

              cVar1 = FUN_140153570(param_1,param_2,&local_b8,&local_c8);

              if (cVar1 != '\0') {

                local_b4 = param_6 + param_3[1];

                local_ac = (param_3[3] - param_6) - param_7;

                local_c4 = fVar5 + param_9[1];

                local_bc = (param_9[3] - fVar5) - fVar6;

                cVar1 = FUN_140153570(param_1,param_2,&local_b8,&local_c8);

                if (cVar1 != '\0') {

                  local_b0 = param_5;

                  local_b8 = (*param_3 + param_3[2]) - param_5;

                  local_c8 = (param_9[2] + *param_9) - fVar4;

                  local_c0 = fVar4;

                  cVar1 = FUN_140153570(param_1,param_2,&local_b8,&local_c8);

                  if (cVar1 != '\0') {

                    local_ac = param_6;

                    local_b8 = param_4 + *param_3;

                    local_b0 = (param_3[2] - param_4) - param_5;

                    local_b4 = param_3[1];

                    local_c8 = fVar3 + *param_9;

                    local_c4 = param_9[1];

                    local_c0 = (param_9[2] - fVar3) - fVar4;

                    local_bc = fVar5;

                    cVar1 = FUN_140153570(param_1,param_2,&local_b8,&local_c8);

                    if (cVar1 != '\0') {

                      local_ac = param_7;

                      local_b4 = (param_3[3] + param_3[1]) - param_7;

                      local_c4 = (param_9[3] + param_9[1]) - fVar6;

                      local_bc = fVar6;

                      cVar1 = FUN_140153570(param_1,param_2,&local_b8,&local_c8);

                      return cVar1 != '\0';

                    }

                  }

                }

              }

            }

          }

        }

      }

      uVar2 = 0;

    }

    else {

      uVar2 = FUN_14012e850("Texture was not created with this renderer");

    }

  }

  else {

    FUN_14012e850("Renderer\'s window has been destroyed, can\'t use further");

    uVar2 = 0;

  }

  return uVar2;

}




