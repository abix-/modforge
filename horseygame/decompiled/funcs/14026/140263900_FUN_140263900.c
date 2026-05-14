// Address: 0x140263900
// Ghidra name: FUN_140263900
// ============ 0x140263900 FUN_140263900 (size=431) ============


undefined8 FUN_140263900(longlong param_1)



{

  char cVar1;

  byte bVar2;

  uint uVar3;

  int *piVar4;

  int *piVar5;

  byte *pbVar6;

  byte bVar7;

  int *piVar8;

  char local_48;

  byte local_47 [47];

  

  piVar4 = (int *)FUN_1401841a0(1,0x54);

  if (piVar4 == (int *)0x0) {

    return 0;

  }

  *(int **)(param_1 + 0x70) = piVar4;

  *(char *)(piVar4 + 0x13) = '\x11';

  if (*(short *)(param_1 + 0x20) == 0x57e) {

    if ((char)*piVar4 == '\0') {

      cVar1 = FUN_140263db0(param_1);

      if (cVar1 == '\0') {

        return 0;

      }

      uVar3 = FUN_140193800(*(undefined8 *)(param_1 + 0x80),&local_48,0x25,0);

      while (0 < (int)uVar3) {

        if ((0x24 < uVar3) && (local_48 == '!')) {

          pbVar6 = local_47;

          bVar7 = 0;

          piVar8 = piVar4 + 0x12;

          piVar5 = piVar4;

          do {

            piVar5 = piVar5 + 1;

            bVar2 = *pbVar6 >> 5 & 1;

            *(byte *)(piVar8 + -0xd) = bVar2;

            if (((*pbVar6 & 4) == 0) || (bVar2 != 0)) {

              cVar1 = '\0';

            }

            else {

              cVar1 = '\x01';

            }

            *(char *)piVar8 = cVar1;

            if ((*pbVar6 & 0x30) == 0) {

              if (*piVar5 != 0) {

                FUN_140208230(param_1);

                *piVar5 = 0;

              }

            }

            else if (*piVar5 == 0) {

              FUN_1402646f0(piVar4,bVar7);

              FUN_140208110(param_1,piVar5);

            }

            bVar7 = bVar7 + 1;

            piVar8 = (int *)((longlong)piVar8 + 1);

            pbVar6 = pbVar6 + 9;

          } while (bVar7 < 4);

        }

        uVar3 = FUN_140193800(*(undefined8 *)(param_1 + 0x80),&local_48,0x25,0);

      }

      goto LAB_140263a76;

    }

  }

  else {

    *(char *)piVar4 = '\x01';

  }

  FUN_1402646f0(piVar4,0);

  FUN_140208110(param_1,piVar4 + 1);

LAB_140263a76:

  FUN_1401427d0("SDL_JOYSTICK_HIDAPI_GAMECUBE_RUMBLE_BRAKE",FUN_140264720,piVar4);

  FUN_1402083c0(param_1,"Nintendo GameCube Controller");

  return 1;

}




