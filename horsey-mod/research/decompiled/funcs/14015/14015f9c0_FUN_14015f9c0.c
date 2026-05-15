// Address: 0x14015f9c0
// Ghidra name: FUN_14015f9c0
// ============ 0x14015f9c0 FUN_14015f9c0 (size=176) ============


undefined8 FUN_14015f9c0(undefined8 param_1,longlong param_2,undefined8 param_3)



{

  int iVar1;

  longlong lVar2;

  longlong lVar3;

  undefined8 uVar4;

  longlong lVar5;

  undefined8 uVar6;

  longlong local_res20;

  

  local_res20 = 0;

  lVar3 = FUN_14015cb20(param_1,&local_res20);

  lVar2 = local_res20;

  uVar6 = 0;

  if (lVar3 == 0) goto LAB_14015fa50;

  uVar6 = 1;

  if ((param_2 == 0) || (*(longlong *)(local_res20 + 0xa8) != 0)) {

LAB_14015fa40:

    *(longlong *)(lVar3 + 0x28) = param_2;

    *(undefined8 *)(lVar3 + 0x30) = param_3;

  }

  else {

    iVar1 = *(int *)(local_res20 + 0xb0);

    uVar4 = FUN_14017fc90();

    lVar5 = FUN_140190080(uVar4,(longlong)iVar1);

    *(longlong *)(lVar2 + 0xa8) = lVar5;

    if (lVar5 != 0) goto LAB_14015fa40;

    uVar6 = 0;

  }

  FUN_14015fec0(lVar2);

LAB_14015fa50:

  FUN_14015d3e0(lVar2);

  return uVar6;

}




