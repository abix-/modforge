// Address: 0x14019c9d0
// Ghidra name: FUN_14019c9d0
// ============ 0x14019c9d0 FUN_14019c9d0 (size=69) ============


bool FUN_14019c9d0(uint param_1,uint param_2)



{

  if ((int)(~param_1 ^ ~param_2) < 0) {

    return true;

  }

  if (((int)param_1 < 0) && ((int)param_2 < 0)) {

    return (int)(-0x80000000 - param_2) <= (int)param_1;

  }

  return (int)param_1 <= (int)(0x7fffffff - param_2);

}




