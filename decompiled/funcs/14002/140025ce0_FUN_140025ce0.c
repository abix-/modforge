// Address: 0x140025ce0
// Ghidra name: FUN_140025ce0
// ============ 0x140025ce0 FUN_140025ce0 (size=120) ============


void FUN_140025ce0(longlong param_1,longlong *param_2)



{

  longlong *plVar1;

  char cVar2;

  longlong lVar3;

  

  lVar3 = *(longlong *)(param_1 + 0xd0);

  if (*(longlong *)(param_1 + 0xd0) == param_1 + 0x68) {

    lVar3 = 0;

  }

  cVar2 = (**(code **)(*param_2 + 8))(param_2,param_1,lVar3);

  if (cVar2 != '\0') {

    plVar1 = *(longlong **)(param_1 + 0x28);

    while ((plVar1 != (longlong *)0x0 &&

           (cVar2 = (**(code **)(*plVar1 + 0x80))(plVar1,param_2), cVar2 != '\0'))) {

      plVar1 = (longlong *)plVar1[0xc];

    }

  }

                    /* WARNING: Could not recover jumptable at 0x000140025d54. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  (**(code **)(*param_2 + 0x18))(param_2,param_1);

  return;

}




