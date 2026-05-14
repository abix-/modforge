// Address: 0x1402e6114
// Ghidra name: FUN_1402e6114
// ============ 0x1402e6114 FUN_1402e6114 (size=145) ============


/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */



undefined8 FUN_1402e6114(int param_1)



{

  ulonglong uVar1;

  byte bVar2;

  ulonglong *puVar3;

  code *pcVar4;

  undefined8 uVar5;

  

  __acrt_lock(3);

  if (param_1 == 0) {

    puVar3 = &DAT_1403fed40;

    uVar5 = 2;

    uVar1 = DAT_1403fed40;

  }

  else {

    puVar3 = &DAT_1403fed48;

    uVar5 = 0x15;

    uVar1 = DAT_1403fed48;

  }

  bVar2 = (byte)DAT_1403e8b00 & 0x3f;

  pcVar4 = (code *)((DAT_1403e8b00 ^ uVar1) >> bVar2 | (DAT_1403e8b00 ^ uVar1) << 0x40 - bVar2);

  if ((code *)0x1 < pcVar4) {

    *puVar3 = DAT_1403e8b00;

  }

  __acrt_unlock(3);

  if (pcVar4 == (code *)0x0) {

    uVar5 = 0;

  }

  else {

    if (pcVar4 != (code *)0x1) {

      (*pcVar4)(uVar5);

    }

    uVar5 = 1;

  }

  return uVar5;

}




