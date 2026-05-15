// Address: 0x1400257d0
// Ghidra name: FUN_1400257d0
// ============ 0x1400257d0 FUN_1400257d0 (size=84) ============


undefined8 FUN_1400257d0(longlong param_1,undefined8 param_2,undefined8 param_3)



{

  int iVar1;

  longlong lVar2;

  longlong *plVar3;

  undefined8 uVar4;

  

  lVar2 = FUN_1400273e0(param_1 + 0x68);

  if (lVar2 == 0) {

    return 1;

  }

  plVar3 = (longlong *)(lVar2 + 0x40);

  if (0xf < *(ulonglong *)(lVar2 + 0x58)) {

    plVar3 = (longlong *)*plVar3;

  }

  iVar1 = FUN_140023f30(plVar3,&DAT_14039bf04,param_3);

  uVar4 = 0;

  if (iVar1 != 1) {

    uVar4 = 2;

  }

  return uVar4;

}




