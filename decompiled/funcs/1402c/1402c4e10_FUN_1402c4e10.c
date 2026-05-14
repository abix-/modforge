// Address: 0x1402c4e10
// Ghidra name: FUN_1402c4e10
// ============ 0x1402c4e10 FUN_1402c4e10 (size=132) ============


undefined8 FUN_1402c4e10(void)



{

  longlong lVar1;

  undefined1 local_28 [40];

  

  if ((DAT_1403fdf68 == 0) && (DAT_1403fdf64 < DAT_1403fdf60)) {

    FUN_14012ef10(local_28,0x20,"SDLasyncio%d",DAT_1403fdf6c);

    lVar1 = FUN_140163260(FUN_1402c4cf0,local_28,0,FUN_1402cfa08,FUN_1402cfae8);

    if (lVar1 == 0) {

      return 0;

    }

    FUN_140163550(lVar1);

    DAT_1403fdf64 = DAT_1403fdf64 + 1;

    DAT_1403fdf6c = DAT_1403fdf6c + 1;

  }

  return 1;

}




