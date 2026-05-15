// Address: 0x14026bb40
// Ghidra name: FUN_14026bb40
// ============ 0x14026bb40 FUN_14026bb40 (size=925) ============


void FUN_14026bb40(undefined8 param_1,longlong *param_2,byte *param_3)



{

  byte bVar1;

  undefined1 uVar2;

  undefined2 uVar3;

  undefined8 uVar4;

  undefined8 uVar5;

  

  uVar4 = FUN_140149300();

  if ((int)param_2[4] == 1) {

    if ((*(longlong *)(*param_2 + 0xa0) == 0) && ((char)param_2[0x1a] == '\0')) {

      FUN_14026b5a0(uVar4,param_1,param_2,param_3);

    }

    else {

      FUN_14026a030(uVar4,param_1,param_2,param_3);

    }

  }

  else if ((int)param_2[4] == 2) {

    if ((*(longlong *)(*param_2 + 0xa0) == 0) && ((char)param_2[0x1a] == '\0')) {

      FUN_14026b860(uVar4,param_1,param_2,param_3);

    }

    else {

      FUN_14026a290(uVar4,param_1,param_2,param_3);

    }

  }

  else {

    bVar1 = *param_3;

    if (bVar1 != *(byte *)((longlong)param_2 + 0xe3)) {

      uVar2 = FUN_14026ca40(param_2,0);

      FUN_14015ad00(uVar4,param_1,uVar2);

      uVar2 = FUN_14026ca40(param_2,1);

      FUN_14015ad00(uVar4,param_1,uVar2);

      uVar2 = FUN_14026ca40(param_2,2);

      FUN_14015ad00(uVar4,param_1,uVar2);

      uVar2 = FUN_14026ca40(param_2,3);

      FUN_14015ad00(uVar4,param_1,uVar2);

      FUN_14015ad00(uVar4,param_1,9,bVar1 >> 4 & 1);

      FUN_14015ad00(uVar4,param_1,10,bVar1 >> 5 & 1);

    }

    bVar1 = param_3[1];

    if (bVar1 != *(byte *)((longlong)param_2 + 0xe4)) {

      FUN_14015ad00(uVar4,param_1,4,bVar1 & 1);

      FUN_14015ad00(uVar4,param_1,6,bVar1 >> 1 & 1);

      FUN_14015ad00(uVar4,param_1,7,bVar1 >> 2 & 1);

      FUN_14015ad00(uVar4,param_1,8,bVar1 >> 3 & 1);

      FUN_14015ad00(uVar4,param_1,5,bVar1 >> 4 & 1);

      FUN_14015ad00(uVar4,param_1,0xb,bVar1 >> 5 & 1);

    }

    if (param_3[2] != *(byte *)((longlong)param_2 + 0xe5)) {

      switch(param_3[2]) {

      case 0:

        uVar5 = 1;

        break;

      case 1:

        uVar5 = 3;

        break;

      case 2:

        uVar5 = 2;

        break;

      case 3:

        uVar5 = 6;

        break;

      case 4:

        uVar5 = 4;

        break;

      case 5:

        uVar5 = 0xc;

        break;

      case 6:

        uVar5 = 8;

        break;

      case 7:

        uVar5 = 9;

        break;

      default:

        uVar5 = 0;

      }

      FUN_14015ae90(uVar4,param_1,0,uVar5);

    }

    uVar3 = 0x8000;

    uVar5 = 0xffff8000;

    if ((*param_3 & 0x40) != 0) {

      uVar5 = 0xffff7fff;

    }

    FUN_14015aab0(uVar4,param_1,4,uVar5);

    if (((char)*param_3 < '\0') || ((char)param_3[1] < '\0')) {

      uVar3 = 0x7fff;

    }

    FUN_14015aab0(uVar4,param_1,5,uVar3);

    uVar3 = FUN_140268fe0(param_2,0,0,*(undefined2 *)(param_3 + 3));

    FUN_14015aab0(uVar4,param_1,0,uVar3);

    uVar3 = FUN_140268fe0(param_2,0,1,*(undefined2 *)(param_3 + 5));

    FUN_14015aab0(uVar4,param_1,1,uVar3);

    uVar3 = FUN_140268fe0(param_2,1,0,*(undefined2 *)(param_3 + 7));

    FUN_14015aab0(uVar4,param_1,2,uVar3);

    uVar3 = FUN_140268fe0(param_2,1,1,*(undefined2 *)(param_3 + 9));

    FUN_14015aab0(uVar4,param_1,3,uVar3);

  }

  *(undefined8 *)((longlong)param_2 + 0xe3) = *(undefined8 *)param_3;

  *(undefined2 *)((longlong)param_2 + 0xeb) = *(undefined2 *)(param_3 + 8);

  *(byte *)((longlong)param_2 + 0xed) = param_3[10];

  return;

}




