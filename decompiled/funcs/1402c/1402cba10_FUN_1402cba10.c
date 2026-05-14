// Address: 0x1402cba10
// Ghidra name: FUN_1402cba10
// ============ 0x1402cba10 FUN_1402cba10 (size=130) ============


HandlerMap4 *

FUN_1402cba10(HandlerMap4 *param_1,longlong param_2,longlong param_3,undefined4 param_4)



{

  byte *pbVar1;

  longlong lVar2;

  

  *(undefined8 *)(param_1 + 8) = 0;

  *(undefined8 *)(param_1 + 0x10) = 0;

  param_1[0x18] = (HandlerMap4)0x0;

  *(undefined8 *)(param_1 + 0x1c) = 0;

  *(undefined8 *)(param_1 + 0x24) = 0;

  *(undefined8 *)(param_1 + 0x30) = 0;

  *(undefined8 *)(param_1 + 0x38) = 0;

  *(longlong *)(param_1 + 0x40) = param_3;

  *(undefined4 *)(param_1 + 0x48) = param_4;

  if (*(int *)(param_2 + 0xc) == 0) {

    *(undefined4 *)param_1 = 0;

  }

  else {

    pbVar1 = (byte *)(*(int *)(param_2 + 0xc) + param_3);

    *(byte **)(param_1 + 8) = pbVar1;

    lVar2 = (longlong)pbVar1 - (longlong)(char)(&DAT_1403872c0)[*pbVar1 & 0xf];

    *(uint *)param_1 = *(uint *)(lVar2 + -4) >> ((&DAT_1403872d0)[*pbVar1 & 0xf] & 0x1f);

    *(longlong *)(param_1 + 8) = lVar2;

    *(longlong *)(param_1 + 0x10) = lVar2;

    FH4::HandlerMap4::DecompHandler(param_1);

  }

  return param_1;

}




