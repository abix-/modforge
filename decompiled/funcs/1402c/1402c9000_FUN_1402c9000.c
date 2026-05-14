// Address: 0x1402c9000
// Ghidra name: FUN_1402c9000
// ============ 0x1402c9000 FUN_1402c9000 (size=114) ============


void FUN_1402c9000(int *param_1)



{

  byte *pbVar1;

  

  if (((((param_1 != (int *)0x0) && (*param_1 == -0x1f928c9d)) && (param_1[6] == 4)) &&

      ((param_1[8] == 0x19930520 || (param_1[8] + 0xe66cfadfU < 2)))) &&

     (pbVar1 = *(byte **)(param_1 + 0xc), pbVar1 != (byte *)0x0)) {

    if (*(int *)(pbVar1 + 4) == 0) {

      if (((*pbVar1 & 0x10) != 0) && (**(longlong **)(param_1 + 10) != 0)) {

        (*(code *)PTR__guard_dispatch_icall_140302c68)();

      }

    }

    else {

      FUN_1402c9074(*(undefined8 *)(param_1 + 10),

                    (longlong)*(int *)(pbVar1 + 4) + *(longlong *)(param_1 + 0xe));

    }

  }

  return;

}




