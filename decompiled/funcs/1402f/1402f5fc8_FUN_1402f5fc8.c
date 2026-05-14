// Address: 0x1402f5fc8
// Ghidra name: FUN_1402f5fc8
// ============ 0x1402f5fc8 FUN_1402f5fc8 (size=283) ============


undefined4

FUN_1402f5fc8(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,

             undefined4 param_5,undefined4 param_6,undefined4 param_7)



{

  int iVar1;

  undefined4 uVar2;

  undefined8 uVar3;

  undefined1 local_68 [8];

  longlong local_60;

  longlong local_58;

  char local_48;

  undefined8 local_40;

  undefined8 local_38;

  undefined8 local_30;

  undefined8 local_28;

  undefined8 local_20;

  char local_18;

  

  local_40 = 0;

  local_38 = 0;

  local_30 = 0;

  local_28 = 0;

  local_20 = 0;

  local_18 = '\0';

  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&local_60,(__crt_locale_pointers *)0x0);

  uVar3 = 0xfde9;

  if (*(int *)(local_58 + 0xc) == 0xfde9) {

    if (local_48 != '\0') {

      *(uint *)(local_60 + 0x3a8) = *(uint *)(local_60 + 0x3a8) & 0xfffffffd;

    }

  }

  else {

    iVar1 = FUN_1402ec34c();

    if (iVar1 == 0) {

      if (local_48 != '\0') {

        *(uint *)(local_60 + 0x3a8) = *(uint *)(local_60 + 0x3a8) & 0xfffffffd;

      }

      uVar3 = 1;

    }

    else {

      if (local_48 != '\0') {

        *(uint *)(local_60 + 0x3a8) = *(uint *)(local_60 + 0x3a8) & 0xfffffffd;

      }

      uVar3 = 0;

    }

  }

  iVar1 = FUN_1402e68f8(param_3,&local_40,local_68,uVar3);

  if (iVar1 == 0) {

    uVar2 = FUN_1402f6118(param_1,param_2,local_30,param_4,param_5,param_6,param_7);

  }

  else {

    uVar2 = 0xffffffff;

  }

  if (local_18 != '\0') {

    FUN_1402e9a80(local_30);

  }

  return uVar2;

}




