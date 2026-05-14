// Address: 0x14021ec30
// Ghidra name: FUN_14021ec30
// ============ 0x14021ec30 FUN_14021ec30 (size=102) ============


undefined8 FUN_14021ec30(HWND param_1,DWORD *param_2)



{

  BOOL BVar1;

  DWORD local_res10 [6];

  

  local_res10[0] = 0;

  GetWindowThreadProcessId(param_1,local_res10);

  if (local_res10[0] == *param_2) {

    BVar1 = PostMessageW(param_1,0x10,0,0);

    if (BVar1 != 0) {

      param_2[1] = param_2[1] + 1;

      return 1;

    }

  }

  return 1;

}




