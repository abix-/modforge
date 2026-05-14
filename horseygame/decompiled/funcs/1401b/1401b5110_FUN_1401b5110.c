// Address: 0x1401b5110
// Ghidra name: FUN_1401b5110
// ============ 0x1401b5110 FUN_1401b5110 (size=408) ============


undefined8 FUN_1401b5110(longlong param_1,longlong param_2,undefined8 param_3,char *param_4)



{

  char cVar1;

  int iVar2;

  char *pcVar3;

  char *_Str1;

  undefined8 uVar4;

  ulonglong uVar5;

  uint local_res8 [2];

  undefined8 local_res10;

  

  (**(code **)(param_1 + 0x950))(param_3,0,local_res8,0);

  pcVar3 = (char *)FUN_1401841f0((ulonglong)local_res8[0] * 0x104);

  (**(code **)(param_1 + 0x950))(param_3,0,local_res8,pcVar3);

  param_4[0] = '\0';

  param_4[1] = '\0';

  param_4[2] = '\0';

  param_4[3] = '\0';

  param_4[4] = '\0';

  param_4[5] = '\0';

  if (local_res8[0] != 0) {

    uVar5 = (ulonglong)local_res8[0];

    _Str1 = pcVar3;

    do {

      iVar2 = strcmp(_Str1,"VK_KHR_swapchain");

      if (iVar2 == 0) {

        *param_4 = '\x01';

      }

      else {

        iVar2 = strcmp(_Str1,"VK_KHR_maintenance1");

        if (iVar2 == 0) {

          param_4[1] = '\x01';

        }

        else {

          iVar2 = strcmp(_Str1,"VK_KHR_driver_properties");

          if (iVar2 == 0) {

            param_4[2] = '\x01';

          }

          else {

            iVar2 = strcmp(_Str1,"VK_KHR_portability_subset");

            if (iVar2 == 0) {

              param_4[3] = '\x01';

            }

            else {

              iVar2 = strcmp(_Str1,"VK_MSFT_layered_driver");

              if (iVar2 == 0) {

                param_4[4] = '\x01';

              }

              else {

                iVar2 = strcmp(_Str1,"VK_EXT_texture_compression_astc_hdr");

                if (iVar2 == 0) {

                  param_4[5] = '\x01';

                }

              }

            }

          }

        }

      }

      _Str1 = _Str1 + 0x104;

      uVar5 = uVar5 - 1;

    } while (uVar5 != 0);

  }

  if ((*param_4 == '\0') || (param_4[1] == '\0')) {

    uVar4 = 0;

  }

  else {

    uVar4 = 1;

  }

  if ((*(char *)(param_2 + 0x240) != '\0') &&

     (cVar1 = FUN_1401adbb0(param_2,local_res8[0],pcVar3,&local_res10), cVar1 == '\0')) {

    if (*(char *)(param_1 + 0x57c) != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(9,"Required Vulkan device extension \'%s\' not supported",local_res10);

    }

    uVar4 = 0;

  }

  FUN_1401841e0(pcVar3);

  return uVar4;

}




