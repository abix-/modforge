// Address: 0x1402eee84
// Ghidra name: FUN_1402eee84
// ============ 0x1402eee84 FUN_1402eee84 (size=61) ============


void FUN_1402eee84(char param_1,undefined8 *param_2,undefined8 param_3)



{

  if ((param_1 != '\0') && ((*(uint *)((longlong)param_2 + 0x14) >> 9 & 1) != 0)) {

    FUN_1402e1948(param_2,param_3);

    LOCK();

    *(uint *)((longlong)param_2 + 0x14) = *(uint *)((longlong)param_2 + 0x14) & 0xfffffd7f;

    UNLOCK();

    *(undefined4 *)(param_2 + 4) = 0;

    param_2[1] = 0;

    *param_2 = 0;

  }

  return;

}




