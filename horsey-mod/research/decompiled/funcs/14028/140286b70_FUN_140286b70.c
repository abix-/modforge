// Address: 0x140286b70
// Ghidra name: FUN_140286b70
// ============ 0x140286b70 FUN_140286b70 (size=86) ============


ulonglong FUN_140286b70(undefined2 param_1,undefined2 param_2)



{

  undefined2 local_res20;

  undefined2 local_res22;

  byte local_res24;

  

  if (DAT_1403fde50 == (longlong *)0x0) {

    return (ulonglong)(byte)((ushort)param_1 >> 8) << 8;

  }

  local_res24 = 0;

  local_res20 = param_1;

  local_res22 = param_2;

  (**(code **)(*DAT_1403fde50 + 0x20))(DAT_1403fde50,4,FUN_140286130,&local_res20,1);

  return (ulonglong)local_res24;

}




