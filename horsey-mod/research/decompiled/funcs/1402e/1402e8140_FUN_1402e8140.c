// Address: 0x1402e8140
// Ghidra name: FUN_1402e8140
// ============ 0x1402e8140 FUN_1402e8140 (size=43) ============


uint FUN_1402e8140(uint param_1)



{

  uint uVar1;

  uint uVar2;

  undefined4 *puVar3;

  

  if (param_1 < 2) {

    LOCK();

    UNLOCK();

    uVar1 = param_1;

    uVar2 = DAT_1403ff140;

  }

  else {

    puVar3 = (undefined4 *)FUN_1402e68b0();

    *puVar3 = 0x16;

    FUN_1402cd454();

    uVar1 = DAT_1403ff140;

    uVar2 = 0xffffffff;

  }

  DAT_1403ff140 = uVar1;

  return uVar2;

}




