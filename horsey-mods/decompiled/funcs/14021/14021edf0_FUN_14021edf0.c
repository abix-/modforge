// Address: 0x14021edf0
// Ghidra name: FUN_14021edf0
// ============ 0x14021edf0 FUN_14021edf0 (size=62) ============


undefined1 FUN_14021edf0(undefined8 *param_1)



{

  char cVar1;

  

  if (param_1 != (undefined8 *)0x0) {

    cVar1 = FUN_140179b50(*param_1);

    if (cVar1 == '\0') {

      return 0;

    }

    FUN_140138fb0(param_1 + 3,1);

    FUN_140179b60(*param_1);

  }

  return 1;

}




