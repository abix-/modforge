// Address: 0x140278b50
// Ghidra name: FUN_140278b50
// ============ 0x140278b50 FUN_140278b50 (size=438) ============


void FUN_140278b50(longlong param_1,undefined8 param_2,longlong param_3)



{

  byte bVar1;

  char cVar2;

  byte bVar3;

  byte bVar4;

  undefined2 uVar5;

  undefined *puVar6;

  undefined2 uVar7;

  

  if (5 < *(byte *)(param_3 + 0x1c)) {

    puVar6 = &DAT_14037f8a0;

    if (*(char *)(param_1 + 0x2a) == '\a') {

      puVar6 = &DAT_14037f8b8;

    }

    uVar7 = 0;

    FUN_140279770(*(undefined8 *)(param_1 + 0x10),param_2,puVar6,param_3 + 9,2,0,1);

    if (*(char *)(param_1 + 0x2a) == '\a') {

      uVar7 = 0;

      FUN_140279770(*(undefined8 *)(param_1 + 0x10),param_2,&DAT_14037f8d0,param_3 + 5,2,0,1);

    }

    bVar1 = *(byte *)(param_3 + 10);

    FUN_14015aab0(*(undefined8 *)(param_1 + 0x10),param_2,4,(char)((char)bVar1 >> 7 & 1) + 0x7fff);

    uVar5 = 0x7fff;

    if ((bVar1 & 4) != 0) {

      uVar5 = 0x8000;

    }

    FUN_14015aab0(*(undefined8 *)(param_1 + 0x10),param_2,5,uVar5);

    bVar1 = *(byte *)(param_3 + 5);

    cVar2 = *(char *)(param_1 + 0x2a);

    bVar3 = *(byte *)(param_3 + 6);

    bVar4 = *(byte *)(param_3 + 7);

    FUN_140279910(*(undefined8 *)(param_1 + 0x10),param_2,param_1 + 0x62,0,

                  CONCAT22(uVar7,(ushort)((cVar2 != '\a') + 0x3eU & bVar1)));

    FUN_140279910(*(undefined8 *)(param_1 + 0x10),param_2,param_1 + 0x6a,1,

                  (cVar2 != '\a') + 0x3eU & bVar3);

    FUN_140279910(*(undefined8 *)(param_1 + 0x10),param_2,param_1 + 0x72,2,

                  (byte)((byte)(bVar4 >> 2 | bVar3 & 0xdf) >> 2 | bVar1 & 199) >> 3);

    FUN_140279910(*(undefined8 *)(param_1 + 0x10),param_2,param_1 + 0x7a,3,bVar4 & 0x1f);

  }

  return;

}




