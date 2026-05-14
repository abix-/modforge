// Address: 0x14026f040
// Ghidra name: FUN_14026f040
// ============ 0x14026f040 FUN_14026f040 (size=757) ============


void FUN_14026f040(undefined8 param_1,longlong param_2,byte *param_3,int param_4)



{

  undefined8 uVar1;

  int *piVar2;

  ulonglong uVar3;

  undefined8 uVar4;

  char cVar5;

  longlong lVar6;

  

  uVar1 = FUN_140149300();

  if (*(byte *)(param_2 + 0x1a) != *param_3) {

    FUN_14015ad00(uVar1,param_1,2,*param_3 & 1);

    FUN_14015ad00(uVar1,param_1,0,*param_3 >> 1 & 1);

    FUN_14015ad00(uVar1,param_1,1,*param_3 >> 2 & 1);

    FUN_14015ad00(uVar1,param_1,3,*param_3 >> 3 & 1);

    FUN_14015ad00(uVar1,param_1,9,*param_3 >> 4 & 1);

    FUN_14015ad00(uVar1,param_1,10,*param_3 >> 5 & 1);

  }

  if (*(byte *)(param_2 + 0x1b) != param_3[1]) {

    FUN_14015ad00(uVar1,param_1,4,param_3[1] & 1);

    FUN_14015ad00(uVar1,param_1,6,param_3[1] >> 1 & 1);

    FUN_14015ad00(uVar1,param_1,7,param_3[1] >> 2 & 1);

    FUN_14015ad00(uVar1,param_1,8,param_3[1] >> 3 & 1);

    switch(param_3[1] >> 4) {

    case 0:

      uVar4 = 1;

      break;

    case 1:

      uVar4 = 3;

      break;

    case 2:

      uVar4 = 2;

      break;

    case 3:

      uVar4 = 6;

      break;

    case 4:

      uVar4 = 4;

      break;

    case 5:

      uVar4 = 0xc;

      break;

    case 6:

      uVar4 = 8;

      break;

    case 7:

      uVar4 = 9;

      break;

    default:

      uVar4 = 0;

    }

    FUN_14015ae90(uVar1,param_1,0,uVar4);

  }

  FUN_14015aab0(uVar1,param_1,4,(ushort)param_3[0x10] * 0x101 + -0x8000);

  FUN_14015aab0(uVar1,param_1,5,(ushort)param_3[0x11] * 0x101 + -0x8000);

  FUN_14015aab0(uVar1,param_1,0,(ushort)param_3[2] * 0x101 + -0x8000);

  FUN_14015aab0(uVar1,param_1,1,(ushort)param_3[3] * 0x101 + -0x8000);

  FUN_14015aab0(uVar1,param_1,2,(ushort)param_3[4] * 0x101 + -0x8000);

  FUN_14015aab0(uVar1,param_1,3,(ushort)param_3[5] * 0x101 + -0x8000);

  if (*(char *)(param_2 + 0x11) != '\0') {

    cVar5 = '\x06';

    piVar2 = &DAT_1403e5dd8;

    lVar6 = 0xf;

    do {

      if (*piVar2 != 0) {

        FUN_14015aab0(uVar1,param_1,cVar5,(ushort)param_3[*piVar2] * 0x101 + -0x8000);

        cVar5 = cVar5 + '\x01';

      }

      piVar2 = piVar2 + 1;

      lVar6 = lVar6 + -1;

    } while (lVar6 != 0);

  }

  uVar3 = 0x40;

  if ((ulonglong)(longlong)param_4 < 0x40) {

    uVar3 = (longlong)param_4;

  }

  FUN_1402f8e20((byte *)(param_2 + 0x1a),param_3,uVar3);

  return;

}




