// Address: 0x14018bc10
// Ghidra name: FUN_14018bc10
// ============ 0x14018bc10 FUN_14018bc10 (size=177) ============


void FUN_14018bc10(void)



{

  BOOL BVar1;

  tagWNDCLASSEXW local_a8;

  tagWNDCLASSEXW local_58;

  

  if ((DAT_1403fcbbc != 0) && (DAT_1403fcbbc = DAT_1403fcbbc + -1, DAT_1403fcbbc == 0)) {

    local_a8.hIcon = (HICON)0x0;

    local_a8.hIconSm = (HICON)0x0;

    BVar1 = GetClassInfoExW(DAT_1403fcb90,DAT_1403fcb80,&local_a8);

    if (BVar1 != 0) {

      UnregisterClassW(DAT_1403fcb80,DAT_1403fcb90);

    }

    local_58.cbSize = local_a8.cbSize;

    local_58.style = local_a8.style;

    local_58.lpfnWndProc = local_a8.lpfnWndProc;

    local_58.hIcon = local_a8.hIcon;

    local_58.hCursor = local_a8.hCursor;

    local_58.cbClsExtra = local_a8.cbClsExtra;

    local_58.cbWndExtra = local_a8.cbWndExtra;

    local_58.hInstance = local_a8.hInstance;

    local_58.lpszClassName._0_4_ = local_a8.lpszClassName._0_4_;

    local_58.lpszClassName._4_4_ = local_a8.lpszClassName._4_4_;

    local_58.hIconSm._0_4_ = local_a8.hIconSm._0_4_;

    local_58.hIconSm._4_4_ = local_a8.hIconSm._4_4_;

    local_58.hbrBackground._0_4_ = local_a8.hbrBackground._0_4_;

    local_58.hbrBackground._4_4_ = local_a8.hbrBackground._4_4_;

    local_58.lpszMenuName._0_4_ = local_a8.lpszMenuName._0_4_;

    local_58.lpszMenuName._4_4_ = local_a8.lpszMenuName._4_4_;

    FUN_14018c570(&local_58);

  }

  return;

}




