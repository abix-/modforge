// Address: 0x14000b2a0
// Ghidra name: FUN_14000b2a0
// ============ 0x14000b2a0 FUN_14000b2a0 (size=71) ============


void FUN_14000b2a0(longlong param_1,undefined1 param_2)



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

  *(undefined1 *)(param_1 + 0xa0) = param_2;

  return;

}




