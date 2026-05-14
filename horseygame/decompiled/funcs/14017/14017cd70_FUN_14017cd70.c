// Address: 0x14017cd70
// Ghidra name: FUN_14017cd70
// ============ 0x14017cd70 FUN_14017cd70 (size=48) ============


void FUN_14017cd70(undefined8 *param_1)



{

  BOOL BVar1;

  

  if (param_1 != (undefined8 *)0x0) {

    LOCK();

    *(int *)(param_1 + 1) = *(int *)(param_1 + 1) + 1;

    UNLOCK();

    BVar1 = ReleaseSemaphore((HANDLE)*param_1,1,(LPLONG)0x0);

    if (BVar1 == 0) {

      LOCK();

      *(int *)(param_1 + 1) = *(int *)(param_1 + 1) + -1;

      UNLOCK();

    }

  }

  return;

}




