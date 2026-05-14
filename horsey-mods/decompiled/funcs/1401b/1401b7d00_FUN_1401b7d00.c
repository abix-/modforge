// Address: 0x1401b7d00
// Ghidra name: FUN_1401b7d00
// ============ 0x1401b7d00 FUN_1401b7d00 (size=1652) ============


longlong FUN_1401b7d00(longlong param_1,int *param_2)



{

  longlong lVar1;

  int iVar2;

  undefined4 uVar3;

  undefined4 uVar4;

  undefined4 uVar5;

  undefined4 uVar6;

  char cVar7;

  int iVar8;

  uint uVar9;

  longlong lVar10;

  undefined4 *puVar11;

  undefined8 uVar12;

  uint uVar13;

  ulonglong uVar14;

  uint uVar15;

  uint uVar16;

  undefined4 uVar17;

  uint uVar18;

  bool bVar19;

  uint local_res18;

  undefined4 local_128;

  undefined4 uStack_124;

  undefined4 uStack_120;

  undefined4 uStack_11c;

  undefined4 local_118 [2];

  undefined8 local_110;

  undefined4 local_108;

  int local_104;

  undefined4 local_100;

  int local_fc;

  int local_f8;

  uint local_f4;

  int local_f0;

  uint local_ec;

  undefined4 local_e8;

  undefined4 local_e4;

  uint local_e0;

  undefined8 local_dc;

  undefined8 local_d0;

  undefined4 local_c8;

  undefined4 local_b8 [2];

  undefined8 local_b0;

  undefined4 local_a8;

  undefined8 local_a0;

  int local_98;

  undefined4 local_94;

  undefined4 local_90;

  undefined4 uStack_8c;

  undefined4 uStack_88;

  undefined4 uStack_84;

  uint local_80;

  undefined4 local_7c;

  int local_78;

  undefined4 local_74;

  uint local_70;

  undefined4 local_68 [2];

  undefined8 local_60;

  undefined4 local_58;

  undefined8 local_50;

  undefined8 local_48;

  

  uVar17 = 0;

  uVar15 = 1;

  if (*param_2 == 2) {

    uVar15 = param_2[5];

    uVar16 = 1;

  }

  else {

    uVar16 = param_2[5];

  }

  lVar10 = FUN_1401841a0(1,0x58);

  puVar11 = (undefined4 *)FUN_1401adcc0(&local_128,param_2[1]);

  uVar3 = *puVar11;

  uVar4 = puVar11[1];

  uVar5 = puVar11[2];

  uVar6 = puVar11[3];

  *(uint *)(lVar10 + 0x3c) = uVar15;

  *(undefined4 *)(lVar10 + 0x28) = uVar3;

  *(undefined4 *)(lVar10 + 0x2c) = uVar4;

  *(undefined4 *)(lVar10 + 0x30) = uVar5;

  *(undefined4 *)(lVar10 + 0x34) = uVar6;

  *(int *)(lVar10 + 0x40) = param_2[2];

  FUN_140139010(lVar10 + 0x54,0);

  iVar8 = param_2[1];

  if ((((iVar8 == 0x3a) || (iVar8 == 0x3b)) || (iVar8 == 0x3c)) ||

     ((iVar8 == 0x3d || (iVar8 == 0x3e)))) {

    *(undefined4 *)(lVar10 + 0x38) = 2;

    iVar8 = param_2[1];

    if ((iVar8 != 0x3d) && (iVar8 != 0x3e)) goto LAB_1401b7dc0;

    *(undefined4 *)(lVar10 + 0x38) = 6;

  }

  else {

    *(undefined4 *)(lVar10 + 0x38) = 1;

  }

  iVar8 = param_2[1];

LAB_1401b7dc0:

  iVar2 = *param_2;

  if ((iVar2 == 3) || (iVar2 == 4)) {

    uVar17 = 0x10;

  }

  else if (iVar2 == 2) {

    uVar17 = 0x20;

  }

  uVar18 = param_2[2];

  local_118[0] = 0xe;

  uVar9 = 7;

  if ((uVar18 & 0x19) == 0) {

    uVar9 = 3;

  }

  uVar13 = uVar9 | 0x10;

  if ((uVar18 & 2) == 0) {

    uVar13 = uVar9;

  }

  uVar9 = uVar13 | 0x20;

  if ((uVar18 & 4) == 0) {

    uVar9 = uVar13;

  }

  local_110 = 0;

  local_e4 = 0;

  local_dc = 0;

  local_d0 = 0;

  local_104 = (iVar2 == 2) + 1;

  local_c8 = 0;

  local_100 = *(undefined4 *)(&DAT_1403e3ec0 + (longlong)iVar8 * 4);

  local_fc = param_2[3];

  local_f8 = param_2[4];

  local_f0 = param_2[6];

  local_e8 = *(undefined4 *)(&DAT_1403e4250 + (longlong)param_2[7] * 4);

  local_e0 = uVar9 | 8;

  if ((uVar18 & 0x60) == 0) {

    local_e0 = uVar9;

  }

  local_108 = uVar17;

  local_f4 = uVar15;

  local_ec = uVar16;

  iVar8 = (**(code **)(param_1 + 0xb30))(*(undefined8 *)(param_1 + 0x570),local_118,0,lVar10 + 0x18)

  ;

  if (iVar8 == 0) {

    cVar7 = FUN_1401b49d0(param_1,*(undefined8 *)(lVar10 + 0x18),lVar10 + 0x10);

    if (cVar7 == '\x01') {

      *(longlong *)(*(longlong *)(lVar10 + 0x10) + 0x38) = lVar10;

      if ((*(byte *)(param_2 + 2) & 0x19) != 0) {

        local_b8[0] = 0xf;

        local_b0 = 0;

        local_a8 = 0;

        local_a0 = *(undefined8 *)(lVar10 + 0x18);

        local_94 = *(undefined4 *)(&DAT_1403e3ec0 + (longlong)param_2[1] * 4);

        local_90 = *(undefined4 *)(lVar10 + 0x28);

        uStack_8c = *(undefined4 *)(lVar10 + 0x2c);

        uStack_88 = *(undefined4 *)(lVar10 + 0x30);

        uStack_84 = *(undefined4 *)(lVar10 + 0x34);

        local_80 = *(uint *)(lVar10 + 0x38) & 0xfffffffb;

        local_7c = 0;

        local_78 = param_2[6];

        local_98 = *param_2;

        local_74 = 0;

        if (local_98 != 3) {

          if (local_98 == 4) {

            local_98 = 6;

          }

          else if (local_98 != 2) {

            bVar19 = local_98 == 1;

            local_98 = 1;

            if (bVar19) {

              local_98 = 5;

            }

          }

        }

        local_70 = uVar16;

        iVar8 = (**(code **)(param_1 + 0xb38))

                          (*(undefined8 *)(param_1 + 0x570),local_b8,0,lVar10 + 0x20);

        if (iVar8 != 0) {

          FUN_1401b9570(param_1,lVar10);

          if (*(char *)(param_1 + 0x57c) == '\0') {

            uVar12 = FUN_1401c0ba0(iVar8);

            FUN_14012e850("%s %s","\"vkCreateImageView\"",uVar12);

            return 0;

          }

          uVar12 = FUN_1401c0ba0(iVar8);

                    /* WARNING: Subroutine does not return */

          FUN_14012e0b0(9,"%s %s","\"vkCreateImageView\"",uVar12);

        }

      }

      iVar8 = param_2[6];

      *(uint *)(lVar10 + 0x44) = uVar16 * iVar8;

      uVar12 = FUN_1401841a0(uVar16 * iVar8,0x28);

      *(undefined8 *)(lVar10 + 0x48) = uVar12;

      local_res18 = 0;

      if (uVar16 != 0) {

        do {

          uVar18 = 0;

          if (param_2[6] != 0) {

            do {

              uVar9 = FUN_1401bb2e0(uVar18,local_res18);

              if ((*(byte *)(param_2 + 2) & 2) != 0) {

                uVar12 = FUN_1401841f0((ulonglong)uVar15 << 3);

                lVar1 = (ulonglong)uVar9 * 0x28;

                *(undefined8 *)(*(longlong *)(lVar10 + 0x48) + 0x10 + lVar1) = uVar12;

                if (uVar15 < 2) {

                  local_128 = *(undefined4 *)(lVar10 + 0x28);

                  uStack_124 = *(undefined4 *)(lVar10 + 0x2c);

                  uStack_120 = *(undefined4 *)(lVar10 + 0x30);

                  uStack_11c = *(undefined4 *)(lVar10 + 0x34);

                  cVar7 = FUN_1401b71e0(param_1,lVar10,local_res18,uVar18,

                                        *(undefined4 *)(&DAT_1403e3ec0 + (longlong)param_2[1] * 4),

                                        &local_128,

                                        *(undefined8 *)(*(longlong *)(lVar10 + 0x48) + 0x10 + lVar1)

                                       );

                  if (cVar7 == '\0') goto LAB_1401b8365;

                }

                else {

                  uVar14 = 0;

                  do {

                    local_128 = *(undefined4 *)(lVar10 + 0x28);

                    uStack_124 = *(undefined4 *)(lVar10 + 0x2c);

                    uStack_120 = *(undefined4 *)(lVar10 + 0x30);

                    uStack_11c = *(undefined4 *)(lVar10 + 0x34);

                    cVar7 = FUN_1401b71e0(param_1,lVar10,uVar14,uVar18,

                                          *(undefined4 *)(&DAT_1403e3ec0 + (longlong)param_2[1] * 4)

                                          ,&local_128,

                                          *(longlong *)(*(longlong *)(lVar10 + 0x48) + 0x10 + lVar1)

                                          + uVar14 * 8);

                    if (cVar7 == '\0') goto LAB_1401b8365;

                    uVar13 = (int)uVar14 + 1;

                    uVar14 = (ulonglong)uVar13;

                  } while (uVar13 < uVar15);

                }

              }

              uVar14 = (ulonglong)uVar9;

              if ((*(byte *)(param_2 + 2) & 0x60) != 0) {

                local_128 = *(undefined4 *)(lVar10 + 0x28);

                uStack_124 = *(undefined4 *)(lVar10 + 0x2c);

                uStack_120 = *(undefined4 *)(lVar10 + 0x30);

                uStack_11c = *(undefined4 *)(lVar10 + 0x34);

                cVar7 = FUN_1401b7300(param_1,param_2,lVar10,local_res18,uVar18,&local_128,

                                      *(longlong *)(lVar10 + 0x48) + (uVar14 * 5 + 3) * 8);

                if (cVar7 == '\0') goto LAB_1401b8365;

              }

              if ((*(byte *)(param_2 + 2) & 4) != 0) {

                local_128 = *(undefined4 *)(lVar10 + 0x28);

                uStack_124 = *(undefined4 *)(lVar10 + 0x2c);

                uStack_120 = *(undefined4 *)(lVar10 + 0x30);

                uStack_11c = *(undefined4 *)(lVar10 + 0x34);

                cVar7 = FUN_1401b7300(param_1,param_2,lVar10,local_res18,uVar18,&local_128,

                                      *(longlong *)(lVar10 + 0x48) + (uVar14 * 5 + 4) * 8);

                if (cVar7 == '\0') {

LAB_1401b8365:

                  FUN_1401b9570(param_1,lVar10);

                  return 0;

                }

              }

              *(longlong *)(*(longlong *)(lVar10 + 0x48) + uVar14 * 0x28) = lVar10;

              *(uint *)(*(longlong *)(lVar10 + 0x48) + 8 + uVar14 * 0x28) = local_res18;

              *(uint *)(*(longlong *)(lVar10 + 0x48) + 0xc + uVar14 * 0x28) = uVar18;

              uVar18 = uVar18 + 1;

            } while (uVar18 < (uint)param_2[6]);

          }

          local_res18 = local_res18 + 1;

        } while (local_res18 < uVar16);

      }

      if (((*(char *)(param_1 + 0x57c) != '\0') && (*(char *)(param_1 + 0x58e) != '\0')) &&

         (cVar7 = FUN_140174fc0(param_2[8],"SDL.gpu.texture.create.name"), cVar7 != '\0')) {

        local_68[0] = 0x3b9cbe00;

        local_60 = 0;

        local_48 = FUN_140174e70(param_2[8],"SDL.gpu.texture.create.name",0);

        local_50 = *(undefined8 *)(lVar10 + 0x18);

        local_58 = 10;

        (**(code **)(param_1 + 0x9d0))(*(undefined8 *)(param_1 + 0x570),local_68);

      }

    }

    else {

      (**(code **)(param_1 + 0xba8))

                (*(undefined8 *)(param_1 + 0x570),*(undefined8 *)(lVar10 + 0x18),0);

      FUN_1401b9570(param_1,lVar10);

      if (*(char *)(param_1 + 0x57c) != '\0') {

                    /* WARNING: Subroutine does not return */

        FUN_14012e0b0(9,&DAT_14039bf30,"Unable to bind memory for texture!");

      }

      FUN_14012e850(&DAT_14039bf30,"Unable to bind memory for texture!");

      lVar10 = 0;

    }

  }

  else {

    FUN_1401b9570(param_1,lVar10);

    if (*(char *)(param_1 + 0x57c) != '\0') {

      uVar12 = FUN_1401c0ba0(iVar8);

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(9,"%s %s","vkCreateImage",uVar12);

    }

    uVar12 = FUN_1401c0ba0(iVar8);

    FUN_14012e850("%s %s","vkCreateImage",uVar12);

    lVar10 = 0;

  }

  return lVar10;

}




