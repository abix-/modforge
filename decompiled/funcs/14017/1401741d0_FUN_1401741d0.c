// Address: 0x1401741d0
// Ghidra name: FUN_1401741d0
// ============ 0x1401741d0 FUN_1401741d0 (size=54) ============


void FUN_1401741d0(void)



{

  longlong lVar1;

  int iVar2;

  

  lVar1 = DAT_1403fc410;

  if (DAT_1403fc410 == 0) {

    FUN_14012e850("Video subsystem has not been initialized");

    return;

  }

  if (((0 < *(int *)(DAT_1403fc410 + 0x570)) &&

      (iVar2 = *(int *)(DAT_1403fc410 + 0x570) + -1, *(int *)(DAT_1403fc410 + 0x570) = iVar2,

      iVar2 < 1)) && (*(code **)(lVar1 + 0x200) != (code *)0x0)) {

                    /* WARNING: Could not recover jumptable at 0x000140174202. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    (**(code **)(lVar1 + 0x200))();

    return;

  }

  return;

}




