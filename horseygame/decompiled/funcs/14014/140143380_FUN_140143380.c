// Address: 0x140143380
// Ghidra name: FUN_140143380
// ============ 0x140143380 FUN_140143380 (size=263) ============


undefined1

FUN_140143380(longlong param_1,int *param_2,undefined8 param_3,longlong param_4,undefined4 param_5)



{

  undefined4 uVar1;

  undefined4 uVar2;

  longlong lVar3;

  undefined1 uVar4;

  longlong lVar5;

  uint uVar6;

  

  uVar1 = *(undefined4 *)(param_1 + 8);

  uVar2 = *(undefined4 *)(param_1 + 0xc);

  lVar3 = *(longlong *)(param_1 + 0x18);

  *(int *)(param_1 + 8) = param_2[2];

  *(int *)(param_1 + 0xc) = param_2[3];

  uVar6 = *(uint *)(param_1 + 4);

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

  *(longlong *)(param_1 + 0x18) =

       (longlong)(int)(uVar6 * *param_2) + *(int *)(param_1 + 0x10) * param_2[1] + lVar3;

  lVar5 = FUN_140148140(param_1,*(undefined4 *)(param_4 + 8),*(undefined4 *)(param_4 + 0xc),param_5)

  ;

  if (lVar5 == 0) {

    uVar4 = 0;

  }

  else {

    uVar4 = FUN_140144390(lVar5,0,param_3,param_4);

    FUN_140146010(lVar5);

  }

  *(undefined4 *)(param_1 + 8) = uVar1;

  *(undefined4 *)(param_1 + 0xc) = uVar2;

  *(longlong *)(param_1 + 0x18) = lVar3;

  return uVar4;

}




