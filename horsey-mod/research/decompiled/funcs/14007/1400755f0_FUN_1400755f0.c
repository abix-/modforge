// Address: 0x1400755f0
// Ghidra name: FUN_1400755f0
// ============ 0x1400755f0 FUN_1400755f0 (size=89) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_1400755f0(undefined8 *param_1)



{

  longlong lVar1;

  

  if (0xf < (ulonglong)param_1[3]) {

    param_1 = (undefined8 *)*param_1;

  }

  lVar1 = FUN_1402ce0f8(param_1,&DAT_14030a390);

  if (lVar1 != 0) {

    FUN_1402d185c(DAT_1403ead28,1,DAT_1403ead20 - _DAT_1403ead18,lVar1);

    FUN_1402ce288(lVar1);

    return;

  }

  return;

}




