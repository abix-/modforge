// Address: 0x140269e10
// Ghidra name: FUN_140269e10
// ============ 0x140269e10 FUN_140269e10 (size=530) ============


void FUN_140269e10(undefined8 param_1,undefined8 param_2,longlong param_3,longlong param_4)



{

  byte bVar1;

  undefined1 uVar2;

  undefined2 uVar3;

  ushort uVar4;

  

  bVar1 = *(byte *)(param_4 + 2);

  if (bVar1 != *(byte *)(param_3 + 0xf0)) {

    uVar2 = FUN_14026ca40(param_3,0,param_3,bVar1 >> 2 & 1);

    FUN_14015ad00(param_1,param_2,uVar2);

    uVar2 = FUN_14026ca40(param_3,1);

    FUN_14015ad00(param_1,param_2,uVar2);

    uVar2 = FUN_14026ca40(param_3,2);

    FUN_14015ad00(param_1,param_2,uVar2);

    uVar2 = FUN_14026ca40(param_3,3);

    FUN_14015ad00(param_1,param_2,uVar2);

    FUN_14015ad00(param_1,param_2,0xc,bVar1 >> 4 & 1);

    FUN_14015ad00(param_1,param_2,0xe,bVar1 >> 5 & 1);

    FUN_14015ad00(param_1,param_2,10,bVar1 >> 6 & 1);

    FUN_14015aab0(param_1,param_2,5,((char)bVar1 >> 7) + -0x8000);

  }

  bVar1 = *(byte *)(param_4 + 3);

  if (bVar1 != *(byte *)(param_3 + 0xf1)) {

    FUN_14015ad00(param_1,param_2,6,bVar1 >> 1 & 1);

    FUN_14015ad00(param_1,param_2,8,bVar1 >> 2 & 1);

    FUN_14015ad00(param_1,param_2,5,bVar1 >> 4 & 1);

  }

  uVar3 = FUN_140269080(param_3,1,0,*(ushort *)(param_4 + 8) & 0xfff);

  FUN_14015aab0(param_1,param_2,2,uVar3);

  uVar4 = FUN_140269080(param_3,1,1,

                        (ushort)*(byte *)(param_4 + 10) << 4 | (ushort)(*(byte *)(param_4 + 9) >> 4)

                       );

  FUN_14015aab0(param_1,param_2,3,~uVar4);

  return;

}




