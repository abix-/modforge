// Address: 0x14012e110
// Ghidra name: FUN_14012e110
// ============ 0x14012e110 FUN_14012e110 (size=323) ============


void FUN_14012e110(undefined4 param_1,int param_2,undefined8 param_3,undefined8 param_4)



{

  int iVar1;

  uint uVar2;

  undefined1 *puVar3;

  ulonglong uVar4;

  undefined1 local_118 [256];

  

  if (PTR_FUN_1403dec30 == (undefined *)0x0) {

    return;

  }

  iVar1 = FUN_14012df60();

  if (param_2 < iVar1) {

    return;

  }

  uVar2 = FUN_14012f860(local_118,0x100,param_3,param_4);

  if ((int)uVar2 < 0) {

    return;

  }

  uVar4 = (ulonglong)(int)uVar2;

  if (uVar4 < 0x100) {

    puVar3 = local_118;

LAB_14012e1ca:

    if ((int)uVar2 < 1) goto LAB_14012e1ee;

  }

  else {

    if (uVar4 != 0xffffffffffffffff) {

      puVar3 = (undefined1 *)FUN_1401841f0(uVar4 + 1);

      if (puVar3 == (undefined1 *)0x0) {

        return;

      }

      uVar2 = FUN_14012f860(puVar3,uVar4 + 1,param_3,param_4);

      goto LAB_14012e1ca;

    }

    puVar3 = local_118;

    uVar2 = 0x100;

  }

  if (((puVar3[(ulonglong)uVar2 - 1] == '\n') &&

      (puVar3[(ulonglong)uVar2 - 1] = 0, 0 < (int)(uVar2 - 1))) &&

     (puVar3[(ulonglong)uVar2 - 2] == '\r')) {

    puVar3[(ulonglong)uVar2 - 2] = 0;

  }

LAB_14012e1ee:

  FUN_140179b40(DAT_1403fb518);

  (*(code *)PTR_FUN_1403dec30)(DAT_1403fb528,param_1,param_2,puVar3);

  FUN_140179b60(DAT_1403fb518);

  if (puVar3 != local_118) {

    FUN_1401841e0(puVar3);

  }

  return;

}




