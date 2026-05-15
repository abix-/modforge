// Address: 0x1401010d0
// Ghidra name: FUN_1401010d0
// ============ 0x1401010d0 FUN_1401010d0 (size=63) ============


undefined4 * FUN_1401010d0(longlong param_1,int param_2,int param_3)



{

  if ((((-1 < param_2) && (param_2 < *(int *)(param_1 + 0x278))) && (-1 < param_3)) &&

     (param_3 < *(int *)(param_1 + 0x27c))) {

    return (undefined4 *)

           (*(longlong *)(param_1 + 0x270) +

           (longlong)(*(int *)(param_1 + 0x278) * param_3 + param_2) * 0x28);

  }

  return &DAT_1403dc390;

}




