// Address: 0x140206a80
// Ghidra name: FUN_140206a80
// ============ 0x140206a80 FUN_140206a80 (size=321) ============


undefined8 FUN_140206a80(longlong param_1,undefined4 param_2)



{

  char cVar1;

  longlong lVar2;

  longlong *plVar3;

  undefined8 uVar4;

  undefined4 local_res18 [2];

  

  local_res18[0] = 0;

  lVar2 = FUN_140207ae0(param_2,local_res18);

  _guard_check_icall();

  if (((lVar2 == 0) || (*(longlong *)(lVar2 + 0x68) == 0)) || (*(char *)(lVar2 + 0x9a) != '\0')) {

    uVar4 = FUN_14012e850("Couldn\'t find HIDAPI device at index %d",param_2);

    return uVar4;

  }

  plVar3 = (longlong *)FUN_1401841a0(1,8);

  if (plVar3 != (longlong *)0x0) {

    *plVar3 = lVar2;

    FUN_140179b40(*(undefined8 *)(lVar2 + 0x78));

    *(undefined1 *)(lVar2 + 0x99) = 1;

    (**(code **)(*(longlong *)(lVar2 + 0x68) + 0x48))(lVar2);

    *(undefined1 *)(lVar2 + 0x99) = 0;

    FUN_140179b60(*(undefined8 *)(lVar2 + 0x78));

    if (*(int *)(lVar2 + 0x8c) == 0) {

      FUN_1401841e0(plVar3);

      uVar4 = FUN_14012e850("HIDAPI device disconnected while opening");

      return uVar4;

    }

    *(uint *)(param_1 + 0xe4) = (*(char *)(lVar2 + 0x54) != '\0') + 1;

    cVar1 = (**(code **)(*(longlong *)(lVar2 + 0x68) + 0x50))(lVar2,param_1);

    if (cVar1 != '\0') {

      FUN_140208ab0(lVar2,param_1);

      if (*(longlong *)(lVar2 + 0x28) != 0) {

        uVar4 = FUN_14012f0d0();

        *(undefined8 *)(param_1 + 0x18) = uVar4;

      }

      *(longlong **)(param_1 + 0x148) = plVar3;

      return 1;

    }

    FUN_140208230(lVar2,local_res18[0]);

    FUN_1401841e0(plVar3);

  }

  return 0;

}




