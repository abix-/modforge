// Address: 0x1401efc00
// Ghidra name: FUN_1401efc00
// ============ 0x1401efc00 FUN_1401efc00 (size=162) ============


undefined8 FUN_1401efc00(longlong param_1,undefined4 param_2,int param_3,int param_4)



{

  undefined8 uVar1;

  code *pcVar2;

  

  if (param_4 == 0) {

LAB_1401efc69:

    pcVar2 = *(code **)(param_1 + 0x188);

  }

  else {

    if (param_4 != 1) {

      if (param_4 != 2) {

        uVar1 = FUN_14012e850("Unknown texture scale mode: %d",param_4);

        return uVar1;

      }

      if (*(char *)(param_1 + 10) == '\0') goto LAB_1401efc69;

    }

    pcVar2 = *(code **)(param_1 + 0x188);

    if (param_3 != 0x13000801) {

      (*pcVar2)(param_2,0x2801,0x2601);

      uVar1 = 0x2601;

      goto LAB_1401efc85;

    }

  }

  (*pcVar2)(param_2,0x2801,0x2600);

  uVar1 = 0x2600;

LAB_1401efc85:

  (**(code **)(param_1 + 0x188))(param_2,0x2800,uVar1);

  return 1;

}




