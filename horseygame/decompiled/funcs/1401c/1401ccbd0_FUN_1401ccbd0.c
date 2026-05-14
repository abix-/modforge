// Address: 0x1401ccbd0
// Ghidra name: FUN_1401ccbd0
// ============ 0x1401ccbd0 FUN_1401ccbd0 (size=102) ============


undefined8 FUN_1401ccbd0(longlong param_1,int param_2,int param_3)



{

  int iVar1;

  undefined4 local_18;

  undefined4 local_14;

  undefined4 local_10;

  int local_c;

  

  local_10 = 0;

  local_18 = *(undefined4 *)(&DAT_1403e43f0 + (longlong)param_2 * 4);

  local_14 = *(undefined4 *)(&DAT_1403e49f0 + (longlong)param_3 * 4);

  iVar1 = (**(code **)(**(longlong **)(param_1 + 0x70) + 0x68))

                    (*(longlong **)(param_1 + 0x70),4,&local_18,0x10);

  if ((-1 < iVar1) && (local_c != 0)) {

    return 1;

  }

  return 0;

}




