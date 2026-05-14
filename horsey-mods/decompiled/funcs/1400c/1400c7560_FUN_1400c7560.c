// Address: 0x1400c7560
// Ghidra name: FUN_1400c7560
// ============ 0x1400c7560 FUN_1400c7560 (size=140) ============


undefined8 * FUN_1400c7560(undefined8 *param_1)



{

  char *_Str;

  size_t sVar1;

  

  DAT_1403f34a8 = DAT_1403f34a8 + 1;

  if ((ulonglong)(DAT_1403f34d0 - DAT_1403f34c8 >> 2) <= (ulonglong)(longlong)DAT_1403f34a8) {

    DAT_1403f34a8 = 0;

  }

  _Str = *(char **)(DAT_1403f34f8 +

                   (longlong)*(int *)(DAT_1403f34c8 + (longlong)DAT_1403f34a8 * 4) * 8);

  *param_1 = 0;

  param_1[1] = 0;

  param_1[2] = 0;

  param_1[3] = 0;

  sVar1 = strlen(_Str);

  FUN_140027e30(param_1,_Str,sVar1);

  return param_1;

}




