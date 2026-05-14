// Address: 0x1401d30e0
// Ghidra name: FUN_1401d30e0
// ============ 0x1401d30e0 FUN_1401d30e0 (size=842) ============


/* WARNING: Type propagation algorithm not settling */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



longlong FUN_1401d30e0(byte *param_1,double param_2,undefined4 param_3,undefined4 param_4,

                      undefined4 param_5,longlong param_6,double param_7,double param_8,

                      undefined8 param_9)



{

  bool bVar1;

  bool bVar2;

  double dVar3;

  char cVar4;

  uint uVar5;

  longlong lVar6;

  uint uVar7;

  uint in_stack_ffffffffffffff68;

  undefined8 in_stack_ffffffffffffff78;

  undefined4 uVar8;

  undefined4 local_68;

  int local_64 [15];

  

  uVar8 = (undefined4)((ulonglong)in_stack_ffffffffffffff78 >> 0x20);

  bVar2 = false;

  local_68 = 0;

  cVar4 = FUN_1401489c0();

  if (cVar4 == '\0') {

    return 0;

  }

  cVar4 = FUN_140148960(param_1);

  bVar1 = false;

  if ((cVar4 != '\0') && (cVar4 = FUN_140146750(param_1,&local_68), bVar1 = false, cVar4 != '\0')) {

    bVar1 = true;

  }

  dVar3 = _DAT_14034a978;

  uVar5 = *(uint *)(param_1 + 4);

  if (uVar5 == 0x13000801) {

    if (!bVar1) {

      return 0;

    }

    lVar6 = FUN_140145e60(*(undefined4 *)(param_6 + 8),*(int *)(param_6 + 0xc) + 2);

    if (lVar6 == 0) {

      return 0;

    }

    FUN_1401487f0(lVar6,*(undefined8 *)(param_1 + 0x48));

    *(undefined4 *)(lVar6 + 0xc) = *(undefined4 *)(param_6 + 0xc);

    FUN_1401465d0(param_1,local_64);

    bVar2 = true;

  }

  else {

    if (uVar5 == 0) {

      return 0;

    }

    if ((uVar5 & 0xf0000000) != 0x10000000) {

      return 0;

    }

    if ((uVar5 & 0xff00) != 0x2000) {

      return 0;

    }

    if ((uVar5 & 0xf0000) != 0x60000) {

      return 0;

    }

    lVar6 = FUN_140145e60(*(undefined4 *)(param_6 + 8),*(int *)(param_6 + 0xc) + 2);

    if (lVar6 == 0) {

      return 0;

    }

    *(undefined4 *)(lVar6 + 0xc) = *(undefined4 *)(param_6 + 0xc);

    FUN_1401465d0(param_1,local_64);

    if (!bVar1) {

      if (local_64[0] == 0) {

        local_64[0] = 1;

        bVar2 = false;

      }

      else if ((local_64[0] - 4U & 0xfffffffb) == 0) {

        local_68 = FUN_140146f80(lVar6,0xff,0xff,0xff,in_stack_ffffffffffffff68 & 0xffffff00);

        FUN_14017dc90(lVar6,0,local_68);

        FUN_140148630(lVar6,1,local_68);

        bVar2 = false;

      }

      goto LAB_1401d32db;

    }

  }

  FUN_140148630(lVar6,1,local_68);

  FUN_14017dc90(lVar6,0,local_68);

LAB_1401d32db:

  param_7 = param_7 * dVar3;

  param_8 = param_8 * dVar3;

  FUN_140148450(lVar6,local_64[0]);

  if (((*param_1 & 2) != 0) && (cVar4 = FUN_140146f20(param_1), cVar4 == '\0')) {

    FUN_140146010(lVar6);

    return 0;

  }

  uVar5 = (uint)(param_2 / _DAT_14034a968);

  if ((double)(int)uVar5 == param_2 / _DAT_14034a968) {

    uVar5 = uVar5 & 0x80000003;

    if ((int)uVar5 < 0) {

      uVar5 = (uVar5 - 1 | 0xfffffffc) + 1;

    }

    uVar7 = uVar5 + 4;

    if (-1 < (int)uVar5) {

      uVar7 = uVar5;

    }

  }

  else {

    uVar7 = 0xffffffff;

  }

  if (bVar2) {

    if ((int)uVar7 < 0) {

      FUN_1401d4070(param_1,lVar6,(int)param_8,(int)param_7,param_4,param_5,param_6,param_9);

    }

    else {

      FUN_1401d4300(param_1,lVar6,uVar7,param_4,param_5);

    }

  }

  else if ((int)uVar7 < 0) {

    FUN_1401d38e0(param_1,lVar6,(int)param_8,(int)param_7,param_4,param_5,CONCAT44(uVar8,param_3),

                  param_6,param_9);

  }

  else {

    FUN_1401d3f30(param_1,lVar6,uVar7,param_4,param_5);

  }

  if ((*param_1 & 2) != 0) {

    FUN_1401489e0(param_1);

    return lVar6;

  }

  return lVar6;

}




