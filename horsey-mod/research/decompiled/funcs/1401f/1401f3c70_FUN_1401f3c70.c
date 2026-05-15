// Address: 0x1401f3c70
// Ghidra name: FUN_1401f3c70
// ============ 0x1401f3c70 FUN_1401f3c70 (size=238) ============


undefined4 FUN_1401f3c70(longlong param_1,undefined4 param_2)



{

  longlong lVar1;

  undefined4 uVar2;

  undefined4 uVar3;

  int iVar4;

  undefined4 uVar5;

  undefined4 uVar6;

  uint uVar7;

  int iVar8;

  ulonglong uVar9;

  

  lVar1 = *(longlong *)(param_1 + 0x2e0);

  uVar2 = FUN_14014df00(param_2);

  uVar3 = FUN_14014dee0(param_2);

  iVar4 = FUN_14014de80(param_2);

  uVar5 = FUN_14014dec0(param_2);

  uVar6 = FUN_14014dea0(param_2);

  uVar7 = FUN_14014de60(param_2);

  uVar9 = (ulonglong)uVar7;

  iVar8 = FUN_1401ef410(uVar2);

  if (((((iVar8 != 0x500) && (iVar8 = FUN_1401ef410(uVar3), iVar8 != 0x500)) &&

       (iVar8 = FUN_1401ef3d0(iVar4), iVar8 != 0x500)) &&

      ((iVar8 = FUN_1401ef410(uVar5), iVar8 != 0x500 &&

       (iVar8 = FUN_1401ef410(uVar6), iVar8 != 0x500)))) &&

     ((iVar8 = FUN_1401ef3d0(uVar9 & 0xffffffff), iVar8 != 0x500 &&

      (((iVar4 != 4 && (iVar4 != 5)) || (*(char *)(lVar1 + 10) != '\0')))))) {

    return 1;

  }

  return 0;

}




