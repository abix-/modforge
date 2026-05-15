// Address: 0x140183700
// Ghidra name: FUN_140183700
// ============ 0x140183700 FUN_140183700 (size=191) ============


void FUN_140183700(uint param_1)



{

  int iVar1;

  int iVar2;

  undefined8 local_88;

  undefined8 uStack_80;

  ulonglong local_78;

  undefined8 uStack_70;

  undefined8 local_68;

  undefined8 uStack_60;

  undefined8 local_58;

  undefined8 uStack_50;

  undefined8 local_48;

  undefined8 uStack_40;

  undefined8 local_38;

  undefined8 uStack_30;

  undefined8 local_28;

  undefined8 uStack_20;

  undefined8 local_18;

  undefined8 uStack_10;

  

  iVar2 = FUN_1401832a0();

  if (-1 < iVar2) {

    iVar1 = DAT_1403fcb08 + -1;

    if (iVar2 != iVar1) {

      FUN_1402f8e20(DAT_1403fcb10 + (longlong)iVar2 * 4,DAT_1403fcb10 + (longlong)(iVar2 + 1) * 4,

                    (longlong)((DAT_1403fcb08 - iVar2) + -1) << 2);

    }

    DAT_1403fcb08 = iVar1;

    if (DAT_1403fcb0c == '\0') {

      uStack_80 = 0;

      local_88 = 0x306;

      uStack_70 = 0;

      local_78 = (ulonglong)param_1;

      local_68 = 0;

      uStack_60 = 0;

      local_58 = 0;

      uStack_50 = 0;

      local_48 = 0;

      uStack_40 = 0;

      local_38 = 0;

      uStack_30 = 0;

      local_28 = 0;

      uStack_20 = 0;

      local_18 = 0;

      uStack_10 = 0;

      FUN_14013b140(&local_88);

    }

  }

  return;

}




