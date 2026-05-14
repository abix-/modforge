// Address: 0x140164c00
// Ghidra name: FUN_140164c00
// ============ 0x140164c00 FUN_140164c00 (size=125) ============


void FUN_140164c00(undefined2 *param_1,longlong *param_2,uint param_3,int param_4,undefined2 param_5

                  )



{

  longlong *plVar1;

  undefined2 uVar2;

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

            uVar2 = *(undefined2 *)(*plVar1 + lVar4 * 2);

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




