// Address: 0x14019a0a0
// Ghidra name: FUN_14019a0a0
// ============ 0x14019a0a0 FUN_14019a0a0 (size=125) ============


void FUN_14019a0a0(int param_1,uint param_2,longlong *param_3,uint *param_4,int *param_5,

                  int *param_6)



{

  uint uVar1;

  longlong lVar2;

  ulonglong uVar3;

  

  uVar1 = (uint)(param_1 << 0x10) / param_2;

  lVar2 = (longlong)((int)((ulonglong)(((longlong)(int)uVar1 + 1) * 0x8000) >> 0x10) + -0x8000);

  *param_3 = lVar2;

  *param_4 = uVar1;

  *param_5 = 0;

  *param_6 = 0;

  if (0 < (int)param_2) {

    uVar3 = (ulonglong)param_2;

    do {

      if (lVar2 < 0) {

        *param_5 = *param_5 + 1;

      }

      else if (param_1 + -2 < (int)((uint)((ulonglong)lVar2 >> 0x10) & 0xffff)) {

        *param_6 = *param_6 + 1;

      }

      lVar2 = lVar2 + (int)uVar1;

      uVar3 = uVar3 - 1;

    } while (uVar3 != 0);

  }

  return;

}




