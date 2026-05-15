// Address: 0x1400c6df0
// Ghidra name: FUN_1400c6df0
// ============ 0x1400c6df0 FUN_1400c6df0 (size=32) ============


ulonglong FUN_1400c6df0(uint param_1,int param_2)



{

  if (-1 < (int)param_1) {

    return (longlong)(int)param_1 % (longlong)param_2 & 0xffffffff;

  }

  return (ulonglong)((param_2 - (int)~param_1 % param_2) - 1);

}




