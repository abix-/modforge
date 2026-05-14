// Address: 0x140209880
// Ghidra name: FUN_140209880
// ============ 0x140209880 FUN_140209880 (size=244) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined8 FUN_140209880(longlong param_1,ushort param_2,ushort param_3)



{

  longlong lVar1;

  int iVar2;

  undefined8 uVar3;

  undefined8 local_28;

  undefined8 uStack_20;

  undefined4 local_18;

  undefined4 uStack_14;

  undefined4 uStack_10;

  undefined4 uStack_c;

  

  lVar1 = *(longlong *)(param_1 + 0x148);

  *(double *)(lVar1 + 0x78) = (double)param_2 / _DAT_1403502f8;

  *(double *)(lVar1 + 0x80) = (double)param_3 / _DAT_1403502f8;

  if (*(char *)(lVar1 + 0x56) == '\0') {

    uVar3 = FUN_14012e850("Controller isn\'t correlated yet, try hitting a button first");

    return uVar3;

  }

  local_28 = *(undefined8 *)(lVar1 + 0x68);

  uStack_20 = *(undefined8 *)(lVar1 + 0x70);

  local_18 = *(undefined4 *)(lVar1 + 0x78);

  uStack_14 = *(undefined4 *)(lVar1 + 0x7c);

  uStack_10 = *(undefined4 *)(lVar1 + 0x80);

  uStack_c = *(undefined4 *)(lVar1 + 0x84);

  iVar2 = (**(code **)(*(longlong *)**(undefined8 **)(lVar1 + 0x60) + 0x38))

                    ((longlong *)**(undefined8 **)(lVar1 + 0x60),&local_28);

  if (iVar2 < 0) {

    uVar3 = FUN_14012e850("Setting vibration failed: 0x%lx",iVar2);

    return uVar3;

  }

  if ((param_2 == 0) && (param_3 == 0)) {

    *(undefined1 *)(lVar1 + 0x88) = 0;

    return 1;

  }

  *(undefined1 *)(lVar1 + 0x88) = 1;

  return 1;

}




