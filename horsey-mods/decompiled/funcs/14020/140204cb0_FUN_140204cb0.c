// Address: 0x140204cb0
// Ghidra name: FUN_140204cb0
// ============ 0x140204cb0 FUN_140204cb0 (size=816) ============


byte FUN_140204cb0(longlong param_1,uint *param_2,int *param_3,longlong param_4,int param_5)



{

  longlong lVar1;

  longlong lVar2;

  byte bVar3;

  byte bVar4;

  byte bVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  undefined8 uVar9;

  longlong lVar10;

  uint uVar11;

  uint uVar12;

  

  lVar1 = *(longlong *)(param_1 + 0x2e0);

  lVar2 = *(longlong *)(param_2 + 0x4e);

  uVar9 = FUN_140132c70(*(undefined8 *)(lVar1 + 0xa0));

  uVar12 = *param_2;

  if ((uVar12 == 0) || ((uVar12 & 0xf0000000) == 0x10000000)) {

    uVar12 = uVar12 & 0xff;

  }

  else if ((((uVar12 == 0x32595559) || (uVar12 == 0x59565955)) || (uVar12 == 0x55595659)) ||

          (uVar12 == 0x30313050)) {

    uVar12 = 2;

  }

  else {

    uVar12 = 1;

  }

  bVar3 = FUN_140204fe0(lVar1,uVar9,*(undefined8 *)(lVar2 + 8),uVar12,*param_3,param_3[1],param_3[2]

                        ,param_3[3],param_4,param_5);

  if (*(char *)(lVar2 + 0x58) == '\0') {

    if (*(char *)(lVar2 + 0x40) != '\0') {

      iVar6 = (param_5 + 1) / 2;

      param_4 = param_3[3] * param_5 + param_4;

      iVar7 = (param_3[3] + 1) / 2;

      lVar10 = iVar7 * iVar6 + param_4;

      iVar8 = (param_3[2] + 1) / 2;

      if (*param_2 == 0x32315659) {

        bVar4 = FUN_140204fe0(lVar1,uVar9,*(undefined8 *)(lVar2 + 0x50),uVar12,*param_3 / 2,

                              param_3[1] / 2,iVar8,iVar7,param_4,iVar6);

        bVar5 = FUN_140204fe0(lVar1,uVar9,*(undefined8 *)(lVar2 + 0x48),uVar12,*param_3 / 2,

                              param_3[1] / 2,(param_3[2] + 1) / 2,(param_3[3] + 1) / 2,lVar10,iVar6)

        ;

        bVar3 = bVar5 & (bVar4 & bVar3) != 0;

      }

      else {

        bVar4 = FUN_140204fe0(lVar1,uVar9,*(undefined8 *)(lVar2 + 0x48),uVar12,*param_3 / 2,

                              param_3[1] / 2,iVar8,iVar7,param_4,iVar6);

        bVar5 = FUN_140204fe0(lVar1,uVar9,*(undefined8 *)(lVar2 + 0x50),uVar12,*param_3 / 2,

                              param_3[1] / 2,(param_3[2] + 1) / 2,(param_3[3] + 1) / 2,lVar10,iVar6)

        ;

        bVar3 = bVar5 & (bVar4 & bVar3) != 0;

      }

    }

  }

  else {

    if (*param_2 == 0x30313050) {

      uVar11 = param_5 + 3U & 0xfffffffc;

    }

    else {

      uVar11 = param_5 + 1U & 0xfffffffe;

    }

    bVar4 = FUN_140204fe0(lVar1,uVar9,*(undefined8 *)(lVar2 + 0x60),uVar12 * 2,*param_3 / 2,

                          param_3[1] / 2,(param_3[2] + 1) / 2,(param_3[3] + 1) / 2,

                          param_3[3] * param_5 + param_4,uVar11);

    bVar3 = (bVar3 & bVar4) != 0;

  }

  FUN_140136720(uVar9);

  return bVar3;

}




