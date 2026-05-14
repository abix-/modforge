// Address: 0x140144a40
// Ghidra name: FUN_140144a40
// ============ 0x140144a40 FUN_140144a40 (size=785) ============


void FUN_140144a40(longlong param_1,char param_2)



{

  ushort uVar1;

  ushort *puVar2;

  uint *puVar3;

  char cVar4;

  uint uVar5;

  uint uVar6;

  uint *puVar7;

  ushort *puVar8;

  int iVar9;

  ushort uVar10;

  int iVar11;

  

  cVar4 = FUN_1401489c0();

  if (cVar4 == '\0') {

    return;

  }

  if ((*(uint *)(param_1 + 0x108) & 0x400) == 0) {

    return;

  }

  uVar6 = *(uint *)(param_1 + 4);

  if (uVar6 == 0) {

LAB_140144a97:

    if (((uVar6 & 0xf000000) + 0xfb000000 & 0xfeffffff) != 0) {

LAB_140144ac6:

      if (uVar6 != 0) goto LAB_140144aca;

      goto LAB_140144adc;

    }

LAB_140144aa3:

    uVar5 = uVar6 & 0xf00000;

    if ((((uVar5 != 0x300000) && (uVar5 != 0x400000)) && (uVar5 != 0x700000)) && (uVar5 != 0x800000)

       ) goto LAB_140144ac6;

  }

  else {

    if ((uVar6 & 0xf0000000) == 0x10000000) {

      if ((uVar6 & 0xf000000) != 0x4000000) goto LAB_140144a97;

      goto LAB_140144aa3;

    }

LAB_140144aca:

    if ((uVar6 & 0xf0000000) != 0x10000000) {

      return;

    }

LAB_140144adc:

    uVar6 = *(uint *)(param_1 + 4) & 0xf000000;

    if ((uVar6 != 0x7000000) && ((uVar6 + 0xf8000000 & 0xfcffffff) != 0)) {

      return;

    }

    uVar6 = *(uint *)(param_1 + 4) & 0xf00000;

    if (((uVar6 != 0x300000) && (uVar6 != 0x200000)) && ((uVar6 != 0x600000 && (uVar6 != 0x500000)))

       ) {

      return;

    }

  }

  uVar6 = *(uint *)(param_1 + 4);

  if ((uVar6 == 0) || ((uVar6 & 0xf0000000) == 0x10000000)) {

    uVar6 = uVar6 & 0xff;

  }

  else {

    if ((((uVar6 != 0x32595559) && (uVar6 != 0x59565955)) && (uVar6 != 0x55595659)) &&

       (uVar6 != 0x30313050)) {

      FUN_140146f20(param_1);

      goto LAB_140144d1f;

    }

    uVar6 = 2;

  }

  FUN_140146f20(param_1);

  if (uVar6 == 2) {

    uVar1 = *(ushort *)(param_1 + 0x10c);

    puVar2 = *(ushort **)(param_1 + 0x18);

    iVar11 = *(int *)(param_1 + 0xc);

    uVar10 = ~*(ushort *)(*(longlong *)(param_1 + 0x38) + 0x14);

    if (param_2 == '\0') {

      while (iVar11 != 0) {

        iVar9 = *(int *)(param_1 + 8);

        iVar11 = iVar11 + -1;

        puVar8 = puVar2;

        while (iVar9 != 0) {

          iVar9 = iVar9 + -1;

          if (*puVar8 == uVar1) {

            *puVar8 = *puVar8 & uVar10;

          }

          puVar8 = puVar8 + 1;

        }

        iVar9 = *(int *)(param_1 + 0x10);

        if (iVar9 < 0) {

          iVar9 = iVar9 + 1;

        }

        puVar2 = puVar2 + (iVar9 >> 1);

      }

    }

    else {

      while (iVar11 != 0) {

        iVar9 = *(int *)(param_1 + 8);

        iVar11 = iVar11 + -1;

        puVar8 = puVar2;

        while (iVar9 != 0) {

          iVar9 = iVar9 + -1;

          if ((uVar10 & *puVar8) == (uVar10 & uVar1)) {

            *puVar8 = uVar10 & *puVar8;

          }

          puVar8 = puVar8 + 1;

        }

        iVar9 = *(int *)(param_1 + 0x10);

        if (iVar9 < 0) {

          iVar9 = iVar9 + 1;

        }

        puVar2 = puVar2 + (iVar9 >> 1);

      }

    }

  }

  else if (uVar6 == 4) {

    uVar6 = *(uint *)(param_1 + 0x10c);

    puVar3 = *(uint **)(param_1 + 0x18);

    iVar11 = *(int *)(param_1 + 0xc);

    uVar5 = ~*(uint *)(*(longlong *)(param_1 + 0x38) + 0x14);

    if (param_2 == '\0') {

      while (iVar11 != 0) {

        iVar9 = *(int *)(param_1 + 8);

        iVar11 = iVar11 + -1;

        puVar7 = puVar3;

        while (iVar9 != 0) {

          iVar9 = iVar9 + -1;

          if (*puVar7 == uVar6) {

            *puVar7 = *puVar7 & uVar5;

          }

          puVar7 = puVar7 + 1;

        }

        iVar9 = *(int *)(param_1 + 0x10);

        if (iVar9 < 0) {

          iVar9 = iVar9 + 3;

        }

        puVar3 = puVar3 + (iVar9 >> 2);

      }

    }

    else {

      while (iVar11 != 0) {

        iVar9 = *(int *)(param_1 + 8);

        iVar11 = iVar11 + -1;

        puVar7 = puVar3;

        while (iVar9 != 0) {

          iVar9 = iVar9 + -1;

          if ((uVar5 & *puVar7) == (uVar6 & uVar5)) {

            *puVar7 = uVar5 & *puVar7;

          }

          puVar7 = puVar7 + 1;

        }

        iVar9 = *(int *)(param_1 + 0x10);

        if (iVar9 < 0) {

          iVar9 = iVar9 + 3;

        }

        puVar3 = puVar3 + (iVar9 >> 2);

      }

    }

  }

LAB_140144d1f:

  FUN_1401489e0(param_1);

  FUN_140148630(param_1,0,0);

  FUN_140148450(param_1,1);

  return;

}




