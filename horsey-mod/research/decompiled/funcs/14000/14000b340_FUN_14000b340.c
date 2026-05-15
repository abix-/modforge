// Address: 0x14000b340
// Ghidra name: FUN_14000b340
// ============ 0x14000b340 FUN_14000b340 (size=66) ============


void FUN_14000b340(longlong param_1,undefined4 param_2)



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

  *(undefined4 *)(param_1 + 0xa4) = param_2;

  return;

}




