// Address: 0x1401bdf00
// Ghidra name: FUN_1401bdf00
// ============ 0x1401bdf00 FUN_1401bdf00 (size=685) ============


ulonglong FUN_1401bdf00(longlong param_1,uint *param_2,undefined8 param_3,undefined8 param_4)



{

  byte bVar1;

  byte bVar2;

  byte bVar3;

  ulonglong uVar4;

  undefined8 uVar5;

  undefined4 local_328;

  undefined4 uStack_324;

  undefined8 uStack_320;

  undefined8 local_318;

  undefined8 uStack_310;

  undefined8 local_308;

  undefined8 uStack_300;

  undefined8 local_2f8;

  undefined8 uStack_2f0;

  undefined8 local_2e8;

  undefined8 *local_2e0;

  undefined8 local_2d8;

  undefined8 uStack_2d0;

  undefined8 local_2c8;

  undefined8 *local_2c0;

  undefined8 local_2b8;

  undefined8 local_2b0;

  undefined8 *local_2a8;

  undefined8 local_2a0;

  undefined8 local_298;

  undefined8 *local_290;

  undefined8 local_288;

  undefined8 local_280;

  undefined8 uStack_278;

  undefined8 local_270;

  undefined8 local_268;

  undefined8 *local_260;

  undefined8 local_258;

  undefined8 uStack_250;

  undefined8 local_248;

  undefined8 uStack_240;

  undefined8 local_238;

  undefined8 uStack_230;

  undefined8 local_228;

  undefined8 uStack_220;

  undefined8 local_218;

  undefined8 uStack_210;

  undefined8 local_208;

  undefined8 uStack_200;

  undefined4 local_1f8 [2];

  undefined8 *local_1f0;

  undefined4 local_108 [2];

  undefined4 *local_100;

  

  if ((*param_2 & 0x3ff000) < 0x1000) {

    uVar4 = FUN_1401be1b0(param_2 + 1,param_4);

  }

  else if ((*param_2 & 0x3ff000) < 0x2000) {

    local_2e8 = 0x3b9c0e38;

    local_2b8 = 0;

    uStack_278 = 0;

    local_2a0 = 0;

    local_288 = 0;

    local_270 = 0;

    local_2d8 = 0;

    uStack_2d0 = 0;

    local_268 = 0x3b9b9909;

    local_258 = 0;

    uStack_250 = 0;

    local_2c8 = 0x3b9d0069;

    local_2b0 = 0x3b9d2b64;

    local_298 = 0x3b9bc018;

    local_280 = 0x3b9c9ec0;

    FUN_1402f94c0(local_1f8,0,0xf0);

    local_1f0 = &local_2e8;

    local_1f8[0] = 0x3b9bb078;

    local_2e0 = &local_268;

    local_260 = &local_2c8;

    local_2c0 = &local_2b0;

    local_2a8 = &local_298;

    local_290 = &local_280;

    (**(code **)(param_1 + 0x990))(param_3,local_1f8);

    local_318 = local_2d8;

    uStack_310 = uStack_2d0;

    local_308 = local_258;

    uStack_2f0 = CONCAT44((undefined4)local_288,(int)local_2a0);

    local_2f8 = CONCAT44((int)local_2b8,local_270._4_4_);

    uStack_300 = CONCAT44((undefined4)local_270,(int)uStack_250);

    uStack_324 = 0;

    uStack_320._0_4_ = 0;

    uStack_320._4_4_ = 0;

    local_328 = 0x31;

    bVar1 = FUN_1401be1b0(param_2 + 1,param_4);

    uVar5 = FUN_1401be910(param_2 + 0x38,&local_328);

    uVar4 = CONCAT71((int7)((ulonglong)uVar5 >> 8),(byte)uVar5 & bVar1);

  }

  else {

    local_328 = 0x31;

    uStack_324 = 0;

    local_308 = 0;

    uStack_300 = 0;

    local_318 = 0;

    uStack_310 = 0;

    local_2f8 = 0;

    uStack_2f0 = 0;

    FUN_1402f94c0(local_1f8,0,0xd0);

    local_1f8[0] = 0x33;

    uStack_240 = 0;

    local_248 = 0x35;

    local_238 = 0;

    uStack_230 = 0;

    local_228 = 0;

    uStack_220 = 0;

    local_218 = 0;

    uStack_210 = 0;

    local_208 = 0;

    uStack_200 = 0;

    FUN_1402f94c0(local_108,0,0xf0);

    local_100 = &local_328;

    local_108[0] = 0x3b9bb078;

    uStack_320 = local_1f8;

    local_1f0 = &local_248;

    (**(code **)(param_1 + 0x990))(param_3,local_108);

    bVar1 = FUN_1401be1b0(param_2 + 1,param_4);

    bVar2 = FUN_1401be910(param_2 + 0x38,&local_328);

    bVar3 = FUN_1401beac0(param_2 + 0x48,local_1f8);

    uVar5 = FUN_1401bf120(param_2 + 0x7c,&local_248);

    uVar4 = CONCAT71((int7)((ulonglong)uVar5 >> 8),(byte)uVar5 & bVar3 & bVar2 & bVar1);

  }

  return uVar4 & 0xffffffffffffff01;

}




