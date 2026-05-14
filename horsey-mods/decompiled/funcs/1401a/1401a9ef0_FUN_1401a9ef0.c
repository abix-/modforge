// Address: 0x1401a9ef0
// Ghidra name: FUN_1401a9ef0
// ============ 0x1401a9ef0 FUN_1401a9ef0 (size=230) ============


ulonglong FUN_1401a9ef0(undefined1 *param_1,DWORD param_2)



{

  DWORD DVar1;

  longlong lVar2;

  undefined8 uVar3;

  ulonglong uVar4;

  undefined1 *puVar5;

  WCHAR *pWVar6;

  undefined *puVar7;

  WCHAR local_808 [1024];

  

  pWVar6 = local_808;

  DVar1 = FormatMessageW(0x1000,(LPCVOID)0x0,param_2,0,local_808,0x400,(va_list *)0x0);

  local_808[DVar1] = L'\0';

  do {

    if (local_808[0] == L'\0') {

LAB_1401a9f5f:

      lVar2 = FUN_14012fd40(local_808);

      uVar3 = FUN_140197820(&DAT_14039c6f0,"UTF-16LE",local_808,lVar2 * 2 + 2);

      puVar7 = &DAT_14039bcb9;

      puVar5 = &DAT_14039bcb9;

      if (param_1 != (undefined1 *)0x0) {

        puVar7 = &DAT_14039bca8;

        puVar5 = param_1;

      }

      FUN_14012e850("%s%s%s",puVar5,puVar7,uVar3);

      uVar4 = FUN_1401841e0(uVar3);

      return uVar4 & 0xffffffffffffff00;

    }

    if (local_808[0] == L'\r') {

      *pWVar6 = L'\0';

      goto LAB_1401a9f5f;

    }

    local_808[0] = pWVar6[1];

    pWVar6 = pWVar6 + 1;

  } while( true );

}




