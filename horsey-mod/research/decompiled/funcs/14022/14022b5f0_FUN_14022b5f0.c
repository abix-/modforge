// Address: 0x14022b5f0
// Ghidra name: FUN_14022b5f0
// ============ 0x14022b5f0 FUN_14022b5f0 (size=160) ============


void FUN_14022b5f0(undefined8 param_1,longlong param_2,int *param_3,LONG *param_4)



{

  char cVar1;

  BOOL BVar2;

  tagRECT local_18;

  

  BVar2 = GetClientRect(*(HWND *)(*(longlong *)(param_2 + 0x188) + 8),&local_18);

  if (BVar2 != 0) {

    cVar1 = FUN_1401aa1d0(&local_18);

    if (cVar1 != '\0') {

      *param_3 = local_18.right;

      *param_4 = local_18.bottom;

      return;

    }

  }

  if ((*(int *)(param_2 + 0x40) != 0) && (*(int *)(param_2 + 0x44) != 0)) {

    *param_3 = *(int *)(param_2 + 0x40);

    *param_4 = *(LONG *)(param_2 + 0x44);

    return;

  }

  *param_3 = *(int *)(param_2 + 0x84);

  *param_4 = *(LONG *)(param_2 + 0x88);

  return;

}




