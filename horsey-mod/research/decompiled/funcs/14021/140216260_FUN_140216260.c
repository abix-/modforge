// Address: 0x140216260
// Ghidra name: FUN_140216260
// ============ 0x140216260 FUN_140216260 (size=407) ============


undefined8 FUN_140216260(longlong param_1)



{

  longlong *plVar1;

  int iVar2;

  uint local_res8 [2];

  undefined4 local_res18 [2];

  undefined4 local_res20 [2];

  

  local_res8[0] = 0;

  local_res18[0] = 0;

  *(undefined8 *)(*(longlong *)(param_1 + 200) + 0x28) = 0;

  plVar1 = *(longlong **)(*(longlong *)(param_1 + 200) + 8);

  iVar2 = (**(code **)(*plVar1 + 0x20))(plVar1,local_res18,local_res8);

  if (iVar2 == -0x7787ff6a) {

    (**(code **)(**(longlong **)(*(longlong *)(param_1 + 200) + 8) + 0xa0))();

    plVar1 = *(longlong **)(*(longlong *)(param_1 + 200) + 8);

    iVar2 = (**(code **)(*plVar1 + 0x20))(plVar1,local_res18,local_res8);

  }

  if (iVar2 != 0) {

    FUN_140216c30("DirectSound GetCurrentPosition",iVar2);

    return 0;

  }

  local_res8[0] = local_res8[0] / *(uint *)(param_1 + 0x6c);

  *(uint *)(*(longlong *)(param_1 + 200) + 0x24) = local_res8[0];

  local_res20[0] = 0;

  local_res8[0] =

       ((local_res8[0] + 1) % *(uint *)(*(longlong *)(param_1 + 200) + 0x20)) *

       *(int *)(param_1 + 0x6c);

  iVar2 = (**(code **)(**(longlong **)(*(longlong *)(param_1 + 200) + 8) + 0x58))();

  if (iVar2 == -0x7787ff6a) {

    (**(code **)(**(longlong **)(*(longlong *)(param_1 + 200) + 8) + 0xa0))();

    plVar1 = *(longlong **)(*(longlong *)(param_1 + 200) + 8);

    iVar2 = (**(code **)(*plVar1 + 0x58))

                      (plVar1,local_res8[0],*(undefined4 *)(param_1 + 0x6c),

                       *(longlong *)(param_1 + 200) + 0x28,local_res20,0,local_res18,0);

  }

  if (iVar2 != 0) {

    FUN_140216c30("DirectSound Lock",iVar2);

    return 0;

  }

  return *(undefined8 *)(*(longlong *)(param_1 + 200) + 0x28);

}




