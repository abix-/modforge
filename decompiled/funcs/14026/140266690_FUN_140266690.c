// Address: 0x140266690
// Ghidra name: FUN_140266690
// ============ 0x140266690 FUN_140266690 (size=403) ============


void FUN_140266690(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)



{

  short sVar1;

  short sVar2;

  

  FUN_14015ad00(param_3,param_2,7,*(byte *)(param_4 + 1) >> 6 & 1);

  FUN_14015ad00(param_3,param_2,8,*(byte *)(param_4 + 1) >> 7);

  sVar2 = -0x8000;

  sVar1 = *(short *)(param_4 + 2);

  if (sVar1 < 0) {

    sVar1 = -0x8000;

  }

  else if ((0x3ff < sVar1) || (sVar1 = (sVar1 + -0x200) * 0x40, sVar1 == 0x7fc0)) {

    sVar1 = 0x7fff;

  }

  FUN_14015aab0(param_3,param_2,4,sVar1);

  sVar1 = *(short *)(param_4 + 4);

  if ((-1 < sVar1) && ((0x3ff < sVar1 || (sVar2 = (sVar1 + -0x200) * 0x40, sVar2 == 0x7fc0)))) {

    sVar2 = 0x7fff;

  }

  FUN_14015aab0(param_3,param_2,5,sVar2);

  FUN_14015aab0(param_3,param_2,0,*(undefined2 *)(param_4 + 6));

  FUN_14015aab0(param_3,param_2,1,~*(ushort *)(param_4 + 8));

  FUN_14015aab0(param_3,param_2,2,*(undefined2 *)(param_4 + 10));

  FUN_14015aab0(param_3,param_2,3,~*(ushort *)(param_4 + 0xc));

  return;

}




