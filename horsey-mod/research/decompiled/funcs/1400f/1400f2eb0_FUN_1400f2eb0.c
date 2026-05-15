// Address: 0x1400f2eb0
// Ghidra name: FUN_1400f2eb0
// ============ 0x1400f2eb0 FUN_1400f2eb0 (size=484) ============


void FUN_1400f2eb0(undefined8 *param_1,undefined8 param_2,int param_3,int param_4,int param_5,

                  float param_6,float param_7,float param_8,float param_9,undefined4 param_10)



{

  longlong lVar1;

  undefined4 uVar2;

  int iVar3;

  longlong lVar4;

  int iVar5;

  int iVar6;

  bool bVar7;

  double dVar8;

  double dVar9;

  undefined8 local_88;

  int local_80;

  int local_7c;

  int local_78;

  undefined8 local_70;

  

  uVar2 = FUN_1400f1b40(param_1,param_10,&local_88);

  iVar3 = FUN_1400f3c70(param_1,param_10);

  bVar7 = -1 < iVar3;

  iVar6 = param_5;

  iVar5 = param_5;

  if (bVar7) {

    lVar1 = param_1[1];

    lVar4 = (longlong)iVar3;

    iVar6 = (int)(short)((ushort)*(byte *)(lVar1 + 9 + lVar4) +

                        (ushort)*(byte *)(lVar1 + 8 + lVar4) * 0x100);

    iVar5 = (int)(short)((ushort)*(byte *)(lVar1 + 2 + lVar4) * 0x100 +

                        (ushort)*(byte *)(lVar1 + 3 + lVar4));

  }

  iVar3 = 0;

  if (bVar7) {

    iVar3 = iVar5;

  }

  dVar8 = (double)FUN_1402d0290((double)((float)iVar3 * param_6 + param_8));

  iVar5 = 0;

  if (bVar7) {

    iVar5 = iVar6;

  }

  dVar9 = (double)FUN_1402da530((double)((float)iVar5 * param_7 + param_9));

  local_78 = param_5;

  local_80 = param_3;

  local_7c = param_4;

  local_70 = param_2;

  if ((param_3 != 0) && (param_4 != 0)) {

    FUN_1400f32d0(&local_80,DAT_14030d950,local_88,uVar2,param_6,param_7,param_8,param_9,(int)dVar8,

                  -(int)dVar9,1,*param_1);

  }

  thunk_FUN_1402e9a80(local_88);

  return;

}




