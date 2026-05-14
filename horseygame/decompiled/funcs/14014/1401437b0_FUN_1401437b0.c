// Address: 0x1401437b0
// Ghidra name: FUN_1401437b0
// ============ 0x1401437b0 FUN_1401437b0 (size=899) ============


bool FUN_1401437b0(byte *param_1,longlong param_2,float param_3,undefined4 param_4,byte *param_5,

                  undefined8 *param_6)



{

  char cVar1;

  undefined1 uVar2;

  int iVar3;

  int iVar4;

  ulonglong uVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  float fVar9;

  float extraout_XMM0_Da;

  int local_98;

  int local_94;

  int local_90;

  int local_8c;

  int local_88;

  undefined8 local_80;

  int local_78;

  int local_74;

  uint local_70;

  undefined8 local_68;

  int iStack_60;

  int iStack_5c;

  undefined8 local_58;

  undefined8 uStack_50;

  int local_48;

  int local_44;

  int local_40;

  int local_3c;

  

  cVar1 = FUN_1401489c0();

  if (cVar1 == '\0') {

    uVar2 = FUN_14012e850("Parameter \'%s\' is invalid",&DAT_1403141a4);

    return (bool)uVar2;

  }

  cVar1 = FUN_1401489c0(param_5);

  if (cVar1 == '\0') {

    uVar2 = FUN_14012e850("Parameter \'%s\' is invalid",&DAT_140331e9c);

    return (bool)uVar2;

  }

  if (((*param_1 & 4) != 0) || ((*param_5 & 4) != 0)) {

    uVar2 = FUN_14012e850("Surfaces must not be locked during blit");

    return (bool)uVar2;

  }

  if (param_3 < 0.0) {

    uVar2 = FUN_14012e850("Parameter \'%s\' is invalid","scale");

    return (bool)uVar2;

  }

  iStack_60 = *(int *)(param_1 + 8);

  iVar8 = 0;

  iStack_5c = *(int *)(param_1 + 0xc);

  local_68 = 0;

  if (param_6 == (undefined8 *)0x0) {

    local_78 = *(int *)(param_5 + 8);

    local_74 = *(int *)(param_5 + 0xc);

    local_80 = 0;

  }

  else {

    local_80 = *param_6;

    local_78 = *(int *)(param_6 + 1);

    local_74 = *(int *)((longlong)param_6 + 0xc);

  }

  if (((param_2 == 0) || (cVar1 = FUN_140185790(param_2,&local_68,&local_68), cVar1 != '\0')) &&

     (cVar1 = FUN_140185790(&local_80,param_5 + 100,&local_80), cVar1 != '\0')) {

    if ((*(uint *)(param_1 + 0x108) >> 0xb & 1) != 0) {

      *(uint *)(param_1 + 0x108) = *(uint *)(param_1 + 0x108) & 0xfffff7ff;

      FUN_14017ba60(param_1 + 0x78);

    }

    fVar9 = (float)thunk_FUN_1402e1d00((float)iStack_60 * param_3);

    iVar6 = (int)fVar9;

    local_44 = iVar6;

    thunk_FUN_1402e1d00((float)iStack_5c * param_3);

    local_8c = (int)extraout_XMM0_Da;

    if ((0 < iVar6) && (0 < local_8c)) {

      local_70 = (uint)((longlong)local_74 / (longlong)local_8c);

      uVar5 = (longlong)local_74 / (longlong)local_8c & 0xffffffff;

      iVar3 = local_78 / iVar6;

      local_94 = local_80._4_4_;

      iVar4 = local_78 - iVar3 * iVar6;

      local_40 = local_74 - local_70 * local_8c;

      local_88 = (int)((float)iVar4 / param_3);

      uStack_50 = CONCAT44(iStack_5c,iStack_60);

      local_58 = local_68;

      local_3c = (int)((float)local_40 / param_3);

      iVar7 = iVar8;

      local_90 = iVar6;

      local_48 = iVar4;

      if (0 < (int)local_70) {

        do {

          local_98 = (int)local_80;

          iVar6 = iVar8;

          if (0 < iVar3) {

            do {

              cVar1 = FUN_140143df0(param_1,&local_58,param_5,&local_98,param_4);

              if (cVar1 == '\0') {

                return false;

              }

              iVar6 = iVar6 + 1;

              local_98 = local_98 + local_90;

            } while (iVar6 < iVar3);

            uVar5 = (ulonglong)local_70;

          }

          iVar4 = local_48;

          if (0 < local_48) {

            local_90 = local_48;

            uStack_50._0_4_ = local_88;

            cVar1 = FUN_140143df0(param_1,&local_58,param_5,&local_98,param_4);

            if (cVar1 == '\0') {

              return false;

            }

            uVar5 = (ulonglong)local_70;

            uStack_50 = CONCAT44(uStack_50._4_4_,iStack_60);

            local_90 = local_44;

          }

          iVar7 = iVar7 + 1;

          local_94 = local_94 + local_8c;

        } while (iVar7 < (int)uVar5);

      }

      if (0 < local_40) {

        local_98 = (int)local_80;

        local_8c = local_40;

        uStack_50._4_4_ = local_3c;

        if (0 < iVar3) {

          do {

            cVar1 = FUN_140143df0(param_1,&local_58,param_5,&local_98,param_4);

            if (cVar1 == '\0') {

              return false;

            }

            iVar8 = iVar8 + 1;

            local_98 = local_98 + local_90;

          } while (iVar8 < iVar3);

        }

        if (0 < iVar4) {

          uStack_50 = CONCAT44(uStack_50._4_4_,local_88);

          local_90 = iVar4;

          cVar1 = FUN_140143df0(param_1,&local_58,param_5,&local_98,param_4);

          return cVar1 != '\0';

        }

      }

      return true;

    }

  }

  return true;

}




