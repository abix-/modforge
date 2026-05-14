// Address: 0x140199ac0
// Ghidra name: FUN_140199ac0
// ============ 0x140199ac0 FUN_140199ac0 (size=279) ============


void FUN_140199ac0(longlong param_1,int *param_2,longlong param_3,int *param_4)



{

  uint uVar1;

  longlong lVar2;

  

  uVar1 = *(uint *)(param_3 + 4);

  if ((uVar1 == 0) || ((uVar1 & 0xf0000000) == 0x10000000)) {

    uVar1 = uVar1 & 0xff;

  }

  else if ((((uVar1 == 0x32595559) || (uVar1 == 0x59565955)) || (uVar1 == 0x55595659)) ||

          (uVar1 == 0x30313050)) {

    uVar1 = 2;

  }

  else {

    uVar1 = 1;

  }

  lVar2 = (longlong)(*(int *)(param_1 + 0x10) * param_2[1]) + (longlong)(int)(uVar1 * *param_2) +

          *(longlong *)(param_1 + 0x18);

  if (uVar1 == 4) {

    FUN_14019ad30(lVar2);

  }

  else if (uVar1 == 3) {

    FUN_14019ac40(lVar2);

  }

  else if (uVar1 == 2) {

    FUN_14019ab60();

  }

  else {

    FUN_14019aa90(lVar2,param_2[2],param_2[3],*(int *)(param_1 + 0x10),

                  (longlong)(*(int *)(param_3 + 0x10) * param_4[1]) +

                  (longlong)(int)(uVar1 * *param_4) + *(longlong *)(param_3 + 0x18),param_4[2],

                  param_4[3],*(int *)(param_3 + 0x10));

  }

  return;

}




