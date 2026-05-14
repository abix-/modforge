// Address: 0x1400265a0
// Ghidra name: FUN_1400265a0
// ============ 0x1400265a0 FUN_1400265a0 (size=104) ============


void FUN_1400265a0(longlong param_1,longlong *param_2)



{

  longlong *plVar1;

  char cVar2;

  

  cVar2 = (**(code **)(*param_2 + 0x10))(param_2,param_1);

  if (cVar2 != '\0') {

    plVar1 = *(longlong **)(param_1 + 0x28);

    while ((plVar1 != (longlong *)0x0 &&

           (cVar2 = (**(code **)(*plVar1 + 0x80))(plVar1,param_2), cVar2 != '\0'))) {

      plVar1 = (longlong *)plVar1[0xc];

    }

  }

                    /* WARNING: Could not recover jumptable at 0x000140026604. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  (**(code **)(*param_2 + 0x20))(param_2,param_1);

  return;

}




