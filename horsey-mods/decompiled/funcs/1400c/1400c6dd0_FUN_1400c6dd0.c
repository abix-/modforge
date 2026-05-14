// Address: 0x1400c6dd0
// Ghidra name: FUN_1400c6dd0
// ============ 0x1400c6dd0 FUN_1400c6dd0 (size=25) ============


ulonglong FUN_1400c6dd0(int param_1,int param_2)



{

  if (-1 < param_1) {

    return (longlong)param_1 / (longlong)param_2 & 0xffffffff;

  }

  return (longlong)((param_1 - param_2) + 1) / (longlong)param_2 & 0xffffffff;

}




