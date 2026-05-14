// Address: 0x14026bf00
// Ghidra name: FUN_14026bf00
// ============ 0x14026bf00 FUN_14026bf00 (size=77) ============


ulonglong FUN_14026bf00(ulonglong *param_1)



{

  short *psVar1;

  short sVar2;

  uint uVar3;

  ulonglong uVar4;

  bool bVar5;

  

  uVar4 = *param_1;

  sVar2 = *(short *)(uVar4 + 0x20);

  psVar1 = (short *)(uVar4 + 0x22);

  if (sVar2 == 0) {

    bVar5 = *psVar1 == 0;

LAB_14026bf2a:

    if (bVar5) goto LAB_14026bf4a;

  }

  else if (sVar2 == 0xf0d) {

    uVar4 = 0;

    bVar5 = *psVar1 == 0xf6;

    goto LAB_14026bf2a;

  }

  uVar3 = (uint)param_1[4];

  uVar4 = (ulonglong)uVar3;

  if (((uVar3 != 0) && (uVar3 != 6)) && ((sVar2 != 0x57e || ((int)uVar3 < 4)))) {

    return CONCAT71((uint7)(uint3)(uVar3 >> 8),1);

  }

LAB_14026bf4a:

  return uVar4 & 0xffffffffffffff00;

}




