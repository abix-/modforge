// Address: 0x140170020
// Ghidra name: FUN_140170020
// ============ 0x140170020 FUN_140170020 (size=85) ============


void FUN_140170020(longlong param_1,int param_2,int param_3,int *param_4,int *param_5)



{

  longlong lVar1;

  

  if ((*(uint *)(param_1 + 0x48) & 0xc0000) != 0) {

    for (lVar1 = *(longlong *)(param_1 + 0x1a8); lVar1 != 0; lVar1 = *(longlong *)(lVar1 + 0x1a8)) {

      param_2 = param_2 + *(int *)(lVar1 + 0x18);

      param_3 = param_3 + *(int *)(lVar1 + 0x1c);

      if ((*(uint *)(lVar1 + 0x48) & 0xc0000) == 0) break;

    }

  }

  if (param_4 != (int *)0x0) {

    *param_4 = param_2;

  }

  if (param_5 != (int *)0x0) {

    *param_5 = param_3;

  }

  return;

}




