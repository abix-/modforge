// Address: 0x1400e73c0
// Ghidra name: FUN_1400e73c0
// ============ 0x1400e73c0 FUN_1400e73c0 (size=934) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined8 FUN_1400e73c0(undefined8 *param_1,longlong param_2,int param_3,int param_4,int param_5)



{

  uint uVar1;

  uint uVar2;

  ulonglong uVar3;

  undefined8 uVar4;

  undefined8 uVar5;

  undefined8 uVar6;

  undefined8 uVar7;

  undefined8 uVar8;

  undefined8 uVar9;

  undefined8 uVar10;

  undefined4 uVar11;

  uint uVar12;

  int iVar13;

  undefined8 uVar14;

  longlong lVar15;

  int iVar16;

  ulonglong uVar17;

  int iVar18;

  int iVar19;

  longlong local_res10;

  int local_res18;

  int local_138;

  int local_134;

  longlong local_110;

  undefined8 local_100;

  undefined8 uStack_f8;

  undefined8 local_f0;

  undefined4 local_e8;

  undefined8 local_e0;

  undefined8 uStack_d8;

  undefined4 local_d0;

  undefined8 local_cc;

  undefined8 local_c0;

  undefined8 uStack_b8;

  undefined4 local_b0;

  undefined4 local_ac;

  undefined4 local_a8;

  undefined8 local_a0;

  undefined8 uStack_98;

  undefined4 local_90;

  undefined4 local_8c;

  undefined4 local_88;

  

  uVar11 = DAT_1403ffc00;

  if (param_5 == 0) {

    uVar14 = FUN_1400e7770();

    return uVar14;

  }

  DAT_1403ffc00 = 0;

  lVar15 = _malloc_base(((int *)*param_1)[1] * *(int *)*param_1 * param_4);

  uVar10 = _UNK_140310278;

  uVar9 = _DAT_140310270;

  uVar8 = _UNK_140310268;

  uVar7 = _DAT_140310260;

  uVar6 = _UNK_140310238;

  uVar5 = _DAT_140310230;

  uVar4 = _UNK_140310228;

  uVar14 = _DAT_140310220;

  local_134 = 0;

  local_110 = 0;

  local_res10 = param_2;

  local_res18 = param_3;

  do {

    local_d0 = 0;

    local_e0 = uVar5;

    uStack_d8 = uVar6;

    local_cc = 1;

    local_b0 = 2;

    local_c0 = uVar7;

    uStack_b8 = uVar8;

    local_ac = 2;

    local_a8 = 1;

    uVar1 = *(uint *)((longlong)&local_c0 + local_110);

    uVar3 = (ulonglong)(~*(uint *)((longlong)&local_e0 + local_110) + uVar1 + *(int *)*param_1) /

            (ulonglong)uVar1;

    local_90 = 4;

    iVar19 = (int)uVar3;

    local_a0 = uVar9;

    uStack_98 = uVar10;

    local_8c = 2;

    local_88 = 2;

    uVar2 = *(uint *)((longlong)&local_a0 + local_110);

    local_100 = uVar14;

    uStack_f8 = uVar4;

    local_f0 = 2;

    local_e8 = 1;

    uVar12 = (((int *)*param_1)[1] + ~*(uint *)((longlong)&local_100 + local_110) + uVar2) / uVar2;

    if ((iVar19 != 0) && (uVar12 != 0)) {

      iVar13 = FUN_1400e7770(param_1,local_res10,param_3,param_4,iVar19,uVar12);

      if (iVar13 == 0) {

        thunk_FUN_1402e9a80(lVar15);

        return 0;

      }

      param_5 = 0;

      if (0 < (int)uVar12) {

        local_138 = 0;

        do {

          if (0 < iVar19) {

            iVar13 = *(int *)((longlong)&local_100 + local_110);

            iVar16 = *(int *)((longlong)&local_e0 + local_110) * param_4;

            uVar17 = uVar3;

            iVar18 = local_138;

            do {

              FUN_1402f8e20((longlong)iVar16 +

                            (ulonglong)((iVar13 + uVar2 * param_5) * *(int *)*param_1 * param_4) +

                            lVar15,(longlong)iVar18 + param_1[3],(longlong)param_4);

              iVar18 = iVar18 + param_4;

              iVar16 = iVar16 + uVar1 * param_4;

              uVar17 = uVar17 - 1;

            } while (uVar17 != 0);

          }

          param_5 = param_5 + 1;

          local_138 = local_138 + iVar19 * param_4;

        } while (param_5 < (int)uVar12);

      }

      thunk_FUN_1402e9a80(param_1[3]);

      iVar19 = (iVar19 * param_4 + 1) * uVar12;

      local_res10 = local_res10 + iVar19;

      local_res18 = local_res18 - iVar19;

      param_3 = local_res18;

    }

    local_134 = local_134 + 1;

    local_110 = local_110 + 4;

  } while (local_134 < 7);

  param_1[3] = lVar15;

  DAT_1403ffc00 = uVar11;

  return 1;

}




