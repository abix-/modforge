// Address: 0x1401bc440
// Ghidra name: FUN_1401bc440
// ============ 0x1401bc440 FUN_1401bc440 (size=774) ============


undefined8 FUN_1401bc440(longlong param_1,undefined8 param_2,undefined8 param_3,longlong param_4)



{

  int iVar1;

  undefined8 uVar2;

  longlong lVar3;

  char *pcVar4;

  int local_res8 [2];

  

  (**(code **)(param_1 + 0x9c0))(param_2,*(undefined4 *)(param_1 + 0x7c0),param_3,local_res8);

  *(undefined8 *)(param_4 + 0x38) = 0;

  *(undefined4 *)(param_4 + 0x40) = 0;

  *(undefined8 *)(param_4 + 0x48) = 0;

  *(undefined4 *)(param_4 + 0x50) = 0;

  if (local_res8[0] == 0) {

    if (*(char *)(param_1 + 0x57c) != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(9,&DAT_14039bf30,"This surface does not support presenting!");

    }

    FUN_14012e850(&DAT_14039bf30,"This surface does not support presenting!");

    return 0;

  }

  iVar1 = (**(code **)(param_1 + 0x9a8))(param_2,param_3,param_4);

  if (iVar1 == 0) {

    if ((*(byte *)(param_4 + 0x2c) & 1) == 0) {

      FUN_14012e2e0(9,"Opaque presentation unsupported! Expect weird transparency bugs!");

    }

    iVar1 = (**(code **)(param_1 + 0x9b0))(param_2,param_3,param_4 + 0x40,0);

    if (iVar1 != 0) {

      *(undefined4 *)(param_4 + 0x40) = 0;

      if (*(char *)(param_1 + 0x57c) != '\0') {

        uVar2 = FUN_1401c0ba0(iVar1);

                    /* WARNING: Subroutine does not return */

        FUN_14012e0b0(9,"%s %s","vkGetPhysicalDeviceSurfaceFormatsKHR",uVar2);

      }

      uVar2 = FUN_1401c0ba0(iVar1);

      pcVar4 = "vkGetPhysicalDeviceSurfaceFormatsKHR";

      goto LAB_1401bc714;

    }

    iVar1 = (**(code **)(param_1 + 0x9b8))(param_2,param_3,param_4 + 0x50,0);

    if (iVar1 == 0) {

      if (*(uint *)(param_4 + 0x40) != 0) {

        lVar3 = FUN_1401841f0((ulonglong)*(uint *)(param_4 + 0x40) << 3);

        *(longlong *)(param_4 + 0x38) = lVar3;

        if (lVar3 == 0) goto LAB_1401bc691;

        iVar1 = (**(code **)(param_1 + 0x9b0))(param_2,param_3,param_4 + 0x40,lVar3);

        if (iVar1 != 0) {

          FUN_1401841e0(*(undefined8 *)(param_4 + 0x38));

          *(undefined8 *)(param_4 + 0x38) = 0;

          *(undefined4 *)(param_4 + 0x40) = 0;

          *(undefined4 *)(param_4 + 0x50) = 0;

          if (*(char *)(param_1 + 0x57c) != '\0') {

            uVar2 = FUN_1401c0ba0(iVar1);

                    /* WARNING: Subroutine does not return */

            FUN_14012e0b0(9,"%s %s","vkGetPhysicalDeviceSurfaceFormatsKHR",uVar2);

          }

          uVar2 = FUN_1401c0ba0(iVar1);

          FUN_14012e850("%s %s","vkGetPhysicalDeviceSurfaceFormatsKHR",uVar2);

          return 0;

        }

      }

      if (*(uint *)(param_4 + 0x50) == 0) {

        return 1;

      }

      lVar3 = FUN_1401841f0((ulonglong)*(uint *)(param_4 + 0x50) << 2);

      *(longlong *)(param_4 + 0x48) = lVar3;

      if (lVar3 == 0) {

        FUN_1401841e0(*(undefined8 *)(param_4 + 0x38));

        *(undefined8 *)(param_4 + 0x38) = 0;

LAB_1401bc691:

        *(undefined4 *)(param_4 + 0x40) = 0;

        *(undefined4 *)(param_4 + 0x50) = 0;

        return 0;

      }

      iVar1 = (**(code **)(param_1 + 0x9b8))(param_2,param_3,param_4 + 0x50,lVar3);

      if (iVar1 == 0) {

        return 1;

      }

      FUN_1401841e0(*(undefined8 *)(param_4 + 0x38));

      FUN_1401841e0(*(undefined8 *)(param_4 + 0x48));

      *(undefined8 *)(param_4 + 0x38) = 0;

      *(undefined8 *)(param_4 + 0x48) = 0;

    }

    *(undefined4 *)(param_4 + 0x40) = 0;

    *(undefined4 *)(param_4 + 0x50) = 0;

    if (*(char *)(param_1 + 0x57c) != '\0') {

      uVar2 = FUN_1401c0ba0(iVar1);

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(9,"%s %s","vkGetPhysicalDeviceSurfacePresentModesKHR",uVar2);

    }

    uVar2 = FUN_1401c0ba0(iVar1);

    pcVar4 = "vkGetPhysicalDeviceSurfacePresentModesKHR";

  }

  else {

    if (*(char *)(param_1 + 0x57c) != '\0') {

      uVar2 = FUN_1401c0ba0(iVar1);

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(9,"%s %s","vkGetPhysicalDeviceSurfaceCapabilitiesKHR",uVar2);

    }

    uVar2 = FUN_1401c0ba0(iVar1);

    pcVar4 = "vkGetPhysicalDeviceSurfaceCapabilitiesKHR";

  }

LAB_1401bc714:

  FUN_14012e850("%s %s",pcVar4,uVar2);

  return 0;

}




