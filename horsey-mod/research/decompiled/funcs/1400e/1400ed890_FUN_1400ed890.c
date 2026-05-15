// Address: 0x1400ed890
// Ghidra name: FUN_1400ed890
// ============ 0x1400ed890 FUN_1400ed890 (size=65) ============


void FUN_1400ed890(longlong param_1,int param_2)



{

  int iVar1;

  

  if (*(longlong *)(param_1 + 0x10) != 0) {

    iVar1 = *(int *)(param_1 + 0xc0) - *(int *)(param_1 + 0xb8);

    if (iVar1 < param_2) {

      *(undefined8 *)(param_1 + 0xb8) = *(undefined8 *)(param_1 + 0xc0);

                    /* WARNING: Could not recover jumptable at 0x0001400ed8c3. Too many branches */

                    /* WARNING: Treating indirect jump as call */

      (**(code **)(param_1 + 0x18))(*(undefined8 *)(param_1 + 0x28),param_2 - iVar1);

      return;

    }

  }

  *(longlong *)(param_1 + 0xb8) = *(longlong *)(param_1 + 0xb8) + (longlong)param_2;

  return;

}




