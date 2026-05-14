// Address: 0x14012eaa0
// Ghidra name: FUN_14012eaa0
// ============ 0x14012eaa0 FUN_14012eaa0 (size=500) ============


longlong FUN_14012eaa0(ushort *param_1,int param_2,uint param_3,ulonglong *param_4,char *param_5)



{

  ushort uVar1;

  undefined1 auVar2 [16];

  bool bVar3;

  int iVar4;

  uint uVar5;

  ulonglong uVar6;

  ushort *puVar7;

  ushort *puVar9;

  ulonglong uVar10;

  bool bVar11;

  ushort *puVar8;

  

  bVar11 = false;

  bVar3 = false;

  uVar10 = 0;

  puVar7 = param_1;

  if ((param_3 == 0) || (param_3 - 2 < 0x23)) {

    iVar4 = FUN_140190430(*param_1);

    while (iVar4 != 0) {

      puVar8 = puVar7 + 1;

      puVar7 = puVar7 + 1;

      iVar4 = FUN_140190430(*puVar8);

    }

    uVar1 = *puVar7;

    if ((uVar1 == 0x2d) || (uVar1 == 0x2b)) {

      bVar11 = uVar1 == 0x2d;

      puVar7 = puVar7 + 1;

    }

    puVar8 = puVar7;

    if ((param_3 & 0xffffffef) == 0) {

      if ((*puVar7 == 0x30) && ((puVar7[1] - 0x58 & 0xffdf) == 0)) {

        puVar7 = puVar7 + 2;

        param_3 = 0x10;

        puVar8 = puVar7;

      }

      else if (param_3 == 0) {

        if ((*puVar7 == 0x30) && ((ushort)(puVar7[1] - 0x30) < 10)) {

          puVar7 = puVar7 + 1;

          param_3 = 8;

          puVar8 = puVar7;

        }

        else {

          param_3 = 10;

        }

      }

    }

    do {

      uVar1 = *puVar7;

      uVar6 = (ulonglong)uVar1;

      if ((uVar1 < 0x30) || (0x39 < uVar1)) {

        if ((int)param_3 < 0xb) break;

        uVar5 = (uint)uVar1;

        if ((uVar5 < 0x41) || ((int)(param_3 + 0x37) <= (int)uVar5)) {

          if ((uVar1 < 0x61) || ((int)(param_3 + 0x57) <= (int)uVar5)) break;

          uVar6 = uVar6 - 0x57;

        }

        else {

          uVar6 = uVar6 - 0x37;

        }

      }

      else {

        uVar6 = uVar6 - 0x30;

      }

      if ((uVar10 == 0) ||

         (auVar2._8_8_ = 0, auVar2._0_8_ = uVar10,

         (ulonglong)(longlong)(int)param_3 <=

         SUB168((ZEXT816(0) << 0x40 | ZEXT816(0xffffffffffffffff)) / auVar2,0))) {

        uVar10 = uVar10 * (longlong)(int)param_3;

        if (~uVar10 < uVar6) {

          bVar3 = true;

        }

        else {

          uVar10 = uVar10 + uVar6;

        }

      }

      else {

        bVar3 = true;

      }

      puVar7 = puVar7 + 1;

    } while ((param_2 == 0) || ((longlong)puVar7 - (longlong)param_1 >> 1 != (longlong)param_2));

    puVar9 = puVar7;

    if (puVar7 != puVar8) goto LAB_14012ec38;

  }

  if ((param_3 == 0x10) && (param_1 < puVar7)) {

    puVar9 = puVar7 + -1;

    if ((puVar7[-1] == 0x78) || (puVar7[-1] == 0x58)) goto LAB_14012ec38;

  }

  puVar9 = param_1;

LAB_14012ec38:

  if (bVar3) {

    uVar10 = (ulonglong)(bVar11 != false) - 1;

  }

  else if (uVar10 == 0) {

    bVar11 = false;

  }

  *param_4 = uVar10;

  *param_5 = bVar11;

  return (longlong)puVar9 - (longlong)param_1 >> 1;

}




