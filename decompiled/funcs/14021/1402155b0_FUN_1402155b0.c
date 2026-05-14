// Address: 0x1402155b0
// Ghidra name: FUN_1402155b0
// ============ 0x1402155b0 FUN_1402155b0 (size=278) ============


undefined8 FUN_1402155b0(longlong param_1)



{

  longlong *plVar1;

  HANDLE hHandle;

  char cVar2;

  undefined4 uVar3;

  DWORD DVar4;

  uint local_res10 [6];

  

  cVar2 = FUN_140214d50();

  do {

    if (cVar2 == '\0') {

      return 1;

    }

    plVar1 = *(longlong **)(*(longlong *)(param_1 + 200) + 0x10);

    if (plVar1 == (longlong *)0x0) {

      return 1;

    }

    hHandle = *(HANDLE *)(*(longlong *)(param_1 + 200) + 0x28);

    if (hHandle == (HANDLE)0x0) {

      return 1;

    }

    if (*(char *)(param_1 + 0x94) == '\0') {

      DVar4 = WaitForSingleObjectEx(hHandle,200,0);

      if (DVar4 != 0) goto LAB_140215639;

      local_res10[0] = 0;

      plVar1 = *(longlong **)(*(longlong *)(param_1 + 200) + 0x10);

      uVar3 = (**(code **)(*plVar1 + 0x30))(plVar1,local_res10);

      cVar2 = FUN_1402156d0(param_1,uVar3);

      if ((cVar2 == '\0') && (local_res10[0] <= *(uint *)(param_1 + 0x84))) {

        return 1;

      }

    }

    else {

      local_res10[0] = 0;

      uVar3 = (**(code **)(*plVar1 + 0x30))(plVar1,local_res10);

      cVar2 = FUN_1402156d0(param_1,uVar3);

      if ((cVar2 == '\0') && (local_res10[0] != 0)) {

        return 1;

      }

      DVar4 = WaitForSingleObjectEx(*(HANDLE *)(*(longlong *)(param_1 + 200) + 0x28),200,0);

      if (DVar4 != 0) {

LAB_140215639:

        if (DVar4 != 0x102) {

          (**(code **)(**(longlong **)(*(longlong *)(param_1 + 200) + 0x10) + 0x58))();

          return 0;

        }

      }

    }

    cVar2 = FUN_140214d50(param_1);

  } while( true );

}




