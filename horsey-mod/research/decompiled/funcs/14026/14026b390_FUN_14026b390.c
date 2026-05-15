// Address: 0x14026b390
// Ghidra name: FUN_14026b390
// ============ 0x14026b390 FUN_14026b390 (size=526) ============


void FUN_14026b390(undefined8 param_1,undefined8 param_2,longlong param_3,longlong param_4)



{

  byte bVar1;

  undefined1 uVar2;

  undefined2 uVar3;

  

  bVar1 = *(byte *)(param_4 + 2);

  if (bVar1 != *(byte *)(param_3 + 0xf0)) {

    uVar2 = FUN_14026ca40(param_3,0,param_3,bVar1 >> 3 & 1);

    FUN_14015ad00(param_1,param_2,uVar2);

    uVar2 = FUN_14026ca40(param_3,1);

    FUN_14015ad00(param_1,param_2,uVar2);

    uVar2 = FUN_14026ca40(param_3,2);

    FUN_14015ad00(param_1,param_2,uVar2);

    uVar2 = FUN_14026ca40(param_3,3);

    FUN_14015ad00(param_1,param_2,uVar2);

    FUN_14015ad00(param_1,param_2,10,bVar1 >> 4 & 1);

    FUN_14015ad00(param_1,param_2,9,bVar1 >> 5 & 1);

    FUN_14015ad00(param_1,param_2,0xc,bVar1 >> 6 & 1);

    FUN_14015ad00(param_1,param_2,0xe,bVar1 >> 7);

  }

  bVar1 = *(byte *)(param_4 + 3);

  if (bVar1 != *(byte *)(param_3 + 0xf1)) {

    FUN_14015ad00(param_1,param_2,6,bVar1 >> 1 & 1);

    FUN_14015ad00(param_1,param_2,7,bVar1 >> 2 & 1);

    FUN_14015ad00(param_1,param_2,5,bVar1 >> 4 & 1);

  }

  uVar3 = FUN_140269080(param_3,1,0,*(ushort *)(param_4 + 8) & 0xfff);

  FUN_14015aab0(param_1,param_2,1,uVar3);

  uVar3 = FUN_140269080(param_3,1,1,

                        (ushort)*(byte *)(param_4 + 10) << 4 | (ushort)(*(byte *)(param_4 + 9) >> 4)

                       );

  FUN_14015aab0(param_1,param_2,0,uVar3);

  return;

}




