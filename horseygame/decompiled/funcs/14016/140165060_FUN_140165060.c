// Address: 0x140165060
// Ghidra name: FUN_140165060
// ============ 0x140165060 FUN_140165060 (size=43) ============


ulonglong FUN_140165060(longlong param_1,int param_2)



{

  int iVar1;

  ulonglong in_RAX;

  

  if ((param_1 != 0) && (0 < param_2)) {

    in_RAX = 0;

    do {

      iVar1 = *(int *)(param_1 + in_RAX * 4);

      if ((iVar1 < -1) || (param_2 <= iVar1)) {

        return CONCAT71((int7)(in_RAX >> 8),1);

      }

      in_RAX = in_RAX + 1;

    } while ((longlong)in_RAX < (longlong)param_2);

  }

  return in_RAX & 0xffffffffffffff00;

}




