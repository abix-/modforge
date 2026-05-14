// Address: 0x14010cd90
// Ghidra name: FUN_14010cd90
// ============ 0x14010cd90 FUN_14010cd90 (size=335) ============


void FUN_14010cd90(longlong param_1,undefined8 param_2,float param_3)



{

  uint uVar1;

  int iVar2;

  ulonglong uVar3;

  undefined4 uVar4;

  undefined4 local_res8;

  undefined4 local_resc;

  undefined8 local_58 [10];

  

  if ((*(char *)(param_1 + 0x260) != '\0') &&

     (local_58[0] = param_2, uVar1 = FUN_1400c5f50((int)(param_3 * DAT_14030338c),3,10),

     0 < (int)uVar1)) {

    uVar3 = (ulonglong)uVar1;

    do {

      uVar4 = FUN_1400c6940();

      local_res8 = FUN_1400c6940();

      local_resc = uVar4;

      iVar2 = FUN_1400c6580(2);

      FUN_1400c8dc0(*(undefined8 *)(param_1 + 0x248),0xffffffff,local_58,&local_res8,0,0,

                    &DAT_1403dc2dc,0x1e,(float)(iVar2 + 2));

      uVar3 = uVar3 - 1;

    } while (uVar3 != 0);

  }

  return;

}




