// Address: 0x14018d5d0
// Ghidra name: FUN_14018d5d0
// ============ 0x14018d5d0 FUN_14018d5d0 (size=130) ============


void FUN_14018d5d0(undefined8 param_1,HWND param_2)



{

  int iVar1;

  tagMSG local_38;

  

  if (DAT_1403e2908 != '\0') {

    DAT_1403fcb98 = 1;

    iVar1 = PeekMessageW(&local_38,param_2,0,0,1);

    while (iVar1 != 0) {

      FUN_14018d6b0(local_38.time);

      TranslateMessage(&local_38);

      DispatchMessageW(&local_38);

      iVar1 = PeekMessageW(&local_38,param_2,0,0,1);

    }

    DAT_1403fcb98 = 0;

  }

  return;

}




