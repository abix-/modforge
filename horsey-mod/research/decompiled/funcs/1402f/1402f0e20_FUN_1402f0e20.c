// Address: 0x1402f0e20
// Ghidra name: FUN_1402f0e20
// ============ 0x1402f0e20 FUN_1402f0e20 (size=211) ============


undefined8

FUN_1402f0e20(ulonglong param_1,short *param_2,ulonglong param_3,uint param_4,char param_5)



{

  short *psVar1;

  short sVar2;

  ulonglong uVar3;

  undefined4 *puVar4;

  undefined8 uVar5;

  ulonglong uVar6;

  short *psVar7;

  short *psVar8;

  

  psVar7 = param_2;

  if (param_5 != '\0') {

    *param_2 = 0x2d;

    psVar7 = param_2 + 1;

    param_1 = (ulonglong)(uint)-(int)param_1;

  }

  uVar6 = (ulonglong)(param_5 != '\0');

  psVar1 = psVar7;

  do {

    psVar8 = psVar1;

    uVar3 = param_1 & 0xffffffff;

    param_1 = uVar3 / param_4;

    uVar3 = uVar3 % (ulonglong)param_4;

    sVar2 = 0x57;

    if ((uint)uVar3 < 10) {

      sVar2 = 0x30;

    }

    uVar6 = uVar6 + 1;

    *psVar8 = sVar2 + (short)uVar3;

  } while (((int)param_1 != 0) && (psVar1 = psVar8 + 1, uVar6 < param_3));

  if (uVar6 < param_3) {

    psVar8[1] = 0;

    do {

      sVar2 = *psVar8;

      *psVar8 = *psVar7;

      psVar8 = psVar8 + -1;

      *psVar7 = sVar2;

      psVar7 = psVar7 + 1;

    } while (psVar7 < psVar8);

    uVar5 = 0;

  }

  else {

    *param_2 = 0;

    puVar4 = (undefined4 *)FUN_1402e68b0();

    *puVar4 = 0x22;

    FUN_1402cd454();

    uVar5 = 0x22;

  }

  return uVar5;

}




