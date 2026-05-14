// Address: 0x140142f50
// Ghidra name: FUN_140142f50
// ============ 0x140142f50 FUN_140142f50 (size=1063) ============


undefined1

FUN_140142f50(longlong param_1,int *param_2,int param_3,int param_4,int param_5,int param_6,

             float param_7,undefined4 param_8,longlong param_9,int *param_10)



{

  char cVar1;

  undefined1 uVar2;

  int iVar3;

  float fVar4;

  int local_88;

  int local_84;

  int local_80;

  int local_78;

  int local_74;

  int local_70;

  int local_6c;

  int local_68;

  int local_64;

  int local_60;

  int local_5c;

  int local_58 [3];

  undefined4 local_4c;

  int local_48 [3];

  undefined4 local_3c;

  

  cVar1 = FUN_1401489c0();

  if (cVar1 == '\0') {

    uVar2 = FUN_14012e850("Parameter \'%s\' is invalid",&DAT_1403141a4);

    return uVar2;

  }

  cVar1 = FUN_1401489c0();

  if (cVar1 == '\0') {

    uVar2 = FUN_14012e850("Parameter \'%s\' is invalid",&DAT_140331e9c);

  }

  else {

    if (param_2 == (int *)0x0) {

      param_2 = local_58;

      local_58[2] = *(undefined4 *)(param_1 + 8);

      local_4c = *(undefined4 *)(param_1 + 0xc);

      local_58[0] = 0;

      local_58[1] = 0;

    }

    if (param_10 == (int *)0x0) {

      param_10 = local_48;

      local_48[2] = *(undefined4 *)(param_9 + 8);

      local_3c = *(undefined4 *)(param_9 + 0xc);

      local_48[0] = 0;

      local_48[1] = 0;

    }

    if ((param_7 <= 0.0) || (param_7 == DAT_14039ca44)) {

      local_84 = param_5;

      iVar3 = param_6;

      local_88 = param_3;

      local_80 = param_4;

    }

    else {

      fVar4 = (float)thunk_FUN_1402e1d00((float)param_3 * param_7);

      local_88 = (int)fVar4;

      fVar4 = (float)thunk_FUN_1402e1d00((float)param_4 * param_7);

      local_80 = (int)fVar4;

      fVar4 = (float)thunk_FUN_1402e1d00((float)param_5 * param_7);

      local_84 = (int)fVar4;

      fVar4 = (float)thunk_FUN_1402e1d00((float)param_6 * param_7);

      iVar3 = (int)fVar4;

    }

    local_68 = *param_2;

    local_64 = param_2[1];

    local_78 = *param_10;

    local_74 = param_10[1];

    local_70 = local_88;

    local_6c = local_84;

    local_5c = param_5;

    local_60 = param_3;

    cVar1 = FUN_140143490(param_1,&local_68,param_9,&local_78,param_8);

    if (cVar1 != '\0') {

      local_70 = local_80;

      local_68 = (param_2[2] - param_4) + *param_2;

      local_78 = (param_10[2] - local_80) + *param_10;

      local_60 = param_4;

      cVar1 = FUN_140143490(param_1,&local_68,param_9,&local_78,param_8);

      if (cVar1 != '\0') {

        local_64 = (param_2[1] - param_6) + param_2[3];

        local_74 = (param_10[3] - iVar3) + param_10[1];

        local_6c = iVar3;

        cVar1 = FUN_140143490(param_1,&local_68,param_9,&local_78,param_8);

        if (cVar1 != '\0') {

          local_68 = *param_2;

          local_78 = *param_10;

          local_70 = local_88;

          local_60 = param_3;

          cVar1 = FUN_140143490(param_1,&local_68,param_9,&local_78,param_8);

          if (cVar1 != '\0') {

            local_5c = (param_2[3] - param_5) - param_6;

            local_64 = param_2[1] + param_5;

            local_6c = (param_10[3] - iVar3) - local_84;

            local_74 = param_10[1] + local_84;

            cVar1 = FUN_140143490(param_1,&local_68,param_9,&local_78,param_8);

            if (cVar1 != '\0') {

              local_70 = local_80;

              local_68 = (param_2[2] - param_4) + *param_2;

              local_78 = (param_10[2] - local_80) + *param_10;

              local_60 = param_4;

              cVar1 = FUN_140143490(param_1,&local_68,param_9,&local_78,param_8);

              if (cVar1 != '\0') {

                local_64 = param_2[1];

                local_68 = *param_2 + param_3;

                local_60 = (param_2[2] - param_3) - param_4;

                local_78 = *param_10 + local_88;

                local_74 = param_10[1];

                local_70 = (param_10[2] - local_80) - local_88;

                local_6c = local_84;

                local_5c = param_5;

                cVar1 = FUN_140143490(param_1,&local_68,param_9,&local_78,param_8);

                if (cVar1 != '\0') {

                  local_64 = (param_2[3] - param_6) + param_2[1];

                  local_74 = (param_10[3] - iVar3) + param_10[1];

                  local_6c = iVar3;

                  cVar1 = FUN_140143490(param_1,&local_68,param_9,&local_78,param_8);

                  if (cVar1 != '\0') {

                    local_68 = *param_2 + param_3;

                    local_60 = (param_2[2] - param_3) - param_4;

                    local_64 = param_2[1] + param_5;

                    local_5c = (param_2[3] - param_5) - param_6;

                    local_78 = *param_10 + local_88;

                    local_70 = (param_10[2] - local_80) - local_88;

                    local_6c = (param_10[3] - iVar3) - local_84;

                    local_74 = param_10[1] + local_84;

                    cVar1 = FUN_140143490(param_1,&local_68,param_9,&local_78,param_8);

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

  return uVar2;

}




