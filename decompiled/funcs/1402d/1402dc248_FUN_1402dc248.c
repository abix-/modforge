// Address: 0x1402dc248
// Ghidra name: FUN_1402dc248
// ============ 0x1402dc248 FUN_1402dc248 (size=351) ============


void FUN_1402dc248(uint *param_1,uint param_2,undefined8 param_3,byte param_4,longlong param_5)



{

  sbyte sVar1;

  ulonglong uVar2;

  byte bVar3;

  uint uVar4;

  ulonglong uVar5;

  longlong lVar6;

  int iVar7;

  uint uVar8;

  uint uVar9;

  uint uVar10;

  

  uVar10 = 0;

  iVar7 = (-(uint)(*(char *)(param_5 + 8) != '\0') & 0x1d) + 0x17;

  if (param_2 < 0x41) {

    if (*param_1 == 0) {

      uVar5 = 0;

    }

    else {

      uVar5 = (ulonglong)param_1[1];

      uVar10 = 0;

      if (1 < *param_1) {

        uVar10 = param_1[2];

      }

    }

    param_4 = param_4 ^ 1;

    lVar6 = ((ulonglong)uVar10 << 0x20) + uVar5;

  }

  else {

    uVar9 = param_2 >> 5;

    uVar8 = uVar9 - 2;

    uVar10 = param_1[(ulonglong)uVar8 + 1];

    param_2 = param_2 & 0x1f;

    uVar5 = 0;

    if (param_2 == 0) {

      iVar7 = iVar7 + uVar8 * 0x20;

      lVar6 = CONCAT44(param_1[(ulonglong)(uVar9 - 1) + 1],uVar10);

      param_4 = param_4 ^ 1;

      uVar10 = 0;

      if (uVar8 != 0) {

        do {

          uVar5 = 0;

          if (param_1[(ulonglong)uVar10 + 1] == 0) {

            uVar5 = (ulonglong)param_4;

          }

          uVar10 = uVar10 + 1;

          param_4 = (byte)uVar5;

        } while (uVar10 != uVar8);

      }

    }

    else {

      sVar1 = (sbyte)param_2;

      iVar7 = uVar8 * 0x20 + param_2 + iVar7;

      uVar4 = (1 << sVar1) - 1;

      lVar6 = ((ulonglong)param_1[(ulonglong)(uVar9 - 1) + 1] << (-sVar1 + 0x20U & 0x3f)) +

              ((ulonglong)(param_1[(ulonglong)uVar9 + 1] & uVar4) << (-sVar1 + 0x40U & 0x3f)) +

              (ulonglong)((~uVar4 & uVar10) >> sVar1);

      if ((param_4 != 0) || (param_4 = 1, (uVar4 & uVar10) != 0)) {

        param_4 = 0;

      }

      uVar2 = 0;

      if (uVar8 != 0) {

        do {

          uVar5 = uVar2;

          bVar3 = 0;

          if (param_1[uVar5 + 1] == 0) {

            bVar3 = param_4;

          }

          param_4 = bVar3;

          uVar10 = (int)uVar5 + 1;

          uVar2 = (ulonglong)uVar10;

        } while (uVar10 != uVar8);

      }

    }

    param_3 = CONCAT71((int7)(uVar5 >> 8),(char)param_3);

  }

  FUN_1402dbe90(lVar6,iVar7,param_3,param_4);

  return;

}




