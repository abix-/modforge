// Address: 0x1401cc420
// Ghidra name: FUN_1401cc420
// ============ 0x1401cc420 FUN_1401cc420 (size=335) ============


undefined1 FUN_1401cc420(longlong param_1,undefined8 param_2,int param_3,int param_4)



{

  undefined1 uVar1;

  char cVar2;

  longlong lVar3;

  

  lVar3 = FUN_1401c9f40(param_2);

  if (lVar3 == 0) {

    if (*(char *)(param_1 + 0x98) != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(9,&DAT_14039bf30,"Cannot set swapchain parameters on unclaimed window!");

    }

    FUN_14012e850(&DAT_14039bf30,"Cannot set swapchain parameters on unclaimed window!");

    uVar1 = 0;

  }

  else {

    cVar2 = FUN_1401ccc40(param_1,param_2,param_3);

    if (cVar2 == '\0') {

      if (*(char *)(param_1 + 0x98) != '\0') {

                    /* WARNING: Subroutine does not return */

        FUN_14012e0b0(9,&DAT_14039bf30,"Swapchain composition not supported!");

      }

      FUN_14012e850(&DAT_14039bf30,"Swapchain composition not supported!");

      uVar1 = 0;

    }

    else {

      cVar2 = FUN_1401ccbb0(param_1,param_2,param_4);

      if (cVar2 == '\0') {

        if (*(char *)(param_1 + 0x98) != '\0') {

                    /* WARNING: Subroutine does not return */

          FUN_14012e0b0(9,&DAT_14039bf30,"Present mode not supported!");

        }

        FUN_14012e850(&DAT_14039bf30,"Present mode not supported!");

        uVar1 = 0;

      }

      else if ((param_3 == *(int *)(lVar3 + 0x24)) && (param_4 == *(int *)(lVar3 + 0x20))) {

        uVar1 = 1;

      }

      else {

        FUN_1401cd410(param_1);

        FUN_1401c9cd0(param_1,lVar3);

        uVar1 = FUN_1401c8780(param_1,lVar3,param_3,param_4);

      }

    }

  }

  return uVar1;

}




