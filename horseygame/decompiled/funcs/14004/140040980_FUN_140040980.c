// Address: 0x140040980
// Ghidra name: FUN_140040980
// ============ 0x140040980 FUN_140040980 (size=74) ============


undefined4 FUN_140040980(undefined8 param_1,int param_2)



{

  longlong *plVar1;

  

  plVar1 = (longlong *)FUN_140047560(&DAT_1403ea2c0,param_1);

  if ((-1 < param_2) && (param_2 < (int)(plVar1[1] - *plVar1 >> 6))) {

    return *(undefined4 *)((longlong)param_2 * 0x40 + 0x34 + *plVar1);

  }

  return 0xffffffff;

}




