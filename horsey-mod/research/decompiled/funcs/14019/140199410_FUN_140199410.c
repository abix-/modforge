// Address: 0x140199410
// Ghidra name: FUN_140199410
// ============ 0x140199410 FUN_140199410 (size=46) ============


void FUN_140199410(undefined8 *param_1,char param_2)



{

  if ((param_1 != (undefined8 *)0x0) && ((*(byte *)(param_1 + 0x202) & 2) != 0)) {

                    /* WARNING: Could not recover jumptable at 0x000140199436. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    CheckMenuItem(*(undefined8 *)*param_1,*(undefined4 *)(param_1 + 1),-(param_2 != '\0') & 8);

    return;

  }

  return;

}




