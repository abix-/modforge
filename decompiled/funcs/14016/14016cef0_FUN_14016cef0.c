// Address: 0x14016cef0
// Ghidra name: FUN_14016cef0
// ============ 0x14016cef0 FUN_14016cef0 (size=54) ============


void FUN_14016cef0(void)



{

  longlong lVar1;

  int iVar2;

  

  lVar1 = DAT_1403fc410;

  if (DAT_1403fc410 == 0) {

    FUN_14012e850("Video subsystem has not been initialized");

    return;

  }

  if (((0 < *(int *)(DAT_1403fc410 + 0x410)) &&

      (iVar2 = *(int *)(DAT_1403fc410 + 0x410) + -1, *(int *)(DAT_1403fc410 + 0x410) = iVar2,

      iVar2 < 1)) && (*(code **)(lVar1 + 0x1b0) != (code *)0x0)) {

                    /* WARNING: Could not recover jumptable at 0x00014016cf22. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    (**(code **)(lVar1 + 0x1b0))();

    return;

  }

  return;

}




