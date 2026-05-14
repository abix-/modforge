// Address: 0x140217eb0
// Ghidra name: FUN_140217eb0
// ============ 0x140217eb0 FUN_140217eb0 (size=759) ============


longlong FUN_140217eb0(undefined8 *param_1,longlong param_2,uint param_3,uint param_4,

                      undefined8 param_5,int param_6,int param_7,int param_8,longlong param_9,

                      float param_10)



{

  uint uVar1;

  uint uVar2;

  uint *puVar3;

  undefined8 uVar4;

  ulonglong uVar5;

  bool bVar6;

  undefined8 uVar7;

  ulonglong uVar8;

  longlong lVar9;

  longlong lVar10;

  longlong lVar11;

  longlong lVar12;

  ulonglong uVar13;

  longlong lVar14;

  

  puVar3 = (uint *)*param_1;

  if (puVar3 == (uint *)0x0) {

    return 0;

  }

  uVar1 = *puVar3;

  uVar4 = *(undefined8 *)(puVar3 + 4);

  uVar13 = (ulonglong)((param_3 >> 3 & 0x1f) * param_4);

  uVar2 = puVar3[1];

  uVar8 = (ulonglong)((uVar1 >> 3 & 0x1f) * uVar2);

  lVar11 = (longlong)param_6 * uVar13;

  lVar12 = (longlong)param_7 * uVar13;

  uVar13 = (longlong)param_6 * uVar8;

  lVar14 = (longlong)param_7 * uVar8;

  if (((uVar1 == param_3) && (uVar2 == param_4)) && (param_10 == DAT_14039ca44)) {

    bVar6 = false;

  }

  else {

    bVar6 = true;

    if (param_2 == 0) {

      param_2 = param_9;

    }

  }

  uVar5 = *(ulonglong *)(puVar3 + 0x10);

  if ((uVar5 < uVar13) ||

     (*(longlong *)(puVar3 + 0x12) - uVar5 < (longlong)param_8 * uVar8 + lVar14)) {

    lVar9 = param_9;

    if ((param_2 != 0) && (lVar9 = param_2, !bVar6)) {

      param_9 = param_2;

    }

    lVar10 = lVar9;

    if (uVar13 != 0) {

      uVar7 = FUN_1402178c0(param_1,param_9,uVar13);

      FUN_140163e70(param_6,uVar7,uVar1,uVar2,uVar4,lVar9,param_3,param_4,param_5,param_9,param_10);

      lVar10 = lVar9 + lVar11;

      param_9 = param_9 + lVar11;

    }

    if (lVar14 != 0) {

      uVar7 = FUN_140217960(param_1,param_9,lVar14);

      FUN_140163e70(param_7,uVar7,uVar1,uVar2,uVar4,lVar10,param_3,param_4,param_5,param_9,param_10)

      ;

      lVar10 = lVar10 + lVar12;

      param_9 = param_9 + lVar12;

    }

    if ((longlong)param_8 * uVar8 != 0) {

      uVar7 = FUN_1402177e0(param_1,param_9);

      FUN_140163e70(param_8,uVar7,uVar1,uVar2,uVar4,lVar10,param_3,param_4,param_5,param_9,param_10)

      ;

    }

  }

  else {

    *(ulonglong *)(puVar3 + 0x10) = uVar5 + lVar14;

    lVar9 = (*(longlong *)(puVar3 + 0xe) - uVar13) + uVar5;

    if (param_2 != 0) {

      FUN_140163e70(param_7 + param_6 + param_8,lVar9,uVar1,uVar2,uVar4,param_2,param_3,param_4,

                    param_5,param_9,param_10);

      lVar9 = param_2;

    }

  }

  return lVar9;

}




