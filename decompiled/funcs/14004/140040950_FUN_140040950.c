// Address: 0x140040950
// Ghidra name: FUN_140040950
// ============ 0x140040950 FUN_140040950 (size=37) ============


ulonglong FUN_140040950(undefined8 param_1)



{

  longlong *plVar1;

  

  plVar1 = (longlong *)FUN_140047560(&DAT_1403ea2c0,param_1);

  return plVar1[1] - *plVar1 >> 6 & 0xffffffff;

}




