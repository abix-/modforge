// Address: 0x1402184d0
// Ghidra name: FUN_1402184d0
// ============ 0x1402184d0 FUN_1402184d0 (size=170) ============


longlong FUN_1402184d0(void)



{

  char cVar1;

  longlong lVar2;

  

  cVar1 = FUN_140218490();

  if (cVar1 != '\0') {

    lVar2 = FUN_1401841a0(1,0x6a8);

    if (lVar2 != 0) {

      *(undefined1 *)(lVar2 + 0x319) = 1;

      *(code **)(lVar2 + 8) = FUN_1402185d0;

      *(code **)(lVar2 + 0x10) = _guard_check_icall;

      *(code **)(lVar2 + 0x250) = _guard_check_icall;

      *(undefined1 **)(lVar2 + 0x68) = &LAB_1402185b0;

      *(code **)(lVar2 + 0x60) = FUN_140218580;

      *(code **)(lVar2 + 0x138) = FUN_140289e50;

      *(code **)(lVar2 + 0x150) = FUN_140289f10;

      *(code **)(lVar2 + 0x158) = FUN_140289ef0;

      *(code **)(lVar2 + 0x6a0) = FUN_140160120;

      return lVar2;

    }

  }

  return 0;

}




