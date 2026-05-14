// Address: 0x1401e60b0
// Ghidra name: FUN_1401e60b0
// ============ 0x1401e60b0 FUN_1401e60b0 (size=73) ============


longlong FUN_1401e60b0(longlong *param_1,longlong param_2)



{

  longlong local_res8;

  longlong local_res10;

  

  (**(code **)(*param_1 + 0x48))(param_1,&local_res8);

  (**(code **)(*param_1 + 0x50))(param_1,&local_res10);

  return local_res10 + (param_2 - local_res8);

}




