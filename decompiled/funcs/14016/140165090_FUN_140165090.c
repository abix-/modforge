// Address: 0x140165090
// Ghidra name: FUN_140165090
// ============ 0x140165090 FUN_140165090 (size=42) ============


undefined8 FUN_140165090(longlong param_1,int param_2)



{

  ulonglong uVar1;

  ulonglong uVar2;

  

  if (param_1 != 0) {

    uVar1 = 0;

    uVar2 = uVar1;

    if (0 < (longlong)param_2) {

      do {

        if (*(int *)(param_1 + uVar1 * 4) != (int)uVar2) {

          return 0;

        }

        uVar1 = uVar1 + 1;

        uVar2 = (ulonglong)((int)uVar2 + 1);

      } while ((longlong)uVar1 < (longlong)param_2);

    }

  }

  return 1;

}




