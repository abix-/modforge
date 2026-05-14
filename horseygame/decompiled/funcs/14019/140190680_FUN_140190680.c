// Address: 0x140190680
// Ghidra name: FUN_140190680
// ============ 0x140190680 FUN_140190680 (size=154) ============


longlong FUN_140190680(undefined8 param_1,longlong param_2,ulonglong param_3,longlong param_4,

                      code *param_5,undefined8 param_6)



{

  int iVar1;

  ulonglong uVar2;

  longlong lVar3;

  

  do {

    while( true ) {

      if (param_3 == 0) {

        return 0;

      }

      uVar2 = param_3 >> 1;

      lVar3 = uVar2 * param_4 + param_2;

      iVar1 = (*param_5)(param_6,param_1,lVar3);

      if (iVar1 < 1) break;

      param_2 = lVar3 + param_4;

      param_3 = (uVar2 - 1) + (ulonglong)((uint)param_3 & 1);

    }

    param_3 = uVar2;

  } while (iVar1 != 0);

  return lVar3;

}




