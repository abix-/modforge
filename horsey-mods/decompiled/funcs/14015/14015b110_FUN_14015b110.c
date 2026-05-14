// Address: 0x14015b110
// Ghidra name: FUN_14015b110
// ============ 0x14015b110 FUN_14015b110 (size=528) ============


void FUN_14015b110(undefined8 param_1,undefined4 *param_2,int param_3,int param_4,char param_5,

                  float param_6,float param_7,float param_8)



{

  char cVar1;

  int *piVar2;

  char *pcVar3;

  int iVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  int local_c8 [2];

  undefined8 local_c0;

  undefined4 local_b8;

  int local_b4;

  int local_b0;

  float local_ac;

  float local_a8;

  float local_a4;

  

  if (-1 < param_3) {

    if (((param_3 < (int)param_2[0x20]) &&

        (piVar2 = (int *)((longlong)param_3 * 0x10 + *(longlong *)(param_2 + 0x22)), -1 < param_4))

       && (param_4 < *piVar2)) {

      pcVar3 = (char *)((longlong)param_4 * 0x10 + *(longlong *)(piVar2 + 2));

      if (param_5 == '\0') {

        if ((param_6 == 0.0) && (param_7 == 0.0)) {

          param_6 = *(float *)(pcVar3 + 4);

          param_8 = 0.0;

          param_7 = *(float *)(pcVar3 + 8);

        }

        else {

          param_8 = 0.0;

        }

      }

      if (0.0 <= param_6) {

        fVar7 = DAT_14039ca44;

        if (param_6 <= DAT_14039ca44) {

          fVar7 = param_6;

        }

      }

      else {

        fVar7 = 0.0;

      }

      if (0.0 <= param_7) {

        fVar6 = DAT_14039ca44;

        if (param_7 <= DAT_14039ca44) {

          fVar6 = param_7;

        }

      }

      else {

        fVar6 = 0.0;

      }

      fVar5 = 0.0;

      if ((0.0 <= param_8) && (fVar5 = DAT_14039ca44, param_8 <= DAT_14039ca44)) {

        fVar5 = param_8;

      }

      if (param_5 == *pcVar3) {

        if (param_5 == '\0') {

          return;

        }

        if (((fVar7 == *(float *)(pcVar3 + 4)) && (fVar6 == *(float *)(pcVar3 + 8))) &&

           (fVar5 == *(float *)(pcVar3 + 0xc))) {

          return;

        }

        iVar4 = 0x657;

      }

      else {

        iVar4 = 0x658;

        if (param_5 != '\0') {

          iVar4 = 0x656;

        }

      }

      cVar1 = FUN_14015a640();

      if ((cVar1 == '\0') || (iVar4 == 0x658)) {

        *(float *)(pcVar3 + 4) = fVar7;

        *(float *)(pcVar3 + 8) = fVar6;

        *(float *)(pcVar3 + 0xc) = fVar5;

        *pcVar3 = param_5;

        *(undefined8 *)(param_2 + 0x4e) = param_1;

        cVar1 = FUN_140139420(iVar4);

        if (cVar1 != '\0') {

          local_b8 = *param_2;

          local_c8[0] = iVar4;

          local_c0 = param_1;

          local_b4 = param_3;

          local_b0 = param_4;

          local_ac = fVar7;

          local_a8 = fVar6;

          local_a4 = fVar5;

          FUN_14013b140(local_c8);

        }

      }

    }

  }

  return;

}




