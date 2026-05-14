// Address: 0x14017eb50
// Ghidra name: FUN_14017eb50
// ============ 0x14017eb50 FUN_14017eb50 (size=30) ============


ulonglong FUN_14017eb50(uint param_1)



{

  uint uVar1;

  ulonglong uVar2;

  

  uVar1 = 0x1f;

  if (param_1 != 0) {

    for (; param_1 >> uVar1 == 0; uVar1 = uVar1 - 1) {

    }

  }

  uVar2 = (ulonglong)uVar1;

  if (((param_1 != 0) && (-1 < (int)uVar1)) &&

     (uVar2 = (ulonglong)(int)uVar1, (&DAT_1403fc648)[uVar2] == '\0')) {

    return CONCAT71((int7)(int3)(uVar1 >> 8),1);

  }

  return uVar2 & 0xffffffffffffff00;

}




