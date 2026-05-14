// Address: 0x140144390
// Ghidra name: FUN_140144390
// ============ 0x140144390 FUN_140144390 (size=435) ============


undefined8 FUN_140144390(byte *param_1,int *param_2,byte *param_3,int *param_4)



{

  char cVar1;

  undefined8 uVar2;

  undefined *puVar3;

  int local_38;

  int iStack_34;

  int iStack_30;

  int iStack_2c;

  int local_28;

  int iStack_24;

  int iStack_20;

  int iStack_1c;

  int local_18;

  int iStack_14;

  int iStack_10;

  int iStack_c;

  

  cVar1 = FUN_1401489c0();

  if ((cVar1 == '\0') || ((*(longlong *)(param_1 + 0x18) == 0 && ((*param_1 & 2) == 0)))) {

    puVar3 = &DAT_1403141a4;

  }

  else {

    cVar1 = FUN_1401489c0(param_3);

    if ((cVar1 != '\0') && ((*(longlong *)(param_3 + 0x18) != 0 || ((*param_3 & 2) != 0)))) {

      if (((*param_1 & 4) != 0) || ((*param_3 & 4) != 0)) {

        uVar2 = FUN_14012e850("Surfaces must not be locked during blit");

        return uVar2;

      }

      iStack_20 = *(int *)(param_1 + 8);

      iStack_1c = *(int *)(param_1 + 0xc);

      local_28 = 0;

      iStack_24 = 0;

      if (param_4 == (int *)0x0) {

        local_38 = 0;

        iStack_34 = 0;

      }

      else {

        local_38 = *param_4;

        iStack_34 = param_4[1];

      }

      if (param_2 != (int *)0x0) {

        cVar1 = FUN_140185790(param_2,&local_28,&local_18);

        if (cVar1 == '\0') {

          return 1;

        }

        local_28 = local_18;

        iStack_24 = iStack_14;

        iStack_1c = iStack_c;

        local_38 = local_38 + (local_18 - *param_2);

        iStack_34 = iStack_34 + (iStack_14 - param_2[1]);

        iStack_20 = iStack_10;

      }

      _iStack_30 = CONCAT44(iStack_1c,iStack_20);

      cVar1 = FUN_140185790(&local_38,param_3 + 100,&local_18);

      if (((cVar1 != '\0') &&

          (_local_28 = CONCAT44(iStack_24 + (iStack_14 - iStack_34),local_28 + (local_18 - local_38)

                               ), 0 < iStack_10)) && (0 < iStack_c)) {

        if ((*(uint *)(param_1 + 0x108) >> 0xb & 1) != 0) {

          *(uint *)(param_1 + 0x108) = *(uint *)(param_1 + 0x108) & 0xfffff7ff;

          FUN_14017ba60(param_1 + 0x78);

        }

        uVar2 = FUN_140144330(param_1,&local_28,param_3,&local_38);

        return uVar2;

      }

      return 1;

    }

    puVar3 = &DAT_140331e9c;

  }

  uVar2 = FUN_14012e850("Parameter \'%s\' is invalid",puVar3);

  return uVar2;

}




