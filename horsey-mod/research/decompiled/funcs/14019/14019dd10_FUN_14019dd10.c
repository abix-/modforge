// Address: 0x14019dd10
// Ghidra name: FUN_14019dd10
// ============ 0x14019dd10 FUN_14019dd10 (size=1033) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined8

FUN_14019dd10(undefined8 *param_1,longlong param_2,int param_3,undefined8 param_4,int param_5,

             undefined4 param_6,int param_7)



{

  uint uVar1;

  uint uVar2;

  undefined4 *puVar3;

  int *piVar4;

  ulonglong uVar5;

  undefined8 uVar6;

  undefined8 uVar7;

  undefined8 uVar8;

  undefined8 uVar9;

  undefined8 uVar10;

  undefined8 uVar11;

  undefined8 uVar12;

  uint uVar13;

  int iVar14;

  undefined8 uVar15;

  longlong lVar16;

  int iVar17;

  int iVar18;

  uint uVar19;

  int iVar20;

  int iVar21;

  ulonglong uVar22;

  longlong local_res10;

  int local_res18;

  int local_138;

  int local_134;

  longlong local_118;

  undefined8 local_108;

  undefined8 uStack_100;

  undefined4 local_f8;

  undefined4 local_f4;

  undefined4 local_f0;

  undefined8 local_e8;

  undefined8 uStack_e0;

  undefined4 local_d8;

  undefined8 local_d4;

  undefined8 local_c8;

  undefined8 uStack_c0;

  undefined4 local_b8;

  undefined4 local_b4;

  undefined4 local_b0;

  undefined8 local_a8;

  undefined8 uStack_a0;

  undefined8 local_98;

  undefined4 local_90;

  

  puVar3 = (undefined4 *)*param_1;

  iVar18 = ((param_5 == 0x10) + 1) * (int)param_4;

  if (param_7 == 0) {

    uVar15 = FUN_14019e120(param_1,param_2,param_3,param_4,*puVar3,puVar3[1],param_5,param_6);

    return uVar15;

  }

  lVar16 = FUN_1401a1b30(*puVar3,puVar3[1],iVar18,0);

  uVar12 = _UNK_140310278;

  uVar11 = _DAT_140310270;

  uVar10 = _UNK_140310268;

  uVar9 = _DAT_140310260;

  uVar8 = _UNK_140310238;

  uVar7 = _DAT_140310230;

  uVar6 = _UNK_140310228;

  uVar15 = _DAT_140310220;

  if (lVar16 == 0) {

    uVar15 = FUN_14019f050("Out of memory");

  }

  else {

    local_134 = 0;

    local_118 = 0;

    local_res10 = param_2;

    local_res18 = param_3;

    do {

      piVar4 = (int *)*param_1;

      local_e8 = uVar7;

      uStack_e0 = uVar8;

      local_d8 = 0;

      local_d4 = 1;

      local_f8 = 2;

      local_108 = uVar9;

      uStack_100 = uVar10;

      local_f4 = 2;

      local_f0 = 1;

      uVar5 = (ulonglong)

              (~*(uint *)((longlong)&local_e8 + local_118) +

               *(uint *)((longlong)&local_108 + local_118) + *piVar4) /

              (ulonglong)*(uint *)((longlong)&local_108 + local_118);

      local_a8 = uVar15;

      uStack_a0 = uVar6;

      local_98 = 2;

      local_90 = 1;

      uVar1 = *(uint *)((longlong)&local_a8 + local_118);

      local_b8 = 4;

      local_b4 = 2;

      local_b0 = 2;

      iVar21 = (int)uVar5;

      local_c8 = uVar11;

      uStack_c0 = uVar12;

      uVar2 = *(uint *)((longlong)&local_c8 + local_118);

      if ((iVar21 != 0) && (uVar13 = (piVar4[1] + ~uVar1 + uVar2) / uVar2, uVar13 != 0)) {

        uVar19 = ((iVar21 * piVar4[2] * param_5 + 7 >> 3) + 1) * uVar13;

        iVar14 = FUN_14019e120(param_1,local_res10,local_res18,(int)param_4,iVar21,uVar13,param_5,

                               param_6);

        if (iVar14 == 0) {

          FUN_1401841e0(lVar16);

          return 0;

        }

        param_7 = 0;

        if (0 < (int)uVar13) {

          local_138 = 0;

          do {

            if (0 < iVar21) {

              iVar14 = *(int *)((longlong)&local_108 + local_118);

              iVar17 = *(int *)((longlong)&local_e8 + local_118) * iVar18;

              uVar22 = uVar5;

              iVar20 = local_138;

              do {

                FUN_1402f8e20((longlong)iVar17 +

                              (ulonglong)((uVar2 * param_7 + uVar1) * *(int *)*param_1 * iVar18) +

                              lVar16,(longlong)iVar20 + param_1[3],(longlong)iVar18);

                iVar20 = iVar20 + iVar18;

                iVar17 = iVar17 + iVar14 * iVar18;

                uVar22 = uVar22 - 1;

              } while (uVar22 != 0);

            }

            param_7 = param_7 + 1;

            local_138 = local_138 + iVar21 * iVar18;

          } while (param_7 < (int)uVar13);

        }

        FUN_1401841e0(param_1[3]);

        local_res18 = local_res18 - uVar19;

        local_res10 = local_res10 + (ulonglong)uVar19;

      }

      local_134 = local_134 + 1;

      local_118 = local_118 + 4;

    } while (local_134 < 7);

    param_1[3] = lVar16;

    uVar15 = 1;

  }

  return uVar15;

}




