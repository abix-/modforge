// Address: 0x1402746d0
// Ghidra name: FUN_1402746d0
// ============ 0x1402746d0 FUN_1402746d0 (size=180) ============


undefined8 FUN_1402746d0(longlong param_1,longlong param_2)



{

  short sVar1;

  longlong lVar2;

  undefined8 uVar3;

  

  lVar2 = *(longlong *)(param_1 + 0x70);

  _guard_check_icall();

  *(undefined4 *)(lVar2 + 0x10) = 0;

  *(undefined8 *)(lVar2 + 0x18) = 0;

  *(undefined8 *)(lVar2 + 0x20) = 0;

  *(undefined8 *)(lVar2 + 0x28) = 0;

  *(undefined8 *)(lVar2 + 0x30) = 0;

  *(undefined8 *)(lVar2 + 0x38) = 0;

  *(undefined8 *)(lVar2 + 0x40) = 0;

  *(undefined8 *)(lVar2 + 0x48) = 0;

  *(undefined8 *)(lVar2 + 0x50) = 0;

  *(undefined8 *)(lVar2 + 0x58) = 0;

  sVar1 = *(short *)(param_1 + 0x22);

  *(undefined4 *)(param_2 + 0x44) = 6;

  *(undefined4 *)(param_2 + 0x60) = 1;

  if (sVar1 == 0x7210) {

    *(undefined4 *)(param_2 + 0x70) = 0xf;

    FUN_14015a220(param_2,1);

  }

  else {

    *(undefined4 *)(param_2 + 0x70) = 0xc;

  }

  uVar3 = FUN_140149350();

  *(undefined8 *)(lVar2 + 8) = uVar3;

  FUN_140275130(param_1,0x3a,0,0);

  FUN_140275130(param_1,7,0,0);

  return 1;

}




