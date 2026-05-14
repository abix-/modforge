// Address: 0x14017a190
// Ghidra name: FUN_14017a190
// ============ 0x14017a190 FUN_14017a190 (size=160) ============


void FUN_14017a190(int *param_1)



{

  longlong lVar1;

  uint uVar2;

  byte bVar3;

  uint uVar4;

  longlong lVar5;

  

  if (*param_1 == 0x100) {

    uVar2 = 0;

    lVar5 = 0;

    do {

      lVar1 = lVar5 + 4;

      uVar4 = uVar2 & 0xe0;

      *(byte *)(lVar5 + *(longlong *)(param_1 + 2)) =

           (byte)(uVar4 >> 6) | (byte)(uVar4 >> 3) | (byte)uVar4;

      bVar3 = (byte)(uVar2 & 0x1c);

      *(byte *)(*(longlong *)(param_1 + 2) + -3 + lVar1) =

           (byte)((uVar2 & 0x1c) >> 3) | bVar3 * '\b' | bVar3;

      bVar3 = (byte)uVar2 & 3;

      uVar2 = uVar2 + 1;

      bVar3 = bVar3 << 2 | bVar3;

      *(byte *)(*(longlong *)(param_1 + 2) + -2 + lVar1) = bVar3 << 4 | bVar3;

      *(undefined1 *)(*(longlong *)(param_1 + 2) + -1 + lVar1) = 0xff;

      lVar5 = lVar1;

    } while ((int)uVar2 < *param_1);

  }

  return;

}




