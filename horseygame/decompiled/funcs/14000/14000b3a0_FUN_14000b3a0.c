// Address: 0x14000b3a0
// Ghidra name: FUN_14000b3a0
// ============ 0x14000b3a0 FUN_14000b3a0 (size=83) ============


void FUN_14000b3a0(longlong param_1,char param_2)



{

  longlong lVar1;

  

  if (param_2 != *(char *)(param_1 + 0xac)) {

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

    *(char *)(param_1 + 0xac) = param_2;

    *(undefined4 *)(param_1 + 0x98) = 0;

  }

  return;

}




