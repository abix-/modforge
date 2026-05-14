// Address: 0x1401896e0
// Ghidra name: FUN_1401896e0
// ============ 0x1401896e0 FUN_1401896e0 (size=310) ============


undefined8 FUN_1401896e0(uint *param_1)



{

  longlong lVar1;

  byte bVar2;

  uint uVar3;

  ushort *puVar4;

  uint uVar5;

  undefined8 uVar6;

  ulonglong uVar7;

  undefined2 *puVar8;

  uint uVar9;

  ulonglong uVar10;

  

  uVar3 = *param_1;

  uVar7 = (ulonglong)uVar3;

  uVar10 = 0;

  puVar4 = *(ushort **)(param_1 + 0xe);

  if (uVar3 != 0) {

    puVar8 = (undefined2 *)(*(longlong *)(param_1 + 0x10) + 4);

    do {

      bVar2 = *(byte *)(uVar10 + *(longlong *)(param_1 + 0x18));

      if (*puVar4 < (ushort)bVar2) {

        uVar6 = FUN_14012e850("Invalid MS ADPCM coefficient index in block header");

        return uVar6;

      }

      puVar8[-1] = *(undefined2 *)(*(longlong *)(puVar4 + 4) + (ulonglong)bVar2 * 4);

      uVar5 = (int)uVar10 * 2;

      *puVar8 = *(undefined2 *)(*(longlong *)(puVar4 + 4) + 2 + (ulonglong)bVar2 * 4);

      uVar9 = (int)uVar10 + 1;

      uVar10 = (ulonglong)uVar9;

      lVar1 = (ulonglong)uVar5 + uVar7 * 3;

      puVar8[-2] = CONCAT11(*(undefined1 *)(uVar7 + uVar5 + 1 + *(longlong *)(param_1 + 0x18)),

                            *(undefined1 *)(uVar7 + uVar5 + *(longlong *)(param_1 + 0x18)));

      puVar8 = puVar8 + 3;

      *(ushort *)(*(longlong *)(param_1 + 0x1e) + (*(longlong *)(param_1 + 0x22) + uVar7) * 2) =

           CONCAT11(*(undefined1 *)(lVar1 + 1 + *(longlong *)(param_1 + 0x18)),

                    *(undefined1 *)(lVar1 + *(longlong *)(param_1 + 0x18)));

      lVar1 = (ulonglong)uVar5 + uVar7 * 5;

      *(ushort *)(*(longlong *)(param_1 + 0x1e) + *(longlong *)(param_1 + 0x22) * 2) =

           CONCAT11(*(undefined1 *)(lVar1 + 1 + *(longlong *)(param_1 + 0x18)),

                    *(undefined1 *)(lVar1 + *(longlong *)(param_1 + 0x18)));

      *(longlong *)(param_1 + 0x22) = *(longlong *)(param_1 + 0x22) + 1;

    } while (uVar9 < uVar3);

  }

  *(longlong *)(param_1 + 0x1c) = *(longlong *)(param_1 + 0x1c) + *(longlong *)(param_1 + 4);

  *(ulonglong *)(param_1 + 0x22) = *(longlong *)(param_1 + 0x22) + (ulonglong)*param_1;

  *(longlong *)(param_1 + 0xc) = *(longlong *)(param_1 + 0xc) + -2;

  return CONCAT71((uint7)(uint3)(*param_1 >> 8),1);

}




