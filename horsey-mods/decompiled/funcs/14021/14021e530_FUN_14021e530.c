// Address: 0x14021e530
// Ghidra name: FUN_14021e530
// ============ 0x14021e530 FUN_14021e530 (size=151) ============


ulonglong FUN_14021e530(longlong param_1,char param_2,uint *param_3)



{

  DWORD DVar1;

  BOOL BVar2;

  undefined4 extraout_var;

  ulonglong uVar3;

  uint local_res10 [6];

  

  DVar1 = WaitForSingleObject((HANDLE)**(undefined8 **)(param_1 + 0x10),-(uint)(param_2 != '\0'));

  if (DVar1 != 0) {

    if (DVar1 == 0xffffffff) {

      uVar3 = FUN_1401a9ed0("WaitForSingleObject(hProcess) returned WAIT_FAILED");

      return uVar3;

    }

    uVar3 = FUN_14012e710();

    return uVar3 & 0xffffffffffffff00;

  }

  BVar2 = GetExitCodeProcess((HANDLE)**(undefined8 **)(param_1 + 0x10),local_res10);

  uVar3 = CONCAT44(extraout_var,BVar2);

  if (BVar2 == 0) {

    uVar3 = FUN_1401a9ed0("GetExitCodeProcess");

    return uVar3;

  }

  if (param_3 != (uint *)0x0) {

    uVar3 = (ulonglong)local_res10[0];

    *param_3 = local_res10[0];

  }

  return CONCAT71((int7)(uVar3 >> 8),1);

}




