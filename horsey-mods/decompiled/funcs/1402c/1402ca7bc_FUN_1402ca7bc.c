// Address: 0x1402ca7bc
// Ghidra name: FUN_1402ca7bc
// ============ 0x1402ca7bc FUN_1402ca7bc (size=1331) ============


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */



void FUN_1402ca7bc(int *param_1,undefined8 param_2,undefined8 param_3,longlong param_4,byte *param_5

                  ,char param_6,undefined4 param_7,longlong *param_8)



{

  byte bVar1;

  int iVar2;

  uint uVar3;

  undefined4 uVar4;

  undefined8 uVar5;

  char cVar6;

  int iVar7;

  int iVar8;

  longlong lVar9;

  uint uVar10;

  byte *pbVar11;

  byte *pbVar12;

  byte *pbVar13;

  longlong lVar14;

  int iVar15;

  int *piVar16;

  undefined1 auStack_1c8 [32];

  byte *local_1a8;

  undefined8 *local_1a0;

  longlong local_198;

  longlong *local_190;

  undefined4 local_188;

  longlong *local_180;

  undefined1 local_178;

  char local_170;

  undefined1 local_168;

  uint local_164;

  int local_160;

  undefined8 local_158;

  int local_150;

  longlong local_148;

  longlong local_140;

  undefined8 uStack_138;

  longlong *local_128;

  undefined8 local_120;

  longlong local_118;

  undefined8 uStack_110;

  uint local_100;

  undefined8 local_f8;

  undefined8 uStack_f0;

  undefined4 local_e8;

  undefined4 uStack_e4;

  undefined4 uStack_e0;

  undefined4 uStack_dc;

  undefined8 local_d8;

  int local_d0 [10];

  int local_a8 [6];

  undefined8 local_90;

  undefined8 uStack_88;

  undefined4 local_80;

  undefined4 uStack_7c;

  undefined4 uStack_78;

  undefined4 uStack_74;

  undefined8 local_70;

  ulonglong local_58;

  

  local_58 = DAT_1403e8b00 ^ (ulonglong)auStack_1c8;

  local_128 = param_8;

  local_168 = 0;

  local_158 = param_3;

  local_120 = param_2;

  iVar7 = FUN_1402c9a44(param_5,param_4);

  if (*(int *)(param_4 + 0x48) == 0) {

    lVar9 = FUN_1402c97f8();

    if (*(int *)(lVar9 + 0x78) != -2) {

      lVar9 = FUN_1402c97f8();

      iVar7 = *(int *)(lVar9 + 0x78);

      lVar9 = FUN_1402c97f8();

      *(undefined4 *)(lVar9 + 0x78) = 0xfffffffe;

    }

  }

  else {

    lVar9 = FUN_1402c97f8();

    if (*(int *)(lVar9 + 0x78) != -2) goto LAB_1402caced;

    iVar7 = *(int *)(param_4 + 0x48) + -2;

  }

  if (-2 < iVar7) {

    if (*(int *)(param_5 + 8) == 0) {

      uVar10 = 0;

    }

    else {

      pbVar11 = (byte *)(*(longlong *)(param_4 + 8) + (longlong)*(int *)(param_5 + 8));

      uVar10 = *pbVar11 & 0xf;

      uVar10 = *(uint *)(pbVar11 + (-4 - (longlong)(char)(&DAT_1403872c0)[uVar10])) >>

               ((&DAT_1403872d0)[uVar10] & 0x1f);

    }

    if (iVar7 < (int)uVar10) {

      if ((((*param_1 == -0x1f928c9d) && (param_1[6] == 4)) &&

          ((param_1[8] == 0x19930520 || (param_1[8] + 0xe66cfadfU < 2)))) &&

         (*(longlong *)(param_1 + 0xc) == 0)) {

        lVar9 = FUN_1402c97f8();

        if (*(longlong *)(lVar9 + 0x20) == 0) {

          return;

        }

        lVar9 = FUN_1402c97f8();

        param_1 = *(int **)(lVar9 + 0x20);

        lVar9 = FUN_1402c97f8();

        local_168 = 1;

        param_3 = *(undefined8 *)(lVar9 + 0x28);

        local_158 = param_3;

        FUN_1402c8e90(*(undefined8 *)(param_1 + 0xe));

        if ((param_1 == (int *)0x0) ||

           (((*param_1 == -0x1f928c9d && (param_1[6] == 4)) &&

            (((param_1[8] == 0x19930520 || (param_1[8] + 0xe66cfadfU < 2)) &&

             (*(longlong *)(param_1 + 0xc) == 0)))))) goto LAB_1402caced;

        lVar9 = FUN_1402c97f8();

        if (*(longlong *)(lVar9 + 0x38) != 0) {

          lVar9 = FUN_1402c97f8();

          uVar5 = *(undefined8 *)(lVar9 + 0x38);

          lVar9 = FUN_1402c97f8();

          *(undefined8 *)(lVar9 + 0x38) = 0;

          cVar6 = FUN_1402cc784(param_1,uVar5);

          param_3 = local_158;

          if (cVar6 == '\0') {

            cVar6 = FUN_1402cc86c(uVar5);

            if (cVar6 != '\0') {

              FUN_1402c9000(param_1,1);

              FUN_1402cbbb4(&local_140);

                    /* WARNING: Subroutine does not return */

              FUN_1402c8240(&local_140,&DAT_1403c7800);

            }

                    /* WARNING: Subroutine does not return */

            FUN_1402cf8b8();

          }

        }

      }

      FUN_1402cba94(local_d0,param_5,*(undefined8 *)(param_4 + 8));

      if (((*param_1 == -0x1f928c9d) && (param_1[6] == 4)) &&

         ((param_1[8] == 0x19930520 || (param_1[8] + 0xe66cfadfU < 2)))) {

        if (local_d0[0] != 0) {

          local_1a0 = (undefined8 *)CONCAT44(local_1a0._4_4_,param_7);

          local_1a8 = param_5;

          FUN_1402c8830(&local_118,local_d0,iVar7,param_4);

          uVar10 = (uint)uStack_110;

          local_140 = local_118;

          uStack_138 = uStack_110;

          if (uVar10 < local_100) {

            local_148 = local_118;

            lVar9 = local_118;

            do {

              local_140 = *(longlong *)(lVar9 + 0x18);

              uStack_138 = *(undefined8 *)(lVar9 + 0x20);

              if ((*(int *)(lVar9 + 0x18) <= iVar7) && (iVar7 <= *(int *)(lVar9 + 0x1c))) {

                local_164 = uVar10;

                FUN_1402cba10(local_a8,&local_140,*(undefined8 *)(param_4 + 8),

                              **(undefined4 **)(param_4 + 0x10));

                local_160 = 0;

                local_150 = local_a8[0];

                if (local_a8[0] != 0) {

                  do {

                    local_f8 = local_90;

                    uStack_f0 = uStack_88;

                    local_d8 = local_70;

                    local_e8 = local_80;

                    uStack_e4 = uStack_7c;

                    uStack_e0 = uStack_78;

                    uStack_dc = uStack_74;

                    iVar15 = *(int *)(*(longlong *)(param_1 + 0xc) + 0xc);

                    lVar9 = FUN_1402c8e64();

                    piVar16 = (int *)((longlong)iVar15 + lVar9 + 4);

                    iVar15 = *(int *)(*(longlong *)(param_1 + 0xc) + 0xc);

                    lVar9 = FUN_1402c8e64();

                    for (iVar15 = *(int *)(lVar9 + iVar15); 0 < iVar15; iVar15 = iVar15 + -1) {

                      iVar2 = *piVar16;

                      lVar9 = FUN_1402c8e64();

                      iVar8 = FUN_1402cb390(&local_f8,iVar2 + lVar9,*(undefined8 *)(param_1 + 0xc));

                      if (iVar8 != 0) {

                        local_170 = param_6;

                        local_178 = local_168;

                        local_180 = local_128;

                        local_188 = param_7;

                        local_190 = &local_140;

                        local_1a0 = &local_f8;

                        local_1a8 = param_5;

                        local_198 = iVar2 + lVar9;

                        FUN_1402ca1ec(param_1,local_120,local_158,param_4);

                        lVar9 = local_148;

                        uVar10 = local_164;

                        goto LAB_1402cab7c;

                      }

                      piVar16 = piVar16 + 1;

                    }

                    FH4::HandlerMap4::DecompHandler((HandlerMap4 *)local_a8);

                    local_160 = local_160 + 1;

                    lVar9 = local_148;

                    uVar10 = local_164;

                  } while (local_160 != local_150);

                }

              }

LAB_1402cab7c:

              pbVar11 = *(byte **)(lVar9 + 8);

              uVar10 = uVar10 + 1;

              lVar14 = (longlong)(char)(&DAT_1403872c0)[*pbVar11 & 0xf];

              bVar1 = (&DAT_1403872d0)[*pbVar11 & 0xf];

              pbVar12 = pbVar11 + -lVar14;

              uVar3 = *(uint *)(pbVar12 + -4);

              *(byte **)(lVar9 + 8) = pbVar12;

              *(uint *)(lVar9 + 0x18) = uVar3 >> (bVar1 & 0x1f);

              cVar6 = (&DAT_1403872c0)[*pbVar12 & 0xf];

              pbVar13 = pbVar11 + (-lVar14 - (longlong)cVar6);

              *(uint *)(lVar9 + 0x1c) =

                   *(uint *)(pbVar13 + -4) >> ((&DAT_1403872d0)[*pbVar12 & 0xf] & 0x1f);

              *(byte **)(lVar9 + 8) = pbVar13;

              pbVar11 = pbVar11 + ((-(longlong)cVar6 -

                                   (longlong)(char)(&DAT_1403872c0)[*pbVar13 & 0xf]) - lVar14);

              *(uint *)(lVar9 + 0x20) =

                   *(uint *)(pbVar11 + -4) >> ((&DAT_1403872d0)[*pbVar13 & 0xf] & 0x1f);

              *(byte **)(lVar9 + 8) = pbVar11;

              uVar4 = *(undefined4 *)pbVar11;

              *(byte **)(lVar9 + 8) = pbVar11 + 4;

              *(undefined4 *)(lVar9 + 0x24) = uVar4;

              local_164 = uVar10;

            } while (uVar10 < local_100);

          }

        }

        if (((*param_5 & 0x40) != 0) && (cVar6 = FUN_1402c854c(param_4,param_5), cVar6 == '\0')) {

          lVar9 = FUN_1402c97f8();

          *(int **)(lVar9 + 0x20) = param_1;

          lVar9 = FUN_1402c97f8();

          *(undefined8 *)(lVar9 + 0x28) = local_158;

                    /* WARNING: Subroutine does not return */

          FUN_1402cf8b8();

        }

      }

      else if (local_d0[0] != 0) {

        if (param_6 != '\0') goto LAB_1402caced;

        local_190 = param_8;

        local_198 = CONCAT44(local_198._4_4_,param_7);

        local_1a0 = (undefined8 *)CONCAT44(local_1a0._4_4_,iVar7);

        local_1a8 = param_5;

        FUN_1402caf58(param_1,param_2,param_3,param_4);

      }

      lVar9 = FUN_1402c97f8();

      if (*(longlong *)(lVar9 + 0x38) == 0) {

        return;

      }

    }

  }

LAB_1402caced:

                    /* WARNING: Subroutine does not return */

  FUN_1402e1bf8();

}




