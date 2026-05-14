// Address: 0x140191f50
// Ghidra name: FUN_140191f50
// ============ 0x140191f50 FUN_140191f50 (size=106) ============


undefined8 FUN_140191f50(undefined8 *param_1,undefined8 param_2,longlong param_3,ulonglong param_4)



{

  char cVar1;

  

  if (((param_1[0x11] != 0) && (*(int *)(param_1[0x11] + 0x40) == 1)) && (0x7e < param_4)) {

    param_4 = 0x7e;

    *(undefined2 *)(param_3 + 0xfc) = 0;

  }

  cVar1 = (*DAT_1403fcc88)(*param_1,param_2,param_3,(int)param_4 * 2);

  if (cVar1 == '\0') {

    FUN_140196c00(param_1,L"HidD_GetIndexedString");

    return 0xffffffff;

  }

  FUN_140196b60(param_1,0);

  return 0;

}




