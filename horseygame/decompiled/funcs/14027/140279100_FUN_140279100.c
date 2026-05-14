// Address: 0x140279100
// Ghidra name: FUN_140279100
// ============ 0x140279100 FUN_140279100 (size=277) ============


void FUN_140279100(longlong param_1,undefined8 param_2,undefined8 param_3)



{

  char cVar1;

  ushort local_res8 [4];

  undefined8 local_28;

  undefined8 uStack_20;

  undefined8 local_18;

  undefined4 local_10;

  undefined1 local_c;

  

  local_18 = 0;

  local_10 = 0;

  local_c = 0;

  local_28 = 0;

  uStack_20 = 0;

  FUN_140278670(&local_28,param_1 + 0x2d,param_3,param_2);

  FUN_140278840(param_1,param_2,&local_28);

  if ((*(int *)(param_1 + 0x18) == 1) || (*(int *)(param_1 + 0x18) == 2)) {

    local_res8[0] = 0;

    cVar1 = FUN_1402796b0(param_1,local_res8);

    if (cVar1 != '\0') {

      if ((local_res8[0] & 0xf0ff) == 5) {

        FUN_14012e080(7,"HIDAPI Wii: Motion Plus CONNECTED (stage %d)",

                      (*(int *)(param_1 + 0x18) != 1) + '\x01');

        if (*(char *)(param_1 + 0x29) == '\0') {

          *(undefined4 *)(param_1 + 0x18) = 0;

          *(undefined1 *)(param_1 + 0x60) = 1;

          return;

        }

      }

      else {

        if (*(int *)(param_1 + 0x18) == 1) {

          FUN_140279c00(param_1,0xa600fe,2,0);

          *(undefined4 *)(param_1 + 0x18) = 2;

          return;

        }

        FUN_14012e080(7,"HIDAPI Wii: Motion Plus DISCONNECTED (stage %d)",2);

        if (*(char *)(param_1 + 0x29) != '\0') {

          *(undefined1 *)(param_1 + 0x60) = 1;

        }

      }

      *(undefined4 *)(param_1 + 0x18) = 0;

    }

  }

  return;

}




