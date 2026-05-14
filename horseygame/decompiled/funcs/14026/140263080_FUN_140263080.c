// Address: 0x140263080
// Ghidra name: FUN_140263080
// ============ 0x140263080 FUN_140263080 (size=50) ============


longlong FUN_140263080(int *param_1,int *param_2,int param_3,int param_4)



{

  return (longlong)(*param_2 - *param_1) * (longlong)(param_4 - param_1[1]) -

         (longlong)(param_2[1] - param_1[1]) * (longlong)(param_3 - *param_1);

}




