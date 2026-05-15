// Address: 0x140180060
// Ghidra name: FUN_140180060
// ============ 0x140180060 FUN_140180060 (size=85) ============


undefined8 FUN_140180060(int param_1)



{

  BOOL BVar1;

  HANDLE hThread;

  undefined4 extraout_var;

  undefined8 uVar2;

  int nPriority;

  

  if (param_1 == 0) {

    nPriority = -2;

  }

  else if (param_1 == 2) {

    nPriority = 2;

  }

  else {

    nPriority = 0;

    if (param_1 == 3) {

      nPriority = 0xf;

    }

  }

  hThread = GetCurrentThread();

  BVar1 = SetThreadPriority(hThread,nPriority);

  if (BVar1 == 0) {

    uVar2 = FUN_1401a9ed0("SetThreadPriority()");

    return uVar2;

  }

  return CONCAT71((int7)(CONCAT44(extraout_var,BVar1) >> 8),1);

}




