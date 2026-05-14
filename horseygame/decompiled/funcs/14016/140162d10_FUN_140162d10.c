// Address: 0x140162d10
// Ghidra name: FUN_140162d10
// ============ 0x140162d10 FUN_140162d10 (size=246) ============


undefined1 FUN_140162d10(char param_1)



{

  undefined1 uVar1;

  char cVar2;

  longlong lVar3;

  longlong lVar4;

  

  lVar3 = FUN_1401611a0();

  lVar4 = FUN_140183290();

  if (param_1 == '\0') {

    *(undefined1 *)(lVar3 + 0xc6) = 0;

  }

  if (param_1 == *(char *)(lVar3 + 0xc1)) {

    return 1;

  }

  if (*(code **)(lVar3 + 0x40) == (code *)0x0) {

    uVar1 = FUN_14012e850("That operation is not supported");

    return uVar1;

  }

  cVar2 = (**(code **)(lVar3 + 0x40))(param_1);

  if (cVar2 == '\0') {

    return 0;

  }

  *(char *)(lVar3 + 0xc1) = param_1;

  if (param_1 == '\0') {

    if (lVar4 != 0) {

      FUN_1401735a0(lVar4);

      FUN_1401618c0(lVar4,*(undefined4 *)(lVar3 + 0x90),*(undefined4 *)(lVar3 + 0x94),1);

      goto LAB_140162dd9;

    }

  }

  else {

    FUN_140162700();

    if (lVar4 == 0) goto LAB_140162dea;

    FUN_140162ca0(lVar4);

    FUN_1401735a0(lVar4);

LAB_140162dd9:

    FUN_140162f40(0);

    if (param_1 != '\0') goto LAB_140162dea;

  }

  FUN_140162700();

LAB_140162dea:

  FUN_140139550(0x400);

  return 1;

}




