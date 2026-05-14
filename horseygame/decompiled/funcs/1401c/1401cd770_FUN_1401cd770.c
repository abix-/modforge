// Address: 0x1401cd770
// Ghidra name: FUN_1401cd770
// ============ 0x1401cd770 FUN_1401cd770 (size=137) ============


bool FUN_1401cd770(longlong param_1,undefined8 param_2)



{

  char cVar1;

  longlong lVar2;

  longlong lVar3;

  

  lVar2 = FUN_1401c9f40(param_2);

  if (lVar2 != 0) {

    lVar3 = (ulonglong)*(uint *)(lVar2 + 0x2c) + 0x25;

    if (*(longlong *)(lVar2 + lVar3 * 8) != 0) {

      cVar1 = FUN_1401cd5b0(param_1,1,lVar2 + lVar3 * 8);

      return cVar1 != '\0';

    }

    return true;

  }

  if (*(char *)(param_1 + 0x98) != '\0') {

                    /* WARNING: Subroutine does not return */

    FUN_14012e0b0(9,&DAT_14039bf30,"Cannot wait for a swapchain from an unclaimed window!");

  }

  FUN_14012e850(&DAT_14039bf30,"Cannot wait for a swapchain from an unclaimed window!");

  return false;

}




