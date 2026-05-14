// Address: 0x140228100
// Ghidra name: FUN_140228100
// ============ 0x140228100 FUN_140228100 (size=140) ============


undefined8 FUN_140228100(undefined4 param_1)



{

  HCURSOR pHVar1;

  undefined8 uVar2;

  LPCWSTR lpCursorName;

  

  switch(param_1) {

  case 0:

    lpCursorName = (LPCWSTR)0x7f00;

    break;

  case 1:

    lpCursorName = (LPCWSTR)0x7f01;

    break;

  case 2:

    lpCursorName = (LPCWSTR)0x7f02;

    break;

  case 3:

    lpCursorName = (LPCWSTR)0x7f03;

    break;

  case 4:

    lpCursorName = (LPCWSTR)0x7f8a;

    break;

  case 5:

  case 0xc:

  case 0x10:

    lpCursorName = (LPCWSTR)0x7f82;

    break;

  case 6:

  case 0xe:

  case 0x12:

    lpCursorName = (LPCWSTR)0x7f83;

    break;

  case 7:

  case 0xf:

  case 0x13:

    lpCursorName = (LPCWSTR)0x7f84;

    break;

  case 8:

  case 0xd:

  case 0x11:

    lpCursorName = (LPCWSTR)0x7f85;

    break;

  case 9:

    lpCursorName = (LPCWSTR)0x7f86;

    break;

  case 10:

    lpCursorName = (LPCWSTR)0x7f88;

    break;

  case 0xb:

    lpCursorName = (LPCWSTR)0x7f89;

    break;

  default:

    return 0;

  }

  pHVar1 = LoadCursorW((HINSTANCE)0x0,lpCursorName);

  uVar2 = FUN_140228070(pHVar1);

  return uVar2;

}




