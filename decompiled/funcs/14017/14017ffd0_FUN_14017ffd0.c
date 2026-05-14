// Address: 0x14017ffd0
// Ghidra name: FUN_14017ffd0
// ============ 0x14017ffd0 FUN_14017ffd0 (size=125) ============


undefined8 FUN_14017ffd0(LPVOID param_1,code *param_2,undefined8 param_3)



{

  SIZE_T dwStackSize;

  HANDLE pvVar1;

  undefined8 uVar2;

  DWORD local_res8 [8];

  

  local_res8[0] = 0;

  dwStackSize = *(SIZE_T *)((longlong)param_1 + 0x48);

  *(undefined8 *)((longlong)param_1 + 0x70) = param_3;

  if (param_2 == (code *)0x0) {

    pvVar1 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,dwStackSize,

                          (LPTHREAD_START_ROUTINE)&LAB_14017ffa0,param_1,

                          -(uint)(dwStackSize != 0) & 0x10000,local_res8);

  }

  else {

    pvVar1 = (HANDLE)(*param_2)(0,dwStackSize,&LAB_14017ffa0);

  }

  *(HANDLE *)((longlong)param_1 + 8) = pvVar1;

  if (pvVar1 == (HANDLE)0x0) {

    uVar2 = FUN_14012e850("Not enough resources to create thread");

    return uVar2;

  }

  return 1;

}




