// Address: 0x140142ea0
// Ghidra name: FUN_140142ea0
// ============ 0x140142ea0 FUN_140142ea0 (size=166) ============


undefined8 FUN_140142ea0(longlong param_1,longlong param_2)



{

  int iVar1;

  char cVar2;

  undefined8 uVar3;

  longlong lVar4;

  

  cVar2 = FUN_1401489c0();

  if (cVar2 == '\0') {

    uVar3 = FUN_14012e850("Parameter \'%s\' is invalid","surface");

    return uVar3;

  }

  cVar2 = FUN_1401489c0(param_2);

  if (cVar2 == '\0') {

    uVar3 = FUN_14012e850("Parameter \'%s\' is invalid","image");

    return uVar3;

  }

  lVar4 = FUN_140184230(*(undefined8 *)(param_1 + 0x58),(longlong)*(int *)(param_1 + 0x50) * 8 + 8);

  if (lVar4 == 0) {

    return 0;

  }

  iVar1 = *(int *)(param_1 + 0x50);

  *(longlong *)(lVar4 + (longlong)iVar1 * 8) = param_2;

  *(int *)(param_1 + 0x50) = *(int *)(param_1 + 0x50) + 1;

  *(longlong *)(param_1 + 0x58) = lVar4;

  *(int *)(param_2 + 0x20) = *(int *)(param_2 + 0x20) + 1;

  return CONCAT71((int7)(int3)((uint)iVar1 >> 8),1);

}




