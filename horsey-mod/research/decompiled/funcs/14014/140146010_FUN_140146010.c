// Address: 0x140146010
// Ghidra name: FUN_140146010
// ============ 0x140146010 FUN_140146010 (size=169) ============


void FUN_140146010(uint *param_1)



{

  uint uVar1;

  char cVar2;

  

  cVar2 = FUN_1401489c0();

  if (((cVar2 != '\0') && ((param_1[0xc] & 1) == 0)) &&

     (param_1[8] = param_1[8] - 1, (int)param_1[8] < 1)) {

    FUN_140147e50(param_1);

    FUN_1401747e0(param_1[0xd]);

    FUN_14017ba60(param_1 + 0x1e);

    uVar1 = param_1[0x18];

    while (0 < (int)uVar1) {

      FUN_1401489e0(param_1);

      uVar1 = param_1[0x18];

    }

    if ((param_1[0xc] & 4) != 0) {

      FUN_1401d2c00(param_1);

    }

    FUN_1401487f0(param_1,0);

    if ((*param_1 & 1) == 0) {

      if ((*param_1 & 8) == 0) {

        FUN_1401841e0(*(undefined8 *)(param_1 + 6));

      }

      else {

        FUN_140190140();

      }

    }

    param_1[10] = 0;

    param_1[0xb] = 0;

    if ((param_1[0xc] & 2) == 0) {

      FUN_1401841e0(param_1);

      return;

    }

  }

  return;

}




