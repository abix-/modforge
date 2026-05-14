// Address: 0x1401cbd50
// Ghidra name: FUN_1401cbd50
// ============ 0x1401cbd50 FUN_1401cbd50 (size=120) ============


undefined8 FUN_1401cbd50(undefined8 param_1,longlong param_2,char param_3)



{

  longlong *plVar1;

  int iVar2;

  undefined8 local_res8;

  

  if (param_3 != '\0') {

    iVar2 = FUN_140138fe0(*(longlong *)(param_2 + 0x10) + 0x88);

    if (0 < iVar2) {

      FUN_1401c92f0(param_1,param_2);

    }

  }

  if (*(int *)(param_2 + 8) == 2) {

    return *(undefined8 *)(*(longlong *)(param_2 + 0x10) + 0x80);

  }

  plVar1 = *(longlong **)(*(longlong *)(param_2 + 0x10) + 0x10);

  (**(code **)(*plVar1 + 0x40))(plVar1,0,0,&local_res8);

  return local_res8;

}




