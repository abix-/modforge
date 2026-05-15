// Address: 0x140073360
// Ghidra name: FUN_140073360
// ============ 0x140073360 FUN_140073360 (size=180) ============


void FUN_140073360(longlong *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,

                  undefined4 param_5,undefined4 param_6,undefined4 param_7)



{

  int iVar1;

  longlong lVar2;

  longlong lVar3;

  

  lVar3 = 6;

  iVar1 = FUN_140075290(param_1,6);

  FUN_140073780(*param_1 + (longlong)iVar1 * 0x20,param_2,param_3,param_4,param_5,param_6,param_7);

  lVar2 = (longlong)iVar1 * 0x20 + *param_1;

  do {

    FUN_1400745d0(lVar2);

    lVar2 = lVar2 + 0x20;

    lVar3 = lVar3 + -1;

  } while (lVar3 != 0);

  return;

}




