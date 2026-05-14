// Address: 0x140178b70
// Ghidra name: FUN_140178b70
// ============ 0x140178b70 FUN_140178b70 (size=85) ============


longlong FUN_140178b70(uint param_1)



{

  longlong lVar1;

  

  if ((-1 < (int)param_1) && (param_1 < 0xb)) {

    lVar1 = (&DAT_1403fc4a0)[(int)param_1];

    if (lVar1 == 0) {

      lVar1 = FUN_14021ca00();

      (&DAT_1403fc4a0)[(int)param_1] = lVar1;

    }

    return lVar1;

  }

  FUN_14012e850("Parameter \'%s\' is invalid","folder");

  return 0;

}




