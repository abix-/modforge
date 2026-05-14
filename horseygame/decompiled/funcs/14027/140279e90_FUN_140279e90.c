// Address: 0x140279e90
// Ghidra name: FUN_140279e90
// ============ 0x140279e90 FUN_140279e90 (size=183) ============


void FUN_140279e90(longlong param_1,byte param_2)



{

  byte bVar1;

  undefined8 uVar2;

  byte bVar3;

  undefined8 uVar4;

  

  bVar3 = param_2 >> 4;

  bVar1 = ~(param_2 >> 2) & 1;

  _guard_check_icall();

  *(uint *)(param_1 + 0xe4) = (bVar1 ^ 1) + 1;

  if ((~(param_2 >> 3) & 1) == 0) {

    uVar2 = 1;

    if (bVar1 != 0) {

      uVar2 = 4;

    }

  }

  else {

    uVar2 = 3;

  }

  if (bVar3 < 4) {

    if (bVar3 == 3) {

      uVar4 = 0x46;

    }

    else if (bVar3 == 2) {

      uVar4 = 0x28;

    }

    else {

      uVar4 = 3;

      if (bVar3 == 1) {

        uVar4 = 10;

      }

    }

  }

  else {

    uVar4 = 100;

  }

  FUN_14015af40(param_1,uVar2,uVar4);

  return;

}




