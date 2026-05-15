// Address: 0x140183810
// Ghidra name: FUN_140183810
// ============ 0x140183810 FUN_140183810 (size=162) ============


void FUN_140183810(longlong param_1,undefined4 param_2,undefined4 param_3)



{

  char cVar1;

  undefined4 local_88 [2];

  undefined8 local_80;

  undefined4 local_78;

  longlong local_70;

  undefined4 local_68;

  undefined4 local_64;

  

  if (DAT_1403fc6e0 != (undefined4 *)0x0) {

    cVar1 = FUN_140172fc0();

    if ((cVar1 != '\0') && (param_1 != 0)) {

      cVar1 = FUN_140139420();

      if (cVar1 != '\0') {

        local_88[0] = 0x302;

        local_80 = 0;

        if (DAT_1403fc6e0 == (undefined4 *)0x0) {

          local_78 = 0;

        }

        else {

          local_78 = *DAT_1403fc6e0;

        }

        local_68 = param_2;

        local_64 = param_3;

        local_70 = FUN_1401392f0(param_1);

        if (local_70 != 0) {

          FUN_14013b140(local_88);

        }

      }

    }

  }

  return;

}




