// Address: 0x1401b46e0
// Ghidra name: FUN_1401b46e0
// ============ 0x1401b46e0 FUN_1401b46e0 (size=190) ============


undefined8 FUN_1401b46e0(longlong param_1,longlong *param_2,undefined8 param_3,undefined8 param_4)



{

  int iVar1;

  undefined8 uVar2;

  

  FUN_140179b40(*(undefined8 *)(*param_2 + 0x58));

  iVar1 = (**(code **)(param_1 + 0xa10))

                    (*(undefined8 *)(param_1 + 0x570),param_4,*(undefined8 *)(*param_2 + 8),param_3)

  ;

  FUN_140179b60(*(undefined8 *)(*param_2 + 0x58));

  if (iVar1 == 0) {

    uVar2 = 1;

  }

  else {

    if (*(char *)(param_1 + 0x57c) != '\0') {

      uVar2 = FUN_1401c0ba0(iVar1);

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(9,"%s %s","vkBindImageMemory",uVar2);

    }

    uVar2 = FUN_1401c0ba0(iVar1);

    FUN_14012e850("%s %s","vkBindImageMemory",uVar2);

    uVar2 = 0;

  }

  return uVar2;

}




