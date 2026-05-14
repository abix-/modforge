// Address: 0x1401bfb70
// Ghidra name: FUN_1401bfb70
// ============ 0x1401bfb70 FUN_1401bfb70 (size=321) ============


undefined4 FUN_1401bfb70(longlong param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4)



{

  char cVar1;

  int iVar2;

  longlong lVar3;

  

  lVar3 = FUN_1401baca0(param_2);

  if (lVar3 == 0) {

    if (*(char *)(param_1 + 0x57c) != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(9,&DAT_14039bf30,"Cannot set swapchain parameters on unclaimed window!");

    }

    FUN_14012e850(&DAT_14039bf30,"Cannot set swapchain parameters on unclaimed window!");

  }

  else {

    cVar1 = FUN_1401c0410(param_1,param_2,param_3);

    if (cVar1 == '\0') {

      if (*(char *)(param_1 + 0x57c) == '\0') {

        FUN_14012e850(&DAT_14039bf30,"Swapchain composition not supported!");

        return 0;

      }

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(9,&DAT_14039bf30,"Swapchain composition not supported!");

    }

    cVar1 = FUN_1401c02c0(param_1,param_2,param_4);

    if (cVar1 == '\0') {

      if (*(char *)(param_1 + 0x57c) == '\0') {

        FUN_14012e850(&DAT_14039bf30,"Present mode not supported!");

        return 0;

      }

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(9,&DAT_14039bf30,"Present mode not supported!");

    }

    *(undefined4 *)(lVar3 + 0x18) = param_4;

    *(undefined4 *)(lVar3 + 0x14) = param_3;

    iVar2 = FUN_1401bc750(param_1,lVar3);

    if (iVar2 != 0) {

      if (iVar2 != 2) {

        return 1;

      }

      *(undefined1 *)(lVar3 + 0x1c) = 1;

      return 1;

    }

  }

  return 0;

}




