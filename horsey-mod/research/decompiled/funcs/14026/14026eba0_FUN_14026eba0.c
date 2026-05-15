// Address: 0x14026eba0
// Ghidra name: FUN_14026eba0
// ============ 0x14026eba0 FUN_14026eba0 (size=217) ============


ulonglong FUN_14026eba0(longlong param_1)



{

  longlong lVar1;

  ulonglong in_RAX;

  longlong lVar2;

  ulonglong uVar3;

  char local_48;

  undefined1 local_47 [63];

  

  lVar1 = *(longlong *)(param_1 + 0x70);

  if (0 < *(int *)(param_1 + 0x8c)) {

    lVar2 = FUN_1401581c0(**(undefined4 **)(param_1 + 0x90));

    in_RAX = 0;

    if (lVar2 != 0) {

      uVar3 = FUN_14026ffd0(*(undefined8 *)(param_1 + 0x80),0,&local_48,0x40);

      if ((int)uVar3 < 0) {

        uVar3 = FUN_14012e080(7,

                              "HIDAPI_DriverPS3SonySixaxis_UpdateDevice(): Couldn\'t read feature report 0x00"

                             );

        uVar3 = uVar3 & 0xffffffffffffff00;

      }

      else {

        if (local_48 == '\0') {

          FUN_14026ec80(lVar2,lVar1,local_47,(int)uVar3 + -1);

          if (*(char *)(lVar1 + 0x13) == '\0') {

            FUN_14026ff30(param_1);

            *(undefined1 *)(lVar1 + 0x13) = 1;

          }

        }

        uVar3 = (ulonglong)((byte)(uVar3 >> 0x1f) & 1 ^ 1);

      }

      return uVar3;

    }

  }

  return in_RAX & 0xffffffffffffff00;

}




