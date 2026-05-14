// Address: 0x1401c0880
// Ghidra name: FUN_1401c0880
// ============ 0x1401c0880 FUN_1401c0880 (size=221) ============


undefined8 FUN_1401c0880(longlong param_1)



{

  int iVar1;

  undefined8 uVar2;

  longlong lVar3;

  

  FUN_140179b40(*(undefined8 *)(param_1 + 0x8d0));

  iVar1 = (**(code **)(param_1 + 0xbf0))(*(undefined8 *)(param_1 + 0x570));

  if (iVar1 == 0) {

    iVar1 = *(int *)(param_1 + 0x7d8) + -1;

    lVar3 = (longlong)iVar1;

    if (-1 < iVar1) {

      do {

        FUN_1401b55b0(param_1,*(undefined8 *)(*(longlong *)(param_1 + 2000) + lVar3 * 8),0);

        lVar3 = lVar3 + -1;

      } while (-1 < lVar3);

    }

    FUN_1401bbb60(param_1);

    FUN_140179b60(*(undefined8 *)(param_1 + 0x8d0));

    return 1;

  }

  if (*(char *)(param_1 + 0x57c) != '\0') {

    uVar2 = FUN_1401c0ba0(iVar1);

                    /* WARNING: Subroutine does not return */

    FUN_14012e0b0(9,"%s %s","vkDeviceWaitIdle",uVar2);

  }

  uVar2 = FUN_1401c0ba0(iVar1);

  FUN_14012e850("%s %s","vkDeviceWaitIdle",uVar2);

  FUN_140179b60(*(undefined8 *)(param_1 + 0x8d0));

  return 0;

}




