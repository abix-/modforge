// Address: 0x140188680
// Ghidra name: FUN_140188680
// ============ 0x140188680 FUN_140188680 (size=198) ============


bool FUN_140188680(longlong param_1,ulonglong param_2)



{

  ushort uVar1;

  int iVar2;

  undefined1 auVar3 [16];

  undefined1 auVar4 [16];

  undefined1 uVar5;

  ulonglong uVar6;

  ulonglong uVar7;

  longlong lVar8;

  ulonglong uVar9;

  ulonglong uVar10;

  

  uVar1 = *(ushort *)(param_1 + 0x24);

  uVar9 = (ulonglong)uVar1 * 4;

  uVar7 = param_2 % (ulonglong)*(ushort *)(param_1 + 0x30);

  iVar2 = *(int *)(param_1 + 0x6c);

  if (((iVar2 == 1) || (iVar2 == 2)) && ((param_2 < uVar9 || (uVar7 != 0)))) {

    uVar5 = FUN_14012e850("Truncated IMA ADPCM block");

    return (bool)uVar5;

  }

  uVar10 = (ulonglong)*(uint *)(param_1 + 0x38);

  lVar8 = uVar10 * (param_2 / *(ushort *)(param_1 + 0x30));

  *(longlong *)(param_1 + 0x58) = lVar8;

  if (((uVar7 != 0) && (iVar2 == 3)) && (uVar9 - 2 < uVar7)) {

    uVar6 = 1;

    if (uVar9 < uVar7) {

      auVar3._8_8_ = 0;

      auVar3._0_8_ = uVar7 + (ulonglong)uVar1 * -4;

      auVar4 = auVar3 % (ZEXT216(uVar1) << 2);

      uVar6 = SUB168(auVar3 / (ZEXT216(uVar1) << 2),0) * 8 + 1;

      if (uVar9 - 4 < auVar4._0_8_) {

        uVar6 = uVar6 + (ulonglong)(auVar4._0_4_ & 3) * 2;

      }

    }

    if (uVar10 < uVar6) {

      uVar6 = uVar10;

    }

    *(ulonglong *)(param_1 + 0x58) = lVar8 + uVar6;

  }

  lVar8 = FUN_14018a0e0(param_1);

  *(longlong *)(param_1 + 0x58) = lVar8;

  return -1 < lVar8;

}




