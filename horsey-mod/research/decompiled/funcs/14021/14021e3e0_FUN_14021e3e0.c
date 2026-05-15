// Address: 0x14021e3e0
// Ghidra name: FUN_14021e3e0
// ============ 0x14021e3e0 FUN_14021e3e0 (size=164) ============


void FUN_14021e3e0(longlong param_1)



{

  undefined8 *puVar1;

  longlong lVar2;

  

  puVar1 = *(undefined8 **)(param_1 + 0x10);

  lVar2 = FUN_140174d30(*(undefined4 *)(param_1 + 8),"SDL.process.stdin",0);

  if (lVar2 != 0) {

    FUN_14012bd50(lVar2);

  }

  lVar2 = FUN_140174d30(*(undefined4 *)(param_1 + 8),"SDL.process.stderr",0);

  if (lVar2 != 0) {

    FUN_14012bd50(lVar2);

  }

  lVar2 = FUN_140174d30(*(undefined4 *)(param_1 + 8),"SDL.process.stdout",0);

  if (lVar2 != 0) {

    FUN_14012bd50(lVar2);

  }

  if (puVar1 != (undefined8 *)0x0) {

    if ((HANDLE)puVar1[1] != (HANDLE)0xffffffffffffffff) {

      CloseHandle((HANDLE)puVar1[1]);

    }

    if ((HANDLE)*puVar1 != (HANDLE)0xffffffffffffffff) {

      CloseHandle((HANDLE)*puVar1);

    }

  }

  FUN_1401841e0(puVar1);

  return;

}




