// Address: 0x14021e490
// Ghidra name: FUN_14021e490
// ============ 0x14021e490 FUN_14021e490 (size=149) ============


undefined8 FUN_14021e490(longlong param_1,char param_2)



{

  longlong *plVar1;

  BOOL BVar2;

  undefined4 extraout_var;

  undefined4 extraout_var_00;

  undefined4 extraout_var_01;

  undefined4 extraout_var_02;

  undefined8 uVar3;

  DWORD local_res18;

  int local_res1c;

  

  plVar1 = (longlong *)(param_1 + 0x10);

  if (param_2 == '\0') {

    local_res18 = *(DWORD *)(*plVar1 + 0x10);

    local_res1c = 0;

    BVar2 = EnumWindows(FUN_14021ec30,(LPARAM)&local_res18);

    uVar3 = CONCAT44(extraout_var,BVar2);

    if (local_res1c != 0) goto LAB_14021e51d;

    BVar2 = PostThreadMessageW(*(DWORD *)(*plVar1 + 0x14),0x10,0,0);

    uVar3 = CONCAT44(extraout_var_00,BVar2);

    if (BVar2 != 0) goto LAB_14021e51d;

    BVar2 = GenerateConsoleCtrlEvent(1,local_res18);

    uVar3 = CONCAT44(extraout_var_01,BVar2);

    if (BVar2 != 0) goto LAB_14021e51d;

  }

  BVar2 = TerminateProcess(*(HANDLE *)*plVar1,1);

  uVar3 = CONCAT44(extraout_var_02,BVar2);

  if (BVar2 == 0) {

    uVar3 = FUN_1401a9ed0("TerminateProcess failed");

    return uVar3;

  }

LAB_14021e51d:

  return CONCAT71((int7)((ulonglong)uVar3 >> 8),1);

}




