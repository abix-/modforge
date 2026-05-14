// Address: 0x1400083a0
// Ghidra name: FUN_1400083a0
// ============ 0x1400083a0 FUN_1400083a0 (size=42) ============


void FUN_1400083a0(longlong param_1,char param_2)



{

  longlong lVar1;

  

  if (param_2 != *(char *)(param_1 + 0x3a)) {

    lVar1 = *(longlong *)(param_1 + 0x10);

    if ((*(ushort *)(lVar1 + 4) & 2) == 0) {

      *(undefined4 *)(lVar1 + 0xac) = 0;

      *(ushort *)(lVar1 + 4) = *(ushort *)(lVar1 + 4) | 2;

    }

    *(char *)(param_1 + 0x3a) = param_2;

  }

  return;

}




