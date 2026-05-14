// Address: 0x140208080
// Ghidra name: FUN_140208080
// ============ 0x140208080 FUN_140208080 (size=139) ============


bool FUN_140208080(short param_1,short param_2,longlong param_3)



{

  int iVar1;

  char cVar2;

  

  if ((param_1 == *(short *)(param_3 + 0x20)) && (param_2 == *(short *)(param_3 + 0x22))) {

    return true;

  }

  if (param_1 == 0x45e) {

    if (param_2 == 0x2a1) {

      if (*(short *)(param_3 + 0x22) == 0x719) {

        return true;

      }

      iVar1 = *(int *)(param_3 + 0x5c);

      if (iVar1 == 2) {

        return true;

      }

    }

    else {

      if (param_2 != 0x2ff) {

        return false;

      }

      iVar1 = *(int *)(param_3 + 0x5c);

    }

    if (iVar1 == 3) {

      return true;

    }

  }

  else if ((param_1 == 0x955) && (param_2 == -0x4c00)) {

    cVar2 = FUN_140159500(0x955,0xb400);

    return cVar2 != '\0';

  }

  return false;

}




