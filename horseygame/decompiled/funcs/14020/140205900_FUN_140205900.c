// Address: 0x140205900
// Ghidra name: FUN_140205900
// ============ 0x140205900 FUN_140205900 (size=243) ============


undefined8 FUN_140205900(longlong param_1,undefined8 param_2,ulonglong param_3)



{

  char cVar1;

  undefined8 uVar2;

  longlong lVar3;

  undefined8 local_28;

  undefined4 local_20;

  undefined4 local_1c;

  undefined8 local_18;

  undefined8 local_10;

  

  if (param_3 == 0) {

    return 1;

  }

  if (*(uint *)(param_1 + 0x88) < param_3) {

    FUN_1402057a0();

    cVar1 = FUN_140205680(param_1,param_3 & 0xffffffff);

    if (cVar1 == '\0') {

      return 0;

    }

  }

  uVar2 = FUN_140137ac0(*(undefined8 *)(param_1 + 8),*(undefined8 *)(param_1 + 0x78),1);

  FUN_1402f8e20(uVar2,param_2,param_3);

  FUN_140138720(*(undefined8 *)(param_1 + 8),*(undefined8 *)(param_1 + 0x78));

  lVar3 = FUN_140132c70();

  if (lVar3 == 0) {

    return 0;

  }

  local_18 = *(undefined8 *)(param_1 + 0x78);

  local_28 = *(undefined8 *)(param_1 + 0x80);

  local_10 = 0;

  local_20 = 0;

  local_1c = (int)param_3;

  FUN_140138760(lVar3,&local_18,&local_28,1);

  FUN_140136720(lVar3);

  return 1;

}




