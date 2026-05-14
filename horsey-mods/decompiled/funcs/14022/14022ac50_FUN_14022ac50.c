// Address: 0x14022ac50
// Ghidra name: FUN_14022ac50
// ============ 0x14022ac50 FUN_14022ac50 (size=386) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined8 FUN_14022ac50(undefined8 param_1,longlong param_2)



{

  longlong lVar1;

  int iVar2;

  longlong *plVar3;

  undefined8 uVar4;

  longlong lVar5;

  float fVar6;

  

  lVar1 = *(longlong *)(param_2 + 0x188);

  if ((*(char *)(lVar1 + 0xbc) != '\0') &&

     ((*(int *)(param_2 + 0x170) != 0 || (*(longlong *)(*(longlong *)(lVar1 + 0xc0) + 0x390) != 0)))

     ) {

    plVar3 = (longlong *)FUN_140229db0(param_2);

    if (plVar3 == (longlong *)0x0) {

      return 0;

    }

    iVar2 = *(int *)(param_2 + 0x170);

    if (iVar2 == 0) {

      uVar4 = 0;

    }

    else if (iVar2 == 1) {

      uVar4 = 1;

    }

    else if (iVar2 == 2) {

      uVar4 = 2;

    }

    else if (iVar2 == 3) {

      uVar4 = 8;

    }

    else {

      if (iVar2 != 4) {

        uVar4 = FUN_14012e850("Parameter \'state\' is not supported");

        return uVar4;

      }

      uVar4 = 4;

    }

    iVar2 = (**(code **)(*plVar3 + 0x50))(plVar3,*(undefined8 *)(lVar1 + 8),uVar4);

    if (iVar2 < 0) {

      uVar4 = FUN_1401a9ef0("ITaskbarList3::SetProgressState()",iVar2);

      return uVar4;

    }

    if (1 < *(int *)(param_2 + 0x170)) {

      lVar5 = 0;

      fVar6 = *(float *)(param_2 + 0x174) * DAT_14030dc08;

      if ((_DAT_140357984 <= fVar6) && (fVar6 = fVar6 - _DAT_140357984, fVar6 < _DAT_140357984)) {

        lVar5 = -0x8000000000000000;

      }

      iVar2 = (**(code **)(*plVar3 + 0x48))

                        (plVar3,*(undefined8 *)(lVar1 + 8),(longlong)fVar6 + lVar5,10000);

      if (iVar2 < 0) {

        uVar4 = FUN_1401a9ef0("ITaskbarList3::SetProgressValue()",iVar2);

        return uVar4;

      }

    }

  }

  return 1;

}




