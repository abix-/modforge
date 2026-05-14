// Address: 0x140205350
// Ghidra name: FUN_140205350
// ============ 0x140205350 FUN_140205350 (size=475) ============


byte FUN_140205350(longlong param_1,uint *param_2,int *param_3,undefined8 param_4,undefined4 param_5

                  ,undefined8 param_6,undefined4 param_7,undefined8 param_8,undefined4 param_9)



{

  longlong lVar1;

  longlong lVar2;

  byte bVar3;

  byte bVar4;

  byte bVar5;

  undefined8 uVar6;

  uint uVar7;

  

  lVar1 = *(longlong *)(param_1 + 0x2e0);

  uVar7 = *param_2;

  lVar2 = *(longlong *)(param_2 + 0x4e);

  if ((uVar7 == 0) || ((uVar7 & 0xf0000000) == 0x10000000)) {

    uVar7 = uVar7 & 0xff;

  }

  else if ((((uVar7 == 0x32595559) || (uVar7 == 0x59565955)) || (uVar7 == 0x55595659)) ||

          (uVar7 == 0x30313050)) {

    uVar7 = 2;

  }

  else {

    uVar7 = 1;

  }

  uVar6 = FUN_140132c70(*(undefined8 *)(lVar1 + 0xa0));

  bVar3 = FUN_140204fe0(lVar1,uVar6,*(undefined8 *)(lVar2 + 8),uVar7,*param_3,param_3[1],param_3[2],

                        param_3[3],param_4,param_5);

  bVar4 = FUN_140204fe0(lVar1,uVar6,*(undefined8 *)(lVar2 + 0x48),uVar7,*param_3 / 2,param_3[1] / 2,

                        (param_3[2] + 1) / 2,(param_3[3] + 1) / 2,param_6,param_7);

  bVar5 = FUN_140204fe0(lVar1,uVar6,*(undefined8 *)(lVar2 + 0x50),uVar7,*param_3 / 2,param_3[1] / 2,

                        (param_3[2] + 1) / 2,(param_3[3] + 1) / 2,param_8,param_9);

  FUN_140136720(uVar6);

  return bVar5 & bVar4 & bVar3 & 1;

}




