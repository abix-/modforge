// Address: 0x1402f4a28
// Ghidra name: FUN_1402f4a28
// ============ 0x1402f4a28 FUN_1402f4a28 (size=126) ============


/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */



undefined8 FUN_1402f4a28(undefined8 *param_1,undefined8 *param_2)



{

  undefined8 *puVar1;

  char cVar2;

  undefined8 *puVar3;

  

  puVar3 = param_1;

  if (param_1 != param_2) {

    do {

      if (((code *)*puVar3 != (code *)0x0) && (cVar2 = (*(code *)*puVar3)(), cVar2 == '\0')) break;

      puVar3 = puVar3 + 2;

    } while (puVar3 != param_2);

    if (puVar3 != param_2) {

      if (puVar3 != param_1) {

        puVar3 = puVar3 + -1;

        do {

          if ((puVar3[-1] != 0) && ((code *)*puVar3 != (code *)0x0)) {

            (*(code *)*puVar3)(0);

          }

          puVar1 = puVar3 + -1;

          puVar3 = puVar3 + -2;

        } while (puVar1 != param_1);

      }

      return 0;

    }

  }

  return 1;

}




