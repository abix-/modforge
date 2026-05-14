// Address: 0x1400732c0
// Ghidra name: FUN_1400732c0
// ============ 0x1400732c0 FUN_1400732c0 (size=148) ============


void FUN_1400732c0(longlong *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,

                  undefined4 param_5)



{

  int iVar1;

  longlong lVar2;

  longlong lVar3;

  

  lVar3 = 0x30;

  iVar1 = FUN_140075290(param_1,0x30);

  FUN_140073c30(*param_1 + (longlong)iVar1 * 0x20,param_2,param_3,param_4,param_5);

  lVar2 = (longlong)iVar1 * 0x20 + *param_1;

  do {

    FUN_1400745d0(lVar2);

    lVar2 = lVar2 + 0x20;

    lVar3 = lVar3 + -1;

  } while (lVar3 != 0);

  return;

}




