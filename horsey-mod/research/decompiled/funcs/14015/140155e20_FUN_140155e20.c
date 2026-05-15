// Address: 0x140155e20
// Ghidra name: FUN_140155e20
// ============ 0x140155e20 FUN_140155e20 (size=398) ============


undefined8 FUN_140155e20(undefined4 *param_1,longlong param_2,undefined8 param_3,undefined4 param_4)



{

  uint *puVar1;

  char cVar2;

  longlong lVar3;

  uint uVar4;

  undefined4 local_res8 [2];

  undefined8 local_38 [2];

  

  puVar1 = *(uint **)(param_1 + 0x3e);

  if (param_1[9] == 1) {

    local_38[0] = 0;

    local_res8[0] = 0;

    cVar2 = FUN_14014f910(puVar1,param_2,local_38,local_res8);

    if (cVar2 == '\0') {

      return 0;

    }

    FUN_140144d60(*(undefined4 *)(param_2 + 8),*(undefined4 *)(param_2 + 0xc),*param_1,param_1[6],0,

                  param_3,param_4,*puVar1,puVar1[6],0,local_38[0],local_res8[0]);

    FUN_1401556c0(puVar1);

  }

  else {

    uVar4 = *puVar1;

    if ((uVar4 == 0) || ((uVar4 & 0xf0000000) == 0x10000000)) {

      uVar4 = uVar4 & 0xff;

    }

    else if ((((uVar4 == 0x32595559) || (uVar4 == 0x59565955)) || (uVar4 == 0x55595659)) ||

            (uVar4 == 0x30313050)) {

      uVar4 = 2;

    }

    else {

      uVar4 = 1;

    }

    uVar4 = uVar4 * *(int *)(param_2 + 8) + 3 & 0xfffffffc;

    if ((longlong)*(int *)(param_2 + 0xc) * (longlong)(int)uVar4 != 0) {

      lVar3 = FUN_1401841f0();

      if (lVar3 == 0) {

        return 0;

      }

      FUN_140144d60(*(undefined4 *)(param_2 + 8),*(undefined4 *)(param_2 + 0xc),*param_1,param_1[6],

                    0,param_3,param_4,*puVar1,puVar1[6],0,lVar3,uVar4);

      FUN_140156430(puVar1,param_2,lVar3,uVar4);

      FUN_1401841e0(lVar3);

    }

  }

  return 1;

}




