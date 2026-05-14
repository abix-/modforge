// Address: 0x1401b3660
// Ghidra name: FUN_1401b3660
// ============ 0x1401b3660 FUN_1401b3660 (size=169) ============


undefined8 FUN_1401b3660(longlong param_1,longlong param_2)



{

  int iVar1;

  undefined8 uVar2;

  undefined4 local_28 [2];

  undefined8 local_20;

  undefined4 local_18;

  undefined8 local_10;

  

  local_28[0] = 0x2a;

  local_20 = 0;

  local_10 = 0;

  local_18 = 1;

  iVar1 = (**(code **)(param_1 + 0xa00))(*(undefined8 *)(param_2 + 0x118),local_28);

  if (iVar1 == 0) {

    return 1;

  }

  if (*(char *)(param_1 + 0x57c) != '\0') {

    uVar2 = FUN_1401c0ba0(iVar1);

                    /* WARNING: Subroutine does not return */

    FUN_14012e0b0(9,"%s %s","vkBeginCommandBuffer",uVar2);

  }

  uVar2 = FUN_1401c0ba0(iVar1);

  FUN_14012e850("%s %s","vkBeginCommandBuffer",uVar2);

  return 0;

}




