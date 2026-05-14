// Address: 0x14026a030
// Ghidra name: FUN_14026a030
// ============ 0x14026a030 FUN_14026a030 (size=562) ============


void FUN_14026a030(undefined8 param_1,undefined8 param_2,longlong param_3,byte *param_4)



{

  byte bVar1;

  byte bVar2;

  byte bVar3;

  undefined8 uVar4;

  

  bVar1 = *param_4;

  if (bVar1 != *(byte *)(param_3 + 0xe3)) {

    bVar2 = (bVar1 & 1) << 3;

    bVar3 = bVar2 | 4;

    if ((bVar1 & 2) == 0) {

      bVar3 = bVar2;

    }

    bVar2 = bVar3 | 1;

    if ((bVar1 & 4) == 0) {

      bVar2 = bVar3;

    }

    bVar3 = bVar2 | 2;

    if ((bVar1 & 8) == 0) {

      bVar3 = bVar2;

    }

    FUN_14015ae90(param_1,param_2,0,bVar3);

    FUN_14015ad00(param_1,param_2,0xd,bVar1 >> 4 & 1);

    FUN_14015ad00(param_1,param_2,0xf,bVar1 >> 5 & 1);

  }

  bVar1 = param_4[1];

  if (bVar1 != *(byte *)(param_3 + 0xe4)) {

    FUN_14015ad00(param_1,param_2,4,bVar1 & 1);

    FUN_14015ad00(param_1,param_2,7,bVar1 >> 2 & 1);

    FUN_14015ad00(param_1,param_2,0xb,bVar1 >> 5 & 1);

    FUN_14015ad00(param_1,param_2,9,bVar1 >> 6 & 1);

  }

  FUN_14015aab0(param_1,param_2,4,((char)param_4[1] >> 7) + -0x8000);

  if (param_4[2] == *(byte *)(param_3 + 0xe5)) {

    return;

  }

  switch(param_4[2]) {

  case 0:

    uVar4 = 0x7fff;

    break;

  case 1:

    FUN_14015aab0(param_1,param_2,0,0x7fff);

    uVar4 = 0x7fff;

    goto LAB_14026a239;

  case 2:

    FUN_14015aab0(param_1,param_2,0,0);

    uVar4 = 0x7fff;

    goto LAB_14026a239;

  case 3:

    FUN_14015aab0(param_1,param_2,0,0xffff8000);

    uVar4 = 0x7fff;

    goto LAB_14026a239;

  case 4:

    uVar4 = 0xffff8000;

    break;

  case 5:

    uVar4 = 0xffff8000;

    goto LAB_14026a205;

  case 6:

    uVar4 = 0;

    goto LAB_14026a205;

  case 7:

    uVar4 = 0x7fff;

LAB_14026a205:

    FUN_14015aab0(param_1,param_2,0,uVar4);

    uVar4 = 0xffff8000;

    goto LAB_14026a239;

  default:

    uVar4 = 0;

  }

  FUN_14015aab0(param_1,param_2,0,uVar4);

  uVar4 = 0;

LAB_14026a239:

  FUN_14015aab0(param_1,param_2,1,uVar4);

  return;

}




