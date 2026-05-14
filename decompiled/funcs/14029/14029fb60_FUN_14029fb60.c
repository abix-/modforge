// Address: 0x14029fb60
// Ghidra name: FUN_14029fb60
// ============ 0x14029fb60 FUN_14029fb60 (size=522) ============


void FUN_14029fb60(longlong param_1)



{

  undefined8 *puVar1;

  int iVar2;

  undefined4 uVar3;

  undefined4 uVar4;

  undefined4 uVar5;

  undefined8 uVar6;

  undefined8 uVar7;

  undefined8 uVar8;

  undefined8 uVar9;

  undefined8 uVar10;

  undefined8 uVar11;

  char cVar12;

  undefined4 *puVar13;

  undefined4 *puVar14;

  undefined4 *puVar15;

  longlong lVar16;

  ulonglong uVar17;

  int iVar18;

  undefined4 *puVar19;

  longlong lVar20;

  int iVar21;

  ulonglong uVar22;

  uint uVar23;

  bool bVar24;

  

  puVar19 = *(undefined4 **)(param_1 + 8);

  puVar15 = *(undefined4 **)(param_1 + 0x30);

  iVar18 = *(int *)(param_1 + 0x3c);

  uVar23 = (uint)*(byte *)(*(longlong *)(param_1 + 0x58) + 5) * *(int *)(param_1 + 0x38);

  iVar21 = *(int *)(param_1 + 0x18);

  uVar17 = (ulonglong)iVar21;

  iVar2 = *(int *)(param_1 + 0x40);

  uVar22 = (ulonglong)iVar2;

  if (puVar19 < puVar15) {

    bVar24 = puVar15 < (undefined4 *)((longlong)(iVar21 * iVar18) + (longlong)puVar19);

  }

  else {

    bVar24 = puVar19 < (undefined4 *)((longlong)(iVar2 * iVar18) + (longlong)puVar15);

  }

  if (bVar24) {

    if (puVar15 < puVar19) {

      if (iVar18 != 0) {

        do {

          FUN_1402f8e20(puVar15,puVar19,(longlong)(int)uVar23);

          puVar19 = (undefined4 *)((longlong)puVar19 + uVar17);

          puVar15 = (undefined4 *)((longlong)puVar15 + uVar22);

          iVar18 = iVar18 + -1;

        } while (iVar18 != 0);

        return;

      }

    }

    else {

      lVar20 = (longlong)puVar19 + (longlong)((iVar18 + -1) * iVar21);

      lVar16 = (longlong)puVar15 + (longlong)((iVar18 + -1) * iVar2);

      if (iVar18 != 0) {

        do {

          FUN_1402f8e20(lVar16,lVar20,(longlong)(int)uVar23);

          lVar20 = lVar20 - uVar17;

          lVar16 = lVar16 - uVar22;

          iVar18 = iVar18 + -1;

        } while (iVar18 != 0);

        return;

      }

    }

  }

  else {

    cVar12 = FUN_14017fed0();

    if ((((cVar12 == '\0') || (((ulonglong)puVar19 & 0xf) != 0)) || ((uVar17 & 0xf) != 0)) ||

       ((((ulonglong)puVar15 & 0xf) != 0 || ((uVar22 & 0xf) != 0)))) {

      if (iVar18 != 0) {

        do {

          FUN_1402f8e20(puVar15,puVar19,(longlong)(int)uVar23);

          puVar19 = (undefined4 *)((longlong)puVar19 + uVar17);

          puVar15 = (undefined4 *)((longlong)puVar15 + uVar22);

          iVar18 = iVar18 + -1;

        } while (iVar18 != 0);

      }

    }

    else if (iVar18 != 0) {

      do {

        iVar18 = iVar18 + -1;

        puVar13 = puVar15;

        puVar14 = puVar19;

        for (iVar21 = (int)(((int)uVar23 >> 0x1f & 0x3fU) + uVar23) >> 6; iVar21 != 0;

            iVar21 = iVar21 + -1) {

          uVar3 = puVar14[1];

          uVar4 = puVar14[2];

          uVar5 = puVar14[3];

          uVar6 = *(undefined8 *)(puVar14 + 4);

          uVar7 = *(undefined8 *)(puVar14 + 6);

          uVar8 = *(undefined8 *)(puVar14 + 8);

          uVar9 = *(undefined8 *)(puVar14 + 10);

          uVar10 = *(undefined8 *)(puVar14 + 0xc);

          uVar11 = *(undefined8 *)(puVar14 + 0xe);

          *puVar13 = *puVar14;

          puVar13[1] = uVar3;

          puVar13[2] = uVar4;

          puVar13[3] = uVar5;

          puVar13 = puVar13 + 0x10;

          puVar1 = (undefined8 *)

                   ((longlong)puVar15 + (0x10 - (longlong)puVar19) + (longlong)puVar14);

          *puVar1 = uVar6;

          puVar1[1] = uVar7;

          puVar1 = (undefined8 *)

                   ((longlong)puVar15 + (0x20 - (longlong)puVar19) + (longlong)puVar14);

          *puVar1 = uVar8;

          puVar1[1] = uVar9;

          puVar1 = (undefined8 *)

                   ((longlong)puVar15 + (0x30 - (longlong)puVar19) + (longlong)puVar14);

          *puVar1 = uVar10;

          puVar1[1] = uVar11;

          puVar14 = puVar14 + 0x10;

        }

        if ((uVar23 & 0x3f) != 0) {

          FUN_1402f8e20(puVar13,puVar14,uVar23 & 0x3f);

        }

        puVar19 = (undefined4 *)((longlong)puVar19 + uVar17);

        puVar15 = (undefined4 *)((longlong)puVar15 + uVar22);

      } while (iVar18 != 0);

      return;

    }

  }

  return;

}




