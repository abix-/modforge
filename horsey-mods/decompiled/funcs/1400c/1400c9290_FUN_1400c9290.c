// Address: 0x1400c9290
// Ghidra name: FUN_1400c9290
// ============ 0x1400c9290 FUN_1400c9290 (size=400) ============


void FUN_1400c9290(longlong param_1)



{

  uint uVar1;

  int iVar2;

  uint uVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  uint uVar7;

  undefined1 uVar8;

  longlong lVar9;

  int iVar10;

  float fVar11;

  undefined4 local_res10;

  

  uVar7 = DAT_14039cac0;

  fVar6 = DAT_14039ca50;

  fVar5 = DAT_14039ca34;

  fVar4 = DAT_140304c34;

  iVar10 = 0;

  do {

    lVar9 = (longlong)((*(int *)(param_1 + 8000) + 1 + iVar10) % 200);

    iVar2 = *(int *)(param_1 + 0x14 + lVar9 * 0x28);

    if (0 < iVar2) {

      uVar3 = *(uint *)(param_1 + 0x20 + lVar9 * 0x28);

      if (*(int *)(param_1 + 0x18 + lVar9 * 0x28) == -1) {

        uVar1 = *(uint *)(param_1 + 0x1c + lVar9 * 0x28);

        uVar8 = FUN_1400c5c20(uVar3 >> 0x18,iVar2 * 0x14);

        local_res10 = CONCAT13(uVar8,(int3)uVar3);

        FUN_140072f50(*(undefined8 *)(param_1 + lVar9 * 0x28),

                      *(undefined4 *)(param_1 + 0x24 + lVar9 * 0x28));

        fVar11 = (float)(uVar1 ^ uVar7) * fVar5;

        FUN_140071000(fVar11,fVar11,uVar1,uVar1,local_res10);

        FUN_1400730f0();

      }

      else {

        FUN_140072640();

        FUN_140071f00(*(undefined4 *)(param_1 + 0x18 + lVar9 * 0x28),

                      *(undefined4 *)(param_1 + lVar9 * 0x28),

                      *(undefined4 *)(param_1 + 4 + lVar9 * 0x28),

                      (*(float *)(param_1 + 0x24 + lVar9 * 0x28) * fVar6) / fVar4,

                      *(undefined4 *)(param_1 + 0x1c + lVar9 * 0x28),0);

      }

    }

    iVar10 = iVar10 + 1;

  } while (iVar10 < 200);

  FUN_1400727d0();

  return;

}




