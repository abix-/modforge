// Address: 0x140024730
// Ghidra name: FUN_140024730
// ============ 0x140024730 FUN_140024730 (size=232) ============


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */



undefined8 * FUN_140024730(undefined8 *param_1,longlong param_2,undefined8 *param_3)



{

  undefined8 *puVar1;

  undefined8 uVar2;

  longlong lVar3;

  undefined1 auStackY_88 [32];

  undefined8 *local_58;

  undefined8 uStack_50;

  longlong local_48 [8];

  

  local_48[4] = DAT_1403e8b00 ^ (ulonglong)auStackY_88;

  puVar1 = (undefined8 *)*param_3;

  uVar2 = param_3[1];

  local_48[0] = 0;

  local_48[1] = 0;

  local_48[2] = 0;

  local_48[3] = 0;

  lVar3 = -1;

  do {

    lVar3 = lVar3 + 1;

  } while (*(char *)(param_2 + lVar3) != '\0');

  local_58 = param_1;

  FUN_140027e30(local_48);

  local_58 = puVar1;

  uStack_50 = uVar2;

  FUN_140024220(param_1,&local_58);

  if (0xf < (ulonglong)local_48[3]) {

    if (0xfff < local_48[3] + 1U) {

      if (0x1f < (local_48[0] - *(longlong *)(local_48[0] + -8)) - 8U) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

    }

    FUN_1402c7088();

  }

  *param_1 = std::ios_base::failure::vftable;

  return param_1;

}




