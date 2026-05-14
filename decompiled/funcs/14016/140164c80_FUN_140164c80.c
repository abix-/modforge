// Address: 0x140164c80
// Ghidra name: FUN_140164c80
// ============ 0x140164c80 FUN_140164c80 (size=101) ============


void FUN_140164c80(undefined4 *param_1,longlong *param_2,uint param_3,int param_4,undefined4 param_5

                  )



{

  undefined4 uVar1;

  longlong *plVar2;

  ulonglong uVar3;

  longlong lVar4;

  

  if (0 < param_4) {

    lVar4 = 0;

    do {

      if (0 < (int)param_3) {

        uVar3 = (ulonglong)param_3;

        plVar2 = param_2;

        do {

          uVar1 = param_5;

          if (*plVar2 != 0) {

            uVar1 = *(undefined4 *)(*plVar2 + lVar4 * 4);

          }

          *param_1 = uVar1;

          plVar2 = plVar2 + 1;

          param_1 = param_1 + 1;

          uVar3 = uVar3 - 1;

        } while (uVar3 != 0);

      }

      lVar4 = lVar4 + 1;

    } while (lVar4 < param_4);

  }

  return;

}




