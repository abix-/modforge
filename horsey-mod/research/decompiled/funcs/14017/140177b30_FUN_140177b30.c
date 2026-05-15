// Address: 0x140177b30
// Ghidra name: FUN_140177b30
// ============ 0x140177b30 FUN_140177b30 (size=64) ============


undefined8 FUN_140177b30(undefined8 param_1,undefined8 param_2,undefined8 *param_3)



{

  char cVar1;

  undefined1 local_38 [8];

  undefined8 local_30;

  

  cVar1 = FUN_140177b70(param_1,param_2,local_38);

  if (cVar1 != '\0') {

    if (param_3 != (undefined8 *)0x0) {

      *param_3 = local_30;

    }

    return 1;

  }

  if (param_3 != (undefined8 *)0x0) {

    *param_3 = 0;

  }

  return 0;

}




