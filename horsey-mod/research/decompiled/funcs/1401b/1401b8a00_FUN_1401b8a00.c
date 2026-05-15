// Address: 0x1401b8a00
// Ghidra name: FUN_1401b8a00
// ============ 0x1401b8a00 FUN_1401b8a00 (size=1228) ============


undefined8 FUN_1401b8a00(longlong param_1,longlong param_2)



{

  longlong *plVar1;

  longlong lVar2;

  longlong lVar3;

  undefined4 uVar4;

  int iVar5;

  uint uVar6;

  longlong *plVar7;

  undefined8 uVar8;

  longlong *plVar9;

  int *piVar10;

  uint uVar11;

  longlong lVar12;

  ulonglong uVar13;

  uint local_res8;

  uint local_res10;

  undefined8 *in_stack_ffffffffffffff18;

  longlong *plVar14;

  undefined8 in_stack_ffffffffffffff20;

  undefined4 uVar15;

  undefined4 local_c8;

  undefined4 local_c4;

  undefined4 local_c0;

  undefined4 local_bc;

  undefined8 local_b8;

  undefined4 local_b0;

  undefined4 local_ac;

  undefined4 local_a8;

  undefined4 local_a4;

  undefined4 local_a0;

  undefined8 local_9c;

  undefined4 local_94;

  uint local_90;

  uint local_8c;

  undefined4 local_88;

  undefined8 local_78;

  undefined8 uStack_70;

  undefined1 local_68 [16];

  int local_58;

  

  *(undefined1 *)(param_1 + 0x920) = 1;

  *(undefined1 *)(param_2 + 0xa9a) = 1;

  FUN_140179b40(*(undefined8 *)(param_1 + 0x8c0));

  FUN_14017cab0(*(undefined8 *)(param_1 + 0x918));

  uVar11 = *(int *)(param_1 + 0x930) - 1;

  lVar12 = (longlong)(int)uVar11;

  if (-1 < (int)uVar11) {

    do {

      iVar5 = FUN_140138fe0(*(longlong *)(*(longlong *)(param_1 + 0x928) + lVar12 * 8) + 0x60);

      if (iVar5 == 0) {

        if (uVar11 != 0xffffffff) {

          lVar12 = *(longlong *)(param_1 + 0x928);

          lVar2 = *(longlong *)(lVar12 + (longlong)(int)uVar11 * 8);

          uVar6 = *(int *)(param_1 + 0x930) - 1;

          if (uVar11 != uVar6) {

            *(undefined8 *)(lVar12 + (longlong)(int)uVar11 * 8) =

                 *(undefined8 *)(lVar12 + (ulonglong)uVar6 * 8);

          }

          *(int *)(param_1 + 0x930) = *(int *)(param_1 + 0x930) + -1;

          uVar13 = 0;

          local_res10 = 0;

          if (*(int *)(lVar2 + 0x20) != 0) goto LAB_1401b8b00;

          goto LAB_1401b8e5b;

        }

        break;

      }

      uVar11 = uVar11 - 1;

      lVar12 = lVar12 + -1;

    } while (-1 < lVar12);

  }

  FUN_14017cae0(*(undefined8 *)(param_1 + 0x918));

  FUN_140179b60(*(undefined8 *)(param_1 + 0x8c0));

  return 1;

LAB_1401b8b00:

  uVar8 = 0;

  uVar11 = (uint)uVar13;

  lVar12 = *(longlong *)(*(longlong *)(lVar2 + 0x18) + uVar13 * 8);

  plVar7 = *(longlong **)(lVar12 + 0x38);

  if (*(char *)(lVar12 + 0x30) == '\0') {

    if ((char)plVar7[10] == '\0') {

      plVar7 = (longlong *)FUN_1401b7d00(param_1,*plVar7);

      if (plVar7 == (longlong *)0x0) goto LAB_1401b8e9c;

      plVar9 = *(longlong **)(lVar12 + 0x38);

      uVar13 = 0;

      local_res8 = 0;

      piVar10 = (int *)*plVar9;

      local_78 = *(undefined8 *)piVar10;

      uStack_70 = *(undefined8 *)(piVar10 + 2);

      local_58 = piVar10[8];

      local_68 = *(undefined1 (*) [16])(piVar10 + 4);

      if (*(int *)((longlong)plVar9 + 0x44) != 0) {

        uVar4 = 1;

        if (*piVar10 == 2) {

          uVar4 = local_68._4_4_;

        }

        do {

          uVar15 = (undefined4)((ulonglong)in_stack_ffffffffffffff20 >> 0x20);

          plVar9 = (longlong *)(plVar9[9] + uVar13 * 0x28);

          plVar1 = (longlong *)(plVar7[9] + uVar13 * 0x28);

          FUN_1401bd590(param_1,param_2,1,plVar9);

          plVar14 = plVar1;

          FUN_1401bd2d0(param_1,param_2,0,2,plVar1);

          local_b8 = 0;

          local_b0 = 0;

          local_c8 = *(undefined4 *)(*plVar9 + 0x38);

          local_c0 = (undefined4)plVar9[1];

          local_bc = 1;

          local_c4 = *(undefined4 *)((longlong)plVar9 + 0xc);

          local_90 = uStack_70._4_4_ >> ((byte)*(undefined4 *)((longlong)plVar9 + 0xc) & 0x1f);

          if (local_90 == 0) {

            local_90 = 1;

          }

          local_8c = (uint)local_68._0_4_ >> ((byte)*(undefined4 *)((longlong)plVar9 + 0xc) & 0x1f);

          local_9c = 0;

          local_94 = 0;

          if (local_8c == 0) {

            local_8c = 1;

          }

          local_ac = *(undefined4 *)(*plVar1 + 0x38);

          local_a4 = (undefined4)plVar1[1];

          local_a0 = 1;

          local_a8 = *(undefined4 *)((longlong)plVar1 + 0xc);

          in_stack_ffffffffffffff20 = CONCAT44(uVar15,1);

          in_stack_ffffffffffffff18 = (undefined8 *)CONCAT44((int)((ulonglong)plVar14 >> 0x20),7);

          local_88 = uVar4;

          (**(code **)(param_1 + 0xa68))

                    (*(undefined8 *)(param_2 + 0x118),

                     *(undefined8 *)(*(longlong *)(lVar12 + 0x38) + 0x18),6,plVar7[3],

                     in_stack_ffffffffffffff18,in_stack_ffffffffffffff20,&local_c8);

          FUN_1401bd5f0(param_1,param_2,2,plVar1);

          FUN_1401bdb50(param_2,*plVar9);

          FUN_1401bdb50(param_2,*plVar1);

          plVar9 = *(longlong **)(lVar12 + 0x38);

          local_res8 = local_res8 + 1;

          uVar13 = (ulonglong)local_res8;

        } while (local_res8 < *(uint *)((longlong)plVar9 + 0x44));

        piVar10 = (int *)*plVar9;

        uVar11 = local_res10;

      }

      *plVar7 = (longlong)piVar10;

      *(undefined4 *)(plVar7 + 1) = *(undefined4 *)(*(longlong *)(lVar12 + 0x38) + 8);

      *(longlong **)

       (*(longlong *)(piVar10 + 0xe) + (ulonglong)*(uint *)(*(longlong *)(lVar12 + 0x38) + 8) * 8) =

           plVar7;

      if (*(longlong **)(lVar12 + 0x38) == *(longlong **)(**(longlong **)(lVar12 + 0x38) + 0x28)) {

        *(longlong **)(*plVar7 + 0x28) = plVar7;

      }

      FUN_1401bca30(param_1,*(undefined8 *)(lVar12 + 0x38));

    }

  }

  else if (*(char *)((longlong)plVar7 + 0x35) == '\0') {

    if (*plVar7 != 0) {

      uVar8 = *(undefined8 *)(*plVar7 + 0x20);

    }

    in_stack_ffffffffffffff18 =

         (undefined8 *)((ulonglong)in_stack_ffffffffffffff18 & 0xffffffffffffff00);

    plVar7 = (longlong *)

             FUN_1401b5a30(param_1,plVar7[5],*(undefined4 *)((longlong)plVar7 + 0x24),(int)plVar7[4]

                           ,in_stack_ffffffffffffff18,uVar8);

    if (plVar7 == (longlong *)0x0) {

LAB_1401b8e9c:

      FUN_14017cae0(*(undefined8 *)(param_1 + 0x918));

      FUN_140179b60(*(undefined8 *)(param_1 + 0x8c0));

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(9,&DAT_14039bf30,"Failed to allocate defrag buffer!");

    }

    in_stack_ffffffffffffff20 = uVar8;

    if ((*(int *)(*(longlong *)(lVar12 + 0x38) + 0x20) == 0) &&

       (*(char *)(*(longlong *)(lVar12 + 0x38) + 0x34) != '\0')) {

      FUN_1401b5050(param_1,param_2,0);

      FUN_1401b5050(param_1,param_2,1,plVar7);

      in_stack_ffffffffffffff18 = &local_78;

      local_68._0_8_ = *(undefined8 *)(lVar12 + 0x20);

      local_78 = 0;

      uStack_70 = 0;

      (**(code **)(param_1 + 0xa60))

                (*(undefined8 *)(param_2 + 0x118),

                 *(undefined8 *)(*(longlong *)(lVar12 + 0x38) + 0x10),plVar7[2],1,

                 in_stack_ffffffffffffff18);

      FUN_1401b50b0(param_1,param_2,1);

      FUN_1401bd730(param_2,*(undefined8 *)(lVar12 + 0x38));

      FUN_1401bd730(param_2,plVar7);

      in_stack_ffffffffffffff20 = uVar8;

    }

    lVar3 = **(longlong **)(lVar12 + 0x38);

    *plVar7 = lVar3;

    uVar6 = *(uint *)(*(longlong *)(lVar12 + 0x38) + 8);

    *(uint *)(plVar7 + 1) = uVar6;

    if ((int)plVar7[4] == 1) {

      plVar9 = *(longlong **)(*(longlong *)(lVar12 + 0x38) + 0x38);

LAB_1401b8c38:

      *plVar9 = (longlong)plVar7;

    }

    else {

      *(longlong **)(*(longlong *)(lVar3 + 8) + (ulonglong)uVar6 * 8) = plVar7;

      plVar9 = (longlong *)*plVar7;

      if (*plVar9 == *(longlong *)(lVar12 + 0x38)) goto LAB_1401b8c38;

    }

    lVar3 = *(longlong *)(*(longlong *)(lVar12 + 0x38) + 0x38);

    if (lVar3 != 0) {

      plVar7[7] = lVar3;

    }

    FUN_1401bc800(param_1,*(undefined8 *)(lVar12 + 0x38));

  }

  local_res10 = uVar11 + 1;

  uVar13 = (ulonglong)local_res10;

  if (*(uint *)(lVar2 + 0x20) <= local_res10) {

LAB_1401b8e5b:

    FUN_14017cae0(*(undefined8 *)(param_1 + 0x918));

    FUN_140179b60(*(undefined8 *)(param_1 + 0x8c0));

    return 1;

  }

  goto LAB_1401b8b00;

}




