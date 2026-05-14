// Address: 0x1401f4ff0
// Ghidra name: FUN_1401f4ff0
// ============ 0x1401f4ff0 FUN_1401f4ff0 (size=156) ============


undefined8 FUN_1401f4ff0(longlong param_1,undefined4 param_2,int param_3,int param_4)



{

  undefined8 uVar1;

  code *pcVar2;

  

  if (param_4 == 0) {

LAB_1401f5053:

    pcVar2 = *(code **)(param_1 + 0x130);

  }

  else {

    if (param_4 != 1) {

      if (param_4 != 2) {

        uVar1 = FUN_14012e850("Unknown texture scale mode: %d",param_4);

        return uVar1;

      }

      goto LAB_1401f5053;

    }

    pcVar2 = *(code **)(param_1 + 0x130);

    if (param_3 != 0x13000801) {

      (*pcVar2)(param_2,0x2801,0x2601);

      uVar1 = 0x2601;

      goto LAB_1401f506f;

    }

  }

  (*pcVar2)(param_2,0x2801,0x2600);

  uVar1 = 0x2600;

LAB_1401f506f:

  (**(code **)(param_1 + 0x130))(param_2,0x2800,uVar1);

  return 1;

}




