// Address: 0x14009b740
// Ghidra name: FUN_14009b740
// ============ 0x14009b740 FUN_14009b740 (size=101) ============


bool FUN_14009b740(undefined8 *param_1,char *param_2)



{

  size_t _Size;

  int iVar1;

  size_t sVar2;

  undefined8 *_Buf1;

  

  sVar2 = strlen(param_2);

  _Buf1 = param_1;

  if (0xf < (ulonglong)param_1[3]) {

    _Buf1 = (undefined8 *)*param_1;

  }

  _Size = param_1[2];

  if (_Size != sVar2) {

    return false;

  }

  if (_Size == 0) {

    return true;

  }

  iVar1 = memcmp(_Buf1,param_2,_Size);

  return iVar1 == 0;

}




