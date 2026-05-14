// Address: 0x1400ee5f0
// Ghidra name: FUN_1400ee5f0
// ============ 0x1400ee5f0 FUN_1400ee5f0 (size=810) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined8

FUN_1400ee5f0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)



{

  longlong *plVar1;

  char cVar2;

  bool bVar3;

  int iVar4;

  int iVar5;

  uint uVar6;

  undefined4 uVar7;

  char *_Str1;

  char *local_458;

  undefined4 *local_450 [5];

  undefined1 local_428 [1024];

  

  iVar4 = FUN_1400ee920();

  if (iVar4 == 0) {

    local_450[0] = param_1;

    iVar4 = FUN_1400eaf60(local_450,2,0);

    if (iVar4 == 0) {

      *(undefined8 *)(local_450[0] + 0x2e) = *(undefined8 *)(local_450[0] + 0x32);

      iVar4 = FUN_1400edd60(param_1,param_2,param_3,param_4);

      if ((iVar4 == 0) && (iVar4 = FUN_1400ed8e0(param_1,param_2,param_3,param_4), iVar4 == 0)) {

        iVar4 = FUN_1400e8ad0(param_1);

        iVar5 = FUN_1400e8ad0(param_1);

        if ((iVar5 + iVar4 * 0x10000 == 0x38425053) && (iVar4 = FUN_1400e8ad0(param_1), iVar4 == 1))

        {

          plVar1 = (longlong *)(param_1 + 0x2e);

          if ((*(longlong *)(param_1 + 4) == 0) || (iVar4 = param_1[0x30] - (int)*plVar1, 5 < iVar4)

             ) {

            *plVar1 = *plVar1 + 6;

          }

          else {

            *plVar1 = *(longlong *)(param_1 + 0x30);

            (**(code **)(param_1 + 6))(*(undefined8 *)(param_1 + 10),6 - iVar4);

          }

          uVar6 = FUN_1400e8ad0(param_1);

          if (uVar6 < 0x11) {

            uVar7 = FUN_1400e8c30(param_1);

            *param_3 = uVar7;

            uVar7 = FUN_1400e8c30(param_1);

            *param_2 = uVar7;

            iVar4 = FUN_1400e8ad0(param_1);

            if ((iVar4 == 8) && (iVar4 = FUN_1400e8ad0(param_1), iVar4 == 3)) {

              *param_4 = 4;

              return 1;

            }

          }

        }

        *(undefined8 *)(param_1 + 0x2e) = *(undefined8 *)(param_1 + 0x32);

        iVar4 = FUN_1400ef220(param_1,param_2,param_3,param_4);

        if (iVar4 == 0) {

          bVar3 = false;

          _Str1 = (char *)FUN_1400e91d0(param_1,local_428);

          iVar4 = strcmp(_Str1,"#?RADIANCE");

          if ((iVar4 == 0) &&

             (local_458 = (char *)FUN_1400e91d0(param_1,local_428), *local_458 != '\0')) {

            do {

              iVar4 = strcmp(local_458,"FORMAT=32-bit_rle_rgbe");

              if (iVar4 == 0) {

                bVar3 = true;

              }

              local_458 = (char *)FUN_1400e91d0(param_1,local_428);

            } while (*local_458 != '\0');

            if (bVar3) {

              local_458 = (char *)FUN_1400e91d0(param_1,local_428);

              iVar4 = strncmp(local_458,"-Y ",3);

              if (iVar4 == 0) {

                local_458 = local_458 + 3;

                uVar7 = FUN_1402d8a8c(local_458,&local_458,10);

                *param_3 = uVar7;

                cVar2 = *local_458;

                while (cVar2 == ' ') {

                  local_458 = local_458 + 1;

                  cVar2 = *local_458;

                }

                iVar4 = strncmp(local_458,"+X ",3);

                if (iVar4 == 0) {

                  local_458 = local_458 + 3;

                  uVar7 = FUN_1402d8a8c(local_458,0,10);

                  *param_2 = uVar7;

                  *param_4 = 3;

                  return 1;

                }

              }

            }

          }

          *(undefined8 *)(param_1 + 0x2e) = *(undefined8 *)(param_1 + 0x32);

          iVar4 = FUN_1400ef8a0(param_1,param_2,param_3,param_4);

          if (iVar4 == 0) {

            _DAT_1403f4c40 = "unknown image type";

            return 0;

          }

        }

      }

    }

    else {

      if (param_2 != (undefined4 *)0x0) {

        *param_2 = *local_450[0];

      }

      if (param_3 != (undefined4 *)0x0) {

        *param_3 = local_450[0][1];

      }

      if (param_4 != (undefined4 *)0x0) {

        *param_4 = local_450[0][2];

      }

    }

  }

  return 1;

}




