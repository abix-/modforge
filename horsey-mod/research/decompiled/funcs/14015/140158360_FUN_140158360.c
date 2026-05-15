// Address: 0x140158360
// Ghidra name: FUN_140158360
// ============ 0x140158360 FUN_140158360 (size=537) ============


ulonglong FUN_140158360(undefined4 *param_1)



{

  char cVar1;

  int iVar2;

  ulonglong uVar3;

  undefined2 local_res8 [4];

  undefined2 local_res10 [4];

  undefined4 local_28;

  undefined4 uStack_24;

  undefined4 uStack_20;

  undefined4 uStack_1c;

  

  local_28 = *param_1;

  uStack_24 = param_1[1];

  uStack_20 = param_1[2];

  uStack_1c = param_1[3];

  FUN_1401582b0(&local_28,local_res10,local_res8,0,0);

  cVar1 = FUN_140159780(local_res10[0],local_res8[0]);

  if (cVar1 != '\0') {

switchD_140158431_caseD_2:

    return 2;

  }

  cVar1 = FUN_1401593e0(local_res10[0],local_res8[0]);

  if (cVar1 == '\0') {

    cVar1 = FUN_140159420(local_res10[0],local_res8[0]);

    if (cVar1 == '\0') {

      cVar1 = FUN_1401596d0(local_res10[0],local_res8[0]);

      if (cVar1 != '\0') {

        return 9;

      }

      local_28 = *param_1;

      uStack_24 = param_1[1];

      uStack_20 = param_1[2];

      uStack_1c = param_1[3];

      cVar1 = FUN_140159790(&local_28);

      if (cVar1 == '\0') {

        local_28 = *param_1;

        uStack_24 = param_1[1];

        uStack_20 = param_1[2];

        uStack_1c = param_1[3];

        cVar1 = FUN_140159770(&local_28);

        if (cVar1 == '\0') {

          local_28 = *param_1;

          uStack_24 = param_1[1];

          uStack_20 = param_1[2];

          uStack_1c = param_1[3];

          cVar1 = FUN_140159480(&local_28);

          if (cVar1 == '\0') {

            local_28 = *param_1;

            uStack_24 = param_1[1];

            uStack_20 = param_1[2];

            uStack_1c = param_1[3];

            cVar1 = FUN_1401596e0(&local_28);

            if (cVar1 == '\0') {

              local_28 = *param_1;

              uStack_24 = param_1[1];

              uStack_20 = param_1[2];

              uStack_1c = param_1[3];

              cVar1 = FUN_1401594b0(&local_28);

              if (cVar1 != '\0') {

                local_28 = *param_1;

                uStack_24 = param_1[1];

                uStack_20 = param_1[2];

                uStack_1c = param_1[3];

                uVar3 = FUN_140207eb0(&local_28);

                return uVar3;

              }

              iVar2 = FUN_140211000(local_res10[0],local_res8[0]);

              return (ulonglong)(iVar2 != 0x1e);

            }

          }

        }

        return (ulonglong)*(byte *)((longlong)param_1 + 0xf);

      }

      switch(*(undefined1 *)((longlong)param_1 + 0xf)) {

      case 1:

        return 1;

      case 2:

        goto switchD_140158431_caseD_2;

      case 3:

        goto switchD_140158431_caseD_3;

      case 4:

        break;

      case 5:

        return 5;

      case 6:

      case 7:

      case 0xb:

        return 6;

      case 8:

        return 7;

      default:

        return 0;

      case 0x13:

        return 8;

      }

    }

    return 4;

  }

switchD_140158431_caseD_3:

  return 3;

}




