// Address: 0x1401865d0
// Ghidra name: FUN_1401865d0
// ============ 0x1401865d0 FUN_1401865d0 (size=913) ============


void FUN_1401865d0(undefined8 param_1,ulonglong param_2,longlong param_3,longlong param_4,

                  int param_5,float param_6,float param_7,undefined4 param_8)



{

  char cVar1;

  longlong lVar2;

  longlong lVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  uint in_stack_ffffffffffffff08;

  int local_d8 [2];

  undefined8 local_d0;

  ulonglong local_c8;

  longlong local_c0;

  float local_b8;

  float local_b4;

  undefined8 local_b0;

  undefined4 local_a8;

  undefined4 local_a4;

  

  FUN_140186540();

  lVar2 = FUN_140186240(param_2);

  if (lVar2 == 0) goto LAB_14018693e;

  lVar3 = FUN_1401611a0();

  if ((param_2 < 0xfffffffffffffffe) && (*(char *)(lVar3 + 0xec) != '\0')) {

    if (param_4 == 0) {

      if (param_5 == 0x700) {

LAB_140186868:

        if (DAT_1403fcb68 == '\0') {

          DAT_1403fcb68 = '\x01';

          DAT_1403fcb70 = param_3;

          DAT_1403fcb78 = param_2;

        }

      }

      else {

LAB_140186740:

        if (((DAT_1403fcb68 == '\x01') && (DAT_1403fcb78 == param_2)) && (DAT_1403fcb70 == param_3))

        {

          DAT_1403fcb68 = '\0';

        }

      }

    }

    else if (param_5 == 0x700) {

      if (DAT_1403fcb68 == '\0') {

        fVar5 = (float)*(int *)(param_4 + 0x24) * param_7;

        fVar6 = (float)(*(int *)(param_4 + 0x24) + -1);

        fVar7 = 0.0;

        if (0.0 <= fVar5) {

          fVar7 = fVar5;

        }

        fVar5 = (float)(*(int *)(param_4 + 0x20) + -1);

        if (fVar7 <= fVar6) {

          fVar6 = fVar7;

        }

        fVar4 = (float)*(int *)(param_4 + 0x20) * param_6;

        fVar7 = 0.0;

        if (0.0 <= fVar4) {

          fVar7 = fVar4;

        }

        if (fVar7 <= fVar5) {

          fVar5 = fVar7;

        }

        FUN_1401628f0(param_1,param_4,0xffffffff,0,fVar5,fVar6);

        FUN_1401628d0(param_1,param_4,0xffffffff,1,1);

        goto LAB_140186868;

      }

    }

    else if (DAT_1403fcb68 == '\x01') {

      if ((DAT_1403fcb78 == param_2) && (DAT_1403fcb70 == param_3)) {

        FUN_1401628d0(param_1,param_4,0xffffffff,1,in_stack_ffffffffffffff08 & 0xffffff00);

      }

      goto LAB_140186740;

    }

  }

  if (((*(char *)(lVar3 + 0xed) != '\0') || (param_2 != 0xffffffffffffffff)) &&

     ((*(char *)(lVar3 + 0xef) != '\0' || (param_2 != 0xfffffffffffffffe)))) {

    lVar3 = FUN_1401861d0(lVar2,param_3);

    if (param_5 == 0x700) {

      if (lVar3 != 0) {

        FUN_1401865d0(param_1,param_2,param_3,param_4,0x703,param_6,param_7,param_8);

      }

      cVar1 = FUN_140185eb0(lVar2,param_3);

      if ((cVar1 != '\0') && (cVar1 = FUN_140139420(0x700), cVar1 != '\0')) {

        local_b8 = param_6;

        local_b4 = param_7;

        local_a8 = param_8;

        local_d8[0] = 0x700;

        local_b0 = 0;

        if (param_4 == 0) {

          local_a4 = 0;

          local_d0 = param_1;

          local_c8 = param_2;

          local_c0 = param_3;

          FUN_14013b140(local_d8);

        }

        else {

          local_d0 = param_1;

          local_c8 = param_2;

          local_c0 = param_3;

          local_a4 = FUN_14016e2d0(param_4);

          FUN_14013b140(local_d8);

        }

      }

    }

    else if (lVar3 != 0) {

      cVar1 = FUN_140139420(param_5);

      if (cVar1 != '\0') {

        local_b8 = *(float *)(lVar3 + 8);

        local_b4 = *(float *)(lVar3 + 0xc);

        local_a8 = param_8;

        local_d8[0] = param_5;

        local_b0 = 0;

        if (param_4 == 0) {

          local_a4 = 0;

          local_d0 = param_1;

          local_c8 = param_2;

          local_c0 = param_3;

        }

        else {

          local_d0 = param_1;

          local_c8 = param_2;

          local_c0 = param_3;

          local_a4 = FUN_14016e2d0(param_4);

        }

        FUN_14013b140(local_d8);

      }

      FUN_1401860a0(lVar2,param_3);

    }

  }

LAB_14018693e:

  FUN_140186c50();

  return;

}




