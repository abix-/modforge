// Address: 0x140160670
// Ghidra name: FUN_140160670
// ============ 0x140160670 FUN_140160670 (size=219) ============


void FUN_140160670(uint param_1,char *param_2)



{

  int iVar1;

  longlong lVar2;

  undefined8 uVar3;

  char *pcVar4;

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

  

  iVar1 = FUN_140161250();

  if (iVar1 < 0) {

    lVar2 = FUN_140184230(DAT_1403fc330,(longlong)(DAT_1403fc328 + 1) << 2);

    if (lVar2 != 0) {

      DAT_1403fc330 = lVar2;

      *(uint *)(lVar2 + (longlong)DAT_1403fc328 * 4) = param_1;

      DAT_1403fc328 = DAT_1403fc328 + 1;

      pcVar4 = "Mouse";

      if (param_2 != (char *)0x0) {

        pcVar4 = param_2;

      }

      uVar3 = FUN_14012f0d0(pcVar4);

      FUN_1401ab100(DAT_1403fc338,param_1,uVar3,1);

      uStack_80 = 0;

      local_88 = 0x404;

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




