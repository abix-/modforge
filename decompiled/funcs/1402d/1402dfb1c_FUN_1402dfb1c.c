// Address: 0x1402dfb1c
// Ghidra name: FUN_1402dfb1c
// ============ 0x1402dfb1c FUN_1402dfb1c (size=417) ============


undefined8 FUN_1402dfb1c(byte *param_1,int param_2)



{

  byte bVar1;

  undefined8 *puVar2;

  longlong lVar3;

  undefined4 *puVar4;

  byte *pbVar5;

  ulonglong uVar6;

  longlong lVar7;

  byte *pbVar8;

  uint uVar9;

  uint uVar10;

  ulonglong uVar11;

  byte *pbVar12;

  bool bVar13;

  

  pbVar5 = (byte *)0x0;

  if (param_1[0x3a] == 0) {

    puVar2 = *(undefined8 **)(param_1 + 0x80);

    *(undefined8 **)(param_1 + 0x80) = puVar2 + 1;

    pbVar5 = (byte *)*puVar2;

    if (pbVar5 == (byte *)0x0) {

      puVar4 = (undefined4 *)FUN_1402e68b0();

      *puVar4 = 0x16;

      FUN_1402cd454();

      return 0;

    }

    if ((*param_1 & 1) != 0) {

      *(undefined8 **)(param_1 + 0x80) = puVar2 + 2;

      uVar11 = (ulonglong)*(uint *)(puVar2 + 1);

      if (uVar11 == 0) {

        if ((*param_1 & 4) != 0) {

          if (*(longlong *)(param_1 + 0x18) != *(longlong *)(param_1 + 0x10)) {

            *(longlong *)(param_1 + 0x18) = *(longlong *)(param_1 + 0x18) + 1;

          }

LAB_1402dfbb9:

          *pbVar5 = 0;

        }

LAB_1402dfbbc:

        puVar4 = (undefined4 *)FUN_1402e68b0();

        *puVar4 = 0xc;

        return 0;

      }

      goto LAB_1402dfbcd;

    }

  }

  uVar11 = 0xffffffffffffffff;

LAB_1402dfbcd:

  lVar3 = *(longlong *)(param_1 + 0x40);

  uVar6 = uVar11;

  if ((param_2 != 0) && (uVar11 != 0xffffffffffffffff)) {

    uVar6 = uVar11 - 1;

  }

  lVar7 = 0;

  pbVar12 = pbVar5;

  while( true ) {

    if ((lVar3 != 0) && (lVar7 == lVar3)) goto LAB_1402dfc8b;

    pbVar8 = *(byte **)(param_1 + 0x18);

    if (pbVar8 == *(byte **)(param_1 + 0x10)) break;

    bVar1 = *pbVar8;

    uVar9 = (uint)bVar1;

    pbVar8 = pbVar8 + 1;

    *(byte **)(param_1 + 0x18) = pbVar8;

    if (param_2 != 0) {

      if (param_2 == 1) {

        uVar10 = uVar9;

        if (bVar1 - 9 < 5) goto LAB_1402dfc71;

        bVar13 = uVar9 == 0x20;

      }

      else {

        uVar10 = (uint)bVar1;

        if (param_2 != 8) goto LAB_1402dfc71;

        bVar13 = (param_1[(ulonglong)(bVar1 >> 3) + 0x54] & (byte)(1 << (bVar1 & 7))) == 0;

      }

      uVar10 = uVar9;

      if (bVar13) goto LAB_1402dfc71;

    }

    if (param_1[0x3a] == 0) {

      if (uVar6 == 0) {

        if (uVar11 != 0xffffffffffffffff) goto LAB_1402dfbb9;

        goto LAB_1402dfbbc;

      }

      *pbVar12 = bVar1;

      pbVar12 = pbVar12 + 1;

      uVar6 = uVar6 - 1;

    }

    lVar7 = lVar7 + 1;

  }

  uVar10 = 0xffffffff;

LAB_1402dfc71:

  if ((pbVar8 != *(byte **)(param_1 + 8)) &&

     ((pbVar8 != *(byte **)(param_1 + 0x10) || (uVar10 != 0xffffffff)))) {

    *(byte **)(param_1 + 0x18) = pbVar8 + -1;

  }

LAB_1402dfc8b:

  if ((lVar7 != 0) && (((param_2 != 0 || (lVar7 == lVar3)) || ((*param_1 & 4) != 0)))) {

    if ((param_1[0x3a] == 0) && (param_2 != 0)) {

      *pbVar12 = 0;

    }

    return 1;

  }

  return 0;

}




