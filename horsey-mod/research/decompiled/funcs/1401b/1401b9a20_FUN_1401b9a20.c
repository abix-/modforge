// Address: 0x1401b9a20
// Ghidra name: FUN_1401b9a20
// ============ 0x1401b9a20 FUN_1401b9a20 (size=133) ============


undefined8 FUN_1401b9a20(longlong param_1,longlong param_2)



{

  int iVar1;

  undefined8 uVar2;

  

  iVar1 = (**(code **)(param_1 + 0xbf8))(*(undefined8 *)(param_2 + 0x118));

  if (iVar1 == 0) {

    return 1;

  }

  if (*(char *)(param_1 + 0x57c) != '\0') {

    uVar2 = FUN_1401c0ba0(iVar1);

                    /* WARNING: Subroutine does not return */

    FUN_14012e0b0(9,"%s %s","vkEndCommandBuffer",uVar2);

  }

  uVar2 = FUN_1401c0ba0(iVar1);

  FUN_14012e850("%s %s","vkEndCommandBuffer",uVar2);

  return 0;

}




