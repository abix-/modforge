// Address: 0x1400bf7f0
// Ghidra name: FUN_1400bf7f0
// ============ 0x1400bf7f0 FUN_1400bf7f0 (size=376) ============


void FUN_1400bf7f0(longlong *param_1,longlong param_2,char *param_3)



{

  longlong lVar1;

  char cVar2;

  ulonglong uVar3;

  uint uVar4;

  uint *puVar5;

  uint *puVar6;

  uint uVar7;

  uint uVar8;

  longlong local_18 [2];

  

  local_18[0] = *param_1;

  if (local_18[0] != param_1[1]) {

    param_1[1] = local_18[0];

  }

  param_1[3] = 0;

  local_18[1] = 0;

  uVar3 = FUN_1400bf3c0(param_1,local_18,param_2);

  if (((longlong)uVar3 < 0) && (uVar3 != 0)) {

    lVar1 = -((~uVar3 >> 5) * 4 + 4);

  }

  else {

    lVar1 = (uVar3 >> 5) * 4;

  }

  puVar5 = (uint *)(*param_1 + lVar1);

  uVar4 = (uint)uVar3 & 0x1f;

  uVar3 = (ulonglong)uVar4;

  if (param_2 != 0) {

    if ((param_2 < 0) && (uVar3 < (ulonglong)-param_2)) {

      lVar1 = -((~(uVar3 + param_2) >> 5) * 4 + 4);

    }

    else {

      lVar1 = (uVar3 + param_2 >> 5) * 4;

    }

    puVar6 = (uint *)((longlong)puVar5 + lVar1);

    cVar2 = *param_3;

    uVar7 = uVar4 + (int)param_2 & 0x1f;

    if ((puVar5 != puVar6) || (uVar3 != uVar7)) {

      uVar8 = -1 << (sbyte)uVar4;

      uVar4 = -(uint)(cVar2 != '\0');

      if (puVar5 == puVar6) {

        uVar7 = 0xffffffff >> (0x20U - (char)uVar7 & 0x1f);

        *puVar5 = (~uVar7 | ~uVar8) & *puVar5 | uVar7 & uVar8 & uVar4;

      }

      else {

        *puVar5 = *puVar5 & ~uVar8 | uVar8 & uVar4;

        FUN_1402f94c0(puVar5 + 1,-(cVar2 != '\0'),(longlong)puVar6 - (longlong)(puVar5 + 1));

        if ((ulonglong)uVar7 != 0) {

          uVar7 = 0xffffffff >> (0x20U - (char)uVar7 & 0x1f);

          *puVar6 = ~uVar7 & *puVar6 | uVar7 & uVar4;

        }

      }

    }

  }

  return;

}




