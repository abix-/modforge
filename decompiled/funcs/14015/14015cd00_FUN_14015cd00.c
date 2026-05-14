// Address: 0x14015cd00
// Ghidra name: FUN_14015cd00
// ============ 0x14015cd00 FUN_14015cd00 (size=222) ============


longlong FUN_14015cd00(uint param_1)



{

  longlong lVar1;

  uint uVar2;

  uint uVar3;

  

  uVar2 = param_1;

  if (param_1 < 0xfffffffe) {

    lVar1 = FUN_14015cc50();

    return lVar1;

  }

  while( true ) {

    FUN_14017caa0(DAT_1403fc128);

    uVar3 = DAT_1403fc148;

    if ((param_1 != 0xffffffff) && (uVar3 = uVar2, param_1 == 0xfffffffe)) {

      uVar3 = DAT_1403fc14c;

    }

    FUN_14017cae0(DAT_1403fc128);

    if (uVar3 == 0) {

      FUN_14012e850("No default audio device available");

      return 0;

    }

    lVar1 = FUN_14015cc50(uVar3);

    if (lVar1 == 0) {

      return 0;

    }

    FUN_14017caa0(DAT_1403fc128);

    uVar2 = DAT_1403fc148;

    if (((param_1 == 0xffffffff) || (uVar2 = DAT_1403fc14c, param_1 == 0xfffffffe)) &&

       (uVar3 == uVar2)) break;

    FUN_14017cae0(DAT_1403fc128);

    FUN_14015d3e0(lVar1);

    uVar2 = uVar3;

  }

  FUN_14017cae0(DAT_1403fc128);

  return lVar1;

}




