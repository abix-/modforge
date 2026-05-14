// Address: 0x140174340
// Ghidra name: FUN_140174340
// ============ 0x140174340 FUN_140174340 (size=326) ============


uint FUN_140174340(longlong param_1,longlong param_2)



{

  uint uVar1;

  int iVar2;

  int iVar3;

  uint uVar4;

  uint uVar5;

  int iVar6;

  int iVar7;

  uint uVar8;

  int iVar9;

  uint uVar10;

  int iVar11;

  

  iVar3 = *(int *)(param_1 + 8);

  iVar2 = *(int *)(param_2 + 8);

  iVar11 = (int)(*(float *)(param_1 + 0x14) * DAT_14039ca5c);

  iVar7 = (int)(*(float *)(param_1 + 0x10) * DAT_14039ca5c);

  iVar9 = (int)(*(float *)(param_2 + 0x14) * DAT_14039ca5c);

  iVar6 = (int)(*(float *)(param_2 + 0x10) * DAT_14039ca5c);

  if (iVar3 == iVar2) {

    iVar2 = *(int *)(param_2 + 0xc);

    iVar3 = *(int *)(param_1 + 0xc);

    if (iVar3 == iVar2) {

      uVar5 = *(uint *)(param_1 + 4);

      uVar8 = 0;

      if ((uVar5 == 0) || ((uVar5 & 0xf0000000) == 0x10000000)) {

        uVar4 = (int)uVar5 >> 8 & 0xff;

      }

      else {

        uVar4 = 0;

      }

      uVar1 = *(uint *)(param_2 + 4);

      if ((uVar1 == 0) || ((uVar1 & 0xf0000000) == 0x10000000)) {

        uVar10 = (int)uVar1 >> 8 & 0xff;

      }

      else {

        uVar10 = 0;

      }

      if (uVar4 != uVar10) {

        if ((uVar1 == 0) || (uVar4 = 0, (uVar1 & 0xf0000000) == 0x10000000)) {

          uVar4 = (int)uVar1 >> 8 & 0xff;

        }

        if ((uVar5 == 0) || ((uVar5 & 0xf0000000) == 0x10000000)) {

          uVar8 = (int)uVar5 >> 8 & 0xff;

        }

        return uVar4 - uVar8;

      }

      uVar4 = (int)uVar5 >> 0x10 & 0xf;

      uVar5 = (int)uVar1 >> 0x10 & 0xf;

      if (uVar4 != uVar5) {

        return uVar5 - uVar4;

      }

      if (iVar11 != iVar9) {

        return iVar9 - iVar11;

      }

      if (iVar7 != iVar6) {

        uVar8 = iVar7 - iVar6;

      }

      return uVar8;

    }

  }

  return iVar2 - iVar3;

}




