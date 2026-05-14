// Address: 0x14016d5f0
// Ghidra name: FUN_14016d5f0
// ============ 0x14016d5f0 FUN_14016d5f0 (size=117) ============


ulonglong FUN_14016d5f0(int param_1)



{

  ulonglong uVar1;

  undefined8 *puVar2;

  ulonglong uVar3;

  

  if (DAT_1403fc410 == 0) {

    FUN_1401730c0();

    return 0xffffffff;

  }

  uVar1 = 0;

  if (0 < *(int *)(DAT_1403fc410 + 0x328)) {

    puVar2 = *(undefined8 **)(DAT_1403fc410 + 0x330);

    uVar3 = uVar1;

    do {

      if (param_1 == *(int *)*puVar2) {

        return uVar3;

      }

      uVar3 = (ulonglong)((int)uVar3 + 1);

      uVar1 = uVar1 + 1;

      puVar2 = puVar2 + 1;

    } while ((longlong)uVar1 < (longlong)*(int *)(DAT_1403fc410 + 0x328));

  }

  FUN_14012e850("Invalid display");

  return 0xffffffff;

}




