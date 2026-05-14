// Address: 0x140263bb0
// Ghidra name: FUN_140263bb0
// ============ 0x140263bb0 FUN_140263bb0 (size=104) ============


longlong FUN_140263bb0(longlong param_1,int *param_2)



{

  longlong lVar1;

  byte bVar2;

  ulonglong uVar3;

  uint7 uVar4;

  

  lVar1 = *(longlong *)(param_1 + 0x70);

  uVar3 = _guard_check_icall();

  uVar3 = uVar3 & 0xffffffffffffff00;

  do {

    if (*param_2 == *(int *)(lVar1 + 4 + (uVar3 & 0xff) * 4)) {

      param_2[0x1c] = 0xc;

      param_2[0x11] = 6;

      param_2[0x39] = (*(char *)((uVar3 & 0xff) + 0x14 + lVar1) != '\0') + 1;

      return 1;

    }

    uVar4 = (uint7)(uVar3 >> 8);

    bVar2 = (char)uVar3 + 1;

    uVar3 = CONCAT71(uVar4,bVar2);

  } while (bVar2 < 4);

  return (ulonglong)uVar4 << 8;

}




