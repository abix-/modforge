// Address: 0x14028af90
// Ghidra name: FUN_14028af90
// ============ 0x14028af90 FUN_14028af90 (size=100) ============


int FUN_14028af90(ushort *param_1)



{

  ushort uVar1;

  int iVar2;

  int iVar3;

  

  uVar1 = *param_1;

  iVar2 = 0;

  if ((((uVar1 == 2) ||

       (((uVar1 < 0x21 && ((0x100010110U >> ((ulonglong)uVar1 & 0x3f) & 1) != 0)) || (uVar1 == 0x80)

        ))) || (((uVar1 == 0x100 || (uVar1 == 0x400)) || (uVar1 == 1)))) || (uVar1 == 0x40)) {

    iVar2 = *(int *)(param_1 + 10);

  }

  iVar3 = 0;

  if (iVar2 != -1) {

    iVar3 = iVar2;

  }

  return iVar3;

}




