// Address: 0x14017cec0
// Ghidra name: FUN_14017cec0
// ============ 0x14017cec0 FUN_14017cec0 (size=414) ============


longlong FUN_14017cec0(int param_1,int param_2,int param_3,int *param_4,int *param_5)



{

  uint uVar1;

  int iVar2;

  int iVar3;

  uint uVar4;

  uint uVar5;

  longlong lVar6;

  uint uVar7;

  

  iVar2 = 0;

  uVar4 = param_1 - (uint)(param_2 < 3);

  uVar1 = uVar4;

  if ((int)uVar4 < 0) {

    uVar1 = uVar4 - 399;

  }

  uVar5 = uVar4 + ((int)uVar1 / 400) * -400;

  iVar3 = -0x1c9;

  if (param_2 < 3) {

    iVar3 = 0x563;

  }

  uVar7 = param_3 + -1 + (iVar3 + param_2 * 0x99) / 5;

  lVar6 = (longlong)((int)uVar1 / 400) * 0x23ab1 + -0xafa6c +

          (ulonglong)(uVar7 + (uVar5 * 0x16d - uVar5 / 100) + (uVar5 >> 2));

  if (param_4 != (int *)0x0) {

    if (lVar6 < -4) {

      iVar3 = (int)(lVar6 + 5) + (int)((lVar6 + 5) / 7) * -7 + 6;

    }

    else {

      iVar3 = (int)(lVar6 + 4) + (int)((lVar6 + 4) / 7) * -7;

    }

    *param_4 = iVar3;

  }

  if (param_5 != (int *)0x0) {

    if (uVar7 < 0x132) {

      uVar1 = uVar4 & 0x80000003;

      if ((int)uVar1 < 0) {

        uVar1 = (uVar1 - 1 | 0xfffffffc) + 1;

      }

      if ((uVar1 == 0) &&

         ((uVar4 != ((int)uVar4 / 100) * 100 || (uVar4 == ((int)uVar4 / 400) * 400)))) {

        iVar2 = 1;

      }

      iVar2 = uVar7 + 0x3b + iVar2;

    }

    else {

      iVar2 = uVar7 - 0x132;

    }

    *param_5 = iVar2;

  }

  return lVar6;

}




