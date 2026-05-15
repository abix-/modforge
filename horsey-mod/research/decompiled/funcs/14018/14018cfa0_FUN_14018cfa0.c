// Address: 0x14018cfa0
// Ghidra name: FUN_14018cfa0
// ============ 0x14018cfa0 FUN_14018cfa0 (size=472) ============


void FUN_14018cfa0(longlong param_1,longlong param_2)



{

  longlong lVar1;

  BOOL BVar2;

  UINT UVar3;

  DWORD DVar4;

  uint uVar5;

  HANDLE hProcess;

  longlong lVar6;

  longlong lVar7;

  int *piVar8;

  ulonglong uVar9;

  PRAWINPUT pData;

  ulonglong uVar10;

  ulonglong uVar11;

  uint uVar12;

  ulonglong uVar13;

  int local_res8 [2];

  uint local_res18 [4];

  

  lVar1 = *(longlong *)(param_1 + 0x680);

  uVar13 = 0;

  if (*(int *)(lVar1 + 0x108) == 0) {

    *(undefined4 *)(lVar1 + 0x108) = 0x18;

    hProcess = GetCurrentProcess();

    BVar2 = IsWow64Process(hProcess,local_res8);

    if ((BVar2 != 0) && (local_res8[0] != 0)) {

      *(int *)(lVar1 + 0x108) = *(int *)(lVar1 + 0x108) + 8;

    }

  }

  pData = *(PRAWINPUT *)(lVar1 + 0x100);

  uVar10 = uVar13;

  while( true ) {

    while( true ) {

      local_res18[0] = (*(int *)(lVar1 + 0x10c) - (int)pData) + *(int *)(lVar1 + 0x100);

      UVar3 = GetRawInputBuffer(pData,local_res18,0x18);

      lVar6 = FUN_140149300();

      if (0xfffffffd < UVar3 - 1) break;

      uVar10 = (ulonglong)((int)uVar10 + UVar3);

      do {

        pData = (PRAWINPUT)

                ((longlong)&(pData->header).dwSize + (ulonglong)(pData->header).dwSize + 3 &

                0xfffffffffffffff8);

        UVar3 = UVar3 - 1;

      } while (UVar3 != 0);

    }

    if (((*(longlong *)(lVar1 + 0x100) != 0) &&

        ((UVar3 != 0xffffffff || (DVar4 = GetLastError(), DVar4 != 0x7a)))) ||

       (lVar7 = FUN_140184230(*(undefined8 *)(lVar1 + 0x100),*(int *)(lVar1 + 0x10c) + 0x60),

       lVar7 == 0)) break;

    pData = (PRAWINPUT)((longlong)pData + (lVar7 - *(longlong *)(lVar1 + 0x100)));

    *(longlong *)(lVar1 + 0x100) = lVar7;

    *(int *)(lVar1 + 0x10c) = *(int *)(lVar1 + 0x10c) + 0x60;

  }

  if ((int)uVar10 != 0) {

    piVar8 = *(int **)(lVar1 + 0x100);

    uVar9 = uVar10;

    uVar11 = uVar13;

    do {

      uVar5 = (uint)uVar11 + 1;

      if (*piVar8 != 0) {

        uVar5 = (uint)uVar11;

      }

      uVar11 = (ulonglong)uVar5;

      piVar8 = (int *)((longlong)piVar8 + (ulonglong)(uint)piVar8[1] + 7 & 0xfffffffffffffff8);

      uVar9 = uVar9 - 1;

    } while (uVar9 != 0);

    piVar8 = *(int **)(lVar1 + 0x100);

    do {

      if (*piVar8 == 0) {

        uVar12 = (int)uVar13 + 1;

        uVar13 = (ulonglong)uVar12;

        FUN_14018c820(lVar6 - ((ulonglong)(uVar5 - uVar12) * (lVar6 - param_2)) / uVar11,lVar1,

                      *(undefined8 *)(piVar8 + 2),

                      (ulonglong)*(uint *)(lVar1 + 0x108) + (longlong)piVar8);

      }

      else if (*piVar8 == 1) {

        FUN_14018c6b0(lVar6,lVar1,*(undefined8 *)(piVar8 + 2),

                      (ulonglong)*(uint *)(lVar1 + 0x108) + (longlong)piVar8);

      }

      piVar8 = (int *)((longlong)piVar8 + (ulonglong)(uint)piVar8[1] + 7 & 0xfffffffffffffff8);

      uVar10 = uVar10 - 1;

    } while (uVar10 != 0);

  }

  *(longlong *)(lVar1 + 0x118) = lVar6;

  return;

}




