// Address: 0x140284770
// Ghidra name: FUN_140284770
// ============ 0x140284770 FUN_140284770 (size=130) ============


undefined8 FUN_140284770(longlong param_1)



{

  longlong lVar1;

  

  DAT_1403fddb8 = FUN_140179a30();

  if (DAT_1403fddb8 != 0) {

    lVar1 = FUN_14017cda0(0);

    *(longlong *)(param_1 + 0x10) = lVar1;

    if (lVar1 != 0) {

      FUN_140139010(param_1 + 4,1);

      lVar1 = FUN_140163260(FUN_140284470,"HIDAPI Rumble",param_1,FUN_1402cfa08,FUN_1402cfae8);

      *(longlong *)(param_1 + 8) = lVar1;

      if (lVar1 != 0) {

        return 1;

      }

    }

  }

  FUN_140284800(param_1);

  return 0;

}




