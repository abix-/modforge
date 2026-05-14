// Address: 0x14017fb80
// Ghidra name: FUN_14017fb80
// ============ 0x14017fb80 FUN_14017fb80 (size=203) ============


/* WARNING: Removing unreachable block (ram,0x00014017fba5) */



undefined1 * FUN_14017fb80(void)



{

  longlong lVar1;

  undefined4 uVar2;

  undefined4 uVar3;

  uint uVar4;

  

  if (DAT_1403fc6b0 == 0) {

    FUN_14017f460();

    if (DAT_1403fc6a0 < 1) {

      uVar4 = (uint)DAT_1403fc6b0;

    }

    else {

      lVar1 = cpuid_basic_info(0);

      uVar4 = *(uint *)(lVar1 + 4);

      uVar2 = *(undefined4 *)(lVar1 + 8);

      uVar3 = *(undefined4 *)(lVar1 + 0xc);

      DAT_1403fc6b4 = (undefined1)uVar2;

      DAT_1403fc6b8 = (undefined1)uVar3;

      DAT_1403fc6b1 = (undefined1)(uVar4 >> 8);

      DAT_1403fc6b5 = (undefined1)((uint)uVar2 >> 8);

      DAT_1403fc6b9 = (undefined1)((uint)uVar3 >> 8);

      DAT_1403fc6b2 = (undefined1)(uVar4 >> 0x10);

      DAT_1403fc6b6 = (undefined1)((uint)uVar2 >> 0x10);

      DAT_1403fc6ba = (undefined1)((uint)uVar3 >> 0x10);

      DAT_1403fc6bb = (undefined1)((uint)uVar3 >> 0x18);

      DAT_1403fc6b0 = (byte)uVar4;

      DAT_1403fc6b3 = (undefined1)(uVar4 >> 0x18);

      DAT_1403fc6b7 = (undefined1)((uint)uVar2 >> 0x18);

    }

    if ((char)uVar4 == '\0') {

      FUN_14012f1a0(&DAT_1403fc6b0,"Unknown",0xd);

      return &DAT_1403fc6b0;

    }

  }

  return &DAT_1403fc6b0;

}




