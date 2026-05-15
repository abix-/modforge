// Address: 0x1401999d0
// Ghidra name: FUN_1401999d0
// ============ 0x1401999d0 FUN_1401999d0 (size=236) ============


void FUN_1401999d0(longlong param_1,int *param_2,longlong param_3,int *param_4)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  byte bVar7;

  char cVar8;

  longlong lVar9;

  longlong lVar10;

  

  iVar1 = *(int *)(param_1 + 0x10);

  iVar2 = *(int *)(param_3 + 0x10);

  iVar3 = param_2[2];

  iVar4 = param_2[3];

  iVar5 = param_4[2];

  iVar6 = param_4[3];

  lVar9 = (longlong)(iVar1 * param_2[1]) + (longlong)(*param_2 << 2) + *(longlong *)(param_1 + 0x18)

  ;

  lVar10 = (longlong)(iVar2 * param_4[1]) + (longlong)(*param_4 << 2) +

           *(longlong *)(param_3 + 0x18);

  if (DAT_1403e3d00 == 0xffffffff) {

    bVar7 = FUN_14017fe50();

    DAT_1403e3d00 = (uint)bVar7;

  }

  if ((DAT_1403e3d00 != 0) &&

     (cVar8 = FUN_14019a610(lVar9,iVar3,iVar4,iVar1,lVar10,iVar5,iVar6,iVar2), cVar8 != '\0')) {

    return;

  }

  FUN_14019a120(lVar9,iVar3,iVar4,iVar1,lVar10,iVar5,iVar6,iVar2);

  return;

}




