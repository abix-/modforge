// Address: 0x140240ee0
// Ghidra name: FUN_140240ee0
// ============ 0x140240ee0 FUN_140240ee0 (size=28) ============


ulonglong FUN_140240ee0(longlong param_1,int param_2)



{

  ulonglong in_RAX;

  

  if ((param_1 != 0) &&

     (in_RAX = ((longlong)param_2 + 0xb) * 3,

     *(int *)(param_1 + ((longlong)param_2 + 0xb) * 0xc) != 0)) {

    return CONCAT71((int7)(in_RAX >> 8),1);

  }

  return in_RAX & 0xffffffffffffff00;

}




