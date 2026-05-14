// Address: 0x1402786c0
// Ghidra name: FUN_1402786c0
// ============ 0x1402786c0 FUN_1402786c0 (size=88) ============


void FUN_1402786c0(longlong param_1,char *param_2,uint param_3)



{

  char *pcVar1;

  uint uVar2;

  int iVar3;

  

  uVar2 = 0x15;

  if (param_3 < 0x16) {

    uVar2 = param_3;

  }

  iVar3 = 0;

  pcVar1 = param_2;

  if (0 < (int)uVar2) {

    while (*pcVar1 == -1) {

      iVar3 = iVar3 + 1;

      pcVar1 = pcVar1 + 1;

      if ((int)uVar2 <= iVar3) {

        return;

      }

    }

    FUN_1402f8e20(param_1 + 5,param_2,(longlong)(int)uVar2);

    *(char *)(param_1 + 0x1c) = (char)uVar2;

  }

  return;

}




