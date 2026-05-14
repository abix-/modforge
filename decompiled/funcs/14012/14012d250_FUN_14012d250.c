// Address: 0x14012d250
// Ghidra name: FUN_14012d250
// ============ 0x14012d250 FUN_14012d250 (size=471) ============


HANDLE FUN_14012d250(char *param_1,undefined8 param_2)



{

  UINT uMode;

  int iVar1;

  longlong lVar2;

  longlong lVar3;

  longlong lVar4;

  longlong lVar5;

  HANDLE pvVar6;

  size_t sVar7;

  LPCWSTR lpFileName;

  uint uVar8;

  uint uVar9;

  uint uVar10;

  undefined8 local_res18;

  

  lVar2 = thunk_FUN_1402c9190(param_2,0x72);

  lVar3 = thunk_FUN_1402c9190(param_2,0x77,-lVar2);

  uVar9 = -(uint)(lVar3 != 0) & 2;

  lVar4 = thunk_FUN_1402c9190(param_2,0x2b);

  if ((lVar4 == 0) && (lVar2 == 0)) {

    uVar10 = 0;

  }

  else {

    uVar10 = 0x80000000;

  }

  lVar4 = thunk_FUN_1402c9190(param_2,0x61);

  if (((lVar4 == 0) && (lVar5 = thunk_FUN_1402c9190(param_2,0x2b), lVar5 == 0)) && (lVar3 == 0)) {

    uVar8 = 0;

  }

  else {

    uVar8 = 0x40000000;

    if ((lVar3 != 0) && (lVar3 = thunk_FUN_1402c9190(param_2,0x78), lVar3 != 0)) {

      uVar9 = 1;

    }

  }

  if ((uVar10 == 0) && (uVar8 == 0)) {

    pvVar6 = (HANDLE)0xffffffffffffffff;

  }

  else {

    uMode = SetErrorMode(0x8001);

    sVar7 = strlen(param_1);

    lpFileName = (LPCWSTR)FUN_140197820("UTF-16LE",&DAT_14039c6f0,param_1,sVar7 + 1);

    pvVar6 = CreateFileW(lpFileName,uVar8 | uVar10,(uint)(uVar8 == 0),(LPSECURITY_ATTRIBUTES)0x0,

                         -(uint)(lVar4 != 0) & 4 | uVar9 | -(uint)(lVar2 != 0) & 3,0x80,(HANDLE)0x0)

    ;

    FUN_1401841e0(lpFileName);

    SetErrorMode(uMode);

    if (pvVar6 == (HANDLE)0xffffffffffffffff) {

      iVar1 = FUN_14012ee40(&local_res18,"Couldn\'t open %s",param_1);

      if (iVar1 < 1) {

        FUN_14012e850("Couldn\'t open %s",param_1);

      }

      else {

        FUN_1401a9ed0(local_res18);

        FUN_1401841e0(local_res18);

      }

    }

  }

  return pvVar6;

}




