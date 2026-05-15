// Address: 0x140204a00
// Ghidra name: FUN_140204a00
// ============ 0x140204a00 FUN_140204a00 (size=211) ============


bool FUN_140204a00(undefined8 param_1,undefined4 param_2)



{

  undefined4 uVar1;

  undefined4 uVar2;

  int iVar3;

  undefined4 uVar4;

  undefined4 uVar5;

  uint uVar6;

  int iVar7;

  ulonglong uVar8;

  

  uVar1 = FUN_14014df00(param_2);

  uVar2 = FUN_14014dee0(param_2);

  iVar3 = FUN_14014de80(param_2);

  uVar4 = FUN_14014dec0(param_2);

  uVar5 = FUN_14014dea0(param_2);

  uVar6 = FUN_14014de60(param_2);

  uVar8 = (ulonglong)uVar6;

  iVar7 = FUN_140203470(uVar1);

  if ((((iVar7 != 0x7fffffff) && (iVar7 = FUN_140203470(uVar2), iVar7 != 0x7fffffff)) &&

      (((iVar3 == 1 || (((iVar3 == 2 || (iVar3 == 3)) || (iVar3 == 4)))) || (iVar3 == 5)))) &&

     ((iVar3 = FUN_140203470(uVar4), iVar3 != 0x7fffffff &&

      (iVar3 = FUN_140203470(uVar5), iVar3 != 0x7fffffff)))) {

    iVar3 = FUN_140203500(uVar8 & 0xffffffff);

    return iVar3 != 0x7fffffff;

  }

  return false;

}




