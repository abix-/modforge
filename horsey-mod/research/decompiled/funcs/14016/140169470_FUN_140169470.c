// Address: 0x140169470
// Ghidra name: FUN_140169470
// ============ 0x140169470 FUN_140169470 (size=87) ============


void FUN_140169470(void)



{

  longlong lVar1;

  undefined1 *puVar2;

  

  lVar1 = FUN_14016dcf0();

  if (lVar1 == 0) {

    FUN_1401730c0();

    FUN_14012f0d0(&DAT_14039bcb9);

    return;

  }

  if (*(code **)(lVar1 + 0x2e0) != (code *)0x0) {

                    /* WARNING: Could not recover jumptable at 0x0001401694a6. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    (**(code **)(lVar1 + 0x2e0))(lVar1);

    return;

  }

  puVar2 = &DAT_14039bcb9;

  if (*(undefined1 **)(lVar1 + 0x388) != (undefined1 *)0x0) {

    puVar2 = *(undefined1 **)(lVar1 + 0x388);

  }

  FUN_14012f0d0(puVar2);

  return;

}




