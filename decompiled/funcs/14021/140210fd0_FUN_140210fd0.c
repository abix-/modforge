// Address: 0x140210fd0
// Ghidra name: FUN_140210fd0
// ============ 0x140210fd0 FUN_140210fd0 (size=48) ============


undefined8 FUN_140210fd0(int param_1,uint param_2)



{

  uint uVar1;

  uint *puVar2;

  

  puVar2 = &DAT_140350d60;

  uVar1 = 0;

  do {

    if ((param_1 << 0x10 | param_2) == *puVar2) {

      return *(undefined8 *)(&DAT_140350d68 + (longlong)(int)uVar1 * 0x10);

    }

    uVar1 = uVar1 + 1;

    puVar2 = puVar2 + 4;

  } while (uVar1 < 0x238);

  return 0;

}




