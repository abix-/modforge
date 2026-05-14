// Address: 0x14027ad40
// Ghidra name: FUN_14027ad40
// ============ 0x14027ad40 FUN_14027ad40 (size=646) ============


void FUN_14027ad40(undefined8 param_1,undefined8 param_2,longlong param_3,longlong param_4,

                  int param_5)



{

  byte bVar1;

  undefined8 uVar2;

  byte bVar3;

  byte bVar4;

  ulonglong uVar5;

  

  uVar2 = FUN_140149300();

  bVar1 = *(byte *)(param_4 + 2);

  if (*(byte *)(param_3 + 0x13) != bVar1) {

    bVar4 = bVar1 & 1 | 4;

    if ((bVar1 & 2) == 0) {

      bVar4 = bVar1 & 1;

    }

    bVar3 = bVar4 | 8;

    if ((bVar1 & 4) == 0) {

      bVar3 = bVar4;

    }

    bVar4 = bVar3 | 2;

    if ((bVar1 & 8) == 0) {

      bVar4 = bVar3;

    }

    FUN_14015ae90(uVar2,param_1,0,bVar4);

    FUN_14015ad00(uVar2,param_1,6,*(byte *)(param_4 + 2) >> 4 & 1);

    FUN_14015ad00(uVar2,param_1,4,*(byte *)(param_4 + 2) >> 5 & 1);

    FUN_14015ad00(uVar2,param_1,7,*(byte *)(param_4 + 2) >> 6 & 1);

    FUN_14015ad00(uVar2,param_1,8,*(byte *)(param_4 + 2) >> 7);

  }

  if (*(byte *)(param_3 + 0x14) != *(byte *)(param_4 + 3)) {

    FUN_14015ad00(uVar2,param_1,9,*(byte *)(param_4 + 3) & 1);

    FUN_14015ad00(uVar2,param_1,10,*(byte *)(param_4 + 3) >> 1 & 1);

    FUN_14015ad00(uVar2,param_1,5,*(byte *)(param_4 + 3) >> 2 & 1);

    FUN_14015ad00(uVar2,param_1,0,*(byte *)(param_4 + 3) >> 4 & 1);

    FUN_14015ad00(uVar2,param_1,1,*(byte *)(param_4 + 3) >> 5 & 1);

    FUN_14015ad00(uVar2,param_1,2,*(byte *)(param_4 + 3) >> 6 & 1);

    FUN_14015ad00(uVar2,param_1,3,*(byte *)(param_4 + 3) >> 7);

  }

  FUN_14015aab0(uVar2,param_1,4,(ushort)*(byte *)(param_4 + 4) * 0x101 + -0x8000);

  FUN_14015aab0(uVar2,param_1,5,(ushort)*(byte *)(param_4 + 5) * 0x101 + -0x8000);

  FUN_14015aab0(uVar2,param_1,0,*(undefined2 *)(param_4 + 6));

  FUN_14015aab0(uVar2,param_1,1,~*(ushort *)(param_4 + 8));

  FUN_14015aab0(uVar2,param_1,2,*(undefined2 *)(param_4 + 10));

  FUN_14015aab0(uVar2,param_1,3,~*(ushort *)(param_4 + 0xc));

  uVar5 = 0x40;

  if ((ulonglong)(longlong)param_5 < 0x40) {

    uVar5 = (longlong)param_5;

  }

  FUN_1402f8e20(param_3 + 0x11,param_4,uVar5);

  return;

}




