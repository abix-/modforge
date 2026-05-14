// Address: 0x1400dc2d0
// Ghidra name: FUN_1400dc2d0
// ============ 0x1400dc2d0 FUN_1400dc2d0 (size=183) ============


void FUN_1400dc2d0(longlong param_1)



{

  undefined *puVar1;

  undefined8 uVar2;

  longlong local_28 [3];

  ulonglong local_10;

  

  if (*(longlong *)(param_1 + 0x148) != 0) {

    puVar1 = (&PTR_s_My_House_14030ec3f_1_1403da9d0)[(longlong)*(int *)(param_1 + 600) * 10];

    FUN_1400cf970();

    uVar2 = FUN_14008d760(local_28,puVar1);

    FUN_1400c5580(param_1 + 0x18,uVar2);

    if (0xf < local_10) {

      if (0xfff < local_10 + 1) {

        if (0x1f < (local_28[0] - *(longlong *)(local_28[0] + -8)) - 8U) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

      }

      FUN_1402c7088();

    }

  }

  FUN_1400cdae0(param_1);

  return;

}




