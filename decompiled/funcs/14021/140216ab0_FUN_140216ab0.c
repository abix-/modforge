// Address: 0x140216ab0
// Ghidra name: FUN_140216ab0
// ============ 0x140216ab0 FUN_140216ab0 (size=152) ============


undefined8 FUN_140216ab0(longlong param_1)



{

  longlong lVar1;

  longlong *plVar2;

  int iVar3;

  uint local_res8 [2];

  undefined1 local_res10 [8];

  

  lVar1 = *(longlong *)(param_1 + 200);

  iVar3 = FUN_140138fe0(param_1 + 0x8c);

  while( true ) {

    if (iVar3 != 0) {

      return 1;

    }

    plVar2 = *(longlong **)(lVar1 + 0x18);

    iVar3 = (**(code **)(*plVar2 + 0x20))(plVar2,local_res10,local_res8);

    if (iVar3 != 0) break;

    if (local_res8[0] / *(uint *)(param_1 + 0x6c) != *(uint *)(lVar1 + 0x24)) {

      return 1;

    }

    FUN_1401492f0(1,(ulonglong)local_res8[0] % (ulonglong)*(uint *)(param_1 + 0x6c));

    iVar3 = FUN_140138fe0(param_1 + 0x8c);

  }

  return 0;

}




