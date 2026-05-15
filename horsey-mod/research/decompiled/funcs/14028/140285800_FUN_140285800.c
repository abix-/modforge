// Address: 0x140285800
// Ghidra name: FUN_140285800
// ============ 0x140285800 FUN_140285800 (size=380) ============


void FUN_140285800(undefined8 param_1,longlong param_2,undefined8 param_3)



{

  ushort uVar1;

  byte bVar2;

  undefined8 uVar3;

  byte bVar4;

  ushort *puVar5;

  

  uVar1 = *(ushort *)(param_2 + 4);

  uVar3 = FUN_140149300();

  FUN_14015aab0(uVar3,param_1,0,*(undefined2 *)(param_2 + 8));

  FUN_14015aab0(uVar3,param_1,1,~*(ushort *)(param_2 + 10));

  FUN_14015aab0(uVar3,param_1,2,(ushort)*(byte *)(param_2 + 6) * 0x101 + -0x8000);

  FUN_14015aab0(uVar3,param_1,3,*(undefined2 *)(param_2 + 0xc));

  FUN_14015aab0(uVar3,param_1,4,~*(ushort *)(param_2 + 0xe));

  FUN_14015aab0(uVar3,param_1,5,(ushort)*(byte *)(param_2 + 7) * 0x101 + -0x8000);

  bVar4 = 0;

  puVar5 = &DAT_1403e6a18;

  do {

    FUN_14015ad00(uVar3,param_1,bVar4,(*puVar5 & uVar1) != 0);

    bVar4 = bVar4 + 1;

    puVar5 = puVar5 + 1;

  } while (bVar4 < 0xb);

  bVar2 = (byte)uVar1 & 1;

  bVar4 = bVar2 | 4;

  if ((uVar1 & 2) == 0) {

    bVar4 = bVar2;

  }

  bVar2 = bVar4 | 8;

  if ((uVar1 & 4) == 0) {

    bVar2 = bVar4;

  }

  bVar4 = bVar2 | 2;

  if ((uVar1 & 8) == 0) {

    bVar4 = bVar2;

  }

  FUN_14015ae90(uVar3,param_1,0,bVar4);

  FUN_140285780(param_1,param_3);

  return;

}




