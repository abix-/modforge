// Address: 0x14012f390
// Ghidra name: FUN_14012f390
// ============ 0x14012f390 FUN_14012f390 (size=80) ============


longlong FUN_14012f390(undefined8 param_1)



{

  longlong lVar1;

  longlong lVar2;

  

  lVar1 = FUN_14012f3e0();

  lVar2 = FUN_1401841f0(lVar1 + 1);

  if (lVar2 != 0) {

    FUN_1402f8e20(lVar2,param_1,lVar1);

    *(undefined1 *)(lVar2 + lVar1) = 0;

  }

  return lVar2;

}




