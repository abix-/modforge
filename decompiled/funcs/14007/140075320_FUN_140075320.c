// Address: 0x140075320
// Ghidra name: FUN_140075320
// ============ 0x140075320 FUN_140075320 (size=199) ============


void FUN_140075320(longlong *param_1,ulonglong param_2)



{

  ulonglong uVar1;

  longlong lVar2;

  longlong lVar3;

  undefined1 local_res8 [8];

  

  lVar3 = param_1[1];

  lVar2 = *param_1;

  uVar1 = (lVar3 - lVar2) / 0x38;

  if (param_2 < uVar1) {

    param_1[1] = param_2 * 0x38 + lVar2;

    return;

  }

  if (uVar1 < param_2) {

    if ((ulonglong)((param_1[2] - lVar2) / 0x38) < param_2) {

      FUN_140074da0(param_1,param_2,local_res8);

      return;

    }

    if (param_2 - uVar1 != 0) {

      lVar2 = (param_2 - uVar1) * 0x38;

      FUN_1402f94c0(lVar3,0,lVar2);

      lVar3 = lVar3 + lVar2;

    }

    param_1[1] = lVar3;

  }

  return;

}




