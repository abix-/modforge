// Address: 0x1401d09c0
// Ghidra name: FUN_1401d09c0
// ============ 0x1401d09c0 FUN_1401d09c0 (size=1108) ============


undefined8 FUN_1401d09c0(longlong param_1)



{

  byte bVar1;

  code *pcVar2;

  bool bVar3;

  int iVar4;

  uint uVar5;

  uint uVar6;

  uint uVar7;

  undefined4 *puVar8;

  longlong lVar9;

  undefined4 *puVar10;

  int iVar11;

  uint uVar12;

  int iVar13;

  int iVar14;

  int iVar15;

  int iVar16;

  uint uVar17;

  int iVar18;

  int local_res18;

  longlong local_98;

  undefined4 *local_78;

  undefined4 *local_70;

  ulonglong local_60;

  

  lVar9 = *(longlong *)(param_1 + 0xb8);

  bVar1 = *(byte *)(*(longlong *)(param_1 + 0x38) + 5);

  if (lVar9 != 0) {

    if (bVar1 == 1) {

      iVar4 = ((*(int *)(param_1 + 8) / 2 + 1) * *(int *)(param_1 + 0xc) + 2) * 3;

    }

    else if ((bVar1 == 2) || (bVar1 == 3)) {

      iVar4 = (*(int *)(param_1 + 8) * (uint)bVar1 + 2 + (*(int *)(param_1 + 8) / 0xff) * 2) *

              *(int *)(param_1 + 0xc) + 6;

    }

    else {

      if (bVar1 != 4) {

        return 0;

      }

      iVar4 = (*(int *)(param_1 + 8) + 1 + *(int *)(param_1 + 8) / 0xffff) * *(int *)(param_1 + 0xc)

              * 4 + 8;

    }

    puVar8 = (undefined4 *)FUN_1401841f0((longlong)iVar4);

    if (puVar8 != (undefined4 *)0x0) {

      uVar12 = (uint)bVar1;

      *puVar8 = *(undefined4 *)(lVar9 + 4);

      puVar10 = puVar8 + 1;

      local_98 = *(longlong *)(param_1 + 0x18);

      iVar4 = *(int *)(param_1 + 8);

      uVar17 = ~*(uint *)(*(longlong *)(param_1 + 0x38) + 0x14);

      iVar18 = 0xff;

      if (uVar12 == 4) {

        iVar18 = 0xffff;

      }

      uVar5 = *(uint *)(param_1 + 0x10c) & uVar17;

      pcVar2 = *(code **)("SDL_NO_SIGNAL_HANDLERS" + (longlong)(int)uVar12 * 8 + 0x10);

      local_60 = (ulonglong)*(uint *)(param_1 + 0xc);

      local_78 = puVar10;

      local_70 = puVar10;

      if (0 < (int)*(uint *)(param_1 + 0xc)) {

        do {

          iVar11 = 0;

          local_res18 = 0;

          bVar3 = false;

          do {

            iVar13 = iVar11;

            if (iVar11 < iVar4) {

              iVar14 = iVar11 * uVar12;

              do {

                uVar6 = (*pcVar2)(iVar14 + local_98);

                local_res18 = iVar13;

                if ((uVar6 & uVar17) != uVar5) break;

                iVar13 = iVar13 + 1;

                iVar14 = iVar14 + uVar12;

                local_res18 = iVar13;

              } while (iVar13 < iVar4);

            }

            uVar6 = (uint)bVar1;

            iVar14 = iVar13;

            if (iVar13 < iVar4) {

              iVar15 = iVar13 * uVar6;

              do {

                uVar7 = (*pcVar2)(iVar15 + local_98);

                local_res18 = iVar14;

                if ((uVar7 & uVar17) == uVar5) break;

                iVar14 = iVar14 + 1;

                iVar15 = iVar15 + uVar6;

                local_res18 = iVar14;

              } while (iVar14 < iVar4);

            }

            iVar11 = iVar13 - iVar11;

            if (iVar11 == iVar4) {

              bVar3 = true;

            }

            iVar15 = iVar14 - iVar13;

            for (; iVar18 < iVar11; iVar11 = iVar11 - iVar18) {

              if (bVar1 == 4) {

                *(short *)local_78 = (short)iVar18;

                lVar9 = 4;

                *(undefined2 *)((longlong)local_78 + 2) = 0;

              }

              else {

                *(char *)local_78 = (char)iVar18;

                lVar9 = 2;

                *(undefined1 *)((longlong)local_78 + 1) = 0;

              }

              local_78 = (undefined4 *)((longlong)local_78 + lVar9);

              iVar14 = local_res18;

            }

            iVar16 = iVar18;

            if (iVar15 < iVar18) {

              iVar16 = iVar15;

            }

            if (bVar1 == 4) {

              *(short *)local_78 = (short)iVar11;

              lVar9 = 4;

              *(short *)((longlong)local_78 + 2) = (short)iVar16;

            }

            else {

              *(char *)local_78 = (char)iVar11;

              lVar9 = 2;

              *(char *)((longlong)local_78 + 1) = (char)iVar16;

            }

            FUN_1402f8e20((undefined1 *)(lVar9 + (longlong)local_78),

                          (int)(iVar13 * uVar6) + local_98,(longlong)iVar16 * (longlong)(int)uVar6);

            iVar13 = iVar13 + iVar16;

            local_78 = (undefined4 *)((longlong)local_78 + (int)(iVar16 * uVar6) + lVar9);

            iVar15 = iVar15 - iVar16;

            iVar11 = iVar14;

            while (iVar15 != 0) {

              iVar11 = iVar18;

              if (iVar15 < iVar18) {

                iVar11 = iVar15;

              }

              if (bVar1 == 4) {

                *(short *)((longlong)local_78 + 2) = (short)iVar11;

                *(undefined2 *)local_78 = 0;

                lVar9 = 4;

              }

              else {

                *(undefined1 *)local_78 = 0;

                lVar9 = 2;

                *(char *)((longlong)local_78 + 1) = (char)iVar11;

              }

              FUN_1402f8e20((undefined1 *)(lVar9 + (longlong)local_78),

                            (int)(iVar13 * uVar6) + local_98,(longlong)iVar11 * (ulonglong)bVar1);

              iVar13 = iVar13 + iVar11;

              local_78 = (undefined4 *)((longlong)local_78 + (int)(iVar11 * uVar6) + lVar9);

              iVar15 = iVar15 - iVar11;

              iVar11 = local_res18;

            }

            puVar10 = local_78;

            if (bVar3) {

              puVar10 = local_70;

            }

            local_70 = puVar10;

          } while (iVar11 < iVar4);

          local_98 = local_98 + *(int *)(param_1 + 0x10);

          local_60 = local_60 - 1;

        } while (local_60 != 0);

      }

      lVar9 = 4;

      if (bVar1 == 4) {

        *puVar10 = 0;

      }

      else {

        *(undefined2 *)puVar10 = 0;

        lVar9 = 2;

      }

      puVar10 = (undefined4 *)

                FUN_140184230(puVar8,(undefined1 *)((longlong)puVar10 + (lVar9 - (longlong)puVar8)))

      ;

      if (puVar10 == (undefined4 *)0x0) {

        puVar10 = puVar8;

      }

      *(undefined4 **)(param_1 + 0x88) = puVar10;

      return 1;

    }

  }

  return 0;

}




