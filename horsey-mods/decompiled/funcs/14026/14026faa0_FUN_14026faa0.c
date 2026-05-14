// Address: 0x14026faa0
// Ghidra name: FUN_14026faa0
// ============ 0x14026faa0 FUN_14026faa0 (size=946) ============


void FUN_14026faa0(undefined8 param_1,longlong param_2,longlong param_3,int param_4)



{

  byte bVar1;

  byte bVar2;

  undefined8 uVar3;

  byte bVar4;

  int *piVar5;

  ulonglong uVar6;

  char cVar7;

  longlong lVar8;

  undefined4 local_48;

  uint local_44;

  uint local_40;

  

  uVar3 = FUN_140149300();

  if (*(byte *)(param_2 + 0x1c) != *(byte *)(param_3 + 2)) {

    FUN_14015ad00(uVar3,param_1,4,*(byte *)(param_3 + 2) & 1);

    FUN_14015ad00(uVar3,param_1,7,*(byte *)(param_3 + 2) >> 1 & 1);

    FUN_14015ad00(uVar3,param_1,8,*(byte *)(param_3 + 2) >> 2 & 1);

    FUN_14015ad00(uVar3,param_1,6,*(byte *)(param_3 + 2) >> 3 & 1);

    bVar1 = *(byte *)(param_3 + 2);

    bVar2 = bVar1 >> 4 & 1;

    bVar4 = bVar2 | 2;

    if ((bVar1 & 0x20) == 0) {

      bVar4 = bVar2;

    }

    bVar2 = bVar4 | 4;

    if ((bVar1 & 0x40) == 0) {

      bVar2 = bVar4;

    }

    bVar4 = bVar2 | 8;

    if (-1 < (char)bVar1) {

      bVar4 = bVar2;

    }

    FUN_14015ae90(uVar3,param_1,0,bVar4);

  }

  if (*(byte *)(param_2 + 0x1d) != *(byte *)(param_3 + 3)) {

    FUN_14015ad00(uVar3,param_1,9,*(byte *)(param_3 + 3) >> 2 & 1);

    FUN_14015ad00(uVar3,param_1,10,*(byte *)(param_3 + 3) >> 3 & 1);

    FUN_14015ad00(uVar3,param_1,3,*(byte *)(param_3 + 3) >> 4 & 1);

    FUN_14015ad00(uVar3,param_1,1,*(byte *)(param_3 + 3) >> 5 & 1);

    FUN_14015ad00(uVar3,param_1,0,*(byte *)(param_3 + 3) >> 6 & 1);

    FUN_14015ad00(uVar3,param_1,2,*(byte *)(param_3 + 3) >> 7);

  }

  if (*(byte *)(param_2 + 0x1e) != *(byte *)(param_3 + 4)) {

    FUN_14015ad00(uVar3,param_1,5,*(byte *)(param_3 + 4) & 1);

  }

  FUN_14015aab0(uVar3,param_1,4,(ushort)*(byte *)(param_3 + 0x12) * 0x101 + -0x8000);

  FUN_14015aab0(uVar3,param_1,5,(ushort)*(byte *)(param_3 + 0x13) * 0x101 + -0x8000);

  FUN_14015aab0(uVar3,param_1,0,(ushort)*(byte *)(param_3 + 6) * 0x101 + -0x8000);

  FUN_14015aab0(uVar3,param_1,1,(ushort)*(byte *)(param_3 + 7) * 0x101 + -0x8000);

  FUN_14015aab0(uVar3,param_1,2,(ushort)*(byte *)(param_3 + 8) * 0x101 + -0x8000);

  FUN_14015aab0(uVar3,param_1,3,(ushort)*(byte *)(param_3 + 9) * 0x101 + -0x8000);

  if (*(char *)(param_2 + 0x11) != '\0') {

    piVar5 = &DAT_1403e5d98;

    lVar8 = 0xf;

    cVar7 = '\x06';

    do {

      if (*piVar5 != 0) {

        FUN_14015aab0(uVar3,param_1,cVar7,(ushort)*(byte *)(*piVar5 + param_3) * 0x101 + -0x8000);

        cVar7 = cVar7 + '\x01';

      }

      piVar5 = piVar5 + 1;

      lVar8 = lVar8 + -1;

    } while (lVar8 != 0);

  }

  if (*(char *)(param_2 + 0x12) != '\0') {

    local_48 = FUN_14026fe60(*(undefined2 *)(param_3 + 0x29));

    local_44 = FUN_14026fe60(*(undefined2 *)(param_3 + 0x2d));

    local_44 = local_44 ^ DAT_14039cac0;

    local_40 = FUN_14026fe60(*(undefined2 *)(param_3 + 0x2b));

    local_40 = local_40 ^ DAT_14039cac0;

    FUN_14015afd0(uVar3,param_1,1,uVar3,&local_48,3);

  }

  uVar6 = 0x40;

  if ((ulonglong)(longlong)param_4 < 0x40) {

    uVar6 = (longlong)param_4;

  }

  FUN_1402f8e20(param_2 + 0x1a,param_3,uVar6);

  return;

}




