// Address: 0x140207fa0
// Ghidra name: FUN_140207fa0
// ============ 0x140207fa0 FUN_140207fa0 (size=209) ============


undefined4

FUN_140207fa0(undefined2 param_1,undefined2 param_2,undefined2 param_3,undefined8 param_4)



{

  char cVar1;

  undefined4 uVar2;

  undefined **ppuVar3;

  uint uVar4;

  

  uVar2 = FUN_140208c00(param_4,param_1,param_2,0xffffffff,0,0,0);

  ppuVar3 = &PTR_PTR_1403e4d40;

  uVar4 = 0;

  do {

    if ((*ppuVar3)[8] != '\0') {

      cVar1 = (**(code **)(*ppuVar3 + 0x28))

                        (0,param_4,uVar2,param_1,param_2,param_3,0xffffffff,0,0,0);

      if (cVar1 != '\0') {

        return 1;

      }

    }

    uVar4 = uVar4 + 1;

    ppuVar3 = ppuVar3 + 1;

  } while (uVar4 < 0x1a);

  return 0;

}




