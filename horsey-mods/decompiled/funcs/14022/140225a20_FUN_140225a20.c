// Address: 0x140225a20
// Ghidra name: FUN_140225a20
// ============ 0x140225a20 FUN_140225a20 (size=158) ============


void FUN_140225a20(void)



{

  BOOL BVar1;

  UINT wScanCode;

  int iVar2;

  int iVar3;

  WCHAR local_128 [16];

  BYTE local_108 [256];

  

  BVar1 = GetKeyboardState(local_108);

  if ((BVar1 != 0) && (wScanCode = MapVirtualKeyW(0x20,0), wScanCode != 0)) {

    iVar3 = 0;

    do {

      iVar2 = ToUnicode(0x20,wScanCode,local_108,local_128,0x10,0);

      if (0 < iVar2) {

        return;

      }

      iVar3 = iVar3 + 1;

    } while (iVar3 < 5);

  }

  return;

}




