// Address: 0x14022c420
// Ghidra name: FUN_14022c420
// ============ 0x14022c420 FUN_14022c420 (size=282) ============


undefined1 FUN_14022c420(longlong param_1,UINT param_2,undefined4 param_3)



{

  HWND hWnd;

  char cVar1;

  undefined1 uVar2;

  BOOL BVar3;

  longlong lVar4;

  HWND hWndInsertAfter;

  int local_res8 [2];

  int local_res20 [2];

  int local_38;

  int local_34 [3];

  

  lVar4 = *(longlong *)(param_1 + 0x188);

  uVar2 = 1;

  hWnd = *(HWND *)(lVar4 + 8);

  cVar1 = FUN_140172540();

  if ((cVar1 == '\0') ||

     (hWndInsertAfter = (HWND)0xffffffffffffffff, (*(uint *)(param_1 + 0x48) >> 0x10 & 1) == 0)) {

    hWndInsertAfter = (HWND)0xfffffffffffffffe;

  }

  FUN_14022a7f0(param_1,local_34,&local_38,local_res20,local_res8,param_3);

  *(undefined1 *)(lVar4 + 99) = 1;

  BVar3 = SetWindowPos(hWnd,hWndInsertAfter,local_34[0],local_38,local_res20[0],local_res8[0],

                       param_2);

  if (BVar3 == 0) {

    uVar2 = FUN_1401a9ed0("SetWindowPos()");

  }

  *(undefined1 *)(lVar4 + 99) = 0;

  lVar4 = *(longlong *)(param_1 + 0x1b0);

  if (lVar4 != 0) {

    do {

      if (*(longlong *)(lVar4 + 0x188) != 0) {

        cVar1 = FUN_14022c420(lVar4,param_2,0);

        if (cVar1 == '\0') {

          uVar2 = 0;

        }

      }

      lVar4 = *(longlong *)(lVar4 + 0x1c0);

    } while (lVar4 != 0);

  }

  return uVar2;

}




