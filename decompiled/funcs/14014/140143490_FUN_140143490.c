// Address: 0x140143490
// Ghidra name: FUN_140143490
// ============ 0x140143490 FUN_140143490 (size=789) ============


undefined1 FUN_140143490(byte *param_1,byte *param_2,byte *param_3,byte *param_4,int param_5)



{

  char cVar1;

  undefined1 uVar2;

  byte *pbVar3;

  byte *pbVar4;

  int local_68;

  int iStack_64;

  int local_60;

  int local_5c;

  int local_58;

  int local_54;

  int local_50;

  int local_4c;

  undefined8 local_48;

  int iStack_40;

  int iStack_3c;

  int local_38;

  int iStack_34;

  int iStack_30;

  int iStack_2c;

  int local_28;

  int local_24;

  int local_20;

  int local_1c;

  

  cVar1 = FUN_1401489c0();

  if ((cVar1 == '\0') || ((*(longlong *)(param_1 + 0x18) == 0 && ((*param_1 & 2) == 0)))) {

    uVar2 = FUN_14012e850("Parameter \'%s\' is invalid",&DAT_1403141a4);

    return uVar2;

  }

  cVar1 = FUN_1401489c0(param_3);

  if ((cVar1 != '\0') && ((*(longlong *)(param_3 + 0x18) != 0 || ((*param_3 & 2) != 0)))) {

    if (((*param_1 & 4) != 0) || ((*param_3 & 4) != 0)) {

      uVar2 = FUN_14012e850("Surfaces must not be locked during blit");

      return uVar2;

    }

    if ((param_5 != 0) && (param_5 != 1)) {

      if (param_5 != 2) {

        uVar2 = FUN_14012e850("Parameter \'%s\' is invalid","scaleMode");

        return uVar2;

      }

      param_5 = 0;

    }

    pbVar3 = param_4;

    if (param_4 == (byte *)0x0) {

      pbVar3 = param_3;

    }

    pbVar4 = param_2;

    if (param_2 == (byte *)0x0) {

      pbVar4 = param_1;

    }

    if ((*(int *)(pbVar4 + 8) == *(int *)(pbVar3 + 8)) &&

       (*(int *)(pbVar4 + 0xc) == *(int *)(pbVar3 + 0xc))) {

      uVar2 = FUN_140144390(param_1,param_2,param_3,param_4);

      return uVar2;

    }

    iStack_40 = *(int *)(param_1 + 8);

    if ((iStack_40 != 0) && (iStack_3c = *(int *)(param_1 + 0xc), iStack_3c != 0)) {

      local_48 = 0;

      if (param_4 == (byte *)0x0) {

        local_60 = *(int *)(param_3 + 8);

        local_5c = *(int *)(param_3 + 0xc);

        local_68 = 0;

        iStack_64 = 0;

      }

      else {

        local_68 = *(int *)param_4;

        iStack_64 = *(int *)(param_4 + 4);

        local_60 = *(int *)(param_4 + 8);

        local_5c = *(int *)(param_4 + 0xc);

      }

      if (param_2 != (byte *)0x0) {

        local_58 = *(int *)param_2;

        local_54 = *(int *)(param_2 + 4);

        local_50 = 1;

        if (1 < *(int *)(param_2 + 8)) {

          local_50 = *(int *)(param_2 + 8);

        }

        local_4c = 1;

        if (1 < *(int *)(param_2 + 0xc)) {

          local_4c = *(int *)(param_2 + 0xc);

        }

        cVar1 = FUN_140185790(&local_58,&local_48,&local_38);

        if (cVar1 == '\0') {

          return 1;

        }

        local_48 = CONCAT44(iStack_34,local_38);

        iStack_40 = iStack_30;

        iStack_3c = iStack_2c;

        local_68 = local_68 + ((local_38 - local_58) * local_60) / local_50;

        iStack_64 = iStack_64 + ((iStack_34 - local_54) * local_5c) / local_4c;

        local_60 = local_60 + ((iStack_30 - local_50) * local_60) / local_50;

        local_5c = local_5c + ((iStack_2c - local_4c) * local_5c) / local_4c;

      }

      cVar1 = FUN_140185790(&local_68,param_3 + 100,&local_28);

      if (cVar1 != '\0') {

        if ((((local_28 != local_68) || (local_24 != iStack_64)) || (local_20 != local_60)) ||

           (local_1c != local_5c)) {

          uVar2 = FUN_140143380(param_1,&local_48,param_3,&local_68,param_5);

          return uVar2;

        }

        if (((*param_1 & 2) == 0) || (cVar1 = FUN_140146f20(param_1), cVar1 != '\0')) {

          if (((*param_3 & 2) == 0) || (cVar1 = FUN_140146f20(param_3), cVar1 != '\0')) {

            uVar2 = FUN_140143df0(param_1,&local_48,param_3,&local_68,param_5);

            if ((*param_1 & 2) != 0) {

              FUN_1401489e0(param_1);

            }

            if ((*param_3 & 2) != 0) {

              FUN_1401489e0(param_3);

              return uVar2;

            }

            return uVar2;

          }

          if ((*param_1 & 2) != 0) {

            FUN_1401489e0(param_1);

          }

        }

        return 0;

      }

    }

    return 1;

  }

  uVar2 = FUN_14012e850("Parameter \'%s\' is invalid",&DAT_140331e9c);

  return uVar2;

}




