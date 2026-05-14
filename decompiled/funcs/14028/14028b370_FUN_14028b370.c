// Address: 0x14028b370
// Ghidra name: FUN_14028b370
// ============ 0x14028b370 FUN_14028b370 (size=31) ============


ulonglong FUN_14028b370(longlong param_1,uint param_2)



{

  ulonglong in_RAX;

  

  if ((param_2 < 0x10) &&

     (in_RAX = (ulonglong)(int)param_2, *(char *)(in_RAX * 0x98 + 0x9c + param_1) != '\0')) {

    return CONCAT71((int7)(int3)(param_2 >> 8),1);

  }

  return in_RAX & 0xffffffffffffff00;

}




