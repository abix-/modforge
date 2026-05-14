// Address: 0x1401c8b30
// Ghidra name: FUN_1401c8b30
// ============ 0x1401c8b30 FUN_1401c8b30 (size=1976) ============


longlong FUN_1401c8b30(longlong param_1,int *param_2,char param_3,undefined8 param_4)



{

  longlong lVar1;

  undefined1 uVar2;

  undefined4 uVar3;

  int iVar4;

  longlong lVar5;

  longlong lVar6;

  undefined8 uVar7;

  undefined *puVar8;

  ulonglong uVar9;

  uint uVar10;

  uint uVar11;

  uint uVar12;

  undefined4 *puVar13;

  undefined4 uVar14;

  uint uVar15;

  ulonglong uVar16;

  uint uVar17;

  bool bVar18;

  undefined8 in_stack_fffffffffffffef8;

  undefined4 uVar19;

  undefined4 local_e8;

  undefined4 local_e4;

  uint local_e0;

  uint local_dc;

  undefined8 local_d8;

  ulonglong local_d0;

  ulonglong local_c8;

  uint local_c0;

  int local_bc;

  uint local_b8;

  uint local_b4;

  undefined4 local_b0;

  undefined4 local_ac;

  undefined4 local_a8;

  undefined4 local_a4;

  undefined4 local_a0;

  undefined4 local_98 [2];

  undefined8 local_90;

  ulonglong local_88;

  int local_80;

  undefined2 local_7c;

  undefined2 local_7a;

  undefined4 local_78;

  undefined8 local_74;

  undefined4 local_6c;

  uint local_68;

  undefined8 local_60;

  undefined8 local_58;

  undefined8 local_50;

  undefined4 local_48;

  

  uVar19 = (undefined4)((ulonglong)in_stack_fffffffffffffef8 >> 0x20);

  local_b4 = param_2[2] & 0x60;

  uVar17 = param_2[2] & 0x19;

  lVar5 = FUN_1401841a0(1,0x50);

  if (lVar5 == 0) {

    return 0;

  }

  if (*param_2 == 2) {

    local_b8 = 1;

    local_c0 = param_2[5];

  }

  else {

    local_c0 = 1;

    local_b8 = param_2[5];

  }

  bVar18 = (*(byte *)(param_2 + 2) & 2) != 0;

  local_bc = param_2[7];

  uVar3 = *(undefined4 *)(&DAT_1403e43f0 + (longlong)param_2[1] * 4);

  if (bVar18) {

    local_b0 = uVar3;

    local_ac = FUN_140174af0(param_2[8],"SDL.gpu.texture.create.d3d12.clear.r",0);

    local_a8 = FUN_140174af0(param_2[8],"SDL.gpu.texture.create.d3d12.clear.g",0);

    local_a4 = FUN_140174af0(param_2[8],"SDL.gpu.texture.create.d3d12.clear.b",0);

    local_a0 = FUN_140174af0(param_2[8],"SDL.gpu.texture.create.d3d12.clear.a",0);

  }

  uVar11 = (uint)bVar18;

  uVar15 = uVar11;

  if ((*(byte *)(param_2 + 2) & 4) != 0) {

    uVar11 = uVar11 | 2;

    local_b0 = *(undefined4 *)(&DAT_1403e45a0 + (longlong)param_2[1] * 4);

    local_ac = FUN_140174af0(param_2[8],"SDL.gpu.texture.create.d3d12.clear.depth",0);

    uVar2 = FUN_140174c40(param_2[8],"SDL.gpu.texture.create.d3d12.clear.stencil",0);

    puVar8 = &DAT_1403e4750;

    local_a8 = CONCAT31(local_a8._1_3_,uVar2);

    uVar15 = 1;

    if (uVar17 == 0) {

      puVar8 = &DAT_1403e45a0;

    }

    uVar3 = *(undefined4 *)(puVar8 + (longlong)param_2[1] * 4);

  }

  local_58 = 1;

  local_68 = uVar11 | 4;

  if (local_b4 == 0) {

    local_68 = uVar11;

  }

  local_90 = 0;

  local_50 = 0;

  uVar14 = 0;

  local_48 = 0;

  if (*param_2 == 2) {

    local_90 = 0x10000;

    uVar11 = param_2[3];

    local_80 = param_2[4];

    local_7c = (undefined2)param_2[5];

    local_7a = (undefined2)param_2[6];

    local_98[0] = 4;

    local_74 = 1;

  }

  else {

    local_98[0] = 3;

    if ((param_3 == '\0') && (local_90 = 0x10000, 0 < local_bc)) {

      local_90 = 0x400000;

    }

    uVar11 = param_2[3];

    local_80 = param_2[4];

    local_7c = (undefined2)param_2[5];

    local_7a = (undefined2)param_2[6];

    if (0 < local_bc) {

      uVar14 = 0xffffffff;

    }

    local_74 = CONCAT44(uVar14,*(undefined4 *)(&DAT_1403e49f0 + (longlong)param_2[7] * 4));

  }

  local_88 = (ulonglong)uVar11;

  local_6c = 0;

  local_78 = uVar3;

  if (param_3 == '\0') {

    uVar3 = FUN_1401c9550(param_2[2]);

  }

  else {

    uVar3 = 0;

  }

  puVar13 = &local_b0;

  if (uVar15 == 0) {

    puVar13 = (undefined4 *)0x0;

  }

  iVar4 = (**(code **)(**(longlong **)(param_1 + 0x70) + 0xd8))

                    (*(longlong **)(param_1 + 0x70),&local_58,-(param_3 != '\0') & 8,local_98,

                     CONCAT44(uVar19,uVar3),puVar13,&DAT_1403492f8,&local_60);

  if (iVar4 < 0) {

    FUN_1401cb240(param_1,"Failed to create texture!",iVar4);

    goto LAB_1401c8e41;

  }

  *(undefined8 *)(lVar5 + 0x20) = local_60;

  if (uVar17 != 0) {

    FUN_1401c5df0(param_1,0,lVar5 + 0x28);

    local_e0 = 0x1688;

    local_e8 = *(undefined4 *)(&DAT_1403e43f0 + (longlong)param_2[1] * 4);

    iVar4 = *param_2;

    if (iVar4 == 3) {

      local_e4 = 9;

LAB_1401c8f05:

      local_d0 = local_d0 & 0xffffffff00000000;

    }

    else if (iVar4 == 4) {

      local_e4 = 10;

      local_c8 = local_c8 & 0xffffffff00000000;

      local_d0 = (ulonglong)((uint)param_2[5] / 6) << 0x20;

    }

    else if (iVar4 == 1) {

      local_c8 = 0;

      local_e4 = 5;

      local_d0 = (ulonglong)local_b8 << 0x20;

    }

    else {

      if (iVar4 == 2) {

        local_e4 = 8;

        goto LAB_1401c8f05;

      }

      local_e4 = 4;

      local_d0 = 0;

    }

    local_d8 = (ulonglong)(uint)param_2[6] << 0x20;

    (**(code **)(**(longlong **)(param_1 + 0x70) + 0x90))

              (*(longlong **)(param_1 + 0x70),local_60,&local_e8,*(undefined8 *)(lVar5 + 0x38));

  }

  FUN_140139010(lVar5 + 0x48,0);

  uVar17 = local_b8;

  *(uint *)(lVar5 + 0x18) = local_b8 * param_2[6];

  lVar6 = FUN_1401841a0();

  *(longlong *)(lVar5 + 0x10) = lVar6;

  if (lVar6 != 0) {

    uVar15 = 0;

    if (uVar17 != 0) {

      do {

        uVar12 = 0;

        uVar17 = param_2[6];

        uVar11 = local_c0;

        if (uVar17 != 0) {

          do {

            uVar17 = uVar17 * uVar15 + uVar12;

            lVar6 = (ulonglong)uVar17 * 0x60;

            *(longlong *)(lVar6 + *(longlong *)(lVar5 + 0x10)) = lVar5;

            *(uint *)(lVar6 + 8 + *(longlong *)(lVar5 + 0x10)) = uVar15;

            *(uint *)(lVar6 + 0xc + *(longlong *)(lVar5 + 0x10)) = uVar12;

            *(uint *)(lVar6 + 0x10 + *(longlong *)(lVar5 + 0x10)) = uVar11;

            *(uint *)(lVar6 + 0x14 + *(longlong *)(lVar5 + 0x10)) = uVar17;

            *(undefined8 *)(lVar6 + 0x18 + *(longlong *)(lVar5 + 0x10)) = 0;

            *(undefined8 *)(lVar6 + 0x28 + *(longlong *)(lVar5 + 0x10)) = 0;

            *(undefined8 *)(lVar6 + 0x48 + *(longlong *)(lVar5 + 0x10)) = 0;

            if ((*(byte *)(param_2 + 2) & 2) != 0) {

              lVar1 = *(longlong *)(lVar5 + 0x10);

              uVar7 = FUN_1401841a0(uVar11);

              uVar9 = 0;

              *(undefined8 *)(lVar6 + 0x18 + lVar1) = uVar7;

              uVar16 = uVar9;

              if (uVar11 != 0) {

                do {

                  FUN_1401c5df0(param_1,2,

                                *(longlong *)(lVar6 + 0x18 + *(longlong *)(lVar5 + 0x10)) + uVar16);

                  local_e8 = *(undefined4 *)(&DAT_1403e43f0 + (longlong)param_2[1] * 4);

                  iVar4 = *param_2;

                  if ((iVar4 - 1U & 0xfffffffc) == 0) {

                    if (iVar4 == 2) {

LAB_1401c908f:

                      local_e4 = 8;

                      local_d8 = CONCAT44(local_d8._4_4_,1);

                      local_e0 = uVar12;

                      local_dc = (uint)uVar9;

                    }

                    else {

                      local_e4 = 5;

                      local_d8 = 1;

                      local_e0 = uVar12;

                      local_dc = uVar15;

                    }

                  }

                  else {

                    if (iVar4 == 2) goto LAB_1401c908f;

                    if (local_bc < 1) {

                      local_e4 = 4;

                      local_dc = 0;

                      local_e0 = uVar12;

                    }

                    else {

                      local_e4 = 6;

                    }

                  }

                  (**(code **)(**(longlong **)(param_1 + 0x70) + 0xa0))

                            (*(longlong **)(param_1 + 0x70),*(undefined8 *)(lVar5 + 0x20),&local_e8,

                             *(undefined8 *)

                              (*(longlong *)(lVar6 + 0x18 + *(longlong *)(lVar5 + 0x10)) + 0x10 +

                              uVar16));

                  uVar10 = (uint)uVar9 + 1;

                  uVar9 = (ulonglong)uVar10;

                  uVar16 = uVar16 + 0x20;

                  uVar11 = local_c0;

                } while (uVar10 < local_c0);

              }

            }

            if ((*(byte *)(param_2 + 2) & 4) != 0) {

              FUN_1401c5df0(param_1,3,*(longlong *)(lVar5 + 0x10) + 0x40 + (ulonglong)uVar17 * 0x60)

              ;

              local_e0 = 0;

              local_e8 = *(undefined4 *)(&DAT_1403e45a0 + (longlong)param_2[1] * 4);

              if (((*param_2 - 1U & 0xfffffffc) == 0) && (*param_2 != 2)) {

                local_e4 = 4;

                local_d8 = CONCAT44(1,uVar15);

                local_dc = uVar12;

              }

              else if (local_bc < 1) {

                local_e4 = 3;

                local_dc = uVar12;

              }

              else {

                local_e4 = 5;

              }

              (**(code **)(**(longlong **)(param_1 + 0x70) + 0xa8))

                        (*(longlong **)(param_1 + 0x70),*(undefined8 *)(lVar5 + 0x20),&local_e8,

                         *(undefined8 *)

                          ((ulonglong)uVar17 * 0x60 + 0x50 + *(longlong *)(lVar5 + 0x10)));

            }

            if (local_b4 != 0) {

              FUN_1401c5df0(param_1,0,*(longlong *)(lVar5 + 0x10) + 0x20 + (ulonglong)uVar17 * 0x60)

              ;

              local_e8 = *(undefined4 *)(&DAT_1403e43f0 + (longlong)param_2[1] * 4);

              iVar4 = *param_2;

              if ((iVar4 - 1U & 0xfffffffc) == 0) {

                if (iVar4 == 2) {

LAB_1401c923c:

                  local_e4 = 8;

                  local_d8 = CONCAT44(local_d8._4_4_,uVar11);

                  goto LAB_1401c9252;

                }

                local_e4 = 5;

                local_d8 = 1;

                local_dc = uVar15;

              }

              else {

                if (iVar4 == 2) goto LAB_1401c923c;

                local_e4 = 4;

LAB_1401c9252:

                local_dc = 0;

              }

              local_e0 = uVar12;

              (**(code **)(**(longlong **)(param_1 + 0x70) + 0x98))

                        (*(longlong **)(param_1 + 0x70),*(undefined8 *)(lVar5 + 0x20),0,&local_e8,

                         *(undefined8 *)

                          ((ulonglong)uVar17 * 0x60 + 0x30 + *(longlong *)(lVar5 + 0x10)));

            }

            uVar17 = param_2[6];

            uVar12 = uVar12 + 1;

          } while (uVar12 < uVar17);

        }

        uVar15 = uVar15 + 1;

      } while (uVar15 < local_b8);

    }

    FUN_1401cb3d0(param_1,*(undefined8 *)(lVar5 + 0x20),param_4);

    return lVar5;

  }

LAB_1401c8e41:

  FUN_1401c9d80(lVar5);

  return 0;

}




