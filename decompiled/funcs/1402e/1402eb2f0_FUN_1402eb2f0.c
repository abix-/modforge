// Address: 0x1402eb2f0
// Ghidra name: FUN_1402eb2f0
// ============ 0x1402eb2f0 FUN_1402eb2f0 (size=378) ============


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */



undefined8

FUN_1402eb2f0(ulonglong param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4,

             undefined8 param_5)



{

  char cVar1;

  int iVar2;

  undefined4 *puVar3;

  undefined8 uVar4;

  undefined1 auStack_f8 [32];

  undefined8 *local_d8;

  undefined8 *local_d0;

  int local_c8;

  undefined8 local_b8;

  undefined8 local_b0;

  undefined8 local_a8;

  undefined8 uStack_a0;

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

  ulonglong local_38;

  

  uVar4 = param_5;

  local_38 = DAT_1403e8b00 ^ (ulonglong)auStack_f8;

  local_b8 = param_4;

  local_b0 = param_3;

  iVar2 = FUN_1402eb6f0(param_1,&local_b8,param_5);

  if (iVar2 == 0) {

    local_d0 = &local_b8;

    local_d8 = &local_b0;

    local_a8 = 0;

    uStack_a0 = 0;

    local_98 = 0;

    uStack_90 = 0;

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

    local_c8 = iVar2;

    FUN_1402ebab0(&local_a8,&param_5,param_1 & 0xffffffff,param_2);

    uVar4 = param_5;

  }

  if ((param_1 & 0x20) == 0) {

    if ((param_1 & 8) == 0) {

      if ((param_1 & 4) == 0) {

        if ((param_1 & 1) == 0) {

          iVar2 = ((uint)param_1 & 2) * 2;

        }

        else {

          iVar2 = 3;

        }

      }

      else {

        iVar2 = 2;

      }

    }

    else {

      iVar2 = 1;

    }

  }

  else {

    iVar2 = 5;

  }

  cVar1 = FUN_1402e7d50();

  if (cVar1 == '\0') {

    if (iVar2 == 1) {

      puVar3 = (undefined4 *)FUN_1402e68b0();

      *puVar3 = 0x21;

    }

    else if ((iVar2 == 2) || (iVar2 == 3)) {

      puVar3 = (undefined4 *)FUN_1402e68b0();

      *puVar3 = 0x22;

    }

  }

  else if (iVar2 != 0) {

    local_d8 = (undefined8 *)local_b8;

    local_d0 = (undefined8 *)uVar4;

    uVar4 = FUN_1402ebe30(iVar2,param_2,(int)param_3,0);

    return uVar4;

  }

  FUN_1402e8c20(uVar4,0xffc0);

  return local_b8;

}




