// Address: 0x1402e705c
// Ghidra name: FUN_1402e705c
// ============ 0x1402e705c FUN_1402e705c (size=363) ============


/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */



undefined4 FUN_1402e705c(int param_1,undefined8 param_2)



{

  undefined4 uVar1;

  int *piVar2;

  code *pcVar3;

  undefined8 uVar4;

  undefined8 *puVar5;

  int *piVar6;

  int *piVar7;

  undefined4 uVar8;

  

  puVar5 = (undefined8 *)FUN_1402e86c4();

  if (puVar5 != (undefined8 *)0x0) {

    piVar2 = (int *)*puVar5;

    for (piVar6 = piVar2; piVar6 != piVar2 + 0x30; piVar6 = piVar6 + 4) {

      if (*piVar6 == param_1) {

        if (piVar6 == (int *)0x0) {

          return 0;

        }

        pcVar3 = *(code **)(piVar6 + 2);

        if (pcVar3 == (code *)0x0) {

          return 0;

        }

        if (pcVar3 == (code *)0x5) {

          piVar6[2] = 0;

          piVar6[3] = 0;

          return 1;

        }

        if (pcVar3 != (code *)0x1) {

          uVar4 = puVar5[1];

          puVar5[1] = param_2;

          if (piVar6[1] == 8) {

            for (piVar7 = piVar2 + 0xc; piVar7 != piVar2 + 0x30; piVar7 = piVar7 + 4) {

              piVar7[2] = 0;

              piVar7[3] = 0;

            }

            uVar1 = *(undefined4 *)(puVar5 + 2);

            if (*piVar6 == -0x3fffff73) {

              uVar8 = 0x82;

LAB_1402e719a:

              *(undefined4 *)(puVar5 + 2) = uVar8;

            }

            else {

              if (*piVar6 == -0x3fffff72) {

                uVar8 = 0x83;

                goto LAB_1402e719a;

              }

              if (*piVar6 == -0x3fffff71) {

                uVar8 = 0x86;

                goto LAB_1402e719a;

              }

              if (*piVar6 == -0x3fffff70) {

                uVar8 = 0x81;

                goto LAB_1402e719a;

              }

              if (*piVar6 == -0x3fffff6f) {

                uVar8 = 0x84;

                goto LAB_1402e719a;

              }

              if (*piVar6 == -0x3fffff6e) {

                uVar8 = 0x8a;

                goto LAB_1402e719a;

              }

              if (*piVar6 == -0x3fffff6d) {

                uVar8 = 0x85;

                goto LAB_1402e719a;

              }

              if (*piVar6 == -0x3ffffd4c) {

                uVar8 = 0x8e;

                goto LAB_1402e719a;

              }

              uVar8 = uVar1;

              if (*piVar6 == -0x3ffffd4b) {

                uVar8 = 0x8d;

                goto LAB_1402e719a;

              }

            }

            (*pcVar3)(8,uVar8);

            *(undefined4 *)(puVar5 + 2) = uVar1;

          }

          else {

            piVar6[2] = 0;

            piVar6[3] = 0;

            (*pcVar3)(piVar6[1]);

          }

          puVar5[1] = uVar4;

        }

        return 0xffffffff;

      }

    }

  }

  return 0;

}




