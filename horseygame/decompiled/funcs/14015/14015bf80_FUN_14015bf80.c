// Address: 0x14015bf80
// Ghidra name: FUN_14015bf80
// ============ 0x14015bf80 FUN_14015bf80 (size=62) ============


void FUN_14015bf80(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)



{

  undefined8 uVar1;

  

  uVar1 = 0;

  if (*(char *)(param_1 + 0x40) != '\0') {

    if (*(longlong *)(param_1 + 0x18) != 0) {

      uVar1 = FUN_140142960();

    }

    FUN_140159c80(param_1,param_4,uVar1);

  }

  return;

}




