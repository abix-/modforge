// Address: 0x14021a810
// Ghidra name: FUN_14021a810
// ============ 0x14021a810 FUN_14021a810 (size=161) ============


void FUN_14021a810(void)



{

  char cVar1;

  uint uVar2;

  undefined1 *puVar3;

  ulonglong uVar4;

  undefined1 local_808 [2048];

  

  uVar2 = FUN_14013afe0(local_808,0x10,2,0,0xffff);

  while (0 < (int)uVar2) {

    puVar3 = local_808;

    uVar4 = (ulonglong)uVar2;

    do {

      cVar1 = FUN_14021aaa0(puVar3);

      if (cVar1 == '\0') {

        FUN_14021a7c0(puVar3);

      }

      puVar3 = puVar3 + 0x80;

      uVar4 = uVar4 - 1;

    } while (uVar4 != 0);

    uVar2 = FUN_14013afe0(local_808,0x10,2,0,0xffff);

  }

  return;

}




