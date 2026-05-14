// Address: 0x1401aca90
// Ghidra name: FUN_1401aca90
// ============ 0x1401aca90 FUN_1401aca90 (size=181) ============


undefined8 FUN_1401aca90(longlong param_1)



{

  longlong *plVar1;

  int iVar2;

  uint local_res8 [2];

  longlong local_res10;

  

  plVar1 = (longlong *)**(undefined8 **)(param_1 + 0x1d0);

  local_res10 = 0;

  iVar2 = FUN_140138fe0(param_1 + 0x1b8);

  while (iVar2 == 0) {

    local_res8[0] = 0;

    iVar2 = (**(code **)(*plVar1 + 0x48))(plVar1,0xfffffffc,0,0,local_res8,0,&local_res10);

    if (iVar2 < 0) {

      return 0;

    }

    if (local_res10 != 0) break;

    if ((local_res8[0] & 3) != 0) {

      return 0;

    }

    iVar2 = FUN_140138fe0(param_1 + 0x1b8);

  }

  *(longlong *)(*(longlong *)(param_1 + 0x1d0) + 8) = local_res10;

  return 1;

}




