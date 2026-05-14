// Address: 0x1401a8b60
// Ghidra name: FUN_1401a8b60
// ============ 0x1401a8b60 FUN_1401a8b60 (size=340) ============


void FUN_1401a8b60(undefined8 param_1,undefined4 param_2,undefined4 *param_3,byte param_4,

                  char param_5)



{

  uint uVar1;

  bool bVar2;

  char cVar3;

  longlong lVar4;

  undefined4 uVar5;

  uint uVar6;

  int local_88 [2];

  undefined8 local_80;

  undefined4 local_78;

  undefined4 local_74;

  undefined8 local_70;

  undefined8 uStack_68;

  undefined8 local_60;

  undefined8 uStack_58;

  undefined8 local_50;

  undefined8 uStack_48;

  undefined8 local_40;

  undefined8 uStack_38;

  undefined8 local_30;

  undefined8 uStack_28;

  undefined8 local_20;

  undefined8 uStack_18;

  undefined8 local_10;

  

  bVar2 = false;

  FUN_14017caa0(DAT_1403fcd48);

  lVar4 = FUN_1401a8110();

  if (lVar4 != 0) {

    if ((param_4 == 0) && (param_5 == '\0')) {

      *(undefined1 *)(lVar4 + 0x50) = 1;

      if (param_3 == (undefined4 *)0x0) {

        uVar5 = 0;

      }

      else {

        uVar5 = *param_3;

      }

      *(undefined4 *)(lVar4 + 0x54) = uVar5;

      FUN_140139010(&DAT_1403fcd58,1);

      FUN_14017cae0(DAT_1403fcd48);

      return;

    }

    uVar1 = *(uint *)(lVar4 + 0x4c);

    if ((byte)(uVar1 >> 0x1f) != param_4) {

      bVar2 = true;

      uVar6 = uVar1 | 0x80000000;

      if (param_4 == 0) {

        uVar6 = uVar1 & 0x7fffffff;

      }

      *(uint *)(lVar4 + 0x4c) = uVar6;

    }

    *(undefined1 *)(lVar4 + 0x50) = 0;

  }

  FUN_14017cae0(DAT_1403fcd48);

  local_88[0] = 0x1301 - (uint)(param_4 != 0);

  if ((bVar2) && (cVar3 = FUN_140139420(), cVar3 != '\0')) {

    local_88[1] = 0;

    local_10 = 0;

    local_70 = 0;

    uStack_68 = 0;

    local_60 = 0;

    uStack_58 = 0;

    local_50 = 0;

    uStack_48 = 0;

    local_40 = 0;

    uStack_38 = 0;

    local_30 = 0;

    uStack_28 = 0;

    local_20 = 0;

    uStack_18 = 0;

    if (param_3 == (undefined4 *)0x0) {

      local_78 = 0;

    }

    else {

      local_78 = *param_3;

    }

    local_80 = param_1;

    local_74 = param_2;

    FUN_14013b140(local_88);

  }

  return;

}




