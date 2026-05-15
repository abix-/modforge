// Address: 0x140220a10
// Ghidra name: FUN_140220a10
// ============ 0x140220a10 FUN_140220a10 (size=328) ============


undefined8 * FUN_140220a10(int *param_1)



{

  bool bVar1;

  int iVar2;

  UINT UVar3;

  int iVar4;

  undefined8 uVar5;

  undefined8 *puVar6;

  int iVar7;

  undefined8 *puVar8;

  undefined8 *puVar9;

  

  *param_1 = 0;

  uVar5 = FUN_14016dcf0();

  iVar2 = FUN_140221210(uVar5);

  if (iVar2 == 0) {

    return (undefined8 *)0x0;

  }

  iVar2 = 0;

  iVar7 = 0;

  bVar1 = false;

  for (UVar3 = EnumClipboardFormats(0); UVar3 != 0; UVar3 = EnumClipboardFormats(UVar3)) {

    if ((UVar3 == 8) || (UVar3 == 0x11)) {

      if (!bVar1) {

        bVar1 = true;

        goto LAB_140220a79;

      }

    }

    else {

LAB_140220a79:

      iVar4 = FUN_140220940(UVar3,0);

      if (0 < iVar4) {

        iVar2 = iVar2 + 1;

        iVar7 = iVar7 + iVar4;

      }

    }

  }

  bVar1 = false;

  puVar6 = (undefined8 *)FUN_1401391c0((longlong)iVar7 + (longlong)(iVar2 + 1) * 8);

  if (puVar6 != (undefined8 *)0x0) {

    puVar9 = puVar6 + iVar2 + 1;

    UVar3 = EnumClipboardFormats(0);

    puVar8 = puVar6;

    for (; UVar3 != 0; UVar3 = EnumClipboardFormats(UVar3)) {

      if ((UVar3 == 8) || (UVar3 == 0x11)) {

        if (!bVar1) {

          bVar1 = true;

          goto LAB_140220ae9;

        }

      }

      else {

LAB_140220ae9:

        iVar7 = FUN_140220940(UVar3,puVar9);

        if (0 < iVar7) {

          *puVar8 = puVar9;

          puVar8 = puVar8 + 1;

          puVar9 = (undefined8 *)((longlong)puVar9 + (longlong)iVar7);

        }

      }

    }

    puVar6[iVar2] = 0;

    *param_1 = iVar2;

  }

  CloseClipboard();

  return puVar6;

}




