// Address: 0x140224350
// Ghidra name: FUN_140224350
// ============ 0x140224350 FUN_140224350 (size=842) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined4 FUN_140224350(longlong param_1,ulonglong param_2)



{

  HKL pHVar1;

  UINT UVar2;

  int iVar3;

  DWORD dwLen;

  BOOL BVar4;

  undefined4 uVar5;

  LPCVOID lpData;

  uint uVar6;

  uint uVar7;

  uint local_res8 [2];

  LPVOID local_res18;

  CHAR local_118 [256];

  

  pHVar1 = *(HKL *)(param_1 + 0x248);

  local_res18 = (LPVOID)0x0;

  local_res8[0] = 0;

  if (DAT_1403fdc48 == pHVar1) {

    return (&DAT_1403fdc50)[param_2 & 0xffffffff];

  }

  uVar7 = (uint)pHVar1 & 0xffff;

  DAT_1403fdc48 = pHVar1;

  if ((*(char *)(param_1 + 0x144) != '\0') && (uVar7 == 0x404)) {

    _DAT_1403fdc50 = 0x7000404;

    return 0x7000404;

  }

  if (((((pHVar1 == (HKL)0xe0080404) || (pHVar1 == (HKL)0xe0090404)) || (pHVar1 == (HKL)0xe00a0404))

      || ((pHVar1 == (HKL)0xe00b0404 || (pHVar1 == (HKL)0xe00e0804)))) &&

     ((((UVar2 = ImmGetIMEFileNameA(pHVar1,local_118,0xff), UVar2 != 0 &&

        (*(longlong *)(param_1 + 600) == 0)) &&

       ((((iVar3 = CompareStringA(0x409,1,local_118,-1,"TINTLGNT.IME",-1), iVar3 == 2 ||

          (iVar3 = CompareStringA(0x409,1,local_118,-1,"CINTLGNT.IME",-1), iVar3 == 2)) ||

         (iVar3 = CompareStringA(0x409,1,local_118,-1,"MSTCIPHA.IME",-1), iVar3 == 2)) ||

        ((iVar3 = CompareStringA(0x409,1,local_118,-1,"PINTLGNT.IME",-1), iVar3 == 2 ||

         (iVar3 = CompareStringA(0x409,1,local_118,-1,"MSSCIPYA.IME",-1), iVar3 == 2)))))) &&

      (dwLen = GetFileVersionInfoSizeA(local_118,(LPDWORD)0x0), dwLen != 0)))) {

    lpData = (LPCVOID)FUN_1401841f0(dwLen);

    if (((lpData != (LPCVOID)0x0) &&

        (BVar4 = GetFileVersionInfoA(local_118,0,dwLen,lpData), BVar4 != 0)) &&

       (BVar4 = VerQueryValueA(lpData,"\\",&local_res18,local_res8), BVar4 != 0)) {

      uVar6 = ((*(uint *)((longlong)local_res18 + 8) & 0xff) << 8 |

              *(uint *)((longlong)local_res18 + 8) & 0xffff0000) << 8;

      if (*(longlong *)(param_1 + 600) != 0) {

LAB_140224679:

        _DAT_1403fdc50 = CONCAT44(*(undefined4 *)((longlong)local_res18 + 0xc),uVar6 | uVar7);

        FUN_1401841e0(lpData);

        uVar5 = DAT_1403fdc50;

        return uVar5;

      }

      if (uVar7 == 0x404) {

        if (((uVar6 == 0x4020000) || (uVar6 == 0x4030000)) ||

           ((uVar6 == 0x4040000 ||

            ((((uVar6 == 0x5000000 || (uVar6 == 0x5010000)) || (uVar6 == 0x5020000)) ||

             (uVar6 == 0x6000000)))))) goto LAB_140224679;

      }

      else if ((uVar7 == 0x804) &&

              (((uVar6 == 0x4010000 || (uVar6 == 0x4020000)) || (uVar6 == 0x5030000))))

      goto LAB_140224679;

    }

    FUN_1401841e0(lpData);

  }

  _DAT_1403fdc50 = 0;

  return 0;

}




