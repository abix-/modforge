// Address: 0x1402e1ed0
// Ghidra name: FUN_1402e1ed0
// ============ 0x1402e1ed0 FUN_1402e1ed0 (size=95) ============


ulonglong FUN_1402e1ed0(undefined8 param_1,int param_2)



{

  short sVar1;

  undefined4 uVar2;

  uint local_res8 [8];

  

  uVar2 = (undefined4)((ulonglong)param_1 >> 0x20);

  local_res8[0] = (uint)param_1;

  if (param_2 != 0) {

    sVar1 = FUN_1402f19c0();

    if (sVar1 < 0) {

      sVar1 = FUN_1402f1b50(local_res8,param_2);

      if (sVar1 == 0) {

        FUN_1402eb620(0x10);

      }

      else if (sVar1 == 1) {

        FUN_1402eb620(8);

        return (ulonglong)local_res8[0];

      }

    }

    uVar2 = 0;

  }

  return CONCAT44(uVar2,local_res8[0]);

}




