// Address: 0x14017cc70
// Ghidra name: FUN_14017cc70
// ============ 0x14017cc70 FUN_14017cc70 (size=107) ============


undefined8 * FUN_14017cc70(LONG param_1)



{

  undefined8 *puVar1;

  HANDLE pvVar2;

  

  puVar1 = (undefined8 *)FUN_1401841f0(0x10);

  if (puVar1 != (undefined8 *)0x0) {

    pvVar2 = CreateSemaphoreW((LPSECURITY_ATTRIBUTES)0x0,param_1,0x8000,(LPCWSTR)0x0);

    *puVar1 = pvVar2;

    *(LONG *)(puVar1 + 1) = param_1;

    if (pvVar2 == (HANDLE)0x0) {

      FUN_14012e850("Couldn\'t create semaphore");

      FUN_1401841e0(puVar1);

      return (undefined8 *)0x0;

    }

  }

  return puVar1;

}




