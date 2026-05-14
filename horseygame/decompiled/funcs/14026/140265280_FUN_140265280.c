// Address: 0x140265280
// Ghidra name: FUN_140265280
// ============ 0x140265280 FUN_140265280 (size=95) ============


ulonglong FUN_140265280(ulonglong param_1,longlong param_2,int param_3)



{

  byte bVar1;

  uint uVar2;

  byte bVar5;

  ulonglong uVar6;

  ulonglong uVar3;

  ulonglong uVar4;

  

  uVar4 = 0;

  uVar6 = uVar4;

  if (0 < param_3) {

    while( true ) {

      bVar1 = (byte)param_1;

      param_1 = param_1 >> 7;

      bVar1 = bVar1 & 0x7f;

      uVar2 = (int)uVar4 + 1;

      uVar4 = (ulonglong)uVar2;

      uVar3 = uVar4;

      bVar5 = bVar1 | 0x80;

      if (param_1 == 0) {

        bVar5 = bVar1;

      }

      *(byte *)(param_2 + uVar6) = bVar5;

      if (param_1 == 0) break;

      uVar6 = uVar6 + 1;

      uVar4 = (ulonglong)uVar2;

      if ((longlong)param_3 <= (longlong)uVar6) {

        return uVar3;

      }

    }

  }

  return uVar4;

}




