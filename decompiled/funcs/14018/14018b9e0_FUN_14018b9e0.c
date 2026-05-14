// Address: 0x14018b9e0
// Ghidra name: FUN_14018b9e0
// ============ 0x14018b9e0 FUN_14018b9e0 (size=35) ============


ulonglong FUN_14018b9e0(int param_1,longlong param_2,int param_3)



{

  ulonglong in_RAX;

  

  if (0 < param_3) {

    in_RAX = 0;

    do {

      if (param_1 == *(int *)(param_2 + in_RAX * 4)) {

        return CONCAT71((int7)(in_RAX >> 8),1);

      }

      in_RAX = in_RAX + 1;

    } while ((longlong)in_RAX < (longlong)param_3);

  }

  return in_RAX & 0xffffffffffffff00;

}




