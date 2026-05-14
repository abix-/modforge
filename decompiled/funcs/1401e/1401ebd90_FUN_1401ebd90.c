// Address: 0x1401ebd90
// Ghidra name: FUN_1401ebd90
// ============ 0x1401ebd90 FUN_1401ebd90 (size=313) ============


undefined1

FUN_1401ebd90(char *param_1,longlong param_2,undefined8 param_3,undefined4 param_4,

             undefined8 param_5)



{

  longlong lVar1;

  int iVar2;

  undefined8 uVar3;

  ulonglong uVar4;

  uint uVar5;

  undefined1 local_res10;

  ulonglong uVar6;

  

  lVar1 = *(longlong *)(param_2 + 0x2e0);

  local_res10 = 1;

  if (*(char *)(lVar1 + 8) != '\0') {

    if (*(char *)(lVar1 + 9) == '\0') {

      iVar2 = (**(code **)(lVar1 + 0xd8))();

      if (iVar2 != 0) {

        local_res10 = 0;

        do {

          if ((param_1 == (char *)0x0) || (*param_1 == '\0')) {

            param_1 = "generic";

          }

          uVar3 = FUN_1401eea90(iVar2);

          FUN_14012e850("%s: %s (%d): %s %s (0x%X)",param_1,param_3,param_4,param_5,uVar3,iVar2);

          iVar2 = (**(code **)(lVar1 + 0xd8))();

        } while (iVar2 != 0);

      }

    }

    else if (*(int *)(lVar1 + 0xc) != 0) {

      uVar4 = 0;

      if (0 < *(int *)(lVar1 + 0xc)) {

        local_res10 = 0;

        uVar6 = uVar4;

        do {

          FUN_14012e850("%s: %s (%d): %s %s",param_1,param_3,param_4,param_5,

                        *(undefined8 *)(*(longlong *)(lVar1 + 0x10) + uVar4));

          uVar5 = (int)uVar6 + 1;

          uVar6 = (ulonglong)uVar5;

          uVar4 = uVar4 + 8;

        } while ((int)uVar5 < *(int *)(lVar1 + 0xc));

      }

      FUN_1401ebed0(param_2);

    }

  }

  return local_res10;

}




