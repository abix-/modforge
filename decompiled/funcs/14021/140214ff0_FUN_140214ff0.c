// Address: 0x140214ff0
// Ghidra name: FUN_140214ff0
// ============ 0x140214ff0 FUN_140214ff0 (size=183) ============


void FUN_140214ff0(longlong param_1)



{

  longlong *plVar1;

  char cVar2;

  int iVar3;

  undefined4 uVar4;

  undefined4 local_res8 [2];

  undefined4 local_res10 [2];

  undefined8 local_res18 [2];

  

  local_res18[0] = 0;

  local_res8[0] = 0;

  local_res10[0] = 0;

  iVar3 = FUN_140138fe0(param_1 + 0x8c);

  while ((((iVar3 == 0 &&

           (plVar1 = *(longlong **)(*(longlong *)(param_1 + 200) + 0x20), plVar1 != (longlong *)0x0)

           ) && (iVar3 = (**(code **)(*plVar1 + 0x18))

                                   (plVar1,local_res18,local_res8,local_res10,0,0),

                iVar3 != 0x8890001)) && (cVar2 = FUN_1402156d0(param_1,iVar3), cVar2 == '\0'))) {

    plVar1 = *(longlong **)(*(longlong *)(param_1 + 200) + 0x20);

    uVar4 = (**(code **)(*plVar1 + 0x20))(plVar1,local_res8[0]);

    cVar2 = FUN_1402156d0(param_1,uVar4);

    if (cVar2 != '\0') {

      return;

    }

    iVar3 = FUN_140138fe0(param_1 + 0x8c);

  }

  return;

}




