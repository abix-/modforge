// Address: 0x140287610
// Ghidra name: FUN_140287610
// ============ 0x140287610 FUN_140287610 (size=260) ============


bool FUN_140287610(longlong param_1,longlong param_2)



{

  int iVar1;

  undefined4 uVar2;

  

  if (((*(byte *)(param_1 + 0x18) & 3) != 0) && ((*(byte *)(param_1 + 0x1c) & 1) != 0)) {

    param_1 = param_1 + 4;

    iVar1 = FUN_1401a98e0(param_1,&DAT_140350a40);

    if (iVar1 == 0) {

      iVar1 = FUN_1401a98e0(param_1,&DAT_140350a50);

      if (iVar1 == 0) {

        iVar1 = FUN_1401a98e0(param_1,&DAT_140350a60);

        if (iVar1 == 0) {

          iVar1 = FUN_1401a98e0(param_1,&DAT_140350a70);

          if (iVar1 == 0) {

            iVar1 = FUN_1401a98e0(param_1,&DAT_140350a80);

            if (iVar1 == 0) {

              iVar1 = FUN_1401a98e0(param_1,&DAT_140350a90);

              if (iVar1 == 0) {

                return true;

              }

              uVar2 = 0x14;

            }

            else {

              uVar2 = 0x10;

            }

          }

          else {

            uVar2 = 0xc;

          }

        }

        else {

          uVar2 = 8;

        }

      }

      else {

        uVar2 = 4;

      }

    }

    else {

      uVar2 = 0;

    }

    *(undefined4 *)(*(longlong *)(param_2 + 0x28) + 8 + (longlong)*(int *)(param_2 + 0x24) * 4) =

         uVar2;

    *(int *)(param_2 + 0x24) = *(int *)(param_2 + 0x24) + 1;

    return *(int *)(param_2 + 0x24) < 3;

  }

  return true;

}




