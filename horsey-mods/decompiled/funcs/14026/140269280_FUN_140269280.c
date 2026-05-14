// Address: 0x140269280
// Ghidra name: FUN_140269280
// ============ 0x140269280 FUN_140269280 (size=58) ============


int FUN_140269280(longlong *param_1,int param_2)



{

  longlong lVar1;

  

  lVar1 = *param_1;

  if (param_2 == 3) {

    if (*(short *)(lVar1 + 0x22) == 0x2019) {

      return 0xc;

    }

  }

  else if ((param_2 == 0) && (*(short *)(lVar1 + 0x22) == 0x200e)) {

    return (*(int *)(lVar1 + 0x40) != 1) + 1;

  }

  return param_2;

}




