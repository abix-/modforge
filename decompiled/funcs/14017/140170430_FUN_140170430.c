// Address: 0x140170430
// Ghidra name: FUN_140170430
// ============ 0x140170430 FUN_140170430 (size=102) ============


void FUN_140170430(int *param_1,float param_2)



{

  longlong lVar1;

  

  if (param_2 != (float)param_1[0x16]) {

    param_1[0x16] = (int)param_2;

    FUN_14021a690(param_1,0x157,0,0);

    for (lVar1 = *(longlong *)(DAT_1403fc410 + 0x348); lVar1 != 0;

        lVar1 = *(longlong *)(lVar1 + 0x1a0)) {

      if (*param_1 == *(int *)(lVar1 + 100)) {

        FUN_14016a4b0(lVar1);

      }

    }

  }

  return;

}




