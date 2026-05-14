// Address: 0x1401838c0
// Ghidra name: FUN_1401838c0
// ============ 0x1401838c0 FUN_1401838c0 (size=208) ============


void FUN_1401838c0(undefined8 param_1,int param_2,undefined4 param_3,undefined1 param_4)



{

  char cVar1;

  undefined4 local_88 [2];

  undefined8 local_80;

  undefined4 local_78;

  longlong local_70;

  int local_68;

  undefined4 local_64;

  undefined1 local_60;

  

  if (((DAT_1403fc6e0 != (undefined4 *)0x0) && (cVar1 = FUN_140172fc0(), cVar1 != '\0')) &&

     (cVar1 = FUN_140139420(), cVar1 != '\0')) {

    local_88[0] = 0x307;

    local_80 = 0;

    if (DAT_1403fc6e0 == (undefined4 *)0x0) {

      local_78 = 0;

    }

    else {

      local_78 = *DAT_1403fc6e0;

    }

    if (param_2 < 1) {

      local_70 = 0;

      local_68 = 0;

      local_64 = 0xffffffff;

      local_60 = 0;

    }

    else {

      local_70 = FUN_140182d60(param_1,param_2);

      local_68 = param_2;

      local_64 = param_3;

      local_60 = param_4;

      if (local_70 == 0) {

        return;

      }

    }

    FUN_14013b140(local_88);

  }

  return;

}




