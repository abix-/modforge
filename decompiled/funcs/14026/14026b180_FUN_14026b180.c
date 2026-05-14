// Address: 0x14026b180
// Ghidra name: FUN_14026b180
// ============ 0x14026b180 FUN_14026b180 (size=521) ============


void FUN_14026b180(undefined8 param_1,undefined8 param_2,longlong param_3,longlong param_4)



{

  byte bVar1;

  undefined1 uVar2;

  ushort uVar3;

  

  bVar1 = *(byte *)(param_4 + 3);

  if (bVar1 != *(byte *)(param_3 + 0xf1)) {

    FUN_14015ad00(param_1,param_2,6,bVar1 & 1);

    FUN_14015ad00(param_1,param_2,7,bVar1 >> 3 & 1);

    FUN_14015ad00(param_1,param_2,5,bVar1 >> 5 & 1);

  }

  bVar1 = *(byte *)(param_4 + 4);

  if (bVar1 != *(byte *)(param_3 + 0xf2)) {

    uVar2 = FUN_14026ca40(param_3,0);

    FUN_14015ad00(param_1,param_2,uVar2);

    uVar2 = FUN_14026ca40(param_3,1);

    FUN_14015ad00(param_1,param_2,uVar2);

    uVar2 = FUN_14026ca40(param_3,2);

    FUN_14015ad00(param_1,param_2,uVar2);

    uVar2 = FUN_14026ca40(param_3,3);

    FUN_14015ad00(param_1,param_2,uVar2);

    FUN_14015ad00(param_1,param_2,10,bVar1 >> 4 & 1);

    FUN_14015ad00(param_1,param_2,9,bVar1 >> 5 & 1);

    FUN_14015ad00(param_1,param_2,0xd,bVar1 >> 6 & 1);

    FUN_14015ad00(param_1,param_2,0xf,bVar1 >> 7);

  }

  uVar3 = FUN_140269080(param_3,0,0,*(ushort *)(param_4 + 5) & 0xfff);

  FUN_14015aab0(param_1,param_2,1,~uVar3);

  uVar3 = FUN_140269080(param_3,0,1,

                        (ushort)*(byte *)(param_4 + 7) << 4 | (ushort)(*(byte *)(param_4 + 6) >> 4))

  ;

  FUN_14015aab0(param_1,param_2,0,~uVar3);

  return;

}




