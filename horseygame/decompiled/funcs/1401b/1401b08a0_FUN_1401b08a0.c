// Address: 0x1401b08a0
// Ghidra name: FUN_1401b08a0
// ============ 0x1401b08a0 FUN_1401b08a0 (size=504) ============


undefined8 * FUN_1401b08a0(longlong param_1,int *param_2)



{

  char cVar1;

  int iVar2;

  undefined8 *puVar3;

  undefined8 uVar4;

  undefined4 local_98 [2];

  undefined8 local_90;

  undefined4 local_88;

  undefined8 local_80;

  undefined8 local_78;

  undefined4 local_68 [2];

  undefined8 local_60;

  undefined4 local_58;

  undefined4 local_54;

  undefined4 local_50;

  undefined4 local_4c;

  undefined4 local_48;

  undefined4 local_44;

  undefined4 local_40;

  int local_3c;

  uint local_38;

  int local_34;

  uint local_30;

  undefined4 local_2c;

  int local_28;

  int local_24;

  undefined8 local_20;

  

  puVar3 = (undefined8 *)FUN_1401841f0(0x10);

  local_3c = param_2[6];

  local_54 = *(undefined4 *)(&DAT_1403e4268 + (longlong)param_2[1] * 4);

  local_50 = *(undefined4 *)(&DAT_1403e4268 + (longlong)*param_2 * 4);

  local_4c = *(undefined4 *)(&DAT_1403e4270 + (longlong)param_2[2] * 4);

  local_24 = param_2[10];

  local_34 = param_2[7];

  local_48 = *(undefined4 *)(&DAT_1403e4278 + (longlong)param_2[3] * 4);

  local_28 = param_2[9];

  local_44 = *(undefined4 *)(&DAT_1403e4278 + (longlong)param_2[4] * 4);

  local_68[0] = 0x1f;

  local_40 = *(undefined4 *)(&DAT_1403e4278 + (longlong)param_2[5] * 4);

  local_38 = (uint)*(byte *)(param_2 + 0xb);

  local_30 = (uint)*(byte *)((longlong)param_2 + 0x2d);

  local_60 = 0;

  local_58 = 0;

  local_20 = 0;

  local_2c = *(undefined4 *)(&DAT_1403e41e0 + (longlong)param_2[8] * 4);

  iVar2 = (**(code **)(param_1 + 0xb58))(*(undefined8 *)(param_1 + 0x570),local_68,0,puVar3);

  if (iVar2 == 0) {

    FUN_140139010(puVar3 + 1,0);

    if (((*(char *)(param_1 + 0x57c) != '\0') && (*(char *)(param_1 + 0x58e) != '\0')) &&

       (cVar1 = FUN_140174fc0(param_2[0xc],"SDL.gpu.sampler.create.name"), cVar1 != '\0')) {

      local_98[0] = 0x3b9cbe00;

      local_90 = 0;

      local_78 = FUN_140174e70(param_2[0xc],"SDL.gpu.sampler.create.name",0);

      local_80 = *puVar3;

      local_88 = 0x15;

      (**(code **)(param_1 + 0x9d0))(*(undefined8 *)(param_1 + 0x570),local_98);

    }

  }

  else {

    FUN_1401841e0(puVar3);

    if (*(char *)(param_1 + 0x57c) != '\0') {

      uVar4 = FUN_1401c0ba0(iVar2);

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(9,"%s %s","vkCreateSampler",uVar4);

    }

    uVar4 = FUN_1401c0ba0(iVar2);

    FUN_14012e850("%s %s","vkCreateSampler",uVar4);

    puVar3 = (undefined8 *)0x0;

  }

  return puVar3;

}




