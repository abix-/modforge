// Address: 0x14015daf0
// Ghidra name: FUN_14015daf0
// ============ 0x14015daf0 FUN_14015daf0 (size=637) ============


ulonglong FUN_14015daf0(undefined4 param_1,longlong param_2,int param_3)



{

  undefined8 *puVar1;

  longlong lVar2;

  char cVar3;

  byte bVar4;

  ulonglong uVar5;

  longlong lVar6;

  uint uVar7;

  ulonglong uVar8;

  ulonglong uVar9;

  byte local_res18;

  longlong local_48 [2];

  

  uVar5 = 0;

  local_48[0] = 0;

  bVar4 = 1;

  local_res18 = 1;

  if (param_3 == 0) goto LAB_14015dd5c;

  if (param_3 < 0) {

    uVar5 = FUN_14012e850("Parameter \'%s\' is invalid","num_streams");

    return uVar5;

  }

  if (param_2 == 0) {

    uVar5 = FUN_14012e850("Parameter \'%s\' is invalid","streams");

    return uVar5;

  }

  cVar3 = FUN_14015ec10();

  if (cVar3 != '\0') {

    uVar5 = FUN_14012e850(

                         "Audio streams are bound to device ids from SDL_OpenAudioDevice, not raw physical devices"

                         );

    return uVar5;

  }

  lVar6 = FUN_14015cb20(param_1,local_48);

  if (lVar6 == 0) {

    bVar4 = 0;

  }

  else {

    if (*(char *)(lVar6 + 0x21) == '\0') {

      uVar8 = uVar5;

      uVar9 = uVar5;

      if (0 < param_3) {

        do {

          puVar1 = *(undefined8 **)(param_2 + uVar9 * 8);

          if (puVar1 == (undefined8 *)0x0) {

            FUN_14012e850("Stream #%d is NULL",uVar8);

            bVar4 = 0;

LAB_14015dcaf:

            if (0 < (longlong)uVar9) {

              do {

                FUN_140179b60(**(undefined8 **)(param_2 + uVar5 * 8));

                uVar5 = uVar5 + 1;

              } while ((longlong)uVar5 < (longlong)uVar9);

            }

            if (puVar1 != (undefined8 *)0x0) {

              FUN_140179b60(*puVar1);

            }

            goto LAB_14015dd47;

          }

          FUN_140179b40(*puVar1);

          if (puVar1[0x18] == 0) {

            if (*(char *)(puVar1 + 0x17) != '\0') {

              bVar4 = FUN_14012e850(

                                   "Cannot change binding on a stream created with SDL_OpenAudioDeviceStream"

                                   );

              local_res18 = bVar4;

            }

          }

          else {

            bVar4 = FUN_14012e850("Stream #%d is already bound to a device",uVar8);

            local_res18 = bVar4;

          }

          if (bVar4 == 0) goto LAB_14015dcaf;

          uVar7 = (int)uVar8 + 1;

          uVar8 = (ulonglong)uVar7;

          uVar9 = uVar9 + 1;

        } while ((int)uVar7 < param_3);

      }

    }

    else {

      bVar4 = FUN_14012e850(

                           "Cannot change stream bindings on device opened with SDL_OpenAudioDeviceStream"

                           );

      local_res18 = bVar4;

      if (bVar4 == 0) goto LAB_14015dd47;

    }

    lVar2 = local_48[0];

    cVar3 = *(char *)(local_48[0] + 0x94);

    if (param_3 != 0) {

      do {

        puVar1 = *(undefined8 **)(param_2 + uVar5 * 8);

        if (puVar1 != (undefined8 *)0x0) {

          if (cVar3 == '\0') {

            if (*(int *)(puVar1 + 6) == 0) {

              puVar1[6] = *(undefined8 *)(lVar2 + 0x60);

              *(undefined4 *)(puVar1 + 7) = *(undefined4 *)(lVar2 + 0x68);

            }

          }

          else if (*(int *)((longlong)puVar1 + 0x3c) == 0) {

            *(undefined8 *)((longlong)puVar1 + 0x3c) = *(undefined8 *)(lVar2 + 0x60);

            *(undefined4 *)((longlong)puVar1 + 0x44) = *(undefined4 *)(lVar2 + 0x68);

          }

          puVar1[0x18] = lVar6;

          puVar1[0x1a] = 0;

          puVar1[0x19] = *(undefined8 *)(lVar6 + 0x18);

          if (*(longlong *)(lVar6 + 0x18) != 0) {

            *(undefined8 **)(*(longlong *)(lVar6 + 0x18) + 0xd0) = puVar1;

          }

          *(undefined8 **)(lVar6 + 0x18) = puVar1;

          FUN_140179b60(*puVar1);

        }

        uVar5 = uVar5 + 1;

        bVar4 = local_res18;

      } while ((longlong)uVar5 < (longlong)param_3);

    }

  }

LAB_14015dd47:

  lVar6 = local_48[0];

  FUN_14015fec0(local_48[0]);

  FUN_14015d3e0(lVar6);

LAB_14015dd5c:

  return (ulonglong)bVar4;

}




