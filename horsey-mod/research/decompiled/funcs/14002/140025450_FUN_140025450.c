// Address: 0x140025450
// Ghidra name: FUN_140025450
// ============ 0x140025450 FUN_140025450 (size=62) ============


undefined8 FUN_140025450(longlong param_1)



{

  longlong *plVar1;

  longlong lVar2;

  undefined8 uVar3;

  

  plVar1 = *(longlong **)(param_1 + 0x60);

  while( true ) {

    if (plVar1 == (longlong *)0x0) {

      return 0;

    }

    lVar2 = (**(code **)(*plVar1 + 0x30))(plVar1);

    if (lVar2 != 0) break;

    plVar1 = (longlong *)plVar1[0xc];

  }

                    /* WARNING: Could not recover jumptable at 0x00014002548a. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  uVar3 = (**(code **)(*plVar1 + 0x30))(plVar1);

  return uVar3;

}




