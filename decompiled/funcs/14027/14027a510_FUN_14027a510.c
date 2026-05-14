// Address: 0x14027a510
// Ghidra name: FUN_14027a510
// ============ 0x14027a510 FUN_14027a510 (size=657) ============


void FUN_14027a510(undefined8 param_1,longlong param_2,longlong param_3,int param_4)



{

  byte bVar1;

  undefined8 uVar2;

  byte bVar3;

  byte bVar4;

  ulonglong uVar5;

  

  uVar2 = FUN_140149300();

  bVar1 = *(byte *)(param_3 + 2);

  if (*(byte *)(param_2 + 0x17) != bVar1) {

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

    FUN_14015ad00(uVar2,param_1,6,*(byte *)(param_3 + 2) >> 4 & 1);

    FUN_14015ad00(uVar2,param_1,4,*(byte *)(param_3 + 2) >> 5 & 1);

    FUN_14015ad00(uVar2,param_1,7,*(byte *)(param_3 + 2) >> 6 & 1);

    FUN_14015ad00(uVar2,param_1,8,*(byte *)(param_3 + 2) >> 7);

  }

  if (*(byte *)(param_2 + 0x18) != *(byte *)(param_3 + 3)) {

    FUN_14015ad00(uVar2,param_1,9,*(byte *)(param_3 + 3) & 1);

    FUN_14015ad00(uVar2,param_1,10,*(byte *)(param_3 + 3) >> 1 & 1);

    FUN_14015ad00(uVar2,param_1,5,*(byte *)(param_3 + 3) >> 2 & 1);

    FUN_14015ad00(uVar2,param_1,0,*(byte *)(param_3 + 3) >> 4 & 1);

    FUN_14015ad00(uVar2,param_1,1,*(byte *)(param_3 + 3) >> 5 & 1);

    FUN_14015ad00(uVar2,param_1,2,*(byte *)(param_3 + 3) >> 6 & 1);

    FUN_14015ad00(uVar2,param_1,3,*(byte *)(param_3 + 3) >> 7);

  }

  FUN_14015aab0(uVar2,param_1,4,(ushort)*(byte *)(param_3 + 4) * 0x101 + -0x8000);

  FUN_14015aab0(uVar2,param_1,5,(ushort)*(byte *)(param_3 + 5) * 0x101 + -0x8000);

  FUN_14015aab0(uVar2,param_1,0,*(undefined2 *)(param_3 + 6));

  FUN_14015aab0(uVar2,param_1,1,~*(ushort *)(param_3 + 8));

  FUN_14015aab0(uVar2,param_1,2,*(undefined2 *)(param_3 + 10));

  FUN_14015aab0(uVar2,param_1,3,~*(ushort *)(param_3 + 0xc));

  uVar5 = 0x40;

  if ((ulonglong)(longlong)param_4 < 0x40) {

    uVar5 = (longlong)param_4;

  }

  FUN_1402f8e20(param_2 + 0x15,param_3,uVar5);

  return;

}




