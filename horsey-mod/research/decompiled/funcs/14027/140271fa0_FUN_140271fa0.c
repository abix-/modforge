// Address: 0x140271fa0
// Ghidra name: FUN_140271fa0
// ============ 0x140271fa0 FUN_140271fa0 (size=164) ============


void FUN_140271fa0(longlong param_1,undefined8 param_2,undefined8 param_3,longlong param_4)



{

  uint uVar1;

  uint uVar2;

  

  uVar2 = 4;

  if (param_4 != 0) {

    uVar1 = thunk_FUN_1402d89dc(param_4);

    if (uVar1 != 1) {

      if ((uVar1 != 2) && (uVar1 != 4)) goto LAB_140271fd6;

    }

    uVar2 = uVar1;

  }

LAB_140271fd6:

  if (uVar2 != *(byte *)(param_1 + 0x23)) {

    *(char *)(param_1 + 0x23) = (char)uVar2;

    FUN_140271d80(param_1,0);

    FUN_140159d30();

    FUN_14015a600(*(undefined8 *)(param_1 + 8),2);

    FUN_14015a600(*(undefined8 *)(param_1 + 8),1);

    FUN_14015bb10();

  }

  return;

}




