// Address: 0x14026f360
// Ghidra name: FUN_14026f360
// ============ 0x14026f360 FUN_14026f360 (size=1084) ============


void FUN_14026f360(undefined8 param_1,longlong *param_2,byte *param_3,int param_4)



{

  undefined8 uVar1;

  byte bVar2;

  byte bVar3;

  short sVar4;

  int *piVar5;

  ulonglong uVar6;

  short sVar7;

  char cVar8;

  longlong lVar9;

  uint uVar10;

  uint local_48;

  uint local_44;

  uint local_40;

  

  uVar1 = FUN_140149300();

  if (*(byte *)((longlong)param_2 + 0x1a) != *param_3) {

    FUN_14015ad00(uVar1,param_1,2,*param_3 & 1);

    FUN_14015ad00(uVar1,param_1,0,*param_3 >> 1 & 1);

    FUN_14015ad00(uVar1,param_1,1,*param_3 >> 2 & 1);

    FUN_14015ad00(uVar1,param_1,3,*param_3 >> 3 & 1);

    FUN_14015ad00(uVar1,param_1,9,*param_3 >> 4 & 1);

    FUN_14015ad00(uVar1,param_1,10,*param_3 >> 5 & 1);

  }

  if (*(byte *)((longlong)param_2 + 0x1b) != param_3[1]) {

    FUN_14015ad00(uVar1,param_1,4,param_3[1] & 1);

    FUN_14015ad00(uVar1,param_1,6,param_3[1] >> 1 & 1);

    FUN_14015ad00(uVar1,param_1,7,param_3[1] >> 2 & 1);

    FUN_14015ad00(uVar1,param_1,8,param_3[1] >> 3 & 1);

    FUN_14015ad00(uVar1,param_1,5,param_3[1] >> 4 & 1);

  }

  if ((*(short *)(*param_2 + 0x20) == 0x6a3) && (*(short *)(*param_2 + 0x22) == -0x9de)) {

    bVar2 = -(param_3[7] != 0) & 2;

    bVar3 = bVar2 | 8;

    if (param_3[8] == 0) {

      bVar3 = bVar2;

    }

    bVar2 = bVar3 | 1;

    if (param_3[9] == 0) {

      bVar2 = bVar3;

    }

    bVar3 = bVar2 | 4;

    if (param_3[10] == 0) {

      bVar3 = bVar2;

    }

  }

  else {

    if (*(byte *)((longlong)param_2 + 0x1c) == param_3[2]) goto LAB_14026f581;

    switch(param_3[2] & 0xf) {

    case 0:

      bVar3 = 1;

      break;

    case 1:

      bVar3 = 3;

      break;

    case 2:

      bVar3 = 2;

      break;

    case 3:

      bVar3 = 6;

      break;

    case 4:

      bVar3 = 4;

      break;

    case 5:

      bVar3 = 0xc;

      break;

    case 6:

      bVar3 = 8;

      break;

    case 7:

      bVar3 = 9;

      break;

    default:

      bVar3 = 0;

    }

  }

  FUN_14015ae90(uVar1,param_1,0,bVar3);

LAB_14026f581:

  sVar4 = 0x7fff;

  if ((*param_3 & 0x40) == 0) {

    sVar7 = (ushort)param_3[0x11] * 0x101 + -0x8000;

  }

  else {

    sVar7 = 0x7fff;

  }

  FUN_14015aab0(uVar1,param_1,4,sVar7);

  if (-1 < (char)*param_3) {

    sVar4 = (ushort)param_3[0x12] * 0x101 + -0x8000;

  }

  FUN_14015aab0(uVar1,param_1,5,sVar4);

  FUN_14015aab0(uVar1,param_1,0,(ushort)param_3[3] * 0x101 + -0x8000);

  FUN_14015aab0(uVar1,param_1,1,(ushort)param_3[4] * 0x101 + -0x8000);

  FUN_14015aab0(uVar1,param_1,2,(ushort)param_3[5] * 0x101 + -0x8000);

  FUN_14015aab0(uVar1,param_1,3,(ushort)param_3[6] * 0x101 + -0x8000);

  if (*(char *)((longlong)param_2 + 0x11) != '\0') {

    cVar8 = '\x06';

    piVar5 = &DAT_1403e5e18;

    lVar9 = 0xf;

    do {

      if (*piVar5 != 0) {

        FUN_14015aab0(uVar1,param_1,cVar8,(ushort)param_3[*piVar5] * 0x101 + -0x8000);

        cVar8 = cVar8 + '\x01';

      }

      piVar5 = piVar5 + 1;

      lVar9 = lVar9 + -1;

    } while (lVar9 != 0);

  }

  if (*(char *)((longlong)param_2 + 0x12) != '\0') {

    local_48 = FUN_14026f7c0(*(undefined2 *)(param_3 + 0x13));

    local_48 = local_48 ^ DAT_14039cac0;

    uVar10 = DAT_14039cac0;

    local_44 = FUN_14026f7c0(*(undefined2 *)(param_3 + 0x15));

    local_44 = local_44 ^ uVar10;

    local_40 = FUN_14026f7c0(*(undefined2 *)(param_3 + 0x17));

    local_40 = local_40 ^ uVar10;

    FUN_14015afd0(uVar1,param_1,1,uVar1,&local_48,3);

  }

  uVar6 = 0x40;

  if ((ulonglong)(longlong)param_4 < 0x40) {

    uVar6 = (longlong)param_4;

  }

  FUN_1402f8e20((longlong)param_2 + 0x1a,param_3,uVar6);

  return;

}




