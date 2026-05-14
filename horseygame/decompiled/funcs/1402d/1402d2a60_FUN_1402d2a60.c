// Address: 0x1402d2a60
// Ghidra name: FUN_1402d2a60
// ============ 0x1402d2a60 FUN_1402d2a60 (size=521) ============


ulonglong FUN_1402d2a60(longlong param_1,undefined1 param_2)



{

  ulonglong *puVar1;

  ushort *puVar2;

  byte *pbVar3;

  uint *puVar4;

  short *psVar5;

  uint uVar6;

  ulonglong uVar7;

  longlong lVar8;

  int iVar9;

  

  iVar9 = *(int *)(param_1 + 0x34);

  if (iVar9 < 6) {

    if (iVar9 != 5) {

      if (iVar9 != 0) {

        if (iVar9 == 1) {

          uVar6 = *(uint *)(param_1 + 0x28);

          lVar8 = 1;

          pbVar3 = *(byte **)(param_1 + 0x18);

          *(byte **)(param_1 + 0x18) = pbVar3 + 8;

          if ((uVar6 >> 4 & 1) == 0) {

            uVar7 = (ulonglong)*pbVar3;

          }

          else {

            uVar7 = (ulonglong)(char)*pbVar3;

          }

          goto LAB_1402d2ade;

        }

        iVar9 = iVar9 + -2;

        if (iVar9 == 0) {

          uVar6 = *(uint *)(param_1 + 0x28);

          lVar8 = 2;

          puVar2 = *(ushort **)(param_1 + 0x18);

          *(ushort **)(param_1 + 0x18) = puVar2 + 4;

          if ((uVar6 >> 4 & 1) == 0) {

            uVar7 = (ulonglong)*puVar2;

          }

          else {

            uVar7 = (ulonglong)(short)*puVar2;

          }

          goto LAB_1402d2ade;

        }

        goto LAB_1402d2aae;

      }

LAB_1402d2bb3:

      uVar6 = *(uint *)(param_1 + 0x28);

      lVar8 = 4;

      puVar4 = *(uint **)(param_1 + 0x18);

      *(uint **)(param_1 + 0x18) = puVar4 + 2;

      if ((uVar6 >> 4 & 1) == 0) {

        uVar7 = (ulonglong)*puVar4;

      }

      else {

        uVar7 = (ulonglong)(int)*puVar4;

      }

      goto LAB_1402d2ade;

    }

  }

  else if (((iVar9 != 6) && (iVar9 != 7)) && (iVar9 = iVar9 + -9, iVar9 != 0)) {

LAB_1402d2aae:

    if (iVar9 == 1) goto LAB_1402d2bb3;

    if (iVar9 != 2) {

      lVar8 = *(longlong *)(param_1 + 8);

      *(undefined1 *)(lVar8 + 0x30) = 1;

      *(undefined4 *)(lVar8 + 0x2c) = 0x16;

      uVar7 = FUN_1402cd39c(0,0,0,0,0,*(undefined8 *)(param_1 + 8));

      return uVar7 & 0xffffffffffffff00;

    }

  }

  uVar6 = *(uint *)(param_1 + 0x28);

  lVar8 = 8;

  puVar1 = *(ulonglong **)(param_1 + 0x18);

  *(ulonglong **)(param_1 + 0x18) = puVar1 + 1;

  uVar7 = *puVar1;

LAB_1402d2ade:

  if (((uVar6 >> 4 & 1) != 0) && ((longlong)uVar7 < 0)) {

    uVar7 = -uVar7;

    uVar6 = uVar6 | 0x40;

    *(uint *)(param_1 + 0x28) = uVar6;

  }

  if (*(int *)(param_1 + 0x30) < 0) {

    *(undefined4 *)(param_1 + 0x30) = 1;

  }

  else {

    *(uint *)(param_1 + 0x28) = uVar6 & 0xfffffff7;

    FUN_1402d1d50(param_1 + 0x50,(longlong)*(int *)(param_1 + 0x30),*(undefined8 *)(param_1 + 8));

  }

  if (uVar7 == 0) {

    *(uint *)(param_1 + 0x28) = *(uint *)(param_1 + 0x28) & 0xffffffdf;

  }

  *(undefined1 *)(param_1 + 0x4c) = 1;

  if (lVar8 == 8) {

    FUN_1402d3880(param_1,uVar7);

  }

  else {

    FUN_1402d34fc(param_1,uVar7 & 0xffffffff,param_2);

  }

  uVar6 = *(uint *)(param_1 + 0x28) >> 7;

  psVar5 = (short *)(ulonglong)uVar6;

  if (((uVar6 & 1) != 0) &&

     ((*(int *)(param_1 + 0x48) == 0 || (psVar5 = *(short **)(param_1 + 0x40), *psVar5 != 0x30)))) {

    *(longlong *)(param_1 + 0x40) = *(longlong *)(param_1 + 0x40) + -2;

    **(undefined2 **)(param_1 + 0x40) = 0x30;

    *(int *)(param_1 + 0x48) = *(int *)(param_1 + 0x48) + 1;

  }

  return CONCAT71((int7)((ulonglong)psVar5 >> 8),1);

}




