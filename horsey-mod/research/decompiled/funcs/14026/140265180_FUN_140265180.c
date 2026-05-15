// Address: 0x140265180
// Ghidra name: FUN_140265180
// ============ 0x140265180 FUN_140265180 (size=78) ============


void FUN_140265180(ulonglong *param_1,byte *param_2,int param_3)



{

  byte bVar1;

  uint uVar2;

  ulonglong uVar3;

  ulonglong uVar4;

  ulonglong uVar5;

  

  uVar3 = 0;

  *param_1 = 0;

  uVar4 = uVar3;

  uVar5 = uVar3;

  if (0 < param_3) {

    do {

      bVar1 = *param_2;

      uVar5 = (ulonglong)(bVar1 & 0x7f) << ((byte)uVar4 & 0x3f) | uVar5;

      uVar2 = (int)uVar3 + 1;

      uVar3 = (ulonglong)uVar2;

      *param_1 = uVar5;

      if (-1 < (char)bVar1) {

        return;

      }

      param_2 = param_2 + 1;

      uVar4 = (ulonglong)((int)uVar4 + 7);

    } while ((int)uVar2 < param_3);

  }

  return;

}




