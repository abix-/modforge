// Address: 0x140169690
// Ghidra name: FUN_140169690
// ============ 0x140169690 FUN_140169690 (size=75) ============


undefined1 FUN_140169690(void)



{

  undefined1 uVar1;

  longlong lVar2;

  

  lVar2 = FUN_14016dcf0();

  if (lVar2 == 0) {

    uVar1 = FUN_1401730c0();

    return uVar1;

  }

  if (*(code **)(lVar2 + 0x2e8) != (code *)0x0) {

                    /* WARNING: Could not recover jumptable at 0x0001401696ba. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    uVar1 = (**(code **)(lVar2 + 0x2e8))(lVar2);

    return uVar1;

  }

  if (*(char **)(lVar2 + 0x388) != (char *)0x0) {

    return **(char **)(lVar2 + 0x388) != '\0';

  }

  return false;

}




