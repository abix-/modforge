// Address: 0x1402889b0
// Ghidra name: FUN_1402889b0
// ============ 0x1402889b0 FUN_1402889b0 (size=2149) ============


undefined8 FUN_1402889b0(longlong param_1,undefined4 *param_2,ushort *param_3)



{

  ushort uVar1;

  ushort uVar2;

  char cVar3;

  uint uVar4;

  undefined4 uVar5;

  undefined4 *puVar6;

  undefined4 *puVar7;

  int *piVar8;

  int *piVar9;

  undefined8 uVar10;

  uint *puVar11;

  uint uVar12;

  int iVar13;

  longlong lVar14;

  longlong lVar15;

  int iVar16;

  ushort *puVar17;

  

  *(undefined8 *)(param_2 + 2) = 0;

  *(undefined8 *)(param_2 + 5) = 0;

  uVar12 = 10000;

  *(undefined8 *)(param_2 + 7) = 0;

  *(undefined8 *)(param_2 + 9) = 0;

  *(undefined8 *)(param_2 + 0xb) = 0;

  *(undefined8 *)(param_2 + 0xd) = 0;

  *(undefined8 *)(param_2 + 0xf) = 0;

  *(undefined8 *)(param_2 + 0x11) = 0;

  param_2[0x13] = 0;

  *param_2 = 0x50;

  param_2[4] = 10000;

  param_2[1] = 2;

  puVar6 = (undefined4 *)FUN_1401841a0(1,0x14);

  if (puVar6 == (undefined4 *)0x0) {

    return 0;

  }

  *(undefined4 **)(param_2 + 0xc) = puVar6;

  *puVar6 = 0x14;

  if ((char)param_3[2] == '\x03') {

    uVar4 = 1;

    param_2[7] = 1;

LAB_140288a52:

    puVar7 = (undefined4 *)FUN_1401841f0((ulonglong)uVar4 << 2);

    if (puVar7 == (undefined4 *)0x0) {

      return 0;

    }

    *puVar7 = *(undefined4 *)(*(longlong *)(param_1 + 0x28) + 8);

    if (1 < (uint)param_2[7]) {

      puVar7[1] = *(undefined4 *)(*(longlong *)(param_1 + 0x28) + 0xc);

    }

    if (2 < (uint)param_2[7]) {

      puVar7[2] = *(undefined4 *)(*(longlong *)(param_1 + 0x28) + 0x10);

    }

    *(undefined4 **)(param_2 + 8) = puVar7;

  }

  else {

    uVar4 = *(uint *)(param_1 + 0x24);

    param_2[7] = uVar4;

    if (uVar4 != 0) goto LAB_140288a52;

  }

  piVar8 = param_2 + 7;

  uVar1 = *param_3;

  if (uVar1 < 0x41) {

    if (uVar1 == 0x40) {

      piVar9 = (int *)FUN_1401841a0(1,8);

      if (piVar9 != (int *)0x0) {

        *piVar9 = ((short)param_3[0xf] * 10000) / 0x7fff;

        piVar9[1] = ((short)param_3[0x10] * 10000) / 0x7fff;

        param_2[0xe] = 8;

        *(int **)(param_2 + 0x10) = piVar9;

        param_2[2] = *(int *)(param_3 + 10) * 1000;

        uVar5 = FUN_1402875a0(param_3[0xd]);

        param_2[5] = uVar5;

        param_2[6] = (uint)param_3[0xe];

        param_2[0x12] = (uint)param_3[0xc] * 1000;

        cVar3 = FUN_1402888c0(param_2,param_3 + 2,*piVar8);

        if (cVar3 != '\0') {

          if ((param_3[0x11] != 0) || (param_3[0x13] != 0)) {

            if (param_3[0x12] < 0x8000) {

              uVar4 = ((uint)param_3[0x12] * 10000) / 0x7fff;

            }

            else {

              uVar4 = 10000;

            }

            puVar6[1] = uVar4;

            puVar6[2] = (uint)param_3[0x11] * 1000;

            if (param_3[0x14] < 0x8000) {

              uVar12 = ((uint)param_3[0x14] * 10000) / 0x7fff;

            }

            puVar6[3] = uVar12;

            puVar6[4] = (uint)param_3[0x13] * 1000;

            return 1;

          }

          goto LAB_1402891e1;

        }

      }

    }

    else {

      switch(uVar1) {

      case 1:

        piVar8 = (int *)FUN_1401841a0(1,4);

        if (piVar8 != (int *)0x0) {

          *piVar8 = ((short)param_3[0xf] * 10000) / 0x7fff;

          param_2[0xe] = 4;

          *(int **)(param_2 + 0x10) = piVar8;

          param_2[2] = *(int *)(param_3 + 10) * 1000;

          uVar5 = FUN_1402875a0(param_3[0xd]);

          param_2[5] = uVar5;

          param_2[6] = (uint)param_3[0xe];

          param_2[0x12] = (uint)param_3[0xc] * 1000;

          cVar3 = FUN_1402888c0(param_2,param_3 + 2,param_2[7]);

          if (cVar3 != '\0') {

            if ((param_3[0x10] != 0) || (param_3[0x12] != 0)) {

              if (param_3[0x11] < 0x8000) {

                uVar4 = ((uint)param_3[0x11] * 10000) / 0x7fff;

              }

              else {

                uVar4 = 10000;

              }

              puVar6[1] = uVar4;

              puVar6[2] = (uint)param_3[0x10] * 1000;

              if (param_3[0x13] < 0x8000) {

                uVar12 = ((uint)param_3[0x13] * 10000) / 0x7fff;

              }

              puVar6[3] = uVar12;

              puVar6[4] = (uint)param_3[0x12] * 1000;

              return 1;

            }

LAB_1402891e1:

            FUN_1401841e0(*(undefined8 *)(param_2 + 0xc));

            *(undefined8 *)(param_2 + 0xc) = 0;

            return 1;

          }

        }

        break;

      case 2:

      case 4:

      case 8:

      case 0x10:

      case 0x20:

        piVar8 = (int *)FUN_1401841a0(1,0x10);

        if (piVar8 != (int *)0x0) {

          iVar16 = FUN_140190050((int)(short)param_3[0x10]);

          *piVar8 = (iVar16 * 10000) / 0x7fff;

          piVar8[1] = ((short)param_3[0x11] * 10000) / 0x7fff;

          piVar8[2] = (((int)(short)param_3[0x10] >> 0xf & 18000U) + (uint)param_3[0x12]) % 36000;

          piVar8[3] = (uint)param_3[0xf] * 1000;

          param_2[0xe] = 0x10;

          *(int **)(param_2 + 0x10) = piVar8;

          param_2[2] = *(int *)(param_3 + 10) * 1000;

          uVar5 = FUN_1402875a0(param_3[0xd]);

          param_2[5] = uVar5;

          param_2[6] = (uint)param_3[0xe];

          param_2[0x12] = (uint)param_3[0xc] * 1000;

          cVar3 = FUN_1402888c0(param_2,param_3 + 2,param_2[7]);

          if (cVar3 != '\0') {

            if ((param_3[0x13] != 0) || (param_3[0x15] != 0)) {

              if (param_3[0x14] < 0x8000) {

                uVar4 = ((uint)param_3[0x14] * 10000) / 0x7fff;

              }

              else {

                uVar4 = 10000;

              }

              puVar6[1] = uVar4;

              puVar6[2] = (uint)param_3[0x13] * 1000;

              if (param_3[0x16] < 0x8000) {

                uVar12 = ((uint)param_3[0x16] * 10000) / 0x7fff;

              }

              puVar6[3] = uVar12;

              puVar6[4] = (uint)param_3[0x15] * 1000;

              return 1;

            }

            goto LAB_1402891e1;

          }

        }

        break;

      default:

switchD_140288ad5_caseD_3:

        uVar10 = FUN_14012e850("Haptic: Unknown effect type.");

        return uVar10;

      }

    }

  }

  else if ((((uVar1 == 0x80) || (uVar1 == 0x100)) || (uVar1 == 0x200)) || (uVar1 == 0x400)) {

    lVar14 = FUN_1401841a0(*piVar8,0x18);

    if (lVar14 != 0) {

      iVar16 = *piVar8;

      iVar13 = 0;

      if (0 < iVar16) {

        piVar8 = (int *)(lVar14 + 8);

        puVar17 = param_3 + 0x15;

        do {

          iVar13 = iVar13 + 1;

          piVar8[-2] = ((short)puVar17[9] * 10000) / 0x7fff;

          piVar8[-1] = ((short)*puVar17 * 10000) / 0x7fff;

          *piVar8 = ((short)puVar17[3] * 10000) / 0x7fff;

          piVar8[1] = ((uint)(puVar17[-6] >> 1) * 10000) / 0x7fff;

          piVar8[2] = ((uint)(puVar17[-3] >> 1) * 10000) / 0x7fff;

          piVar8[3] = ((uint)(puVar17[6] >> 1) * 10000) / 0x7fff;

          iVar16 = param_2[7];

          piVar8 = piVar8 + 6;

          puVar17 = puVar17 + 1;

        } while (iVar13 < iVar16);

      }

      *(longlong *)(param_2 + 0x10) = lVar14;

      param_2[0xe] = iVar16 * 0x18;

      param_2[2] = *(int *)(param_3 + 10) * 1000;

      uVar5 = FUN_1402875a0(param_3[0xd]);

      param_2[5] = uVar5;

      param_2[6] = (uint)param_3[0xe];

      param_2[0x12] = (uint)param_3[0xc] * 1000;

      cVar3 = FUN_1402888c0(param_2,param_3 + 2);

      if (cVar3 != '\0') goto LAB_1402891e1;

    }

  }

  else {

    if (uVar1 != 0x8000) goto switchD_140288ad5_caseD_3;

    puVar11 = (uint *)FUN_1401841a0(1,0x18);

    if (puVar11 != (uint *)0x0) {

      uVar2 = param_3[0xf];

      *puVar11 = (uint)(byte)uVar2;

      puVar11[1] = (uint)param_3[0x10] * 1000;

      uVar1 = param_3[0x11];

      puVar11[2] = (uint)uVar1;

      uVar10 = FUN_1401841f0((uint)(byte)uVar2 * (uint)uVar1 * 4);

      *(undefined8 *)(puVar11 + 4) = uVar10;

      iVar16 = 0;

      if ((uint)param_3[0x11] * (uint)(byte)param_3[0xf] != 0) {

        lVar15 = 0;

        lVar14 = 0;

        do {

          uVar4 = 10000;

          if (*(ushort *)(lVar14 + *(longlong *)(param_3 + 0x14)) < 0x8000) {

            uVar4 = ((uint)*(ushort *)(lVar14 + *(longlong *)(param_3 + 0x14)) * 10000) / 0x7fff;

          }

          iVar16 = iVar16 + 1;

          lVar14 = lVar14 + 2;

          *(uint *)(lVar15 + *(longlong *)(puVar11 + 4)) = uVar4;

          lVar15 = lVar15 + 4;

        } while (iVar16 < (int)((uint)param_3[0x11] * (uint)(byte)param_3[0xf]));

      }

      param_2[0xe] = 0x18;

      *(uint **)(param_2 + 0x10) = puVar11;

      param_2[2] = *(int *)(param_3 + 10) * 1000;

      uVar5 = FUN_1402875a0(param_3[0xd]);

      param_2[5] = uVar5;

      param_2[6] = (uint)param_3[0xe];

      param_2[0x12] = (uint)param_3[0xc] * 1000;

      cVar3 = FUN_1402888c0(param_2,param_3 + 2,param_2[7]);

      if (cVar3 != '\0') {

        if ((param_3[0x18] != 0) || (param_3[0x1a] != 0)) {

          if (param_3[0x19] < 0x8000) {

            uVar4 = ((uint)param_3[0x19] * 10000) / 0x7fff;

          }

          else {

            uVar4 = 10000;

          }

          puVar6[1] = uVar4;

          puVar6[2] = (uint)param_3[0x18] * 1000;

          if (param_3[0x1b] < 0x8000) {

            uVar12 = ((uint)param_3[0x1b] * 10000) / 0x7fff;

          }

          puVar6[3] = uVar12;

          puVar6[4] = (uint)param_3[0x1a] * 1000;

          return 1;

        }

        goto LAB_1402891e1;

      }

    }

  }

  return 0;

}




