// Address: 0x1401648f0
// Ghidra name: FUN_1401648f0
// ============ 0x1401648f0 FUN_1401648f0 (size=66) ============


longlong FUN_1401648f0(longlong param_1,int param_2,longlong param_3)



{

  longlong lVar1;

  

  lVar1 = FUN_140214330((int)((float)param_2 * *(float *)(param_1 + 0x58)),

                        *(undefined4 *)(param_1 + 0x44));

  if ((lVar1 == 0x100000000) && (param_3 == 0)) {

    lVar1 = 0;

  }

  return lVar1;

}




