// Address: 0x140189250
// Ghidra name: FUN_140189250
// ============ 0x140189250 FUN_140189250 (size=193) ============


bool FUN_140189250(longlong param_1,ulonglong param_2)



{

  int iVar1;

  undefined1 uVar2;

  ulonglong uVar3;

  longlong lVar4;

  ulonglong uVar5;

  ulonglong uVar6;

  

  uVar3 = (ulonglong)*(ushort *)(param_1 + 0x24);

  iVar1 = *(int *)(param_1 + 0x6c);

  uVar5 = param_2 % (ulonglong)*(ushort *)(param_1 + 0x30);

  if (((iVar1 == 1) || (iVar1 == 2)) && ((param_2 < uVar3 * 7 || (uVar5 != 0)))) {

    uVar2 = FUN_14012e850("Truncated MS ADPCM block");

    return (bool)uVar2;

  }

  uVar6 = (ulonglong)*(uint *)(param_1 + 0x38);

  lVar4 = uVar6 * (param_2 / *(ushort *)(param_1 + 0x30));

  *(longlong *)(param_1 + 0x58) = lVar4;

  if (((uVar5 != 0) && (iVar1 == 3)) && (uVar3 * 7 <= uVar5)) {

    uVar3 = ((uVar5 + uVar3 * -7) * 8) / (*(ushort *)(param_1 + 0x32) * uVar3) + 2;

    if (uVar6 < uVar3) {

      uVar3 = uVar6;

    }

    *(ulonglong *)(param_1 + 0x58) = lVar4 + uVar3;

  }

  lVar4 = FUN_14018a0e0(param_1);

  *(longlong *)(param_1 + 0x58) = lVar4;

  return -1 < lVar4;

}




