// Address: 0x140161be0
// Ghidra name: FUN_140161be0
// ============ 0x140161be0 FUN_140161be0 (size=812) ============


undefined4 *

FUN_140161be0(undefined8 param_1,longlong param_2,uint param_3,byte param_4,char param_5,

             uint param_6)



{

  uint uVar1;

  longlong lVar2;

  undefined4 *puVar3;

  undefined4 *puVar4;

  ulonglong *puVar5;

  ulonglong uVar6;

  uint uVar7;

  double dVar8;

  int local_b8 [2];

  undefined8 local_b0;

  undefined4 local_a8;

  undefined4 local_a4;

  byte local_a0;

  char local_9f;

  undefined1 local_9e;

  undefined4 local_9c;

  undefined4 local_98;

  

  lVar2 = FUN_1401611a0();

  puVar3 = (undefined4 *)FUN_140160560(lVar2,param_3,param_5,(uint)param_4);

  puVar4 = puVar3;

  if (puVar3 != (undefined4 *)0x0) {

    uVar7 = puVar3[1];

    if ((((*(char *)(lVar2 + 0xed) != '\0') && (param_3 < 0xfffffffe)) && (param_4 == 1)) &&

       (DAT_1403fc32d = param_5 != '\0', param_2 != 0)) {

      puVar4 = (undefined4 *)

               FUN_1401865d0(param_1,0xffffffffffffffff,1,param_2,0x701 - (uint)(param_5 != '\0'),

                             *(float *)(lVar2 + 0x90) / (float)*(int *)(param_2 + 0x20),

                             *(float *)(lVar2 + 0x94) / (float)*(int *)(param_2 + 0x24),

                             DAT_14039ca44);

    }

    if ((*(char *)(lVar2 + 0xec) != '\0') || (param_3 != 0xffffffff)) {

      uVar1 = param_4 - 1;

      if (param_5 == '\0') {

        uVar7 = uVar7 & ~(1 << (uVar1 & 0x1f));

      }

      else {

        uVar7 = uVar7 | 1 << (uVar1 & 0x1f);

      }

      puVar4 = (undefined4 *)(ulonglong)(byte)-param_5;

      if ((param_2 != 0) && (param_5 != '\0')) {

        puVar4 = (undefined4 *)FUN_140163030(param_2);

      }

      if (uVar7 != puVar3[1]) {

        puVar3[1] = uVar7;

        if ((int)param_6 < 0) {

          puVar5 = (ulonglong *)FUN_1401604d0(puVar3,param_4);

          if (puVar5 == (ulonglong *)0x0) {

            param_6 = 1;

          }

          else {

            if (param_5 != '\0') {

              uVar6 = FUN_140149350();

              if ((((ulonglong)*(uint *)(lVar2 + 0xe4) + *puVar5 <= uVar6) ||

                  (dVar8 = (double)FUN_140190240(*(double *)(lVar2 + 0xb0) - (double)puVar5[1]),

                  (double)*(int *)(lVar2 + 0xe8) < dVar8)) ||

                 (dVar8 = (double)FUN_140190240(*(double *)(lVar2 + 0xb8) - (double)puVar5[2]),

                 (double)*(int *)(lVar2 + 0xe8) < dVar8)) {

                *(undefined1 *)(puVar5 + 3) = 0;

              }

              *puVar5 = uVar6;

              puVar5[1] = *(ulonglong *)(lVar2 + 0xb0);

              puVar5[2] = *(ulonglong *)(lVar2 + 0xb8);

              if ((char)puVar5[3] != -1) {

                *(char *)(puVar5 + 3) = (char)puVar5[3] + '\x01';

              }

            }

            param_6 = (uint)(byte)puVar5[3];

          }

        }

        puVar4 = (undefined4 *)FUN_140139420();

        if ((char)puVar4 != '\0') {

          if (((*(char *)(lVar2 + 0xc1) == '\0') || (*(char *)(lVar2 + 0xc6) != '\0')) &&

             (param_3 < 0xfffffffe)) {

            local_a4 = 0;

          }

          else {

            local_a4 = *puVar3;

          }

          if (*(undefined4 **)(lVar2 + 0x88) == (undefined4 *)0x0) {

            local_a8 = 0;

          }

          else {

            local_a8 = **(undefined4 **)(lVar2 + 0x88);

          }

          local_9c = *(undefined4 *)(lVar2 + 0x90);

          local_98 = *(undefined4 *)(lVar2 + 0x94);

          local_9e = 0xff;

          if ((int)param_6 < 0xff) {

            local_9e = (char)param_6;

          }

          local_9f = param_5;

          local_b8[0] = 0x402 - (uint)(param_5 != '\0');

          local_b0 = param_1;

          local_a0 = param_4;

          puVar4 = (undefined4 *)FUN_14013b140(local_b8);

        }

        if ((param_2 != 0) && (param_5 == '\0')) {

          puVar4 = (undefined4 *)FUN_140163030(param_2);

        }

        if (*(char *)(lVar2 + 0xf3) != '\0') {

          puVar4 = (undefined4 *)FUN_140162f40(0);

        }

      }

    }

  }

  return puVar4;

}




