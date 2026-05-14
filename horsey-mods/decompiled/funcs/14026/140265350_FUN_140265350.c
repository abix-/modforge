// Address: 0x140265350
// Ghidra name: FUN_140265350
// ============ 0x140265350 FUN_140265350 (size=106) ============


undefined8 FUN_140265350(longlong *param_1)



{

  longlong lVar1;

  undefined8 uVar2;

  

  if ((int)param_1[7] != 0) {

    return 1;

  }

  if (*(char *)(*param_1 + 0x10) != '\0') {

    *(undefined4 *)(*param_1 + 0x14) = 10;

    *(undefined4 *)(param_1 + 7) = 3;

    lVar1 = FUN_140149350();

    param_1[8] = lVar1 + 500;

    *(undefined4 *)(param_1 + 9) = 0;

    uVar2 = FUN_140267e80(param_1,4,0,0,0);

    return uVar2;

  }

  uVar2 = FUN_140268010();

  return uVar2;

}




