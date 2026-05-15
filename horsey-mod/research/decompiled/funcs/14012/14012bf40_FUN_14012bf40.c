// Address: 0x14012bf40
// Ghidra name: FUN_14012bf40
// ============ 0x14012bf40 FUN_14012bf40 (size=319) ============


longlong FUN_14012bf40(longlong param_1,longlong param_2)



{

  int iVar1;

  longlong *plVar2;

  longlong lVar3;

  undefined8 local_48;

  undefined1 *local_40;

  code *local_38;

  code *local_30;

  undefined8 local_28;

  undefined8 uStack_20;

  code *local_18;

  

  if ((param_2 != 0) && (param_1 == 0)) {

    FUN_14012e850("Parameter \'%s\' is invalid",&DAT_1403140c4);

    return 0;

  }

  plVar2 = (longlong *)FUN_1401841a0(1,0x20);

  if (plVar2 != (longlong *)0x0) {

    local_40 = &LAB_14012d160;

    local_48 = 0x38;

    local_38 = FUN_14012d100;

    *plVar2 = param_1;

    local_30 = FUN_14012d0b0;

    plVar2[1] = param_1;

    local_18 = FUN_14012d020;

    plVar2[2] = param_1 + param_2;

    local_28 = 0;

    uStack_20 = 0;

    lVar3 = FUN_14012c690(&local_48,plVar2);

    if (lVar3 == 0) {

      FUN_1401841e0(plVar2);

    }

    else {

      iVar1 = FUN_14012be20(lVar3);

      if (iVar1 != 0) {

        *(int *)(plVar2 + 3) = iVar1;

        FUN_140175480(iVar1,"SDL.iostream.memory.base",param_1);

        FUN_140175360(iVar1,"SDL.iostream.memory.size",param_2);

      }

    }

    return lVar3;

  }

  return 0;

}




