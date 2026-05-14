// Address: 0x140130f00
// Ghidra name: FUN_140130f00
// ============ 0x140130f00 FUN_140130f00 (size=169) ============


undefined8

FUN_140130f00(longlong *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,

             undefined4 param_5,undefined4 param_6,undefined4 param_7)



{

  longlong lVar1;

  longlong lVar2;

  int iVar3;

  

  iVar3 = *(int *)((longlong)param_1 + 0xc);

  if (iVar3 <= (int)param_1[1]) {

    if (iVar3 == 0) {

      iVar3 = 0x10;

    }

    else {

      iVar3 = iVar3 * 2;

    }

    lVar1 = FUN_140184230(*param_1,(longlong)iVar3 * 0x18);

    if (lVar1 == 0) {

      return 0;

    }

    *param_1 = lVar1;

    *(int *)((longlong)param_1 + 0xc) = iVar3;

  }

  lVar2 = (longlong)(int)param_1[1];

  lVar1 = *param_1;

  *(undefined4 *)(lVar1 + lVar2 * 0x18) = param_2;

  *(undefined4 *)(lVar1 + 4 + lVar2 * 0x18) = param_3;

  *(undefined4 *)(lVar1 + 8 + lVar2 * 0x18) = param_4;

  lVar1 = lVar1 + lVar2 * 0x18;

  *(undefined4 *)(lVar1 + 0xc) = param_5;

  *(undefined4 *)(lVar1 + 0x10) = param_6;

  *(undefined4 *)(lVar1 + 0x14) = param_7;

  *(int *)(param_1 + 1) = (int)param_1[1] + 1;

  return CONCAT71((uint7)(uint3)((uint)param_7 >> 8),1);

}




