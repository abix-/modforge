// Address: 0x1400a6e10
// Ghidra name: FUN_1400a6e10
// ============ 0x1400a6e10 FUN_1400a6e10 (size=555) ============


undefined8 FUN_1400a6e10(longlong param_1)



{

  longlong *plVar1;

  undefined8 uVar2;

  undefined4 uVar3;

  undefined4 uVar4;

  undefined4 uVar5;

  undefined8 uVar6;

  undefined8 uVar7;

  ulonglong uVar8;

  ulonglong uVar9;

  uint uVar10;

  ulonglong uVar11;

  longlong lVar12;

  undefined4 local_68;

  undefined4 local_64;

  undefined8 local_60;

  undefined8 local_58;

  undefined8 uStack_50;

  undefined4 local_48;

  undefined4 local_44;

  undefined1 local_40;

  undefined8 local_38;

  undefined4 local_30;

  

  FUN_1400d0a00(param_1,0);

  FUN_1400cd5a0(param_1,1);

  FUN_1400ce540(param_1,DAT_140303fb8,0);

  uVar5 = DAT_14039ca44;

  uVar9 = 0;

  local_58 = 0;

  uStack_50 = 0;

  local_38 = 0;

  local_60 = 0x40b00000;

  local_48 = 0;

  local_44 = 0x101;

  local_40 = 1;

  local_30 = 0x3f800000;

  local_68 = 1;

  local_64 = 0x41500000;

  uVar6 = FUN_140005e10(*(undefined8 *)(param_1 + 0x98),&local_68);

  uVar7 = CONCAT44(DAT_14039ca34,DAT_140303fc0);

  uVar2 = CONCAT44(DAT_14030d030,DAT_14030d034);

  *(undefined8 *)(param_1 + 600) = uVar6;

  FUN_140083480(uVar6,uVar2,uVar7,0,0,uVar5,0);

  FUN_140084570(*(undefined8 *)(param_1 + 600),*(undefined4 *)(param_1 + 0x120),1,0xff);

  uVar7 = FUN_1400833d0(*(undefined8 *)(param_1 + 0x98),CONCAT44(DAT_140303394,DAT_140303388),1);

  uVar4 = DAT_14030338c;

  uVar3 = DAT_14030335c;

  *(undefined8 *)(param_1 + 0x260) = uVar7;

  FUN_140083480(uVar7,DAT_1403ffbe8,CONCAT44(uVar3,uVar4),0,0,uVar5,0);

  FUN_140084570(*(undefined8 *)(param_1 + 0x260),*(undefined4 *)(param_1 + 0x120),1,0xff);

  *(undefined8 *)(param_1 + 0x27c) = 0xffffffffffffffff;

  *(undefined1 *)(param_1 + 0x278) = 0;

  *(undefined8 *)(param_1 + 0x26c) = 0;

  *(undefined4 *)(param_1 + 0x274) = 0;

  *(undefined4 *)(param_1 + 0x250) = 0;

  lVar12 = *(longlong *)(param_1 + 0x130);

  uVar8 = 0;

  uVar11 = uVar9;

  if (*(longlong *)(param_1 + 0x138) - lVar12 >> 3 != 0) {

    do {

      plVar1 = (longlong *)(uVar9 + lVar12);

      uVar9 = uVar9 + 8;

      uVar10 = (int)uVar11 + 1;

      *(undefined4 *)(*plVar1 + 0x1cc) = 0;

      lVar12 = *(longlong *)(param_1 + 0x130);

      uVar8 = (ulonglong)(int)uVar10;

      uVar11 = (ulonglong)uVar10;

    } while (uVar8 < (ulonglong)(*(longlong *)(param_1 + 0x138) - lVar12 >> 3));

  }

  return CONCAT71((int7)(uVar8 >> 8),1);

}




