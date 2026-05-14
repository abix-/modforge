// Address: 0x1401a1c40
// Ghidra name: FUN_1401a1c40
// ============ 0x1401a1c40 FUN_1401a1c40 (size=46) ============


bool FUN_1401a1c40(int param_1,uint param_2)



{

  if ((-1 < param_1) && (-1 < (int)param_2)) {

    if (param_2 == 0) {

      return true;

    }

    return param_1 <= (int)(0x7fffffff / (ulonglong)param_2);

  }

  return false;

}




