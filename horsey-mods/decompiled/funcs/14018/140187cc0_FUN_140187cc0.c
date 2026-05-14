// Address: 0x140187cc0
// Ghidra name: FUN_140187cc0
// ============ 0x140187cc0 FUN_140187cc0 (size=1458) ============


bool FUN_140187cc0(longlong param_1,longlong param_2,char param_3)



{

  undefined1 uVar1;

  undefined4 uVar2;

  int *piVar3;

  bool bVar4;

  char cVar5;

  uint uVar6;

  int iVar7;

  ulonglong uVar8;

  longlong lVar9;

  longlong lVar10;

  ulonglong uVar11;

  undefined8 uVar12;

  undefined4 uVar13;

  ulonglong uVar14;

  uint uVar15;

  int iVar16;

  undefined8 uVar17;

  undefined1 *puVar18;

  undefined2 local_res8 [4];

  undefined4 local_res20;

  undefined4 local_88;

  undefined4 local_84;

  undefined4 local_80;

  undefined4 local_7c;

  undefined4 local_78;

  undefined8 local_60;

  undefined8 uStack_58;

  undefined8 local_50;

  undefined8 uStack_48;

  undefined4 local_40;

  

  uVar13 = 0;

  local_res8[0] = 0x4d42;

  local_40 = 0;

  bVar4 = true;

  local_res20 = 0;

  local_88 = 0;

  local_84 = 0;

  local_80 = 0;

  local_7c = 0;

  local_60 = 0;

  uStack_58 = 0;

  local_78 = 0;

  local_50 = 0;

  uStack_48 = 0;

  cVar5 = FUN_140146f20(*(undefined8 *)(param_1 + 8));

  if (cVar5 == '\0') goto LAB_1401881cd;

  uVar6 = (uint)*(byte *)(*(longlong *)(*(longlong *)(param_1 + 8) + 0x38) + 5) *

          *(int *)(*(longlong *)(param_1 + 8) + 8);

  uVar8 = (ulonglong)(int)uVar6;

  lVar9 = FUN_14012cba0(param_2);

  if ((((lVar9 < 0) || (lVar10 = FUN_14012cbb0(param_2,local_res8,2), lVar10 != 2)) ||

      (cVar5 = FUN_14012cd80(param_2,0), cVar5 == '\0')) ||

     (((cVar5 = FUN_14012cd20(param_2,0), cVar5 == '\0' ||

       (cVar5 = FUN_14012cd20(param_2,0), cVar5 == '\0')) ||

      (cVar5 = FUN_14012cd80(param_2,0), cVar5 == '\0')))) goto LAB_1401881cd;

  lVar10 = *(longlong *)(param_1 + 8);

  uVar12 = 0x28;

  uVar17 = 0;

  iVar7 = *(int *)(lVar10 + 0xc);

  iVar16 = *(int *)(lVar10 + 0x10);

  uVar1 = *(undefined1 *)(*(longlong *)(lVar10 + 0x38) + 4);

  uVar2 = *(undefined4 *)(lVar10 + 8);

  if (*(undefined4 **)(lVar10 + 0x48) != (undefined4 *)0x0) {

    uVar13 = **(undefined4 **)(lVar10 + 0x48);

  }

  if ((*(char *)(param_1 + 0x10) != '\0') && (*(char *)(param_1 + 0x11) == '\0')) {

    uVar12 = 0x7c;

    local_res20 = 0xff0000;

    uVar17 = 3;

    local_88 = 0xff00;

    local_84 = 0xff;

    local_80 = 0xff000000;

    local_7c = 0x73524742;

    local_78 = 2;

  }

  cVar5 = FUN_14012cd80(param_2,uVar12);

  if (((((((cVar5 != '\0') && (cVar5 = thunk_FUN_14012cd80(param_2,uVar2), cVar5 != '\0')) &&

         (cVar5 = thunk_FUN_14012cd80(param_2,iVar7), cVar5 != '\0')) &&

        ((cVar5 = FUN_14012cd20(param_2,1), cVar5 != '\0' &&

         (cVar5 = FUN_14012cd20(param_2,uVar1), cVar5 != '\0')))) &&

       (cVar5 = FUN_14012cd80(param_2,uVar17), cVar5 != '\0')) &&

      ((cVar5 = FUN_14012cd80(param_2,iVar7 * iVar16), cVar5 != '\0' &&

       (cVar5 = FUN_14012cd80(param_2,0), cVar5 != '\0')))) &&

     ((cVar5 = FUN_14012cd80(param_2,0), cVar5 != '\0' &&

      ((cVar5 = FUN_14012cd80(param_2,uVar13), cVar5 != '\0' &&

       (cVar5 = FUN_14012cd80(param_2,0), cVar5 != '\0')))))) {

    if ((*(char *)(param_1 + 0x10) == '\0') || (*(char *)(param_1 + 0x11) != '\0')) {

LAB_14018803d:

      piVar3 = *(int **)(*(longlong *)(param_1 + 8) + 0x48);

      if (piVar3 != (int *)0x0) {

        iVar7 = *piVar3;

        if (0 < (longlong)iVar7) {

          lVar10 = 0;

          puVar18 = (undefined1 *)(*(longlong *)(piVar3 + 2) + 1);

          do {

            cVar5 = FUN_14012ccc0(param_2,puVar18[1]);

            if (((cVar5 == '\0') || (cVar5 = FUN_14012ccc0(param_2,*puVar18), cVar5 == '\0')) ||

               ((cVar5 = FUN_14012ccc0(param_2,puVar18[-1]), cVar5 == '\0' ||

                (cVar5 = FUN_14012ccc0(param_2,puVar18[2]), cVar5 == '\0')))) goto LAB_1401881ad;

            lVar10 = lVar10 + 1;

            puVar18 = puVar18 + 4;

          } while (lVar10 < iVar7);

        }

      }

      iVar7 = FUN_14012cba0(param_2);

      uVar15 = iVar7 - (int)lVar9;

      lVar10 = FUN_14012cb40(param_2,lVar9 + 10,0);

      if (((-1 < lVar10) && (cVar5 = FUN_14012cd80(param_2,uVar15), cVar5 != '\0')) &&

         (lVar10 = FUN_14012cb40(param_2,(ulonglong)uVar15 + lVar9,0), -1 < lVar10)) {

        lVar10 = *(longlong *)(param_1 + 8);

        uVar14 = (longlong)(*(int *)(lVar10 + 0x10) * *(int *)(lVar10 + 0xc)) +

                 *(ulonglong *)(lVar10 + 0x18);

        if ((uVar8 & 3) == 0) {

          iVar7 = 0;

        }

        else {

          iVar7 = 4 - (uVar6 & 3);

        }

        if (*(ulonglong *)(lVar10 + 0x18) < uVar14) {

          uVar14 = uVar14 - (longlong)*(int *)(lVar10 + 0x10);

          uVar11 = FUN_14012cbb0(param_2,uVar14,uVar8);

          while (uVar11 == uVar8) {

            if ((iVar7 != 0) && (iVar16 = 0, 0 < iVar7)) {

              do {

                cVar5 = FUN_14012ccc0(param_2,0);

                if (cVar5 == '\0') goto LAB_1401881ad;

                iVar16 = iVar16 + 1;

              } while (iVar16 < iVar7);

            }

            if (uVar14 <= *(ulonglong *)(*(longlong *)(param_1 + 8) + 0x18)) goto LAB_1401881ff;

            uVar14 = uVar14 - (longlong)*(int *)(*(longlong *)(param_1 + 8) + 0x10);

            uVar11 = FUN_14012cbb0(param_2);

          }

        }

        else {

LAB_1401881ff:

          lVar10 = FUN_14012cba0(param_2);

          if (-1 < lVar10) {

            uVar6 = (int)lVar10 - (int)lVar9;

            lVar10 = FUN_14012cb40(param_2,lVar9 + 2,0);

            if (((-1 < lVar10) && (cVar5 = FUN_14012cd80(param_2,uVar6), cVar5 != '\0')) &&

               (lVar9 = FUN_14012cb40(param_2,(ulonglong)uVar6 + lVar9,0), -1 < lVar9)) {

              FUN_1401489e0(*(undefined8 *)(param_1 + 8));

              bVar4 = false;

              goto LAB_1401881cd;

            }

          }

        }

      }

    }

    else {

      cVar5 = FUN_14012cd80(param_2,local_res20);

      if ((((cVar5 != '\0') && (cVar5 = FUN_14012cd80(param_2,local_88), cVar5 != '\0')) &&

          (cVar5 = FUN_14012cd80(param_2,local_84), cVar5 != '\0')) &&

         ((cVar5 = FUN_14012cd80(param_2,local_80), cVar5 != '\0' &&

          (cVar5 = FUN_14012cd80(param_2,local_7c), cVar5 != '\0')))) {

        lVar10 = 0;

        do {

          cVar5 = FUN_14012cd80(param_2,*(undefined4 *)((longlong)&local_60 + lVar10 * 4));

          if (cVar5 == '\0') goto LAB_1401881ad;

          lVar10 = lVar10 + 1;

        } while (lVar10 < 9);

        cVar5 = FUN_14012cd80(param_2,0);

        if ((((cVar5 != '\0') && (cVar5 = FUN_14012cd80(param_2,0), cVar5 != '\0')) &&

            ((cVar5 = FUN_14012cd80(param_2,0), cVar5 != '\0' &&

             (((cVar5 = FUN_14012cd80(param_2,local_78), cVar5 != '\0' &&

               (cVar5 = FUN_14012cd80(param_2,0), cVar5 != '\0')) &&

              (cVar5 = FUN_14012cd80(param_2,0), cVar5 != '\0')))))) &&

           (cVar5 = FUN_14012cd80(param_2,0), cVar5 != '\0')) goto LAB_14018803d;

      }

    }

  }

LAB_1401881ad:

  bVar4 = true;

LAB_1401881cd:

  if (((param_3 != '\0') && (param_2 != 0)) && (cVar5 = FUN_14012bd50(param_2), cVar5 == '\0')) {

    return false;

  }

  return !bVar4;

}




