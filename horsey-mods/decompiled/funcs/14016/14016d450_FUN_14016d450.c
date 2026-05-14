// Address: 0x14016d450
// Ghidra name: FUN_14016d450
// ============ 0x14016d450 FUN_14016d450 (size=229) ============


int FUN_14016d450(longlong param_1)



{

  char cVar1;

  int iVar2;

  undefined4 uVar3;

  undefined4 uVar4;

  undefined4 local_res10 [2];

  undefined4 local_res18 [4];

  

  iVar2 = 0;

  if (DAT_1403fc410 == 0) {

    FUN_1401730c0();

    return 0;

  }

  if ((param_1 != 0) &&

     ((DAT_1403e3d60 == '\0' || (cVar1 = FUN_1401aa7c0(param_1,1), cVar1 != '\0')))) {

    if (*(code **)(DAT_1403fc410 + 0x110) != (code *)0x0) {

      iVar2 = (**(code **)(DAT_1403fc410 + 0x110))(DAT_1403fc410,param_1);

    }

    FUN_140170020(param_1,*(undefined4 *)(param_1 + 0x18),*(undefined4 *)(param_1 + 0x1c),

                  local_res18,local_res10);

    if (iVar2 == 0) {

      if ((*(byte *)(param_1 + 0x48) & 1) == 0) {

        uVar4 = *(undefined4 *)(param_1 + 0x24);

        uVar3 = *(undefined4 *)(param_1 + 0x20);

      }

      else {

        uVar4 = 1;

        uVar3 = 1;

      }

      iVar2 = FUN_140169d40(local_res18[0],local_res10[0],uVar3,uVar4);

      if (iVar2 == 0) {

        iVar2 = FUN_14016dba0();

      }

    }

    return iVar2;

  }

  FUN_14012e850("Invalid window");

  return 0;

}




