// Address: 0x140186970
// Ghidra name: FUN_140186970
// ============ 0x140186970 FUN_140186970 (size=677) ============


void FUN_140186970(undefined8 param_1,ulonglong param_2,longlong param_3,longlong param_4,

                  float param_5,float param_6,float param_7)



{

  char cVar1;

  longlong lVar2;

  longlong lVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  undefined4 local_f8 [2];

  undefined8 local_f0;

  ulonglong local_e8;

  longlong local_e0;

  float local_d8;

  float local_d4;

  float local_d0;

  float local_cc;

  float local_c8;

  undefined4 local_c4;

  

  FUN_140186540();

  lVar2 = FUN_140186240(param_2);

  if (lVar2 != 0) {

    lVar3 = FUN_1401611a0();

    if ((((param_2 < 0xfffffffffffffffe) && (*(char *)(lVar3 + 0xec) != '\0')) && (param_4 != 0)) &&

       (((DAT_1403fcb68 == '\x01' && (DAT_1403fcb78 == param_2)) && (DAT_1403fcb70 == param_3)))) {

      fVar4 = (float)*(int *)(param_4 + 0x24) * param_6;

      fVar7 = (float)(*(int *)(param_4 + 0x24) + -1);

      fVar6 = 0.0;

      if (0.0 <= fVar4) {

        fVar6 = fVar4;

      }

      if (fVar6 <= fVar7) {

        fVar7 = fVar6;

      }

      fVar5 = (float)*(int *)(param_4 + 0x20) * param_5;

      fVar6 = (float)(*(int *)(param_4 + 0x20) + -1);

      fVar4 = 0.0;

      if (0.0 <= fVar5) {

        fVar4 = fVar5;

      }

      if (fVar4 <= fVar6) {

        fVar6 = fVar4;

      }

      FUN_1401628f0(param_1,param_4,0xffffffff,0,fVar6,fVar7);

    }

    if ((*(char *)(lVar3 + 0xed) != '\0') || (param_2 != 0xffffffffffffffff)) {

      lVar2 = FUN_1401861d0(lVar2,param_3);

      if (lVar2 == 0) {

        FUN_1401865d0(param_1,param_2,param_3,param_4,0x700,param_5,param_6,param_7);

      }

      else {

        fVar7 = param_6 - *(float *)(lVar2 + 0xc);

        fVar6 = param_5 - *(float *)(lVar2 + 8);

        if (((fVar6 != 0.0) || (fVar7 != 0.0)) || (param_7 - *(float *)(lVar2 + 0x10) != 0.0)) {

          *(float *)(lVar2 + 8) = param_5;

          *(float *)(lVar2 + 0xc) = param_6;

          *(float *)(lVar2 + 0x10) = param_7;

          cVar1 = FUN_140139420(0x702);

          if (cVar1 != '\0') {

            local_d8 = param_5;

            local_d4 = param_6;

            local_c8 = param_7;

            local_f8[0] = 0x702;

            local_f0 = param_1;

            local_e8 = param_2;

            local_e0 = param_3;

            local_d0 = fVar6;

            local_cc = fVar7;

            if (param_4 == 0) {

              local_c4 = 0;

            }

            else {

              local_c4 = FUN_14016e2d0(param_4);

            }

            FUN_14013b140(local_f8);

          }

        }

      }

    }

  }

  FUN_140186c50();

  return;

}




