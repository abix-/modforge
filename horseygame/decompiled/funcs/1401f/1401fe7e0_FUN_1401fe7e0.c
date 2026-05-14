// Address: 0x1401fe7e0
// Ghidra name: FUN_1401fe7e0
// ============ 0x1401fe7e0 FUN_1401fe7e0 (size=1242) ============


undefined8

FUN_1401fe7e0(longlong param_1,longlong param_2,longlong param_3,longlong param_4,

             undefined8 *param_5,int param_6,undefined4 param_7,ulonglong param_8,undefined4 param_9

             ,undefined8 param_10,undefined8 *param_11,undefined8 param_12)



{

  undefined8 *puVar1;

  undefined4 *puVar2;

  int iVar3;

  longlong lVar4;

  longlong lVar5;

  undefined8 uVar6;

  bool bVar7;

  char cVar8;

  int iVar9;

  int iVar10;

  int *piVar11;

  longlong lVar12;

  undefined8 uVar13;

  int iVar14;

  longlong lVar15;

  uint uVar16;

  longlong local_res8;

  longlong local_res10;

  undefined8 in_stack_ffffffffffffff48;

  undefined4 uVar17;

  undefined8 in_stack_ffffffffffffff50;

  undefined4 uVar18;

  undefined8 in_stack_ffffffffffffff58;

  undefined4 uVar19;

  undefined8 in_stack_ffffffffffffff60;

  undefined4 uVar20;

  undefined8 local_88;

  undefined8 uStack_80;

  undefined8 local_78;

  undefined8 uStack_70;

  undefined8 local_68 [6];

  

  uVar17 = (undefined4)((ulonglong)in_stack_ffffffffffffff48 >> 0x20);

  uVar18 = (undefined4)((ulonglong)in_stack_ffffffffffffff50 >> 0x20);

  uVar19 = (undefined4)((ulonglong)in_stack_ffffffffffffff58 >> 0x20);

  uVar20 = (undefined4)((ulonglong)in_stack_ffffffffffffff60 >> 0x20);

  lVar4 = *(longlong *)(param_1 + 0x2e0);

  iVar10 = *(int *)(param_2 + 0x2c);

  iVar3 = *(int *)(lVar4 + 0x2880);

  if (param_11 == (undefined8 *)0x0) {

    param_11 = (undefined8 *)(lVar4 + 0x292c);

  }

  bVar7 = false;

  local_res10 = param_2;

  iVar9 = FUN_1401eb3f0(param_5);

  cVar8 = FUN_1401f56c0(param_1,0,0,param_12);

  if (cVar8 != '\0') {

    piVar11 = *(int **)(lVar4 + 0x2868);

    if (((((piVar11 == (int *)0x0) || (*piVar11 != iVar9)) || (piVar11[0xd] != iVar10)) ||

        ((piVar11[0xe] != param_6 || (piVar11[0xf] != iVar3)))) ||

       ((*(longlong *)(piVar11 + 0x10) != param_3 || (*(longlong *)(piVar11 + 0x12) != param_4)))) {

      iVar14 = 0;

      *(undefined8 *)(lVar4 + 0x2868) = 0;

      if (0 < *(int *)(lVar4 + 0x2858)) {

        piVar11 = *(int **)(lVar4 + 0x2860);

        do {

          if (((*piVar11 == iVar9) && (piVar11[0xd] == iVar10)) &&

             ((piVar11[0xe] == param_6 &&

              (((piVar11[0xf] == iVar3 && (*(longlong *)(piVar11 + 0x10) == param_3)) &&

               (*(longlong *)(piVar11 + 0x12) == param_4)))))) {

            *(int **)(lVar4 + 0x2868) = piVar11;

            break;

          }

          iVar14 = iVar14 + 1;

          piVar11 = piVar11 + 0x16;

        } while (iVar14 < *(int *)(lVar4 + 0x2858));

      }

      lVar12 = *(longlong *)(lVar4 + 0x2868);

      if (lVar12 == 0) {

        lVar12 = FUN_1401f73c0(param_1,iVar9,param_3,param_4,CONCAT44(uVar17,iVar10),

                               CONCAT44(uVar18,param_6),CONCAT44(uVar19,iVar3));

        *(longlong *)(lVar4 + 0x2868) = lVar12;

        if (lVar12 == 0) {

          uVar13 = FUN_14012e850("Unable to create required pipeline state");

          return uVar13;

        }

      }

      (*DAT_1403fcee0)(*(undefined8 *)(lVar4 + 0x698),0,*(undefined8 *)(lVar12 + 0x50));

      bVar7 = true;

    }

    if ((*(char *)(lVar4 + 0x2928) != '\0') && (cVar8 = FUN_1401ffc70(param_1), cVar8 != '\0')) {

      bVar7 = true;

    }

    if (*(char *)(lVar4 + 0x2900) != '\0') {

      FUN_1401ff210(param_1);

    }

    if ((bVar7) || (iVar10 = memcmp((void *)(lVar4 + 0x2758),param_11,0x40), iVar10 != 0)) {

      uVar13 = param_11[1];

      *(undefined8 *)(lVar4 + 0x2758) = *param_11;

      *(undefined8 *)(lVar4 + 0x2760) = uVar13;

      uVar13 = param_11[3];

      *(undefined8 *)(lVar4 + 0x2768) = param_11[2];

      *(undefined8 *)(lVar4 + 0x2770) = uVar13;

      uVar17 = *(undefined4 *)((longlong)param_11 + 0x24);

      uVar18 = *(undefined4 *)(param_11 + 5);

      uVar19 = *(undefined4 *)((longlong)param_11 + 0x2c);

      *(undefined4 *)(lVar4 + 0x2778) = *(undefined4 *)(param_11 + 4);

      *(undefined4 *)(lVar4 + 0x277c) = uVar17;

      *(undefined4 *)(lVar4 + 0x2780) = uVar18;

      *(undefined4 *)(lVar4 + 0x2784) = uVar19;

      uVar17 = *(undefined4 *)((longlong)param_11 + 0x34);

      uVar18 = *(undefined4 *)(param_11 + 7);

      uVar19 = *(undefined4 *)((longlong)param_11 + 0x3c);

      *(undefined4 *)(lVar4 + 0x2788) = *(undefined4 *)(param_11 + 6);

      *(undefined4 *)(lVar4 + 0x278c) = uVar17;

      *(undefined4 *)(lVar4 + 0x2790) = uVar18;

      *(undefined4 *)(lVar4 + 0x2794) = uVar19;

      (*DAT_1403fcf20)(*(undefined8 *)(lVar4 + 0x698),

                       *(undefined8 *)(*(longlong *)(lVar4 + 0x2868) + 0x40),1,0,0x80,

                       (undefined8 *)(lVar4 + 0x2758));

    }

    if (param_5 == (undefined8 *)0x0) {

      FUN_1401fedf0(param_1,local_res10,0,local_68);

      param_5 = local_68;

    }

    uVar13 = *(undefined8 *)

              (*(longlong *)

                (*(longlong *)(lVar4 + 0x27e8) + (ulonglong)*(uint *)(lVar4 + 0x690) * 8) + 8 +

              (ulonglong)*(uint *)(lVar4 + 0x27f8) * 0x20);

    iVar10 = 0;

    if (-1 < *(int *)(lVar4 + 0x27fc)) {

      iVar10 = *(int *)(lVar4 + 0x27fc);

    }

    lVar12 = (longlong)iVar10;

    if ((bVar7) ||

       (iVar10 = memcmp(param_5,(void *)(*(longlong *)(lVar4 + 0x2868) + 4),0x30), iVar10 != 0)) {

      if (*(int *)(lVar4 + 0x27fc) == -1) {

        *(undefined4 *)(lVar4 + 0x27fc) = 0;

        lVar12 = 0;

      }

      else {

        iVar10 = (-*(int *)(lVar4 + 0x298) & *(int *)(lVar4 + 0x298) + 0x2fU) +

                 *(int *)(lVar4 + 0x27fc);

        *(int *)(lVar4 + 0x27fc) = iVar10;

        lVar12 = (longlong)iVar10;

        if (0xffff < iVar10) {

          uVar16 = *(int *)(lVar4 + 0x27f8) + 1;

          if (*(uint *)(*(longlong *)(lVar4 + 0x27f0) + (ulonglong)*(uint *)(lVar4 + 0x690) * 4) <=

              uVar16) {

            iVar10 = FUN_1401f58a0(lVar4,0x10000,0x10,6,1,&local_88);

            if (iVar10 != 0) {

              return 0;

            }

            piVar11 = (int *)(*(longlong *)(lVar4 + 0x27f0) +

                             (ulonglong)*(uint *)(lVar4 + 0x690) * 4);

            *piVar11 = *piVar11 + 1;

            lVar12 = FUN_140184230(*(undefined8 *)

                                    (*(longlong *)(lVar4 + 0x27e8) +

                                    (ulonglong)*(uint *)(lVar4 + 0x690) * 8),

                                   (ulonglong)

                                   *(uint *)(*(longlong *)(lVar4 + 0x27f0) +

                                            (ulonglong)*(uint *)(lVar4 + 0x690) * 4) << 5);

            lVar15 = (ulonglong)

                     (*(int *)(*(longlong *)(lVar4 + 0x27f0) +

                              (ulonglong)*(uint *)(lVar4 + 0x690) * 4) - 1) * 0x20;

            puVar1 = (undefined8 *)(lVar15 + lVar12);

            *puVar1 = local_88;

            puVar1[1] = uStack_80;

            puVar1 = (undefined8 *)(lVar15 + 0x10 + lVar12);

            *puVar1 = local_78;

            puVar1[1] = uStack_70;

            *(longlong *)(*(longlong *)(lVar4 + 0x27e8) + (ulonglong)*(uint *)(lVar4 + 0x690) * 8) =

                 lVar12;

          }

          *(uint *)(lVar4 + 0x27f8) = uVar16;

          *(undefined4 *)(lVar4 + 0x27fc) = 0;

          uVar13 = *(undefined8 *)

                    (*(longlong *)

                      (*(longlong *)(lVar4 + 0x27e8) + (ulonglong)*(uint *)(lVar4 + 0x690) * 8) + 8

                    + (ulonglong)uVar16 * 0x20);

          lVar12 = 0;

        }

      }

      lVar15 = *(longlong *)(lVar4 + 0x2868);

      uVar6 = param_5[1];

      *(undefined8 *)(lVar15 + 4) = *param_5;

      *(undefined8 *)(lVar15 + 0xc) = uVar6;

      uVar6 = param_5[3];

      *(undefined8 *)(lVar15 + 0x14) = param_5[2];

      *(undefined8 *)(lVar15 + 0x1c) = uVar6;

      uVar6 = param_5[5];

      *(undefined8 *)(lVar15 + 0x24) = param_5[4];

      *(undefined8 *)(lVar15 + 0x2c) = uVar6;

      lVar15 = *(longlong *)(lVar4 + 0x2868);

      uVar6 = *(undefined8 *)(lVar15 + 0xc);

      lVar5 = *(longlong *)

               (*(longlong *)

                 (*(longlong *)(lVar4 + 0x27e8) + (ulonglong)*(uint *)(lVar4 + 0x690) * 8) + 0x18 +

               (ulonglong)*(uint *)(lVar4 + 0x27f8) * 0x20);

      *(undefined8 *)(lVar5 + lVar12) = *(undefined8 *)(lVar15 + 4);

      ((undefined8 *)(lVar5 + lVar12))[1] = uVar6;

      uVar6 = *(undefined8 *)(lVar15 + 0x1c);

      puVar1 = (undefined8 *)(lVar5 + 0x10 + lVar12);

      *puVar1 = *(undefined8 *)(lVar15 + 0x14);

      puVar1[1] = uVar6;

      uVar17 = *(undefined4 *)(lVar15 + 0x28);

      uVar18 = *(undefined4 *)(lVar15 + 0x2c);

      uVar19 = *(undefined4 *)(lVar15 + 0x30);

      puVar2 = (undefined4 *)(lVar5 + 0x20 + lVar12);

      *puVar2 = *(undefined4 *)(lVar15 + 0x24);

      puVar2[1] = uVar17;

      puVar2[2] = uVar18;

      puVar2[3] = uVar19;

    }

    local_res8 = FUN_1401f5ca0(param_1,iVar9,param_4,uVar13,lVar12,param_7,param_8,

                               CONCAT44(uVar20,param_9),param_10);

    if (local_res8 != 0) {

      (*DAT_1403fced8)(*(undefined8 *)(lVar4 + 0x698),0,

                       *(undefined8 *)(*(longlong *)(lVar4 + 0x2868) + 0x40),0,1,&local_res8,

                       param_8 & 0xffffffff00000000,0);

      return 1;

    }

  }

  return 0;

}




