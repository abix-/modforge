// Address: 0x1402680e0
// Ghidra name: FUN_1402680e0
// ============ 0x1402680e0 FUN_1402680e0 (size=69) ============


ulonglong FUN_1402680e0(longlong param_1,char param_2,char param_3)



{

  uint uVar1;

  char *in_RAX;

  ulonglong uVar2;

  

  uVar2 = 0;

  if ((ulonglong)*(byte *)(param_1 + 200) != 0) {

    in_RAX = *(char **)(param_1 + 0xd0);

    do {

      if (*in_RAX == param_2) {

        uVar1 = *(uint *)(in_RAX + 8);

        if ((uVar1 & 0x20) != 0) {

          return CONCAT71((uint7)(uint3)(uVar1 >> 8),1);

        }

        if (param_3 != '\0') {

          return (ulonglong)(uVar1 >> 4) & 0xffffffffffffff01;

        }

        return (ulonglong)(uVar1 >> 3) & 0xffffffffffffff01;

      }

      uVar2 = uVar2 + 1;

      in_RAX = in_RAX + 0x10;

    } while (uVar2 < *(byte *)(param_1 + 200));

  }

  return (ulonglong)in_RAX & 0xffffffffffffff00;

}




