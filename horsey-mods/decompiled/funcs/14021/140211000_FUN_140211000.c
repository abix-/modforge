// Address: 0x140211000
// Ghidra name: FUN_140211000
// ============ 0x140211000 FUN_140211000 (size=389) ============


undefined4 FUN_140211000(int param_1,uint param_2)



{

  int iVar1;

  uint uVar2;

  longlong lVar3;

  uint *puVar4;

  

  lVar3 = FUN_140210ef0();

  if (lVar3 == 0) {

    puVar4 = &DAT_140350d60;

    uVar2 = 0;

    do {

      if ((param_1 << 0x10 | param_2) == *puVar4) {

        return *(undefined4 *)(&DAT_140350d64 + (longlong)(int)uVar2 * 0x10);

      }

      uVar2 = uVar2 + 1;

      puVar4 = puVar4 + 4;

    } while (uVar2 < 0x238);

  }

  else {

    iVar1 = FUN_14012f260(lVar3,"Xbox360",7);

    if (iVar1 == 0) {

      return 0x1f;

    }

    iVar1 = FUN_14012f260(lVar3,"XboxOne",7);

    if (iVar1 == 0) {

      return 0x20;

    }

    iVar1 = FUN_14012f260(lVar3,&DAT_1403538c8,3);

    if (iVar1 == 0) {

      return 0x21;

    }

    iVar1 = FUN_14012f260(lVar3,&DAT_1403538cc,3);

    if (iVar1 == 0) {

      return 0x22;

    }

    iVar1 = FUN_14012f260(lVar3,&DAT_1403538d0,3);

    if (iVar1 == 0) {

      return 0x2d;

    }

    iVar1 = FUN_14012f260(lVar3,"SwitchPro",9);

    if (iVar1 == 0) {

      return 0x26;

    }

    iVar1 = FUN_14012f260(lVar3,"Steam",5);

    if (iVar1 == 0) {

      return 2;

    }

  }

  return 0x1e;

}




