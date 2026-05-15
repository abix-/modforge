// Address: 0x1401ed790
// Ghidra name: FUN_1401ed790
// ============ 0x1401ed790 FUN_1401ed790 (size=345) ============


undefined1 FUN_1401ed790(undefined4 param_1,longlong param_2,float *param_3,int param_4)



{

  float fVar1;

  float fVar2;

  undefined1 uVar3;

  float *pfVar4;

  longlong lVar5;

  longlong lVar6;

  undefined4 uVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  float fVar11;

  

  lVar5 = (longlong)param_4;

  pfVar4 = (float *)FUN_14014b940(param_1,lVar5 * 8,0,param_2 + 8);

  uVar3 = SUB81(pfVar4,0);

  if (pfVar4 != (float *)0x0) {

    *(longlong *)(param_2 + 0x10) = lVar5;

    fVar2 = DAT_14039ca34;

    fVar11 = *param_3 + DAT_14039ca34;

    fVar8 = param_3[1] + DAT_14039ca34;

    *pfVar4 = fVar11;

    pfVar4[1] = fVar8;

    fVar1 = DAT_14030335c;

    if (1 < lVar5) {

      lVar6 = 1;

      do {

        fVar9 = param_3[lVar6 * 2] + fVar2;

        fVar10 = param_3[lVar6 * 2 + 1] + fVar2;

        uVar7 = thunk_FUN_1402cd4c0(fVar10 - fVar8,fVar9 - fVar11);

        fVar8 = (float)thunk_FUN_1402cfda0();

        fVar11 = fVar8 * fVar1 + fVar9;

        fVar8 = (float)thunk_FUN_1402cdc50(uVar7);

        pfVar4[2] = fVar11;

        lVar6 = lVar6 + 1;

        fVar8 = fVar8 * fVar1 + fVar10;

        pfVar4[3] = fVar8;

        pfVar4 = pfVar4 + 2;

      } while (lVar6 < lVar5);

    }

    uVar3 = 1;

  }

  return uVar3;

}




