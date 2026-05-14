// Address: 0x1402150d0
// Ghidra name: FUN_1402150d0
// ============ 0x1402150d0 FUN_1402150d0 (size=131) ============


undefined8 FUN_1402150d0(longlong param_1,undefined4 *param_2)



{

  longlong *plVar1;

  char cVar2;

  int iVar3;

  undefined8 local_res8;

  

  local_res8 = 0;

  plVar1 = *(longlong **)(*(longlong *)(param_1 + 200) + 0x18);

  if (plVar1 == (longlong *)0x0) {

    return 0;

  }

  iVar3 = (**(code **)(*plVar1 + 0x18))(plVar1,*(undefined4 *)(param_1 + 0x84),&local_res8);

  if (iVar3 != -0x7776fffa) {

    cVar2 = FUN_1402156d0(param_1,iVar3);

    if (cVar2 == '\0') {

      return local_res8;

    }

    if (*(char *)(*(longlong *)(param_1 + 200) + 0x44) == '\0') {

      return local_res8;

    }

  }

  *param_2 = 0;

  return local_res8;

}




