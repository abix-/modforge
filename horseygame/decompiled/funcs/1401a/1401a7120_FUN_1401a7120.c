// Address: 0x1401a7120
// Ghidra name: FUN_1401a7120
// ============ 0x1401a7120 FUN_1401a7120 (size=165) ============


undefined8 FUN_1401a7120(undefined8 param_1,int param_2,ulonglong *param_3)



{

  ulonglong uVar1;

  undefined8 uVar2;

  ulonglong uVar3;

  ulonglong uVar4;

  

  uVar3 = param_3[1];

  uVar4 = *param_3 + (longlong)param_2;

  if (uVar3 < uVar4) {

    if ((int)param_3[3] != 0) {

      do {

        uVar3 = uVar3 * 2;

        if (uVar3 < 0x80) {

          uVar3 = 0x80;

        }

      } while (uVar3 < uVar4);

      uVar1 = FUN_140184230(param_3[2],uVar3);

      if (uVar1 != 0) {

        param_3[2] = uVar1;

        param_3[1] = uVar3;

        goto LAB_1401a718c;

      }

    }

    uVar2 = 0;

  }

  else {

LAB_1401a718c:

    FUN_1402f8e20(*param_3 + param_3[2],param_1,(longlong)param_2);

    uVar2 = 1;

    *param_3 = uVar4;

  }

  return uVar2;

}




