// Address: 0x1401b47a0
// Ghidra name: FUN_1401b47a0
// ============ 0x1401b47a0 FUN_1401b47a0 (size=540) ============


char FUN_1401b47a0(longlong param_1,undefined8 param_2,undefined8 param_3,int param_4,

                  undefined1 param_5,undefined8 param_6)



{

  uint *puVar1;

  uint uVar2;

  char cVar3;

  undefined4 uVar4;

  longlong lVar5;

  uint uVar6;

  ulonglong uVar7;

  undefined8 uVar8;

  undefined4 uVar9;

  uint local_res20 [2];

  undefined1 local_58 [32];

  

  uVar8 = 0;

  local_res20[0] = 0;

  uVar4 = 0;

  if (param_4 == 0) {

    uVar9 = 1;

  }

  else {

    if (param_4 == 1) {

      uVar9 = 1;

      uVar4 = 0;

    }

    else {

      if (param_4 != 2) {

                    /* WARNING: Subroutine does not return */

        FUN_14012e0b0(9,"Unrecognized buffer type!",0);

      }

      uVar4 = 1;

      uVar9 = 8;

    }

    uVar8 = 6;

  }

  lVar5 = FUN_1401bacc0(param_1,param_2,uVar8,uVar9,uVar4,local_58,local_res20);

  uVar2 = local_res20[0];

  uVar7 = 0;

  if (local_res20[0] == 0) {

    FUN_1401841e0(lVar5);

    cVar3 = '\0';

  }

  else {

    do {

      puVar1 = (uint *)(lVar5 + uVar7 * 4);

      cVar3 = FUN_1401b4af0(param_1,*puVar1,local_58,param_3,param_5,param_2,0,param_6);

      if (cVar3 == '\x01') {

        uVar7 = (ulonglong)*puVar1;

        FUN_1401841e0(lVar5);

        if (param_4 == 0) {

          if (*(char *)(param_1 + 0x579) != '\0') {

            return '\x01';

          }

          if ((*(byte *)(param_1 + 0x5a4 + uVar7 * 8) & 1) != 0) {

            return '\x01';

          }

          FUN_14012e2e0(9,

                        "Out of device-local memory, allocating buffers on host-local memory, expect degraded performance!"

                       );

          *(undefined1 *)(param_1 + 0x579) = 1;

          return '\x01';

        }

        if (param_4 != 1) {

          if (param_4 != 2) {

            return '\x01';

          }

          if (*(char *)(param_1 + 0x578) != '\0') {

            return '\x01';

          }

          if ((*(byte *)(param_1 + 0x5a4 + uVar7 * 8) & 1) == 0) {

            return '\x01';

          }

          FUN_14012e0e0(9,

                        "Integrated memory detected, allocating TransferBuffers on device-local memory!"

                       );

          *(undefined1 *)(param_1 + 0x578) = 1;

          return '\x01';

        }

        if (*(char *)(param_1 + 0x57a) != '\0') {

          return '\x01';

        }

        if ((*(byte *)(param_1 + 0x5a4 + uVar7 * 8) & 1) != 0) {

          return '\x01';

        }

        FUN_14012e2e0(9,

                      "Out of BAR memory, allocating uniform buffers on host-local memory, expect degraded performance!"

                     );

        *(undefined1 *)(param_1 + 0x57a) = 1;

        return '\x01';

      }

      uVar6 = (int)uVar7 + 1;

      uVar7 = (ulonglong)uVar6;

    } while (uVar6 < uVar2);

    FUN_1401841e0(lVar5);

  }

  return cVar3;

}




