// Address: 0x140130fb0
// Ghidra name: FUN_140130fb0
// ============ 0x140130fb0 FUN_140130fb0 (size=268) ============


void FUN_140130fb0(longlong param_1)



{

  char cVar1;

  undefined4 *puVar2;

  undefined4 *puVar3;

  undefined4 local_18 [2];

  undefined4 *local_10;

  

  if (param_1 != 0) {

    local_10 = (undefined4 *)0x0;

    FUN_140130b40();

    cVar1 = FUN_140138fc0(param_1 + 0x1bc,0,1);

    if (cVar1 == '\0') {

      FUN_140130b70(param_1);

    }

    else {

      *(undefined8 *)(param_1 + 0x88) = 0;

      *(code **)(param_1 + 0x18) = FUN_140132720;

      *(undefined8 *)(param_1 + 0x80) = 0;

      *(code **)(param_1 + 0x20) = FUN_140132550;

      *(undefined1 **)(param_1 + 0x28) = &LAB_140132700;

      puVar2 = (undefined4 *)FUN_1401841f0(0x10);

      puVar3 = local_18;

      if (puVar2 != (undefined4 *)0x0) {

        *puVar2 = 0x1401;

        puVar2[1] = *(undefined4 *)(param_1 + 0x6c);

        *(undefined8 *)(puVar2 + 2) = 0;

        puVar3 = puVar2;

        local_10 = puVar2;

      }

      FUN_1401324e0(param_1);

      FUN_140130b70(param_1);

      if (local_10 != (undefined4 *)0x0) {

        FUN_14017cab0(DAT_1403fb628);

        *(undefined4 **)((longlong)DAT_1403fb648 + 8) = local_10;

        DAT_1403fb648 = puVar3;

        FUN_14017cae0(DAT_1403fb628);

        return;

      }

    }

  }

  return;

}




