// Address: 0x140279480
// Ghidra name: FUN_140279480
// ============ 0x140279480 FUN_140279480 (size=288) ============


void FUN_140279480(longlong param_1,undefined8 param_2,longlong param_3)



{

  byte bVar1;

  undefined2 uVar2;

  undefined2 *puVar3;

  longlong lVar4;

  longlong lVar5;

  undefined1 *puVar6;

  

  if (10 < *(byte *)(param_3 + 0x1c)) {

    FUN_140279770(*(undefined8 *)(param_1 + 0x10),param_2,&DAT_14037f8a0,param_3 + 0xd,3,0,1);

    bVar1 = *(byte *)(param_3 + 0xe);

    FUN_14015aab0(*(undefined8 *)(param_1 + 0x10),param_2,4,(char)((char)bVar1 >> 7 & 1) + 0x7fff);

    uVar2 = 0x7fff;

    if ((bVar1 & 4) != 0) {

      uVar2 = 0x8000;

    }

    FUN_14015aab0(*(undefined8 *)(param_1 + 0x10),param_2,5,uVar2);

    puVar6 = &DAT_14037f8e0;

    lVar4 = 4;

    puVar3 = (undefined2 *)(param_3 + 5);

    lVar5 = param_1 + 0x62;

    do {

      FUN_140279910(*(undefined8 *)(param_1 + 0x10),param_2,lVar5,*puVar6,*puVar3);

      lVar5 = lVar5 + 8;

      puVar3 = puVar3 + 1;

      puVar6 = puVar6 + 1;

      lVar4 = lVar4 + -1;

    } while (lVar4 != 0);

    FUN_140279e90(param_2,*(undefined1 *)(param_3 + 0xf));

    return;

  }

  return;

}




