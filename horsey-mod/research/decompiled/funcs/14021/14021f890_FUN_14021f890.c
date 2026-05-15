// Address: 0x14021f890
// Ghidra name: FUN_14021f890
// ============ 0x14021f890 FUN_14021f890 (size=51) ============


ulonglong FUN_14021f890(longlong param_1,uint param_2,ulonglong *param_3)



{

  ulonglong in_RAX;

  ulonglong uVar1;

  ulonglong uVar2;

  

  uVar1 = 0;

  *param_3 = 0;

  uVar2 = uVar1;

  if (*(int *)(param_1 + 0x20) != 0) {

    do {

      if ((*(uint *)(uVar2 + *(longlong *)(param_1 + 0x28)) & param_2) != 0) {

        return CONCAT71((int7)((ulonglong)*(longlong *)(param_1 + 0x28) >> 8),1);

      }

      uVar1 = uVar1 + 1;

      *param_3 = uVar1;

      in_RAX = (ulonglong)*(int *)(param_1 + 0x20);

      uVar2 = uVar2 + 0x10;

    } while (uVar1 < in_RAX);

  }

  return in_RAX & 0xffffffffffffff00;

}




