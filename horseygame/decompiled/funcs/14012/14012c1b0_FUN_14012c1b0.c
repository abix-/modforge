// Address: 0x14012c1b0
// Ghidra name: FUN_14012c1b0
// ============ 0x14012c1b0 FUN_14012c1b0 (size=332) ============


longlong FUN_14012c1b0(HANDLE param_1,undefined8 param_2,char param_3)



{

  DWORD DVar1;

  int iVar2;

  undefined8 *puVar3;

  longlong lVar4;

  undefined4 local_48;

  undefined4 local_44;

  undefined4 uStack_40;

  undefined4 uStack_3c;

  undefined4 uStack_38;

  undefined4 uStack_34;

  code *local_30;

  code *local_28;

  code *local_20;

  code *local_18;

  

  puVar3 = (undefined8 *)FUN_1401841a0(1,0x28);

  if (puVar3 == (undefined8 *)0x0) {

    if (param_3 != '\0') {

      CloseHandle(param_1);

    }

    lVar4 = 0;

  }

  else {

    uStack_34 = 0;

    local_48 = 0x38;

    local_44 = 0;

    uStack_40 = 0;

    uStack_3c = 0;

    uStack_38 = 0;

    DVar1 = GetFileType(param_1);

    if (DVar1 == 1) {

      uStack_40 = 0x4012d610;

      uStack_3c = 1;

      uStack_38 = 0x4012d580;

      uStack_34 = 1;

    }

    *puVar3 = param_1;

    local_30 = FUN_14012d430;

    local_28 = FUN_14012d650;

    local_20 = FUN_14012d220;

    local_18 = FUN_14012d1e0;

    lVar4 = thunk_FUN_1402c9190(param_2,0x61);

    *(char *)((longlong)puVar3 + 0x21) = param_3;

    *(bool *)(puVar3 + 4) = lVar4 != 0;

    lVar4 = FUN_1401841f0(0x400);

    puVar3[1] = lVar4;

    if (lVar4 == 0) {

      FUN_14012d1e0(puVar3);

      lVar4 = 0;

    }

    else {

      lVar4 = FUN_14012c690(&local_48,puVar3);

      if (lVar4 == 0) {

        FUN_14012d1e0(puVar3);

      }

      else {

        iVar2 = FUN_14012be20(lVar4);

        if (iVar2 != 0) {

          FUN_140175480(iVar2,"SDL.iostream.windows.handle",*puVar3);

        }

      }

    }

  }

  return lVar4;

}




