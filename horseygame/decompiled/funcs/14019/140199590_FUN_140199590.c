// Address: 0x140199590
// Ghidra name: FUN_140199590
// ============ 0x140199590 FUN_140199590 (size=159) ============


void FUN_140199590(PNOTIFYICONDATAW param_1,char *param_2)



{

  char cVar1;

  size_t sVar2;

  undefined8 uVar3;

  

  if ((param_1 != (PNOTIFYICONDATAW)0x0) &&

     ((DAT_1403e3d60 == '\0' || (cVar1 = FUN_1401aa7c0(param_1,0xb), cVar1 != '\0')))) {

    if (param_2 == (char *)0x0) {

      param_1->szTip[0] = L'\0';

    }

    else {

      sVar2 = strlen(param_2);

      uVar3 = FUN_140197820("UTF-16LE",&DAT_14039c6f0,param_2,sVar2 + 1);

      FUN_14012fcd0(param_1->szTip,uVar3,0x80);

      FUN_1401841e0(uVar3);

    }

    Shell_NotifyIconW(1,param_1);

  }

  return;

}




