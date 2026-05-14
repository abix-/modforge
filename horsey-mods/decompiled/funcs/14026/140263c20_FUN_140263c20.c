// Address: 0x140263c20
// Ghidra name: FUN_140263c20
// ============ 0x140263c20 FUN_140263c20 (size=216) ============


undefined8 FUN_140263c20(longlong param_1,int *param_2,short param_3,short param_4)



{

  char *pcVar1;

  byte bVar2;

  char cVar3;

  ulonglong uVar4;

  undefined8 uVar5;

  undefined7 uVar6;

  ulonglong uVar7;

  

  pcVar1 = *(char **)(param_1 + 0x70);

  uVar4 = _guard_check_icall();

  if (*pcVar1 == '\0') {

    uVar4 = uVar4 & 0xffffffffffffff00;

    do {

      uVar7 = uVar4 & 0xff;

      uVar6 = (undefined7)(uVar4 >> 8);

      if (*param_2 == *(int *)(pcVar1 + uVar7 * 4 + 4)) {

        if (pcVar1[uVar7 + 0x14] != '\0') {

          uVar5 = FUN_14012e850("Nintendo GameCube WaveBird controllers do not support rumble");

          return uVar5;

        }

        if (pcVar1[uVar7 + 0x48] == '\0') {

          uVar5 = FUN_14012e850("Second USB cable for WUP-028 not connected");

          return uVar5;

        }

        if (pcVar1[0x52] == '\0') {

          if ((param_3 == 0) && (param_4 == 0)) {

            cVar3 = '\0';

            goto LAB_140263cd3;

          }

        }

        else if (param_3 == 0) {

          cVar3 = '\x02';

          if (param_4 != 0) {

            cVar3 = '\0';

          }

          uVar6 = 0;

          goto LAB_140263cd3;

        }

        cVar3 = '\x01';

LAB_140263cd3:

        if (cVar3 != pcVar1[uVar7 + 0x4d]) {

          pcVar1[uVar7 + 0x4d] = cVar3;

          pcVar1[0x51] = '\x01';

        }

        return CONCAT71(uVar6,1);

      }

      bVar2 = (char)uVar4 + 1;

      uVar4 = CONCAT71(uVar6,bVar2);

    } while (bVar2 < 4);

    uVar5 = FUN_14012e850("Couldn\'t find joystick");

  }

  else {

    uVar5 = FUN_14012e850("That operation is not supported");

  }

  return uVar5;

}




