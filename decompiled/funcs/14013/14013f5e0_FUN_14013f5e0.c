// Address: 0x14013f5e0
// Ghidra name: FUN_14013f5e0
// ============ 0x14013f5e0 FUN_14013f5e0 (size=184) ============


bool FUN_14013f5e0(undefined4 param_1)



{

  char cVar1;

  longlong lVar2;

  longlong local_res10 [3];

  

  FUN_140159d30();

  if (DAT_1403fbf38 != 0) {

    cVar1 = FUN_1401aaff0(DAT_1403fbf38,param_1,local_res10);

    if (cVar1 != '\0') {

      FUN_14015bb10();

      return local_res10[0] != 0;

    }

  }

  lVar2 = FUN_140140710(param_1,1);

  if (DAT_1403fbf38 == 0) {

    DAT_1403fbf38 = FUN_1401aaee0(0,0,&LAB_1401aa980,&LAB_1401aa9c0,0,0);

    if (DAT_1403fbf38 == 0) goto LAB_14013f685;

  }

  FUN_1401ab100(DAT_1403fbf38,param_1,lVar2 != 0,1);

LAB_14013f685:

  FUN_14015bb10();

  return lVar2 != 0;

}




