// Address: 0x140130a00
// Ghidra name: FUN_140130a00
// ============ 0x140130a00 FUN_140130a00 (size=133) ============


ulonglong FUN_140130a00(uint *param_1)



{

  uint uVar1;

  ulonglong uVar2;

  

  uVar1 = *param_1;

  uVar2 = (longlong)(int)param_1[3] * (longlong)(int)param_1[2];

  if ((((uVar1 == 0x3132564e) || (uVar1 == 0x3231564e)) || (uVar1 == 0x32315659)) ||

     (uVar1 == 0x56555949)) {

    return (uVar2 >> 1) + uVar2;

  }

  if ((uVar1 == 0) || ((uVar1 & 0xf0000000) == 0x10000000)) {

    return (uVar1 & 0xff) * uVar2;

  }

  if (((uVar1 != 0x32595559) && (uVar1 != 0x59565955)) &&

     ((uVar1 != 0x55595659 && (uVar1 != 0x30313050)))) {

    return uVar2;

  }

  return uVar2 * 2;

}




