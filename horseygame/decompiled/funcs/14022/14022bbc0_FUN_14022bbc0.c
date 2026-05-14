// Address: 0x14022bbc0
// Ghidra name: FUN_14022bbc0
// ============ 0x14022bbc0 FUN_14022bbc0 (size=233) ============


undefined8 FUN_14022bbc0(undefined8 param_1,longlong param_2,char param_3)



{

  ulonglong uVar1;

  HWND hWnd;

  undefined1 uVar2;

  char cVar3;

  uint uVar4;

  LONG LVar5;

  undefined8 uVar6;

  undefined8 local_res10 [3];

  

  uVar1 = *(ulonglong *)(param_2 + 0x48);

  if ((uVar1 & 0xc0000) == 0) {

    hWnd = *(HWND *)(*(longlong *)(param_2 + 0x188) + 8);

    uVar4 = GetWindowLongW(hWnd,-0x14);

    if (param_3 == '\0') {

      if ((uVar4 & 0x8000000) != 0) {

        return 1;

      }

      uVar4 = uVar4 | 0x8000000;

    }

    else {

      if ((uVar4 & 0x8000000) == 0) {

        return 1;

      }

      uVar4 = uVar4 & 0xf7ffffff;

    }

    LVar5 = SetWindowLongW(hWnd,-0x14,uVar4);

    if (LVar5 == 0) {

      uVar6 = FUN_1401a9ed0("SetWindowLong()");

      return uVar6;

    }

  }

  else if (((uVar1 >> 0x13 & 1) != 0) && ((uVar1 & 8) == 0)) {

    if (param_3 == '\0') {

      if ((uVar1 >> 9 & 1) != 0) {

        uVar2 = FUN_140172630(param_2,local_res10);

        FUN_14022bad0(local_res10[0],uVar2);

        return 1;

      }

    }

    else {

      cVar3 = FUN_140172550(param_2);

      if (cVar3 != '\0') {

        FUN_14022bad0(param_2,1);

      }

    }

  }

  return 1;

}




