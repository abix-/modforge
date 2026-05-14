// Address: 0x1402f8be0
// Ghidra name: FUN_1402f8be0
// ============ 0x1402f8be0 FUN_1402f8be0 (size=43) ============


bool FUN_1402f8be0(short *param_1)



{

  if ((*param_1 == 0x5a4d) &&

     (*(int *)((longlong)*(int *)(param_1 + 0x1e) + (longlong)param_1) == 0x4550)) {

    return (short)((int *)((longlong)*(int *)(param_1 + 0x1e) + (longlong)param_1))[6] == 0x20b;

  }

  return false;

}




