// Address: 0x1400e3c70
// Ghidra name: FUN_1400e3c70
// ============ 0x1400e3c70 FUN_1400e3c70 (size=286) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined8

FUN_1400e3c70(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,

             undefined4 param_5)



{

  int iVar1;

  longlong lVar2;

  undefined8 uVar3;

  undefined1 local_d8 [16];

  undefined *local_c8;

  undefined *puStack_c0;

  undefined *local_b8;

  longlong local_b0;

  undefined4 local_a8;

  undefined4 local_a4;

  undefined1 local_a0 [128];

  undefined1 *local_20;

  undefined1 *local_18;

  undefined1 *local_10;

  

  lVar2 = FUN_1402ce0f8(param_1,&DAT_14039be7c);

  if (lVar2 == 0) {

    _DAT_1403f4c40 = "can\'t fopen";

    uVar3 = 0;

  }

  else {

    local_10 = local_a0;

    local_c8 = PTR_LAB_1403dade0;

    puStack_c0 = PTR_LAB_1403dade8;

    local_b8 = PTR_LAB_1403dadf0;

    local_a4 = 0x80;

    local_a8 = 1;

    local_b0 = lVar2;

    iVar1 = (*(code *)PTR_LAB_1403dade0)(lVar2,local_a0,0x80);

    if (iVar1 == 0) {

      local_20 = local_18 + -1;

      *local_20 = 0;

      local_a8 = 0;

    }

    else {

      local_20 = local_a0;

      local_18 = local_a0 + iVar1;

    }

    uVar3 = FUN_1400ee9e0(local_d8,param_2,param_3,param_4,param_5);

    FUN_1402ce288(lVar2);

  }

  return uVar3;

}




