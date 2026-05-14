// Address: 0x14017f240
// Ghidra name: FUN_14017f240
// ============ 0x14017f240 FUN_14017f240 (size=87) ============


void FUN_14017f240(undefined8 param_1,undefined8 param_2,longlong param_3)



{

  char *pcVar1;

  

  pcVar1 = "times";

  if (*(int *)(param_3 + 4) == 1) {

    pcVar1 = "time";

  }

  FUN_14012ef10(param_1,param_2,"Assertion failure at %s (%s:%d), triggered %u %s:\r\n  \'%s\'",

                *(undefined8 *)(param_3 + 0x20),*(undefined8 *)(param_3 + 0x10),

                *(undefined4 *)(param_3 + 0x18),*(int *)(param_3 + 4),pcVar1,

                *(undefined8 *)(param_3 + 8));

  return;

}




