// Address: 0x140286260
// Ghidra name: FUN_140286260
// ============ 0x140286260 FUN_140286260 (size=123) ============


ulonglong FUN_140286260(longlong *param_1,undefined2 *param_2,undefined2 *param_3)



{

  ulonglong in_RAX;

  undefined4 local_28;

  undefined8 local_24;

  undefined8 local_1c;

  

  if (((param_1 != (longlong *)0x0) && (param_2 != (undefined2 *)0x0)) &&

     (param_3 != (undefined2 *)0x0)) {

    local_28 = 0x14;

    local_1c = 0;

    local_24 = 0x10;

    in_RAX = (**(code **)(*param_1 + 0x28))(param_1,0x18,&local_28);

    if (-1 < (int)in_RAX) {

      *param_2 = local_1c._4_2_;

      *param_3 = (short)((ulonglong)local_1c >> 0x30);

      return CONCAT71((uint7)(byte)((ulonglong)local_1c >> 0x38),1);

    }

  }

  return in_RAX & 0xffffffffffffff00;

}




