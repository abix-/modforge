// Address: 0x140155fb0
// Ghidra name: FUN_140155fb0
// ============ 0x140155fb0 FUN_140155fb0 (size=249) ============


undefined8 FUN_140155fb0(uint *param_1,int *param_2,longlong param_3,int param_4)



{

  longlong lVar1;

  uint uVar2;

  int iVar3;

  uint uVar4;

  ulonglong uVar5;

  int iVar6;

  longlong lVar7;

  

  lVar1 = *(longlong *)(param_1 + 0x3c);

  uVar4 = *param_1;

  if ((uVar4 == 0) || ((uVar4 & 0xf0000000) == 0x10000000)) {

    uVar2 = (int)uVar4 >> 8 & 0xff;

  }

  else {

    uVar2 = 0;

  }

  lVar7 = (longlong)((int)(uVar2 * *param_2 + ((int)(uVar2 * *param_2) >> 0x1f & 7U)) >> 3) +

          (longlong)(param_2[1] * *(int *)(lVar1 + 0x10)) + *(longlong *)(lVar1 + 0x18);

  if ((uVar4 == 0) || ((uVar4 & 0xf0000000) == 0x10000000)) {

    uVar4 = (int)uVar4 >> 8 & 0xff;

  }

  else {

    uVar4 = 0;

  }

  iVar6 = param_2[3];

  iVar3 = uVar4 * param_2[2] + 7;

  uVar4 = (int)(iVar3 + (iVar3 >> 0x1f & 7U)) >> 3;

  uVar5 = (ulonglong)uVar4;

  if (iVar6 != 0) {

    do {

      FUN_1402f8e20(lVar7,param_3,(longlong)(int)uVar4);

      uVar5 = (ulonglong)*(int *)(lVar1 + 0x10);

      param_3 = param_3 + param_4;

      lVar7 = lVar7 + uVar5;

      iVar6 = iVar6 + -1;

    } while (iVar6 != 0);

  }

  param_1[0x3a] = 0;

  return CONCAT71((int7)(uVar5 >> 8),1);

}




