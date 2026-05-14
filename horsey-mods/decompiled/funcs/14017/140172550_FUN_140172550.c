// Address: 0x140172550
// Ghidra name: FUN_140172550
// ============ 0x140172550 FUN_140172550 (size=87) ============


ulonglong FUN_140172550(ulonglong param_1)



{

  uint uVar1;

  ulonglong uVar2;

  ulonglong uVar3;

  

  uVar2 = *(ulonglong *)(param_1 + 0x1a8);

  uVar1 = *(uint *)(uVar2 + 0x48);

  while ((uVar1 & 0xc0000) != 0) {

    uVar2 = *(ulonglong *)(uVar2 + 0x1a8);

    uVar1 = *(uint *)(uVar2 + 0x48);

  }

  uVar3 = *(ulonglong *)(uVar2 + 400);

  while( true ) {

    if (uVar3 == uVar2) {

      return CONCAT71((int7)(uVar3 >> 8),1);

    }

    if (uVar3 == param_1) break;

    uVar3 = *(ulonglong *)(uVar3 + 0x1a8);

  }

  return uVar3 & 0xffffffffffffff00;

}




