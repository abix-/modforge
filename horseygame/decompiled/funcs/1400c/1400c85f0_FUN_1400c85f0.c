// Address: 0x1400c85f0
// Ghidra name: FUN_1400c85f0
// ============ 0x1400c85f0 FUN_1400c85f0 (size=249) ============


void FUN_1400c85f0(longlong *param_1,ulonglong param_2)



{

  ulonglong uVar1;

  longlong lVar2;

  longlong lVar3;

  longlong lVar4;

  undefined1 local_res8 [8];

  

  lVar2 = param_1[1];

  lVar4 = *param_1;

  uVar1 = (lVar2 - lVar4) / 0x88;

  if (param_2 < uVar1) {

    lVar4 = param_2 * 0x88 + lVar4;

    for (lVar3 = lVar4; lVar3 != lVar2; lVar3 = lVar3 + 0x88) {

      thunk_FUN_1400308d0(lVar3 + 0x70);

      FUN_140027900(lVar3 + 0x20);

      FUN_140027900(lVar3);

    }

    param_1[1] = lVar4;

    return;

  }

  if (uVar1 < param_2) {

    if ((ulonglong)((param_1[2] - lVar4) / 0x88) < param_2) {

      FUN_1400c8220(param_1,param_2,local_res8);

      return;

    }

    lVar2 = FUN_1400c8570(lVar2,param_2 - uVar1,param_1);

    param_1[1] = lVar2;

  }

  return;

}




