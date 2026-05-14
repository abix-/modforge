// Address: 0x140188c80
// Ghidra name: FUN_140188c80
// ============ 0x140188c80 FUN_140188c80 (size=243) ============


undefined1 FUN_140188c80(longlong param_1,undefined8 param_2)



{

  ushort uVar1;

  ushort uVar2;

  undefined1 auVar3 [16];

  undefined1 auVar4 [16];

  undefined1 uVar5;

  char cVar6;

  int iVar7;

  ulonglong uVar8;

  ulonglong uVar9;

  ulonglong uVar10;

  

  uVar8 = (ulonglong)*(ushort *)(param_1 + 0x24);

  uVar1 = *(ushort *)(param_1 + 0x32);

  uVar10 = (uint)uVar1 * uVar8;

  uVar2 = *(ushort *)(param_1 + 0x30);

  uVar9 = ((ulonglong)uVar2 + uVar8 * -4) * 8;

  auVar3._8_8_ = 0;

  auVar3._0_8_ = uVar10;

  auVar4._8_8_ = 0;

  auVar4._0_8_ = uVar9;

  uVar9 = uVar9 % uVar10;

  if (uVar1 == 3) {

    uVar5 = FUN_14012e850("3-bit IMA ADPCM currently not supported",uVar9);

    return uVar5;

  }

  if (uVar1 != 4) {

    uVar5 = FUN_14012e850("Invalid IMA ADPCM bits per sample of %u",uVar1);

    return uVar5;

  }

  if (((ulonglong)uVar2 < uVar8 * 4) || ((uVar2 & 3) != 0)) {

    uVar5 = FUN_14012e850("Invalid IMA ADPCM block size (nBlockAlign)",uVar9);

    return uVar5;

  }

  if (((*(short *)(param_1 + 0x20) != -2) && (0x13 < *(ulonglong *)(param_1 + 0x18))) &&

     (1 < *(ushort *)(param_1 + 0x34))) {

    *(uint *)(param_1 + 0x38) = (uint)*(ushort *)(*(longlong *)(param_1 + 0x10) + 0x12);

  }

  iVar7 = *(int *)(param_1 + 0x38);

  if (iVar7 == 0) {

    iVar7 = SUB164(auVar4 / auVar3,0) + 1;

    *(int *)(param_1 + 0x38) = iVar7;

  }

  if (SUB168(auVar4 / auVar3,0) < (ulonglong)(iVar7 - 1)) {

    uVar5 = FUN_14012e850("Invalid number of samples per IMA ADPCM block (wSamplesPerBlock)",uVar9);

    return uVar5;

  }

  cVar6 = FUN_140188680(param_1,param_2);

  return cVar6 != '\0';

}




