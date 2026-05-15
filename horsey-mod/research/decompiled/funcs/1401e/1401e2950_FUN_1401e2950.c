// Address: 0x1401e2950
// Ghidra name: FUN_1401e2950
// ============ 0x1401e2950 FUN_1401e2950 (size=431) ============


undefined8 FUN_1401e2950(undefined8 param_1,longlong param_2,longlong param_3,int param_4)



{

  float fVar1;

  float fVar2;

  char cVar3;

  float *pfVar4;

  undefined8 uVar5;

  float *pfVar6;

  longlong lVar7;

  longlong lVar8;

  longlong lVar9;

  undefined4 local_18;

  undefined4 uStack_14;

  undefined4 uStack_10;

  undefined4 uStack_c;

  

  lVar9 = (longlong)param_4;

  pfVar4 = (float *)FUN_14014b940(param_1,lVar9 << 5,0,param_2 + 8);

  local_18 = *(undefined4 *)(param_2 + 0x1c);

  uStack_14 = *(undefined4 *)(param_2 + 0x20);

  uStack_10 = *(undefined4 *)(param_2 + 0x24);

  uStack_c = *(undefined4 *)(param_2 + 0x28);

  cVar3 = FUN_1401538c0(param_1);

  if (pfVar4 == (float *)0x0) {

    uVar5 = 0;

  }

  else {

    *(longlong *)(param_2 + 0x10) = lVar9;

    if (cVar3 != '\0') {

      FUN_14014bd40(&local_18);

    }

    fVar2 = DAT_14039ca34;

    lVar7 = 0;

    if (3 < lVar9) {

      pfVar6 = (float *)(param_3 + 8);

      lVar8 = (lVar9 - 4U >> 2) + 1;

      lVar7 = lVar8 * 4;

      do {

        *pfVar4 = pfVar6[-2] + fVar2;

        fVar1 = pfVar6[-1];

        pfVar4[2] = 0.0;

        pfVar4[3] = 0.0;

        pfVar4[1] = fVar1 + fVar2;

        *(ulonglong *)(pfVar4 + 4) = CONCAT44(uStack_14,local_18);

        *(ulonglong *)(pfVar4 + 6) = CONCAT44(uStack_c,uStack_10);

        pfVar4[8] = *pfVar6 + fVar2;

        fVar1 = pfVar6[1];

        pfVar4[10] = 0.0;

        pfVar4[0xb] = 0.0;

        pfVar4[9] = fVar1 + fVar2;

        *(ulonglong *)(pfVar4 + 0xc) = CONCAT44(uStack_14,local_18);

        *(ulonglong *)(pfVar4 + 0xe) = CONCAT44(uStack_c,uStack_10);

        pfVar4[0x10] = pfVar6[2] + fVar2;

        fVar1 = pfVar6[3];

        pfVar4[0x12] = 0.0;

        pfVar4[0x13] = 0.0;

        pfVar4[0x11] = fVar1 + fVar2;

        *(ulonglong *)(pfVar4 + 0x14) = CONCAT44(uStack_14,local_18);

        *(ulonglong *)(pfVar4 + 0x16) = CONCAT44(uStack_c,uStack_10);

        pfVar4[0x18] = pfVar6[4] + fVar2;

        fVar1 = pfVar6[5];

        pfVar6 = pfVar6 + 8;

        pfVar4[0x1a] = 0.0;

        pfVar4[0x1b] = 0.0;

        pfVar4[0x19] = fVar1 + fVar2;

        *(ulonglong *)(pfVar4 + 0x1c) = CONCAT44(uStack_14,local_18);

        *(ulonglong *)(pfVar4 + 0x1e) = CONCAT44(uStack_c,uStack_10);

        pfVar4 = pfVar4 + 0x20;

        lVar8 = lVar8 + -1;

      } while (lVar8 != 0);

    }

    if (lVar7 < lVar9) {

      pfVar4 = pfVar4 + 2;

      do {

        pfVar4[-2] = *(float *)(param_3 + lVar7 * 8) + fVar2;

        fVar1 = *(float *)(param_3 + 4 + lVar7 * 8);

        lVar7 = lVar7 + 1;

        pfVar4[0] = 0.0;

        pfVar4[1] = 0.0;

        pfVar4[-1] = fVar1 + fVar2;

        *(ulonglong *)(pfVar4 + 2) = CONCAT44(uStack_14,local_18);

        *(ulonglong *)(pfVar4 + 4) = CONCAT44(uStack_c,uStack_10);

        pfVar4 = pfVar4 + 8;

      } while (lVar7 < lVar9);

    }

    uVar5 = 1;

  }

  return uVar5;

}




