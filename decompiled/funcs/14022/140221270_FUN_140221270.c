// Address: 0x140221270
// Ghidra name: FUN_140221270
// ============ 0x140221270 FUN_140221270 (size=307) ============


ulonglong FUN_140221270(longlong param_1)



{

  longlong lVar1;

  undefined8 uVar2;

  char *_Str1;

  char cVar3;

  int iVar4;

  DWORD DVar5;

  ulonglong uVar6;

  ulonglong uVar7;

  ulonglong uVar8;

  

  lVar1 = *(longlong *)(param_1 + 0x680);

  uVar6 = 1;

  iVar4 = FUN_140221210();

  if (iVar4 == 0) {

    uVar6 = FUN_1401a9ed0("Couldn\'t open clipboard");

    return uVar6;

  }

  EmptyClipboard();

  uVar8 = 0;

  uVar7 = uVar8;

  if (*(longlong *)(param_1 + 0x380) != 0) {

    do {

      uVar2 = *(undefined8 *)(*(longlong *)(param_1 + 0x378) + uVar7 * 8);

      cVar3 = FUN_1401696e0(uVar2);

      if (cVar3 != '\0') {

        cVar3 = FUN_140221520(param_1,uVar2);

        uVar6 = 1;

        if (cVar3 == '\0') {

          uVar6 = uVar8;

        }

        break;

      }

      uVar7 = uVar7 + 1;

    } while (uVar7 < *(ulonglong *)(param_1 + 0x380));

  }

  uVar7 = uVar8;

  if (*(longlong *)(param_1 + 0x380) != 0) {

    do {

      _Str1 = *(char **)(*(longlong *)(param_1 + 0x378) + uVar7 * 8);

      iVar4 = strcmp(_Str1,"image/bmp");

      if ((iVar4 == 0) || (iVar4 = strcmp(_Str1,"image/png"), iVar4 == 0)) {

        cVar3 = FUN_1402213b0(param_1,_Str1);

        if (cVar3 == '\0') {

          uVar6 = uVar8;

        }

        break;

      }

      uVar7 = uVar7 + 1;

    } while (uVar7 < *(ulonglong *)(param_1 + 0x380));

  }

  DVar5 = GetClipboardSequenceNumber();

  *(DWORD *)(lVar1 + 8) = DVar5;

  CloseClipboard();

  return uVar6;

}




