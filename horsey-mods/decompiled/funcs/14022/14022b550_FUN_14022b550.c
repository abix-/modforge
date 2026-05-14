// Address: 0x14022b550
// Ghidra name: FUN_14022b550
// ============ 0x14022b550 FUN_14022b550 (size=153) ============


longlong FUN_14022b550(undefined8 param_1,longlong param_2,undefined8 param_3)



{

  longlong lVar1;

  longlong lVar2;

  

  lVar2 = *(longlong *)(param_2 + 0x188);

  lVar1 = FUN_14012fd40(*(undefined8 *)(lVar2 + 0xb0));

  lVar2 = FUN_140197820(&DAT_14039c6f0,"UTF-16LE",*(undefined8 *)(lVar2 + 0xb0),lVar1 * 2 + 2);

  if (lVar2 != 0) {

    lVar1 = FUN_14012c650(lVar2,param_3);

    if (lVar1 == 0) {

      FUN_14012e850("Could not open ICC profile");

    }

    FUN_1401841e0(lVar2);

    return lVar1;

  }

  return 0;

}




