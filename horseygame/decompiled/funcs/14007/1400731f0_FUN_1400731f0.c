// Address: 0x1400731f0
// Ghidra name: FUN_1400731f0
// ============ 0x1400731f0 FUN_1400731f0 (size=195) ============


void FUN_1400731f0(longlong *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,

                  undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)



{

  int iVar1;

  longlong lVar2;

  longlong lVar3;

  

  lVar3 = 3;

  iVar1 = FUN_140075290(param_1,3);

  FUN_140073b40(*param_1 + (longlong)iVar1 * 0x20,param_2,param_3,param_4,param_5,param_6,param_7,

                param_8);

  lVar2 = (longlong)iVar1 * 0x20 + *param_1;

  do {

    FUN_1400745d0(lVar2);

    lVar2 = lVar2 + 0x20;

    lVar3 = lVar3 + -1;

  } while (lVar3 != 0);

  return;

}




