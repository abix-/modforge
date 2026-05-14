// Address: 0x14021c7c0
// Ghidra name: FUN_14021c7c0
// ============ 0x14021c7c0 FUN_14021c7c0 (size=562) ============


undefined8 FUN_14021c7c0(char *param_1,char *param_2)



{

  int iVar1;

  BOOL BVar2;

  DWORD DVar3;

  size_t sVar4;

  short *psVar5;

  longlong lVar6;

  longlong lVar7;

  longlong lVar8;

  longlong lVar9;

  undefined8 uVar10;

  WCHAR local_218 [264];

  

  iVar1 = SHGetFolderPathW(0,0x801a,0,0,local_218);

  if (iVar1 < 0) {

    FUN_1401a9ef0("Couldn\'t locate our prefpath",iVar1);

    return 0;

  }

  sVar4 = strlen(param_1);

  psVar5 = (short *)FUN_140197820("UTF-16LE",&DAT_14039c6f0,param_1,sVar4 + 1);

  if (psVar5 != (short *)0x0) {

    sVar4 = strlen(param_2);

    lVar6 = FUN_140197820("UTF-16LE",&DAT_14039c6f0,param_2,sVar4 + 1);

    if (lVar6 == 0) {

      FUN_1401841e0(psVar5);

      return 0;

    }

    lVar7 = FUN_14012fd40(lVar6);

    lVar8 = FUN_14012fd40(psVar5);

    lVar9 = FUN_14012fd40(local_218);

    if (0x104 < (ulonglong)(lVar9 + 4 + lVar7 + lVar8)) {

      FUN_1401841e0(psVar5);

      FUN_1401841e0(lVar6);

      FUN_1401a9ed0("Path too long.");

      return 0;

    }

    if (*psVar5 != 0) {

      FUN_14012fc50(local_218,&DAT_1403556b0,0x104);

      FUN_14012fc50(local_218,psVar5,0x104);

    }

    FUN_1401841e0(psVar5);

    BVar2 = CreateDirectoryW(local_218,(LPSECURITY_ATTRIBUTES)0x0);

    if ((BVar2 == 0) && (DVar3 = GetLastError(), DVar3 != 0xb7)) {

      FUN_1401841e0(lVar6);

    }

    else {

      FUN_14012fc50(local_218,&DAT_1403556b0,0x104);

      FUN_14012fc50(local_218,lVar6,0x104);

      FUN_1401841e0(lVar6);

      BVar2 = CreateDirectoryW(local_218,(LPSECURITY_ATTRIBUTES)0x0);

      if ((BVar2 != 0) || (DVar3 = GetLastError(), DVar3 == 0xb7)) {

        FUN_14012fc50(local_218,&DAT_1403556b0,0x104);

        lVar6 = FUN_14012fd40(local_218);

        uVar10 = FUN_140197820(&DAT_14039c6f0,"UTF-16LE",local_218,lVar6 * 2 + 2);

        return uVar10;

      }

    }

    FUN_1401a9ed0("Couldn\'t create a prefpath.");

  }

  return 0;

}




