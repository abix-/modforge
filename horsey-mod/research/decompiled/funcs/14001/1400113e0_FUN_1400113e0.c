// Address: 0x1400113e0
// Ghidra name: FUN_1400113e0
// ============ 0x1400113e0 FUN_1400113e0 (size=1002) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_1400113e0(longlong param_1,longlong param_2,longlong param_3)



{

  int iVar1;

  int iVar2;

  int iVar3;

  uint uVar4;

  longlong lVar5;

  int *piVar6;

  int *piVar7;

  undefined8 *puVar8;

  longlong lVar9;

  longlong *plVar10;

  undefined8 uVar11;

  char cVar12;

  longlong lVar13;

  longlong lVar14;

  

  lVar13 = *(longlong *)(param_2 + 0x10);

  lVar5 = *(longlong *)(param_3 + 0x10);

  iVar1 = *(int *)(param_2 + 0x18);

  iVar2 = *(int *)(param_3 + 0x18);

  piVar6 = *(int **)(lVar13 + 0x10);

  piVar7 = *(int **)(lVar5 + 0x10);

  if (piVar6 != piVar7) {

    for (puVar8 = *(undefined8 **)(piVar7 + 0x22); puVar8 != (undefined8 *)0x0;

        puVar8 = (undefined8 *)puVar8[3]) {

      if ((int *)*puVar8 == piVar6) {

        lVar9 = puVar8[1];

        if ((((*(longlong *)(lVar9 + 0x60) == lVar13) && (*(longlong *)(lVar9 + 0x68) == lVar5)) &&

            (*(int *)(lVar9 + 0x70) == iVar1)) && (*(int *)(lVar9 + 0x74) == iVar2)) {

          return;

        }

        if (((*(longlong *)(lVar9 + 0x60) == lVar5) && (*(longlong *)(lVar9 + 0x68) == lVar13)) &&

           ((*(int *)(lVar9 + 0x70) == iVar2 && (*(int *)(lVar9 + 0x74) == iVar1)))) {

          return;

        }

      }

    }

    if ((*piVar7 == 2) || (*piVar6 == 2)) {

      for (puVar8 = *(undefined8 **)(piVar7 + 0x20); puVar8 != (undefined8 *)0x0;

          puVar8 = (undefined8 *)puVar8[3]) {

        if (((int *)*puVar8 == piVar6) && (*(char *)(puVar8[1] + 0x71) == '\0')) {

          return;

        }

      }

      plVar10 = *(longlong **)(param_1 + 0x68);

      if ((plVar10 == (longlong *)0x0) ||

         (cVar12 = (**(code **)(*plVar10 + 8))(plVar10,lVar13,lVar5), cVar12 != '\0')) {

        uVar11 = *(undefined8 *)(param_1 + 0x78);

        if (DAT_1403ff7b4 == '\0') {

          DAT_1403ff7d0 = 1;

          _DAT_1403ff880 = FUN_14001e250;

          _DAT_1403ff7c0 = FUN_14001de50;

          _DAT_1403ff7c8 = FUN_14001dbf0;

          _DAT_1403ff888 = FUN_14001dbf0;

          _DAT_1403ff7f8 = FUN_14001dbf0;

          _DAT_1403ff8b0 = FUN_14001e380;

          _DAT_1403ff8b8 = FUN_14001dbf0;

          _DAT_1403ff7f0 = FUN_14001e250;

          _DAT_1403ff828 = FUN_14001dbf0;

          _DAT_1403ff7e0 = FUN_14001dbf0;

          _DAT_1403ff820 = FUN_14001e4b0;

          _DAT_1403ff7d8 = FUN_14001e4b0;

          _DAT_1403ff858 = FUN_14001dbf0;

          _DAT_1403ff8a0 = FUN_14001dbf0;

          _DAT_1403ff850 = FUN_14001dcf0;

          _DAT_1403ff898 = FUN_14001dcf0;

          _DAT_1403ff8e8 = FUN_14001dbf0;

          _DAT_1403ff810 = FUN_14001dbf0;

          _DAT_1403ff8e0 = FUN_14001dac0;

          _DAT_1403ff808 = FUN_14001dac0;

          _DAT_1403ff918 = FUN_14001dbf0;

          _DAT_1403ff8d0 = FUN_14001dbf0;

          DAT_1403ff890 = 1;

          DAT_1403ff800 = 0;

          DAT_1403ff8c0 = 1;

          DAT_1403ff830 = 1;

          DAT_1403ff7e8 = 0;

          DAT_1403ff860 = 1;

          DAT_1403ff8a8 = 0;

          DAT_1403ff8f0 = 1;

          DAT_1403ff818 = 0;

          _DAT_1403ff910 = FUN_14001e070;

          DAT_1403ff920 = 1;

          _DAT_1403ff8c8 = FUN_14001e070;

          DAT_1403ff8d8 = 0;

          DAT_1403ff7b4 = '\x01';

        }

        iVar3 = *(int *)(*(longlong *)(lVar13 + 0x18) + 8);

        uVar4 = *(uint *)(*(longlong *)(lVar5 + 0x18) + 8);

        if ((iVar3 < 0) || (3 < iVar3)) {

          FID_conflict__assert

                    (L"0 <= type1 && type1 < b2Shape::e_typeCount",

                     L"C:\\dev\\Box2d2\\Box2D\\Dynamics\\Contacts\\b2Contact.cpp",0x50);

        }

        if (3 < uVar4) {

          FID_conflict__assert

                    (L"0 <= type2 && type2 < b2Shape::e_typeCount",

                     L"C:\\dev\\Box2d2\\Box2D\\Dynamics\\Contacts\\b2Contact.cpp",0x51);

        }

        lVar9 = (longlong)(int)uVar4 + (longlong)iVar3 * 4;

        if (*(code **)(&DAT_1403ff7c0 + lVar9 * 0x18) != (code *)0x0) {

          lVar14 = lVar5;

          iVar3 = iVar2;

          if ((&DAT_1403ff7d0)[lVar9 * 0x18] != '\0') {

            lVar14 = lVar13;

            lVar13 = lVar5;

            iVar3 = iVar1;

            iVar1 = iVar2;

          }

          lVar13 = (**(code **)(&DAT_1403ff7c0 + lVar9 * 0x18))(lVar14,iVar3,lVar13,iVar1,uVar11);

          if (lVar13 != 0) {

            lVar5 = *(longlong *)(*(longlong *)(lVar13 + 0x60) + 0x10);

            lVar9 = *(longlong *)(*(longlong *)(lVar13 + 0x68) + 0x10);

            *(undefined8 *)(lVar13 + 0x10) = 0;

            *(undefined8 *)(lVar13 + 0x18) = *(undefined8 *)(param_1 + 0x58);

            if (*(longlong *)(param_1 + 0x58) != 0) {

              *(longlong *)(*(longlong *)(param_1 + 0x58) + 0x10) = lVar13;

            }

            *(longlong *)(param_1 + 0x58) = lVar13;

            plVar10 = (longlong *)(lVar13 + 0x20);

            *(longlong *)(lVar13 + 0x28) = lVar13;

            *plVar10 = lVar9;

            *(undefined8 *)(lVar13 + 0x30) = 0;

            *(undefined8 *)(lVar13 + 0x38) = *(undefined8 *)(lVar5 + 0x88);

            if (*(longlong *)(lVar5 + 0x88) != 0) {

              *(longlong **)(*(longlong *)(lVar5 + 0x88) + 0x10) = plVar10;

            }

            *(longlong **)(lVar5 + 0x88) = plVar10;

            plVar10 = (longlong *)(lVar13 + 0x40);

            *(longlong *)(lVar13 + 0x48) = lVar13;

            *plVar10 = lVar5;

            *(undefined8 *)(lVar13 + 0x50) = 0;

            *(undefined8 *)(lVar13 + 0x58) = *(undefined8 *)(lVar9 + 0x88);

            if (*(longlong *)(lVar9 + 0x88) != 0) {

              *(longlong **)(*(longlong *)(lVar9 + 0x88) + 0x10) = plVar10;

            }

            *(longlong **)(lVar9 + 0x88) = plVar10;

            if ((*(ushort *)(lVar5 + 4) & 2) == 0) {

              *(undefined4 *)(lVar5 + 0xac) = 0;

              *(ushort *)(lVar5 + 4) = *(ushort *)(lVar5 + 4) | 2;

            }

            if ((*(ushort *)(lVar9 + 4) & 2) == 0) {

              *(undefined4 *)(lVar9 + 0xac) = 0;

              *(ushort *)(lVar9 + 4) = *(ushort *)(lVar9 + 4) | 2;

            }

            *(int *)(param_1 + 0x60) = *(int *)(param_1 + 0x60) + 1;

          }

        }

      }

    }

  }

  return;

}




