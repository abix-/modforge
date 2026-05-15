// Address: 0x14015f4a0
// Ghidra name: FUN_14015f4a0
// ============ 0x14015f4a0 FUN_14015f4a0 (size=373) ============


void FUN_14015f4a0(void)



{

  longlong lVar1;

  longlong lVar2;

  undefined8 uVar3;

  undefined8 uVar4;

  char cVar5;

  

  if (DAT_1403fc0a0 == 0) {

    return;

  }

  (*DAT_1403fc110)();

  lVar2 = DAT_1403fc140;

  while (lVar2 != 0) {

    lVar1 = *(longlong *)(lVar2 + 0xe0);

    if ((*(char *)(lVar2 + 0xb8) == '\0') &&

       (cVar5 = FUN_1401749e0(*(undefined4 *)(lVar2 + 8),"SDL.audiostream.auto_cleanup",1),

       cVar5 == '\0')) {

      *(undefined8 *)(lVar2 + 0xd8) = 0;

      *(undefined8 *)(lVar2 + 0xe0) = 0;

      lVar2 = lVar1;

    }

    else {

      FUN_1401676f0(lVar2);

      lVar2 = lVar1;

    }

  }

  FUN_14017cab0(DAT_1403fc128);

  FUN_140139010(&DAT_1403fc170,1);

  lVar2 = DAT_1403fc158;

  uVar4 = DAT_1403fc138;

  uVar3 = DAT_1403fc130;

  DAT_1403fc138 = 0;

  DAT_1403fc130 = 0;

  DAT_1403fc158 = 0;

  FUN_140139010(&DAT_1403fc168,0);

  FUN_140139010(&DAT_1403fc16c,0);

  FUN_14017cae0(DAT_1403fc128);

  while (lVar2 != 0) {

    lVar1 = *(longlong *)(lVar2 + 8);

    FUN_1401841e0(lVar2);

    lVar2 = lVar1;

  }

  FUN_1401ab210(uVar3,FUN_14015c8b0,0);

  (*DAT_1403fc118)();

  FUN_14017ca90(DAT_1403fc128);

  FUN_1401aafa0(uVar3);

  FUN_1401aafa0(uVar4);

  FUN_1402f94c0(&DAT_1403fc0a0,0,0xd8);

  return;

}




