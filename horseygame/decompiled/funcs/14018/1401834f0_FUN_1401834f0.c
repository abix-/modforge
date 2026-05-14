// Address: 0x1401834f0
// Ghidra name: FUN_1401834f0
// ============ 0x1401834f0 FUN_1401834f0 (size=194) ============


void FUN_1401834f0(longlong param_1,undefined8 param_2,undefined8 param_3,char *param_4)



{

  uint *puVar1;

  longlong lVar2;

  

  if ((param_4 != (char *)0x0) && (*param_4 != '\0')) {

    puVar1 = (uint *)(param_1 + 0x418);

    *puVar1 = 0;

    lVar2 = thunk_FUN_1402c9340(param_4,&DAT_140338bac);

    if (lVar2 == 0) {

      lVar2 = thunk_FUN_1402c9340(param_4,"hide_numpad");

      if (lVar2 != 0) {

        *puVar1 = *puVar1 | 1;

      }

      lVar2 = thunk_FUN_1402c9340(param_4,"french_numbers");

      if (lVar2 != 0) {

        *puVar1 = *puVar1 | 2;

      }

      lVar2 = thunk_FUN_1402c9340(param_4,"latin_letters");

      if (lVar2 != 0) {

        *(uint *)(param_1 + 0x418) = *(uint *)(param_1 + 0x418) | 4;

      }

    }

    return;

  }

  *(undefined4 *)(param_1 + 0x418) = 6;

  return;

}




