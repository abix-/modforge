// Address: 0x14017d6b0
// Ghidra name: FUN_14017d6b0
// ============ 0x14017d6b0 FUN_14017d6b0 (size=237) ============


void FUN_14017d6b0(undefined1 *param_1,int param_2,undefined4 param_3,uint param_4,int param_5)



{

  uint uVar1;

  undefined1 *puVar2;

  undefined1 uVar3;

  uint uVar4;

  

  if (param_5 != 0) {

    do {

      param_5 = param_5 + -1;

      uVar3 = (undefined1)param_3;

      puVar2 = param_1;

      uVar4 = param_4;

      if (3 < (int)param_4) {

        uVar1 = (uint)param_1 & 3;

        if (uVar1 == 1) {

          *param_1 = uVar3;

          puVar2 = param_1 + 1;

          uVar4 = param_4 - 1;

LAB_14017d723:

          *puVar2 = uVar3;

          puVar2 = puVar2 + 1;

          uVar4 = uVar4 - 1;

LAB_14017d72b:

          *puVar2 = uVar3;

          puVar2 = puVar2 + 1;

          uVar4 = uVar4 - 1;

        }

        else {

          if (uVar1 == 2) goto LAB_14017d723;

          if (uVar1 == 3) goto LAB_14017d72b;

        }

        FUN_140197aa0(puVar2,param_3,(longlong)((int)uVar4 >> 2));

      }

      uVar1 = uVar4 & 3;

      if (uVar1 != 0) {

        puVar2 = puVar2 + ((longlong)(int)uVar4 & 0xfffffffffffffffc);

        if (uVar1 != 1) {

          if (uVar1 != 2) {

            if (uVar1 != 3) goto LAB_14017d774;

            *puVar2 = uVar3;

            puVar2 = puVar2 + 1;

          }

          *puVar2 = uVar3;

          puVar2 = puVar2 + 1;

        }

        *puVar2 = uVar3;

      }

LAB_14017d774:

      param_1 = param_1 + param_2;

    } while (param_5 != 0);

  }

  return;

}




