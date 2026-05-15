// Address: 0x140155510
// Ghidra name: FUN_140155510
// ============ 0x140155510 FUN_140155510 (size=256) ============


void FUN_140155510(uint *param_1)



{

  uint uVar1;

  uint uVar2;

  uint uVar3;

  undefined4 *puVar4;

  longlong lVar5;

  char cVar6;

  uint uVar7;

  undefined4 local_res8 [2];

  undefined8 local_res10;

  

  uVar7 = *param_1;

  puVar4 = *(undefined4 **)(param_1 + 0x3e);

  local_res10 = 0;

  local_res8[0] = 0;

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

  uVar1 = param_1[0x45];

  uVar2 = param_1[0x44];

  uVar3 = param_1[0x46];

  lVar5 = *(longlong *)(param_1 + 0x42);

  cVar6 = FUN_14014f910(puVar4,param_1 + 0x45,&local_res10,local_res8);

  if (cVar6 != '\0') {

    FUN_1401451c0(param_1[0x47],param_1[0x48],*param_1,

                  (longlong)(int)(uVar2 * uVar3) + (longlong)(int)(uVar7 * uVar1) + lVar5,uVar2,

                  *puVar4,local_res10,local_res8[0]);

    FUN_1401556c0(puVar4);

  }

  return;

}




