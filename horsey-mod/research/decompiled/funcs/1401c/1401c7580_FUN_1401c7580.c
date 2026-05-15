// Address: 0x1401c7580
// Ghidra name: FUN_1401c7580
// ============ 0x1401c7580 FUN_1401c7580 (size=857) ============


undefined8 *

FUN_1401c7580(longlong param_1,uint param_2,ulonglong param_3,int param_4,undefined8 param_5)



{

  int iVar1;

  undefined8 *puVar2;

  undefined8 uVar3;

  char *pcVar4;

  uint uVar5;

  int iVar6;

  undefined8 in_stack_fffffffffffffef8;

  undefined4 uVar7;

  undefined8 local_e8;

  undefined4 local_e0;

  undefined8 local_dc;

  longlong *local_d0;

  undefined4 local_c8 [2];

  undefined8 local_c0;

  ulonglong local_b8;

  undefined4 local_b0;

  undefined8 local_ac;

  undefined8 local_a4;

  undefined4 local_9c;

  uint local_98;

  undefined4 local_90;

  undefined4 local_8c;

  undefined8 local_88;

  uint local_80;

  undefined4 local_7c;

  undefined8 local_78;

  undefined4 local_70;

  undefined4 local_68;

  undefined4 local_64;

  undefined4 local_60;

  undefined8 local_58;

  uint local_50;

  undefined4 local_4c;

  undefined4 local_48;

  undefined8 local_40;

  undefined4 local_38;

  

  uVar7 = (undefined4)((ulonglong)in_stack_fffffffffffffef8 >> 0x20);

  iVar6 = 0;

  puVar2 = (undefined8 *)FUN_1401841a0();

  if (puVar2 == (undefined8 *)0x0) {

    return (undefined8 *)0x0;

  }

  local_98 = -(uint)((param_2 & 0x20) != 0) & 4;

  local_dc = 0;

  if (param_4 == 0) {

    local_e8 = 1;

  }

  else if (param_4 == 2) {

LAB_1401c7636:

    iVar6 = 0xac3;

    local_e8 = 2;

  }

  else if (param_4 == 3) {

    local_e8 = 3;

    iVar6 = 0x400;

  }

  else {

    if (param_4 != 1) {

      if (*(char *)(param_1 + 0x98) == '\0') {

        FUN_14012e850(&DAT_14039bf30,"Unrecognized buffer type!");

        return (undefined8 *)0x0;

      }

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(9,&DAT_14039bf30,"Unrecognized buffer type!");

    }

    if (*(char *)(param_1 + 0x99) == '\0') goto LAB_1401c7636;

    local_e8 = 5;

  }

  local_c8[0] = 1;

  local_b0 = 1;

  local_a4 = 1;

  local_9c = 1;

  local_e0 = 0;

  local_c0 = 0x10000;

  local_ac = 0x10001;

  local_b8 = param_3 & 0xffffffff;

  iVar1 = (**(code **)(**(longlong **)(param_1 + 0x70) + 0xd8))

                    (*(longlong **)(param_1 + 0x70),&local_e8,0,local_c8,CONCAT44(uVar7,iVar6),0,

                     &DAT_1403492f8,&local_d0);

  if (iVar1 < 0) {

    pcVar4 = "Could not create buffer!";

    goto LAB_1401c76be;

  }

  puVar2[2] = local_d0;

  FUN_140139010(puVar2 + 0x11,0);

  uVar5 = (uint)(param_3 >> 2) & 0x3fffffff;

  puVar2[4] = 0;

  puVar2[8] = 0;

  puVar2[0xc] = 0;

  if ((param_2 & 0x20) != 0) {

    FUN_1401c5df0(param_1,0,puVar2 + 3);

    local_90 = 0x27;

    local_8c = 1;

    local_88 = 0;

    local_70 = 1;

    local_78 = 0;

    local_7c = 0;

    local_80 = uVar5;

    (**(code **)(**(longlong **)(param_1 + 0x70) + 0x98))

              (*(longlong **)(param_1 + 0x70),local_d0,0,&local_90,puVar2[5]);

  }

  if ((param_2 & 0x18) != 0) {

    FUN_1401c5df0(param_1,0,puVar2 + 7);

    local_68 = 0x27;

    local_60 = 0x1688;

    local_64 = 1;

    local_58 = 0;

    local_48 = 1;

    local_4c = 0;

    local_50 = uVar5;

    (**(code **)(**(longlong **)(param_1 + 0x70) + 0x90))

              (*(longlong **)(param_1 + 0x70),local_d0,&local_68,puVar2[9]);

  }

  if (param_4 == 1) {

    FUN_1401c5df0(param_1,0,puVar2 + 0xb);

    local_40 = (**(code **)(*local_d0 + 0x58))();

    local_38 = (int)param_3;

    (**(code **)(**(longlong **)(param_1 + 0x70) + 0x88))

              (*(longlong **)(param_1 + 0x70),&local_40,puVar2[0xd]);

    puVar2[0xf] = 0;

LAB_1401c7807:

    uVar3 = (**(code **)(*(longlong *)puVar2[2] + 0x58))();

    puVar2[0xf] = uVar3;

  }

  else {

    puVar2[0xf] = 0;

    if (param_4 == 0) goto LAB_1401c7807;

  }

  puVar2[0x10] = 0;

  if ((param_4 != 2) ||

     (iVar1 = (**(code **)(*(longlong *)puVar2[2] + 0x40))((longlong *)puVar2[2],0,0), -1 < iVar1))

  {

    *puVar2 = 0;

    *(undefined4 *)(puVar2 + 1) = 0;

    *(bool *)((longlong)puVar2 + 0x8c) = iVar6 != 0;

    FUN_140139010(puVar2 + 0x11,0);

    FUN_1401cb3d0(param_1,puVar2[2],param_5);

    return puVar2;

  }

  pcVar4 = "Failed to map upload buffer!";

LAB_1401c76be:

  FUN_1401cb240(param_1,pcVar4,iVar1);

  FUN_1401c95c0(puVar2);

  return (undefined8 *)0x0;

}




