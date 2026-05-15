// Address: 0x140210810
// Ghidra name: FUN_140210810
// ============ 0x140210810 FUN_140210810 (size=261) ============


undefined8 FUN_140210810(int param_1)



{

  undefined8 *puVar1;

  longlong lVar2;

  int iVar3;

  undefined8 uVar4;

  

  _guard_check_icall();

  if ((param_1 < 0) || (DAT_1403fd3a8 <= param_1)) {

    uVar4 = FUN_14012e850("GAMEINPUT_InternalRemoveByIndex argument idx %d is out of range",param_1)

    ;

    return uVar4;

  }

  puVar1 = *(undefined8 **)((longlong)param_1 * 8 + DAT_1403fd3a0);

  if (puVar1 != (undefined8 *)0x0) {

    (**(code **)(*(longlong *)*puVar1 + 0x10))();

    FUN_1401841e0(puVar1[10]);

    FUN_1401841e0(puVar1);

  }

  iVar3 = DAT_1403fd3a8;

  lVar2 = DAT_1403fd3a0;

  puVar1 = (undefined8 *)((longlong)param_1 * 8 + DAT_1403fd3a0);

  *puVar1 = 0;

  if (iVar3 == 1) {

    FUN_1401841e0();

    DAT_1403fd3a0 = 0;

    DAT_1403fd3a8 = DAT_1403fd3a8 + -1;

    return 1;

  }

  if (param_1 != iVar3 + -1) {

    FUN_1402f8e20(puVar1,lVar2 + (longlong)(param_1 + 1) * 8,(longlong)((iVar3 - param_1) * 8));

  }

  DAT_1403fd3a8 = iVar3 + -1;

  return 1;

}




