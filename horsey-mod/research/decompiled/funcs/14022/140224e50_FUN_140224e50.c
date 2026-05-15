// Address: 0x140224e50
// Ghidra name: FUN_140224e50
// ============ 0x140224e50 FUN_140224e50 (size=386) ============


void FUN_140224e50(longlong param_1,HWND param_2,int *param_3,int param_4)



{

  BOOL BVar1;

  int iVar2;

  HIMC pHVar3;

  tagCOMPOSITIONFORM local_b8;

  tagCANDIDATEFORM local_98;

  tagLOGFONTW local_78;

  

  pHVar3 = ImmGetContext(param_2);

  if (pHVar3 != (HIMC)0x0) {

    iVar2 = param_3[3];

    BVar1 = ImmGetCompositionFontW(pHVar3,&local_78);

    local_b8.rcArea.left = *param_3;

    if (BVar1 != 0) {

      iVar2 = local_78.lfHeight;

    }

    local_b8.rcArea.top = param_3[1];

    local_b8.ptCurrentPos.x = local_b8.rcArea.left + param_4;

    local_b8.rcArea.right = local_b8.rcArea.left + param_3[2];

    local_b8.dwStyle = 1;

    local_b8.ptCurrentPos.y = (param_3[3] - iVar2) / 2 + local_b8.rcArea.top;

    local_b8.rcArea.bottom = param_3[3] + local_b8.rcArea.top;

    iVar2 = memcmp(&local_b8,(void *)(param_1 + 0x20c),0x1c);

    if (iVar2 != 0) {

      *(ulonglong *)(param_1 + 0x20c) = CONCAT44(local_b8.ptCurrentPos.x,local_b8.dwStyle);

      *(ulonglong *)(param_1 + 0x214) = CONCAT44(local_b8.rcArea.left,local_b8.ptCurrentPos.y);

      *(ulonglong *)(param_1 + 0x21c) = CONCAT44(local_b8.rcArea.right,local_b8.rcArea.top);

      *(LONG *)(param_1 + 0x224) = local_b8.rcArea.bottom;

      ImmSetCompositionWindow(pHVar3,&local_b8);

    }

    local_98.rcArea.left = *param_3;

    local_98.ptCurrentPos.y = param_3[1];

    local_98.ptCurrentPos.x = local_98.rcArea.left + param_4;

    local_98.rcArea.right = local_98.rcArea.left + param_3[2];

    local_98.rcArea.bottom = param_3[3] + local_98.ptCurrentPos.y;

    local_98.dwIndex = 0;

    local_98.dwStyle = 0x80;

    local_98.rcArea.top = local_98.ptCurrentPos.y;

    iVar2 = memcmp(&local_98,(void *)(param_1 + 0x228),0x20);

    if (iVar2 != 0) {

      *(ulonglong *)(param_1 + 0x228) = CONCAT44(local_98.dwStyle,local_98.dwIndex);

      *(ulonglong *)(param_1 + 0x230) = CONCAT44(local_98.ptCurrentPos.y,local_98.ptCurrentPos.x);

      *(ulonglong *)(param_1 + 0x238) = CONCAT44(local_98.rcArea.top,local_98.rcArea.left);

      *(ulonglong *)(param_1 + 0x240) = CONCAT44(local_98.rcArea.bottom,local_98.rcArea.right);

      ImmSetCandidateWindow(pHVar3,&local_98);

    }

    ImmReleaseContext(param_2,pHVar3);

  }

  return;

}




