// Address: 0x14013aac0
// Ghidra name: FUN_14013aac0
// ============ 0x14013aac0 FUN_14013aac0 (size=33) ============


longlong * FUN_14013aac0(longlong param_1,longlong param_2)



{

  longlong *plVar1;

  

  plVar1 = *(longlong **)(param_1 + 8);

  while( true ) {

    if (plVar1 == (longlong *)0x0) {

      return (longlong *)0x0;

    }

    if (param_2 == *plVar1) break;

    plVar1 = (longlong *)plVar1[1];

  }

  return plVar1;

}




