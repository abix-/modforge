// Address: 0x140209760
// Ghidra name: FUN_140209760
// ============ 0x140209760 FUN_140209760 (size=279) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined8 FUN_140209760(longlong param_1,ushort param_2,ushort param_3)



{

  longlong lVar1;

  bool bVar2;

  int iVar3;

  undefined8 uVar4;

  ushort local_res8;

  ushort local_resa;

  undefined8 local_28;

  undefined8 uStack_20;

  undefined4 local_18;

  undefined4 uStack_14;

  undefined4 uStack_10;

  undefined4 uStack_c;

  

  lVar1 = *(longlong *)(param_1 + 0x148);

  bVar2 = false;

  if ((*(char *)(lVar1 + 0x51) != '\0') && (*(char *)(lVar1 + 0x88) == '\0')) {

    if (DAT_1403fddf0 == (code *)0x0) {

      uVar4 = FUN_14012e850("That operation is not supported");

      return uVar4;

    }

    local_res8 = param_2;

    local_resa = param_3;

    iVar3 = (*DAT_1403fddf0)(*(undefined1 *)(lVar1 + 0x55),&local_res8);

    if (iVar3 != 0) {

      uVar4 = FUN_14012e850("XInputSetState() failed");

      return uVar4;

    }

    bVar2 = true;

  }

  *(double *)(lVar1 + 0x68) = (double)param_2 / _DAT_1403502f8;

  *(double *)(lVar1 + 0x70) = (double)param_3 / _DAT_1403502f8;

  if (bVar2) {

    return 1;

  }

  if (*(char *)(lVar1 + 0x56) != '\0') {

    local_28 = *(undefined8 *)(lVar1 + 0x68);

    uStack_20 = *(undefined8 *)(lVar1 + 0x70);

    local_18 = *(undefined4 *)(lVar1 + 0x78);

    uStack_14 = *(undefined4 *)(lVar1 + 0x7c);

    uStack_10 = *(undefined4 *)(lVar1 + 0x80);

    uStack_c = *(undefined4 *)(lVar1 + 0x84);

    iVar3 = (**(code **)(*(longlong *)**(undefined8 **)(lVar1 + 0x60) + 0x38))

                      ((longlong *)**(undefined8 **)(lVar1 + 0x60),&local_28);

    if (-1 < iVar3) {

      return 1;

    }

  }

  uVar4 = FUN_14012e850("Controller isn\'t correlated yet, try hitting a button first");

  return uVar4;

}




