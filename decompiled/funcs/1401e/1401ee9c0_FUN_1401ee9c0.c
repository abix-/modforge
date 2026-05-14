// Address: 0x1401ee9c0
// Ghidra name: FUN_1401ee9c0
// ============ 0x1401ee9c0 FUN_1401ee9c0 (size=206) ============


undefined4 FUN_1401ee9c0(undefined8 param_1,undefined4 param_2)



{

  undefined4 uVar1;

  undefined4 uVar2;

  int iVar3;

  undefined4 uVar4;

  undefined4 uVar5;

  uint uVar6;

  int iVar7;

  int iVar8;

  ulonglong uVar9;

  

  uVar1 = FUN_14014df00(param_2);

  uVar2 = FUN_14014dee0(param_2);

  iVar3 = FUN_14014de80(param_2);

  uVar4 = FUN_14014dec0(param_2);

  uVar5 = FUN_14014dea0(param_2);

  uVar6 = FUN_14014de60(param_2);

  uVar9 = (ulonglong)uVar6;

  iVar7 = FUN_1401ef410(uVar1);

  if ((((iVar7 != 0x500) && (iVar7 = FUN_1401ef410(uVar2), iVar7 != 0x500)) &&

      (iVar7 = FUN_1401ef3d0(iVar3), iVar7 != 0x500)) &&

     (iVar7 = FUN_1401ef410(uVar4), iVar7 != 0x500)) {

    iVar7 = FUN_1401ef410(uVar5);

    iVar8 = (int)uVar9;

    if (((iVar7 != 0x500) && (iVar7 = FUN_1401ef3d0(uVar9 & 0xffffffff), iVar7 != 0x500)) &&

       (iVar3 == iVar8)) {

      return 1;

    }

  }

  return 0;

}




