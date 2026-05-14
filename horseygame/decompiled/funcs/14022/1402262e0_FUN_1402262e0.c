// Address: 0x1402262e0
// Ghidra name: FUN_1402262e0
// ============ 0x1402262e0 FUN_1402262e0 (size=120) ============


undefined8 FUN_1402262e0(undefined8 param_1,longlong param_2,int *param_3)



{

  BOOL BVar1;

  undefined8 uVar2;

  tagMONITORINFO local_38;

  

  local_38.rcMonitor.top = 0;

  local_38.rcMonitor.right = 0;

  local_38.cbSize = 0x28;

  local_38.rcMonitor.left = 0;

  local_38.rcMonitor.bottom = 0;

  local_38.rcWork.left = 0;

  local_38.rcWork.top = 0;

  local_38.rcWork.right = 0;

  local_38.rcWork.bottom = 0;

  local_38.dwFlags = 0;

  BVar1 = GetMonitorInfoW(*(HMONITOR *)(*(longlong *)(param_2 + 0x80) + 0x40),&local_38);

  if (BVar1 == 0) {

    uVar2 = FUN_14012e850("Couldn\'t find monitor data");

    return uVar2;

  }

  *param_3 = local_38.rcMonitor.left;

  param_3[2] = local_38.rcMonitor.right - local_38.rcMonitor.left;

  param_3[1] = local_38.rcMonitor.top;

  param_3[3] = local_38.rcMonitor.bottom - local_38.rcMonitor.top;

  return CONCAT71((uint7)(uint3)((uint)(local_38.rcMonitor.bottom - local_38.rcMonitor.top) >> 8),1)

  ;

}




