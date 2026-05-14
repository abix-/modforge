// Address: 0x140218650
// Ghidra name: FUN_140218650
// ============ 0x140218650 FUN_140218650 (size=395) ============


longlong FUN_140218650(void)



{

  char cVar1;

  longlong lVar2;

  

  cVar1 = FUN_140218490("offscreen");

  if (cVar1 != '\0') {

    lVar2 = FUN_1401841a0(1,0x6a8);

    if (lVar2 != 0) {

      *(code **)(lVar2 + 8) = FUN_140218600;

      *(code **)(lVar2 + 0x10) = _guard_check_icall;

      *(code **)(lVar2 + 0x40) = FUN_140018e60;

      *(code **)(lVar2 + 0x250) = _guard_check_icall;

      *(code **)(lVar2 + 0x138) = FUN_140289e50;

      *(code **)(lVar2 + 0x150) = FUN_140289fc0;

      *(code **)(lVar2 + 0x158) = FUN_140289ef0;

      *(code **)(lVar2 + 0x6a0) = FUN_140160120;

      *(undefined1 **)(lVar2 + 0x1e0) = &LAB_14028a0f0;

      *(undefined1 **)(lVar2 + 0x1c0) = &LAB_14028a0d0;

      *(undefined1 **)(lVar2 + 0x1b8) = &LAB_14028a070;

      *(code **)(lVar2 + 0x1e8) = FUN_140218ef0;

      *(code **)(lVar2 + 0x1a0) = FUN_14028a080;

      *(code **)(lVar2 + 0x1b0) = FUN_14021a5f0;

      *(code **)(lVar2 + 0x1a8) = FUN_140219030;

      *(undefined1 **)(lVar2 + 0x1d8) = &LAB_1402190e0;

      *(code **)(lVar2 + 0x1d0) = FUN_14021a4f0;

      *(code **)(lVar2 + 0x1f8) = FUN_14028a270;

      *(code **)(lVar2 + 0x200) = FUN_14022d990;

      *(code **)(lVar2 + 0x208) = FUN_14028a1c0;

      *(code **)(lVar2 + 0x210) = FUN_14028a100;

      *(undefined1 **)(lVar2 + 0x218) = &LAB_14022d700;

      *(code **)(lVar2 + 0x48) = FUN_14028a460;

      *(code **)(lVar2 + 0x130) = FUN_14028a540;

      *(undefined1 **)(lVar2 + 0x68) = &LAB_1402185b0;

      return lVar2;

    }

  }

  return 0;

}




