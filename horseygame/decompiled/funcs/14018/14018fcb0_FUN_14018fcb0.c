// Address: 0x14018fcb0
// Ghidra name: FUN_14018fcb0
// ============ 0x14018fcb0 FUN_14018fcb0 (size=142) ============


ulonglong FUN_14018fcb0(undefined4 param_1,undefined8 param_2,undefined8 param_3)



{

  longlong lVar1;

  ulonglong uVar2;

  HANDLE hHeap;

  undefined4 local_res8 [2];

  undefined8 local_res10 [3];

  LPVOID local_18 [2];

  

  local_18[0] = (LPVOID)0x0;

  local_res8[0] = param_1;

  local_res10[0] = param_2;

  lVar1 = FUN_1401a93d0(local_res8,local_res10,local_18);

  if (lVar1 != 0) {

    FUN_140172ac0(0x10,"Fatal Error",lVar1,0);

    return 0xffffffff;

  }

  uVar2 = FUN_14021a760(local_res8[0],local_res10[0],param_3);

  if (local_18[0] != (LPVOID)0x0) {

    hHeap = GetProcessHeap();

    HeapFree(hHeap,0,local_18[0]);

    uVar2 = uVar2 & 0xffffffff;

  }

  return uVar2;

}




