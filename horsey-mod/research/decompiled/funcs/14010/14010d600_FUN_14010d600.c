// Address: 0x14010d600
// Ghidra name: FUN_14010d600
// ============ 0x14010d600 FUN_14010d600 (size=472) ============


void FUN_14010d600(longlong param_1,int param_2,int param_3)



{

  int iVar1;

  longlong lVar2;

  undefined4 uVar3;

  float fVar4;

  undefined4 local_res8;

  undefined4 local_resc;

  float local_res20;

  float local_res24;

  

  if (*(char *)(param_1 + 0x260) != '\0') {

    lVar2 = 0xb;

    do {

      uVar3 = FUN_1400c6940();

      local_res8 = FUN_1400c6940();

      local_resc = uVar3;

      fVar4 = (float)FUN_1400c6940();

      local_res20 = (float)FUN_1400c6940();

      local_res20 = local_res20 + (float)(param_2 * 0x20 + 0x10);

      local_res24 = (float)(param_3 * 0x20 + 0x10) + fVar4;

      iVar1 = FUN_1400c6580(2);

      FUN_1400c8dc0(*(undefined8 *)(param_1 + 0x248),0xffffffff,&local_res20,&local_res8,0,0,

                    &DAT_1403dc2a8,0x1e,(float)(iVar1 + 2));

      lVar2 = lVar2 + -1;

    } while (lVar2 != 0);

  }

  return;

}




