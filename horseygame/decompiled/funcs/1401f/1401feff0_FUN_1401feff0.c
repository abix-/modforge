// Address: 0x1401feff0
// Ghidra name: FUN_1401feff0
// ============ 0x1401feff0 FUN_1401feff0 (size=200) ============


bool FUN_1401feff0(undefined8 param_1,undefined4 param_2)



{

  undefined4 uVar1;

  undefined4 uVar2;

  undefined4 uVar3;

  undefined4 uVar4;

  undefined4 uVar5;

  uint uVar6;

  int iVar7;

  ulonglong uVar8;

  

  uVar1 = FUN_14014df00(param_2);

  uVar2 = FUN_14014dee0(param_2);

  uVar3 = FUN_14014de80(param_2);

  uVar4 = FUN_14014dec0(param_2);

  uVar5 = FUN_14014dea0(param_2);

  uVar6 = FUN_14014de60(param_2);

  uVar8 = (ulonglong)uVar6;

  iVar7 = FUN_1401f53e0(uVar1);

  if ((((iVar7 != 0x7fffffff) && (iVar7 = FUN_1401f53e0(uVar2), iVar7 != 0x7fffffff)) &&

      (iVar7 = FUN_1401f5470(uVar3), iVar7 != 0x7fffffff)) &&

     ((iVar7 = FUN_1401f53e0(uVar4), iVar7 != 0x7fffffff &&

      (iVar7 = FUN_1401f53e0(uVar5), iVar7 != 0x7fffffff)))) {

    iVar7 = FUN_1401f5470(uVar8 & 0xffffffff);

    return iVar7 != 0x7fffffff;

  }

  return false;

}




