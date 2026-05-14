// Address: 0x1402f57c0
// Ghidra name: FUN_1402f57c0
// ============ 0x1402f57c0 FUN_1402f57c0 (size=132) ============


ulonglong FUN_1402f57c0(byte *param_1,byte *param_2,ulonglong param_3)



{

  byte bVar1;

  byte bVar2;

  ulonglong uVar3;

  uint uVar4;

  uint uVar5;

  

  if (DAT_1403ff13c != 0) {

    uVar3 = FUN_1402f5850();

    return uVar3;

  }

  if (((param_1 != (byte *)0x0) && (param_2 != (byte *)0x0)) && (param_3 < 0x80000000)) {

    if (param_3 == 0) {

      return 0;

    }

    while( true ) {

      bVar1 = *param_1;

      uVar4 = (uint)bVar1;

      param_1 = param_1 + 1;

      bVar2 = *param_2;

      uVar5 = (uint)bVar2;

      param_2 = param_2 + 1;

      if ((uint)bVar1 != (uint)bVar2) {

        uVar4 = bVar1 + 0x20;

        if (0x19 < bVar1 - 0x41) {

          uVar4 = (uint)bVar1;

        }

        if (bVar2 - 0x41 < 0x1a) {

          uVar5 = bVar2 + 0x20;

        }

      }

      uVar3 = (ulonglong)(uVar4 - uVar5);

      if ((uVar4 - uVar5 != 0) || (uVar4 == 0)) break;

      param_3 = param_3 - 1;

      if (param_3 == 0) {

        return uVar3;

      }

    }

    return uVar3;

  }

  uVar3 = FUN_1402f5780();

  return uVar3;

}




