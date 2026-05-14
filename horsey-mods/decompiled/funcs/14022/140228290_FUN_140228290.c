// Address: 0x140228290
// Ghidra name: FUN_140228290
// ============ 0x140228290 FUN_140228290 (size=239) ============


uint FUN_140228290(float *param_1,float *param_2)



{

  ushort uVar1;

  ushort uVar2;

  ushort uVar3;

  ushort uVar4;

  ushort uVar5;

  int iVar6;

  tagPOINT local_res8;

  

  local_res8.x = 0;

  local_res8.y = 0;

  iVar6 = GetSystemMetrics(0x17);

  GetCursorPos(&local_res8);

  *param_1 = (float)local_res8.x;

  *param_2 = (float)local_res8.y;

  uVar1 = GetAsyncKeyState((iVar6 != 0) + 1);

  uVar2 = GetAsyncKeyState(2 - (uint)(iVar6 != 0));

  uVar3 = GetAsyncKeyState(4);

  uVar4 = GetAsyncKeyState(5);

  uVar5 = GetAsyncKeyState(6);

  return (uVar5 & 0x8000) >> 0xb | (uint)((uVar1 & 0x8000) != 0) |

         -(uint)((uVar4 & 0x8000) != 0) & 8 | -(uint)((uVar3 & 0x8000) != 0) & 2 |

         -(uint)((uVar2 & 0x8000) != 0) & 4;

}




