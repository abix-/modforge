// Address: 0x14022ddd0
// Ghidra name: FUN_14022ddd0
// ============ 0x14022ddd0 FUN_14022ddd0 (size=458) ============


ulonglong FUN_14022ddd0(undefined4 *param_1,uint param_2,longlong param_3,longlong param_4,

                       undefined4 param_5,undefined4 param_6)



{

  char cVar1;

  byte bVar2;

  ulonglong uVar3;

  longlong lVar4;

  ulonglong local_98 [2];

  undefined4 local_88;

  undefined4 uStack_84;

  undefined4 uStack_80;

  undefined4 uStack_7c;

  undefined4 uStack_78;

  undefined4 uStack_74;

  undefined4 uStack_70;

  undefined4 uStack_6c;

  undefined4 uStack_68;

  undefined4 local_64;

  undefined4 uStack_60;

  undefined4 uStack_5c;

  undefined4 uStack_58;

  undefined4 local_54;

  undefined4 uStack_50;

  undefined4 uStack_4c;

  undefined4 uStack_48;

  undefined4 local_44;

  undefined4 uStack_40;

  undefined4 uStack_3c;

  undefined4 uStack_38;

  undefined4 local_34;

  undefined4 uStack_30;

  undefined4 uStack_2c;

  undefined4 uStack_28;

  undefined4 local_24;

  undefined4 uStack_20;

  undefined4 local_1c;

  

  cVar1 = FUN_140139420(param_2);

  if (cVar1 == '\0') {

    return 0;

  }

  cVar1 = DAT_1403fdd00;

  if (param_1 != (undefined4 *)0x0) {

    cVar1 = *(char *)(param_1 + 0x44);

  }

  if (cVar1 == '\0') {

    local_98[0] = 0x1002;

    local_98[1] = 0;

    local_24 = 0;

    uStack_20 = 0;

    local_1c = 0;

    uStack_84 = 0;

    uStack_80 = 0;

    uStack_7c = 0;

    uStack_78 = 0;

    uStack_74 = 0;

    uStack_70 = 0;

    uStack_6c = 0;

    uStack_68 = 0;

    local_64 = 0;

    uStack_60 = 0;

    uStack_5c = 0;

    uStack_58 = 0;

    local_54 = 0;

    uStack_50 = 0;

    uStack_4c = 0;

    uStack_48 = 0;

    local_44 = 0;

    uStack_40 = 0;

    uStack_3c = 0;

    uStack_38 = 0;

    local_34 = 0;

    uStack_30 = 0;

    uStack_2c = 0;

    uStack_28 = 0;

    if (param_1 == (undefined4 *)0x0) {

      local_88 = 0;

    }

    else {

      local_88 = *param_1;

    }

    uVar3 = FUN_14013b140(local_98);

    if ((char)uVar3 != '\0') {

      if (param_1 == (undefined4 *)0x0) {

        DAT_1403fdd00 = '\x01';

      }

      else {

        *(undefined1 *)(param_1 + 0x44) = 1;

      }

      goto LAB_14022de8e;

    }

LAB_14022dee4:

    uVar3 = uVar3 & 0xffffffffffffff00;

  }

  else {

LAB_14022de8e:

    local_98[0] = (ulonglong)param_2;

    local_98[1] = 0;

    local_88 = 0;

    uStack_84 = 0;

    uStack_80 = 0;

    uStack_7c = 0;

    uStack_78 = 0;

    uStack_74 = 0;

    uStack_70 = 0;

    uStack_6c = 0;

    uStack_68 = 0;

    local_64 = 0;

    uStack_60 = 0;

    uStack_5c = 0;

    uStack_58 = 0;

    local_54 = 0;

    uStack_50 = 0;

    uStack_4c = 0;

    uStack_48 = 0;

    local_44 = 0;

    uStack_40 = 0;

    uStack_3c = 0;

    uStack_38 = 0;

    local_34 = 0;

    uStack_30 = 0;

    uStack_2c = 0;

    uStack_28 = 0;

    local_24 = 0;

    uStack_20 = 0;

    local_1c = 0;

    if (param_3 != 0) {

      lVar4 = FUN_1401392f0(param_3);

      uStack_78 = (undefined4)lVar4;

      uStack_74 = (undefined4)((ulonglong)lVar4 >> 0x20);

      uVar3 = 0;

      if (lVar4 == 0) goto LAB_14022dee4;

    }

    if (param_4 != 0) {

      lVar4 = FUN_1401392f0(param_4);

      uStack_70 = (undefined4)lVar4;

      uStack_6c = (undefined4)((ulonglong)lVar4 >> 0x20);

      uVar3 = 0;

      if (lVar4 == 0) goto LAB_14022dee4;

    }

    if (param_1 == (undefined4 *)0x0) {

      local_88 = 0;

    }

    else {

      local_88 = *param_1;

    }

    if (param_2 == 0x1004) {

      DAT_1403fdd04 = param_5;

      DAT_1403fdd08 = param_6;

    }

    uStack_84 = DAT_1403fdd04;

    uStack_80 = DAT_1403fdd08;

    bVar2 = FUN_14013b140(local_98);

    uVar3 = (ulonglong)bVar2;

    if ((bVar2 != 0) && (param_2 == 0x1003)) {

      if (param_1 == (undefined4 *)0x0) {

        DAT_1403fdd00 = '\0';

      }

      else {

        *(undefined1 *)(param_1 + 0x44) = 0;

      }

      DAT_1403fdd04 = 0;

      DAT_1403fdd08 = 0;

    }

  }

  return uVar3;

}




