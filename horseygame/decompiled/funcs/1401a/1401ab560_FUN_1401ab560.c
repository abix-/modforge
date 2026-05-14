// Address: 0x1401ab560
// Ghidra name: FUN_1401ab560
// ============ 0x1401ab560 FUN_1401ab560 (size=199) ============


undefined8 *

FUN_1401ab560(longlong param_1,undefined8 param_2,int param_3,uint *param_4,uint *param_5)



{

  undefined8 *puVar1;

  uint uVar2;

  uint uVar3;

  int iVar4;

  int iVar5;

  longlong lVar6;

  char cVar7;

  uint uVar8;

  ulonglong uVar9;

  

  lVar6 = *(longlong *)(param_1 + 8);

  uVar2 = *(uint *)(param_1 + 0x30);

  uVar3 = *(uint *)(param_1 + 0x34);

  iVar4 = *(int *)(lVar6 + 0x14 + (ulonglong)*param_4 * 0x18);

  puVar1 = (undefined8 *)(lVar6 + (ulonglong)*param_4 * 0x18);

  iVar5 = *(int *)(puVar1 + 2);

  while( true ) {

    if (-1 < iVar4) {

      return (undefined8 *)0x0;

    }

    if ((iVar5 == param_3) &&

       (cVar7 = (**(code **)(param_1 + 0x18))(*(undefined8 *)(param_1 + 0x28),*puVar1,param_2),

       cVar7 != '\0')) {

      return puVar1;

    }

    if ((*(uint *)((longlong)puVar1 + 0x14) & 0x7fffffff) < *param_5) {

      return (undefined8 *)0x0;

    }

    uVar8 = *param_5 + 1;

    *param_5 = uVar8;

    if (uVar3 < uVar8) break;

    uVar8 = *param_4 + 1 & uVar2;

    uVar9 = (ulonglong)uVar8;

    *param_4 = uVar8;

    iVar4 = *(int *)(lVar6 + 0x14 + uVar9 * 0x18);

    puVar1 = (undefined8 *)(lVar6 + uVar9 * 0x18);

    iVar5 = *(int *)(lVar6 + 0x10 + uVar9 * 0x18);

  }

  return (undefined8 *)0x0;

}




