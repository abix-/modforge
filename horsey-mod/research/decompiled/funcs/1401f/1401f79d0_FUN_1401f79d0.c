// Address: 0x1401f79d0
// Ghidra name: FUN_1401f79d0
// ============ 0x1401f79d0 FUN_1401f79d0 (size=4150) ============


int FUN_1401f79d0(longlong param_1,uint param_2,uint param_3)



{

  uint *puVar1;

  longlong *plVar2;

  int iVar3;

  longlong lVar4;

  undefined8 *puVar5;

  char cVar6;

  int iVar7;

  uint uVar8;

  int iVar9;

  undefined4 uVar10;

  undefined8 uVar11;

  uint uVar12;

  ulonglong uVar13;

  ulonglong uVar14;

  char *pcVar15;

  longlong lVar16;

  uint uVar17;

  longlong lVar18;

  int iVar19;

  uint local_res20 [2];

  undefined4 local_138;

  undefined8 local_134;

  undefined8 local_12c;

  undefined4 local_124;

  undefined4 uStack_120;

  undefined4 local_11c;

  undefined4 local_118;

  undefined4 local_114;

  undefined8 local_110;

  undefined8 local_108;

  undefined8 local_100;

  undefined8 local_f8;

  undefined8 local_f0;

  undefined4 local_e8;

  undefined8 local_e4;

  undefined4 local_dc;

  undefined8 local_d8;

  undefined4 local_d0;

  undefined4 local_cc;

  undefined8 local_c8;

  undefined8 uStack_c0;

  undefined8 local_b8;

  undefined4 local_a8;

  undefined8 local_a4;

  undefined8 uStack_9c;

  undefined4 local_94;

  undefined8 local_90;

  undefined4 local_88;

  undefined4 local_84;

  undefined4 local_80;

  undefined8 local_7c;

  undefined4 local_74;

  undefined8 local_70;

  undefined8 local_68;

  undefined8 uStack_60;

  undefined4 local_58;

  uint local_54;

  int local_50;

  undefined4 local_4c;

  longlong local_48;

  

  lVar4 = *(longlong *)(param_1 + 0x2e0);

  iVar7 = (*DAT_1403fd130)(*(undefined8 *)(lVar4 + 0x28),*(undefined8 *)(lVar4 + 0x18),lVar4 + 0x6a8

                          );

  if (iVar7 != 0) {

    cVar6 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar6 != '\0') {

      uVar11 = FUN_140241280(iVar7);

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,"%s: %s","vkGetPhysicalDeviceSurfaceCapabilitiesKHR()",uVar11);

    }

    uVar11 = FUN_140241280(iVar7);

    FUN_14012e850("%s: %s","vkGetPhysicalDeviceSurfaceCapabilitiesKHR()",uVar11);

    return iVar7;

  }

  uVar13 = 0;

  if (*(longlong *)(lVar4 + 0x28a0) != 0) {

    uVar14 = uVar13;

    if (*(int *)(lVar4 + 0x2894) != 0) {

      do {

        (*DAT_1403fcff0)(*(undefined8 *)(lVar4 + 0x660),

                         *(undefined8 *)(*(longlong *)(lVar4 + 0x28a0) + uVar14 * 8),0);

        uVar17 = (int)uVar14 + 1;

        uVar14 = (ulonglong)uVar17;

      } while (uVar17 < *(uint *)(lVar4 + 0x2894));

    }

    FUN_1401841e0(*(undefined8 *)(lVar4 + 0x28a0));

    *(undefined8 *)(lVar4 + 0x28a0) = 0;

  }

  if (*(longlong *)(lVar4 + 0x6a0) != 0) {

    uVar14 = uVar13;

    if (*(int *)(lVar4 + 0x2894) != 0) {

      do {

        lVar16 = *(longlong *)(*(longlong *)(lVar4 + 0x6a0) + uVar14 * 8);

        if (lVar16 != 0) {

          (*DAT_1403fcfd8)(*(undefined8 *)(lVar4 + 0x660),lVar16,0);

        }

        uVar17 = (int)uVar14 + 1;

        uVar14 = (ulonglong)uVar17;

      } while (uVar17 < *(uint *)(lVar4 + 0x2894));

    }

    FUN_1401841e0(*(undefined8 *)(lVar4 + 0x6a0));

    *(undefined8 *)(lVar4 + 0x6a0) = 0;

  }

  if (*(longlong *)(lVar4 + 0x688) != 0) {

    (*DAT_1403fd098)(*(undefined8 *)(lVar4 + 0x660),*(undefined8 *)(lVar4 + 0x680),0);

    FUN_1401841e0(*(undefined8 *)(lVar4 + 0x688));

    *(undefined8 *)(lVar4 + 0x688) = 0;

    *(undefined8 *)(lVar4 + 0x698) = 0;

    *(undefined4 *)(lVar4 + 0x690) = 0;

  }

  if (*(longlong *)(lVar4 + 0x6f8) != 0) {

    uVar14 = uVar13;

    if (*(int *)(lVar4 + 0x2894) != 0) {

      do {

        lVar16 = *(longlong *)(*(longlong *)(lVar4 + 0x6f8) + uVar14 * 8);

        if (lVar16 != 0) {

          (*DAT_1403fcfe0)(*(undefined8 *)(lVar4 + 0x660),lVar16,0);

        }

        uVar17 = (int)uVar14 + 1;

        uVar14 = (ulonglong)uVar17;

      } while (uVar17 < *(uint *)(lVar4 + 0x2894));

    }

    FUN_1401841e0(*(undefined8 *)(lVar4 + 0x6f8));

    *(undefined8 *)(lVar4 + 0x6f8) = 0;

  }

  if (*(longlong *)(lVar4 + 0x2840) != 0) {

    if (*(int *)(lVar4 + 0x2894) != 0) {

      do {

        uVar14 = 0;

        if (*(int *)(*(longlong *)(lVar4 + 0x2848) + uVar13 * 4) != 0) {

          do {

            lVar16 = *(longlong *)

                      (*(longlong *)(*(longlong *)(lVar4 + 0x2840) + uVar13 * 8) + uVar14 * 8);

            if (lVar16 != 0) {

              (*DAT_1403fcfc8)(*(undefined8 *)(lVar4 + 0x660),lVar16,0);

            }

            uVar17 = (int)uVar14 + 1;

            uVar14 = (ulonglong)uVar17;

          } while (uVar17 < *(uint *)(*(longlong *)(lVar4 + 0x2848) + uVar13 * 4));

        }

        FUN_1401841e0(*(undefined8 *)(*(longlong *)(lVar4 + 0x2840) + uVar13 * 8));

        uVar17 = (int)uVar13 + 1;

        uVar13 = (ulonglong)uVar17;

      } while (uVar17 < *(uint *)(lVar4 + 0x2894));

    }

    FUN_1401841e0(*(undefined8 *)(lVar4 + 0x2840));

    *(undefined8 *)(lVar4 + 0x2840) = 0;

    FUN_1401841e0(*(undefined8 *)(lVar4 + 0x2848));

    *(undefined8 *)(lVar4 + 0x2848) = 0;

  }

  uVar13 = 0;

  if (*(longlong *)(lVar4 + 0x28b0) != 0) {

    uVar14 = uVar13;

    if (*(int *)(lVar4 + 0x2894) != 0) {

      do {

        lVar16 = *(longlong *)(*(longlong *)(lVar4 + 0x28b0) + uVar14 * 8);

        if (lVar16 != 0) {

          (*DAT_1403fd018)(*(undefined8 *)(lVar4 + 0x660),lVar16,0);

        }

        uVar17 = (int)uVar14 + 1;

        uVar14 = (ulonglong)uVar17;

      } while (uVar17 < *(uint *)(lVar4 + 0x2894));

    }

    FUN_1401841e0(*(undefined8 *)(lVar4 + 0x28b0));

    *(undefined8 *)(lVar4 + 0x28b0) = 0;

  }

  if (*(longlong *)(lVar4 + 0x28b8) != 0) {

    uVar14 = uVar13;

    if (*(int *)(lVar4 + 0x2894) != 0) {

      do {

        lVar16 = *(longlong *)(*(longlong *)(lVar4 + 0x28b8) + uVar14 * 8);

        if (lVar16 != 0) {

          (*DAT_1403fd018)(*(undefined8 *)(lVar4 + 0x660),lVar16,0);

        }

        uVar17 = (int)uVar14 + 1;

        uVar14 = (ulonglong)uVar17;

      } while (uVar17 < *(uint *)(lVar4 + 0x2894));

    }

    FUN_1401841e0(*(undefined8 *)(lVar4 + 0x28b8));

    *(undefined8 *)(lVar4 + 0x28b8) = 0;

  }

  if (*(longlong *)(lVar4 + 0x27d8) != 0) {

    if (*(int *)(lVar4 + 0x2894) != 0) {

      do {

        lVar18 = 0;

        lVar16 = 0x20;

        do {

          FUN_1401f98d0(lVar4,*(longlong *)(*(longlong *)(lVar4 + 0x27d8) + uVar13 * 8) + lVar18);

          lVar18 = lVar18 + 0x20;

          lVar16 = lVar16 + -1;

        } while (lVar16 != 0);

        FUN_1401841e0(*(undefined8 *)(*(longlong *)(lVar4 + 0x27d8) + uVar13 * 8));

        uVar17 = (int)uVar13 + 1;

        uVar13 = (ulonglong)uVar17;

      } while (uVar17 < *(uint *)(lVar4 + 0x2894));

    }

    FUN_1401841e0(*(undefined8 *)(lVar4 + 0x27d8));

    *(undefined8 *)(lVar4 + 0x27d8) = 0;

  }

  uVar13 = 0;

  if (*(longlong *)(lVar4 + 0x27e8) != 0) {

    if (*(int *)(lVar4 + 0x2894) != 0) {

      do {

        uVar14 = 0;

        if (*(int *)(*(longlong *)(lVar4 + 0x27f0) + uVar13 * 4) != 0) {

          do {

            FUN_1401f98d0(lVar4,uVar14 * 0x20 +

                                *(longlong *)(*(longlong *)(lVar4 + 0x27e8) + uVar13 * 8));

            uVar17 = (int)uVar14 + 1;

            uVar14 = (ulonglong)uVar17;

          } while (uVar17 < *(uint *)(*(longlong *)(lVar4 + 0x27f0) + uVar13 * 4));

        }

        FUN_1401841e0(*(undefined8 *)(*(longlong *)(lVar4 + 0x27e8) + uVar13 * 8));

        uVar17 = (int)uVar13 + 1;

        uVar13 = (ulonglong)uVar17;

      } while (uVar17 < *(uint *)(lVar4 + 0x2894));

    }

    FUN_1401841e0(*(undefined8 *)(lVar4 + 0x27e8));

    *(undefined8 *)(lVar4 + 0x27e8) = 0;

    FUN_1401841e0(*(undefined8 *)(lVar4 + 0x27f0));

    *(undefined8 *)(lVar4 + 0x27f0) = 0;

  }

  uVar13 = 0;

  uVar17 = *(uint *)(lVar4 + 0x6ac);

  uVar8 = *(int *)(lVar4 + 0x6a8) + 2;

  *(uint *)(lVar4 + 0x287c) = uVar8;

  if ((uVar17 < uVar8) && (uVar17 != 0)) {

    *(uint *)(lVar4 + 0x287c) = uVar17;

  }

  iVar7 = 0x2c;

  iVar19 = 0;

  if (*(int *)(param_1 + 0x208) == 0x12000500) {

    iVar7 = 0x61;

    iVar19 = 0x3b9c6042;

  }

  else if (*(int *)(param_1 + 0x208) == 0x12002600) {

    iVar7 = 0x40;

    iVar19 = 0x3b9c6048;

  }

  uVar17 = *(uint *)(lVar4 + 0x2878);

  if ((uVar17 == 1) && (**(int **)(lVar4 + 0x6e0) == 0)) {

    *(undefined4 *)(lVar4 + 0x2884) = 0;

    *(int *)(lVar4 + 0x2880) = iVar7;

  }

  else {

    puVar5 = *(undefined8 **)(lVar4 + 0x6e0);

    *(undefined8 *)(lVar4 + 0x2880) = *puVar5;

    *(undefined4 *)(lVar4 + 0x2884) = *(undefined4 *)((longlong)puVar5 + 4);

    if (uVar17 != 0) {

      do {

        if ((*(int *)(puVar5 + uVar13) == iVar7) &&

           (iVar9 = *(int *)((longlong)(puVar5 + uVar13) + 4), iVar9 == iVar19)) {

          *(int *)(lVar4 + 0x2884) = iVar9;

          *(undefined8 *)(lVar4 + 0x2880) = puVar5[uVar13];

          break;

        }

        uVar8 = (int)uVar13 + 1;

        uVar13 = (ulonglong)uVar8;

      } while (uVar8 < uVar17);

    }

  }

  uVar17 = *(uint *)(lVar4 + 0x6b8);

  if ((*(uint *)(lVar4 + 0x6b8) <= param_2) &&

     (uVar17 = param_2, *(uint *)(lVar4 + 0x6c0) < param_2)) {

    uVar17 = *(uint *)(lVar4 + 0x6c0);

  }

  *(uint *)(lVar4 + 0x2888) = uVar17;

  uVar8 = *(uint *)(lVar4 + 0x6bc);

  if ((*(uint *)(lVar4 + 0x6bc) <= param_3) && (uVar8 = param_3, *(uint *)(lVar4 + 0x6c4) < param_3)

     ) {

    uVar8 = *(uint *)(lVar4 + 0x6c4);

  }

  iVar7 = *(int *)(lVar4 + 0x6d0);

  *(uint *)(lVar4 + 0x288c) = uVar8;

  *(int *)(lVar4 + 0x2890) = iVar7;

  if ((iVar7 == 2) || (uVar12 = uVar8, iVar7 == 8)) {

    *(uint *)(lVar4 + 0x2888) = uVar8;

    *(uint *)(lVar4 + 0x288c) = uVar17;

    uVar12 = uVar17;

    uVar17 = uVar8;

  }

  if ((uVar17 == 0) && (uVar12 == 0)) {

    iVar7 = -0x3b9acdec;

  }

  else {

    uVar13 = 0;

    iVar7 = 2;

    iVar19 = 2;

    if (*(int *)(lVar4 + 0x6ec) < 1) {

      local_res20[0] = 0;

      iVar9 = (*DAT_1403fd140)(*(undefined8 *)(lVar4 + 0x28),*(undefined8 *)(lVar4 + 0x18),

                               local_res20,0);

      if (iVar9 != 0) {

        cVar6 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

        if (cVar6 == '\0') {

          uVar11 = FUN_140241280(iVar9);

          FUN_14012e850("%s: %s","vkGetPhysicalDeviceSurfacePresentModesKHR()",uVar11);

          return iVar9;

        }

        uVar11 = FUN_140241280(iVar9);

                    /* WARNING: Subroutine does not return */

        FUN_14012e0b0(6,"%s: %s","vkGetPhysicalDeviceSurfacePresentModesKHR()",uVar11);

      }

      if (local_res20[0] != 0) {

        lVar16 = FUN_1401841a0(local_res20[0],4);

        iVar9 = (*DAT_1403fd140)(*(undefined8 *)(lVar4 + 0x28),*(undefined8 *)(lVar4 + 0x18),

                                 local_res20,lVar16);

        if (iVar9 != 0) {

          cVar6 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

          if (cVar6 == '\0') {

            uVar11 = FUN_140241280(iVar9);

            FUN_14012e850("%s: %s","vkGetPhysicalDeviceSurfacePresentModesKHR()",uVar11);

            FUN_1401841e0(lVar16);

            return iVar9;

          }

          uVar11 = FUN_140241280(iVar9);

                    /* WARNING: Subroutine does not return */

          FUN_14012e0b0(6,"%s: %s","vkGetPhysicalDeviceSurfacePresentModesKHR()",uVar11);

        }

        if (*(int *)(lVar4 + 0x6ec) == 0) {

          uVar14 = uVar13;

          iVar9 = iVar19;

          if (local_res20[0] != 0) {

            do {

              iVar3 = *(int *)(lVar16 + uVar14 * 4);

              iVar19 = 0;

              if (iVar3 == 0) break;

              if (iVar3 == 1) {

                iVar7 = 1;

                iVar19 = iVar7;

              }

              else {

                iVar19 = iVar9;

                if ((iVar9 != 1) && (iVar19 = iVar7, iVar3 == 3)) {

                  iVar7 = 3;

                  iVar19 = 3;

                }

              }

              uVar17 = (int)uVar14 + 1;

              uVar14 = (ulonglong)uVar17;

              iVar9 = iVar19;

            } while (uVar17 < local_res20[0]);

          }

        }

        else if ((*(int *)(lVar4 + 0x6ec) == -1) && (uVar14 = uVar13, local_res20[0] != 0)) {

          do {

            if (*(int *)(lVar16 + uVar14 * 4) == 3) {

              iVar19 = 3;

              break;

            }

            uVar17 = (int)uVar14 + 1;

            uVar14 = (ulonglong)uVar17;

          } while (uVar17 < local_res20[0]);

        }

        FUN_1401841e0(lVar16);

      }

    }

    local_a8 = 0x3b9acde8;

    local_94 = 0;

    local_a4 = 0;

    uStack_9c = 0;

    local_68 = 0;

    uStack_60 = 0;

    local_90 = *(undefined8 *)(lVar4 + 0x18);

    local_88 = *(undefined4 *)(lVar4 + 0x287c);

    local_84 = *(undefined4 *)(lVar4 + 0x2880);

    local_80 = *(undefined4 *)(lVar4 + 0x2884);

    local_7c = *(undefined8 *)(lVar4 + 0x2888);

    local_74 = 1;

    local_70 = 0x12;

    local_58 = *(undefined4 *)(lVar4 + 0x2890);

    local_54 = ~(*(uint *)(*(longlong *)(param_1 + 0x118) + 0x48) >> 0x1e) & 1;

    local_4c = 1;

    local_48 = *(longlong *)(lVar4 + 0x678);

    local_50 = iVar19;

    iVar7 = (*DAT_1403fcfa8)(*(undefined8 *)(lVar4 + 0x660),&local_a8,0,lVar4 + 0x678);

    if (local_48 != 0) {

      (*DAT_1403fd028)(*(undefined8 *)(lVar4 + 0x660),local_48,0);

    }

    if (iVar7 == 0) {

      FUN_1401841e0(*(undefined8 *)(lVar4 + 0x2898));

      puVar1 = (uint *)(lVar4 + 0x2894);

      *(undefined8 *)(lVar4 + 0x2898) = 0;

      iVar7 = (*DAT_1403fd070)(*(undefined8 *)(lVar4 + 0x660),*(undefined8 *)(lVar4 + 0x678),puVar1,

                               0);

      if (iVar7 == 0) {

        uVar11 = FUN_1401841f0((ulonglong)*puVar1 << 3);

        *(undefined8 *)(lVar4 + 0x2898) = uVar11;

        iVar7 = (*DAT_1403fd070)(*(undefined8 *)(lVar4 + 0x660),*(undefined8 *)(lVar4 + 0x678),

                                 puVar1,uVar11);

        if (iVar7 == 0) {

          local_114 = *(undefined4 *)(lVar4 + 0x2880);

          local_134 = 0;

          local_12c = 0;

          local_124 = 0;

          uStack_120 = 0;

          local_11c = 0;

          local_f0 = 1;

          local_138 = 0xf;

          local_110 = 0;

          local_108 = 0;

          local_100 = 1;

          local_f8 = 1;

          local_118 = 1;

          uVar11 = FUN_1401841a0(*puVar1,8);

          *(undefined8 *)(lVar4 + 0x28a0) = uVar11;

          FUN_1401841e0(*(undefined8 *)(lVar4 + 0x28a8));

          uVar11 = FUN_1401841a0(*puVar1,4);

          *(undefined8 *)(lVar4 + 0x28a8) = uVar11;

          uVar14 = uVar13;

          if (*puVar1 != 0) {

            do {

              uVar11 = *(undefined8 *)(*(longlong *)(lVar4 + 0x2898) + uVar14 * 8);

              uStack_120 = (undefined4)uVar11;

              local_11c = (undefined4)((ulonglong)uVar11 >> 0x20);

              iVar7 = (*DAT_1403fcf78)(*(undefined8 *)(lVar4 + 0x660),&local_138,0,

                                       *(longlong *)(lVar4 + 0x28a0) + uVar14 * 8);

              if (iVar7 != 0) {

                FUN_1401f9010(param_1);

                cVar6 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

                if (cVar6 == '\0') {

                  uVar11 = FUN_140241280(iVar7);

                  FUN_14012e850("%s: %s","vkCreateImageView()",uVar11);

                  return iVar7;

                }

                uVar11 = FUN_140241280(iVar7);

                    /* WARNING: Subroutine does not return */

                FUN_14012e0b0(6,"%s: %s","vkCreateImageView()",uVar11);

              }

              uVar17 = (int)uVar14 + 1;

              *(undefined4 *)(*(longlong *)(lVar4 + 0x28a8) + uVar14 * 4) = 0;

              uVar14 = (ulonglong)uVar17;

            } while (uVar17 < *puVar1);

          }

          local_e4 = 0;

          local_dc = 0;

          local_e8 = 0x28;

          local_d8 = *(undefined8 *)(lVar4 + 0x680);

          local_d0 = 0;

          local_cc = *(undefined4 *)(lVar4 + 0x2894);

          uVar11 = FUN_1401841a0(*(undefined4 *)(lVar4 + 0x2894),8);

          *(undefined8 *)(lVar4 + 0x688) = uVar11;

          iVar7 = (*DAT_1403fcea0)(*(undefined8 *)(lVar4 + 0x660),&local_e8,uVar11);

          if (iVar7 != 0) {

            FUN_1401f9010(param_1);

            cVar6 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

            if (cVar6 == '\0') {

              uVar11 = FUN_140241280(iVar7);

              FUN_14012e850("%s: %s","vkAllocateCommandBuffers()",uVar11);

              return iVar7;

            }

            uVar11 = FUN_140241280(iVar7);

                    /* WARNING: Subroutine does not return */

            FUN_14012e0b0(6,"%s: %s","vkAllocateCommandBuffers()",uVar11);

          }

          uVar11 = FUN_1401841a0(*(undefined4 *)(lVar4 + 0x2894),8);

          *(undefined8 *)(lVar4 + 0x6a0) = uVar11;

          uVar14 = uVar13;

          if (*(int *)(lVar4 + 0x2894) != 0) {

            do {

              uStack_c0 = 0;

              local_c8 = 8;

              local_b8 = 1;

              iVar7 = (*DAT_1403fcf58)(*(undefined8 *)(lVar4 + 0x660),&local_c8,0,

                                       *(longlong *)(lVar4 + 0x6a0) + uVar14 * 8);

              if (iVar7 != 0) {

                FUN_1401f9010(param_1);

                cVar6 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

                if (cVar6 == '\0') {

                  uVar11 = FUN_140241280(iVar7);

                  FUN_14012e850("%s: %s","vkCreateFence()",uVar11);

                  return iVar7;

                }

                uVar11 = FUN_140241280(iVar7);

                    /* WARNING: Subroutine does not return */

                FUN_14012e0b0(6,"%s: %s","vkCreateFence()",uVar11);

              }

              uVar17 = (int)uVar14 + 1;

              uVar14 = (ulonglong)uVar17;

            } while (uVar17 < *(uint *)(lVar4 + 0x2894));

          }

          plVar2 = (longlong *)(lVar4 + 0x700);

          if (*plVar2 != 0) {

            (*DAT_1403fd008)(*(undefined8 *)(lVar4 + 0x660),*plVar2,0);

            *plVar2 = 0;

          }

          if (*(longlong *)(lVar4 + 0x708) != 0) {

            (*DAT_1403fd008)(*(undefined8 *)(lVar4 + 0x660),*(longlong *)(lVar4 + 0x708),0);

            *(undefined8 *)(lVar4 + 0x708) = 0;

          }

          uVar11 = FUN_1401841a0(*(undefined4 *)(lVar4 + 0x2894),8);

          *(undefined8 *)(lVar4 + 0x6f8) = uVar11;

          iVar7 = FUN_1401f7010(param_1,*(undefined4 *)(lVar4 + 0x2888),

                                *(undefined4 *)(lVar4 + 0x288c),*(undefined4 *)(lVar4 + 0x2880),

                                *(undefined4 *)(lVar4 + 0x2894),*(undefined8 *)(lVar4 + 0x28a0),

                                uVar11,plVar2);

          if (iVar7 != 0) {

            FUN_1401f9010(param_1);

            cVar6 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

            if (cVar6 == '\0') {

              uVar11 = FUN_140241280(iVar7);

              FUN_14012e850("%s: %s","VULKAN_CreateFramebuffersAndRenderPasses()",uVar11);

              return iVar7;

            }

            uVar11 = FUN_140241280(iVar7);

                    /* WARNING: Subroutine does not return */

            FUN_14012e0b0(6,"%s: %s","VULKAN_CreateFramebuffersAndRenderPasses()",uVar11);

          }

          uVar11 = FUN_1401841a0(*(undefined4 *)(lVar4 + 0x2894),8);

          *(undefined8 *)(lVar4 + 0x2840) = uVar11;

          uVar11 = FUN_1401841a0(*(undefined4 *)(lVar4 + 0x2894),4);

          *(undefined8 *)(lVar4 + 0x2848) = uVar11;

          uVar17 = 0;

          uVar14 = uVar13;

          if (*(int *)(lVar4 + 0x2894) != 0) {

            do {

              *(undefined4 *)(*(longlong *)(lVar4 + 0x2848) + uVar14 * 4) = 1;

              uVar11 = FUN_1401841a0(1,8);

              *(undefined8 *)(*(longlong *)(lVar4 + 0x2840) + uVar14 * 8) = uVar11;

              puVar5 = *(undefined8 **)(*(longlong *)(lVar4 + 0x2840) + uVar14 * 8);

              uVar11 = FUN_1401f5bb0(lVar4);

              *puVar5 = uVar11;

              uVar8 = (int)uVar14 + 1;

              uVar14 = (ulonglong)uVar8;

              uVar17 = *(uint *)(lVar4 + 0x2894);

            } while (uVar8 < uVar17);

          }

          uVar11 = FUN_1401841a0(uVar17,8);

          *(undefined8 *)(lVar4 + 0x28b0) = uVar11;

          uVar11 = FUN_1401841a0(*(undefined4 *)(lVar4 + 0x2894),8);

          *(undefined8 *)(lVar4 + 0x28b8) = uVar11;

          uVar17 = 0;

          uVar14 = uVar13;

          if (*(int *)(lVar4 + 0x2894) != 0) {

            do {

              uVar11 = FUN_1401f7920(lVar4);

              lVar16 = uVar14 * 8;

              *(undefined8 *)(lVar16 + *(longlong *)(lVar4 + 0x28b0)) = uVar11;

              if (*(longlong *)(lVar16 + *(longlong *)(lVar4 + 0x28b0)) == 0) {

LAB_1401f89f6:

                FUN_1401f9010(param_1);

                return -0xd;

              }

              lVar18 = *(longlong *)(lVar4 + 0x28b8);

              uVar11 = FUN_1401f7920(lVar4);

              *(undefined8 *)(lVar18 + lVar16) = uVar11;

              if (*(longlong *)(lVar16 + *(longlong *)(lVar4 + 0x28b8)) == 0) goto LAB_1401f89f6;

              uVar17 = *(uint *)(lVar4 + 0x2894);

              uVar8 = (int)uVar14 + 1;

              uVar14 = (ulonglong)uVar8;

            } while (uVar8 < uVar17);

          }

          uVar11 = FUN_1401841a0(uVar17,8);

          *(undefined8 *)(lVar4 + 0x27d8) = uVar11;

          uVar14 = uVar13;

          if (*(int *)(lVar4 + 0x2894) != 0) {

            do {

              lVar18 = *(longlong *)(lVar4 + 0x27d8);

              lVar16 = uVar14 * 8;

              uVar11 = FUN_1401841a0(0x20);

              uVar17 = (int)uVar14 + 1;

              uVar14 = (ulonglong)uVar17;

              *(undefined8 *)(lVar18 + lVar16) = uVar11;

            } while (uVar17 < *(uint *)(lVar4 + 0x2894));

          }

          FUN_1401841e0(*(undefined8 *)(lVar4 + 0x27e0));

          uVar11 = FUN_1401841a0(*(undefined4 *)(lVar4 + 0x2894),4);

          *(undefined8 *)(lVar4 + 0x27e0) = uVar11;

          uVar11 = FUN_1401841a0(*(undefined4 *)(lVar4 + 0x2894),8);

          *(undefined8 *)(lVar4 + 0x27e8) = uVar11;

          uVar11 = FUN_1401841a0(*(undefined4 *)(lVar4 + 0x2894),4);

          *(undefined8 *)(lVar4 + 0x27f0) = uVar11;

          if (*(int *)(lVar4 + 0x2894) != 0) {

            do {

              *(undefined4 *)(*(longlong *)(lVar4 + 0x27f0) + uVar13 * 4) = 1;

              uVar11 = FUN_1401841a0(1,0x20);

              *(undefined8 *)(*(longlong *)(lVar4 + 0x27e8) + uVar13 * 8) = uVar11;

              iVar7 = FUN_1401f58a0(lVar4,0x10000,0x10,6,1,

                                    *(undefined8 *)(*(longlong *)(lVar4 + 0x27e8) + uVar13 * 8));

              if (iVar7 != 0) {

                FUN_1401f9010(param_1);

                return iVar7;

              }

              uVar17 = (int)uVar13 + 1;

              uVar13 = (ulonglong)uVar17;

            } while (uVar17 < *(uint *)(lVar4 + 0x2894));

          }

          *(undefined4 *)(lVar4 + 0x27fc) = 0xffffffff;

          *(undefined4 *)(lVar4 + 0x27f8) = 0;

          FUN_1401f5580(param_1);

          uVar10 = FUN_14014f090(param_1);

          FUN_140175360(uVar10,"SDL.renderer.vulkan.swapchain_image_count",

                        *(undefined4 *)(lVar4 + 0x2894));

          return 0;

        }

        FUN_1401841e0(*(undefined8 *)(lVar4 + 0x2898));

        *(undefined8 *)(lVar4 + 0x2898) = 0;

      }

      *puVar1 = 0;

      cVar6 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

      if (cVar6 != '\0') {

        uVar11 = FUN_140241280(iVar7);

                    /* WARNING: Subroutine does not return */

        FUN_14012e0b0(6,"%s: %s","vkGetSwapchainImagesKHR()",uVar11);

      }

      uVar11 = FUN_140241280(iVar7);

      pcVar15 = "vkGetSwapchainImagesKHR()";

    }

    else {

      *(undefined8 *)(lVar4 + 0x678) = 0;

      cVar6 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

      if (cVar6 != '\0') {

        uVar11 = FUN_140241280(iVar7);

                    /* WARNING: Subroutine does not return */

        FUN_14012e0b0(6,"%s: %s","vkCreateSwapchainKHR()",uVar11);

      }

      uVar11 = FUN_140241280(iVar7);

      pcVar15 = "vkCreateSwapchainKHR()";

    }

    FUN_14012e850("%s: %s",pcVar15,uVar11);

  }

  return iVar7;

}




