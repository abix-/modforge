// Address: 0x14015afd0
// Ghidra name: FUN_14015afd0
// ============ 0x14015afd0 FUN_14015afd0 (size=312) ============


void FUN_14015afd0(undefined8 param_1,undefined4 *param_2,int param_3,undefined8 param_4,

                  undefined8 param_5,uint param_6)



{

  char cVar1;

  int iVar2;

  int *piVar3;

  uint uVar4;

  undefined4 local_98 [2];

  undefined8 local_90;

  undefined4 local_88;

  int local_84;

  undefined8 local_80;

  undefined4 local_78;

  undefined8 local_70;

  

  cVar1 = FUN_14015a640();

  if (cVar1 == '\0') {

    iVar2 = 0;

    if (0 < (int)param_2[0x24]) {

      piVar3 = *(int **)(param_2 + 0x26);

      do {

        if (*piVar3 == param_3) {

          if ((char)piVar3[1] == '\0') {

            return;

          }

          if (2 < param_6) {

            param_6 = 3;

          }

          FUN_1402f8e20(piVar3 + 3,param_5,(longlong)(int)param_6 * 4);

          *(undefined8 *)(param_2 + 0x4e) = param_1;

          cVar1 = FUN_140139420(0x659);

          if (cVar1 == '\0') {

            return;

          }

          local_88 = *param_2;

          uVar4 = 3;

          if ((ulonglong)(longlong)(int)param_6 < 3) {

            uVar4 = param_6;

          }

          local_98[0] = 0x659;

          local_80 = 0;

          local_78 = 0;

          local_90 = param_1;

          local_84 = param_3;

          FUN_1402f8e20(&local_80,param_5,(longlong)(int)uVar4 << 2);

          local_70 = param_4;

          FUN_14013b140(local_98);

          return;

        }

        iVar2 = iVar2 + 1;

        piVar3 = piVar3 + 6;

      } while (iVar2 < (int)param_2[0x24]);

    }

  }

  return;

}




