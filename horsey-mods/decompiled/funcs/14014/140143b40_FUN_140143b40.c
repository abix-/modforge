// Address: 0x140143b40
// Ghidra name: FUN_140143b40
// ============ 0x140143b40 FUN_140143b40 (size=684) ============


undefined1 FUN_140143b40(byte *param_1,longlong param_2,byte *param_3,undefined8 *param_4)



{

  char cVar1;

  undefined1 uVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  int iVar9;

  uint local_70;

  int local_6c;

  int local_68;

  int local_64;

  undefined8 local_60;

  int local_58;

  int local_54;

  undefined8 local_48;

  int iStack_40;

  int iStack_3c;

  undefined4 local_38;

  undefined4 uStack_34;

  int iStack_30;

  int iStack_2c;

  

  cVar1 = FUN_1401489c0();

  if (cVar1 == '\0') {

    uVar2 = FUN_14012e850("Parameter \'%s\' is invalid",&DAT_1403141a4);

    return uVar2;

  }

  cVar1 = FUN_1401489c0(param_3);

  if (cVar1 == '\0') {

    uVar2 = FUN_14012e850("Parameter \'%s\' is invalid",&DAT_140331e9c);

    return uVar2;

  }

  if (((*param_1 & 4) != 0) || ((*param_3 & 4) != 0)) {

    uVar2 = FUN_14012e850("Surfaces must not be locked during blit");

    return uVar2;

  }

  iStack_40 = *(int *)(param_1 + 8);

  iVar9 = 0;

  iStack_3c = *(int *)(param_1 + 0xc);

  local_48 = 0;

  if (param_4 == (undefined8 *)0x0) {

    local_58 = *(int *)(param_3 + 8);

    local_54 = *(int *)(param_3 + 0xc);

    local_60 = 0;

  }

  else {

    local_60 = *param_4;

    local_58 = *(int *)(param_4 + 1);

    local_54 = *(int *)((longlong)param_4 + 0xc);

  }

  if (((param_2 == 0) || (cVar1 = FUN_140185790(param_2,&local_48,&local_48), cVar1 != '\0')) &&

     (cVar1 = FUN_140185790(&local_60,param_3 + 100,&local_60), cVar1 != '\0')) {

    if ((*(uint *)(param_1 + 0x108) >> 0xb & 1) != 0) {

      *(uint *)(param_1 + 0x108) = *(uint *)(param_1 + 0x108) & 0xfffff7ff;

      FUN_14017ba60(param_1 + 0x78);

    }

    iVar3 = local_54 / iStack_3c;

    local_38 = (undefined4)local_48;

    uStack_34 = local_48._4_4_;

    iStack_30 = iStack_40;

    iStack_2c = iStack_3c;

    local_6c = local_60._4_4_;

    iVar8 = local_58 / iStack_40;

    local_68 = iStack_40;

    local_64 = iStack_3c;

    iVar6 = local_58 % iStack_40;

    iVar4 = local_54 % iStack_3c;

    iVar7 = iVar9;

    if (0 < iVar3) {

      do {

        local_70 = (uint)local_60;

        iVar5 = iVar9;

        if (0 < iVar8) {

          do {

            cVar1 = FUN_140144330(param_1,&local_38,param_3,&local_70);

            if (cVar1 == '\0') {

              return false;

            }

            iVar5 = iVar5 + 1;

            local_70 = local_70 + local_68;

          } while (iVar5 < iVar8);

        }

        if (iVar6 != 0) {

          local_68 = iVar6;

          iStack_30 = iVar6;

          cVar1 = FUN_140144330(param_1,&local_38,param_3,&local_70);

          if (cVar1 == '\0') {

            return false;

          }

          iStack_30 = iStack_40;

          local_68 = iStack_40;

        }

        iVar7 = iVar7 + 1;

        local_6c = local_6c + local_64;

      } while (iVar7 < iVar3);

    }

    if (iVar4 != 0) {

      local_70 = (uint)local_60;

      local_64 = iVar4;

      iStack_2c = iVar4;

      if (0 < iVar8) {

        do {

          cVar1 = FUN_140144330(param_1,&local_38,param_3,&local_70);

          if (cVar1 == '\0') {

            return false;

          }

          iVar9 = iVar9 + 1;

          local_70 = local_70 + local_68;

        } while (iVar9 < iVar8);

      }

      if (iVar6 != 0) {

        local_68 = iVar6;

        iStack_30 = iVar6;

        cVar1 = FUN_140144330(param_1,&local_38,param_3,&local_70);

        return cVar1 != '\0';

      }

    }

  }

  return true;

}




