// Address: 0x140189e70
// Ghidra name: FUN_140189e70
// ============ 0x140189e70 FUN_140189e70 (size=441) ============


char FUN_140189e70(longlong param_1,char param_2,undefined8 *param_3,undefined8 *param_4,

                  undefined4 *param_5)



{

  char cVar1;

  undefined4 uVar2;

  undefined8 local_98;

  undefined8 uStack_90;

  undefined8 local_88;

  undefined8 uStack_80;

  undefined8 local_78;

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

  

  cVar1 = '\0';

  if (param_3 != (undefined8 *)0x0) {

    *param_3 = 0;

    *(undefined4 *)(param_3 + 1) = 0;

  }

  if (param_4 != (undefined8 *)0x0) {

    *param_4 = 0;

  }

  if (param_5 != (undefined4 *)0x0) {

    *param_5 = 0;

  }

  if (param_1 == 0) {

    FUN_14012e850("Parameter \'%s\' is invalid",&DAT_1403141a4);

  }

  else if (param_3 == (undefined8 *)0x0) {

    FUN_14012e850("Parameter \'%s\' is invalid",&DAT_14031769c);

  }

  else if (param_4 == (undefined8 *)0x0) {

    FUN_14012e850("Parameter \'%s\' is invalid","audio_buf");

  }

  else if (param_5 == (undefined4 *)0x0) {

    FUN_14012e850("Parameter \'%s\' is invalid","audio_len");

  }

  else {

    local_98 = 0;

    uStack_90 = 0;

    local_28 = 0;

    local_88 = 0;

    uStack_80 = 0;

    local_78 = 0;

    uStack_70 = 0;

    local_68 = 0;

    uStack_60 = 0;

    local_58 = 0;

    uStack_50 = 0;

    local_48 = 0;

    uStack_40 = 0;

    local_38 = 0;

    uStack_30 = 0;

    uVar2 = FUN_14018a5f0();

    uStack_30 = CONCAT44(uStack_30._4_4_,uVar2);

    uVar2 = FUN_14018a690();

    uStack_30 = CONCAT44(uVar2,(undefined4)uStack_30);

    uVar2 = FUN_14018a4c0();

    local_28 = CONCAT44(local_28._4_4_,uVar2);

    cVar1 = FUN_14018a730(param_1,&local_98,param_3,param_4,param_5);

    if (cVar1 == '\0') {

      FUN_1401841e0(*param_4);

      *param_4 = 0;

      *param_5 = 0;

    }

    if (param_2 == '\0') {

      FUN_14012cb40(param_1,uStack_90,0);

    }

    FUN_14018a480(&local_98);

    FUN_1401841e0(local_38);

  }

  if ((param_2 != '\0') && (param_1 != 0)) {

    FUN_14012bd50(param_1);

  }

  return cVar1;

}




