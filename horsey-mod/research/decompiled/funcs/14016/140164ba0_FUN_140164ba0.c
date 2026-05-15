// Address: 0x140164ba0
// Ghidra name: FUN_140164ba0
// ============ 0x140164ba0 FUN_140164ba0 (size=85) ============


void FUN_140164ba0(undefined1 *param_1,longlong param_2,int param_3,int param_4)



{

  longlong lVar1;

  longlong lVar2;

  longlong lVar3;

  

  if (0 < (longlong)param_4) {

    lVar3 = 0;

    do {

      lVar2 = 0;

      if (0 < (longlong)param_3) {

        do {

          lVar1 = lVar2 * 8;

          lVar2 = lVar2 + 1;

          *param_1 = *(undefined1 *)(lVar3 + *(longlong *)(param_2 + lVar1));

          param_1 = param_1 + 1;

        } while (lVar2 < param_3);

      }

      lVar3 = lVar3 + 1;

    } while (lVar3 < param_4);

  }

  return;

}




