// Address: 0x14021e5d0
// Ghidra name: FUN_14021e5d0
// ============ 0x14021e5d0 FUN_14021e5d0 (size=318) ============


undefined4 FUN_14021e5d0(undefined8 param_1,undefined8 param_2,LPHANDLE param_3)



{

  undefined4 uVar1;

  BOOL BVar2;

  DWORD DVar3;

  longlong lVar4;

  HANDLE hSourceHandle;

  HANDLE hTargetProcessHandle;

  HANDLE hSourceProcessHandle;

  DWORD local_res20 [2];

  

  lVar4 = FUN_140174d30(param_1,param_2,0);

  if (lVar4 == 0) {

    FUN_14012e850("%s is not set",param_2);

    return 0;

  }

  uVar1 = FUN_14012be20(lVar4);

  hSourceHandle = (HANDLE)FUN_140174d30(uVar1,"SDL.iostream.windows.handle",0xffffffffffffffff);

  if (hSourceHandle == (HANDLE)0xffffffffffffffff) {

    FUN_14012e850("%s doesn\'t have SDL_PROP_IOSTREAM_WINDOWS_HANDLE_POINTER available",param_2);

    return 0;

  }

  hTargetProcessHandle = GetCurrentProcess();

  hSourceProcessHandle = GetCurrentProcess();

  BVar2 = DuplicateHandle(hSourceProcessHandle,hSourceHandle,hTargetProcessHandle,param_3,0,1,2);

  if (BVar2 == 0) {

    FUN_1401a9ed0("DuplicateHandle()");

    return 0;

  }

  DVar3 = GetFileType(*param_3);

  if (DVar3 == 3) {

    local_res20[0] = 0;

    BVar2 = SetNamedPipeHandleState(*param_3,local_res20,(LPDWORD)0x0,(LPDWORD)0x0);

    if (BVar2 == 0) {

      FUN_1401a9ed0("SetNamedPipeHandleState()");

      return 0;

    }

  }

  return 1;

}




