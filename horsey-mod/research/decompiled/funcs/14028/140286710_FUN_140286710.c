// Address: 0x140286710
// Ghidra name: FUN_140286710
// ============ 0x140286710 FUN_140286710 (size=351) ============


undefined8 FUN_140286710(longlong param_1,undefined2 param_2)



{

  longlong *plVar1;

  longlong lVar2;

  int iVar3;

  undefined8 uVar4;

  

  plVar1 = *(longlong **)(*(longlong *)(param_1 + 0x148) + 0x10);

  iVar3 = (**(code **)(*plVar1 + 0xb0))(plVar1,1);

  if ((iVar3 == -0x7ff8ffe2) || (iVar3 == -0x7ffbfdfb)) {

    iVar3 = (**(code **)(**(longlong **)(*(longlong *)(param_1 + 0x148) + 0x10) + 0x38))();

    if (iVar3 < 0) goto LAB_140286857;

    plVar1 = *(longlong **)(*(longlong *)(param_1 + 0x148) + 0x10);

    iVar3 = (**(code **)(*plVar1 + 0xb0))(plVar1,1);

  }

  if (-1 < iVar3) {

    plVar1 = *(longlong **)(*(longlong *)(param_1 + 0x148) + 0x10);

    iVar3 = (**(code **)(*plVar1 + 0xb0))(plVar1,0x10);

    if (iVar3 < 0) {

      uVar4 = FUN_140286ef0("IDirectInputDevice8::SendForceFeedbackCommand(DISFFC_SETACTUATORSON)",

                            iVar3);

      return uVar4;

    }

    lVar2 = *(longlong *)(param_1 + 0x148);

    uVar4 = FUN_140285980(param_2);

    *(undefined8 *)(lVar2 + 0xc58) = uVar4;

    lVar2 = *(longlong *)(param_1 + 0x148);

    if (*(longlong *)(lVar2 + 0xc58) == 0) {

      return 0;

    }

    iVar3 = (**(code **)(**(longlong **)(lVar2 + 0x10) + 0x90))

                      (*(longlong **)(lVar2 + 0x10),&DAT_140350af0,*(longlong *)(lVar2 + 0xc58),

                       lVar2 + 0xc60,0);

    if (iVar3 < 0) {

      uVar4 = FUN_140286ef0("IDirectInputDevice8::CreateEffect",iVar3);

      return uVar4;

    }

    return 1;

  }

LAB_140286857:

  uVar4 = FUN_140286ef0("IDirectInputDevice8::SendForceFeedbackCommand(DISFFC_RESET)",iVar3);

  return uVar4;

}




