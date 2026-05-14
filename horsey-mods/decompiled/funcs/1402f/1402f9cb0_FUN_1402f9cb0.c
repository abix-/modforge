// Address: 0x1402f9cb0
// Ghidra name: FUN_1402f9cb0
// ============ 0x1402f9cb0 FUN_1402f9cb0 (size=89) ============


undefined8 FUN_1402f9cb0(undefined8 param_1,longlong param_2)



{

  longlong *plVar1;

  uint uVar2;

  longlong lVar3;

  

  plVar1 = *(longlong **)(param_2 + 0x80);

  lVar3 = (longlong)*(int *)(*plVar1 + 4);

  uVar2 = *(uint *)(lVar3 + 0x10 + (longlong)plVar1) & 0x13 | 4;

  *(uint *)(lVar3 + 0x10 + (longlong)plVar1) = uVar2;

  if ((*(uint *)(lVar3 + 0x14 + (longlong)plVar1) & uVar2) != 0) {

                    /* WARNING: Subroutine does not return */

    FUN_1402c8240(0,0);

  }

  return 0;

}




