// Address: 0x1400f2b30
// Ghidra name: FUN_1400f2b30
// ============ 0x1400f2b30 FUN_1400f2b30 (size=783) ============


longlong FUN_1400f2b30(undefined8 *param_1,float param_2,float param_3,float param_4,float param_5,

                      undefined4 param_6,int *param_7,int *param_8,int *param_9,int *param_10)



{

  longlong lVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  longlong lVar6;

  int iVar7;

  int iVar8;

  longlong lVar9;

  int iVar10;

  bool bVar11;

  double dVar12;

  undefined8 local_88;

  int local_80;

  int local_7c;

  int local_78;

  longlong local_70;

  

  iVar4 = FUN_1400f1b40(param_1,param_6,&local_88);

  if (param_2 == 0.0) {

    param_2 = param_3;

  }

  if ((param_3 == 0.0) && (param_3 = param_2, param_2 == 0.0)) {

    lVar6 = 0;

  }

  else {

    iVar5 = FUN_1400f3c70(param_1,param_6);

    iVar7 = 0;

    lVar6 = 0;

    bVar11 = -1 < iVar5;

    iVar10 = iVar7;

    iVar8 = iVar4;

    iVar2 = iVar4;

    iVar3 = iVar4;

    if (bVar11) {

      lVar1 = param_1[1];

      lVar9 = (longlong)iVar5;

      iVar10 = (int)(short)((ushort)*(byte *)(lVar1 + 3 + lVar9) +

                           (ushort)*(byte *)(lVar1 + 2 + lVar9) * 0x100);

      iVar8 = (int)(short)((ushort)*(byte *)(lVar1 + 9 + lVar9) +

                          (ushort)*(byte *)(lVar1 + 8 + lVar9) * 0x100);

      iVar2 = (int)(short)((ushort)*(byte *)(lVar1 + 7 + lVar9) +

                          (ushort)*(byte *)(lVar1 + 6 + lVar9) * 0x100);

      iVar3 = (int)(short)((ushort)*(byte *)(lVar1 + 4 + lVar9) * 0x100 +

                          (ushort)*(byte *)(lVar1 + 5 + lVar9));

    }

    dVar12 = (double)FUN_1402d0290((double)((float)iVar10 * param_2 + param_4));

    iVar5 = (int)dVar12;

    iVar10 = iVar7;

    if (bVar11) {

      iVar10 = iVar8;

    }

    dVar12 = (double)FUN_1402da530((double)((float)iVar10 * param_3 + param_5));

    iVar10 = -(int)dVar12;

    iVar8 = iVar7;

    if (bVar11) {

      iVar8 = iVar2;

    }

    dVar12 = (double)FUN_1402da530((double)((float)iVar8 * param_2 + param_4));

    iVar8 = (int)dVar12 - iVar5;

    if (bVar11) {

      iVar7 = iVar3;

    }

    local_80 = iVar8;

    dVar12 = (double)FUN_1402d0290((double)((float)iVar7 * param_3 + param_5));

    local_7c = -((int)dVar12 + iVar10);

    if (param_7 != (int *)0x0) {

      *param_7 = iVar8;

    }

    if (param_8 != (int *)0x0) {

      *param_8 = local_7c;

    }

    if (param_9 != (int *)0x0) {

      *param_9 = iVar5;

    }

    if (param_10 != (int *)0x0) {

      *param_10 = iVar10;

    }

    if (((iVar8 != 0) && (local_7c != 0)) &&

       (lVar6 = _malloc_base((longlong)(local_7c * iVar8)), local_70 = lVar6, lVar6 != 0)) {

      local_78 = iVar8;

      FUN_1400f32d0(&local_80,DAT_14030d950,local_88,iVar4,param_2,param_3,param_4,param_5,iVar5,

                    iVar10,1,*param_1);

    }

    thunk_FUN_1402e9a80(local_88);

  }

  return lVar6;

}




