// Address: 0x140298cc0
// Ghidra name: FUN_140298cc0
// ============ 0x140298cc0 FUN_140298cc0 (size=670) ============


void FUN_140298cc0(longlong param_1,ushort param_2)



{

  int iVar1;

  int iVar2;

  uint *puVar3;

  uint uVar4;

  uint uVar5;

  uint uVar6;

  int iVar7;

  ulonglong uVar8;

  int iVar9;

  uint *puVar10;

  ushort uVar11;

  int iVar12;

  

  iVar1 = *(int *)(param_1 + 0x44);

  iVar7 = *(int *)(param_1 + 0x3c);

  iVar2 = *(int *)(param_1 + 0x38);

  puVar10 = *(uint **)(param_1 + 8);

  puVar3 = *(uint **)(param_1 + 0x30);

  iVar12 = *(int *)(param_1 + 0x1c) >> 1;

  if (iVar7 != 0) {

    uVar11 = ~param_2;

    do {

      iVar7 = iVar7 + -1;

      if ((((byte)puVar3 ^ (byte)puVar10) & 2) == 0) {

        iVar9 = iVar2;

        if (((ulonglong)puVar10 & 2) != 0) {

          iVar9 = iVar2 + -1;

          uVar5 = *puVar10;

          puVar10 = (uint *)((longlong)puVar10 + 2);

          *(ushort *)puVar3 =

               (short)((uint)((ushort)*puVar3 & param_2) + (uint)((ushort)uVar5 & param_2) >> 1) +

               ((ushort)*puVar3 & (ushort)uVar5 & uVar11);

          puVar3 = (uint *)((longlong)puVar3 + 2);

        }

        if (1 < iVar9) {

          uVar4 = CONCAT22(param_2,param_2);

          uVar5 = (iVar9 - 2U >> 1) + 1;

          uVar8 = (ulonglong)uVar5;

          iVar9 = iVar9 + uVar5 * -2;

          do {

            uVar5 = *puVar10;

            uVar6 = *puVar10;

            puVar10 = puVar10 + 1;

            *puVar3 = ((*puVar3 & uVar4) >> 1) + ((uVar4 & uVar6) >> 1) + (*puVar3 & uVar5 & ~uVar4)

            ;

            puVar3 = puVar3 + 1;

            uVar8 = uVar8 - 1;

          } while (uVar8 != 0);

        }

        if (iVar9 != 0) {

          uVar5 = *puVar10;

          puVar10 = (uint *)((longlong)puVar10 + 2);

          *(ushort *)puVar3 =

               (short)((uint)((ushort)uVar5 & param_2) + (uint)((ushort)*puVar3 & param_2) >> 1) +

               ((ushort)*puVar3 & (ushort)uVar5 & uVar11);

          puVar3 = (uint *)((longlong)puVar3 + 2);

        }

        puVar10 = (uint *)((longlong)puVar10 + (longlong)iVar12 * 2);

      }

      else {

        iVar9 = iVar2;

        if (((ulonglong)puVar3 & 2) != 0) {

          iVar9 = iVar2 + -1;

          *(ushort *)puVar3 =

               (short)((uint)((ushort)*puVar10 & param_2) + (uint)((ushort)*puVar3 & param_2) >> 1)

               + (uVar11 & (ushort)*puVar10 & (ushort)*puVar3);

          puVar3 = (uint *)((longlong)puVar3 + 2);

          puVar10 = (uint *)((longlong)puVar10 + 2);

        }

        uVar5 = *(uint *)((longlong)puVar10 + -2);

        puVar10 = (uint *)((longlong)puVar10 + 2);

        if (1 < iVar9) {

          uVar6 = CONCAT22(param_2,param_2);

          uVar4 = (iVar9 - 2U >> 1) + 1;

          uVar8 = (ulonglong)uVar4;

          iVar9 = iVar9 + uVar4 * -2;

          do {

            uVar4 = *puVar10 * 0x10000 + (uVar5 >> 0x10);

            uVar5 = *puVar10;

            puVar10 = puVar10 + 1;

            *puVar3 = ((uVar6 & uVar4) >> 1) + ((uVar6 & *puVar3) >> 1) + (~uVar6 & uVar4 & *puVar3)

            ;

            puVar3 = puVar3 + 1;

            uVar8 = uVar8 - 1;

          } while (uVar8 != 0);

        }

        if (iVar9 != 0) {

          puVar10 = (uint *)((longlong)puVar10 + 2);

          *(ushort *)puVar3 =

               (short)((uVar5 >> 0x10 & (uint)param_2) + (uint)((ushort)*puVar3 & param_2) >> 1) +

               ((ushort)(uVar5 >> 0x10) & (ushort)*puVar3 & uVar11);

          puVar3 = (uint *)((longlong)puVar3 + 2);

        }

        puVar10 = (uint *)((longlong)puVar10 + (longlong)(iVar12 + -1) * 2);

      }

      puVar3 = (uint *)((longlong)puVar3 + (longlong)(iVar1 >> 1) * 2);

    } while (iVar7 != 0);

  }

  return;

}




