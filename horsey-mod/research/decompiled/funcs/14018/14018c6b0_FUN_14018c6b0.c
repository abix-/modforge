// Address: 0x14018c6b0
// Ghidra name: FUN_14018c6b0
// ============ 0x14018c6b0 FUN_14018c6b0 (size=361) ============


void FUN_14018c6b0(undefined8 param_1,longlong param_2,undefined4 param_3,ushort *param_4)



{

  int iVar1;

  UINT UVar2;

  longlong lVar3;

  ulonglong uVar4;

  ulonglong uVar5;

  ushort uVar6;

  ushort uVar7;

  undefined4 uVar8;

  byte bVar9;

  

  if (*(char *)(param_2 + 0x129) == '\0') {

    return;

  }

  if ((param_4[1] & 4) != 0) {

    *(undefined1 *)(param_2 + 300) = 1;

    return;

  }

  if (((param_4[1] & 2) != 0) && (*param_4 == 0x2a)) {

    return;

  }

  uVar5 = (ulonglong)*param_4;

  if (*param_4 == 0) {

    iVar1 = FUN_1401a99d0();

    UVar2 = 4;

    if (iVar1 != 0) {

      UVar2 = 0;

    }

    UVar2 = MapVirtualKeyW((uint)param_4[3],UVar2);

    uVar5 = (ulonglong)UVar2;

    *param_4 = (ushort)UVar2;

    if ((ushort)UVar2 == 0) {

      return;

    }

  }

  uVar7 = (ushort)uVar5;

  bVar9 = ~(byte)param_4[1] & 1;

  if (*(char *)(param_2 + 300) == '\0') {

    uVar6 = param_4[1] & 2;

    if (uVar6 != 0) {

      uVar7 = uVar7 | 0xe000;

    }

    uVar4 = (ulonglong)(byte)((byte)uVar5 | 0x80);

    if (uVar6 == 0) {

      uVar4 = uVar5 & 0xff;

    }

    uVar6 = uVar7;

    uVar8 = *(undefined4 *)(&DAT_140339bd0 + uVar4 * 4);

  }

  else {

    uVar6 = uVar7 | 0xe100;

    *(undefined1 *)(param_2 + 300) = 0;

    uVar8 = 0x48;

    if (uVar7 != 0x45) {

      uVar8 = 0;

    }

  }

  if (bVar9 != 0) {

    lVar3 = FUN_140183290();

    if (*(char *)(param_2 + 299) == '\0') {

      if (lVar3 == 0) {

        return;

      }

    }

    else if (lVar3 == 0) goto LAB_14018c7e4;

    if (*(char *)(lVar3 + 0x138) != '\0') {

      return;

    }

  }

LAB_14018c7e4:

  FUN_140183990(param_1,param_3,uVar6,uVar8,bVar9);

  return;

}




