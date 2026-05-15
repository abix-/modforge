// Address: 0x14010d260
// Ghidra name: FUN_14010d260
// ============ 0x14010d260 FUN_14010d260 (size=918) ============


void FUN_14010d260(longlong param_1,int param_2,int param_3,uint param_4)



{

  int iVar1;

  float fVar2;

  undefined4 uVar3;

  undefined4 local_res8;

  undefined4 local_resc;

  float local_68;

  float local_64;

  

  param_4 = param_4 & 0xff;

  if (*(char *)(param_1 + 0x260) != '\0') {

    fVar2 = (float)FUN_1400c6940();

    fVar2 = fVar2 - DAT_140303394;

    local_68 = (float)FUN_1400c6940();

    local_68 = local_68 + (float)(param_2 * 0x20 + 0x10);

    local_64 = (float)(param_3 * 0x20 + 0x10) + fVar2;

    uVar3 = FUN_1400c6940();

    local_res8 = FUN_1400c6940();

    local_resc = uVar3;

    iVar1 = FUN_1400c6580(2);

    FUN_1400c8dc0(*(undefined8 *)(param_1 + 0x248),0xffffffff,&local_68,&local_res8,0,0,

                  &DAT_1403dc2ec,0x1e,(float)(int)(param_4 + 1 + iVar1));

    uVar3 = FUN_1400c6940();

    local_res8 = FUN_1400c6940();

    local_resc = uVar3;

    iVar1 = FUN_1400c6580(2);

    FUN_1400c8dc0(*(undefined8 *)(param_1 + 0x248),0xffffffff,&local_68,&local_res8,0,0,

                  &DAT_1403dc2ec,0x1e,(float)(int)(param_4 + 1 + iVar1));

    uVar3 = FUN_1400c6940();

    local_res8 = FUN_1400c6940();

    local_resc = uVar3;

    iVar1 = FUN_1400c6580(2);

    FUN_1400c8dc0(*(undefined8 *)(param_1 + 0x248),0xffffffff,&local_68,&local_res8,0,0,

                  &DAT_1403dc2ec,0x1e,(float)(int)(param_4 + 1 + iVar1));

    uVar3 = FUN_1400c6940();

    local_res8 = FUN_1400c6940();

    local_resc = uVar3;

    iVar1 = FUN_1400c6580(2);

    FUN_1400c8dc0(*(undefined8 *)(param_1 + 0x248),0xffffffff,&local_68,&local_res8,0,0,

                  &DAT_1403dc2ec,0x1e,(float)(int)(param_4 + 1 + iVar1));

    uVar3 = FUN_1400c6940();

    local_res8 = FUN_1400c6940();

    local_resc = uVar3;

    iVar1 = FUN_1400c6580(2);

    FUN_1400c8dc0(*(undefined8 *)(param_1 + 0x248),0xffffffff,&local_68,&local_res8,0,0,

                  &DAT_1403dc2ec,0x1e,(float)(int)(param_4 + 1 + iVar1));

  }

  return;

}




