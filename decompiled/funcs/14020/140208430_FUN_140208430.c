// Address: 0x140208430
// Ghidra name: FUN_140208430
// ============ 0x140208430 FUN_140208430 (size=85) ============


void FUN_140208430(longlong param_1,undefined2 param_2,undefined2 param_3)



{

  undefined8 uVar1;

  undefined8 *puVar2;

  undefined1 local_18 [16];

  

  puVar2 = (undefined8 *)

           FUN_140157780(local_18,*(undefined1 *)(param_1 + 0x30),param_2,param_3,

                         *(undefined2 *)(param_1 + 0x24),*(undefined8 *)(param_1 + 8),

                         *(undefined8 *)(param_1 + 0x10),0x68,0);

  uVar1 = puVar2[1];

  *(undefined8 *)(param_1 + 0x30) = *puVar2;

  *(undefined8 *)(param_1 + 0x38) = uVar1;

  return;

}




