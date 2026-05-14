// Address: 0x14019aee0
// Ghidra name: FUN_14019aee0
// ============ 0x14019aee0 FUN_14019aee0 (size=661) ============


ulonglong FUN_14019aee0(ulonglong param_1,ulonglong param_2,int param_3,undefined4 param_4,

                       undefined8 param_5,undefined8 param_6,int param_7,int param_8,

                       undefined4 param_9,undefined4 param_10,undefined8 param_11,

                       undefined4 param_12)



{

  char cVar1;

  byte bVar2;

  ulonglong uVar3;

  ulonglong uVar4;

  ulonglong uVar5;

  longlong lVar6;

  int local_res18 [2];

  ulonglong *puVar7;

  uint uVar8;

  undefined8 in_stack_ffffffffffffffa0;

  undefined4 uVar9;

  ulonglong local_28;

  ulonglong local_20;

  

  uVar9 = (undefined4)((ulonglong)in_stack_ffffffffffffffa0 >> 0x20);

  uVar3 = param_1 & 0xffffffff;

  if (param_3 == 0x47504a4d) {

    if (param_8 == 0x3231564e) {

      uVar3 = FUN_14019ae40(param_1,param_2,param_6,param_7,param_11,CONCAT44(uVar9,param_12));

      return uVar3;

    }

    if (((((param_8 == 0x32315659) || (param_8 == 0x56555949)) || (param_8 == 0x32595559)) ||

        ((param_8 == 0x59565955 || (param_8 == 0x55595659)))) ||

       ((param_8 == 0x3132564e || (param_8 == 0x30313050)))) {

      local_28 = 0;

      local_20 = 0;

      uVar4 = FUN_1401d47f0(param_8,uVar3,param_2 & 0xffffffff,&local_28,&local_20);

      if ((char)uVar4 != '\0') {

        uVar5 = FUN_1401841f0(local_28);

        uVar4 = 0;

        if (uVar5 == 0) goto LAB_14019aff8;

        uVar4 = uVar5;

        cVar1 = FUN_14019ae40(param_1 & 0xffffffff,param_2 & 0xffffffff,param_6,param_7,uVar5,

                              CONCAT44(uVar9,(undefined4)local_20));

        if (cVar1 == '\0') {

          uVar4 = FUN_1401841e0(uVar5);

          goto LAB_14019aff8;

        }

        bVar2 = FUN_140144d60(uVar3,param_2 & 0xffffffff,0x3231564e,param_4,

                              uVar4 & 0xffffffff00000000,uVar5,(undefined4)local_20,param_8,param_9,

                              param_10,param_11,param_12);

        FUN_1401841e0(uVar5);

        goto LAB_14019b158;

      }

      goto LAB_14019aff8;

    }

  }

  local_28 = local_28 & 0xffffffff00000000;

  local_res18[0] = 0;

  local_20 = local_20 & 0xffffffff00000000;

  if (param_3 != 0x47504a4d) {

    param_7 = (int)param_2 * param_7;

  }

  puVar7 = &local_20;

  lVar6 = FUN_1401a52c0(param_6,param_7,&local_28,local_res18,puVar7,CONCAT44(uVar9,4));

  uVar4 = 0;

  if (lVar6 != 0) {

    uVar8 = (uint)((ulonglong)puVar7 >> 0x20);

    if (((int)local_28 == (int)param_1) && (local_res18[0] == (int)param_2)) {

      bVar2 = FUN_140144d60(local_28 & 0xffffffff,local_res18[0],0x16762004,0x120005a0,

                            (ulonglong)uVar8 << 0x20,lVar6,(int)param_1 * 4,param_8,param_9,param_10

                            ,param_11,param_12);

    }

    else {

      bVar2 = FUN_14012e850("Expected image size %dx%d, actual size %dx%d",uVar3,

                            param_2 & 0xffffffff,local_28 & 0xffffffff,

                            CONCAT44(uVar8,local_res18[0]));

    }

    FUN_140160120(lVar6);

LAB_14019b158:

    return (ulonglong)bVar2;

  }

LAB_14019aff8:

  return uVar4 & 0xffffffffffffff00;

}




