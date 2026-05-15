// Address: 0x1401984f0
// Ghidra name: FUN_1401984f0
// ============ 0x1401984f0 FUN_1401984f0 (size=188) ============


void FUN_1401984f0(longlong param_1)



{

  int iVar1;

  longlong *plVar2;

  undefined1 local_48 [64];

  

  if (param_1 != 0) {

    iVar1 = FUN_140138fe0(param_1 + 0x38);

    while (0 < iVar1) {

      plVar2 = (longlong *)(**(code **)(param_1 + 0x18))(*(undefined8 *)(param_1 + 0x30),0xffffffff)

      ;

      if (plVar2 != (longlong *)0x0) {

        if (*(char *)(*plVar2 + 200) != '\0') {

          FUN_1401841e0(plVar2[5]);

          plVar2[5] = 0;

        }

        FUN_140197e70(plVar2,local_48);

      }

      iVar1 = FUN_140138fe0(param_1 + 0x38);

    }

    (**(code **)(param_1 + 0x28))(*(undefined8 *)(param_1 + 0x30));

    FUN_1401841e0(param_1);

  }

  return;

}




