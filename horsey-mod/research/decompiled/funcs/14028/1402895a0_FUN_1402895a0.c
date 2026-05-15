// Address: 0x1402895a0
// Ghidra name: FUN_1402895a0
// ============ 0x1402895a0 FUN_1402895a0 (size=542) ============


/* WARNING: Type propagation algorithm not settling */



void FUN_1402895a0(char param_1,undefined8 *param_2,undefined4 param_3,undefined1 param_4)



{

  longlong lVar1;

  int iVar2;

  ulonglong uVar3;

  undefined8 uVar4;

  uint uVar5;

  uint local_res8 [2];

  longlong *local_a8;

  LPVOID local_a0;

  longlong *local_98;

  LPVOID local_90;

  longlong *local_88;

  longlong local_80 [9];

  ulonglong uVar6;

  

  uVar6 = 0;

  local_a8 = (longlong *)0x0;

  iVar2 = (**(code **)(*DAT_1403fde80 + 0x18))(DAT_1403fde80,param_1 != '\0',1,&local_a8);

  if (-1 < iVar2) {

    local_res8[0] = 0;

    iVar2 = (**(code **)(*local_a8 + 0x18))(local_a8,local_res8);

    if (iVar2 < 0) {

      (**(code **)(*local_a8 + 0x10))();

    }

    else {

      uVar3 = uVar6;

      if (param_2 != (undefined8 *)0x0) {

        local_88 = (longlong *)0x0;

        iVar2 = (**(code **)(*DAT_1403fde80 + 0x20))(DAT_1403fde80,param_1 != '\0',0,&local_88);

        if (-1 < iVar2) {

          local_90 = (LPVOID)0x0;

          iVar2 = (**(code **)(*local_88 + 0x28))(local_88,&local_90);

          if (-1 < iVar2) {

            uVar3 = FUN_14012fc00(local_90);

            CoTaskMemFree(local_90);

          }

          (**(code **)(*local_88 + 0x10))();

        }

      }

      if (local_res8[0] != 0) {

        do {

          local_98 = (longlong *)0x0;

          iVar2 = (**(code **)(*local_a8 + 0x20))(local_a8,uVar6,&local_98);

          if (-1 < iVar2) {

            local_a0 = (LPVOID)0x0;

            iVar2 = (**(code **)(*local_98 + 0x28))(local_98,&local_a0);

            if (-1 < iVar2) {

              local_80[0] = 0;

              local_80[7] = 0;

              local_80[3] = 0;

              local_80[4] = 0;

              local_80[5] = 0;

              local_80[6] = 0;

              local_80[1] = 0;

              local_80[2] = 0;

              FUN_140289800(local_98,local_80,local_80 + 3,local_80 + 1);

              lVar1 = local_80[0];

              if (local_80[0] != 0) {

                uVar4 = FUN_140289960(param_1,local_80[0],local_80 + 3,local_a0,local_80 + 1,param_3

                                      ,param_4);

                if ((param_2 != (undefined8 *)0x0) && (uVar3 != 0)) {

                  iVar2 = FUN_14012fbc0(uVar3,local_a0);

                  if (iVar2 == 0) {

                    *param_2 = uVar4;

                  }

                }

                FUN_1401841e0(lVar1);

              }

              CoTaskMemFree(local_a0);

            }

            (**(code **)(*local_98 + 0x10))();

          }

          uVar5 = (int)uVar6 + 1;

          uVar6 = (ulonglong)uVar5;

        } while (uVar5 < local_res8[0]);

      }

      FUN_1401841e0(uVar3);

      (**(code **)(*local_a8 + 0x10))();

    }

  }

  return;

}




