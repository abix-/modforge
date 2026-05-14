// Address: 0x14022ba80
// Ghidra name: FUN_14022ba80
// ============ 0x14022ba80 FUN_14022ba80 (size=70) ============


void FUN_14022ba80(undefined8 param_1,longlong param_2)



{

  longlong lVar1;

  

  lVar1 = *(longlong *)(param_2 + 0x188);

  if ((*(ulonglong *)(param_2 + 0x48) & 1) == 0) {

    if ((*(char *)(lVar1 + 0x6d) == '\0') || ((*(ulonglong *)(param_2 + 0x48) & 0xc0) != 0)) {

      *(undefined1 *)(lVar1 + 99) = 1;

      ShowWindow(*(HWND *)(lVar1 + 8),9);

      *(undefined1 *)(lVar1 + 99) = 0;

      return;

    }

  }

  else {

    *(undefined1 *)(lVar1 + 0x69) = 0;

  }

  return;

}




