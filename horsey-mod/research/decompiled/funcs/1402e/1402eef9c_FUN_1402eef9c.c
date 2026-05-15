// Address: 0x1402eef9c
// Ghidra name: FUN_1402eef9c
// ============ 0x1402eef9c FUN_1402eef9c (size=915) ============


undefined8

FUN_1402eef9c(double *param_1,undefined1 *param_2,ulonglong param_3,undefined8 param_4,

             undefined8 param_5,uint param_6,byte param_7,undefined4 param_8,

             __acrt_rounding_mode param_9,longlong param_10)



{

  bool bVar1;

  ushort uVar2;

  undefined8 uVar3;

  char *pcVar4;

  char *pcVar5;

  longlong lVar6;

  longlong lVar7;

  char cVar8;

  short sVar9;

  short sVar10;

  char *pcVar11;

  uint uVar12;

  char *pcVar13;

  ulonglong uVar14;

  ulonglong uVar15;

  

  *param_2 = 0;

  uVar12 = 0;

  if (-1 < (int)param_6) {

    uVar12 = param_6;

  }

  if (param_3 <= (ulonglong)(longlong)(int)(uVar12 + 0xb)) {

    *(undefined1 *)(param_10 + 0x30) = 1;

    *(undefined4 *)(param_10 + 0x2c) = 0x22;

    FUN_1402cd39c(0,0,0,0,0,param_10);

    return 0x22;

  }

  if (((ulonglong)*param_1 >> 0x34 & 0x7ff) == 0x7ff) {

    uVar3 = FUN_1402ef330(param_1,param_2,param_3,param_4,param_5,uVar12,0,param_8,param_9,param_10)

    ;

    if ((int)uVar3 != 0) {

      *param_2 = 0;

      return uVar3;

    }

    pcVar4 = (char *)FUN_1402c9210(param_2,0x65);

    if (pcVar4 == (char *)0x0) {

      return 0;

    }

    *pcVar4 = (param_7 ^ 1) * ' ' + 'P';

    pcVar4[3] = '\0';

    return 0;

  }

  if ((longlong)*param_1 < 0) {

    *param_2 = 0x2d;

    param_2 = param_2 + 1;

  }

  pcVar4 = param_2 + 1;

  uVar15 = 0x3ff;

  sVar10 = (ushort)(param_7 ^ 1) * 0x20 + 7;

  if (((ulonglong)*param_1 & 0x7ff0000000000000) == 0) {

    *param_2 = 0x30;

    uVar15 = (ulonglong)(-(uint)(((ulonglong)*param_1 & 0xfffffffffffff) != 0) & 0x3fe);

  }

  else {

    *param_2 = 0x31;

  }

  pcVar11 = param_2 + 2;

  if (uVar12 == 0) {

    cVar8 = '\0';

  }

  else {

    if (*(char *)(param_10 + 0x28) == '\0') {

      FUN_1402d74e0(param_10);

    }

    cVar8 = *(char *)**(undefined8 **)(*(longlong *)(param_10 + 0x18) + 0xf8);

  }

  *pcVar4 = cVar8;

  if (((ulonglong)*param_1 & 0xfffffffffffff) != 0) {

    sVar9 = 0x30;

    uVar14 = 0xf000000000000;

    while (0 < (int)uVar12) {

      uVar2 = (short)(((ulonglong)*param_1 & uVar14) >> ((byte)sVar9 & 0x3f)) + 0x30;

      if (0x39 < uVar2) {

        uVar2 = uVar2 + sVar10;

      }

      *pcVar11 = (char)uVar2;

      uVar12 = uVar12 - 1;

      pcVar11 = pcVar11 + 1;

      uVar14 = uVar14 >> 4;

      sVar9 = sVar9 + -4;

      if (sVar9 < 0) goto LAB_1402ef1ee;

    }

    bVar1 = should_round_up(param_1,uVar14,sVar9,param_9);

    pcVar13 = pcVar11;

    if (!bVar1) goto LAB_1402ef214;

    while( true ) {

      pcVar5 = pcVar13 + -1;

      cVar8 = *pcVar5;

      if ((cVar8 + 0xbaU & 0xdf) != 0) break;

      *pcVar5 = '0';

      pcVar13 = pcVar5;

    }

    if (pcVar5 == pcVar4) {

      pcVar13[-2] = pcVar13[-2] + '\x01';

    }

    else {

      if (cVar8 == '9') {

        cVar8 = (char)sVar10 + '9';

      }

      *pcVar5 = cVar8 + '\x01';

    }

  }

LAB_1402ef1ee:

  if (0 < (int)uVar12) {

    FUN_1402f94c0(pcVar11,0x30,uVar12);

    pcVar11 = pcVar11 + uVar12;

  }

LAB_1402ef214:

  if (*pcVar4 == '\0') {

    pcVar11 = pcVar4;

  }

  *pcVar11 = (param_7 ^ 1) * ' ' + 'P';

  pcVar4 = pcVar11 + 2;

  uVar12 = (uint)((ulonglong)*param_1 >> 0x34) & 0x7ff;

  lVar6 = uVar12 - uVar15;

  lVar7 = lVar6;

  if (lVar6 < 0) {

    lVar7 = uVar15 - uVar12;

  }

  cVar8 = '+';

  if (lVar6 < 0) {

    cVar8 = '-';

  }

  pcVar11[1] = cVar8;

  *pcVar4 = '0';

  pcVar13 = pcVar4;

  if (lVar7 < 1000) {

LAB_1402ef29b:

    if (99 < lVar7) goto LAB_1402ef2a1;

LAB_1402ef2d4:

    if (lVar7 < 10) goto LAB_1402ef305;

  }

  else {

    pcVar13 = pcVar11 + 3;

    *pcVar4 = (char)(lVar7 / 1000) + '0';

    lVar7 = lVar7 % 1000;

    if (pcVar13 == pcVar4) goto LAB_1402ef29b;

LAB_1402ef2a1:

    lVar6 = SUB168(SEXT816(-0x5c28f5c28f5c28f5) * SEXT816(lVar7),8) + lVar7;

    lVar6 = (lVar6 >> 6) - (lVar6 >> 0x3f);

    *pcVar13 = (char)lVar6 + '0';

    pcVar13 = pcVar13 + 1;

    lVar7 = lVar7 + lVar6 * -100;

    if (pcVar13 == pcVar4) goto LAB_1402ef2d4;

  }

  *pcVar13 = (char)(lVar7 / 10) + '0';

  pcVar13 = pcVar13 + 1;

  lVar7 = lVar7 % 10;

LAB_1402ef305:

  *pcVar13 = (char)lVar7 + '0';

  pcVar13[1] = '\0';

  return 0;

}




