// Address: 0x14017eb70
// Ghidra name: FUN_14017eb70
// ============ 0x14017eb70 FUN_14017eb70 (size=58) ============


ulonglong FUN_14017eb70(uint param_1)



{

  uint uVar1;

  ulonglong uVar2;

  longlong lVar3;

  

  uVar1 = 0x1f;

  if (param_1 != 0) {

    for (; param_1 >> uVar1 == 0; uVar1 = uVar1 - 1) {

    }

  }

  uVar2 = (ulonglong)uVar1;

  if (param_1 == 0) {

    uVar2 = 0xffffffff;

LAB_14017eb91:

    lVar3 = (longlong)(int)uVar2;

  }

  else {

    if ((int)uVar1 < 0) goto LAB_14017eb91;

    lVar3 = (longlong)(int)uVar1;

    if ((&DAT_1403fc648)[lVar3] == '\0') goto LAB_14017eb89;

  }

  if (((-1 < (int)uVar2) && ((&DAT_1403fc648)[lVar3] == '\x01')) || (DAT_1403fc640 != '\0')) {

    return CONCAT71((int7)(uVar2 >> 8),1);

  }

LAB_14017eb89:

  return uVar2 & 0xffffffffffffff00;

}




