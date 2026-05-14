// Address: 0x1401bfd60
// Ghidra name: FUN_1401bfd60
// ============ 0x1401bfd60 FUN_1401bfd60 (size=1323) ============


undefined8 FUN_1401bfd60(longlong param_1)



{

  longlong lVar1;

  bool bVar2;

  char cVar3;

  int iVar4;

  undefined8 uVar5;

  longlong lVar6;

  longlong *plVar7;

  uint uVar8;

  ulonglong uVar9;

  longlong lVar10;

  ulonglong uVar11;

  longlong lVar12;

  undefined4 local_f8;

  undefined4 local_f4;

  undefined4 local_f0;

  undefined4 local_ec;

  undefined4 local_e8;

  undefined4 local_e4;

  undefined4 local_e0;

  undefined4 local_dc;

  undefined4 local_d8;

  undefined4 local_d4;

  undefined4 local_d0;

  undefined4 local_cc;

  undefined4 local_c8;

  undefined4 local_c4;

  undefined4 local_c0;

  undefined4 local_bc;

  undefined4 local_b8;

  undefined8 local_b0;

  undefined4 local_a8;

  longlong local_a0;

  undefined4 local_98;

  longlong local_90;

  longlong *local_88;

  undefined8 local_80;

  undefined4 local_78 [2];

  undefined8 local_70;

  undefined4 local_68;

  undefined8 local_60;

  undefined4 *local_58;

  undefined4 local_50;

  longlong local_48;

  undefined4 local_40;

  undefined8 local_38;

  

  lVar1 = *(longlong *)(param_1 + 0x110);

  if (((*(int *)(lVar1 + 0x7b8) == 0) || (*(char *)(param_1 + 0xa99) != '\0')) ||

     (*(int *)(lVar1 + 0x7b8) == 0)) {

    bVar2 = true;

  }

  else {

    bVar2 = false;

  }

  FUN_140179b40(*(undefined8 *)(lVar1 + 0x8d0));

  uVar11 = 0;

  local_f8 = 0x400;

  local_f4 = 0x400;

  local_f0 = 0x400;

  local_ec = 0x400;

  local_e8 = 0x400;

  local_e4 = 0x400;

  local_e0 = 0x400;

  local_dc = 0x400;

  local_d8 = 0x400;

  local_d4 = 0x400;

  local_d0 = 0x400;

  local_cc = 0x400;

  local_c8 = 0x400;

  local_c4 = 0x400;

  local_c0 = 0x400;

  local_bc = 0x400;

  uVar9 = uVar11;

  if (*(int *)(param_1 + 0x130) != 0) {

    do {

      plVar7 = (longlong *)(uVar9 * 0x10 + *(longlong *)(param_1 + 0x128));

      uVar5 = FUN_1401bac70((ulonglong)*(uint *)(plVar7 + 1) * 0x50 + *(longlong *)(*plVar7 + 0x58),

                            0,0);

      FUN_1401bd590(lVar1,param_1,9,uVar5);

      uVar8 = (int)uVar9 + 1;

      uVar9 = (ulonglong)uVar8;

    } while (uVar8 < *(uint *)(param_1 + 0x130));

  }

  if (((bVar2) && (*(int *)(lVar1 + 0x930) != 0)) &&

     ((*(char *)(lVar1 + 0x920) == '\0' && (cVar3 = FUN_1401b8a00(lVar1,param_1), cVar3 == '\0'))))

  {

                    /* WARNING: Subroutine does not return */

    FUN_14012e0b0(9,&DAT_14039bf30,"Failed to defragment memory, likely OOM!");

  }

  cVar3 = FUN_1401b9a20(lVar1,param_1);

  if (cVar3 != '\0') {

    lVar6 = FUN_1401b2320(lVar1);

    *(longlong *)(param_1 + 0xa90) = lVar6;

    if (lVar6 != 0) {

      FUN_140138fb0(lVar6 + 8,1);

      local_48 = param_1 + 0x118;

      local_78[0] = 4;

      local_58 = &local_f8;

      local_60 = *(undefined8 *)(param_1 + 0x138);

      local_68 = *(undefined4 *)(param_1 + 0x140);

      local_38 = *(undefined8 *)(param_1 + 0x148);

      local_40 = *(undefined4 *)(param_1 + 0x150);

      local_70 = 0;

      local_50 = 1;

      iVar4 = (**(code **)(lVar1 + 0xc40))

                        (*(undefined8 *)(lVar1 + 0x7c8),1,local_78,

                         **(undefined8 **)(param_1 + 0xa90));

      if (iVar4 == 0) {

        uVar9 = uVar11;

        if (*(int *)(param_1 + 0x130) != 0) {

          do {

            local_b8 = 0x3b9acde9;

            local_b0 = 0;

            plVar7 = (longlong *)(uVar9 * 0x10 + *(longlong *)(param_1 + 0x128));

            local_88 = plVar7 + 1;

            local_a8 = 1;

            local_a0 = *(longlong *)(*plVar7 + 0x88) + (ulonglong)*(uint *)(plVar7 + 1) * 8;

            local_90 = *plVar7 + 0x30;

            local_98 = 1;

            local_80 = 0;

            iVar4 = (**(code **)(lVar1 + 0xca0))(*(undefined8 *)(lVar1 + 0x7c8));

            if (((iVar4 == 0) || (iVar4 == 0x3b9acdeb)) || (iVar4 == -0x3b9acdec)) {

              *(undefined8 *)(*plVar7 + 0x90 + (ulonglong)*(uint *)(*plVar7 + 0xa8) * 8) =

                   *(undefined8 *)(param_1 + 0xa90);

              FUN_140138fb0(*(longlong *)(param_1 + 0xa90) + 8);

              if ((iVar4 == 0x3b9acdeb) || (iVar4 == -0x3b9acdec)) {

                *(undefined1 *)(*plVar7 + 0x1c) = 1;

              }

            }

            else {

              if (iVar4 != -1000000000) {

                FUN_1401bc930(param_1);

                FUN_140179b60(*(undefined8 *)(lVar1 + 0x8d0));

                if (*(char *)(lVar1 + 0x57c) == '\0') {

                  uVar5 = FUN_1401c0ba0(iVar4);

                  FUN_14012e850("%s %s","vkQueuePresentKHR",uVar5);

                  return 0;

                }

                uVar5 = FUN_1401c0ba0(iVar4);

                    /* WARNING: Subroutine does not return */

                FUN_14012e0b0(9,"%s %s","vkQueuePresentKHR",uVar5);

              }

              *(undefined1 *)(*plVar7 + 0x1c) = 1;

              *(undefined1 *)(*plVar7 + 0x1d) = 1;

            }

            uVar8 = (int)uVar9 + 1;

            uVar9 = (ulonglong)uVar8;

            *(uint *)(*plVar7 + 0xa8) = (*(int *)(*plVar7 + 0xa8) + 1U) % *(uint *)(lVar1 + 0x584);

          } while (uVar8 < *(uint *)(param_1 + 0x130));

        }

        if (bVar2) {

          iVar4 = *(int *)(lVar1 + 0x7d8) + -1;

          lVar6 = (longlong)iVar4;

          if (-1 < iVar4) {

            do {

              iVar4 = (**(code **)(lVar1 + 0xc20))

                                (*(undefined8 *)(lVar1 + 0x570),

                                 **(undefined8 **)

                                   (*(longlong *)(*(longlong *)(lVar1 + 2000) + lVar6 * 8) + 0xa90))

              ;

              if (iVar4 == 0) {

                FUN_1401b55b0(lVar1,*(undefined8 *)(*(longlong *)(lVar1 + 2000) + lVar6 * 8),0);

              }

              lVar6 = lVar6 + -1;

            } while (-1 < lVar6);

          }

          if (*(char *)(lVar1 + 0x7a8) != '\0') {

            FUN_140179b40(*(undefined8 *)(lVar1 + 0x8c0));

            lVar6 = 0x20;

            do {

              lVar12 = *(longlong *)(lVar1 + 0x598) + uVar11;

              iVar4 = *(int *)(lVar12 + 0x10) + -1;

              if (-1 < iVar4) {

                lVar10 = (longlong)iVar4 * 8;

                do {

                  if (*(int *)(*(longlong *)(*(longlong *)(lVar12 + 8) + lVar10) + 0x20) == 0) {

                    FUN_1401b8810(lVar1,lVar12,iVar4);

                  }

                  lVar10 = lVar10 + -8;

                  iVar4 = iVar4 + -1;

                } while (-1 < iVar4);

              }

              uVar11 = uVar11 + 0x28;

              lVar6 = lVar6 + -1;

            } while (lVar6 != 0);

            *(undefined1 *)(lVar1 + 0x7a8) = 0;

            FUN_140179b60(*(undefined8 *)(lVar1 + 0x8c0));

          }

          FUN_1401bbb60(lVar1);

        }

        FUN_1401bc930(param_1);

        FUN_140179b60(*(undefined8 *)(lVar1 + 0x8d0));

        return 1;

      }

      FUN_140179b60(*(undefined8 *)(lVar1 + 0x8d0));

      if (*(char *)(lVar1 + 0x57c) == '\0') {

        uVar5 = FUN_1401c0ba0(iVar4);

        FUN_14012e850("%s %s","vkQueueSubmit",uVar5);

        return 0;

      }

      uVar5 = FUN_1401c0ba0(iVar4);

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(9,"%s %s","vkQueueSubmit",uVar5);

    }

  }

  FUN_140179b60(*(undefined8 *)(lVar1 + 0x8d0));

  return 0;

}




