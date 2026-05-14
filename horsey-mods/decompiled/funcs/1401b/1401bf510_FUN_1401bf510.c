// Address: 0x1401bf510
// Ghidra name: FUN_1401bf510
// ============ 0x1401bf510 FUN_1401bf510 (size=127) ============


undefined8 FUN_1401bf510(longlong param_1,undefined8 *param_2)



{

  int iVar1;

  undefined8 uVar2;

  

  iVar1 = (**(code **)(param_1 + 0xc20))(*(undefined8 *)(param_1 + 0x570),*param_2);

  if (iVar1 == 0) {

    return 1;

  }

  if (iVar1 != 1) {

    if (*(char *)(param_1 + 0x57c) != '\0') {

      uVar2 = FUN_1401c0ba0(iVar1);

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(9,"vkGetFenceStatus: %s",uVar2);

    }

    uVar2 = FUN_1401c0ba0(iVar1);

    FUN_14012e850("vkGetFenceStatus: %s",uVar2);

  }

  return 0;

}




