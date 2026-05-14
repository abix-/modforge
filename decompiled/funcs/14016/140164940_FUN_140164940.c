// Address: 0x140164940
// Ghidra name: FUN_140164940
// ============ 0x140164940 FUN_140164940 (size=412) ============


void FUN_140164940(undefined8 param_1,undefined1 *param_2,int param_3,int param_4,uint *param_5)



{

  undefined4 uVar1;

  longlong lVar2;

  uint uVar3;

  uint uVar4;

  undefined1 local_98 [128];

  

  if ((param_3 < 0) || (uVar4 = param_5[1], (int)uVar4 <= param_3)) {

    uVar4 = param_5[1];

    if (0 < (int)uVar4) {

      lVar2 = 0;

      do {

        if (*(longlong *)(param_2 + lVar2 * 8) == 0) goto LAB_1401649be;

        lVar2 = lVar2 + 1;

      } while (lVar2 < (int)uVar4);

    }

    uVar3 = *param_5 & 0xff;

    if (uVar3 == 8) {

      FUN_140164ba0(param_1,param_2,uVar4);

    }

    else if (uVar3 == 0x10) {

      FUN_140164ae0(param_1,param_2,uVar4);

    }

    else if (uVar3 == 0x20) {

      FUN_140164b40(param_1,param_2,uVar4);

    }

    else {

      FUN_1402f94c0(param_1,0,(*param_5 >> 3 & 0x1f) * uVar4 * param_4);

    }

  }

  else {

    FUN_1402f8e20(local_98,param_2,(longlong)param_3 * 8);

    FUN_1402f94c0(local_98 + (longlong)param_3 * 8,0,(longlong)(int)(uVar4 - param_3) << 3);

    uVar4 = param_5[1];

    param_2 = local_98;

LAB_1401649be:

    uVar1 = FUN_14015e760(*param_5);

    uVar3 = *param_5 & 0xff;

    if (uVar3 == 8) {

      FUN_140164cf0(param_1,param_2,uVar4,param_4,uVar1);

    }

    else if (uVar3 == 0x10) {

      FUN_140164c00(param_1,param_2,uVar4,param_4,uVar1);

    }

    else if (uVar3 == 0x20) {

      FUN_140164c80(param_1,param_2,uVar4,param_4,uVar1);

    }

    else {

      FUN_1402f94c0(param_1,0,(*param_5 >> 3 & 0x1f) * param_5[1] * param_4);

    }

  }

  return;

}




