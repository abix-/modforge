// Address: 0x140269c30
// Ghidra name: FUN_140269c30
// ============ 0x140269c30 FUN_140269c30 (size=467) ============


void FUN_140269c30(undefined8 param_1,undefined8 param_2,longlong param_3,longlong param_4)



{

  byte bVar1;

  byte bVar2;

  undefined2 uVar3;

  ushort uVar4;

  byte bVar5;

  

  bVar1 = *(byte *)(param_4 + 3);

  if (bVar1 != *(byte *)(param_3 + 0xf1)) {

    FUN_14015ad00(param_1,param_2,4,bVar1 & 1);

    FUN_14015ad00(param_1,param_2,7,bVar1 >> 3 & 1);

    FUN_14015ad00(param_1,param_2,0xb,bVar1 >> 5 & 1);

  }

  bVar1 = *(byte *)(param_4 + 4);

  if (bVar1 != *(byte *)(param_3 + 0xf2)) {

    bVar2 = (bVar1 & 1) << 2;

    bVar5 = bVar2 | 1;

    if ((bVar1 & 2) == 0) {

      bVar5 = bVar2;

    }

    bVar2 = bVar5 | 2;

    if ((bVar1 & 4) == 0) {

      bVar2 = bVar5;

    }

    bVar5 = bVar2 | 8;

    if ((bVar1 & 8) == 0) {

      bVar5 = bVar2;

    }

    FUN_14015ae90(param_1,param_2,0,bVar5);

    FUN_14015ad00(param_1,param_2,0xf,bVar1 >> 4 & 1);

    FUN_14015ad00(param_1,param_2,0xd,bVar1 >> 5 & 1);

    FUN_14015ad00(param_1,param_2,9,bVar1 >> 6 & 1);

    FUN_14015aab0(param_1,param_2,4,((char)bVar1 >> 7) + -0x8000);

  }

  uVar3 = FUN_140269080(param_3,0,0,*(ushort *)(param_4 + 5) & 0xfff);

  FUN_14015aab0(param_1,param_2,0,uVar3);

  uVar4 = FUN_140269080(param_3,0,1,

                        (ushort)*(byte *)(param_4 + 7) << 4 | (ushort)(*(byte *)(param_4 + 6) >> 4))

  ;

  FUN_14015aab0(param_1,param_2,1,~uVar4);

  return;

}




