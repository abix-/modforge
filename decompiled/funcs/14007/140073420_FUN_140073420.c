// Address: 0x140073420
// Ghidra name: FUN_140073420
// ============ 0x140073420 FUN_140073420 (size=146) ============


void FUN_140073420(longlong *param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,

                  undefined8 param_5)



{

  int iVar1;

  longlong lVar2;

  longlong lVar3;

  

  lVar3 = 6;

  iVar1 = FUN_140075290(param_1,6);

  FUN_140074020(*param_1 + (longlong)iVar1 * 0x20,param_2,param_3,param_4,param_5);

  lVar2 = (longlong)iVar1 * 0x20 + *param_1;

  do {

    FUN_1400745d0(lVar2);

    lVar2 = lVar2 + 0x20;

    lVar3 = lVar3 + -1;

  } while (lVar3 != 0);

  return;

}




