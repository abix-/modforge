// Address: 0x140286c10
// Ghidra name: FUN_140286c10
// ============ 0x140286c10 FUN_140286c10 (size=404) ============


undefined1 FUN_140286c10(longlong param_1,ushort param_2,ushort param_3)



{

  longlong lVar1;

  longlong *plVar2;

  undefined1 uVar3;

  char cVar4;

  int iVar5;

  

  lVar1 = *(longlong *)(param_1 + 0x148);

  if ((*(uint *)(lVar1 + 0x1c) & 0x100) == 0) {

    uVar3 = FUN_14012e850("That operation is not supported");

    return uVar3;

  }

  if (*(char *)(lVar1 + 0xc50) == '\0') {

    cVar4 = FUN_140286710();

    if (cVar4 == '\0') {

      return 0;

    }

    *(undefined1 *)(*(longlong *)(param_1 + 0x148) + 0xc50) = 1;

  }

  else {

    **(uint **)(*(longlong *)(lVar1 + 0xc58) + 0x40) =

         (((uint)(param_2 >> 1) + (uint)(param_3 >> 1) >> 1) * 10000) / 0x7fff;

    plVar2 = *(longlong **)(*(longlong *)(param_1 + 0x148) + 0xc60);

    iVar5 = (**(code **)(*plVar2 + 0x30))

                      (plVar2,*(undefined8 *)(*(longlong *)(param_1 + 0x148) + 0xc58),0x101);

    if (iVar5 == -0x7ff8ffe2) {

      iVar5 = (**(code **)(**(longlong **)(*(longlong *)(param_1 + 0x148) + 0x10) + 0x38))();

      if (iVar5 < 0) goto LAB_140286cee;

      plVar2 = *(longlong **)(*(longlong *)(param_1 + 0x148) + 0xc60);

      iVar5 = (**(code **)(*plVar2 + 0x30))

                        (plVar2,*(undefined8 *)(*(longlong *)(param_1 + 0x148) + 0xc58),0x101);

    }

    if (iVar5 < 0) {

LAB_140286cee:

      uVar3 = FUN_140286ef0("IDirectInputDevice8::SetParameters",iVar5);

      return uVar3;

    }

  }

  plVar2 = *(longlong **)(*(longlong *)(param_1 + 0x148) + 0xc60);

  iVar5 = (**(code **)(*plVar2 + 0x38))(plVar2,1,0);

  if ((iVar5 == -0x7ff8ffe2) || (iVar5 == -0x7ffbfdfb)) {

    iVar5 = (**(code **)(**(longlong **)(*(longlong *)(param_1 + 0x148) + 0x10) + 0x38))();

    if (iVar5 < 0) goto LAB_140286d91;

    plVar2 = *(longlong **)(*(longlong *)(param_1 + 0x148) + 0xc60);

    iVar5 = (**(code **)(*plVar2 + 0x38))(plVar2,1,0);

  }

  if (-1 < iVar5) {

    return 1;

  }

LAB_140286d91:

  uVar3 = FUN_140286ef0("IDirectInputDevice8::Start",iVar5);

  return uVar3;

}




