// Address: 0x14027bfb0
// Ghidra name: FUN_14027bfb0
// ============ 0x14027bfb0 FUN_14027bfb0 (size=80) ============


void FUN_14027bfb0(undefined8 param_1,uint param_2)



{

  uint uVar1;

  undefined8 uVar2;

  undefined8 uVar3;

  

  uVar3 = 0;

  uVar1 = param_2 & 3;

  if (uVar1 == 0) {

    uVar3 = 10;

  }

  else if (uVar1 == 1) {

    uVar3 = 0x28;

  }

  else if (uVar1 == 2) {

    uVar3 = 0x46;

  }

  else if (uVar1 == 3) {

    uVar3 = 100;

  }

  uVar2 = 3;

  if ((param_2 & 0xc) != 0) {

    uVar2 = 1;

  }

  FUN_14015af40(param_1,uVar2,uVar3);

  return;

}




