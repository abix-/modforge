// Address: 0x140179820
// Ghidra name: FUN_140179820
// ============ 0x140179820 FUN_140179820 (size=88) ============


undefined8 FUN_140179820(LPCSTR param_1)



{

  BOOL BVar1;

  longlong lVar2;

  

  if ((param_1 != (LPCSTR)0x0) && (*param_1 != '\0')) {

    lVar2 = thunk_FUN_1402c9190(param_1,0x3d);

    if (lVar2 == 0) {

      if (DAT_1403fc4f8 != 0) {

        FUN_1401795d0(DAT_1403fc4f8,param_1);

      }

      BVar1 = SetEnvironmentVariableA(param_1,(LPCSTR)0x0);

      if (BVar1 != 0) {

        return 0;

      }

    }

  }

  return 0xffffffff;

}




