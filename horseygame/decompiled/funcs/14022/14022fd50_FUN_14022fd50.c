// Address: 0x14022fd50
// Ghidra name: FUN_14022fd50
// ============ 0x14022fd50 FUN_14022fd50 (size=76) ============


longlong FUN_14022fd50(longlong param_1,int param_2)



{

  longlong lVar1;

  longlong lVar2;

  undefined8 *puVar3;

  

  if ((param_1 != 0) && (0 < param_2)) {

    lVar2 = 0;

    puVar3 = (undefined8 *)(param_1 + 8);

    do {

      lVar1 = FUN_14022fda0(*puVar3);

      if (lVar1 != 0) {

        return lVar1;

      }

      lVar2 = lVar2 + 1;

      puVar3 = puVar3 + 2;

    } while (lVar2 < param_2);

  }

  return 0;

}




