// Address: 0x14019c610
// Ghidra name: FUN_14019c610
// ============ 0x14019c610 FUN_14019c610 (size=292) ============


void FUN_14019c610(longlong param_1,longlong param_2,longlong param_3,byte *param_4,int param_5,

                  int param_6)



{

  undefined1 *puVar1;

  uint uVar2;

  longlong lVar3;

  uint uVar4;

  int iVar5;

  uint uVar6;

  uint uVar7;

  uint uVar8;

  

  lVar3 = (longlong)param_5;

  if (0 < lVar3) {

    puVar1 = (undefined1 *)(param_1 + 2);

    param_2 = param_2 - (longlong)param_4;

    param_3 = param_3 - (longlong)param_4;

    uVar8 = 0;

    do {

      iVar5 = (uint)param_4[param_2] * 0x100000 + 0x80000;

      uVar6 = (int)((*param_4 - 0x80) * 0x166f00 + iVar5) >> 0x14;

      uVar4 = (int)((0x80 - (uint)*param_4) * 0xb6d00 +

                   iVar5 + ((0x80 - (uint)param_4[param_3]) * 0x58200 & 0xffff0000)) >> 0x14;

      uVar2 = (int)((param_4[param_3] - 0x80) * 0x1c5a00 + iVar5) >> 0x14;

      uVar7 = uVar6;

      if ((0xff < uVar6) && (uVar7 = 0xff, (int)uVar6 < 0)) {

        uVar7 = uVar8;

      }

      uVar6 = uVar4;

      if ((0xff < uVar4) && (uVar6 = 0xff, (int)uVar4 < 0)) {

        uVar6 = uVar8;

      }

      uVar4 = uVar2;

      if ((0xff < uVar2) && (uVar4 = 0xff, (int)uVar2 < 0)) {

        uVar4 = uVar8;

      }

      puVar1[-2] = (char)uVar7;

      param_4 = param_4 + 1;

      puVar1[-1] = (char)uVar6;

      *puVar1 = (char)uVar4;

      puVar1[1] = 0xff;

      puVar1 = puVar1 + param_6;

      lVar3 = lVar3 + -1;

    } while (lVar3 != 0);

  }

  return;

}




