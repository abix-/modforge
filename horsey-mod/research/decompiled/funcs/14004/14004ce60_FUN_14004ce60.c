// Address: 0x14004ce60
// Ghidra name: FUN_14004ce60
// ============ 0x14004ce60 FUN_14004ce60 (size=119) ============


undefined8 FUN_14004ce60(longlong param_1,void *param_2,int param_3)



{

  longlong lVar1;

  size_t sVar2;

  

  sVar2 = (size_t)param_3;

  lVar1 = *(longlong *)(param_1 + 0x40);

  if (lVar1 == 0) {

    sVar2 = fread(param_2,sVar2,1,*(FILE **)(param_1 + 0x30));

    if (sVar2 != 1) goto LAB_14004cec0;

  }

  else {

    if (*(ulonglong *)(param_1 + 0x50) < lVar1 + sVar2) {

LAB_14004cec0:

      *(undefined4 *)(param_1 + 0x98) = 1;

      return 0;

    }

    FUN_1402f8e20(param_2,lVar1,sVar2);

    *(longlong *)(param_1 + 0x40) = *(longlong *)(param_1 + 0x40) + sVar2;

  }

  return 1;

}




