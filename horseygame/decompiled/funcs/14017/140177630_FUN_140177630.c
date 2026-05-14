// Address: 0x140177630
// Ghidra name: FUN_140177630
// ============ 0x140177630 FUN_140177630 (size=227) ============


void FUN_140177630(undefined8 param_1,undefined4 *param_2,undefined8 param_3,undefined8 param_4,

                  uint param_5)



{

  char cVar1;

  uint uVar2;

  undefined4 local_98 [2];

  undefined8 local_90;

  undefined4 local_88;

  undefined8 local_84;

  undefined8 uStack_7c;

  undefined8 local_74;

  undefined8 local_68;

  

  if (0xf < param_5) {

    param_5 = 0x10;

  }

  FUN_1402f8e20(param_2 + 6,param_4,(longlong)(int)param_5 * 4);

  cVar1 = FUN_140139420(0x1200);

  if (cVar1 != '\0') {

    local_88 = *param_2;

    local_98[0] = 0x1200;

    uVar2 = 6;

    if ((ulonglong)(longlong)(int)param_5 < 6) {

      uVar2 = param_5;

    }

    local_74 = 0;

    local_84 = 0;

    uStack_7c = 0;

    local_90 = param_1;

    FUN_1402f8e20(&local_84,param_4,(longlong)(int)uVar2 << 2);

    local_68 = param_3;

    FUN_14013b140(local_98);

  }

  FUN_14013dcb0(param_1,*param_2,param_3,param_4);

  return;

}




