// Address: 0x14017cb10
// Ghidra name: FUN_14017cb10
// ============ 0x14017cb10 FUN_14017cb10 (size=310) ============


undefined8 FUN_14017cb10(int *param_1,longlong param_2)



{

  int iVar1;

  int iVar2;

  longlong lVar3;

  ulonglong uVar4;

  int local_res8 [2];

  

  if (param_1 != (int *)0x0) {

    if (param_2 == 0) {

      iVar2 = *param_1;

      if (iVar2 != 0) {

        LOCK();

        iVar1 = *param_1;

        if (iVar2 == iVar1) {

          *param_1 = iVar2 + -1;

          iVar1 = iVar2;

        }

        UNLOCK();

        if (iVar1 == iVar2) {

          return 1;

        }

      }

      return 0;

    }

    if (-1 < param_2) {

      lVar3 = FUN_140149300();

      do {

        local_res8[0] = *param_1;

        if (local_res8[0] == 0) {

          local_res8[0] = 0;

          do {

            uVar4 = FUN_140149300();

            if ((ulonglong)(param_2 + lVar3) <= uVar4) {

              return 0;

            }

            iVar2 = (*DAT_1403fc5e0)(param_1,local_res8,4,

                                     ((param_2 + lVar3) - uVar4) / 1000000 & 0xffffffff);

            if (iVar2 == 0) {

              return 0;

            }

            local_res8[0] = *param_1;

          } while (local_res8[0] == 0);

        }

        LOCK();

        iVar2 = *param_1;

        if (local_res8[0] == iVar2) {

          *param_1 = local_res8[0] + -1;

          iVar2 = local_res8[0];

        }

        UNLOCK();

        if (iVar2 == local_res8[0]) {

          return 1;

        }

      } while( true );

    }

    do {

      local_res8[0] = *param_1;

      if (local_res8[0] == 0) {

        local_res8[0] = 0;

        do {

          iVar2 = (*DAT_1403fc5e0)(param_1,local_res8,4,0xffffffff);

          if (iVar2 == 0) {

            return 0;

          }

          local_res8[0] = *param_1;

        } while (local_res8[0] == 0);

      }

      LOCK();

      iVar2 = *param_1;

      if (local_res8[0] == iVar2) {

        *param_1 = local_res8[0] + -1;

        iVar2 = local_res8[0];

      }

      UNLOCK();

    } while (iVar2 != local_res8[0]);

  }

  return 1;

}




