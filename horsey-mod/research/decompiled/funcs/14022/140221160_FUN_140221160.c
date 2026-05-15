// Address: 0x140221160
// Ghidra name: FUN_140221160
// ============ 0x140221160 FUN_140221160 (size=169) ============


undefined4 FUN_140221160(undefined8 param_1,char *param_2)



{

  char cVar1;

  BOOL BVar2;

  int iVar3;

  undefined4 uVar4;

  UINT UVar5;

  

  cVar1 = FUN_1401696e0(param_2);

  if (cVar1 == '\0') {

    iVar3 = strcmp(param_2,"image/bmp");

    if (iVar3 == 0) {

      BVar2 = IsClipboardFormatAvailable(0x11);

      if (BVar2 != 0) {

        return 1;

      }

      UVar5 = 8;

      goto LAB_140221190;

    }

    iVar3 = strcmp(param_2,"image/png");

    if (iVar3 != 0) goto LAB_14022119a;

    UVar5 = FUN_1402209e0();

    iVar3 = IsClipboardFormatAvailable(UVar5);

  }

  else {

    BVar2 = IsClipboardFormatAvailable(0xd);

    if (BVar2 != 0) {

      return 1;

    }

    UVar5 = 1;

LAB_140221190:

    iVar3 = IsClipboardFormatAvailable(UVar5);

  }

  if (iVar3 != 0) {

    return 1;

  }

LAB_14022119a:

  uVar4 = FUN_140169620(param_1,param_2);

  return uVar4;

}




