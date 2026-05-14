// Address: 0x140196c10
// Ghidra name: FUN_140196c10
// ============ 0x140196c10 FUN_140196c10 (size=407) ============


void FUN_140196c10(undefined8 *param_1,longlong param_2)



{

  ushort uVar1;

  DWORD dwMessageId;

  DWORD DVar2;

  int iVar3;

  undefined2 *puVar4;

  longlong lVar5;

  uint uVar6;

  undefined4 uVar7;

  WCHAR local_828 [1024];

  

  dwMessageId = GetLastError();

  FUN_1401841e0(*param_1);

  *param_1 = 0;

  FUN_14012e710();

  if (param_2 != 0) {

    uVar7 = 0;

    DVar2 = FormatMessageW(0x1200,(LPCVOID)0x0,dwMessageId,0x400,local_828,0x400,(va_list *)0x0);

    iVar3 = FUN_14012fd40(param_2);

    uVar6 = iVar3 + 0xf + DVar2;

    puVar4 = (undefined2 *)FUN_1401841a0(uVar6 + 1,2);

    if (puVar4 != (undefined2 *)0x0) {

      iVar3 = FUN_14012f550(puVar4,uVar6 + 1,L"%.*ls: (0x%08X) %.*ls",iVar3,param_2,dwMessageId,

                            CONCAT44(uVar7,DVar2),local_828);

      if (iVar3 < 0) {

        *puVar4 = 0;

      }

      else {

        while( true ) {

          uVar6 = uVar6 - 1;

          uVar1 = puVar4[uVar6];

          if ((0x20 < uVar1) || ((0x100002400U >> ((ulonglong)uVar1 & 0x3f) & 1) == 0)) break;

          puVar4[uVar6] = 0;

        }

        lVar5 = FUN_14012fd40(puVar4);

        lVar5 = FUN_140197820(&DAT_14039c6f0,"WCHAR_T",puVar4,lVar5 * 2 + 2);

        if (lVar5 != 0) {

          FUN_14012e850(&DAT_14039bf30,lVar5);

          FUN_1401841e0(lVar5);

        }

        FUN_1401841e0(puVar4);

      }

    }

  }

  return;

}




