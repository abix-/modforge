// Address: 0x1402051e0
// Ghidra name: FUN_1402051e0
// ============ 0x1402051e0 FUN_1402051e0 (size=364) ============


byte FUN_1402051e0(longlong param_1,uint *param_2,int *param_3,undefined8 param_4,undefined4 param_5

                  ,undefined8 param_6,undefined4 param_7)



{

  longlong lVar1;

  longlong lVar2;

  byte bVar3;

  byte bVar4;

  undefined8 uVar5;

  uint uVar6;

  

  lVar1 = *(longlong *)(param_1 + 0x2e0);

  uVar6 = *param_2;

  lVar2 = *(longlong *)(param_2 + 0x4e);

  if ((uVar6 == 0) || ((uVar6 & 0xf0000000) == 0x10000000)) {

    uVar6 = uVar6 & 0xff;

  }

  else if ((((uVar6 == 0x32595559) || (uVar6 == 0x59565955)) || (uVar6 == 0x55595659)) ||

          (uVar6 == 0x30313050)) {

    uVar6 = 2;

  }

  else {

    uVar6 = 1;

  }

  uVar5 = FUN_140132c70(*(undefined8 *)(lVar1 + 0xa0));

  bVar3 = FUN_140204fe0(lVar1,uVar5,*(undefined8 *)(lVar2 + 8),uVar6,*param_3,param_3[1],param_3[2],

                        param_3[3],param_4,param_5);

  bVar4 = FUN_140204fe0(lVar1,uVar5,*(undefined8 *)(lVar2 + 0x60),uVar6 * 2,*param_3 / 2,

                        param_3[1] / 2,(param_3[2] + 1) / 2,(param_3[3] + 1) / 2,param_6,param_7);

  FUN_140136720(uVar5);

  return bVar4 & bVar3 & 1;

}




