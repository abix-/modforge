// Address: 0x140179150
// Ghidra name: FUN_140179150
// ============ 0x140179150 FUN_140179150 (size=323) ============


undefined8 * FUN_140179150(char param_1)



{

  WCHAR WVar1;

  undefined8 *puVar2;

  longlong lVar3;

  undefined8 uVar4;

  LPWCH pWVar5;

  undefined1 *puVar6;

  undefined1 *puVar7;

  WCHAR *pWVar8;

  

  puVar2 = (undefined8 *)FUN_1401841a0(1,0x10);

  if (puVar2 != (undefined8 *)0x0) {

    lVar3 = FUN_1401aaee0(0,0,FUN_1401ab0c0,FUN_1401ab2f0,&LAB_1401644d0,0);

    puVar2[1] = lVar3;

    if (lVar3 != 0) {

      uVar4 = FUN_140179a30();

      *puVar2 = uVar4;

      if ((param_1 != '\0') && (pWVar5 = GetEnvironmentStringsW(), pWVar5 != (LPWCH)0x0)) {

        WVar1 = *pWVar5;

        pWVar8 = pWVar5;

        while (WVar1 != L'\0') {

          lVar3 = FUN_14012fd40(pWVar8);

          puVar6 = (undefined1 *)FUN_140197820(&DAT_14039c6f0,"UTF-16LE",pWVar8,lVar3 * 2 + 2);

          if (puVar6 != (undefined1 *)0x0) {

            puVar7 = (undefined1 *)thunk_FUN_1402c9190(puVar6,0x3d);

            if ((puVar7 == (undefined1 *)0x0) || (puVar7 == puVar6)) {

              FUN_1401841e0(puVar6);

            }

            else {

              *puVar7 = 0;

              FUN_1401ab100(puVar2[1],puVar6,puVar7 + 1,1);

            }

          }

          lVar3 = FUN_14012fd40(pWVar8);

          pWVar8 = pWVar8 + lVar3 + 1;

          WVar1 = *pWVar8;

        }

        FreeEnvironmentStringsW(pWVar5);

      }

      return puVar2;

    }

    FUN_1401841e0(puVar2);

  }

  return (undefined8 *)0x0;

}




