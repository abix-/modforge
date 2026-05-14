// Address: 0x140265420
// Ghidra name: FUN_140265420
// ============ 0x140265420 FUN_140265420 (size=284) ============


void FUN_140265420(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4,

                  int param_5)



{

  short sVar1;

  short sVar2;

  undefined8 uVar3;

  

  sVar2 = *(short *)(param_4 + 2);

  sVar1 = -0x8000;

  if ((-1 < sVar2) && ((0x3ff < sVar2 || (sVar1 = (sVar2 + -0x200) * 0x40, sVar1 == 0x7fc0)))) {

    sVar1 = 0x7fff;

  }

  FUN_14015aab0(param_3,param_2,4,sVar1);

  sVar2 = *(short *)(param_4 + 4);

  if (sVar2 < 0) {

    sVar2 = -0x8000;

  }

  else if ((0x3ff < sVar2) || (sVar2 = (sVar2 + -0x200) * 0x40, sVar2 == 0x7fc0)) {

    sVar2 = 0x7fff;

  }

  FUN_14015aab0(param_3,param_2,5,sVar2);

  if (0x12 < param_5) {

    uVar3 = 0xffff8000;

    if ((*(byte *)(param_4 + 0x12) & 0x40) != 0) {

      uVar3 = 0xffff7fff;

    }

    FUN_14015aab0(param_3,param_2,5,uVar3);

    FUN_14015aab0(param_3,param_2,4,(*(char *)(param_4 + 0x12) >> 7) + -0x8000);

  }

  return;

}




