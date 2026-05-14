// Address: 0x1401599b0
// Ghidra name: FUN_1401599b0
// ============ 0x1401599b0 FUN_1401599b0 (size=152) ============


undefined8

FUN_1401599b0(undefined *param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4,

             undefined8 param_5)



{

  char cVar1;

  undefined **ppuVar2;

  undefined8 uVar3;

  uint uVar4;

  

  uVar3 = 0;

  FUN_140159d30();

  ppuVar2 = &PTR_PTR_1403e2380;

  uVar4 = 0;

  do {

    if (param_1 == *ppuVar2) break;

    cVar1 = (**(code **)(*ppuVar2 + 0x18))(param_2,param_3,param_4,param_5);

    if (cVar1 != '\0') {

      uVar3 = 1;

      break;

    }

    uVar4 = uVar4 + 1;

    ppuVar2 = ppuVar2 + 1;

  } while (uVar4 < 6);

  FUN_14015bb10();

  return uVar3;

}




