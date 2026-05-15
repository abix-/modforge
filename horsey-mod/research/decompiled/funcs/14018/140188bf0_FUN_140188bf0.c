// Address: 0x140188bf0
// Ghidra name: FUN_140188bf0
// ============ 0x140188bf0 FUN_140188bf0 (size=131) ============


undefined8 FUN_140188bf0(uint *param_1)



{

  longlong lVar1;

  longlong lVar2;

  uint uVar3;

  ulonglong uVar4;

  

  lVar1 = *(longlong *)(param_1 + 0x10);

  uVar4 = 0;

  if (*param_1 != 0) {

    do {

      lVar2 = (ulonglong)(uint)((int)uVar4 * 4) + *(longlong *)(param_1 + 0x1c);

      *(ushort *)(*(longlong *)(param_1 + 0x1e) + *(longlong *)(param_1 + 0x22) * 2) =

           CONCAT11(*(undefined1 *)(lVar2 + 1 + *(longlong *)(param_1 + 0x18)),

                    *(undefined1 *)(lVar2 + *(longlong *)(param_1 + 0x18)));

      *(longlong *)(param_1 + 0x22) = *(longlong *)(param_1 + 0x22) + 1;

      *(undefined1 *)(uVar4 + lVar1) = *(undefined1 *)(lVar2 + 2 + *(longlong *)(param_1 + 0x18));

      uVar3 = (int)uVar4 + 1;

      uVar4 = (ulonglong)uVar3;

    } while (uVar3 < *param_1);

  }

  *(longlong *)(param_1 + 0x1c) = *(longlong *)(param_1 + 0x1c) + *(longlong *)(param_1 + 4);

  *(longlong *)(param_1 + 0xc) = *(longlong *)(param_1 + 0xc) + -1;

  return CONCAT71((int7)((ulonglong)*(longlong *)(param_1 + 4) >> 8),1);

}




