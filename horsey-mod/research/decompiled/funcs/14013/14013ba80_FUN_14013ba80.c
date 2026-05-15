// Address: 0x14013ba80
// Ghidra name: FUN_14013ba80
// ============ 0x14013ba80 FUN_14013ba80 (size=129) ============


void FUN_14013ba80(uint *param_1)



{

  uint uVar1;

  

  uVar1 = *param_1;

  if (uVar1 < 0x1001) {

    if (uVar1 == 0x1000) {

LAB_14013bae1:

      FUN_14013acf0(param_1,*(undefined8 *)(param_1 + 8));

      FUN_14013acf0(param_1,*(undefined8 *)(param_1 + 10));

      return;

    }

    if (uVar1 == 0x201) {

      FUN_14013b9d0();

      return;

    }

    if (((uVar1 == 0x302) || (uVar1 == 0x303)) || ((uVar1 == 0x307 || (uVar1 == 0x900)))) {

      FUN_14013acf0(param_1,*(undefined8 *)(param_1 + 6));

      return;

    }

  }

  else if ((((uVar1 == 0x1001) || (uVar1 == 0x1002)) || (uVar1 == 0x1003)) || (uVar1 == 0x1004))

  goto LAB_14013bae1;

  return;

}




