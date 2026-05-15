// Address: 0x14015d510
// Ghidra name: FUN_14015d510
// ============ 0x14015d510 FUN_14015d510 (size=86) ============


bool FUN_14015d510(int param_1,void *param_2,void *param_3)



{

  int iVar1;

  

  if (param_2 != param_3) {

    if ((param_2 != (void *)0x0) != (param_3 != (void *)0x0)) {

      return false;

    }

    if (param_2 != (void *)0x0) {

      iVar1 = memcmp(param_2,param_3,(longlong)param_1 << 2);

      return iVar1 == 0;

    }

  }

  return true;

}




