// Address: 0x140228970
// Ghidra name: FUN_140228970
// ============ 0x140228970 FUN_140228970 (size=400) ============


byte FUN_140228970(undefined8 param_1,ulonglong param_2)



{

  bool bVar1;

  longlong lVar2;

  longlong lVar3;

  ulonglong uVar4;

  uint uVar5;

  uint uVar6;

  ulonglong uVar7;

  byte bVar8;

  longlong lVar9;

  ulonglong uVar10;

  bool bVar11;

  longlong local_res18 [2];

  undefined4 local_68;

  undefined4 local_64;

  int local_60;

  undefined8 local_5c;

  int local_54;

  undefined8 local_50;

  undefined8 uStack_48;

  

  uVar7 = 0;

  uVar10 = uVar7;

  if ((*(int *)(param_2 + 4) != 0x16362004) &&

     (param_2 = FUN_140145bb0(param_2,0x16362004), uVar10 = param_2, param_2 == 0)) {

    return 0;

  }

  local_res18[0] = 0;

  lVar2 = FUN_1402273d0(param_2,local_res18);

  lVar9 = local_res18[0];

  if (lVar2 == 0) {

    bVar8 = 0;

  }

  else {

    local_50 = 0;

    uStack_48 = 0;

    local_68 = 0x28;

    local_64 = *(undefined4 *)(param_2 + 8);

    local_60 = *(int *)(param_2 + 0xc) * 2;

    uVar5 = *(int *)(param_2 + 8) * 4;

    local_5c = 0x200001;

    local_54 = uVar5 * *(int *)(param_2 + 0xc) + (int)local_res18[0];

    lVar3 = FUN_14012cbb0(param_1,&local_68,0x28);

    bVar11 = lVar3 == 0x28;

    lVar3 = (longlong)((*(int *)(param_2 + 0xc) + -1) * *(int *)(param_2 + 0x10)) +

            *(longlong *)(param_2 + 0x18);

    if (0 < *(int *)(param_2 + 0xc)) {

      do {

        uVar4 = FUN_14012cbb0(param_1,lVar3,(ulonglong)uVar5);

        bVar1 = false;

        if (uVar4 == uVar5) {

          bVar1 = bVar11;

        }

        bVar11 = bVar1;

        lVar3 = lVar3 - *(int *)(param_2 + 0x10);

        uVar6 = (int)uVar7 + 1;

        uVar7 = (ulonglong)uVar6;

        lVar9 = local_res18[0];

      } while ((int)uVar6 < *(int *)(param_2 + 0xc));

    }

    lVar3 = FUN_14012cbb0(param_1,lVar2,lVar9);

    bVar8 = bVar11 & lVar3 == lVar9;

  }

  FUN_1401841e0(lVar2);

  FUN_140146010(uVar10);

  return bVar8;

}




