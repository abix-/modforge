// Address: 0x1402e7d80
// Ghidra name: FUN_1402e7d80
// ============ 0x1402e7d80 FUN_1402e7d80 (size=47) ============


/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */



undefined8 FUN_1402e7d80(undefined8 param_1)



{

  undefined8 uVar1;

  byte bVar2;

  code *pcVar3;

  

  bVar2 = (byte)DAT_1403e8b00 & 0x3f;

  pcVar3 = (code *)((DAT_1403ff130 ^ DAT_1403e8b00) >> bVar2 |

                   (DAT_1403ff130 ^ DAT_1403e8b00) << 0x40 - bVar2);

  if (pcVar3 == (code *)0x0) {

    return 0;

  }

  uVar1 = (*pcVar3)(param_1);

  return uVar1;

}




