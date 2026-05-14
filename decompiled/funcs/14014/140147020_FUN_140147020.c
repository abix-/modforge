// Address: 0x140147020
// Ghidra name: FUN_140147020
// ============ 0x140147020 FUN_140147020 (size=1011) ============


ulonglong FUN_140147020(undefined4 param_1,undefined4 param_2,uint param_3,int param_4,

                       undefined4 param_5,ulonglong param_6,int param_7,uint param_8,int param_9,

                       undefined4 param_10,ulonglong param_11,int param_12,char param_13)



{

  byte bVar1;

  int iVar2;

  char cVar3;

  ulonglong uVar4;

  longlong lVar5;

  uint uVar6;

  int iVar7;

  int iVar8;

  undefined8 in_stack_ffffffffffffff88;

  undefined4 uVar10;

  ulonglong uVar9;

  

  iVar2 = param_12;

  uVar10 = (undefined4)((ulonglong)in_stack_ffffffffffffff88 >> 0x20);

  lVar5 = 0;

  bVar1 = 0;

  param_12._0_1_ = 0;

  if (param_6 == 0) {

    uVar4 = FUN_14012e850("Parameter \'%s\' is invalid",&DAT_1403141a4);

    return uVar4;

  }

  if (param_7 == 0) {

    uVar4 = FUN_14012e850("Parameter \'%s\' is invalid","src_pitch");

    return uVar4;

  }

  if (param_11 == 0) {

    uVar4 = FUN_14012e850("Parameter \'%s\' is invalid",&DAT_140331e9c);

    return uVar4;

  }

  if (iVar2 == 0) {

    uVar4 = FUN_14012e850("Parameter \'%s\' is invalid","dst_pitch");

    return uVar4;

  }

  if (((param_13 == '\0') &&

      (((param_3 == 0 || ((param_3 & 0xf0000000) != 0x10000000)) ||

       ((((param_3 & 0xf000000) != 0x6000000 || ((param_3 & 0xf0000) != 0x70000)) &&

        ((param_3 & 0xff00) < 0x2001)))))) &&

     (((param_8 == 0 || ((param_8 & 0xf0000000) != 0x10000000)) ||

      ((((param_8 & 0xf000000) != 0x6000000 || ((param_8 & 0xf0000) != 0x70000)) &&

       ((param_8 & 0xff00) < 0x2001)))))) {

    iVar7 = 0x120005a0;

    if ((param_3 + 0xe9c9dffc & 0xffafffff) != 0) {

      uVar6 = 0x16362004;

      goto LAB_1401471c1;

    }

LAB_14014728e:

    uVar6 = param_3;

    if (param_4 != iVar7) goto LAB_1401471c1;

    if ((param_8 != param_3) || (uVar4 = param_11, iVar8 = iVar2, param_9 != iVar7)) {

      lVar5 = FUN_140145e60(param_1,param_2,param_3);

      if (lVar5 == 0) goto LAB_1401473e6;

      uVar4 = *(ulonglong *)(lVar5 + 0x18);

      iVar8 = *(int *)(lVar5 + 0x10);

    }

LAB_1401472d1:

    uVar9 = uVar4;

    if ((int)param_3 < 0x16862005) {

      if (param_3 == 0x16862004) {

LAB_140147310:

        FUN_140147680(param_1,param_2,param_6,param_7,uVar4,iVar8);

      }

      else {

        if (param_3 != 0x16362004) {

          if (param_3 == 0x16462004) goto LAB_140147310;

          if (param_3 != 0x16762004) goto LAB_14014733d;

        }

        FUN_1401474b0(param_1,param_2,param_6,param_7,uVar4,iVar8);

      }

LAB_140147369:

      if ((uVar4 == param_11) ||

         (cVar3 = FUN_140144d60(param_1,param_2,param_3,iVar7,uVar9 & 0xffffffff00000000,

                                *(undefined8 *)(lVar5 + 0x18),*(undefined4 *)(lVar5 + 0x10),param_8,

                                param_9,param_10,param_11,iVar2), param_12._0_1_ = bVar1,

         cVar3 != '\0')) {

        param_12._0_1_ = 1;

      }

    }

    else {

      if ((param_3 == 0x1b308010) || (param_3 == 0x1b608010)) {

        FUN_140147420(param_1,param_2,param_6,param_7,uVar4,iVar8);

        goto LAB_140147369;

      }

LAB_14014733d:

      FUN_14012e850("Unexpected internal pixel format");

      param_12._0_1_ = bVar1;

    }

    if (lVar5 == 0) goto LAB_1401473e6;

  }

  else {

    if ((param_3 == 0x1b308010) || (param_3 == 0x1b608010)) {

      iVar7 = 0x12000500;

      if (param_13 == '\0') {

        iVar7 = 0x120005a0;

      }

      goto LAB_14014728e;

    }

    uVar6 = 0x1b308010;

    iVar7 = 0x12000500;

    if (param_13 == '\0') {

      iVar7 = 0x120005a0;

    }

LAB_1401471c1:

    lVar5 = FUN_140145e60(param_1,param_2,uVar6);

    if (lVar5 == 0) goto LAB_1401473e6;

    cVar3 = FUN_140144d60(param_1,param_2,param_3,param_4,CONCAT44(uVar10,param_5),param_6,param_7,

                          uVar6,iVar7,0,*(undefined8 *)(lVar5 + 0x18),*(undefined4 *)(lVar5 + 0x10))

    ;

    param_12._0_1_ = bVar1;

    if (cVar3 != '\0') {

      param_6 = *(ulonglong *)(lVar5 + 0x18);

      param_7 = *(int *)(lVar5 + 0x10);

      uVar4 = param_6;

      param_3 = uVar6;

      iVar8 = param_7;

      goto LAB_1401472d1;

    }

  }

  FUN_140146010(lVar5);

LAB_1401473e6:

  return (ulonglong)(byte)param_12;

}




