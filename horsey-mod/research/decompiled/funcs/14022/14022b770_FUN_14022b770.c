// Address: 0x14022b770
// Ghidra name: FUN_14022b770
// ============ 0x14022b770 FUN_14022b770 (size=249) ============


void FUN_14022b770(undefined8 param_1,longlong param_2)



{

  int iVar1;

  longlong lVar2;

  HWND hWnd;

  int iVar3;

  int local_res10 [2];

  int local_res18 [2];

  int local_res20 [2];

  int local_28 [4];

  

  lVar2 = *(longlong *)(param_2 + 0x188);

  if ((*(byte *)(param_2 + 0x48) & 1) != 0) {

    *(undefined1 *)(lVar2 + 0x69) = 1;

    return;

  }

  hWnd = *(HWND *)(lVar2 + 8);

  *(undefined1 *)(lVar2 + 99) = 1;

  ShowWindow(hWnd,3);

  *(undefined1 *)(lVar2 + 99) = 0;

  iVar1 = *(int *)(param_2 + 0x30);

  if (iVar1 == 0) {

    if (*(int *)(param_2 + 0x34) == 0) {

      return;

    }

    iVar3 = *(int *)(param_2 + 0x74);

  }

  else {

    iVar3 = *(int *)(param_2 + 0x20);

    if (iVar1 <= *(int *)(param_2 + 0x20)) {

      iVar3 = iVar1;

    }

  }

  iVar1 = *(int *)(param_2 + 0x34);

  *(int *)(param_2 + 0x74) = iVar3;

  if (iVar1 == 0) {

    iVar3 = *(int *)(param_2 + 0x78);

  }

  else {

    iVar3 = *(int *)(param_2 + 0x24);

    if (iVar1 <= *(int *)(param_2 + 0x24)) {

      iVar3 = iVar1;

    }

  }

  *(int *)(param_2 + 0x78) = iVar3;

  FUN_14022a7f0(param_2,local_28,local_res20,local_res18,local_res10,1);

  *(undefined1 *)(lVar2 + 99) = 1;

  SetWindowPos(hWnd,(HWND)0x0,local_28[0],local_res20[0],local_res18[0],local_res10[0],

               *(uint *)(lVar2 + 0xd0) | 0x212);

  *(undefined1 *)(lVar2 + 99) = 0;

  return;

}




