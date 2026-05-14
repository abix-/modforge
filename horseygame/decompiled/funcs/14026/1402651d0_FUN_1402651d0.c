// Address: 0x1402651d0
// Ghidra name: FUN_1402651d0
// ============ 0x1402651d0 FUN_1402651d0 (size=169) ============


undefined8 FUN_1402651d0(undefined8 *param_1)



{

  ushort uVar1;

  undefined8 uVar3;

  undefined4 uVar4;

  ulonglong uVar2;

  

  uVar2 = *(ulonglong *)*param_1;

  if (*(short *)(uVar2 + 0x20) == 0x45e) {

    uVar1 = *(ushort *)(uVar2 + 0x22);

    uVar2 = (ulonglong)uVar1;

    if (uVar1 == 0x2e3) {

      *(undefined4 *)(param_1 + 0x29) = 1;

    }

    else if (uVar1 == 0xb00) {

      uVar1 = *(ushort *)((longlong)param_1 + 0x34);

      uVar2 = (ulonglong)uVar1;

      if (uVar1 == 4) {

        *(undefined4 *)(param_1 + 0x29) = 3;

      }

      else if (uVar1 == 5) {

        uVar1 = *(short *)((longlong)param_1 + 0x36) - 0xb;

        uVar2 = (ulonglong)uVar1;

        uVar4 = 4;

        if (uVar1 < 6) {

          uVar4 = 2;

        }

        *(undefined4 *)(param_1 + 0x29) = uVar4;

      }

    }

  }

  if (*(int *)(param_1 + 0x29) == 2) {

    uVar3 = FUN_140267ef0(param_1,0x4d,0,&DAT_14037e328,2);

    return uVar3;

  }

  return CONCAT71((int7)(uVar2 >> 8),1);

}




