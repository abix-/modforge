// Address: 0x140104df0
// Ghidra name: FUN_140104df0
// ============ 0x140104df0 FUN_140104df0 (size=260) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_140104df0(longlong param_1,int param_2)



{

  undefined8 local_28;

  undefined8 uStack_20;

  undefined8 local_18;

  ulonglong uStack_10;

  

  if (param_2 == 0x19) {

    *(undefined4 *)(*(longlong *)(param_1 + 0x300) + 0xa8) = 0x78;

  }

  else if (param_2 == 0x17) {

    *(undefined4 *)(*(longlong *)(param_1 + 0x300) + 0xa0) = 0x78;

  }

  else if (param_2 == 0x18) {

    *(undefined4 *)(*(longlong *)(param_1 + 0x300) + 0xa4) = 0x78;

  }

  if ((*(int *)(*(longlong *)(param_1 + 0x300) + 0xa0) != 0) &&

     (*(int *)(*(longlong *)(param_1 + 0x300) + 0xa4) != 0)) {

    uStack_20 = 0;

    local_18 = _DAT_140304080;

    uStack_10 = _UNK_140304088;

    local_28 = (ulonglong)CONCAT14(s_truck_1403044e4[4],s_truck_1403044e4._0_4_);

    FUN_140037710(&local_28);

    if (0xf < uStack_10) {

      if (0xfff < uStack_10 + 1) {

        if (0x1f < (local_28 - *(longlong *)(local_28 - 8)) - 8) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

      }

      FUN_1402c7088();

    }

  }

  *(undefined4 *)(param_1 + 0x268) = 0;

  return;

}




