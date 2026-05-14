// Address: 0x140009e10
// Ghidra name: FUN_140009e10
// ============ 0x140009e10 FUN_140009e10 (size=71) ============


void FUN_140009e10(longlong param_1,undefined1 param_2)



{

  longlong lVar1;

  

  lVar1 = *(longlong *)(param_1 + 0x60);

  if ((*(ushort *)(lVar1 + 4) & 2) == 0) {

    *(undefined4 *)(lVar1 + 0xac) = 0;

    *(ushort *)(lVar1 + 4) = *(ushort *)(lVar1 + 4) | 2;

  }

  lVar1 = *(longlong *)(param_1 + 0x68);

  if ((*(ushort *)(lVar1 + 4) & 2) == 0) {

    *(undefined4 *)(lVar1 + 0xac) = 0;

    *(ushort *)(lVar1 + 4) = *(ushort *)(lVar1 + 4) | 2;

  }

  *(undefined1 *)(param_1 + 0xc5) = param_2;

  return;

}




