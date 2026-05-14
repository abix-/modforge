// Address: 0x1401a5050
// Ghidra name: FUN_1401a5050
// ============ 0x1401a5050 FUN_1401a5050 (size=205) ============


undefined8 FUN_1401a5050(longlong param_1,undefined8 param_2,uint param_3)



{

  undefined8 uVar1;

  longlong lVar2;

  uint uVar3;

  uint uVar4;

  

  *(undefined8 *)(param_1 + 0x20) = param_2;

  if (*(int *)(param_1 + 0x38) == 0) {

    uVar1 = FUN_14019f050("Corrupt PNG");

    return uVar1;

  }

  uVar4 = (int)param_2 - *(int *)(param_1 + 0x28);

  uVar3 = *(int *)(param_1 + 0x30) - *(int *)(param_1 + 0x28);

  if (param_3 <= ~uVar4) {

    while( true ) {

      if (uVar4 + param_3 <= uVar3) {

        lVar2 = FUN_140184230(*(undefined8 *)(param_1 + 0x28),uVar3);

        if (lVar2 != 0) {

          *(longlong *)(param_1 + 0x28) = lVar2;

          *(ulonglong *)(param_1 + 0x20) = (ulonglong)uVar4 + lVar2;

          *(ulonglong *)(param_1 + 0x30) = (ulonglong)uVar3 + lVar2;

          return 1;

        }

        uVar1 = FUN_14019f050("Out of memory");

        return uVar1;

      }

      if (0x7fffffff < uVar3) break;

      uVar3 = uVar3 * 2;

    }

  }

  uVar1 = FUN_14019f050("Out of memory");

  return uVar1;

}




