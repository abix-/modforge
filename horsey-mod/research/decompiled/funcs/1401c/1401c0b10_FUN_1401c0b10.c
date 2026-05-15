// Address: 0x1401c0b10
// Ghidra name: FUN_1401c0b10
// ============ 0x1401c0b10 FUN_1401c0b10 (size=140) ============


bool FUN_1401c0b10(longlong param_1,undefined8 param_2)



{

  char cVar1;

  longlong lVar2;

  longlong lVar3;

  

  lVar2 = FUN_1401baca0(param_2);

  if (lVar2 != 0) {

    lVar3 = (ulonglong)*(uint *)(lVar2 + 0xa8) + 0x12;

    if (*(longlong *)(lVar2 + lVar3 * 8) != 0) {

      cVar1 = FUN_1401c0990(param_1,1,lVar2 + lVar3 * 8);

      return cVar1 != '\0';

    }

    return true;

  }

  if (*(char *)(param_1 + 0x57c) != '\0') {

                    /* WARNING: Subroutine does not return */

    FUN_14012e0b0(9,&DAT_14039bf30,"Cannot wait for a swapchain from an unclaimed window!");

  }

  FUN_14012e850(&DAT_14039bf30,"Cannot wait for a swapchain from an unclaimed window!");

  return false;

}




