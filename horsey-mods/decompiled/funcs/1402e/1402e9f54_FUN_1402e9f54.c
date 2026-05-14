// Address: 0x1402e9f54
// Ghidra name: FUN_1402e9f54
// ============ 0x1402e9f54 FUN_1402e9f54 (size=253) ============


void FUN_1402e9f54(void)



{

  longlong lVar1;

  DWORD DVar2;

  ulonglong uVar3;

  byte *pbVar4;

  longlong lVar5;

  uint *puVar6;

  uint uVar7;

  ulonglong uVar8;

  _STARTUPINFOW local_78;

  

  FUN_1402f94c0(&local_78,0,0x68);

  GetStartupInfoW(&local_78);

  lVar5 = 0;

  if ((local_78.cbReserved2 != 0) && ((uint *)local_78.lpReserved2 != (uint *)0x0)) {

    puVar6 = (uint *)((longlong)local_78.lpReserved2 + 4);

    pbVar4 = (byte *)((longlong)(int)*(uint *)local_78.lpReserved2 + (longlong)puVar6);

    uVar7 = 0x2000;

    if ((int)*(uint *)local_78.lpReserved2 < 0x2000) {

      uVar7 = *(uint *)local_78.lpReserved2;

    }

    __acrt_lowio_ensure_fh_exists(uVar7);

    if ((int)DAT_1403ff560 < (int)uVar7) {

      uVar7 = DAT_1403ff560;

    }

    uVar8 = (ulonglong)uVar7;

    if (uVar7 != 0) {

      do {

        if ((((*(longlong *)pbVar4 != -1) && (*(longlong *)pbVar4 != -2)) && ((*puVar6 & 1) != 0))

           && (((*puVar6 & 8) != 0 || (DVar2 = GetFileType(*(HANDLE *)pbVar4), DVar2 != 0)))) {

          uVar3 = (ulonglong)((uint)lVar5 & 0x3f);

          lVar1 = (&DAT_1403ff160)[lVar5 >> 6];

          *(undefined8 *)(lVar1 + 0x28 + uVar3 * 0x48) = *(undefined8 *)pbVar4;

          *(byte *)(lVar1 + 0x38 + uVar3 * 0x48) = (byte)*puVar6;

        }

        lVar5 = lVar5 + 1;

        puVar6 = (uint *)((longlong)puVar6 + 1);

        pbVar4 = pbVar4 + 8;

        uVar8 = uVar8 - 1;

      } while (uVar8 != 0);

    }

  }

  return;

}




