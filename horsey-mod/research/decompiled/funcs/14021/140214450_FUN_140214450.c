// Address: 0x140214450
// Ghidra name: FUN_140214450
// ============ 0x140214450 FUN_140214450 (size=289) ============


void FUN_140214450(int param_1,longlong param_2,int param_3,longlong param_4,uint param_5,

                  longlong param_6,ulonglong *param_7)



{

  code *pcVar1;

  float fVar2;

  ulonglong uVar3;

  ulonglong uVar4;

  ulonglong uVar5;

  

  fVar2 = DAT_1403539b0;

  uVar4 = *param_7;

  pcVar1 = *(code **)(&DAT_1403fda48 + (longlong)param_1 * 8);

  if (0 < (int)param_5) {

    uVar5 = (ulonglong)param_5;

    uVar3 = uVar4;

    do {

      uVar4 = uVar3 + param_6;

      (*pcVar1)(param_2 + (longlong)(param_1 * 5) * -4 +

                (longlong)((int)(uVar3 >> 0x20) * param_1) * 4,param_4,

                &DAT_1403fd450 + ((uVar3 & 0xffffffff) >> 0x1d) * 0xc0,

                (float)((uint)uVar3 & 0x1fffffff) * fVar2,param_1);

      param_4 = param_4 + (longlong)param_1 * 4;

      uVar5 = uVar5 - 1;

      uVar3 = uVar4;

    } while (uVar5 != 0);

  }

  *param_7 = uVar4 - ((longlong)param_3 << 0x20);

  return;

}




