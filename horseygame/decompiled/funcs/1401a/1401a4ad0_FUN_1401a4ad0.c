// Address: 0x1401a4ad0
// Ghidra name: FUN_1401a4ad0
// ============ 0x1401a4ad0 FUN_1401a4ad0 (size=86) ============


void FUN_1401a4ad0(longlong param_1,int param_2)



{

  int iVar1;

  

  if (param_2 != 0) {

    if (param_2 < 0) {

      *(undefined8 *)(param_1 + 0xc0) = *(undefined8 *)(param_1 + 200);

      return;

    }

    if (*(longlong *)(param_1 + 0x10) != 0) {

      iVar1 = *(int *)(param_1 + 200) - *(int *)(param_1 + 0xc0);

      if (iVar1 < param_2) {

        *(undefined8 *)(param_1 + 0xc0) = *(undefined8 *)(param_1 + 200);

                    /* WARNING: Could not recover jumptable at 0x0001401a4b18. Too many branches */

                    /* WARNING: Treating indirect jump as call */

        (**(code **)(param_1 + 0x18))(*(undefined8 *)(param_1 + 0x28),param_2 - iVar1);

        return;

      }

    }

    *(longlong *)(param_1 + 0xc0) = *(longlong *)(param_1 + 0xc0) + (longlong)param_2;

  }

  return;

}




