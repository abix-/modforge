// Address: 0x1400f3100
// Ghidra name: FUN_1400f3100
// ============ 0x1400f3100 FUN_1400f3100 (size=454) ============


void FUN_1400f3100(longlong param_1,undefined8 param_2,float param_3,float param_4,float param_5,

                  float param_6,int *param_7,int *param_8,int *param_9,int *param_10)



{

  longlong lVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  longlong lVar6;

  int iVar7;

  bool bVar8;

  double dVar9;

  

  iVar2 = FUN_1400f3c70();

  bVar8 = -1 < iVar2;

  iVar3 = (int)param_7;

  iVar5 = (int)param_7;

  iVar4 = (int)param_7;

  iVar7 = (int)param_7;

  if (bVar8) {

    lVar1 = *(longlong *)(param_1 + 8);

    lVar6 = (longlong)iVar2;

    iVar3 = (int)(short)((ushort)*(byte *)(lVar1 + 6 + lVar6) * 0x100 +

                        (ushort)*(byte *)(lVar1 + 7 + lVar6));

    iVar5 = (int)(short)((ushort)*(byte *)(lVar1 + 4 + lVar6) * 0x100 +

                        (ushort)*(byte *)(lVar1 + 5 + lVar6));

    iVar4 = (int)(short)((ushort)*(byte *)(lVar1 + 3 + lVar6) +

                        (ushort)*(byte *)(lVar1 + 2 + lVar6) * 0x100);

    iVar7 = (int)(short)((ushort)*(byte *)(lVar1 + 9 + lVar6) +

                        (ushort)*(byte *)(lVar1 + 8 + lVar6) * 0x100);

  }

  iVar2 = 0;

  if (bVar8) {

    iVar2 = iVar5;

  }

  iVar5 = 0;

  if (bVar8) {

    iVar5 = iVar3;

  }

  iVar3 = 0;

  if (bVar8) {

    iVar3 = iVar7;

  }

  if (param_7 != (int *)0x0) {

    iVar7 = 0;

    if (bVar8) {

      iVar7 = iVar4;

    }

    dVar9 = (double)FUN_1402d0290((double)((float)iVar7 * param_3 + param_5));

    *param_7 = (int)dVar9;

  }

  if (param_8 != (int *)0x0) {

    dVar9 = (double)FUN_1402da530((double)((float)iVar3 * param_4 + param_6));

    *param_8 = -(int)dVar9;

  }

  if (param_9 != (int *)0x0) {

    dVar9 = (double)FUN_1402da530((double)((float)iVar5 * param_3 + param_5));

    *param_9 = (int)dVar9;

  }

  if (param_10 != (int *)0x0) {

    dVar9 = (double)FUN_1402d0290((double)((float)iVar2 * param_4 + param_6));

    *param_10 = -(int)dVar9;

  }

  return;

}




