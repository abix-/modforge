// Address: 0x1401925a0
// Ghidra name: FUN_1401925a0
// ============ 0x1401925a0 FUN_1401925a0 (size=181) ============


bool FUN_1401925a0(uint param_1,ushort param_2,WORD param_3)



{

  BOOL BVar1;

  undefined8 uVar2;

  DWORDLONG dwlConditionMask;

  _OSVERSIONINFOEXW local_128;

  

  uVar2 = VerSetConditionMask(0,2,3);

  uVar2 = VerSetConditionMask(uVar2,1,3);

  dwlConditionMask = VerSetConditionMask(uVar2,0x20,3);

  FUN_1402f94c0(&local_128,0,0x11c);

  local_128.dwOSVersionInfoSize = 0x11c;

  local_128.dwMinorVersion = (DWORD)param_2;

  local_128.dwMajorVersion = param_1 & 0xffff;

  local_128.wServicePackMajor = param_3;

  BVar1 = VerifyVersionInfoW(&local_128,0x23,dwlConditionMask);

  return BVar1 != 0;

}




