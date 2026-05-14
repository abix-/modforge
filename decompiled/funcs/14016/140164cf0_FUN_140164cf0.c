// Address: 0x140164cf0
// Ghidra name: FUN_140164cf0
// ============ 0x140164cf0 FUN_140164cf0 (size=123) ============


void FUN_140164cf0(undefined1 *param_1,longlong *param_2,uint param_3,int param_4,undefined1 param_5

                  )



{

  longlong *plVar1;

  undefined1 uVar2;

  ulonglong uVar3;

  longlong lVar4;

  

  if (0 < param_4) {

    lVar4 = 0;

    do {

      plVar1 = param_2;

      uVar3 = (ulonglong)param_3;

      if (0 < (int)param_3) {

        do {

          uVar2 = param_5;

          if (*plVar1 != 0) {

            uVar2 = *(undefined1 *)(*plVar1 + lVar4);

          }

          *param_1 = uVar2;

          param_1 = param_1 + 1;

          uVar3 = uVar3 - 1;

          plVar1 = plVar1 + 1;

        } while (uVar3 != 0);

      }

      lVar4 = lVar4 + 1;

    } while (lVar4 < param_4);

  }

  return;

}




