// Address: 0x14016e7f0
// Ghidra name: FUN_14016e7f0
// ============ 0x14016e7f0 FUN_14016e7f0 (size=310) ============


undefined8 FUN_14016e7f0(longlong param_1,undefined4 *param_2,undefined4 *param_3)



{

  bool bVar1;

  char cVar2;

  int iVar3;

  longlong lVar4;

  undefined8 local_18;

  undefined8 uStack_10;

  

  if (DAT_1403fc410 == 0) {

    FUN_1401730c0();

    return 0;

  }

  if (param_1 != 0) {

    if (DAT_1403e3d60 != '\0') {

      cVar2 = FUN_1401aa7c0(param_1,1);

      if (cVar2 == '\0') goto LAB_14016e908;

    }

    if ((*(ulonglong *)(param_1 + 0x48) & 1) == 0) {

      if (((*(ulonglong *)(param_1 + 0x48) & 8) == 0) || (*(char *)(param_1 + 0x10b) == '\0')) {

        bVar1 = false;

      }

      else {

        bVar1 = true;

      }

      if (param_2 != (undefined4 *)0x0) {

        lVar4 = 0x8c;

        if (!bVar1) {

          lVar4 = 0x18;

        }

        *param_2 = *(undefined4 *)(lVar4 + param_1);

      }

      if (param_3 != (undefined4 *)0x0) {

        lVar4 = 0x90;

        if (!bVar1) {

          lVar4 = 0x1c;

        }

        *param_3 = *(undefined4 *)(lVar4 + param_1);

      }

    }

    else {

      if (param_2 != (undefined4 *)0x0) {

        *param_2 = 0;

      }

      if (param_3 != (undefined4 *)0x0) {

        *param_3 = 0;

      }

      iVar3 = FUN_14016d540(param_1);

      if (iVar3 != 0) {

        local_18 = 0;

        uStack_10 = 0;

        FUN_14016d280(iVar3,&local_18);

        if (param_2 != (undefined4 *)0x0) {

          *param_2 = (undefined4)local_18;

        }

        if (param_3 != (undefined4 *)0x0) {

          *param_3 = local_18._4_4_;

          return 1;

        }

      }

    }

    return 1;

  }

LAB_14016e908:

  FUN_14012e850("Invalid window");

  return 0;

}




