// Address: 0x1402d9fac
// Ghidra name: FUN_1402d9fac
// ============ 0x1402d9fac FUN_1402d9fac (size=186) ============


/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */



void FUN_1402d9fac(undefined8 *param_1)



{

  byte bVar1;

  undefined *puVar2;

  

  if (DAT_1403fed20 != '\0') {

    return;

  }

  LOCK();

  DAT_1403fed10 = 1;

  UNLOCK();

  if (*(int *)*param_1 == 0) {

    if (DAT_1403fed18 != DAT_1403e8b00) {

      bVar1 = (byte)DAT_1403e8b00 & 0x3f;

      (*(code *)((DAT_1403e8b00 ^ DAT_1403fed18) >> bVar1 |

                (DAT_1403e8b00 ^ DAT_1403fed18) << 0x40 - bVar1))(0,0,0);

    }

    puVar2 = &DAT_1403ff0f8;

  }

  else {

    if (*(int *)*param_1 != 1) goto LAB_1402da01b;

    puVar2 = &DAT_1403ff110;

  }

  FUN_1402e7b08(puVar2);

LAB_1402da01b:

  if (*(int *)*param_1 == 0) {

    FUN_1402e7e48(&DAT_1403030e0,&DAT_140303100);

  }

  FUN_1402e7e48(&DAT_140303108,&DAT_140303110);

  if (*(int *)param_1[1] == 0) {

    DAT_1403fed20 = '\x01';

    *(undefined1 *)param_1[2] = 1;

  }

  return;

}




