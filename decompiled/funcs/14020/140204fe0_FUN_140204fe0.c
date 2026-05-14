// Address: 0x140204fe0
// Ghidra name: FUN_140204fe0
// ============ 0x140204fe0 FUN_140204fe0 (size=511) ============


undefined8

FUN_140204fe0(longlong param_1,undefined8 param_2,undefined8 param_3,int param_4,undefined4 param_5,

             undefined4 param_6,int param_7,uint param_8,longlong param_9,int param_10)



{

  undefined1 auVar1 [16];

  undefined1 auVar2 [16];

  undefined8 uVar3;

  ulonglong uVar4;

  longlong lVar5;

  longlong lVar6;

  ulonglong uVar7;

  ulonglong uVar8;

  longlong lVar9;

  undefined4 local_88;

  undefined4 local_84;

  undefined4 local_80;

  longlong local_78;

  undefined4 local_70;

  int local_6c;

  uint local_68;

  undefined4 local_64;

  undefined8 local_60;

  undefined8 local_58;

  undefined4 local_50;

  undefined4 local_4c;

  undefined4 local_48;

  int local_44;

  uint local_40;

  undefined4 local_3c;

  

  uVar8 = (ulonglong)param_8;

  uVar7 = 0;

  if ((param_7 != 0) &&

     (auVar1._8_8_ = 0, auVar1._0_8_ = (longlong)param_7, uVar7 = (longlong)param_7,

     SUB168((ZEXT816(0) << 0x40 | ZEXT816(0xffffffffffffffff)) / auVar1,0) <

     (ulonglong)(longlong)param_4)) {

    uVar3 = FUN_14012e850("update size overflow");

    return uVar3;

  }

  uVar7 = (longlong)param_4 * uVar7;

  if ((param_8 != 0) &&

     (auVar2._8_8_ = 0, auVar2._0_8_ = (longlong)(int)param_8,

     auVar1 = ZEXT816(0) << 0x40 | ZEXT816(0xffffffffffffffff), uVar4 = SUB168(auVar1 / auVar2,0),

     uVar4 <= uVar7 && uVar7 - uVar4 != 0)) {

    uVar3 = FUN_14012e850("update size overflow",SUB168(auVar1 % auVar2,0));

    return uVar3;

  }

  local_80 = 0;

  local_88 = 0;

  lVar9 = (longlong)(int)param_8 * uVar7;

  local_84 = (undefined4)lVar9;

  lVar5 = FUN_140135d10(*(undefined8 *)(param_1 + 8),&local_88);

  if ((lVar5 == 0) || (lVar6 = FUN_140137ac0(*(undefined8 *)(param_1 + 8),lVar5,0), lVar6 == 0)) {

    uVar3 = 0;

  }

  else {

    if ((longlong)param_10 == uVar7) {

      FUN_1402f8e20(lVar6,param_9,lVar9);

    }

    else if (0 < (int)param_8) {

      do {

        FUN_1402f8e20(lVar6,param_9,uVar7);

        lVar6 = lVar6 + uVar7;

        param_9 = param_9 + param_10;

        uVar8 = uVar8 - 1;

      } while (uVar8 != 0);

    }

    FUN_140138720(*(undefined8 *)(param_1 + 8),lVar5);

    local_70 = 0;

    local_64 = 0;

    local_58 = 0;

    local_48 = 0;

    local_50 = param_5;

    local_4c = param_6;

    local_68 = param_8;

    local_40 = param_8;

    local_3c = 1;

    local_78 = lVar5;

    local_6c = param_7;

    local_60 = param_3;

    local_44 = param_7;

    FUN_1401388a0(param_2,&local_78,&local_60,0);

    FUN_140138000(*(undefined8 *)(param_1 + 8),lVar5);

    uVar3 = 1;

  }

  return uVar3;

}




