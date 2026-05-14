// Address: 0x140164580
// Ghidra name: FUN_140164580
// ============ 0x140164580 FUN_140164580 (size=741) ============


undefined8 FUN_140164580(longlong param_1,longlong param_2,int param_3,float param_4)



{

  undefined8 *puVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  int iVar9;

  longlong lVar10;

  undefined8 uVar11;

  longlong lVar12;

  longlong lVar13;

  int iVar14;

  int iVar15;

  longlong lVar16;

  float fVar17;

  float fVar18;

  undefined4 uVar19;

  undefined8 in_stack_ffffffffffffff60;

  uint uVar20;

  undefined8 in_stack_ffffffffffffff68;

  undefined4 uVar21;

  undefined8 in_stack_ffffffffffffff80;

  undefined4 uVar22;

  int local_68;

  

  uVar20 = (uint)((ulonglong)in_stack_ffffffffffffff60 >> 0x20);

  uVar21 = (undefined4)((ulonglong)in_stack_ffffffffffffff68 >> 0x20);

  uVar22 = (undefined4)((ulonglong)in_stack_ffffffffffffff80 >> 0x20);

  iVar2 = *(int *)(param_1 + 0x3c);

  iVar8 = *(int *)(param_1 + 0x6c);

  iVar3 = *(int *)(param_1 + 0x40);

  iVar4 = *(int *)(param_1 + 0x68);

  uVar11 = *(undefined8 *)(param_1 + 0x50);

  iVar5 = FUN_140163e10(iVar4,iVar8,iVar2,iVar3);

  puVar1 = (undefined8 *)(param_1 + 0xa0);

  lVar10 = FUN_1401648f0(param_1,*(undefined4 *)(param_1 + 0x70),*puVar1);

  if (lVar10 == 0) {

    lVar10 = 0;

    if ((((iVar4 != iVar2) || (iVar8 != iVar3)) || (param_4 != DAT_14039ca44)) &&

       (lVar10 = FUN_140164440(param_1,(longlong)(iVar5 * param_3)), lVar10 == 0)) {

      return 0;

    }

    lVar10 = FUN_140217eb0(*(undefined8 *)(param_1 + 0x60),param_2,iVar2,iVar3,uVar11,

                           (ulonglong)uVar20 << 0x20,CONCAT44(uVar21,param_3),0,lVar10,

                           CONCAT44(uVar22,param_4));

    if (lVar10 != param_2) {

      uVar11 = FUN_14012e850("Not enough data in queue");

      return uVar11;

    }

  }

  else {

    iVar6 = FUN_140214360((longlong)param_3,lVar10,*puVar1);

    iVar7 = FUN_140214440(lVar10);

    local_68 = -1;

    iVar4 = iVar3;

    if (iVar8 < iVar3) {

      iVar4 = iVar8;

    }

    iVar8 = iVar6 + iVar7 * 2;

    iVar15 = iVar8 * iVar5;

    if ((iVar2 != 0x8120) || (iVar3 != iVar4)) {

      iVar9 = FUN_14017fc90();

      iVar14 = param_3;

      if (iVar5 * param_3 < iVar15) {

        iVar14 = iVar8;

      }

      local_68 = iVar14 * iVar5 + -1 + iVar9;

      local_68 = local_68 - local_68 % iVar9;

      iVar15 = iVar4 * 4 * param_3 + local_68;

    }

    lVar12 = FUN_140164440(param_1,(longlong)iVar15);

    if (lVar12 == 0) {

      return 0;

    }

    fVar17 = param_4;

    fVar18 = DAT_14039ca44;

    if (param_3 < iVar6) {

      fVar17 = DAT_14039ca44;

      fVar18 = param_4;

    }

    uVar19 = 0;

    lVar13 = FUN_140217eb0(*(undefined8 *)(param_1 + 0x60),0,0x8120,iVar4,0,CONCAT44(uVar20,iVar7),

                           CONCAT44(uVar21,iVar6),iVar7,lVar12,CONCAT44(uVar22,fVar17));

    if (lVar13 == 0) {

      uVar11 = FUN_14012e850("Not enough data in queue (resample)");

      return uVar11;

    }

    lVar16 = local_68 + lVar12;

    if (local_68 == -1) {

      lVar16 = param_2;

    }

    FUN_140214450(iVar4,lVar13 + iVar4 * 4 * iVar7,iVar6,lVar16,CONCAT44(uVar19,param_3),lVar10,

                  puVar1);

    FUN_140163e70(param_3,lVar16,0x8120,iVar4,0,param_2,iVar2,iVar3,uVar11,lVar12,fVar18);

  }

  return 1;

}




