// Address: 0x1401b7430
// Ghidra name: FUN_1401b7430
// ============ 0x1401b7430 FUN_1401b7430 (size=2248) ============


/* WARNING: Function: __chkstk replaced with injection: alloca_probe */



undefined8 FUN_1401b7430(longlong param_1,longlong *param_2)



{

  undefined8 *puVar1;

  undefined4 uVar2;

  code *pcVar3;

  undefined4 uVar4;

  undefined4 uVar5;

  undefined4 uVar6;

  undefined4 uVar7;

  longlong lVar8;

  char cVar9;

  char cVar10;

  int iVar11;

  undefined4 uVar12;

  undefined8 uVar13;

  longlong lVar14;

  longlong lVar15;

  ulonglong uVar16;

  char *pcVar17;

  undefined1 *puVar18;

  uint uVar19;

  uint uVar20;

  ulonglong uVar21;

  int iVar22;

  undefined8 uVar23;

  int iVar24;

  longlong lVar25;

  longlong *plVar26;

  undefined8 uStack_180;

  undefined1 auStack_178 [32];

  undefined4 auStack_158 [2];

  longlong alStack_150 [3];

  uint local_138;

  uint uStack_134;

  int local_130;

  int local_12c;

  uint local_128;

  uint local_124;

  uint local_120;

  uint local_11c;

  undefined4 local_110;

  uint local_10c;

  undefined8 local_100;

  int local_f8;

  undefined8 local_f0;

  int local_e8;

  undefined4 local_d8 [2];

  undefined8 local_d0;

  undefined4 local_c8;

  longlong local_c0;

  uint local_b8;

  undefined4 local_b4;

  undefined4 local_b0;

  undefined4 local_ac;

  undefined4 local_a8;

  undefined4 local_a4;

  undefined8 local_a0;

  undefined4 local_98;

  undefined8 local_90;

  undefined4 local_88;

  int local_84;

  undefined4 local_80;

  undefined4 local_7c;

  longlong local_78;

  undefined4 local_68 [2];

  undefined8 local_60;

  undefined4 local_58;

  undefined4 local_48;

  undefined4 uStack_44;

  undefined4 uStack_40;

  undefined4 uStack_3c;

  

  puVar18 = auStack_178;

  iVar11 = 0;

  *(undefined4 *)(param_2 + 0x15) = 0;

  uStack_180 = 0x1401b7470;

  cVar9 = FUN_1401bc440(param_1,*(undefined8 *)(param_1 + 8),param_2[5],&local_138);

  if (cVar9 != '\0') {

    *(undefined1 *)(param_2 + 10) = 0;

    lVar15 = (longlong)*(int *)((longlong)param_2 + 0x14) * 4;

    uVar12 = *(undefined4 *)(&DAT_1403e4068 + lVar15);

    uVar2 = *(undefined4 *)(&DAT_1403e4088 + lVar15);

    *(undefined4 *)(param_2 + 7) = uVar12;

    lVar14 = (longlong)*(int *)((longlong)param_2 + 0x14) * 0x10;

    uVar4 = *(undefined4 *)(&DAT_1403e40a0 + lVar14);

    uVar5 = *(undefined4 *)(lVar14 + 0x1403e40a4);

    uVar6 = *(undefined4 *)(lVar14 + 0x1403e40a8);

    uVar7 = *(undefined4 *)(lVar14 + 0x1403e40ac);

    *(undefined4 *)((longlong)param_2 + 0x3c) = uVar2;

    *(undefined4 *)(param_2 + 8) = uVar4;

    *(undefined4 *)((longlong)param_2 + 0x44) = uVar5;

    *(undefined4 *)(param_2 + 9) = uVar6;

    *(undefined4 *)((longlong)param_2 + 0x4c) = uVar7;

    uStack_180 = 0x1401b74cb;

    uVar13 = local_100;

    iVar24 = local_f8;

    cVar9 = FUN_1401bf340(uVar12,uVar2,local_100,local_f8);

    if (cVar9 == '\0') {

      *(undefined4 *)(param_2 + 7) = *(undefined4 *)(&DAT_1403e4078 + lVar15);

      *(undefined1 *)(param_2 + 10) = 1;

      uStack_180 = 0x1401b74e8;

      cVar9 = FUN_1401bf340();

    }

    lVar15 = param_2[3];

    uStack_180 = 0x1401b7507;

    uVar23 = local_f0;

    iVar22 = local_e8;

    cVar10 = FUN_1401bf320(*(undefined4 *)(&DAT_1403e3eb0 + (longlong)(int)lVar15 * 4),local_f0);

    if ((cVar9 == '\0') || (cVar10 == '\0')) {

      if (iVar24 != 0) {

        uStack_180 = 0x1401b7c5f;

        FUN_1401841e0(uVar13);

        uVar23 = local_f0;

        iVar22 = local_e8;

      }

      if (iVar22 != 0) {

        uStack_180 = 0x1401b7c74;

        FUN_1401841e0(uVar23);

      }

      if (cVar9 == '\0') {

        if (*(char *)(param_1 + 0x57c) != '\0') {

                    /* WARNING: Subroutine does not return */

          uStack_180 = 0x1401b7c9a;

          FUN_14012e0b0(9,&DAT_14039bf30,"Device does not support requested swapchain composition!")

          ;

        }

        pcVar17 = "Device does not support requested swapchain composition!";

      }

      else {

        if (cVar10 != '\0') {

          return 0;

        }

        if (*(char *)(param_1 + 0x57c) != '\0') {

                    /* WARNING: Subroutine does not return */

          uStack_180 = 0x1401b7cc9;

          FUN_14012e0b0(9,&DAT_14039bf30,"Device does not support requested present_mode!");

        }

        pcVar17 = "Device does not support requested present_mode!";

      }

      uStack_180 = 0x1401b7cdc;

      FUN_14012e850(&DAT_14039bf30,pcVar17);

    }

    else {

      if ((local_130 == 0) || (local_12c == 0)) {

        if (iVar24 != 0) {

          uStack_180 = 0x1401b7c33;

          FUN_1401841e0(uVar13);

          uVar23 = local_f0;

          iVar22 = local_e8;

        }

        if (iVar22 != 0) {

          uStack_180 = 0x1401b7c48;

          FUN_1401841e0(uVar23);

        }

        return 2;

      }

      uVar20 = *(uint *)(param_2 + 4);

      uVar19 = *(uint *)(param_1 + 0x584);

      if ((local_128 <= uVar20) && (local_128 = uVar20, local_120 < uVar20)) {

        local_128 = local_120;

      }

      uVar20 = *(uint *)((longlong)param_2 + 0x24);

      *(uint *)((longlong)param_2 + 100) = local_128;

      if ((local_124 <= uVar20) && (local_124 = uVar20, local_11c < uVar20)) {

        local_124 = local_11c;

      }

      *(uint *)(param_2 + 0xd) = local_124;

      if ((uStack_134 != 0) && (uStack_134 < uVar19)) {

        uVar19 = uStack_134;

      }

      if (uVar19 < local_138) {

        uVar19 = local_138;

      }

      uVar20 = uVar19;

      if (((int)lVar15 == 2) && (uVar20 = 3, 3 < uVar19)) {

        uVar20 = uVar19;

      }

      if ((local_10c & 1) == 0) {

        if ((local_10c & 8) != 0) {

          iVar11 = 8;

        }

      }

      else {

        iVar11 = 1;

      }

      if (((*(uint *)(*param_2 + 0x48) >> 0x1e & 1) != 0) || (iVar11 == 0)) {

        if ((local_10c & 2) == 0) {

          if ((local_10c & 4) == 0) {

            if ((local_10c & 8) == 0) {

              uStack_180 = 0x1401b75ed;

              FUN_14012e2e0(9,

                            "SDL_WINDOW_TRANSPARENT flag set, but no suitable swapchain composite alpha value supported!"

                           );

            }

            else {

              iVar11 = 8;

            }

          }

          else {

            iVar11 = 4;

          }

        }

        else {

          iVar11 = 2;

        }

      }

      local_c0 = param_2[5];

      plVar26 = param_2 + 6;

      local_b4 = (undefined4)param_2[7];

      local_b0 = *(undefined4 *)((longlong)param_2 + 0x3c);

      local_ac = *(undefined4 *)((longlong)param_2 + 100);

      local_a8 = (undefined4)param_2[0xd];

      local_88 = local_110;

      uVar19 = 0;

      local_d8[0] = 0x3b9acde8;

      local_d0 = 0;

      local_80 = *(undefined4 *)(&DAT_1403e3eb0 + (longlong)(int)param_2[3] * 4);

      local_c8 = 0;

      local_a4 = 1;

      local_a0 = 0x12;

      local_98 = 0;

      local_90 = 0;

      local_7c = 1;

      if (*(char *)((longlong)param_2 + 0x1d) == '\0') {

        local_78 = *plVar26;

      }

      else {

        local_78 = 0;

      }

      uStack_180 = 0x1401b76c0;

      local_b8 = uVar20;

      local_84 = iVar11;

      iVar11 = (**(code **)(param_1 + 0xc90))(*(undefined8 *)(param_1 + 0x570),local_d8,0,plVar26);

      if (local_78 != 0) {

        uStack_180 = 0x1401b76e2;

        (**(code **)(param_1 + 0xc98))(*(undefined8 *)(param_1 + 0x570),local_78,0);

      }

      if (local_f8 != 0) {

        uStack_180 = 0x1401b76f1;

        FUN_1401841e0(local_100);

      }

      if (local_e8 != 0) {

        uStack_180 = 0x1401b7700;

        FUN_1401841e0(local_f0);

      }

      if (iVar11 == 0) {

        uStack_180 = 0x1401b776e;

        iVar11 = (**(code **)(param_1 + 0xca8))

                           (*(undefined8 *)(param_1 + 0x570),*plVar26,param_2 + 0xc,0);

        if (iVar11 == 0) {

          uStack_180 = 0x1401b77d2;

          lVar14 = FUN_1401841f0((ulonglong)*(uint *)(param_2 + 0xc) * 0x50);

          lVar15 = *plVar26;

          param_2[0xb] = lVar14;

          if (lVar14 == 0) {

            uStack_180 = 0x1401b77f1;

            (**(code **)(param_1 + 0xc98))(*(undefined8 *)(param_1 + 0x570),lVar15,0);

            *plVar26 = 0;

            return 0;

          }

          uVar16 = (ulonglong)*(uint *)(param_2 + 0xc) * 8 + 0xf;

          if (uVar16 <= (ulonglong)*(uint *)(param_2 + 0xc) * 8) {

            uVar16 = 0xffffffffffffff0;

          }

          uStack_180 = 0x1401b7820;

          pcVar3 = *(code **)(param_1 + 0xca8);

          lVar14 = -(uVar16 & 0xfffffffffffffff0);

          puVar18 = auStack_178 + lVar14;

          uVar13 = *(undefined8 *)(param_1 + 0x570);

          *(undefined8 *)(auStack_178 + lVar14 + -8) = 0x1401b7846;

          iVar11 = (*pcVar3)(uVar13,lVar15,param_2 + 0xc,(longlong)&local_138 + lVar14);

          if (iVar11 == 0) {

            if ((int)param_2[0xc] != 0) {

              do {

                lVar15 = param_2[0xb];

                lVar25 = (ulonglong)uVar19 * 0x50;

                *(undefined8 *)(lVar25 + lVar15) = 0;

                ((undefined8 *)(lVar25 + lVar15))[1] = 0;

                puVar1 = (undefined8 *)(lVar25 + 0x10 + lVar15);

                *puVar1 = 0;

                puVar1[1] = 0;

                puVar1 = (undefined8 *)(lVar25 + 0x20 + lVar15);

                *puVar1 = 0;

                puVar1[1] = 0;

                puVar1 = (undefined8 *)(lVar25 + 0x30 + lVar15);

                *puVar1 = 0;

                puVar1[1] = 0;

                puVar1 = (undefined8 *)(lVar25 + 0x40 + lVar15);

                *puVar1 = 0;

                puVar1[1] = 0;

                *(undefined1 *)(lVar25 + 0x48 + param_2[0xb]) = 0;

                *(undefined4 *)(lVar25 + 0xc + param_2[0xb]) =

                     *(undefined4 *)((longlong)param_2 + 100);

                *(int *)(lVar25 + 0x10 + param_2[0xb]) = (int)param_2[0xd];

                *(undefined4 *)(lVar25 + 0x14 + param_2[0xb]) = 1;

                lVar15 = param_2[10];

                uVar12 = *(undefined4 *)((longlong)param_2 + 0x14);

                *(undefined8 *)(auStack_178 + lVar14 + -8) = 0x1401b78cd;

                uVar12 = FUN_1401adc80(uVar12,(char)lVar15);

                *(undefined4 *)(lVar25 + 4 + param_2[0xb]) = uVar12;

                *(undefined4 *)(lVar25 + param_2[0xb]) = 0;

                *(undefined4 *)(lVar25 + 0x18 + param_2[0xb]) = 1;

                *(undefined4 *)(lVar25 + 0x1c + param_2[0xb]) = 0;

                *(undefined4 *)(lVar25 + 8 + param_2[0xb]) = 2;

                lVar15 = param_2[0xb];

                *(undefined8 *)(auStack_178 + lVar14 + -8) = 0x1401b7911;

                uVar13 = FUN_1401841f0(0x58);

                *(undefined8 *)(lVar15 + 0x28 + lVar25) = uVar13;

                *(undefined8 *)(*(longlong *)(lVar25 + 0x28 + param_2[0xb]) + 0x18) =

                     *(undefined8 *)((longlong)&local_138 + lVar14 + (ulonglong)uVar19 * 8);

                *(undefined8 *)(*(longlong *)(lVar25 + 0x28 + param_2[0xb]) + 0x10) = 0;

                uVar12 = *(undefined4 *)((longlong)param_2 + 0x44);

                lVar8 = param_2[9];

                uVar2 = *(undefined4 *)((longlong)param_2 + 0x4c);

                lVar15 = *(longlong *)(lVar25 + 0x28 + param_2[0xb]);

                *(int *)(lVar15 + 0x28) = (int)param_2[8];

                *(undefined4 *)(lVar15 + 0x2c) = uVar12;

                *(int *)(lVar15 + 0x30) = (int)lVar8;

                *(undefined4 *)(lVar15 + 0x34) = uVar2;

                *(undefined4 *)(*(longlong *)(lVar25 + 0x28 + param_2[0xb]) + 0x38) = 1;

                *(undefined4 *)(*(longlong *)(lVar25 + 0x28 + param_2[0xb]) + 0x3c) = 1;

                *(undefined4 *)(*(longlong *)(lVar25 + 0x28 + param_2[0xb]) + 0x40) = 2;

                **(longlong **)(param_2[0xb] + lVar25 + 0x28) = param_2[0xb] + lVar25;

                lVar15 = *(longlong *)(lVar25 + 0x28 + param_2[0xb]);

                *(undefined8 *)(auStack_178 + lVar14 + -8) = 0x1401b79a1;

                FUN_140139010(lVar15 + 0x54,0);

                *(undefined4 *)(*(longlong *)(lVar25 + 0x28 + param_2[0xb]) + 0x44) = 1;

                lVar15 = *(longlong *)(lVar25 + 0x28 + param_2[0xb]);

                *(undefined8 *)(auStack_178 + lVar14 + -8) = 0x1401b79c4;

                uVar13 = FUN_1401841f0(0x28);

                *(undefined8 *)(lVar15 + 0x48) = uVar13;

                lVar15 = *(longlong *)(lVar25 + 0x28 + param_2[0xb]);

                **(longlong **)(lVar15 + 0x48) = lVar15;

                *(undefined4 *)

                 (*(longlong *)(*(longlong *)(lVar25 + 0x28 + param_2[0xb]) + 0x48) + 8) = 0;

                *(undefined4 *)

                 (*(longlong *)(*(longlong *)(lVar25 + 0x28 + param_2[0xb]) + 0x48) + 0xc) = 0;

                lVar15 = *(longlong *)(*(longlong *)(lVar25 + 0x28 + param_2[0xb]) + 0x48);

                *(undefined8 *)(auStack_178 + lVar14 + -8) = 0x1401b7a0f;

                uVar13 = FUN_1401841f0(8);

                *(undefined8 *)(lVar15 + 0x10) = uVar13;

                local_48 = (undefined4)param_2[8];

                uStack_44 = *(undefined4 *)((longlong)param_2 + 0x44);

                uStack_40 = (undefined4)param_2[9];

                uStack_3c = *(undefined4 *)((longlong)param_2 + 0x4c);

                lVar15 = *(longlong *)(lVar25 + 0x28 + param_2[0xb]);

                *(undefined8 *)((longlong)alStack_150 + lVar14 + 8) =

                     *(undefined8 *)(*(longlong *)(lVar15 + 0x48) + 0x10);

                *(undefined4 **)((longlong)alStack_150 + lVar14) = &local_48;

                *(int *)((longlong)auStack_158 + lVar14) = (int)param_2[7];

                *(undefined8 *)(auStack_178 + lVar14 + -8) = 0x1401b7a57;

                cVar9 = FUN_1401b71e0(param_1,lVar15,0,0);

                if (cVar9 == '\0') {

                  pcVar3 = *(code **)(param_1 + 0xc98);

                  uVar13 = *(undefined8 *)(param_1 + 0x570);

                  lVar15 = *plVar26;

                  *(undefined8 *)(auStack_178 + lVar14 + -8) = 0x1401b7b50;

                  (*pcVar3)(uVar13,lVar15,0);

                  *plVar26 = 0;

                  return 0;

                }

                uVar19 = uVar19 + 1;

              } while (uVar19 < *(uint *)(param_2 + 0xc));

            }

            plVar26 = param_2 + 6;

            local_68[0] = 9;

            local_60 = 0;

            local_58 = 0;

            uVar16 = 0;

            do {

              pcVar3 = *(code **)(param_1 + 0xb60);

              uVar13 = *(undefined8 *)(param_1 + 0x570);

              *(undefined8 *)(auStack_178 + lVar14 + -8) = 0x1401b7ab4;

              iVar11 = (*pcVar3)(uVar13,local_68,0,param_2 + uVar16 + 0xe);

              if (iVar11 != 0) {

                pcVar3 = *(code **)(param_1 + 0xc98);

                lVar15 = *plVar26;

                uVar13 = *(undefined8 *)(param_1 + 0x570);

                *(undefined8 *)(auStack_178 + lVar14 + -8) = 0x1401b7bd4;

                (*pcVar3)(uVar13,lVar15,0);

                *plVar26 = 0;

                if (*(char *)(param_1 + 0x57c) == '\0') {

                  *(undefined8 *)(auStack_178 + lVar14 + -8) = 0x1401b7c0b;

                  uVar13 = FUN_1401c0ba0(iVar11);

                  *(undefined8 *)(auStack_178 + lVar14 + -8) = 0x1401b7c21;

                  FUN_14012e850("%s %s","vkCreateSemaphore",uVar13);

                  return 0;

                }

                *(undefined8 *)(auStack_178 + lVar14 + -8) = 0x1401b7be8;

                uVar13 = FUN_1401c0ba0(iVar11);

                    /* WARNING: Subroutine does not return */

                *(undefined8 *)(auStack_178 + lVar14 + -8) = 0x1401b7c03;

                FUN_14012e0b0(9,"%s %s","vkCreateSemaphore",uVar13);

              }

              uVar21 = 0;

              uVar20 = (int)uVar16 + 1;

              param_2[uVar16 + 0x12] = 0;

              uVar16 = (ulonglong)uVar20;

            } while (uVar20 < 3);

            uVar20 = *(uint *)(param_2 + 0xc);

            *(undefined8 *)(auStack_178 + lVar14 + -8) = 0x1401b7ade;

            lVar15 = FUN_1401841f0((ulonglong)uVar20 << 3);

            param_2[0x11] = lVar15;

            if ((int)param_2[0xc] != 0) {

              do {

                lVar15 = param_2[0x11];

                pcVar3 = *(code **)(param_1 + 0xb60);

                uVar13 = *(undefined8 *)(param_1 + 0x570);

                *(undefined8 *)(auStack_178 + lVar14 + -8) = 0x1401b7b17;

                iVar11 = (*pcVar3)(uVar13,local_68,0,lVar15 + uVar21 * 8);

                if (iVar11 != 0) {

                  pcVar3 = *(code **)(param_1 + 0xc98);

                  lVar15 = *plVar26;

                  uVar13 = *(undefined8 *)(param_1 + 0x570);

                  *(undefined8 *)(auStack_178 + lVar14 + -8) = 0x1401b7b6e;

                  (*pcVar3)(uVar13,lVar15,0);

                  *plVar26 = 0;

                  if (*(char *)(param_1 + 0x57c) == '\0') {

                    *(undefined8 *)(auStack_178 + lVar14 + -8) = 0x1401b7ba3;

                    uVar13 = FUN_1401c0ba0(iVar11);

                    *(undefined8 *)(auStack_178 + lVar14 + -8) = 0x1401b7bb9;

                    FUN_14012e850("%s %s","vkCreateSemaphore",uVar13);

                    return 0;

                  }

                  *(undefined8 *)(auStack_178 + lVar14 + -8) = 0x1401b7b81;

                  uVar13 = FUN_1401c0ba0(iVar11);

                    /* WARNING: Subroutine does not return */

                  *(undefined8 *)(auStack_178 + lVar14 + -8) = 0x1401b7b9c;

                  FUN_14012e0b0(9,"%s %s","vkCreateSemaphore",uVar13);

                }

                uVar20 = (int)uVar21 + 1;

                uVar21 = (ulonglong)uVar20;

              } while (uVar20 < *(uint *)(param_2 + 0xc));

            }

            *(undefined1 *)((longlong)param_2 + 0x1c) = 0;

            return 1;

          }

        }

        if (*(char *)(param_1 + 0x57c) != '\0') {

          *(undefined8 *)(puVar18 + -8) = 0x1401b7784;

          uVar13 = FUN_1401c0ba0(iVar11);

                    /* WARNING: Subroutine does not return */

          *(undefined8 *)(puVar18 + -8) = 0x1401b779f;

          FUN_14012e0b0(9,"%s %s","vkGetSwapchainImagesKHR",uVar13);

        }

        *(undefined8 *)(puVar18 + -8) = 0x1401b77a6;

        uVar13 = FUN_1401c0ba0(iVar11);

        *(undefined8 *)(puVar18 + -8) = 0x1401b77bc;

        FUN_14012e850("%s %s","vkGetSwapchainImagesKHR",uVar13);

      }

      else {

        *plVar26 = 0;

        if (*(char *)(param_1 + 0x57c) != '\0') {

          uStack_180 = 0x1401b7717;

          uVar13 = FUN_1401c0ba0(iVar11);

                    /* WARNING: Subroutine does not return */

          uStack_180 = 0x1401b7732;

          FUN_14012e0b0(9,"%s %s","vkCreateSwapchainKHR",uVar13);

        }

        uStack_180 = 0x1401b7739;

        uVar13 = FUN_1401c0ba0(iVar11);

        uStack_180 = 0x1401b774f;

        FUN_14012e850("%s %s","vkCreateSwapchainKHR",uVar13);

      }

    }

  }

  return 0;

}




