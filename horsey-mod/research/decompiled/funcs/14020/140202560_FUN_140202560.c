// Address: 0x140202560
// Ghidra name: FUN_140202560
// ============ 0x140202560 FUN_140202560 (size=204) ============


undefined1

FUN_140202560(undefined8 param_1,longlong param_2,int *param_3,longlong param_4,int param_5)



{

  byte bVar1;

  int iVar2;

  byte *pbVar3;

  char cVar4;

  longlong lVar5;

  int iVar6;

  

  pbVar3 = *(byte **)(param_2 + 0x138);

  if (((*pbVar3 & 2) != 0) && (cVar4 = FUN_140146f20(pbVar3), cVar4 == '\0')) {

    return 0;

  }

  iVar6 = 0;

  bVar1 = *(byte *)(*(longlong *)(pbVar3 + 0x38) + 5);

  iVar2 = param_3[2];

  lVar5 = (longlong)(int)((uint)bVar1 * *param_3) + (longlong)(param_3[1] * *(int *)(pbVar3 + 0x10))

          + *(longlong *)(pbVar3 + 0x18);

  if (0 < param_3[3]) {

    do {

      FUN_1402f8e20(lVar5,param_4,(longlong)iVar2 * (ulonglong)bVar1);

      param_4 = param_4 + param_5;

      lVar5 = lVar5 + *(int *)(pbVar3 + 0x10);

      iVar6 = iVar6 + 1;

    } while (iVar6 < param_3[3]);

  }

  if ((*pbVar3 & 2) != 0) {

    FUN_1401489e0(pbVar3);

  }

  return 1;

}




