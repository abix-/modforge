// Address: 0x1401ccc40
// Ghidra name: FUN_1401ccc40
// ============ 0x1401ccc40 FUN_1401ccc40 (size=230) ============


byte FUN_1401ccc40(longlong param_1,undefined8 param_2,int param_3)



{

  int iVar1;

  longlong lVar2;

  byte local_res18 [16];

  undefined4 local_28;

  uint local_24;

  

  local_28 = *(undefined4 *)(&DAT_1403e4348 + (longlong)param_3 * 4);

  iVar1 = (**(code **)(**(longlong **)(param_1 + 0x70) + 0x68))

                    (*(longlong **)(param_1 + 0x70),3,&local_28,0xc);

  if ((-1 < iVar1) && ((local_24 & 0x80000) != 0)) {

    lVar2 = FUN_1401c9f40(param_2);

    if (lVar2 != 0) {

      if (param_3 != 0) {

        (**(code **)(**(longlong **)(lVar2 + 0x18) + 0x128))

                  (*(longlong **)(lVar2 + 0x18),

                   *(undefined4 *)(&DAT_1403e4358 + (longlong)param_3 * 4),local_res18);

        return local_res18[0] & 1;

      }

      return 1;

    }

    if (*(char *)(param_1 + 0x98) != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(9,&DAT_14039bf30,

                    "Must claim window before querying swapchain composition support!");

    }

    FUN_14012e850(&DAT_14039bf30,"Must claim window before querying swapchain composition support!")

    ;

  }

  return 0;

}




