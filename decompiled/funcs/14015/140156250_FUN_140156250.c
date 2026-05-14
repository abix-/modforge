// Address: 0x140156250
// Ghidra name: FUN_140156250
// ============ 0x140156250 FUN_140156250 (size=477) ============


ulonglong FUN_140156250(longlong param_1)



{

  uint *puVar1;

  byte bVar2;

  ulonglong uVar3;

  longlong lVar4;

  uint uVar5;

  uint uVar6;

  undefined4 local_res8 [2];

  undefined8 in_stack_00000028;

  uint in_stack_00000030;

  undefined8 in_stack_00000038;

  undefined4 in_stack_00000040;

  ulonglong uVar7;

  undefined8 local_38;

  undefined8 local_30;

  int local_28;

  int local_24;

  

  puVar1 = *(uint **)(param_1 + 0xf8);

  bVar2 = 1;

  uVar7 = (ulonglong)in_stack_00000030;

  uVar3 = FUN_140206400(*(undefined8 *)(param_1 + 0x100));

  if ((char)uVar3 == '\0') {

LAB_140156416:

    uVar3 = uVar3 & 0xffffffffffffff00;

  }

  else {

    local_28 = *(int *)(param_1 + 4);

    local_24 = *(int *)(param_1 + 8);

    local_30 = 0;

    if ((local_28 != 0) && (local_24 != 0)) {

      if (*(int *)(param_1 + 0x24) == 1) {

        local_38 = 0;

        local_res8[0] = 0;

        uVar3 = FUN_14014f910(puVar1,&local_30,&local_38,local_res8,in_stack_00000028,uVar7,

                              in_stack_00000038);

        if ((char)uVar3 != '\0') {

          bVar2 = FUN_140205a00(*(undefined8 *)(param_1 + 0x100),&local_30,*puVar1,local_28,local_24

                                ,local_38,local_res8[0],in_stack_00000040);

          FUN_1401556c0(puVar1);

          return (ulonglong)bVar2;

        }

        goto LAB_140156416;

      }

      uVar5 = *puVar1;

      if ((uVar5 == 0) || ((uVar5 & 0xf0000000) == 0x10000000)) {

        uVar5 = uVar5 & 0xff;

      }

      else if ((((uVar5 == 0x32595559) || (uVar5 == 0x59565955)) || (uVar5 == 0x55595659)) ||

              (uVar5 == 0x30313050)) {

        uVar5 = 2;

      }

      else {

        uVar5 = 1;

      }

      uVar5 = uVar5 * local_28 + 3;

      uVar6 = uVar5 & 0xfffffffc;

      if ((longlong)(int)uVar6 * (longlong)local_24 != 0) {

        lVar4 = FUN_1401841f0();

        uVar3 = 0;

        if (lVar4 == 0) goto LAB_140156416;

        bVar2 = FUN_140205a00(*(undefined8 *)(param_1 + 0x100),&local_30,*puVar1,local_28,local_24,

                              lVar4,CONCAT44((int)((ulonglong)in_stack_00000038 >> 0x20),uVar5) &

                                    0xfffffffffffffffc,in_stack_00000040);

        if (bVar2 != 0) {

          FUN_140156430(puVar1,&local_30,lVar4,uVar6);

        }

        FUN_1401841e0(lVar4);

      }

    }

    uVar3 = (ulonglong)bVar2;

  }

  return uVar3;

}




